#ifndef MATH_802A2870_H
#define MATH_802A2870_H
#include "TYPES.H"
struct CommandListController {
    u8 padding000[8];
    struct LinkedCommandEntry *entries; /* 0x08 */
    u8 padding00C[0x3C];
    s32 progress; /* 0x48 */
    u8 padding04C[0x10];
    s32 state; /* 0x5C */
};
extern u32 D_800CD990_de;
extern u32 D_800CD994;
extern u32 D_800CD998;
extern u32 D_800CD99C;
extern void func_802A1870_de(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3);
/* Elapsed game time in seconds; callers must preserve the floating return ABI. */
extern f64 func_802A18CC_de(void);
#endif
