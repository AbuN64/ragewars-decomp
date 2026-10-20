#ifndef SCENE_SHAREDRECAT94_H
#define SCENE_SHAREDRECAT94_H
#include "TYPES.H"

typedef struct SharedRecAt94 SharedRecAt94;
struct SharedRecAt94 {
    char pad0[0x84];
    u8 address84; /* +0x84: src/func_80286A78.c */
    char pad85[0xF];
    u8 unk94; /* +0x94: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S5_size_check[(sizeof(SharedRecAt94) == 0x95) ? 1 : -1];
#endif
