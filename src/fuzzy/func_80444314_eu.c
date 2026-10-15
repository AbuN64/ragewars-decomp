#include "types.h"

/* Stores what func_802B2378 returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 1. */
extern s32 D_8013B2BC;
extern s32 D_801540F4;
extern s32 D_801540F0;
extern s32 func_802B2378(s32);

void func_80444314_eu(void) {
    D_801540F4 = func_802B2378(D_8013B2BC);
    D_801540F0 = 1;
}
