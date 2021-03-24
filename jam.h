/*
 * jam.h - includes and globals for jam
 *
 * 04/08/94 (seiwald) - Coherent/386 support added.
 * 04/21/94 (seiwald) - DGUX is __DGUX__, not just __DGUX.
 * 05/04/94 (seiwald) - new globs.jobs (-j jobs)
 * 11/01/94 (wingerd) - let us define path of Jambase at compile time.
 * 12/30/94 (wingerd) - changed command buffer size for NT (MS-DOS shell).
 * 02/22/95 (seiwald) - Jambase now in /usr/local/lib.
 * 04/30/95 (seiwald) - FreeBSD added.  Live Free or Die.
 * 05/10/95 (seiwald) - SPLITPATH character set up here.
 * 08/20/95 (seiwald) - added LINUX.
 * 08/21/95 (seiwald) - added NCR.
 * 10/23/95 (seiwald) - added SCO.
 * 01/03/96 (seiwald) - SINIX (nixdorf) added.
 * 03/13/96 (seiwald) - Jambase now compiled in; remove JAMBASE variable.
 * 04/29/96 (seiwald) - AIX now has 31 and 42 OSVERs.
 * 11/21/96 (peterk)  - added BeOS with MW CW mwcc
 * 12/21/96 (seiwald) - OSPLAT now defined for NT.
 * 07/19/99 (sickel)  - Mac OS X Server and Client support added
 * 02/22/01 (seiwald) - downshift paths on case-insensitive macintosh
 * 03/23/01 (seiwald) - VMS C++ changes.
 * 10/29/01 (brett)   - More IA64 ifdefs for MS.
 * 02/18/00 (belmonte)- Support for Cygwin.
 * 09/12/00 (seiwald) - OSSYMS split to OSMAJOR/OSMINOR/OSPLAT
 * 12/29/00 (seiwald) - OSVER dropped.
 * 01/21/02 (seiwald) - new -q to quit quickly on build failure
 * 03/16/02 (seiwald) - support for -g (reorder builds by source time)
 * 03/20/02 (seiwald) - MINGW porting from Max Blagai
 * 08/16/02 (seiwald) - BEOS porting from Ingo Weinhold
 * 09/19/02 (seiwald) - new -d displays
 * 11/05/02 (seiwald) - OSPLAT now set to sparc on solaris.
 * 06/03/03 (seiwald) - OpenBSD porting from Michael Champigny.
 */

#ifndef JAM_JAM_H
#define JAM_JAM_H 1


/*
 * VMS, OPENVMS
 */
#if defined(VMS)
# define unlink remove
# include <types.h>
# include <file.h>
# include <stat.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <signal.h>
# include <string.h>
# include <time.h>
# include <unixlib.h>
# define OSMINOR "OS=VMS"
# define OSMAJOR "VMS=true"
# define OS_VMS
# define MAXLINE 1024 /* longest execcmd() */
# define SPLITPATH ','
# define EXITOK   1
# define EXITFAIL 0
# define DOWNSHIFT_PATHS
#endif


/*
 * Windows NT
 */
#if defined(NT)
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <malloc.h>
# include <memory.h>
# include <signal.h>
# include <string.h>
# include <time.h>
# define OSMAJOR "NT=true"
# define OSMINOR "OS=NT"
# define OS_NT
# define SPLITPATH ';'
# define MAXLINE 996   /* longest execcmd() */
# define USE_EXECUNIX
# define USE_PATHUNIX
# define PATH_DELIM '\\'
# define DOWNSHIFT_PATHS
# if _WIN64
typedef unsigned long long int sizeT;
# define SIZET_CHD 20
typedef long long int iMaxT;
# else
typedef unsigned long int sizeT;
# define SIZET_CHD 11
typedef long int iMaxT;
# endif
/* AS400 cross-compile from NT */
# ifdef AS400
#  undef OSMINOR
#  undef OSMAJOR
#  define OSMAJOR "AS400=true"
#  define OSMINOR "OS=AS400"
#  define OS_AS400
# endif
#endif


/*
 * Windows MingW32
 */
