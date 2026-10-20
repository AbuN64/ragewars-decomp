#ifndef SCENE_SHAREDRECAT91_H
#define SCENE_SHAREDRECAT91_H
#include "TYPES.H"

typedef struct SharedRecAt91 SharedRecAt91;
struct SharedRecAt91 {
    char pad0[0x78];
    u8 unk78; /* +0x78: src/func_80286A78.c */
    char pad79[0x18];
    u8 unk91; /* +0x91: src/func_80286A78.c */
};
typedef char Shared_func_80286A78_S3_size_check[(sizeof(SharedRecAt91) == 0x92) ? 1 : -1];
#endif
