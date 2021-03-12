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

static struct hash *strhash  = _NIL_(struct hash *);
static int          strtotal = 0;

typedef struct {
    sizeT length;
    sizeT refs;
} strT;

void
sizeToSz(mNumber, pszNumeral)
    sizeT  mNumber;
    char  *pszNumeral;
{
    char  *pszNext = pszNumeral;
    sizeT  mC;
    char   chTemp;

    assert(pszNumeral != _NIL_(char *));
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
}

boolT
fSToIMaxBounded(psNumeral, mNumeralLen, pmNumber)
    char   *psNumeral;
    sizeT   mNumeralLen;
    iMaxT  *pmNumber;
{
    iMaxT  sum = 0;
    sizeT  mX;
    boolT  fParsed = FALSE;

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
}

/*
 * newstr() - return a malloc'ed copy of a string
 */

const char *
newstr(string)
    const char *string;
{
    const char *str, **s = &str;

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
        char      *m = _NIL_(char *);

        memoryAllocateOrFail((voidT **)&m, l + 1);

        if(DEBUG_MEM) {
            printf("newstr: allocating %d bytes\n", l + 1);
        }

        strtotal += l + 1;
        memcpy(m, string, l + 1);
        *s = m;
    }

    return(*s);
}

/*
 * copystr() - return a copy of a string previously returned by newstr()
 */

const char *
copystr(s)
    const char *s;
{
    return(s);
}

/*
 * freestr() - free a string returned by newstr() or copystr()
 */

void
freestr(s)
    const char *s;
{
}

/*
 * donestr() - free string tables
 */

void
donestr _ARG_((void))
{
    hashdone(strhash);

    if(DEBUG_MEM) {
        printf("%dK in strings\n", strtotal / 1024);
    }
}
