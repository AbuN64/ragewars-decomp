#ifndef SHARED_SHARED_FUNC_80286A78_S8_H
#define SHARED_SHARED_FUNC_80286A78_S8_H

#include "types.h"

typedef struct SharedRecAt10V2 SharedRecAt10V2;
struct SharedRecAt10V2 {
    char pad0[0x10];
    u8 unk10; /* +0x10: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S8_size_check[(sizeof(SharedRecAt10V2) == 0x11) ? 1 : -1];

#endif
