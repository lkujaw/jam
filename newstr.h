/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * newstr.h - string manipulation routines
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_NEWSTR_H
#define JAM_NEWSTR_H 1

#include "ansi.h"

_BEGIN_EXTERNS_

const char *newstr  _ARG_((const char *string));
const char *copystr _ARG_((const char *s));

void freestr _ARG_((const char *s));
void donestr _ARG_((void));

_END_EXTERNS_

#endif /* JAM_NEWSTR_H */
