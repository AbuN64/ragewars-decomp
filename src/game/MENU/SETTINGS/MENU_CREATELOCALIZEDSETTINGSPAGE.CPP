#include "include_asm.h"
#include "MENU/LOCALIZED_GAME_OPTION_CHOICES.H"
#include "COMMON/FRONTEND_RESOURCE_LOAD_STATE.H"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"

/* 80406A88_6.CPP */
#if defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/MENU_OPTIONS_AND_RESULTS.H"
#include "TYPES.H"
struct MenuFadeWidget;
struct MenuResourceWidget;
extern OptionsCommitContext *g_optionsPage;
/* Per-language label pointer tables, indexed by the settings language byte (0x581). */
extern u8 *g_optionsFirstChoiceLabels[];
extern u8 *g_optionsResolutionFirstChoiceLabels[];
extern u8 *g_optionsResolutionSecondChoiceLabels[];
extern u8 *g_optionsResolutionThirdChoiceLabels[];
extern u8 *g_optionsLocalizedShortcutText[];
extern void *Cache_AllocateMemory(s32);
extern s32 Defs_GetMemorySize(void);
extern struct MenuFadeWidget *SmpFade_CreateFadeWidget(s32, s32);
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);
extern MenuWidget *Node_FindWidgetByResourceId(void *, s32);
/* eu-x Options_CreateOptionsPage: the PAL options page with its own resource ids, plus the caption widget
   0x5E whose text is set from the per-language table g_optionsLocalizedShortcutText. */
s32 Menu_CreateLocalizedSettingsPage(void *node) {
    Shared_Game *settings;
    void *firstList;
    void *secondList;
    void *thirdList;
    void *title;
    void *slider;
    g_optionsPage = Cache_AllocateMemory(0x28);
    g_optionsPage->menu = SmpFade_CreateFadeWidget(0x4F, 0x50);
    SmpButton_WrapButtonWidget(0x52);
    SmpButton_WrapButtonWidget(0x55);
    firstList = SmpButton_CreateListWidget(0x53, 0x54);
    settings = &g_gameSettings;
    g_optionsPage->bloodModeList = firstList;
    SmpButton_AppendListText(firstList, g_optionsFirstChoiceLabels[settings->language]);
    SmpButton_AppendListText(g_optionsPage->bloodModeList, g_optionsFirstListChoiceZeroLabels[settings->language]);
    SmpButton_AppendListText(g_optionsPage->bloodModeList, g_optionsFirstListChoiceOneLabels[settings->language]);
    SmpButton_SelectListEntry(g_optionsPage->bloodModeList, settings->bloodMode);
    secondList = SmpButton_CreateListWidget(0x56, 0x57);
    g_optionsPage->twoPlayerScreenList = secondList;
    SmpButton_AppendListText(secondList, g_optionsSecondListChoiceZeroLabels[settings->language]);
    SmpButton_AppendListText(g_optionsPage->twoPlayerScreenList, g_optionsSecondListChoiceOneLabels[settings->language]);
    SmpButton_SelectListEntry(g_optionsPage->twoPlayerScreenList, settings->twoPlayerScreenPreference);
    thirdList = SmpButton_CreateListWidget(0x58, 0x59);
    g_optionsPage->resolutionList = thirdList;
    SmpButton_AppendListText(thirdList, g_optionsResolutionFirstChoiceLabels[settings->language]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->resolutionList, g_optionsResolutionSecondChoiceLabels[settings->language]);
        SmpButton_AppendListText(g_optionsPage->resolutionList, g_optionsResolutionThirdChoiceLabels[settings->language]);
    }
    SmpButton_SelectListEntry(g_optionsPage->resolutionList, settings->resolution);
    slider = SmpSlider_CreateSliderWidget(0x5A, 0x5B, 0x80);
    g_optionsPage->gammaSlider = slider;
    SmpSlider_SetSliderItem(slider, settings->lightingGamma);
    SmpButton_WrapButtonWidget(0x5D);
    Node_FindWidgetByResourceId(node, 0x5E)->text = g_optionsLocalizedShortcutText[settings->language];
    SmpButton_WrapButtonWidget(0x5C);
    title = SmpFlicker_CreateFlickerWidget(0x51, 0x6E);
    g_optionsPage->state = 3;
    g_optionsPage->title = title;
    g_optionsPage->value = -1;
    return 0;
}
#endif

/* 80408AC4_12.CPP */
#if defined(VERSION_DE)
extern char s_nodeDefaultFieldText[];
extern char s_nodeAlternateFieldText[];
typedef struct { char pad0[0x14]; char *text; } PakOperationLabelItem;
s32 Menu_SelectPakOperationActionLabel(PakOperationLabelItem *labelItem) {
    switch (g_frontendResourceLoadStage) {
    case 0:
    default:
        labelItem->text = s_nodeDefaultFieldText;
        break;
    case 3:
        labelItem->text = s_nodeDefaultFieldText;
        break;
    case 4:
        labelItem->text = s_nodeDefaultFieldText;
        break;
    case 1:
    case 2:
        labelItem->text = s_nodeAlternateFieldText;
        break;
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned char g_MenuCreatelocalizedsettingspageTrailingBytes[4] = { 0xD3, 0x1F, 0xFF, 0x0D };
#endif

/* 80408CB0_24.CPP */
#if defined(VERSION_EU)
#include "COMMON/REQUESTRECAT10.H"
extern struct CourseOptionsScreen *g_courseOptionsScreen;
extern void *Cache_AllocateMemory(s32);
extern s32 SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern void Widget_SetWidgetFlag08(MenuWidget *, s32);
extern void Tsmos_ActivateControllerState(void);

s32 Menu_CreateEuJoinOptions(void *handle) {
    MenuWidget *widget;
    s32 i;
    g_courseOptionsScreen = Cache_AllocateMemory(0x20);
    g_courseOptionsScreen->handle = handle;
    g_courseOptionsScreen->mode = SmpOverlay_CreateOverlayNode(handle, 4);
    SmpOverlay_ShowSlotById(handle, 0, 0x389);
    SmpOverlay_ShowSlotById(handle, 1, 0x389);
    SmpOverlay_ShowSlotById(handle, 2, 0x389);
    SmpOverlay_ShowSlotById(handle, 3, 0x389);
    widget = Node_FindWidgetByResourceId(handle, 0x38B);
    widget->alpha = 0x8C;
    if (Menu_GetPreviousScreenOwner(0) == 0x16) {
        Widget_SetWidgetFlag08(widget, 0);
    }
    g_courseOptionsScreen->timer = 0;
    g_courseOptionsScreen->selection = 0;
    g_courseOptionsScreen->rows[0] = Node_FindWidgetByResourceId(handle, 0x38C);
    g_courseOptionsScreen->rows[1] = Node_FindWidgetByResourceId(handle, 0x395);
    g_courseOptionsScreen->rows[2] = Node_FindWidgetByResourceId(handle, 0x396);
    g_courseOptionsScreen->step = Join_CountUsedSlots();
    for (i = 0; i < 3; i++) {
        Join_UpdateJoinRequestDisplay(i);
        Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(g_courseOptionsScreen->rows[i], 0x392), 0);
    }
    Tsmos_ActivateControllerState();
    Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(g_courseOptionsScreen->rows[g_courseOptionsScreen->selection], 0x392), 1);
    return 0;
}
#endif
