#ifndef UTIL_HEAP_H
#define UTIL_HEAP_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
struct Pool80255720 {
    s32 unk0;
    s32 unk4;
    struct Block80255720 *head;
    struct Block80255720 *tail;
    struct Block80255720 *anchor;
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
extern void Heap_CoalesceEmptyPhysicalBlocks(Pool80255720 *arena);
extern void Heap_GetFreeByteCounts(struct Pool80255ACC *arena, s32 *totalBytesOut, u32 *largestBlockBytesOut);
#endif
