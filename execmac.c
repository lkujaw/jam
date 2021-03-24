/*
 * execunix.c - execute a shell script on UNIX
 *
 * If $(JAMSHELL) is defined, uses that to formulate execvp().
 * The default is:
 *
 *      /bin/sh -c %
 *
 * Each word must be an individual element in a jam variable value.
 *
 * In $(JAMSHELL), % expands to the command string and ! expands to
 * the slot number (starting at 1) for multiprocess (-j) invocations.
 * If $(JAMSHELL) doesn't include a %, it is tacked on as the last
 * argument.
 *
 * Don't just set JAMSHELL to /bin/sh - it won't work!
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
 * 05/06/05 (seiwald) - new execmax() to return max command line len.
 */

#include <errno.h>
#include "jam.h"  /* Includes system headers */

#include "lists.h"
#include "execcmd.h"

#ifdef OS_MAC


/*
 * execmax() - max permitted string to execcmd()
 */
int
execmax NULLARY
BEGIN
    return MAXLINE;
END_FUNCTION(execmax)


/*
 * execcmd() - launch an async command execution
 */
void
execcmd DECLARE((string, func, closure, shell))
    char *string                             NP
    void (*func)(void *closure, int status)  NP
    void *closure                            NP
    LIST *shell                              EP
BEGIN
    printf("%s", string);
    (*func)(closure, EXEC_CMD_OK);
END_FUNCTION(execcmd)


/*
 * execwait() - wait and drive at most one execution completion
 */
int
execwait NULLARY
BEGIN
    return(0);
END_FUNCTION(execwait)


#endif  /* OS_MAC */
