#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "TYPES.H"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
#include "TYPES.H"

/* Stores what func_802B2378 returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 1. */
extern s32 D_8013B2BC;
extern s32 func_802B2378(s32);

void func_80444314_eu(void) {
    D_801540F4 = func_802B2378(D_8013B2BC);
    D_801540F0 = 1;
}
#else
INCLUDE_ASM("ovl_80400000", func_80444314_eu);
#endif
#endif

#if defined(VERSION_US_REV1)
/* Stores what func_802B2378 returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 1. */
extern s32 D_8013B2BC;

extern s32 func_802B2378(s32);

void func_80444314_eu(void) {
    D_801540F4 = func_802B2378(D_8013B2BC);
    D_801540F0 = 1;
}
#endif
