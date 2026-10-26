#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "MENU_2/804366D0_2.H"

#if defined(NON_MATCHING) || (!defined(VERSION_EU) && !defined(VERSION_EU_X))
#if defined(VERSION_DE)
#define PLAYER_SETTINGS_ID(id) ((id) - 2)
#else
#define PLAYER_SETTINGS_ID(id) (id)
#endif
extern struct StateMenuSelectPlayerSettingsEntry *D_800E5690;
extern char *D_800D34A4[1], *D_800D34B0[1], *D_800D3470_de[1], *D_800D3474[1], *D_800D34B4[1], *D_800D34B8[1], *D_800D34BC[1];
extern void *Cache_AllocateMemory(s32);
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void SmpButton_WrapButtonWidget(s32);
extern void *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(void *, char *);
extern void *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void *Frontend_FindWidgetByResourceId(s32, s32);
#define ST ((void **)D_800E5690)
/* Builds the five player-settings controls and opens their parent screen. */
s32 Menu_InitPlayerSettingsScreen(s32 root) {
    D_800E5690 = (struct StateMenuSelectPlayerSettingsEntry *)Cache_AllocateMemory(0x64);
    ST[0] = SmpFade_CreateFadeWidget(PLAYER_SETTINGS_ID(0x5B), PLAYER_SETTINGS_ID(0x5C));
    SmpButton_WrapButtonWidget(PLAYER_SETTINGS_ID(0x5E));
    D_800E5690->a = SmpButton_CreateListWidget(PLAYER_SETTINGS_ID(0x64), PLAYER_SETTINGS_ID(0x65));
    SmpButton_AppendListText(D_800E5690->a, D_800D34A4[0]);
    SmpButton_AppendListText(D_800E5690->a, D_800D34B0[0]);
    D_800E5690->b = SmpButton_CreateListWidget(PLAYER_SETTINGS_ID(0x61), PLAYER_SETTINGS_ID(0x63));
    SmpButton_AppendListText(D_800E5690->b, D_800D3470_de[0]);
    SmpButton_AppendListText(D_800E5690->b, D_800D3474[0]);
    D_800E5690->c = SmpSlider_CreateSliderWidget(PLAYER_SETTINGS_ID(0x66), PLAYER_SETTINGS_ID(0x67), 0xF8);
    D_800E5690->d = SmpSlider_CreateSliderWidget(PLAYER_SETTINGS_ID(0x6A), PLAYER_SETTINGS_ID(0x6B), 0xF8);
    D_800E5690->e = SmpButton_CreateListWidget(PLAYER_SETTINGS_ID(0x68), PLAYER_SETTINGS_ID(0x69));
    SmpButton_AppendListText(D_800E5690->e, D_800D34B4[0]);
    SmpButton_AppendListText(D_800E5690->e, D_800D34B8[0]);
    SmpButton_AppendListText(D_800E5690->e, D_800D34BC[0]);
    SmpButton_WrapButtonWidget(PLAYER_SETTINGS_ID(0x60));
    ST[1] = SmpFlicker_CreateFlickerWidget(PLAYER_SETTINGS_ID(0x5D), 0x6E);
    ((s32 *)D_800E5690)[9] = 3;
    ((s32 *)D_800E5690)[8] = -1;
    ST[0xB] = Frontend_FindWidgetByResourceId(root, PLAYER_SETTINGS_ID(0x5F));
    ((s32 *)D_800E5690)[10] = 0;
    Menu_SelectPlayerSettingsEntry(0);
    return 0;
}
#undef ST
#undef PLAYER_SETTINGS_ID
#else
INCLUDE_ASM("ovl_80400000", Menu_InitPlayerSettingsScreen);
#endif

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5690 holds through func_8041AD10_de and SmpSlider_SetSliderItem. */


extern struct StateMenuSelectPlayerSettingsEntry *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern void SmpButton_SelectListEntry(void *, s32);
extern void SmpSlider_SetSliderItem(void *, s32);

void Menu_SelectPlayerSettingsEntry(s32 entryIndex) {
    u8 *slot = &D_801462C8.playerSettings[entryIndex].slot;

    *slot = entryIndex;
    SmpButton_SelectListEntry(D_800E5690->a, D_80102C89[entryIndex * 0x190]);
    SmpButton_SelectListEntry(D_800E5690->b, D_800FEC8A[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(D_800E5690->c, D_800FEC8B[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(D_800E5690->d, D_800FEC8C[entryIndex * 0x190]);
    SmpButton_SelectListEntry(D_800E5690->e, D_800FEC8D[entryIndex * 0x190]);
}

/* Reads five settings from the objects D_800E5690 holds through SmpButton_GetListSelection and SmpSlider_GetSliderItem into slot arg0 of the D_80102C89 table and copies them into the matching bytes of the arg0 entry of D_80146398. */


extern struct StateMenuSelectPlayerSettingsEntry *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 g_playerSettings[];
extern s32 SmpButton_GetListSelection(void *);
extern s32 SmpSlider_GetSliderItem(void *);

void func_804367A8_de(s32 arg0) {
    u8 *config;

    config = g_playerSettings + arg0 * 0x96;
    D_80102C89[arg0 * 0x190] = SmpButton_GetListSelection(D_800E5690->a);
    do {
        D_800FEC8A[arg0 * 0x190] = SmpButton_GetListSelection(D_800E5690->b);
        D_800FEC8B[arg0 * 0x190] = SmpSlider_GetSliderItem(D_800E5690->c);
        D_800FEC8C[arg0 * 0x190] = SmpSlider_GetSliderItem(D_800E5690->d);
        D_800FEC8D[arg0 * 0x190] = SmpButton_GetListSelection(D_800E5690->e);
    } while (0);
    config[0x7B] = D_80102C89[arg0 * 0x190];
    config[0x7D] = D_800FEC8A[arg0 * 0x190];
    config[0x79] = D_800FEC8B[arg0 * 0x190];
    config[0x7A] = D_800FEC8C[arg0 * 0x190];
    config[0x82] = D_800FEC8D[arg0 * 0x190];
}
