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

#include "ansi.h"

const char *newstr PROTO(( const char *string ));
const char *copystr PROTO(( const char *s ));
void freestr PROTO(( const char *s ));
void donestr PROTO(( void ));