#if defined(MINGW)
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <malloc.h>
# include <memory.h>
# include <signal.h>
# include <string.h>
# include <time.h>
# define OSMAJOR "MINGW=true"
# define OSMINOR "OS=MINGW"
# define OS_NT
# define SPLITPATH ';'
# define MAXLINE 996    /* longest execcmd() */
# define USE_EXECUNIX
# define USE_PATHUNIX
# define PATH_DELIM '\\'
# define DOWNSHIFT_PATHS
#endif


/*
 * AS400 - mostly unix-like superficially.
 */

#if defined(AS400)
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <ctype.h>
# include <signal.h>
# include <string.h>
# include <time.h>
# include <memory.h>
# include <stdlib.h>
# define OSMAJOR "AS400=true"
# define OSMINOR "OS=AS400"
# define OS_AS400
# define USE_FILEUNIX
# define USE_PATHUNIX
# define PATH_DELIM '/'
#endif


/*
 * OS2
 */
#if defined(__OS2__)
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <malloc.h>
# include <signal.h>
# include <string.h>
# include <time.h>
# define OSMAJOR "OS2=true"
# define OSMINOR "OS=OS2"
# define OS_OS2
# define SPLITPATH ';'
# define MAXLINE 996    /* longest execcmd() */
# define USE_EXECUNIX
# define USE_PATHUNIX
# define PATH_DELIM '\\'
# define DOWNSHIFT_PATHS
#endif


/*
 * Macintosh MPW
 */
#if defined(macintosh)
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# define OSMAJOR "MAC=true"
# define OSMINOR "OS=MAC"
# define OS_MAC
# define SPLITPATH ','
# define DOWNSHIFT_PATHS
#endif


/*
 * UNIX
 */
#ifdef __APPLE__
# define UNIX
# define OSMINOR "OS=DARWIN"
# define OS_DARWIN
#else
# ifdef NeXT
#  define UNIX
#  define OSMINOR "OS=NEXT"
#  define OS_NEXT
# endif
#endif

