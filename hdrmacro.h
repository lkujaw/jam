/*
 * Copyright 1993, 1995 Christopher Seiwald.
 *
 * This file is part of Jam - see jam.c for Copyright information.
 */

/*
 * hdrmacro.h - parses header files for #define MACRO  <filename> or
 *              #define MACRO  "filename" definitions
 */

#ifndef HDRMACRO_H
#define HDRMACRO_H

#include "ansi.h"
#include "rules.h"

void macro_headers PROTO(( TARGET *t ));

const char* macro_header_get PROTO(( const char*  macro_name ));

#endif /* HDRMACRO_H */
