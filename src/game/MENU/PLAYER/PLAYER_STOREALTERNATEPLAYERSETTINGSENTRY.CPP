#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SCREEN.H"
#include "TYPES.H"
extern struct MenuStepState *g_playerSettingsScreen;
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/INTEGERSTATE530.H"
#include "MENU/PLAYER_INITPLAYERSETTINGSSCREEN.H"
#include "MENU/PLAYER_STOREALTERNATEPLAYERSETTINGSENTRY.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/* Stores arg0 into its own g_playerSettingsSlotByteBase entry and pushes the five settings of slot arg0 of the g_profileSlotSettingsByte7B table into the objects g_alternatePlayerSettingsScreen holds through SmpButton_SelectListEntry_PlayerInitplayersettingsscreen and SmpSlider_SetSliderItem. Adapted from Player_SelectPlayerSettingsEntry_PlayerStorealternateplayersettingsentry with g_playerSettingsScreen changed to g_alternatePlayerSettingsScreen and the object fields moved down by eight bytes. */


extern struct StateMenuSelectAlternatePlayerSettingsEntry *g_alternatePlayerSettingsScreen;







extern void SmpButton_SelectListEntry(void *, s32);

extern void SmpSlider_SetSliderItem(void *, s32);

extern u8 g_playerSettings[];

extern s32 SmpButton_GetListSelection(void *);

extern s32 SmpSlider_GetSliderItem(void *);

/* Releases the object g_playerSettingsScreen holds through Cache_FreeMemory, clears g_playerSettingsScreen and returns zero. */



/* Acts on the mode of the menu held first in the block g_playerSettingsScreen points to: in mode 4 it calls
   MarkMenuEventHandled and then either SmXlate_SwitchScreen with the block's word at 0x20, when that is not -1,
   or Menu_ReturnToPreviousScreen. Returns zero. */




extern s32 SmpSlider_GetTransitionMode(void *);




/* Calls MarkMenuEventHandled; when Menu_GetFocusedElementId reports 0x60, passes the word at offset 0x28 of the object
   g_playerSettingsScreen points to to Player_StorePlayerSettingsEntry, then sets its word at 0x20 to -1 and calls SmpSlider_SetTransitionMode
   on its first word with 2. Returns zero. */



void Player_SelectAlternatePlayerSettingsEntry(s32 entryIndex) {
    u8 *slot = &g_gameSettings.playerSettings[entryIndex].slot;

    *slot = entryIndex;
    SmpButton_SelectListEntry(g_alternatePlayerSettingsScreen->a, g_profileSlotSettingsByte7B[entryIndex * 0x190]);
    SmpButton_SelectListEntry(g_alternatePlayerSettingsScreen->b, g_profileSlotSettingsByte7D[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(g_alternatePlayerSettingsScreen->c, g_profileSlotSettingsByte79[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(g_alternatePlayerSettingsScreen->d, g_profileSlotSettingsByte7A[entryIndex * 0x190]);
    SmpButton_SelectListEntry(g_alternatePlayerSettingsScreen->e, g_profileSlotSettingsByte82[entryIndex * 0x190]);
}

void Player_StoreAlternatePlayerSettingsEntry(s32 entryIndex) {
    u8 *config;

    config = g_playerSettings + entryIndex * 0x96;
    g_profileSlotSettingsByte7B[entryIndex * 0x190] = SmpButton_GetListSelection(g_alternatePlayerSettingsScreen->a);
    do {
        g_profileSlotSettingsByte7D[entryIndex * 0x190] = SmpButton_GetListSelection(g_alternatePlayerSettingsScreen->b);
        g_profileSlotSettingsByte79[entryIndex * 0x190] = SmpSlider_GetSliderItem(g_alternatePlayerSettingsScreen->c);
        g_profileSlotSettingsByte7A[entryIndex * 0x190] = SmpSlider_GetSliderItem(g_alternatePlayerSettingsScreen->d);
        g_profileSlotSettingsByte82[entryIndex * 0x190] = SmpButton_GetListSelection(g_alternatePlayerSettingsScreen->e);
    } while (0);
    config[0x7B] = g_profileSlotSettingsByte7B[entryIndex * 0x190];
    config[0x7D] = g_profileSlotSettingsByte7D[entryIndex * 0x190];
    config[0x79] = g_profileSlotSettingsByte79[entryIndex * 0x190];
    config[0x7A] = g_profileSlotSettingsByte7A[entryIndex * 0x190];
    config[0x82] = g_profileSlotSettingsByte82[entryIndex * 0x190];
}

s32 Player_FreePlayerSettingsScreen(void) {
    Cache_FreeMemory(g_playerSettingsScreen);
    g_playerSettingsScreen = 0;
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_EmptySettingsEntryHook(void) {
    return 0;
}

s32 Player_UpdatePlayerSettingsExit(void) {
    switch (SmpSlider_GetTransitionMode(g_playerSettingsScreen->menu)) {
    case 3:
        break;
    case 4:
        MarkMenuEventHandled();
        if (g_playerSettingsScreen->value != -1) {
            SmXlate_SwitchScreen(g_playerSettingsScreen->value);
        } else {
            Menu_ReturnToPreviousScreen();
        }
        break;
    }
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_EmptySettingsConfirmHook(void) {
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
        Player_StorePlayerSettingsEntry(g_playerSettingsScreen->item);
        state = g_playerSettingsScreen;
        state->value = -1;
        SmpSlider_SetTransitionMode(state->menu, 2);
    }
    return 0;
}