#if defined(UNIX) || defined(unix) || defined(__unix) || defined(__unix__)
# ifndef UNIX
#  define UNIX
# endif
# define OSMAJOR "UNIX=true"
# define USE_EXECUNIX
# define USE_FILEUNIX
# define USE_PATHUNIX
# define PATH_DELIM '/'
# ifdef _AIX
#  define OSMINOR "OS=AIX"
#  define OS_AIX
# endif
# ifdef AMIGA
#  define OSMINOR "OS=AMIGA"
#  define OS_AMIGA
# endif
# ifdef __BEOS__
#  define OSMINOR "OS=BEOS"
#  define OS_BEOS
# endif
# ifdef __bsdi__
#  define OSMINOR "OS=BSDI"
#  define OS_BSDI
# endif
# if defined (COHERENT) && defined (_I386)
#  define OSMINOR "OS=COHERENT"
#  define OS_COHERENT
# endif
# ifdef __cygwin__
#  define OSMINOR "OS=CYGWIN"
#  define OS_CYGWIN
# endif
# ifdef __FreeBSD__
#  define OSMINOR "OS=FREEBSD"
#  define OS_FREEBSD
# endif
# ifdef __DGUX__
#  define OSMINOR "OS=DGUX"
#  define OS_DGUX
# endif
# ifdef __hpux
#  define OSMINOR "OS=HPUX"
#  define OS_HPUX
# endif
# ifdef __OPENNT
#  define OSMINOR "OS=INTERIX"
#  define OS_INTERIX
# endif
# ifdef __sgi
#  define OSMINOR "OS=IRIX"
#  define OS_IRIX
# endif
# ifdef __ISC
#  define OSMINOR "OS=ISC"
#  define OS_ISC
# endif
# if defined(linux) || defined(__linux) || defined(__linux__)
#  define OSMINOR "OS=LINUX"
#  define OS_LINUX
# endif
# ifdef __Lynx__
#  define OSMINOR "OS=LYNX"
#  define OS_LYNX
# endif
# ifdef __MACHTEN__
#  define OSMINOR "OS=MACHTEN"
#  define OS_MACHTEN
# endif
# ifdef mpeix
#  define OSMINOR "OS=MPEIX"
#  define OS_MPEIX
# endif
# ifdef __MVS__
#  define OSMINOR "OS=MVS"
#  define OS_MVS
# endif
# ifdef _ATT4
#  define OSMINOR "OS=NCR"
#  define OS_NCR
# endif
# ifdef __NetBSD__
#  define OSMINOR "OS=NETBSD"
#  define OS_NETBSD
# endif
# ifdef __OpenBSD__
#  define OSMINOR "OS=OPENBSD"
#  define OS_OPENBSD
# endif
# ifdef __QNX__
#  ifdef __QNXNTO__
#   define OSMINOR "OS=QNXNTO"
#   define OS_QNXNTO
#  else
#   define OSMINOR "OS=QNX"
#   define OS_QNX
#   define MAXLINE 996
#  endif
# endif
# ifdef __osf__
#  define OSMINOR "OS=OSF"
#  define OS_OSF
# endif
# ifdef _SEQUENT_
#  define OSMINOR "OS=PTX"
#  define OS_PTX
# endif
# ifdef M_XENIX
#  define OSMINOR "OS=SCO"
#  define OS_SCO
# endif
# ifdef sinix
#  define OSMINOR "OS=SINIX"
#  define OS_SINIX
# endif
# ifdef sun
#  if defined(__svr4__) || defined(__SVR4)
#   define OSMINOR "OS=SOLARIS"
#   define OS_SOLARIS
#  else
#   define OSMINOR "OS=SUNOS"
#   define OS_SUNOS
#  endif
# endif
# ifdef ultrix
#  define OSMINOR "OS=ULTRIX"
#  define OS_ULTRIX
# endif
# ifdef _UNICOS
#  define OSMINOR "OS=UNICOS"
#  define OS_UNICOS
# endif
# if defined(__USLC__) && !defined(M_XENIX)
#  define OSMINOR "OS=UNIXWARE"
#  define OS_UNIXWARE
# endif
# ifdef __nonstopux
#  define OSMINOR "OS=NONSTOP"
#  define OS_NONSTOP
# endif
# ifndef OSMINOR
#  define OSMINOR "OS=UNKNOWN"
# endif
/* All the UNIX includes */
# if defined(_lint)
#  include "jam-lint.h"
# else
#  include "FEATURE/jam"
# endif
# define HAVE_IFFE 1
#endif /* UNIX */

/*
 * OSPLAT definitions - suppressed when it's a one-of-a-kind
 */
#ifndef OSPLAT
# if defined(_M_IA64)    || \
      defined(__IA64__)  || \
      defined(__ia64__)
#  define OSPLAT "OSPLAT=IA64"
# endif
#endif

#ifndef OSPLAT
# if defined(_M_ALPHA)    || \
      defined(__ALPHA__)  || \
       defined(_ALPHA_)   || \
        defined(alpha)    || \
      defined(__alpha__)
#  define OSPLAT "OSPLAT=AXP"
# endif
#endif

#ifndef OSPLAT
# if defined(_M_HPPA)  || \
        defined(hppa)  || \
      defined(__hppa__)
#  define OSPLAT "OSPLAT=HPPA"
# endif
#endif

#ifndef OSPLAT
# if defined(_M_AMD64)    || \
        defined(AMD64)    || \
       defined(_AMD64_)   || \
      defined(__AMD64__)  || \
        defined(amd64)    || \
       defined(_amd64_)   || \
      defined(__amd64)    || \
      defined(__amd64__)  || \
      defined(_x86_64_)   || \
     defined(__x86_64)    || \
     defined(__x86_64__)
#  define OSPLAT "OSPLAT=I386-64"
# endif
#endif

#ifndef OSPLAT
# if defined(_M_IX86)    || \
        defined(i386)    || \
       defined(_i386_)   || \
      defined(__i386)    || \
      defined(__i386__)
#  if !defined(OS_OS2)
#   define OSPLAT "OSPLAT=I386"
#  endif
# endif
#endif

#ifndef OSPLAT
# if defined(__powerpc64__)
#  define OSPLAT "OSPLAT=PPC64"
# else
#  if defined(_M_PPC)       || \
         defined(PPC)       || \
         defined(ppc)       || \
       defined(__ppc__)     || \
      defined(__POWERPC__)  || \
      defined(__powerpc__)
