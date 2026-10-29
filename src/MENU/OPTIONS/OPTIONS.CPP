#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "COMMON/MENU_INITIALIZEOPTIONSSCENE.H"
#include "MENU/OPTIONS.H"

/* OPTIONS.CPP */
#if defined(VERSION_US) || defined(VERSION_US_REV1)
#if defined(VERSION_US)
unsigned int func_8042250C_us_rev1_padding_19050C[1] = {
    0x5F574541,
};
#endif
#if defined(VERSION_US_REV1)
unsigned int func_8042250C_us_rev1_padding_19050C[1] = {
    0x24020001,
};
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
#include "MENU/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/MENU_OPTIONS_AND_RESULTS.H"
#include "TYPES.H"
struct MenuFadeWidget;
struct MenuResourceWidget;
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
#include "COMMON/SHARED_GAMESLOT.H"

/* Builds the options-commit state: allocates its 0x28 bytes through Cache_AllocateMemory and keeps the
   record at g_optionsPage, creates the fade widget 0x4D/0x4E and the title object 0x4F/0x6E, then builds
   the three option lists 0x59/0x5A, 0x55/0x56 and 0x51/0x52, appends their localized labels, and
   selects the entry named by the game settings g_gameSettings bytes 0x1B, 0x1F and 0x580 - the third list
   gains the labels at 0x800D74B8 and 0x800D74BC only when Defs_GetMemorySize does not return 0x400000.
   The 0x80-step slider 0x53/0x54 is created and positioned at the settings' position byte, menu nodes
   0x57, 0x58 and 0x50 are released, and the record is finally armed with a selection value of -1 and
   commit state 3, returning zero. */

extern OptionsCommitContext *g_optionsPage;
/* Localized label pointers supplied to each option list. */
extern u8 *g_toggleListClearLabel[1];
extern u8 *g_optionsFirstListPrimaryLabel;
extern u8 *g_optionsFirstListSecondaryLabel;
extern u8 *g_optionsResolutionFirstChoiceLabels[1];
extern u8 *g_optionsResolutionSecondChoiceLabels;
extern u8 *g_optionsResolutionThirdChoiceLabels;

extern void *Cache_AllocateMemory(s32);
extern struct MenuFadeWidget *SmpFade_CreateFadeWidget(s32, s32);

extern s32 Defs_GetMemorySize(void);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);

s32 Options_CreateOptionsPage(void) {
    Shared_Game *settings;
    void *firstList;
    void *secondList;
    void *thirdList;
    void *title;
    void *slider;

    g_optionsPage = Cache_AllocateMemory(0x28);
    g_optionsPage->menu = SmpFade_CreateFadeWidget(0x4D, 0x4E);
    SmpButton_WrapButtonWidget(0x57);
    SmpButton_WrapButtonWidget(0x58);
    firstList = SmpButton_CreateListWidget(0x59, 0x5A);
    g_optionsPage->bloodModeList = firstList;
    SmpButton_AppendListText(firstList, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_optionsPage->bloodModeList, g_optionsFirstListPrimaryLabel);
    SmpButton_AppendListText(g_optionsPage->bloodModeList, g_optionsFirstListSecondaryLabel);
    settings = &g_gameSettings;
    SmpButton_SelectListEntry(g_optionsPage->bloodModeList, settings->bloodMode);
    secondList = SmpButton_CreateListWidget(0x55, 0x56);
    g_optionsPage->twoPlayerScreenList = secondList;
    SmpButton_AppendListText(secondList, g_optionsPrimaryLocalizedLabels[0]);
    SmpButton_AppendListText(g_optionsPage->twoPlayerScreenList, g_optionsSecondaryLocalizedLabels);
    SmpButton_SelectListEntry(g_optionsPage->twoPlayerScreenList, settings->twoPlayerScreenPreference);
    thirdList = SmpButton_CreateListWidget(0x51, 0x52);
    g_optionsPage->resolutionList = thirdList;
    SmpButton_AppendListText(thirdList, g_optionsResolutionFirstChoiceLabels[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->resolutionList, g_optionsResolutionSecondChoiceLabels);
        SmpButton_AppendListText(g_optionsPage->resolutionList, g_optionsResolutionThirdChoiceLabels);
    }
    SmpButton_SelectListEntry(g_optionsPage->resolutionList, settings->resolution);
    slider = SmpSlider_CreateSliderWidget(0x53, 0x54, 0x80);
    g_optionsPage->gammaSlider = slider;
    SmpSlider_SetSliderItem(slider, settings->lightingGamma);
    SmpButton_WrapButtonWidget(0x50);
    title = SmpFlicker_CreateFlickerWidget(0x4F, 0x6E);
    g_optionsPage->state = 3;
    g_optionsPage->title = title;
    g_optionsPage->value = -1;
    return 0;
}

