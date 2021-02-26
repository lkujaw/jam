/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * search.h - find a target along $(SEARCH) or $(LOCATE)
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_SEARCH_H
#define JAM_SEARCH_H 1

#include "ansi.h"

_BEGIN_EXTERNS_

const char *search _ARG_((const char *target, time_t *time));

_END_EXTERNS_

#endif /* JAM_SEARCH_H */
