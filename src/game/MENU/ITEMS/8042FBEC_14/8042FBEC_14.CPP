#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

/* 8042FBEC_14.CPP */
#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/SHAREDRECAT224.H"

s32 Items_ForwardRulesLock(void *unused, MenuRules *rules) {
    Ovlgame_PlacePlayerForRound(rules->locked);
    return 1;
}
#endif

#if defined(VERSION_EU)
extern char D_8011FAC0[];
extern void Ovlgame_ResetMatchControllerState(void *);
/* Pak/option page handler: while D_80145070 is 1 it runs Ovlgame_ResetMatchControllerState on the session, otherwise it clears the
   flag word at 0x5D0 of the record at 0x1C of its second argument. Returns one. */
s32 Items_HandleSessionOptionPage(void *unused, void **menu) {
    if (D_80145070 == 1) {
        Ovlgame_ResetMatchControllerState(D_8011FAC0);
    } else {
        *(s32 *)((u8 *)menu[7] + 0x5D0) = 0;
    }
    return 1;
}
#endif

#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8043EF1C_us_rev1[12] = { 0x00431023U, 0x3C01800EU, 0xC4202390U, 0x3C018014U, 0xE42068B0U, 0x8C84000CU, 0x3C03FBFFU, 0x8C820030U, 0x3463FFFFU, 0x00431024U, 0x03E00008U, 0xAC820030U };
#endif

#if defined(VERSION_US)
unsigned int D_auto_rodata_unresolved_8043EF1C[12] = {
    0x41444745, 0x3C01800E, 0xC420D010, 0x3C018014, 0xE42007F0, 0x8C84000C, 0x3C03FBFF, 0x8C820030,
    0x3463FFFF, 0x00431024, 0x03E00008, 0xAC820030,
};
#endif

/* 80408AC4_4.CPP */
#if defined(VERSION_DE)
const u32 data_func_8043C324_de_800DE050[33] = {
    0x0043C344, 0x0043C544, 0x0043C3B4, 0x0043C3C4, 0x0043C3E4, 0x0043C3D4,
    0x0043C374, 0x0043C384, 0x0043C454, 0x0043C394, 0x0043C3F4, 0x0043C404,
    0x0043C414, 0x0043C4A4, 0x0043C3A4, 0x0043C424, 0x0043C434, 0x0043C444,
    0x0043C4B4, 0x0043C474, 0x0043C484, 0x0043C4C4, 0x0043C494, 0x0043C4D4,
    0x0043C4E4, 0x0043C504, 0x0043C4F4, 0x0043C524, 0x0043C514, 0x0043C464,
    0x0043C354, 0x0043C364, 0x0043C534,
};
#endif
