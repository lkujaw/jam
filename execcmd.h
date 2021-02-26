/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * execcmd.h - execute a shell script
 *
 * 05/04/94 (seiwald) - async multiprocess interface
 */

#ifndef JAM_EXECCMD_H
#define JAM_EXECCMD_H 1

#include "ansi.h"

#define EXEC_CMD_OK    0
#define EXEC_CMD_FAIL  1
#define EXEC_CMD_INTR  2

_BEGIN_EXTERNS_

void execcmd _ARG_((
    const char *string,   /* command to execute */
    void      (*func)(Void_t *closure, int status),
    Void_t     *closure,
    LIST       *shell ));

int execwait _ARG_((void));

_END_EXTERNS_

#endif /* JAM_EXECCMD_H */
