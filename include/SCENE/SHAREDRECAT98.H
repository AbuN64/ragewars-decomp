#ifndef SCENE_SHAREDRECAT98_H
#define SCENE_SHAREDRECAT98_H
#include "TYPES.H"

typedef struct SharedRecAt98 SharedRecAt98;
struct SharedRecAt98 {
    char pad0[0x98];
    s32 unk98; /* +0x98: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S4_size_check[(sizeof(SharedRecAt98) == 0x9C) ? 1 : -1];
#endif
