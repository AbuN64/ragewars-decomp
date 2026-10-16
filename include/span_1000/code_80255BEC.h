#ifndef UNBAKE_SPAN_1000_CODE_80255BEC_H
#define UNBAKE_SPAN_1000_CODE_80255BEC_H
#include "TYPES.H"
/* Initializes an empty list whose nodes keep their links at the given offsets. */
extern void func_80255CA0_de(IntrusiveList *list, s32 prevOffset, s32 nextOffset);

/* Appends node at the tail and returns the new count. */
extern s32 func_80255D14_de(IntrusiveList *list, void *node);

struct Pool80255ACC;

extern void func_80255E24_de(void *arg0, s32 arg1, s32 arg2);

struct func_80256130_S1;
typedef struct func_80256130_S1 func_80256130_S1;

union func_80255F34_S1_U4;
union func_80255F34_S1_U4 {
    char * v0;
    int v1;
};

union func_80255F34_S1_U4;
typedef union func_80255F34_S1_U4 func_80255F34_S1_U4;

struct func_80255F34_S1;
struct func_80255F34_S1 {
    char pad0[0x4];
    func_80255F34_S1_U4 unk4;
    char pad4[0x8 - 0x4 - sizeof(func_80255F34_S1_U4)];
    int unk8;
    char pad8[0x10 - 0x8 - sizeof(int)];
    int unk10;
};

struct func_80255BEC_S2;
typedef struct func_80255BEC_S2 func_80255BEC_S2;

extern void func_80255F94_de(IntrusiveList *arg0);



struct func_80256130_S1;
struct func_80256130_S1 {
    char pad0[0xC];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    u32 unk10;
};

struct func_80255F34_S1;
typedef struct func_80255F34_S1 func_80255F34_S1;

struct func_80255BEC_S2;
struct func_80255BEC_S2 {
    char pad0[0x4];
    void * unk4;
    char pad4[0x14 - 0x4 - sizeof(void*)];
    u32 unk14;
};

extern void func_80256214_de(IntrusiveList *arg0);

extern void func_802560A4_de(void *arg0, s32 arg1);

#endif
