/*
 * hdrmacro.h - parses header files for #define MACRO  <filename> or
 *              #define MACRO  "filename" definitions
 */

#ifndef JAM_HDRMACRO_H
#define JAM_HDRMACRO_H 1

#include "cstd.h"
#include "rules.h"

BEGIN_EXTERNS

void macro_headers PARAM((TARGET *t));

const char* macro_header_get PARAM((const char* macro_name));

END_EXTERNS

#endif /* JAM_HDRMACRO_H */
