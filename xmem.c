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
fValidPointer DECLARE((pMemory))
    voidT      *pMemory  EP
BEGIN
    XMemHeader *pHeader;

    assert(fInitialized);

    if(pMemory == NIL(voidT*)) {
        return(FALSE);
    }

    if((char*)pMemory < (char*)sizeof(XMemHeader)) {
        return(FALSE);
    }

    pHeader = (XMemHeader*)pMemory - 1;

    if(pHeader == NIL(XMemHeader*)) {
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
END_FUNCTION(fValidPointer)


void
xmemTerminate NULLARY
BEGIN
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
END_FUNCTION(xmemTerminate)


boolT
fMemoryAllocate DECLARE((ppMemory, mBytesC))
    voidT     **ppMemory  NP
    sizeT       mBytesC   EP
BEGIN
    XMemHeader *pAllocMem;
    sizeT       mBytesPlusHeaderC;

    assert(fInitialized);
    assert( ppMemory != NIL(voidT**));
    assert(*ppMemory == NIL(voidT*));

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

    if(pAllocMem == NIL(XMemHeader*)) {
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
END_FUNCTION(fMemoryAllocate)


void
memoryAllocateOrFail DECLARE((ppMemory, mBytesC))
    voidT  **ppMemory  NP
    sizeT    mBytesC   EP
BEGIN
    assert(fInitialized);
    assert( ppMemory != NIL(voidT**));
    assert(*ppMemory == NIL(voidT*));

    if(!fMemoryAllocate(ppMemory, mBytesC)) {
        /* Flawfinder: ignore */
        char  szBytes[SIZET_CHD+1];
        sizeToSz(mBytesC, szBytes);
        fprintf(stderr, "FATAL: heap exhaustion (allocation of %s bytes).\n",
                szBytes);
        exit(EXITFAIL);
    }
END_FUNCTION(memoryAllocateOrFail)


void
memoryRelease DECLARE((ppMemory))
    voidT      **ppMemory  EP
BEGIN
    XMemHeader  *pAllocMem;
    sizeT        mBytesC;

    assert(fInitialized);
    assert(ppMemory != NIL(voidT**));
    assert(fValidPointer(*ppMemory));

    pAllocMem = (XMemHeader*)*ppMemory - 1;
    mBytesC   = pAllocMem->mRegionBytesC;
    mSubtract(mAllocatedC, mAllocatedC, mBytesC);

    /* Wipe freed memory before returning it. */
    memset((voidT*)pAllocMem, MEMORY_FILL, mBytesC + sizeof(XMemHeader));

    free((voidT*)pAllocMem);
    *ppMemory = NIL(voidT*);
END_FUNCTION(memoryRelease)
