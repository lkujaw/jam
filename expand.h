/*
 * expand.h - expand a buffer, given variable values
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_EXPAND_H
#define JAM_EXPAND_H 1

#include "cstd.h"
#include "lists.h"

BEGIN_EXTERNS

LIST *var_expand PARAM((
    LIST        *l,
    const char  *in,
    const char  *end,
    LOL         *lol,
    int          cancopyin));

END_EXTERNS

#endif /* JAM_EXPAND_H */
