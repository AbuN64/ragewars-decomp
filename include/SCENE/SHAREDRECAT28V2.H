#ifndef SCENE_SHAREDRECAT28V2_H
#define SCENE_SHAREDRECAT28V2_H
#include "TYPES.H"

typedef struct SharedRecAt28V2 SharedRecAt28V2;
struct SharedRecAt28V2 {
    s32 unk0; /* +0x0: src/func_80286A78.c */
    char pad4[0x24];
    s16 unk28; /* +0x28: src/func_80286A78.c */
    char pad2A[0x2];
};
typedef char Shared_func_80286A78_S19_size_check[(sizeof(SharedRecAt28V2) == 0x2C) ? 1 : -1];
#endif
