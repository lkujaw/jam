/*
 * str.c - string manipulation routines
 *
 * To minimize string copying, string creation, copying, and freeing
 * is done through str.
 *
 * External functions:
 *
 *     newstr() - return a malloc'ed copy of a string
 *    copystr() - return a copy of a string previously returned by newstr()
 *    freestr() - free a string returned by newstr() or copystr()
 *    donestr() - free string tables
 *
 * Once a string is passed to newstr(), the returned string is readonly.
 *
 * This implementation builds a hash table of all strings, so that multiple
 * calls of newstr() on the same string allocate memory for the string once.
 * Strings are never actually freed.
 *
 */

#include "jam.h"  /* Includes system headers */

#include "hash.h"
#include "str.h"
#include "xmem.h"

static struct hash *strhash  = NIL(struct hash *);
static int          strtotal = 0;

typedef struct {
    sizeT length;
    sizeT refs;
} strT;


void
sizeToSz DECLARE((mNumber, pszNumeral))
    sizeT  mNumber     NP
    char  *pszNumeral  EP
BEGIN
    char  *pszNext = pszNumeral;
    sizeT  mC;
    char   chTemp;

    assert(pszNumeral != NIL(char *));
    assert(mNumber > 0);

    do {
        /* This works with ASCII and EBCDIC. Additionally, the C
         * standard guarantees that digits 0-9 form a contiguous,
         * increasing range within the applicable character set.
         */
        *(pszNext++) = (char)(mNumber % 10 + (sizeT)'0');
        mNumber     /= 10;
    } while (mNumber);

    *pszNext = '\0';

    /* Numeral now contains at least one digit. */
    assert(pszNext > pszNumeral);

    /* Reverse the string from little to big endian for human readers. */
    for(mC = (pszNext - pszNumeral) >> 1; mC != 0; --mC) {
        chTemp          = *(--pszNext);
        *pszNext        = *pszNumeral;
        *(pszNumeral++) = chTemp;
    }
END_FUNCTION(sizeToSz)


boolT
fSToIMaxBounded DECLARE((psNumeral, mNumeralLen, pmNumber))
    char   *psNumeral    NP
    sizeT   mNumeralLen  NP
    iMaxT  *pmNumber     EP
BEGIN
    iMaxT   sum = 0;
    sizeT   mX;
    boolT   fParsed = FALSE;

    for(mX = 0; mX < mNumeralLen; ++mX) {
        char  chDigit = psNumeral[mX];

        if(!isdigit(chDigit)) {
            break;
        }

        if(sum * 10 < sum) {   /* overflow */
            sum     = 0;
            fParsed = FALSE;
            break;
        }

        sum     = (sum * 10) + (chDigit - '0');
        fParsed = TRUE;
    }

    *pmNumber = sum;
    return(fParsed);
END_FUNCTION(fSToIMaxBounded)


/*
 * newstr() - return a malloc'ed copy of a string
 */

const char *
newstr DECLARE((string))
    const char  *string  EP
BEGIN
    const char  *str, **s = &str;

    if(!strhash) {
        strhash = hashinit(sizeof(const char *), "strings");
    }

    *s = string;

    /* What we are doing here:
     *  Passing a copy of string hashenter:
     *  a) If the string is found, return s
     *  b) Otherwise copy the string and return it.
     */

    if(hashenter(strhash, (HASHDATA **)&s)) {
        const int  l = strlen(string);
        char      *m = NIL(char *);

        memoryAllocateOrFail((voidT **)&m, l + 1);

        if(DEBUG_MEM) {
            printf("newstr: allocating %d bytes\n", l + 1);
        }

        strtotal += l + 1;
        memcpy(m, string, l + 1);
        *s = m;
    }

    return(*s);
END_FUNCTION(newstr)


/*
 * copystr() - return a copy of a string previously returned by newstr()
 */
const char *
copystr DECLARE((s))
    const char  *s  EP
BEGIN
    return(s);
END_FUNCTION(copystr)


/*
 * freestr() - free a string returned by newstr() or copystr()
 */
void
freestr DECLARE((s))
    const char  *s  EP
BEGIN
END_FUNCTION(freestr)


/*
 * donestr() - free string tables
 */
void
donestr NULLARY
BEGIN
    hashdone(strhash);

    if(DEBUG_MEM) {
        printf("%dK in strings\n", strtotal / 1024);
    }
END_FUNCTION(donestr)