#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
extern Shared_OptionsScreen *g_optionsShortcutScreen;
extern Shared_MenuReply g_selectionMessageReply;
extern void Widget_SetWidgetFlag08(void *, s32);
extern void Widget_SetWidgetFlag100(void *, s32);
extern void Tsmos_DeactivateControllerState(void);
extern void Frontend_InitMenuImage(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void Frontend_StartMenuImageTransition(Shared_OptionsScreen *);
s32 Options_OpenOptionsScreen(void *node) {
    Shared_Game *settings;
    MenuWidget *handle;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *rumble;
    MenuWidget *pak;
    MenuWidget *prompt;
    MenuListWidget *firstListHandle;
    MenuListWidget *secondListHandle;
    void *slider;
    s32 i;
    s32 rem;

    g_optionsShortcutScreen = Cache_AllocateMemory(0x6C);
    g_optionsShortcutScreen->sound = SoundElement_GetMusicPlaybackEnabled();
    SoundElement_SetMusicPlaybackEnabled(0x34);
    SoundElement_DisableMusicGainOverride();
    SoundElement_StopAudioExceptKey(-1);
    g_optionsShortcutScreen->page = 1;
    g_optionsShortcutScreen->pages = 4;
    g_optionsShortcutScreen->leftTab = Node_FindWidgetByResourceId(node, 0x381);
    g_optionsShortcutScreen->leftTab->x -= g_optionsShortcutScreen->leftTab->width;
    g_optionsShortcutScreen->leftStep = g_optionsShortcutScreen->leftTab->width / 4;
    rem = g_optionsShortcutScreen->leftTab->width - g_optionsShortcutScreen->leftStep * 4;
    g_optionsShortcutScreen->leftTab->x += rem;
    g_optionsShortcutScreen->rightTab = Node_FindWidgetByResourceId(node, 0x388);
    g_optionsShortcutScreen->rightTab->x += g_optionsShortcutScreen->rightTab->width;
    g_optionsShortcutScreen->rightStep = g_optionsShortcutScreen->rightTab->width / 4;
    rem = g_optionsShortcutScreen->rightTab->width - g_optionsShortcutScreen->rightStep * 4;
    g_optionsShortcutScreen->rightTab->x -= rem;
    g_optionsShortcutScreen->title = SmpFlicker_CreateFlickerWidget(0x373, 0x6E);
    marker = Node_FindWidgetByResourceId(node, 0x372);
    g_optionsShortcutScreen->marker = marker;
    Widget_SetWidgetFlag08(marker, 0);
    (Node_FindWidgetByResourceId(node, 0x386))->alpha = 0x6E;
    header = Node_FindWidgetByResourceId(node, 0x387);
    g_optionsShortcutScreen->header = header;
    header->alpha = 0x8C;
    g_optionsShortcutScreen->footer = Node_FindWidgetByResourceId(node, 0x370);
    rumble = Node_FindWidgetByResourceId(node, 0x384);
    g_optionsShortcutScreen->rumbleIcon = rumble;
    Widget_SetWidgetFlag08(rumble, 1);
    (Node_FindWidgetByResourceId(node, 0x385))->alpha = 0x6E;
    pak = Node_FindWidgetByResourceId(node, 0x374);
    g_optionsShortcutScreen->pakIcon = pak;
    Widget_SetWidgetFlag08(pak, 0);
    SmpButton_WrapButtonWidget(0x377);
    SmpButton_WrapButtonWidget(0x37C);
    firstListHandle = SmpButton_CreateListWidget(0x375, 0x376);
    g_optionsShortcutScreen->firstList = firstListHandle;
    SmpButton_AppendListText(firstListHandle, g_toggleListClearLabel[0]);
    SmpButton_AppendListText(g_optionsShortcutScreen->firstList, g_optionsFirstListPrimaryLabel);
    SmpButton_AppendListText(g_optionsShortcutScreen->firstList, g_optionsFirstListSecondaryLabel);
    settings = &g_gameSettings;
    SmpButton_SelectListEntry(g_optionsShortcutScreen->firstList, settings->bloodMode);
    secondListHandle = SmpButton_CreateListWidget(0x378, 0x379);
    g_optionsShortcutScreen->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, g_optionsResolutionFirstChoiceLabels[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsShortcutScreen->secondList, g_optionsResolutionSecondChoiceLabels);
        SmpButton_AppendListText(g_optionsShortcutScreen->secondList, g_optionsResolutionThirdChoiceLabels);
    }
    SmpButton_SelectListEntry(g_optionsShortcutScreen->secondList, settings->slots[7].secondListMode);
    slider = SmpSlider_CreateSliderWidget(0x37A, 0x37B, 0x80);
    g_optionsShortcutScreen->slider = slider;

    SmpSlider_SetSliderItem(slider, settings->lightingGamma);
    switch (settings->controllerMode) {
    case 0:
        if (ScenarioSetup_IsCupSelected() == 0) {
            Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, 0x37E), 1);
        }
        handle = Node_FindWidgetByResourceId(node, 0x380);
        Widget_SetWidgetFlag100(handle, 1);
        for (i = 0; i < 8; i++) {
            if (settings->slots[i].enabled == 1 && settings->slots[i].controller == 1) {
                Widget_SetWidgetFlag100(handle, 0);
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, 0x380), 1);
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, 0x37E), 1);
        break;
    }
    SmpButton_WrapButtonWidget(0x380);
    SmpButton_WrapButtonWidget(0x37D);
    SmpButton_WrapButtonWidget(0x37E);
    SmpButton_WrapButtonWidget(0x37F);
    g_optionsShortcutScreen->state = 0;
    Tsmos_DeactivateControllerState();
    Frontend_InitMenuImage(g_optionsShortcutScreen, 0x67, 0, 0, 0);
    Frontend_StartMenuImageTransition(g_optionsShortcutScreen);
    g_optionsShortcutScreen->cursor = 0;
    g_optionsShortcutScreen->selection = -1;
    Widget_SetWidgetFlag08(node, 0);
    g_gameSession.clockPaused = 1;
    g_selectionMessageReply.ready = 0;
    g_selectionMessageReply.value = -1;
    Menu_ConfigureOptionsCamera();
    prompt = Node_FindWidgetByResourceId(node, 0x371);
    g_optionsShortcutScreen->prompt = prompt;
    Widget_SetWidgetFlag08(prompt, 1);
    return 0;
}

