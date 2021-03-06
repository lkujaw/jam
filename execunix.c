/*
 * execunix.c - execute a shell script on UNIX/WinNT/OS2/AmigaOS
 *
 * If $(JAMSHELL) is defined, uses that to formulate execvp()/spawnvp().
 * The default is:
 *
 *      /bin/sh -c %            [ on UNIX/AmigaOS ]
 *      cmd.exe /c %            [ on OS2/WinNT ]
 *
 * Each word must be an individual element in a jam variable value.
 *
 * In $(JAMSHELL), % expands to the command string and ! expands to
 * the slot number (starting at 1) for multiprocess (-j) invocations.
 * If $(JAMSHELL) doesn't include a %, it is tacked on as the last
 * argument.
 *
 * Don't just set JAMSHELL to /bin/sh or cmd.exe - it won't work!
 *
 * External routines:
 *      execcmd() - launch an async command execution
 *      execwait() - wait and drive at most one execution completion
 *
 * Internal routines:
 *      onintr() - bump intr to note command interruption
 *
 * 04/08/94 (seiwald) - Coherent/386 support added.
 * 05/04/94 (seiwald) - async multiprocess interface
 * 01/22/95 (seiwald) - $(JAMSHELL) support
 * 06/02/97 (gsar)    - full async multiprocess support for Win32
 * 01/20/00 (seiwald) - Upgraded from K&R to ANSI C
 * 11/04/02 (seiwald) - const-ing for string literals
 * 12/27/02 (seiwald) - grist .bat file with pid for system uniqueness
 * 05/06/05 (seiwald) - new execmax() to return max command line len.
 */

#include <errno.h>
#include "jam.h"  /* includes system headers */

#include "lists.h"
#include "execcmd.h"

#ifdef USE_EXECUNIX

# ifdef OS_OS2
#  define USE_EXECNT
#  include <process.h>
# endif

# ifdef OS_NT
#  define USE_EXECNT
#  include <process.h>
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>          /* do the ugly deed */
#  define USE_MYWAIT
#  if !defined(__BORLANDC__)
#   define pid_t int
#   define wait my_wait
static int my_wait PARAM((int *status));
#  endif
# endif

static int  intr        = 0;
static int  cmdsrunning = 0;
static void onintr PARAM((int));
static void (*istat)PARAM((int));

static struct {
    int pid;          /* on win32, a real process handle */
    void   (*func)PARAM((voidT * closure, int status));
    voidT *closure;
# ifdef USE_EXECNT
    char *tempfile;
# endif
} cmdtab[MAXJOBS] = { { 0 } };

/*
 * onintr() - bump intr to note command interruption
 */
static void
onintr DECLARE((disp))
    int  disp  EP
BEGIN
    UNUSED(disp);
    intr++;
    printf("...interrupted\n");
END_FUNCTION(onintr)

# ifdef OS_NT
int
execmax NULLARY
BEGIN
    static int maxline = 0;
    OSVERSIONINFO o;

    if(maxline) {
        return maxline;
    }

    /* Get from OS */

    /* Beyond Win 2003?  (6+?) -- 8191 */
    /* WinXP (5/0) or Win 2003 (5/1) -- 8191 */
    /* Win 2k (5/0) or Win NT 4 (4/0) -- 2047 */
    /* older -- 996 */

   o.dwOSVersionInfoSize = sizeof(o);

   if(!GetVersionEx(&o)) {
       maxline = MAXLINE;
   } else if(o.dwMajorVersion >= 6) {
       maxline = 8191;
   } else if(o.dwMajorVersion == 5 && o.dwMinorVersion >= 1) {
       maxline = 8191;
   } else if(o.dwMajorVersion == 5 && o.dwMinorVersion == 0) {
       maxline = 2047;
   } else if(o.dwMajorVersion == 4 && o.dwMinorVersion == 0) {
       maxline = 2047;
   } else {
       maxline = MAXLINE;
   }

   if(DEBUG_EXECCMD) {
       printf("Windows %d/%d maxline %d\n",
              o.dwMajorVersion,
              o.dwMinorVersion,
              maxline);
   }

   return maxline;
