#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/LONE/D_80152789.H"
#include "SYSTEM/8025E280.H"
#include "COMMON/S1_5.H"
#include "MENU/80406A88_6.H"

/* 80408AC4_21.CPP */
#if defined(VERSION_DE)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern ResidentEventHandlerEntry D_800EB1A4[];

s32 Menu_DispatchGermanJoinOptionsEvent(MenuWidget *pThis, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    for (i = 0; D_800EB1A4[i].handler != 0; i++) {
        if (D_800EB1A4[i].event == event &&
            (D_800EB1A4[i].actorKind == pThis->resource || D_800EB1A4[i].actorKind == 30000)) {
            return D_800EB1A4[i].handler(pThis, event, arg2, arg3, arg4);
        }
    }
    return 0;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_8041F138_de_padding_185138[8] = { 0x00, 0x00, 0x20, 0x21, 0x8F, 0xAA, 0x00, 0x40 };
#endif

/* 80408CB0_28.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "MENU/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
struct MenuFadeWidget;
struct MenuResourceWidget;
/* Per-language label pointer tables, indexed by the settings language byte (0x581). */
extern u8 *D_800E1C14[];
extern u8 *D_800D2134[];
extern u8 *D_800D2138[];
extern u8 *D_800D213C[];
extern void *Cache_AllocateMemory(s32);
extern s32 Defs_GetMemorySize(void);
extern struct MenuFadeWidget *SmpFade_CreateFadeWidget(s32, s32);
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);
extern void Tsmos_DeactivateControllerState(void);
#endif

#if defined(VERSION_EU)
extern OptionsCommitContext *g_optionsPage;
/* PAL Options_CreateOptionsPage: the three option lists take their labels from the per-language tables
   indexed by settings->language. */
