#ifndef COMMON_ARG_H
#define COMMON_ARG_H
#include "TYPES.H"
#include "COMMON/LONE/D_8014D5C0.H"
#include "COMMON/EXTERNS_18.H"



typedef struct {
    s32 field0;
    s32 field4;
    s32 index;
} func_802B80B4_eu_Arg;

extern s32 D_800D8380[];

extern u8 D_8014D4C0[];

extern void __osSiGetAccess(void);
extern u32 __osContDataCrc(void *arg0);
extern void __osSiRelAccess(void);
#endif
