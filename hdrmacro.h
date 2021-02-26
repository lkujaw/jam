/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * hdrmacro.h - parses header files for #define MACRO  <filename> or
 *              #define MACRO  "filename" definitions
 */

#ifndef JAM_HDRMACRO_H
#define JAM_HDRMACRO_H 1

#include "ansi.h"
#include "rules.h"

_BEGIN_EXTERNS_

void macro_headers _ARG_((TARGET *t));

const char* macro_header_get _ARG_((const char* macro_name));

_END_EXTERNS_

#endif /* JAM_HDRMACRO_H */
