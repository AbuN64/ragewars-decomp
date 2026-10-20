#ifndef SCENE_SHARED_S11_H
#define SCENE_SHARED_S11_H
#include "TYPES.H"

typedef struct Shared_func_80286A78_S11 Shared_func_80286A78_S11;
struct Shared_func_80286A78_S11 {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S11_size_check[(sizeof(Shared_func_80286A78_S11) == 0x8) ? 1 : -1];
#endif
