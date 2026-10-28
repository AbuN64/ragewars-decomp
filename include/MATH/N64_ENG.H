#ifndef MATH_N64_ENG_H
#define MATH_N64_ENG_H
#include "TYPES.H"
#include "COMMON/RECORD.H"

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
extern void N64Eng_SetClipBounds(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3);
/* Elapsed game time in seconds; callers must preserve the floating return ABI. */
extern f64 N64Eng_GetTimeSeconds(void);

extern void N64Eng_RenderNoop();
extern void N64Eng_ResetRenderState();

extern void N64Eng_AdvanceFrameCounter();
extern void N64Eng_RegisterNumericWidgetClass();
extern int N64Eng_GetFrameCounter();
#endif
