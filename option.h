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

#include "cstd.h"

#define N_OPTS    256
#define N_TARGETS 256

typedef struct option {
    char        flag;   /* filled in by getoption() */
    const char *val;    /* set to random address if true */
} option;

BEGIN_EXTERNS

int        getoptions PARAM((int          argc,
                             char       **argv,
                             const char  *opts,
                             option      *optv,
                             char       **targets));

const char *getoptval  PARAM((option *optv, int opt, int subopt));

END_EXTERNS

#endif /* JAM_OPTION_H */
