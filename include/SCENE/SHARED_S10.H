#ifndef SCENE_SHARED_S10_H
#define SCENE_SHARED_S10_H
#include "TYPES.H"

typedef struct Shared_func_80286A78_S10 Shared_func_80286A78_S10;
struct Shared_func_80286A78_S10 {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S10_size_check[(sizeof(Shared_func_80286A78_S10) == 0x8) ? 1 : -1];
#endif
