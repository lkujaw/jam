/*
 * fileunix.c - manipulate file names and scan directories on UNIX/AmigaOS
 *
 * External routines:
 *
 *      file_dirscan() - scan a directory for files
 *      file_time() - get timestamp of file, if not done by file_dirscan()
 *      file_archscan() - scan an archive for files
 *
 * File_dirscan() and file_archscan() call back a caller provided function
 * for each file found.  A flag to this callback function lets file_dirscan()
 * and file_archscan() indicate that a timestamp is being provided with the
 * file.   If file_dirscan() or file_archscan() do not provide the file's
 * timestamp, interested parties may later call file_time().
 *
 * 04/08/94 (seiwald) - Coherent/386 support added.
 * 12/19/94 (mikem)   - solaris string table insanity support
 * 02/14/95 (seiwald) - parse and build /xxx properly
 * 05/03/96 (seiwald) - split into pathunix.c
 * 11/21/96 (peterk)  - BEOS does not have Unix-style archives
 * 01/08/01 (seiwald) - closure param for file_dirscan/file_archscan
 * 04/03/01 (seiwald) - AIX uses SARMAG
 * 07/16/02 (seiwald) - Support BSD style long filename in archives.
 * 11/04/02 (seiwald) - const-ing for string literals
 * 12/27/02 (seiwald) - support for AIX big archives
 * 12/30/02 (seiwald) - terminate ar_hdr for solaris sscanf()
 * 12/30/02 (seiwald) - skip solaris' empty archive member names (/, //xxx)
 */

#include "jam.h"  /* Includes system headers */

#include "filesys.h"
#include "pathsys.h"
#include "str.h"
#include "xmem.h"

#ifdef USE_FILEUNIX

/* On SVR4 systems, ar.h defines one of two different archive formats
 * depending on whether PORTAR (normal) or PORT5AR (SVR) are
 * defined. One must be selected as there is no default.
 */
# if defined(OS_SEQUENT) || \
     defined(OS_DGUX)    || \
     defined(OS_SCO)     || \
     defined(OS_ISC)
#  define PORTAR 1
# endif

# if defined(__EMX__)
#  include <sys/types.h>
#  include <sys/stat.h>
# endif

# if defined(OS_NEXT)    || \
     defined(OS_DARWIN)
/* need unistd for rhapsody's proper lseek */
#  include <sys/dir.h>
#  include <unistd.h>
#  define STRUCT_DIRENT struct direct
# else
#  include <dirent.h>
#  define STRUCT_DIRENT struct dirent
# endif

# ifdef OS_COHERENT
#  include <arcoff.h>
#  define HAVE_AR
# endif

# if defined(OS_QNX)  || \
     defined(OS_BEOS) || \
     defined(OS_MPEIX)
#  define NO_AR
#  define HAVE_AR
# endif

# ifdef _AIX43
/* AIX 4.3 ar only supports __AR_BIG__ */
#  define __AR_BIG__
# endif

# if !defined(HAVE_AR) && _hdr_ar
#  include <ar.h>
# else
#  define ARMAG   "!<arch>\n"
#  define SARMAG  8
#  define ARFMAG  "`\n"
struct ar_hdr           /* archive file member header - printable ASCII */
{
    char ar_name[16];     /* file member name - `/' terminated */
    char ar_date[12];     /* file member date - decimal */
    char ar_uid[6];       /* file member user id - decimal */
    char ar_gid[6];       /* file member group id - decimal */
    char ar_mode[8];      /* file member mode - octal */
    char ar_size[10];     /* file member size - decimal */
    char ar_fmag[2];      /* ARFMAG - string to end header */
};
# endif

/*
 * file_dirscan() - scan a directory for files
 */
void
file_dirscan DECLARE((dir, func, closure))
    const char     *dir      NP
    scanback        func     NP
    voidT          *closure  EP
