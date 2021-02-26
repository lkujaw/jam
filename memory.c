#include "jam.h"  /* Includes system headers */

#include "memory.h"

Void_t* xmalloc( size )
    int size;
{
    Void_t *pAllocMem = NULL;

    assert(size > 0);

    /* The curious void cast is necessary on Ultrix. */
    if ((pAllocMem = (Void_t *)malloc((unsigned)size)) == NULL) {
        fprintf
            (stderr, "fatal: heap exhausted (xmalloc of %u octets).\n", size);
        exit(EXIT_FAILURE);
    }

    return pAllocMem;
}

void xfree( ptr )
    Void_t *ptr;
{
    if (ptr != NULL) {
        free(ptr);
    }
}
