#ifndef SHARED_SHARED_FUNC_80286A78_S17_H
#define SHARED_SHARED_FUNC_80286A78_S17_H

#include "TYPES.H"

typedef struct SharedRecAt28V1 SharedRecAt28V1;
struct SharedRecAt28V1 {
    s32 unk0; /* +0x0: src/func_80286A78.c */
    char pad4[0x24];
    s16 unk28; /* +0x28: src/func_80286A78.c */
    char pad2A[0x2];
};
typedef char Shared_func_80286A78_S17_size_check[(sizeof(SharedRecAt28V1) == 0x2C) ? 1 : -1];

#endif
