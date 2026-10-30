#ifndef ENGINE_CACHE_HEAP_H
#define ENGINE_CACHE_HEAP_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
struct HeapArena_Heap {
    s32 reservedWord0;
    s32 reservedWord4;
    struct HeapArenaBlock *head;
    struct HeapArenaBlock *tail;
    struct HeapArenaBlock *anchor;
};
/* A first-fit heap: its byte range, the free-block list (head and tail) and the address-ordered list of all
   blocks; g_runtimeHeap is the game's main heap. */
struct Heap {
    char *start;
    char *end;
    struct HeapAllocationBlock *free;
    struct HeapAllocationBlock *last;
    struct HeapAllocationBlock *first;
};
struct HeapFreeBlockList {
    char pad0[8];
    struct HeapAllocationBlock *head;
    struct HeapAllocationBlock *tail;
};
extern void Heap_CoalesceEmptyPhysicalBlocks(HeapArena_Heap *arena);
extern void Heap_GetFreeByteCounts(struct HeapArena_Entryrecat18v3 *arena, s32 *totalBytesOut, u32 *largestBlockBytesOut);
#endif
