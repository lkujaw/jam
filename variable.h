/*
 * Copyright 1993, 2000 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * variable.h - handle jam multi-element variables
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_VARIABLE_H
#define JAM_VARIABLE_H 1

#include "cstd.h"

/*
 * Defines for var_set().
 */

#define VAR_SET        0       /* override previous value */
#define VAR_APPEND     1       /* append to previous value */
#define VAR_DEFAULT    2       /* set only if no previous value */

BEGIN_EXTERNS

void    var_defines PARAM((const char **e));
int     var_string  PARAM((const char *in, char *out, int outsize, LOL *lol));
LIST *  var_get     PARAM((const char *symbol));
void    var_set     PARAM((const char *symbol, LIST *value, int flag));
LIST *  var_swap    PARAM((const char *symbol, LIST *value));
void    var_done    PARAM((void));

END_EXTERNS

#endif /* JAM_VARIABLE_H */
