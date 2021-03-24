/*
 * execcmd.h - execute a shell script
 *
 * 05/04/94 (seiwald) - async multiprocess interface
 * 05/06/05 (seiwald) - new execmax() to return max command line len.
 */

#ifndef JAM_EXECCMD_H
#define JAM_EXECCMD_H 1

#include "cstd.h"

#define EXEC_CMD_OK    0
#define EXEC_CMD_FAIL  1
#define EXEC_CMD_INTR  2

BEGIN_EXTERNS

int execmax();

void execcmd PARAM((
    const char *string,   /* command to execute */
    void      (*func)(voidT *closure, int status),
    voidT      *closure,
    LIST       *shell));

int execwait PARAM((void));

END_EXTERNS

#endif /* JAM_EXECCMD_H */
