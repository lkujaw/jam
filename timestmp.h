/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * timestmp.h - get the timestamp of a file or archive member
 */

#ifndef JAM_TIMESTMP_H
#define JAM_TIMESTMP_H 1

#include "ansi.h"

_BEGIN_EXTERNS_

void timestamp  _ARG_((char *target, time_t *time));
void donestamps _ARG_((void));

_END_EXTERNS_

#endif /* JAM_TIMESTMP_H */
