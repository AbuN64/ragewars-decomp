#include "include_asm.h"
#include "COMMON/UNUSED.H"

#if defined(VERSION_EU_X)
#include "TYPES.H"
extern s32 D_8013B2BC;
extern s32 func_802B2378(s32);

void func_80444440_eu_x(void) {
    D_801540F4 = func_802B2378(D_8013B2BC);
    D_801540F0 = 1;
}
#endif
