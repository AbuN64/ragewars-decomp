#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern u8 g_matchSettingsByteView[];
typedef struct { void *a0, *a4, *a8, *aC, *a10; s32 a14; void *a18; } MenuBlockEu;
extern MenuBlockEu *g_alternatePlayerSettingsScreen;
extern char *g_matchOptionsCursorLabelThirdByLanguage[], *g_alternateSettingsModeLabels[], *g_optionsFirstChoiceLabels[], *g_alternateSettingsControlLabels[], *g_alternateSettingsHandLabels[], *g_alternateSettingsFinalChoiceLabelsEu[], *g_alternateSettingsFinalChoiceLabelsEuX[];
extern void *Cache_AllocateMemory(s32);
extern void SmpButton_WrapButtonWidget(s32), SmpButton_AppendListText(void *, char *);
extern void *SmpButton_CreateListWidget(s32, s32), *SmpSlider_CreateSliderWidget(s32, s32, s32), *Node_FindWidgetByResourceId(void *, s32);
extern void Player_SelectAlternatePlayerSettingsEntry(s32);
/* Builds the 0x50-byte confirm popup: its three button rows (ids 0x1C9, 0x1D1, 0x1CB) get the labels of the current language,
   the two fade windows 0x1CF/0x1CD are created, and item 0x1C7 is kept as the cursor. Returns 0. */
s32 Player_OpenAlternatePlayerSettingsScreen(void *window) {
    u8 lang;
    g_alternatePlayerSettingsScreen = Cache_AllocateMemory(0x50);
    SmpButton_WrapButtonWidget(0x1C6);
    lang = g_matchSettingsByteView[0x581];
    g_alternatePlayerSettingsScreen->aC = SmpButton_CreateListWidget(0x1C9, 0x1CA);
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->aC, g_matchOptionsCursorLabelThirdByLanguage[lang]);
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->aC, g_alternateSettingsModeLabels[lang]);
    g_alternatePlayerSettingsScreen->a8 = SmpButton_CreateListWidget(0x1D1, 0x1D2);
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->a8, g_optionsFirstChoiceLabels[lang]);
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->a8, g_alternateSettingsControlLabels[lang]);
    SmpSlider_CreateSliderWidget(0x1CF, 0x1D0, 0xFF);
    g_alternatePlayerSettingsScreen->a0 = SmpSlider_CreateSliderWidget(0x1CD, 0x1CE, 0xFF);
    g_alternatePlayerSettingsScreen->a4 = SmpButton_CreateListWidget(0x1CB, 0x1CC);
    g_alternatePlayerSettingsScreen->a10 = g_alternatePlayerSettingsScreen->a4;
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->a4, g_alternateSettingsHandLabels[lang]);
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->a10, g_alternateSettingsFinalChoiceLabelsEu[lang]);
    SmpButton_AppendListText(g_alternatePlayerSettingsScreen->a10, g_alternateSettingsFinalChoiceLabelsEuX[lang]);
    SmpButton_WrapButtonWidget(0x1C8);
    g_alternatePlayerSettingsScreen->a18 = Node_FindWidgetByResourceId(window, 0x1C7);
    g_alternatePlayerSettingsScreen->a14 = 0;
    Player_SelectAlternatePlayerSettingsEntry(0);
    return 0;
}
#else
INCLUDE_ASM("ovl_frontendMenu", Player_OpenAlternatePlayerSettingsScreen);
#endif
#endif
