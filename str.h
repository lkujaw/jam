/*
 * str.h - string manipulation routines
 *
 */

#ifndef JAM_STR_H
#define JAM_STR_H 1

#include "bool.h"
#include "cstd.h"

BEGIN_EXTERNS

const char *newstr  PARAM((const char *string));
const char *copystr PARAM((const char *s));

void freestr PARAM((const char *s));
void donestr PARAM((void));

void sizeToSz PARAM((sizeT mNumber, char *pszNumeral));

boolT fSToIMaxBounded PARAM((char   *psNumeral,
                             sizeT   mNumeralLen,
                             iMaxT  *pmNumber));

END_EXTERNS

#endif /* JAM_STR_H */
