#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"

/* 8042FBEC_14.CPP */
#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/SHAREDRECAT224.H"

s32 Items_ForwardRulesLock(void *unused, MenuRules *rules) {
    Player_PlacePlayerForRound(rules->locked);
    return 1;
}
#endif

#if defined(VERSION_EU)
extern char g_gameSession[];
extern void Match_ResetMatchControllerState(void *);
/* Pak/option page handler: while g_sessionOptionResetMode is 1 it runs Match_ResetMatchControllerState on the session, otherwise it clears the
   flag word at 0x5D0 of the record at 0x1C of its second argument. Returns one. */
s32 Items_HandleSessionOptionPage(void *unused, void **menu) {
    if (g_sessionOptionResetMode == 1) {
        Match_ResetMatchControllerState(g_gameSession);
    } else {
        *(s32 *)((u8 *)menu[7] + 0x5D0) = 0;
    }
    return 1;
}
#endif

#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_itemsHandlesessionoptionpageLinkGapWordsUsRev1[12] = { 0x00431023U, 0x3C01800EU, 0xC4202390U, 0x3C018014U, 0xE42068B0U, 0x8C84000CU, 0x3C03FBFFU, 0x8C820030U, 0x3463FFFFU, 0x00431024U, 0x03E00008U, 0xAC820030U };
#endif

#if defined(VERSION_US)
unsigned int g_itemsHandlesessionoptionpageLinkGapWords[12] = {
    0x41444745, 0x3C01800E, 0xC420D010, 0x3C018014, 0xE42007F0, 0x8C84000C, 0x3C03FBFF, 0x8C820030,
    0x3463FFFF, 0x00431024, 0x03E00008, 0xAC820030,
};
#endif

/* 80408AC4_4.CPP */
