#include "include_asm.h"

#ifdef NON_MATCHING
#include "COMMON/UNUSED.H"
#include "COMMON/RECORD.H"
#include "TYPES.H"

extern f32 D_800C5D70_de;
extern f32 D_800C5D74_de;

void func_802A1270_de(void) {
    f32 value;
    s32 base;

    value = (f32)D_80147054;
    base = D_800CD964[D_80147050_de];
    D_801470A4 = base + D_80147054;
    D_80147060[0] = base;
    D_801470A8 = base;
    D_800CD96C[0] = value;
    D_801470A0 = 0;
    if (value < D_800C5D70_de) {
        D_800CD96C[0] = D_800C5D70_de;
    }
    if (D_800C5D74_de < D_800CD96C[0]) {
        D_800CD96C[0] = D_800C5D74_de;
    }
    if (D_800CD96C[0] < D_800CD96C[1]) {
        D_800CD96C[1] = D_800CD96C[0];
    }
    if (D_800CD96C[2] < D_800CD96C[0]) {
        D_800CD96C[2] = D_800CD96C[0];
    }
    D_800CD978[0] = 0.0f;
    if (D_800CD978[0] < D_800CD978[1]) {
        D_800CD978[1] = D_800CD978[0];
    }
    if (D_800CD978[2] < D_800CD978[0]) {
        D_800CD978[2] = D_800CD978[0];
    }
    D_800CD984[0] = D_800CD978[0];
    if (D_800CD984[0] < D_800CD984[1]) {
        D_800CD984[1] = D_800CD984[0];
    }
    if (D_800CD984[2] < D_800CD984[0]) {
        D_800CD984[2] = D_800CD984[0];
    }
}
#else
INCLUDE_ASM("span_1000", func_802A1270_de);
#endif