END_FUNCTION(execmax)

# else

/*
 * execmax() - max permitted string to execcmd()
 */
int
execmax NULLARY
BEGIN
    return MAXLINE;
END_FUNCTION(execmax)

#endif

/*
 * execcmd() - launch an async command execution
 */
void
execcmd DECLARE((string, func, closure, shell))
    const char *string                                    NP
    void      (*func)PARAM((voidT *closure, int status))  NP
    voidT      *closure                                   NP
    LIST       *shell                                     EP
BEGIN
    int         pid;
    int         slot;
    const char *argv[MAXARGC + 1];        /* +1 for NULL */

# ifdef USE_EXECNT
    char *p;
# endif

    assert(string && func);

    /* Find a slot in the running commands table for this one. */

    for(slot = 0; slot < MAXJOBS; slot++) {
        if(!cmdtab[ slot ].pid) {
            break;
        }
    }

    if(slot == MAXJOBS) {
        printf("no slots for child!\n");
        exit(EXITFAIL);
    }

# ifdef USE_EXECNT
    if(!cmdtab[slot].tempfile) {
        char *tempdir;

        if(!(tempdir = getenv("TEMP")) &&
           !(tempdir = getenv("TMP"))) {
            tempdir = "\\temp";
        }

        /* +32 is room for \jamXXXXXtSS.bat (at least) */
        memoryAllocateOrFail((voidT**)&cmdtab[slot].tempfile,
                             strlen(tempdir) + 32);

        sprintf(cmdtab[slot].tempfile, "%s\\jam%dt%d.bat",
                tempdir, GetCurrentProcessId(), slot);
    }

    /* Trim leading, ending white space */

    while(isspace(*string)) {
        ++string;
    }

    p = strchr(string, '\n');

    while(p && isspace(*p)) {
        ++p;
    }

    /* If multi line, or too long, or JAMSHELL is set, write to bat file. */
    /* Otherwise, exec directly. */
    /* Frankly, if it is a single long line I don't think the */
    /* command interpreter will do any better -- it will fail. */

    if(p && *p || strlen(string) > MAXLINE || shell) {
        FILE *f;

        /* Write command to bat file. */

        f = fopen(cmdtab[slot].tempfile, "w");
        fputs(string, f);
        fclose(f);

        string = cmdtab[slot].tempfile;
    }
# endif

    /* Forumulate argv */
    /* If shell was defined, be prepared for % and ! subs. */
    /* Otherwise, use stock /bin/sh (on unix) or cmd.exe (on NT). */

    if(shell) {
        int   i;
        char  jobno[4];
        int   gotpercent = 0;

        sprintf(jobno, "%d", slot + 1);

        for(i = 0; shell && i < MAXARGC; i++, shell = list_next(shell)) {
            switch(shell->string[0]) {
            case '%':       argv[i] = string; gotpercent++; break;
            case '!':       argv[i] = jobno; break;
            default:        argv[i] = shell->string;
            }
            if(DEBUG_EXECCMD) {
                printf("argv[%d] = '%s'\n", i, argv[i]);
            }
        }

        if(!gotpercent) {
            argv[i++] = string;
        }

        argv[i] = NULL;
    } else   {
# ifdef USE_EXECNT
        argv[0] = "cmd.exe";
        argv[1] = "/Q/C";           /* anything more is non-portable */
# else
        argv[0] = "/bin/sh";
        argv[1] = "-c";
# endif
        argv[2] = string;
        argv[3] = 0;
    }

    /* Catch interrupts whenever commands are running. */

    if(!cmdsrunning++) {
        istat = signal(SIGINT, onintr);
    }

    /* Start the command */

# ifdef USE_EXECNT
    if((pid = spawnvp(P_NOWAIT, argv[0], argv)) == -1) {
        perror("spawn");
        exit(EXITFAIL);
    }
# else
#  if _lib_vfork
    if((pid = vfork()) == 0)
#  else
    if((pid = fork()) == 0)
