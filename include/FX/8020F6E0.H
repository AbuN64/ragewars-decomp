#ifndef FX_8020F6E0_H
#define FX_8020F6E0_H
#include "TYPES.H"
struct ObjRecAt28C {
    char pad[0x38];
    s32 count;
    int keys[10];
    char pad64[0x6C - 0x64];
    int flags[10];
    s32 distances[10];
    char padBC[0x28C - 0xBC];
    int current;
};
#endif
