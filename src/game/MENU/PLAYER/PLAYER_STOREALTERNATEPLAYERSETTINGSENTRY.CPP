#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SCREEN.H"
#include "TYPES.H"
extern struct MenuStepState *D_800E5690;
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/INTEGERSTATE530.H"
#include "MENU/804366D0_2.H"
#include "MENU/804366D0_3.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5694 holds through func_8041AD10_de and SmpSlider_SetSliderItem. Adapted from func_804366B8_de with D_800E5690 changed to D_800E5694 and the object fields moved down by eight bytes. */


extern struct StateMenuSelectAlternatePlayerSettingsEntry *D_800E5694;







extern void SmpButton_SelectListEntry(void *, s32);

extern void SmpSlider_SetSliderItem(void *, s32);

extern u8 g_playerSettings[];

extern s32 SmpButton_GetListSelection(void *);

extern s32 SmpSlider_GetSliderItem(void *);

/* Releases the object D_800E5690 holds through Cache_FreeMemory, clears D_800E5690 and returns zero. */



/* Acts on the mode of the menu held first in the block D_800E5690 points to: in mode 4 it calls
   MarkMenuEventHandled and then either SmXlate_SwitchScreen with the block's word at 0x20, when that is not -1,
   or Menu_ReturnToPreviousScreen. Returns zero. */




extern s32 SmpSlider_GetTransitionMode(void *);




/* Calls MarkMenuEventHandled; when Menu_GetFocusedElementId reports 0x60, passes the word at offset 0x28 of the object
   D_800E5690 points to to Player_StorePlayerSettingsEntry, then sets its word at 0x20 to -1 and calls SmpSlider_SetTransitionMode
   on its first word with 2. Returns zero. */



void Player_SelectAlternatePlayerSettingsEntry(s32 entryIndex) {
    u8 *slot = &D_801462C8.playerSettings[entryIndex].slot;

    *slot = entryIndex;
    SmpButton_SelectListEntry(D_800E5694->a, D_80102C89[entryIndex * 0x190]);
    SmpButton_SelectListEntry(D_800E5694->b, D_800FEC8A[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(D_800E5694->c, D_800FEC8B[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(D_800E5694->d, D_800FEC8C[entryIndex * 0x190]);
    SmpButton_SelectListEntry(D_800E5694->e, D_800FEC8D[entryIndex * 0x190]);
}

void Player_StoreAlternatePlayerSettingsEntry(s32 arg0) {
    u8 *config;

    config = g_playerSettings + arg0 * 0x96;
    D_80102C89[arg0 * 0x190] = SmpButton_GetListSelection(D_800E5694->a);
    do {
        D_800FEC8A[arg0 * 0x190] = SmpButton_GetListSelection(D_800E5694->b);
        D_800FEC8B[arg0 * 0x190] = SmpSlider_GetSliderItem(D_800E5694->c);
        D_800FEC8C[arg0 * 0x190] = SmpSlider_GetSliderItem(D_800E5694->d);
        D_800FEC8D[arg0 * 0x190] = SmpButton_GetListSelection(D_800E5694->e);
    } while (0);
    config[0x7B] = D_80102C89[arg0 * 0x190];
    config[0x7D] = D_800FEC8A[arg0 * 0x190];
    config[0x79] = D_800FEC8B[arg0 * 0x190];
    config[0x7A] = D_800FEC8C[arg0 * 0x190];
    config[0x82] = D_800FEC8D[arg0 * 0x190];
}

s32 Player_FreePlayerSettingsScreen(void) {
    Cache_FreeMemory(D_800E5690);
    D_800E5690 = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80436B68_de(void) {
    return 0;
}

s32 Player_UpdatePlayerSettingsExit(void) {
    switch (SmpSlider_GetTransitionMode(D_800E5690->menu)) {
    case 3:
        break;
    case 4:
        MarkMenuEventHandled();
        if (D_800E5690->value != -1) {
            SmXlate_SwitchScreen(D_800E5690->value);
        } else {
            Menu_ReturnToPreviousScreen();
        }
        break;
    }
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 func_80436BEC_de(void) {
    return 0;
}

s32 Player_ConfirmPlayerSettingsEntry(void) {
    struct MenuStepState *state;
    MarkMenuEventHandled();
#if defined(VERSION_DE)
    if (Menu_GetFocusedElementId() == 0x5E) {
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    if (Menu_GetFocusedElementId() == 0x60) {
#elif defined(VERSION_EU_X)
    if (Menu_GetFocusedElementId() == 0x64) {
#endif
        Player_StorePlayerSettingsEntry(D_800E5690->item);
        state = D_800E5690;
        state->value = -1;
        SmpSlider_SetTransitionMode(state->menu, 2);
    }
    return 0;
}
