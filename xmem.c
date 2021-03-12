#include "str.h"
#include "xmem.h"

#define GUARD       0x8D67
#define MEMORY_FILL 0xCC

static boolT  fInitialized    = TRUE;
static sizeT  mAllocatedC     = 0;
static sizeT  mHighWaterMarkC = 0;

typedef struct {
    sizeT          mRegionBytesC;
    unsigned short mGuard;
} XMemHeader;

boolT
fValidPointer(pMemory)
    voidT      *pMemory;
{
    XMemHeader *pHeader;

    assert(fInitialized);

    if(pMemory == _NIL_(voidT*)) {
        return(FALSE);
    }

    if((char*)pMemory < (char*)sizeof(XMemHeader)) {
        return(FALSE);
    }

    pHeader = (XMemHeader*)pMemory - 1;

    if(pHeader == _NIL_(XMemHeader*)) {
        return(FALSE);
    }

    if(pHeader->mGuard != GUARD) {
        return(FALSE);
    }

    if(mAllocatedC < pHeader->mRegionBytesC) {
        return(FALSE);
    }

    /* TODO: We could keep track of the beginning and end of the heap and
     * verify that the pointer lies therein.
     */

    return(TRUE);
}

void
xmemTerminate()
{
    assert(fInitialized);
    fInitialized = FALSE;

    if(mAllocatedC > 0) {
        /* Flawfinder: ignore */
        char  szBytes[SIZET_CHD+1];
        sizeToSz(mAllocatedC, szBytes);
        fprintf(stderr, "WARNING: leaked %s bytes.\n", szBytes);
    }

    mAllocatedC     = 0;
    mHighWaterMarkC = 0;
}

boolT
fMemoryAllocate(ppMemory, mBytesC)
    voidT     **ppMemory;
    sizeT       mBytesC;
{
    XMemHeader *pAllocMem;
    sizeT       mBytesPlusHeaderC;

    assert(fInitialized);
    assert( ppMemory != _NIL_(voidT**));
    assert(*ppMemory == _NIL_(voidT*));

    mAdd(mBytesPlusHeaderC, mBytesC, sizeof(XMemHeader));

    /* We could return NULL instead, but this is worth knowing about. */
    if(mAllocatedC + mBytesC < mAllocatedC) {
        /* Flawfinder: ignore */
        char  szBytes[SIZET_CHD+1];

        sizeToSz(mBytesC, szBytes);

        fprintf(stderr,
                "FATAL: heap overflow (allocation of %s bytes).\n",
                szBytes);
        exit(EXITFAIL);
    }

    pAllocMem = (XMemHeader*)malloc(mBytesPlusHeaderC);

    if(pAllocMem == _NIL_(XMemHeader*)) {
        return(FALSE);
    }

    /* Fill the received memory with a predictable pattern. */
    memset((voidT*)pAllocMem, MEMORY_FILL, mBytesPlusHeaderC);

    mAllocatedC += mBytesC;
    if(mAllocatedC > mHighWaterMarkC) {
        mHighWaterMarkC = mAllocatedC;
    }

    pAllocMem->mRegionBytesC = mBytesC;
    pAllocMem->mGuard        = GUARD;

    *ppMemory = (void*)(pAllocMem + 1);
    return(TRUE);
}

void
memoryAllocateOrFail(ppMemory, mBytesC)
    voidT  **ppMemory;
    sizeT    mBytesC;
{
    assert(fInitialized);
    assert( ppMemory != _NIL_(voidT**));
    assert(*ppMemory == _NIL_(voidT*));

    if(!fMemoryAllocate(ppMemory, mBytesC)) {
        /* Flawfinder: ignore */
        char  szBytes[SIZET_CHD+1];
        sizeToSz(mBytesC, szBytes);
        fprintf(stderr, "FATAL: heap exhaustion (allocation of %s bytes).\n",
                szBytes);
        exit(EXITFAIL);
    }
}

void
memoryRelease(ppMemory)
    voidT      **ppMemory;
{
    XMemHeader  *pAllocMem;
    sizeT        mBytesC;

    assert(fInitialized);
    assert(ppMemory != _NIL_(voidT**));
    assert(fValidPointer(*ppMemory));

    pAllocMem = (XMemHeader*)*ppMemory - 1;
    mBytesC   = pAllocMem->mRegionBytesC;
    mSubtract(mAllocatedC, mAllocatedC, mBytesC);

    /* Wipe freed memory before returning it. */
    memset((voidT*)pAllocMem, MEMORY_FILL, mBytesC + sizeof(XMemHeader));

    free((voidT*)pAllocMem);
    *ppMemory = _NIL_(voidT*);
}
