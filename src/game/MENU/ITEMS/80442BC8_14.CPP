#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "MENU/ITEMS/80442BC8_14.H"

#if !(defined(VERSION_EU_X))
/* Stores what func_802B2378 returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 0. */
extern s32 D_8013B2BC;
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
#endif
