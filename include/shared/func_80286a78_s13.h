#ifndef SHARED_SHARED_FUNC_80286A78_S13_H
#define SHARED_SHARED_FUNC_80286A78_S13_H

#include "types.h"

typedef struct SharedRecAt1B664V2 SharedRecAt1B664V2;
struct SharedRecAt1B664V2 {
    char pad0[0x1B664];
    s32 unk1B664; /* +0x1B664: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S13_size_check[(sizeof(SharedRecAt1B664V2) == 0x1B668) ? 1 : -1];

#endif