BEGIN
    PATHNAME        f;
    DIR            *d;
    STRUCT_DIRENT  *dirent;
    char            filename[MAXJPATH];

    /* First enter directory itself */
    memset((char *)&f, '\0', sizeof(f));

    f.f_dir.ptr = dir;
    f.f_dir.len = strlen(dir);

    dir = *dir ? dir : ".";

    /* Special case / : enter it */
    if(f.f_dir.len == 1 && f.f_dir.ptr[0] == '/') {
        (*func)(closure, dir, 0 /* not stat()'ed */, (time_t)0);
    }

    /* Now enter contents of directory */
    if(!(d = opendir(dir))) {
        return;
    }

    if(DEBUG_BINDSCAN) {
        printf("scan directory %s\n", dir);
    }

    while((dirent = readdir(d))) {
# ifdef old_sinix
        /* Broken structure definition on sinix. */
        f.f_base.ptr = dirent->d_name - 2;
# else
        f.f_base.ptr = dirent->d_name;
# endif
        f.f_base.len = strlen(f.f_base.ptr);

        path_build(&f, filename, 0);

        (*func)(closure, filename, 0 /* not stat()'ed */, (time_t)0);
    }

    closedir(d);
END_FUNCTION(file_dirscan)

/*
 * file_time() - get timestamp of file, if not done by file_dirscan()
 */
int
file_time DECLARE((filename, time))
    const char  *filename  NP
    time_t      *time      EP
BEGIN
    struct stat  statbuf;

    if(stat(filename, &statbuf) < 0) {
        return(-1);
    }

    *time = statbuf.st_mtime;
    return(0);
END_FUNCTION(file_time)


/*
 * file_archscan() - scan an archive for files
 */
# ifndef AIAMAG  /* UNIX */

#  define SARFMAG 2
#  define SARHDR sizeof(struct ar_hdr)

void
file_archscan DECLARE((archive, func, closure))
    const char  *archive  NP
    scanback     func     NP
    voidT       *closure  EP
BEGIN
#  ifndef NO_AR
    char           buf[MAXJPATH];
    struct ar_hdr  ar_hdr;
    char          *string_table = NIL(char *);
    iMaxT          offset;
    int            fd;

    if((fd = open(archive, O_RDONLY | O_BINARY, 0)) < 0) {
        return;
    }

    if(read(fd, buf, SARMAG) != SARMAG || strncmp(ARMAG, buf, SARMAG)) {
        close(fd);
        return;
    }

    offset = SARMAG;

    if(DEBUG_BINDSCAN) {
        printf("scan archive %s\n", archive);
    }

    while(read(fd, &ar_hdr, SARHDR) == SARHDR &&
          !memcmp(ar_hdr.ar_fmag, ARFMAG, SARFMAG))
    {
        iMaxT  lar_date;
        iMaxT  lar_size;
        char   lar_name[256];
        char  *dst = lar_name;
        boolT  success;

        /* solaris sscanf() does strlen first, so terminate somewhere */

        ar_hdr.ar_fmag[0] = 0;

        /* Get date & size */
        success = fSToIMaxBounded(ar_hdr.ar_date, sizeof(ar_hdr.ar_date),
                                  &lar_date);
        assert(success);

        success = fSToIMaxBounded(ar_hdr.ar_size, sizeof(ar_hdr.ar_size),
                                  &lar_size);
        assert(success);

        /* Handle solaris string table.
        ** The entry under the name // is the table,
        ** and entries with the name /nnnn refer to the table.
        */

        if(ar_hdr.ar_name[0] != '/') {
            /* traditional archive entry names:
            ** ends at the first space, /, or null.
            */
            char       *src = ar_hdr.ar_name;
            const char *e   = src + sizeof(ar_hdr.ar_name);

            while(src < e && *src && *src != ' ' && *src != '/') {
                *dst++ = *src++;
            }
        } else if(ar_hdr.ar_name[1] == '/') {
            /* This is the "string table" entry of the symbol table,
            ** which holds strings of filenames that are longer than
            ** 15 characters (i.e., do not fit into a ar_name).
            */
            assert(lar_size > 0 && lar_size < INT_MAX);
            assert(string_table == NULL);
            memoryAllocateOrFail((voidT **)&string_table, lar_size);

            if(lseek(fd, offset + SARHDR, 0) == -1 ||
               read(fd, string_table, lar_size) != lar_size)
            {
                fprintf(stderr, "error reading string table\n");
            }
        } else if(string_table && ar_hdr.ar_name[1] != ' ') {
            /* Long filenames are recognized by "/nnnn" where nnnn
            ** is the offset of the string in the string table
            ** represented in ASCII decimals.
            */
            char *src = string_table + atoi(ar_hdr.ar_name + 1);

            while(*src != '/') {
                *dst++ = *src++;
            }
        }

        /* Terminate lar_name */
        *dst = 0;

        /* Modern (BSD4.4) long names: if the name is "#1/nnnn",
        ** then the actual name is the nnnn bytes after the header.
        */

        if(!strcmp(lar_name, "#1")) {
            const int  len = MIN(sizeof(lar_name) - 1,
                                 atoi(ar_hdr.ar_name + 3));
            assert(len < sizeof(lar_name));
            if(read(fd, lar_name, len) != len) {
                printf("error reading archive entry\n");
            }
            lar_name[len] = 0;
        }

        /* Build name and pass it on.  */
        if(lar_name[0]) {
            if(DEBUG_BINDSCAN) {
                printf("archive name %s found\n", lar_name);
            }
            sprintf(buf, "%s(%s)", archive, lar_name);

            (*func)(closure, buf, 1 /* time valid */, (time_t)lar_date);
        }

        /* Position at next member */

        offset += SARHDR + ((lar_size + 1) & ~1);
        lseek(fd, offset, 0);
    }

    if(string_table) {
        memoryRelease((voidT **)&string_table);
    }
    close(fd);

