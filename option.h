/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * option.h - command line option processing
 *
 * {o >o
 *  \ -) "Command line option."
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#include "ansi.h"

typedef struct option
{
        char    flag;           /* filled in by getoption() */
        const char      *val;   /* set to random address if true */
} option;

# define N_OPTS    256
# define N_TARGETS 256

int         getoptions PROTO(( int argc, char **argv, const char *opts,
                               option *optv, char** targets ));
const char *getoptval  PROTO(( option *optv, int opt, int subopt ));