#endif

/* 80408AC4_24.CPP */
#if defined(VERSION_DE)
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "MENU/SCROLL.H"
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
struct MenuResourceWidget;
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern Shared_OptionsScreen *g_optionsShortcutScreen;
extern Shared_MenuReply g_selectionMessageReply;
/* Localized label pointers for the memory-mode list (rev1 g_optionsResolutionFirstChoiceLabels..g_optionsResolutionThirdChoiceLabels). */
extern u8 *g_optionsSecondListPrimaryLabels[1];
extern u8 *g_optionsSecondListSecondaryLabels;
extern u8 *g_optionsSecondListTertiaryLabels;
extern void *Cache_AllocateMemory(s32);
extern void Widget_SetWidgetFlag08(void *, s32);
extern void Widget_SetWidgetFlag100(void *, s32);
extern s32 Defs_GetMemorySize(void);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);
extern s32 ScenarioSetup_IsCupSelected(void);
extern void Tsmos_DeactivateControllerState(void);
extern void Frontend_InitMenuImage(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void Frontend_StartMenuImageTransition(Shared_OptionsScreen *);
/* German Options_OpenOptionsScreen: the same options screen without the first (blood) list; the
   widget resource ids are 6..0x14 lower and settings is first taken after the memory-mode labels. */
s32 Menu_OpenGameOptionsScreen(void *node) {
    Shared_Game *settings;
    MenuWidget *handle;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *rumble;
    MenuWidget *pak;
    MenuWidget *prompt;
    MenuListWidget *secondListHandle;
    void *slider;
    s32 i;
    s32 rem;

    g_optionsShortcutScreen = Cache_AllocateMemory(0x6C);
    g_optionsShortcutScreen->sound = SoundElement_GetMusicPlaybackEnabled();
    SoundElement_SetMusicPlaybackEnabled(0x34);
    SoundElement_DisableMusicGainOverride();
    SoundElement_StopAudioExceptKey(-1);
    g_optionsShortcutScreen->page = 1;
    g_optionsShortcutScreen->pages = 4;
    g_optionsShortcutScreen->leftTab = Node_FindWidgetByResourceId(node, 0x37B);
    g_optionsShortcutScreen->leftTab->x -= g_optionsShortcutScreen->leftTab->width;
    g_optionsShortcutScreen->leftStep = g_optionsShortcutScreen->leftTab->width / 4;
    rem = g_optionsShortcutScreen->leftTab->width - g_optionsShortcutScreen->leftStep * 4;
    g_optionsShortcutScreen->leftTab->x += rem;
    g_optionsShortcutScreen->rightTab = Node_FindWidgetByResourceId(node, 0x382);
    g_optionsShortcutScreen->rightTab->x += g_optionsShortcutScreen->rightTab->width;
    g_optionsShortcutScreen->rightStep = g_optionsShortcutScreen->rightTab->width / 4;
    rem = g_optionsShortcutScreen->rightTab->width - g_optionsShortcutScreen->rightStep * 4;
    g_optionsShortcutScreen->rightTab->x -= rem;
    g_optionsShortcutScreen->title = SmpFlicker_CreateFlickerWidget(0x36F, 0x6E);
    marker = Node_FindWidgetByResourceId(node, 0x36E);
    g_optionsShortcutScreen->marker = marker;
    Widget_SetWidgetFlag08(marker, 0);
    (Node_FindWidgetByResourceId(node, 0x380))->alpha = 0x6E;
    header = Node_FindWidgetByResourceId(node, 0x381);
    g_optionsShortcutScreen->header = header;
    header->alpha = 0x8C;
    g_optionsShortcutScreen->footer = Node_FindWidgetByResourceId(node, 0x36C);
    rumble = Node_FindWidgetByResourceId(node, 0x37E);
    g_optionsShortcutScreen->rumbleIcon = rumble;
    Widget_SetWidgetFlag08(rumble, 1);
    (Node_FindWidgetByResourceId(node, 0x37F))->alpha = 0x6E;
    pak = Node_FindWidgetByResourceId(node, 0x370);
    g_optionsShortcutScreen->pakIcon = pak;
    Widget_SetWidgetFlag08(pak, 0);
    SmpButton_WrapButtonWidget(0x379);
    SmpButton_WrapButtonWidget(0x37A);
    secondListHandle = SmpButton_CreateListWidget(0x377, 0x378);
    g_optionsShortcutScreen->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, g_optionsSecondListPrimaryLabels[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsShortcutScreen->secondList, g_optionsSecondListSecondaryLabels);
        SmpButton_AppendListText(g_optionsShortcutScreen->secondList, g_optionsSecondListTertiaryLabels);
    }
    settings = &g_gameSettings;
    SmpButton_SelectListEntry(g_optionsShortcutScreen->secondList, settings->slots[7].secondListMode);
    slider = SmpSlider_CreateSliderWidget(0x371, 0x372, 0x80);
    g_optionsShortcutScreen->slider = slider;

    SmpSlider_SetSliderItem(slider, settings->lightingGamma);
    switch (settings->controllerMode) {
    case 0:
        if (ScenarioSetup_IsCupSelected() == 0) {
            Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, 0x374), 1);
        }
        handle = Node_FindWidgetByResourceId(node, 0x376);
        Widget_SetWidgetFlag100(handle, 1);
        for (i = 0; i < 8; i++) {
            if (settings->slots[i].enabled == 1 && settings->slots[i].controller == 1) {
                Widget_SetWidgetFlag100(handle, 0);
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, 0x376), 1);
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, 0x374), 1);
        break;
    }
    SmpButton_WrapButtonWidget(0x376);
    SmpButton_WrapButtonWidget(0x373);
    SmpButton_WrapButtonWidget(0x374);
    SmpButton_WrapButtonWidget(0x375);
    g_optionsShortcutScreen->state = 0;
    Tsmos_DeactivateControllerState();
    Frontend_InitMenuImage(g_optionsShortcutScreen, 0x67, 0, 0, 0);
    Frontend_StartMenuImageTransition(g_optionsShortcutScreen);
    g_optionsShortcutScreen->cursor = 0;
    g_optionsShortcutScreen->selection = -1;
    Widget_SetWidgetFlag08(node, 0);
    g_gameSession.clockPaused = 1;
    g_selectionMessageReply.ready = 0;
    g_selectionMessageReply.value = -1;
    Menu_ConfigureOptionsCamera();
    prompt = Node_FindWidgetByResourceId(node, 0x36D);
    g_optionsShortcutScreen->prompt = prompt;
    Widget_SetWidgetFlag08(prompt, 1);
    return 0;
}
#endif