#  endif /* NO_AR */
END_FUNCTION(file_archscan)


# else /* AIAMAG - RS6000 AIX */

void
file_archscan DECLARE((archive, func, closure))
    const char    *archive  NP
    scanback       func     NP
    voidT         *closure  EP
BEGIN
    struct fl_hdr  fl_hdr;

    struct {
        struct ar_hdr hdr;
        char          pad[256];
    } ar_hdr;

    char  buf[MAXJPATH];
    long  offset;
    int   fd;

    if((fd = open(archive, O_RDONLY, 0)) < 0) {
        return;
    }

#  ifdef __AR_BIG__
    if(read(fd, (char *)&fl_hdr, FL_HSZ) != FL_HSZ ||
       strncmp(AIAMAGBIG, fl_hdr.fl_magic, SAIAMAG)) {
        if(strncmp(AIAMAG, fl_hdr.fl_magic, SAIAMAG)) {
            printf("Can't read new archive %s before AIX 4.3.\n");
        }

        close(fd);
        return;
    }
#  else
    if(read(fd, (char *)&fl_hdr, FL_HSZ) != FL_HSZ ||
       strncmp(AIAMAG, fl_hdr.fl_magic, SAIAMAG)) {
        close(fd);
        return;
    }
#  endif

    (void)sToImaxBounded(fl_hdr.fl_fstmoff, sizeof(fl_hdr.fl_fstmoff),
                         &offset);

    if(DEBUG_BINDSCAN) {
        printf("scan archive %s\n", archive);
    }

    while(offset > 0 &&
          lseek(fd, offset, 0) >= 0 &&
          read(fd, &ar_hdr, sizeof(ar_hdr)) >= sizeof(ar_hdr.hdr))
    {
        iMaxT  lar_date;
        iMaxT  lar_namlen;

        (void)sToImaxBounded(ar_hdr.hdr.ar_namlen,
                             sizeof(ar_hdr.hdr.ar_namlen),
                             &lar_namlen);

        (void)sToImaxBounded(ar_hdr.hdr.ar_date,
                             sizeof(ar_hdr.hdr.ar_date),
                             &lar_date);
        (void)sToImaxBounded(ar_hdr.hdr.ar_nxtmem,
                             sizeof(ar_hdr.hdr.ar_nxtmem),
                             &offset);

        if(lar_namlen == 0) {
            continue;
        }

        ar_hdr.hdr._ar_name.ar_name[lar_namlen] = '\0';

        sprintf(buf, "%s(%s)", archive, ar_hdr.hdr._ar_name.ar_name);

        (*func)(closure, buf, 1 /* time valid */, (time_t)lar_date);
    }

    close(fd);
END(file_archscan)

# endif /* AIAMAG - RS6000 AIX */
#endif  /* USE_FILEUNIX */