#  endif
    {
        /* POSIX states that argv should not be modified */
        execvp(argv[0], (char *const *)argv);
        _exit(127);
    }

    if(pid == -1) {
        perror("vfork");
        exit(EXITFAIL);
    }
# endif
    /* Save the operation for execwait() to find. */

    cmdtab[slot].pid     = pid;
    cmdtab[slot].func    = func;
    cmdtab[slot].closure = closure;

    /* Wait until we're under the limit of concurrent commands. */
    /* Don't trust globs.jobs alone.                            */

    while(cmdsrunning >= MAXJOBS || cmdsrunning >= globs.jobs) {
        if(!execwait()) {
            break;
        }
    }
END_FUNCTION(execcmd)


/*
 * execwait() - wait and drive at most one execution completion
 */
int
execwait NULLARY
BEGIN
    int    i;
    int    status;
    int    rstat;
    pid_t  w;

    /* Handle naive make1() which doesn't know if cmds are running. */
    if(!cmdsrunning) {
        return(0);
    }

    /* Pick up process pid and status */
    while((w = wait(&status)) == -1 && errno == EINTR) {}

    if(w == -1) {
        printf("child process(es) lost!\n");
        perror("wait");
        exit(EXITFAIL);
    }

    /* Find the process in the cmdtab. */
    for(i = 0; i < MAXJOBS; ++i) {
        if(w == cmdtab[i].pid) {
            break;
        }
    }

    if(i == MAXJOBS) {
        printf("waif child found!\n");
        exit(EXITFAIL);
    }

# ifdef USE_EXECNT
    /* Clear the temp file */
    unlink(cmdtab[i].tempfile);
# endif

    /* Drive the completion */

    if(!--cmdsrunning) {
        signal(SIGINT, istat);
    }

    if(intr) {
        rstat = EXEC_CMD_INTR;
    } else if(w == -1 || status != 0) {
        rstat = EXEC_CMD_FAIL;
    } else {
        rstat = EXEC_CMD_OK;
    }

    cmdtab[i].pid = 0;

    (*cmdtab[i].func)(cmdtab[i].closure, rstat);

    return(1);
END_FUNCTION(execwait)


# ifdef USE_MYWAIT
static int
my_wait DECLARE((status))
    int  *status  EP
BEGIN
    int            i, num_active = 0;
    DWORD          exitcode, waitcode;
    static HANDLE *active_handles = NIL(HANDLE *);

    if(!active_handles) {
        memoryAllocateOrFail((voidT**)&active_handles,
                             globs.jobs * sizeof(HANDLE));
    }

    /* first see if any non-waited-for processes are dead,
     * and return if so.
     */
    for(i = 0; i < globs.jobs; i++) {
        if(cmdtab[i].pid) {
            if(GetExitCodeProcess((HANDLE)cmdtab[i].pid, &exitcode)) {
                if(exitcode == STILL_ACTIVE) {
                    active_handles[num_active++] = (HANDLE)cmdtab[i].pid;
                } else {
                    CloseHandle((HANDLE)cmdtab[i].pid);
                    *status = (int)((exitcode & 0xff) << 8);
                    return(cmdtab[i].pid);
                }
            } else {
                goto FAILED;
            }
        }
    }

    /* if a child exists, wait for it to die */
    if(!num_active) {
        errno = ECHILD;
        return(-1);
    }
    waitcode = WaitForMultipleObjects(num_active,
                                      active_handles,
                                      FALSE,
                                      INFINITE);
    if(waitcode != WAIT_FAILED) {
        if(waitcode >= WAIT_ABANDONED_0
           && waitcode < WAIT_ABANDONED_0 + num_active) {
            i = waitcode - WAIT_ABANDONED_0;
        } else {
            i = waitcode - WAIT_OBJECT_0;
        }
        if(GetExitCodeProcess(active_handles[i], &exitcode)) {
            CloseHandle(active_handles[i]);
            *status = (int)((exitcode & 0xff) << 8);
            return((int)active_handles[i]);
        }
    }

FAILED:
    errno = GetLastError();
    return(-1);
END_FUNCTION(my_wait)

# endif /* USE_MYWAIT */
#endif  /* USE_EXECUNIX */
