#ifndef UTIL_802555D0_H
#define UTIL_802555D0_H
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
struct Heap {
    char *start;
    char *end;
    struct BlockRecAt14 *free;
    struct BlockRecAt14 *last;
    struct BlockRecAt14 *first;
};
struct HeapRecAtC {
    char pad0[8];
    struct BlockRecAt20 *head;
    struct BlockRecAt20 *tail;
};
extern void func_80255780_de(Pool80255720 *arg0);
extern void func_80255C4C_de(struct Pool80255ACC *arg0, s32 *arg1, u32 *arg2);
#endif
