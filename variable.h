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

#include "ansi.h"

void    var_defines PROTO(( const char **e ));
int     var_string  PROTO(( const char *in, char *out, int outsize, LOL *lol ));
LIST *  var_get     PROTO(( const char *symbol ));
void    var_set     PROTO(( const char *symbol, LIST *value, int flag ));
LIST *  var_swap    PROTO(( const char *symbol, LIST *value ));
void    var_done    PROTO(( void ));

/*
 * Defines for var_set().
 */

#define VAR_SET        0       /* override previous value */
#define VAR_APPEND     1       /* append to previous value */
#define VAR_DEFAULT    2       /* set only if no previous value */
