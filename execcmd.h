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

#ifndef EXECCMD_H
#define EXECCMD_H

#include "ansi.h"

void execcmd PROTO((
        const char *string,   /* command to execute */
        void (*func)( void *closure, int status ),
        void *closure,
        LIST *shell ));

int execwait PROTO(( void ));

# define EXEC_CMD_OK    0
# define EXEC_CMD_FAIL  1
# define EXEC_CMD_INTR  2

#endif /* EXECCMD_H */
