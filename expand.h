/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * expand.h - expand a buffer, given variable values
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_EXPAND_H
#define JAM_EXPAND_H 1

#include "ansi.h"
#include "lists.h"

_BEGIN_EXTERNS_

LIST *var_expand _ARG_((
    LIST        *l,
    const char  *in,
    const char  *end,
    LOL         *lol,
    int          cancopyin));

_END_EXTERNS_

#endif /* JAM_EXPAND_H */
