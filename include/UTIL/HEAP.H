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
   blocks; D_801051A0 is the game's main heap. */
struct Heap {
    char *start;
    char *end;
    struct BlockRecAt20 *free;
    struct BlockRecAt20 *last;
    struct BlockRecAt20 *first;
};
struct HeapRecAtC {
    char pad0[8];
    struct BlockRecAt20 *head;
    struct BlockRecAt20 *tail;
};
extern void func_80255780_de(Pool80255720 *arena);
extern void func_80255C4C_de(struct Pool80255ACC *arena, s32 *totalBytesOut, u32 *largestBlockBytesOut);
#endif
