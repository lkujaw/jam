/*
 * timestmp.h - get the timestamp of a file or archive member
 */

#ifndef JAM_TIMESTMP_H
#define JAM_TIMESTMP_H 1

#include "cstd.h"

BEGIN_EXTERNS

void timestamp  PARAM((char *target, time_t *time));
void donestamps PARAM((void));

END_EXTERNS

#endif /* JAM_TIMESTMP_H */
