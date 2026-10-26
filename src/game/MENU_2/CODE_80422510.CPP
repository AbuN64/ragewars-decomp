#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"
#include "SYSTEM_2/8025E280.H"

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
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
struct MenuFadeWidget;
struct MenuResourceWidget;
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
#include "COMMON/SHARED_GAMESLOT.H"

/* Builds the options-commit state: allocates its 0x28 bytes through Cache_AllocateMemory and keeps the
   record at g_optionsPage, creates the fade widget 0x4D/0x4E and the title object 0x4F/0x6E, then builds
   the three option lists 0x59/0x5A, 0x55/0x56 and 0x51/0x52, appends their localized labels, and
   selects the entry named by the game settings D_801462C8 bytes 0x1B, 0x1F and 0x580 - the third list
   gains the labels at 0x800D74B8 and 0x800D74BC only when Defs_GetMemorySize does not return 0x400000.
   The 0x80-step slider 0x53/0x54 is created and positioned at the settings' position byte, menu nodes
   0x57, 0x58 and 0x50 are released, and the record is finally armed with a selection value of -1 and
   commit state 3, returning zero. */

extern OptionsCommitContext *g_optionsPage;
/* Localized label pointers supplied to each option list. */
extern u8 *D_800D3470_de[1];
extern u8 *D_auto_800D74AC[1];
extern u8 *D_800D2124;
extern u8 *D_800D2128;
extern u8 *D_800D2134[1];
extern u8 *D_800D2138;
extern u8 *D_800D213C;
extern u8 *D_auto_800D74B0;

extern void *Cache_AllocateMemory(s32);
extern struct MenuFadeWidget *SmpFade_CreateFadeWidget(s32, s32);

extern s32 Defs_GetMemorySize(void);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);

