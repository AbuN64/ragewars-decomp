#ifndef UTIL_MAP_H
#define UTIL_MAP_H
#include "TYPES.H"
struct ObjRecAtCV3 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
};
#endif
