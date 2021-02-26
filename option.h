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

#ifndef JAM_OPTION_H
#define JAM_OPTION_H 1

#include "ansi.h"

#define N_OPTS    256
#define N_TARGETS 256

typedef struct option
{
    char         flag;  /* filled in by getoption() */
    const char  *val;   /* set to random address if true */
} option;

_BEGIN_EXTERNS_

int         getoptions _ARG_(( int          argc,
                               char       **argv,
                               const char  *opts,
                               option      *optv,
                               char       **targets ));

const char *getoptval  _ARG_((option *optv, int opt, int subopt));

_END_EXTERNS_

#endif /* JAM_OPTION_H */
