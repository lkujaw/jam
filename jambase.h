/*
 * jambase.h - declaration for the internal jambase
 *
 * The file Jambase is turned into a C array of strings in jambase.c
 * so that it can be built in to the executable.  This is the
 * declaration for that array.
 */

#ifndef JAM_JAMBASE_H
#define JAM_JAMBASE_H 1

#include "cstd.h"

BEGIN_EXTERNS

extern char *jambase[];

END_EXTERNS

#endif /* JAM_JAMBASE_H */