#   define OSPLAT "OSPLAT=PPC"
#  endif
# endif
#endif

#ifndef OSPLAT
# if defined(__sparc__)
#  if defined(__sparcv9)    || \
      defined(__sparc64__)
#   define OSPLAT "OSPLAT=SPARC64"
#  else
#   if !defined(OS_SUNOS)
#    define OSPLAT "OSPLAT=SPARC"
#   endif
#  endif
# endif
#endif

#ifndef OSPLAT
# if defined(__mips__)
#  if !defined(OS_SGI)
#   define OSPLAT "OSPLAT=MIPS"
#  endif
# endif
#endif

#ifndef OSPLAT
# if defined(__arm__)
#  define OSPLAT "OSPLAT=ARM"
# endif
#endif

#ifndef OSPLAT
# if defined(__s390x__)
#  define OSPLAT "OSPLAT=s390x"
# else
#  if defined(__s390__)
#   define OSPLAT "OSPLAT=s390"
#  endif
# endif
#endif

#ifndef OSPLAT
# if   defined(VAX)  || \
     defined(__VAX)  || \
       defined(vax)
#  define OSPLAT "OSPLAT=VAX"
# endif
#endif

#ifndef OSPLAT
# define OSPLAT ""
#endif

/*
 * Jam implementation misc.
 */

#ifndef MAXLINE
# define MAXLINE 10240  /* longest execcmd() */
#endif

#ifndef EXITOK
# define EXITOK   0
# define EXITFAIL 1
#endif

#ifndef SPLITPATH
# define SPLITPATH ':'
#endif

#if !_mac_assert
# define assert(ignore)
#endif

#ifndef MIN
# define MIN(a, b) (((a)<(b))?(a):(b))
#endif

#ifndef MAX
# define MAX(a, b) (((a)>(b))?(a):(b))
#endif

/* You probably don't need to muck with these. */
#define MAXSYM   1024   /* longest symbol in the environment */
#define MAXJPATH 1024   /* longest filename */

#define MAXJOBS 64      /* silently enforce -j limit */
#define MAXARGC 32      /* words in $(JAMSHELL) */

/* Jam private definitions below. */
#define DEBUG_MAX      15

struct globs {
    int   noexec;
    int   jobs;
    int   quitquick;
    int   newestfirst;                  /* build newest sources first */
    char  debug[DEBUG_MAX];
    FILE *cmdout;                       /* print cmds, not run them */
};

extern struct globs  globs;

#define DEBUG_MAKE     (globs.debug[1])   /* -da show executed actions */
#define DEBUG_MAKEPROG (globs.debug[3])   /* -dm show progress of make0 */

#define DEBUG_EXECCMD  (globs.debug[4])   /* show execcmds()'s work */

#define DEBUG_COMPILE  (globs.debug[5])   /* -dr show rule invocations */

#define DEBUG_HEADER   (globs.debug[6])   /* show result of header scan */
#define DEBUG_BINDSCAN (globs.debug[6])   /* show result of dir scan */
#define DEBUG_SEARCH   (globs.debug[6])   /* show attempts at binding */

#define DEBUG_VARSET   (globs.debug[7])   /* show variable settings */
#define DEBUG_VARGET   (globs.debug[8])   /* show variable fetches */
#define DEBUG_VAREXP   (globs.debug[8])   /* show variable expansions */
#define DEBUG_IF       (globs.debug[8])   /* show 'if' calculations */
#define DEBUG_LISTS    (globs.debug[9])   /* show list manipulation */
#define DEBUG_SCAN     (globs.debug[9])   /* show scanner tokens */
#define DEBUG_MEM      (globs.debug[9])   /* show memory use */

#define DEBUG_MAKEQ    (globs.debug[11])  /* -da show quiet actions */
#define DEBUG_EXEC     (globs.debug[12])  /* -dx show text of actions */
#define DEBUG_DEPENDS  (globs.debug[13])  /* -dd show dependency graph */
#define DEBUG_CAUSES   (globs.debug[14])  /* -dc show dependency graph */

#endif /* JAM_JAM_H */
