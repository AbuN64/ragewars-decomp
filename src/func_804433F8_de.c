#include "span_16E000/code_80442BC8.h"
#include "types.h"

/* Stores what func_802B2378 returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 0. */
extern s32 D_8013B2BC;
extern s32 D_801540F4;
extern s32 D_801540F0;
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern s32 func_802B2378(s32);
#else
extern s32 func_802AD2A8(s32);
#endif

void func_804433F8_de(void) {
    D_801540F4 = 
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B2378
#else
func_802AD2A8
#endif
(D_8013B2BC);
    D_801540F0 = 0;
}
