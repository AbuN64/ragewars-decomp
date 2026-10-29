#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "MENU/PLAYER_INITPLAYERSETTINGSSCREEN.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#if defined(VERSION_DE)
#define PLAYER_SETTINGS_ID(id) ((id) - 2)
#else
#define PLAYER_SETTINGS_ID(id) (id)
#endif
extern struct StateMenuSelectPlayerSettingsEntry *g_playerSettingsScreen;
extern char *g_matchOptionsCursorLabelThird[1];
extern char *g_playerSettingsPrimaryListLabels[1];
extern char *g_toggleListClearLabel[1];
extern char *g_toggleListSetLabel[1];
extern char *g_playerSettingsSecondaryListLabels[1];
extern char *g_playerSettingsFirstChoiceText[1];
extern char *g_playerSettingsSecondChoiceText[1];
extern void *Cache_AllocateMemory(s32);
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void SmpButton_WrapButtonWidget(s32);
extern void *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(void *, char *);
extern void *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void *Node_FindWidgetByResourceId(s32, s32);
#define ST ((void **)g_playerSettingsScreen)
/* Builds the five player-settings controls and opens their parent screen. */
s32 Player_InitPlayerSettingsScreen(s32 root) {
    g_playerSettingsScreen = (struct StateMenuSelectPlayerSettingsEntry *)Cache_AllocateMemory(0x64);
    ST[0] = SmpFade_CreateFadeWidget(PLAYER_SETTINGS_ID(0x5B), PLAYER_SETTINGS_ID(0x5C));
    SmpButton_WrapButtonWidget(PLAYER_SETTINGS_ID(0x5E));
    g_playerSettingsScreen->a = SmpButton_CreateListWidget(PLAYER_SETTINGS_ID(0x64), PLAYER_SETTINGS_ID(0x65));
    SmpButton_AppendListText(g_playerSettingsScreen->a, g_matchOptionsCursorLabelThird[0]);
    SmpButton_AppendListText(g_playerSettingsScreen->a, g_playerSettingsPrimaryListLabels[0]);
    g_playerSettingsScreen->b = SmpButton_CreateListWidget(PLAYER_SETTINGS_ID(0x61), PLAYER_SETTINGS_ID(0x63));
    SmpButton_AppendListText(g_playerSettingsScreen->b, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_playerSettingsScreen->b, g_toggleListSetLabel[0]);
    g_playerSettingsScreen->c = SmpSlider_CreateSliderWidget(PLAYER_SETTINGS_ID(0x66), PLAYER_SETTINGS_ID(0x67), 0xF8);
    g_playerSettingsScreen->d = SmpSlider_CreateSliderWidget(PLAYER_SETTINGS_ID(0x6A), PLAYER_SETTINGS_ID(0x6B), 0xF8);
    g_playerSettingsScreen->e = SmpButton_CreateListWidget(PLAYER_SETTINGS_ID(0x68), PLAYER_SETTINGS_ID(0x69));
    SmpButton_AppendListText(g_playerSettingsScreen->e, g_playerSettingsSecondaryListLabels[0]);
    SmpButton_AppendListText(g_playerSettingsScreen->e, g_playerSettingsFirstChoiceText[0]);
    SmpButton_AppendListText(g_playerSettingsScreen->e, g_playerSettingsSecondChoiceText[0]);
    SmpButton_WrapButtonWidget(PLAYER_SETTINGS_ID(0x60));
    ST[1] = SmpFlicker_CreateFlickerWidget(PLAYER_SETTINGS_ID(0x5D), 0x6E);
    ((s32 *)g_playerSettingsScreen)[9] = 3;
    ((s32 *)g_playerSettingsScreen)[8] = -1;
    ST[0xB] = Node_FindWidgetByResourceId(root, PLAYER_SETTINGS_ID(0x5F));
    ((s32 *)g_playerSettingsScreen)[10] = 0;
    Player_SelectPlayerSettingsEntry(0);
    return 0;
}
#undef ST
#undef PLAYER_SETTINGS_ID
#else
#include "TYPES.H"
#if defined(VERSION_EU_X)
#define EU_ID(eu, eux) (eux)
#else
#define EU_ID(eu, eux) (eu)
#endif
extern struct StateMenuSelectPlayerSettingsEntry *g_playerSettingsScreen;
extern char *g_matchOptionsCursorLabelThirdByLanguage[], *g_alternateSettingsModeLabels[], *g_optionsFirstChoiceLabels[], *g_alternateSettingsControlLabels[], *g_alternateSettingsHandLabels[], *g_alternateSettingsFinalChoiceLabelsEu[], *g_alternateSettingsFinalChoiceLabelsEuX[];
extern void *Cache_AllocateMemory(s32);
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void SmpButton_WrapButtonWidget(s32);
extern void *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(void *, char *);
extern void *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void *Node_FindWidgetByResourceId(s32, s32);
#define ST ((void **)g_playerSettingsScreen)
/* Builds the five player-settings controls (labels picked by the current language) and opens their parent screen. */
s32 Player_InitPlayerSettingsScreen(s32 root) {
    u8 *settings = (u8 *)&g_gameSettings;
    g_playerSettingsScreen = (struct StateMenuSelectPlayerSettingsEntry *)Cache_AllocateMemory(0x64);
    ST[0] = SmpFade_CreateFadeWidget(EU_ID(0x5B, 0x5F), EU_ID(0x5C, 0x60));
    SmpButton_WrapButtonWidget(EU_ID(0x5E, 0x62));
    g_playerSettingsScreen->a = SmpButton_CreateListWidget(EU_ID(0x64, 0x68), EU_ID(0x65, 0x69));
    SmpButton_AppendListText(g_playerSettingsScreen->a, g_matchOptionsCursorLabelThirdByLanguage[settings[0x581]]);
    SmpButton_AppendListText(g_playerSettingsScreen->a, g_alternateSettingsModeLabels[settings[0x581]]);
    g_playerSettingsScreen->b = SmpButton_CreateListWidget(EU_ID(0x61, 0x65), EU_ID(0x63, 0x66));
    SmpButton_AppendListText(g_playerSettingsScreen->b, g_optionsFirstChoiceLabels[settings[0x581]]);
    SmpButton_AppendListText(g_playerSettingsScreen->b, g_alternateSettingsControlLabels[settings[0x581]]);
    g_playerSettingsScreen->c = SmpSlider_CreateSliderWidget(EU_ID(0x66, 0x6A), EU_ID(0x67, 0x6B), 0xF8);
    g_playerSettingsScreen->d = SmpSlider_CreateSliderWidget(EU_ID(0x6A, 0x6E), EU_ID(0x6B, 0x6F), 0xF8);
    g_playerSettingsScreen->e = SmpButton_CreateListWidget(EU_ID(0x68, 0x6C), EU_ID(0x69, 0x6D));
    SmpButton_AppendListText(g_playerSettingsScreen->e, g_alternateSettingsHandLabels[settings[0x581]]);
    SmpButton_AppendListText(g_playerSettingsScreen->e, g_alternateSettingsFinalChoiceLabelsEu[settings[0x581]]);
    SmpButton_AppendListText(g_playerSettingsScreen->e, g_alternateSettingsFinalChoiceLabelsEuX[settings[0x581]]);
    SmpButton_WrapButtonWidget(EU_ID(0x60, 0x64));
    ST[1] = SmpFlicker_CreateFlickerWidget(EU_ID(0x5D, 0x61), 0x6E);
    ((s32 *)g_playerSettingsScreen)[9] = 3;
    ((s32 *)g_playerSettingsScreen)[8] = -1;
    ST[0xB] = Node_FindWidgetByResourceId(root, EU_ID(0x5F, 0x63));
    ((s32 *)g_playerSettingsScreen)[10] = 0;
    Player_SelectPlayerSettingsEntry(0);
    return 0;
}
#undef ST
#undef EU_ID
#endif