s32 Menu_CreateEuropeanSettingsPage(void) {
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
    settings = &D_801462C8;
    g_optionsPage->unk_C = firstList;
    SmpButton_AppendListText(firstList, D_800E1C14[settings->language]);
    SmpButton_AppendListText(g_optionsPage->unk_C, D_800E1C34[settings->language]);
    SmpButton_AppendListText(g_optionsPage->unk_C, D_800E1C44[settings->language]);
    SmpButton_SelectListEntry(g_optionsPage->unk_C, settings->firstListMode);
    secondList = SmpButton_CreateListWidget(0x55, 0x56);
    g_optionsPage->unk_10 = secondList;
    SmpButton_AppendListText(secondList, D_auto_800E1C54[settings->language]);
    SmpButton_AppendListText(g_optionsPage->unk_10, D_auto_800E1C64[settings->language]);
    SmpButton_SelectListEntry(g_optionsPage->unk_10, settings->unknown1F);
    thirdList = SmpButton_CreateListWidget(0x51, 0x52);
    g_optionsPage->unk_14 = thirdList;
    SmpButton_AppendListText(thirdList, D_800D2134[settings->language]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->unk_14, D_800D2138[settings->language]);
        SmpButton_AppendListText(g_optionsPage->unk_14, D_800D213C[settings->language]);
    }
    SmpButton_SelectListEntry(g_optionsPage->unk_14, settings->reserved580);
    slider = SmpSlider_CreateSliderWidget(0x53, 0x54, 0x80);
    g_optionsPage->unk_8 = slider;
    SmpSlider_SetSliderItem(slider, settings->buttons);
    SmpButton_WrapButtonWidget(0x50);
    title = SmpFlicker_CreateFlickerWidget(0x4F, 0x6E);
    g_optionsPage->state = 3;
    g_optionsPage->title = title;
    g_optionsPage->value = -1;
    return 0;
}
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
#define MENU_RESOURCE_ID(id) ((id) + 4)
#else
#define MENU_RESOURCE_ID(id) (id)
#endif
/* Game-options screen state (0x10 bytes, rev1 SliderScreen in FRONTEND/80423280_30.CPP). */
typedef struct GameOptionsScreen {
    void *slider;
    void *firstList;
    void *secondList;
    s32 state;
} GameOptionsScreen;
extern GameOptionsScreen *D_800E4514;
/* PAL Frontend_CreateGameOptionsScreen: the list labels come from the per-language tables. */
s32 Menu_CreateSessionSettingsControls(void) {
    Shared_Game *settings;
    void *firstList;
    void *secondList;
    void *slider;

    D_800E4514 = Cache_AllocateMemory(0x10);
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x1BD));
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x1C2));
    firstList = SmpButton_CreateListWidget(MENU_RESOURCE_ID(0x1BB), MENU_RESOURCE_ID(0x1BC));
    settings = &D_801462C8;
    D_800E4514->firstList = firstList;
    SmpButton_AppendListText(firstList, D_800E1C14[settings->language]);
    SmpButton_AppendListText(D_800E4514->firstList, D_800E1C34[settings->language]);
    SmpButton_AppendListText(D_800E4514->firstList, D_800E1C44[settings->language]);
    SmpButton_SelectListEntry(D_800E4514->firstList, settings->firstListMode);
    secondList = SmpButton_CreateListWidget(MENU_RESOURCE_ID(0x1BE), MENU_RESOURCE_ID(0x1BF));
    D_800E4514->secondList = secondList;
    SmpButton_AppendListText(secondList, D_800D2134[settings->language]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4514->secondList, D_800D2138[settings->language]);
        SmpButton_AppendListText(D_800E4514->secondList, D_800D213C[settings->language]);
    }
    SmpButton_SelectListEntry(D_800E4514->secondList, settings->reserved580);
    slider = SmpSlider_CreateSliderWidget(MENU_RESOURCE_ID(0x1C0), MENU_RESOURCE_ID(0x1C1), 0x80);
    D_800E4514->slider = slider;
    SmpSlider_SetSliderItem(slider, settings->buttons);
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x1C3));
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x1C4));
    D_800E4514->state = 0;
    Tsmos_DeactivateControllerState();
    return 0;
}
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_OPTIONSSCREEN.H"
extern Shared_OptionsScreen *D_800E4518;
extern Shared_MenuReply D_80154020;
extern MenuWidget *Node_FindWidgetByResourceId(void *, s32);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void Widget_SetWidgetFlag100(void *, s32);
extern void Frontend_InitMenuImage(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void Frontend_StartMenuImageTransition(Shared_OptionsScreen *);
/* PAL Options_OpenOptionsScreen: the list labels come from the per-language tables. */
s32 Menu_OpenLocalizedGameOptions(void *node) {
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

    D_800E4518 = Cache_AllocateMemory(0x6C);
    D_800E4518->sound = func_8025E2C4_de();
    func_8025E2D4_de(0x34);
    func_8025E384_de();
    func_8025E214_de(-1);
    D_800E4518->page = 1;
    D_800E4518->pages = 4;
    D_800E4518->leftTab = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x381));
    D_800E4518->leftTab->x -= D_800E4518->leftTab->width;
    D_800E4518->leftStep = D_800E4518->leftTab->width / 4;
    rem = D_800E4518->leftTab->width - D_800E4518->leftStep * 4;
    D_800E4518->leftTab->x += rem;
    D_800E4518->rightTab = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x388));
    D_800E4518->rightTab->x += D_800E4518->rightTab->width;
    D_800E4518->rightStep = D_800E4518->rightTab->width / 4;
    rem = D_800E4518->rightTab->width - D_800E4518->rightStep * 4;
    D_800E4518->rightTab->x -= rem;
    D_800E4518->title = SmpFlicker_CreateFlickerWidget(MENU_RESOURCE_ID(0x373), 0x6E);
    marker = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x372));
    D_800E4518->marker = marker;
    Frontend_SetWidgetFlag08(marker, 0);
    (Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x386)))->alpha = 0x6E;
    header = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x387));
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x370));
    rumble = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x384));
    D_800E4518->rumbleIcon = rumble;
    Frontend_SetWidgetFlag08(rumble, 1);
    (Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x385)))->alpha = 0x6E;
    pak = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x374));
    D_800E4518->pakIcon = pak;
    Frontend_SetWidgetFlag08(pak, 0);
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x377));
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x37C));
    firstListHandle = SmpButton_CreateListWidget(MENU_RESOURCE_ID(0x375), MENU_RESOURCE_ID(0x376));
    D_800E4518->firstList = firstListHandle;
    settings = &D_801462C8;
    SmpButton_AppendListText(firstListHandle, D_800E1C14[settings->language]);
    SmpButton_AppendListText(D_800E4518->firstList, D_800E1C34[settings->language]);
    SmpButton_AppendListText(D_800E4518->firstList, D_800E1C44[settings->language]);
    SmpButton_SelectListEntry(D_800E4518->firstList, settings->firstListMode);
    secondListHandle = SmpButton_CreateListWidget(MENU_RESOURCE_ID(0x378), MENU_RESOURCE_ID(0x379));
    D_800E4518->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, D_800D2134[settings->language]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4518->secondList, D_800D2138[settings->language]);
        SmpButton_AppendListText(D_800E4518->secondList, D_800D213C[settings->language]);
    }
    SmpButton_SelectListEntry(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = SmpSlider_CreateSliderWidget(MENU_RESOURCE_ID(0x37A), MENU_RESOURCE_ID(0x37B), 0x80);
    D_800E4518->slider = slider;

    SmpSlider_SetSliderItem(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (ScenarioSetup_IsCupSelected() == 0) {
            Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x37E)), 1);
        }
        handle = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x380));
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
        handle = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x380));
        Widget_SetWidgetFlag100(handle, 1);
        Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x37E)), 1);
        break;
    }
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x380));
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x37D));
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x37E));
    SmpButton_WrapButtonWidget(MENU_RESOURCE_ID(0x37F));
    D_800E4518->state = 0;
    Tsmos_DeactivateControllerState();
    Frontend_InitMenuImage(D_800E4518, 0x67, 0, 0, 0);
    Frontend_StartMenuImageTransition(D_800E4518);
    D_800E4518->cursor = 0;
    D_800E4518->selection = -1;
    Frontend_SetWidgetFlag08(node, 0);
    D_8011FAC0.clockPaused = 1;
    D_80154020.ready = 0;
    D_80154020.value = -1;
    Menu_ConfigureOptionsCamera();
    prompt = Node_FindWidgetByResourceId(node, MENU_RESOURCE_ID(0x371));
    D_800E4518->prompt = prompt;
    Frontend_SetWidgetFlag08(prompt, 1);
    return 0;
}
#endif
