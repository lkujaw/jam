/*
 * search.h - find a target along $(SEARCH) or $(LOCATE)
 *
 * 11/04/02 (seiwald) - const-ing for string literals
 */

#ifndef JAM_SEARCH_H
#define JAM_SEARCH_H 1

#include "cstd.h"

BEGIN_EXTERNS

const char *search PARAM((const char *target, time_t *time));

END_EXTERNS

#endif /* JAM_SEARCH_H */