/* Stores entryIndex into its own g_playerSettingsSlotByteBase entry and pushes the five settings of slot entryIndex of the g_profileSlotSettingsByte7B table into the objects g_playerSettingsScreen holds through SmpButton_SelectListEntry_PlayerInitplayersettingsscreen and SmpSlider_SetSliderItem. */


extern struct StateMenuSelectPlayerSettingsEntry *g_playerSettingsScreen;
extern s8 g_profileSlotSettingsByte7B[];
extern void SmpButton_SelectListEntry(void *, s32);
extern void SmpSlider_SetSliderItem(void *, s32);

void Player_SelectPlayerSettingsEntry(s32 entryIndex) {
    u8 *slot = &g_gameSettings.playerSettings[entryIndex].slot;

    *slot = entryIndex;
    SmpButton_SelectListEntry(g_playerSettingsScreen->a, g_profileSlotSettingsByte7B[entryIndex * 0x190]);
    SmpButton_SelectListEntry(g_playerSettingsScreen->b, g_profileSlotSettingsByte7D[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(g_playerSettingsScreen->c, g_profileSlotSettingsByte79[entryIndex * 0x190]);
    SmpSlider_SetSliderItem(g_playerSettingsScreen->d, g_profileSlotSettingsByte7A[entryIndex * 0x190]);
    SmpButton_SelectListEntry(g_playerSettingsScreen->e, g_profileSlotSettingsByte82[entryIndex * 0x190]);
}

/* Reads five settings from the objects g_playerSettingsScreen holds through SmpButton_GetListSelection and SmpSlider_GetSliderItem into slot entryIndex of the g_profileSlotSettingsByte7B table and copies them into the matching bytes of the entryIndex entry of g_playerSettings_Achieve. */


extern u8 g_playerSettings[];
extern s32 SmpButton_GetListSelection(void *);
extern s32 SmpSlider_GetSliderItem(void *);

void Player_StorePlayerSettingsEntry(s32 entryIndex) {
    u8 *config;

    config = g_playerSettings + entryIndex * 0x96;
    g_profileSlotSettingsByte7B[entryIndex * 0x190] = SmpButton_GetListSelection(g_playerSettingsScreen->a);
    do {
        g_profileSlotSettingsByte7D[entryIndex * 0x190] = SmpButton_GetListSelection(g_playerSettingsScreen->b);
        g_profileSlotSettingsByte79[entryIndex * 0x190] = SmpSlider_GetSliderItem(g_playerSettingsScreen->c);
        g_profileSlotSettingsByte7A[entryIndex * 0x190] = SmpSlider_GetSliderItem(g_playerSettingsScreen->d);
        g_profileSlotSettingsByte82[entryIndex * 0x190] = SmpButton_GetListSelection(g_playerSettingsScreen->e);
    } while (0);
    config[0x7B] = g_profileSlotSettingsByte7B[entryIndex * 0x190];
    config[0x7D] = g_profileSlotSettingsByte7D[entryIndex * 0x190];
    config[0x79] = g_profileSlotSettingsByte79[entryIndex * 0x190];
    config[0x7A] = g_profileSlotSettingsByte7A[entryIndex * 0x190];
    config[0x82] = g_profileSlotSettingsByte82[entryIndex * 0x190];
}