s32 Menu_CreateOptionsPage(void) {
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
    g_optionsPage->unk_C = firstList;
    SmpButton_AppendListText(firstList, D_800D3470_de[0]);
    SmpButton_AppendListText(g_optionsPage->unk_C, D_800D2124);
    SmpButton_AppendListText(g_optionsPage->unk_C, D_800D2128);
    settings = &D_801462C8;
    SmpButton_SelectListEntry(g_optionsPage->unk_C, settings->firstListMode);
    secondList = SmpButton_CreateListWidget(0x55, 0x56);
    g_optionsPage->unk_10 = secondList;
    SmpButton_AppendListText(secondList, D_auto_800D74AC[0]);
    SmpButton_AppendListText(g_optionsPage->unk_10, D_auto_800D74B0);
    SmpButton_SelectListEntry(g_optionsPage->unk_10, settings->unknown1F);
    thirdList = SmpButton_CreateListWidget(0x51, 0x52);
    g_optionsPage->unk_14 = thirdList;
    SmpButton_AppendListText(thirdList, D_800D2134[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->unk_14, D_800D2138);
        SmpButton_AppendListText(g_optionsPage->unk_14, D_800D213C);
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

#if defined(VERSION_US) || defined(VERSION_US_REV1)
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
extern Shared_OptionsScreen *D_800E4518;
extern Shared_MenuReply D_80154020;
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void Frontend_SetWidgetFlag100(void *, s32);
extern void func_8025E384_de(void);
extern s32 ScenarioSetup_IsCupSelected(void);
extern void Menu_ConfigureOptionsCamera(void);
extern void Tsmos_DeactivateControllerState(void);
extern void func_8043C210_de(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void func_8043C278_de(Shared_OptionsScreen *);
s32 Menu_OpenOptionsScreen(void *node) {
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
    D_800E4518->leftTab = Frontend_FindWidgetByResourceId(node, 0x381);
    D_800E4518->leftTab->x -= D_800E4518->leftTab->width;
    D_800E4518->leftStep = D_800E4518->leftTab->width / 4;
    rem = D_800E4518->leftTab->width - D_800E4518->leftStep * 4;
    D_800E4518->leftTab->x += rem;
    D_800E4518->rightTab = Frontend_FindWidgetByResourceId(node, 0x388);
    D_800E4518->rightTab->x += D_800E4518->rightTab->width;
    D_800E4518->rightStep = D_800E4518->rightTab->width / 4;
    rem = D_800E4518->rightTab->width - D_800E4518->rightStep * 4;
    D_800E4518->rightTab->x -= rem;
    D_800E4518->title = SmpFlicker_CreateFlickerWidget(0x373, 0x6E);
    marker = Frontend_FindWidgetByResourceId(node, 0x372);
    D_800E4518->marker = marker;
    Frontend_SetWidgetFlag08(marker, 0);
    (Frontend_FindWidgetByResourceId(node, 0x386))->alpha = 0x6E;
    header = Frontend_FindWidgetByResourceId(node, 0x387);
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = Frontend_FindWidgetByResourceId(node, 0x370);
    rumble = Frontend_FindWidgetByResourceId(node, 0x384);
    D_800E4518->rumbleIcon = rumble;
    Frontend_SetWidgetFlag08(rumble, 1);
    (Frontend_FindWidgetByResourceId(node, 0x385))->alpha = 0x6E;
    pak = Frontend_FindWidgetByResourceId(node, 0x374);
    D_800E4518->pakIcon = pak;
    Frontend_SetWidgetFlag08(pak, 0);
    SmpButton_WrapButtonWidget(0x377);
    SmpButton_WrapButtonWidget(0x37C);
    firstListHandle = SmpButton_CreateListWidget(0x375, 0x376);
    D_800E4518->firstList = firstListHandle;
    SmpButton_AppendListText(firstListHandle, D_800D3470_de[0]);
    SmpButton_AppendListText(D_800E4518->firstList, D_800D2124);
    SmpButton_AppendListText(D_800E4518->firstList, D_800D2128);
    settings = &D_801462C8;
    SmpButton_SelectListEntry(D_800E4518->firstList, settings->firstListMode);
    secondListHandle = SmpButton_CreateListWidget(0x378, 0x379);
    D_800E4518->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, D_800D2134[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4518->secondList, D_800D2138);
        SmpButton_AppendListText(D_800E4518->secondList, D_800D213C);
    }
    SmpButton_SelectListEntry(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = SmpSlider_CreateSliderWidget(0x37A, 0x37B, 0x80);
    D_800E4518->slider = slider;

    SmpSlider_SetSliderItem(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (ScenarioSetup_IsCupSelected() == 0) {
            Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(node, 0x37E), 1);
        }
        handle = Frontend_FindWidgetByResourceId(node, 0x380);
        Frontend_SetWidgetFlag100(handle, 1);
        for (i = 0; i < 8; i++) {
            if (settings->slots[i].enabled == 1 && settings->slots[i].controller == 1) {
                Frontend_SetWidgetFlag100(handle, 0);
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(node, 0x380), 1);
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(node, 0x37E), 1);
        break;
    }
    SmpButton_WrapButtonWidget(0x380);
    SmpButton_WrapButtonWidget(0x37D);
    SmpButton_WrapButtonWidget(0x37E);
    SmpButton_WrapButtonWidget(0x37F);
    D_800E4518->state = 0;
    Tsmos_DeactivateControllerState();
    func_8043C210_de(D_800E4518, 0x67, 0, 0, 0);
    func_8043C278_de(D_800E4518);
    D_800E4518->cursor = 0;
    D_800E4518->selection = -1;
    Frontend_SetWidgetFlag08(node, 0);
    D_8011FAC0.clockPaused = 1;
    D_80154020.ready = 0;
    D_80154020.value = -1;
    Menu_ConfigureOptionsCamera();
    prompt = Frontend_FindWidgetByResourceId(node, 0x371);
    D_800E4518->prompt = prompt;
    Frontend_SetWidgetFlag08(prompt, 1);
    return 0;
}

#endif
