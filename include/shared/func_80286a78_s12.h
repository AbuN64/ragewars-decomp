#ifndef SHARED_SHARED_FUNC_80286A78_S12_H
#define SHARED_SHARED_FUNC_80286A78_S12_H

#include "TYPES.H"

typedef struct SharedRecAt8V1 SharedRecAt8V1;
struct SharedRecAt8V1 {
    char pad0[0x4];
    s32 unk4; /* +0x4: src/func_80286A78.c */
    u8 address8; /* +0x8: src/func_80286A78.c */
    char pad9[0x3];
};
typedef char Shared_func_80286A78_S12_size_check[(sizeof(SharedRecAt8V1) == 0xC) ? 1 : -1];

#endif
