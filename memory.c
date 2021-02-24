#include "jam.h"
#include "memory.h"

void *xmalloc( size )
    int size;
{
    void *pAllocMem = NULL;

    assert(size > 0);

    if ((pAllocMem = malloc((unsigned)size)) == NULL) {
        (void)fprintf
            (stderr, "fatal: heap exhausted (xmalloc of %u octets).\n", size);
        exit(EXIT_FAILURE);
    }

    return pAllocMem;
}

void xfree( ptr )
    void *ptr;
{
    if (ptr != NULL) {
        free(ptr);
    }
}
