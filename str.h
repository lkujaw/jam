/*
 * str.h - string manipulation routines
 *
 */

#ifndef JAM_STR_H
#define JAM_STR_H 1

#include "ansi.h"
#include "bool.h"

_BEGIN_EXTERNS_

const char *newstr  _ARG_((const char *string));
const char *copystr _ARG_((const char *s));

void freestr _ARG_((const char *s));
void donestr _ARG_((void));

void sizeToSz _ARG_((sizeT mNumber, char *pszNumeral));

boolT fSToIMaxBounded _ARG_((char   *psNumeral,
                             sizeT   mNumeralLen,
                             iMaxT  *pmNumber));

_END_EXTERNS_

#endif /* JAM_STR_H */
