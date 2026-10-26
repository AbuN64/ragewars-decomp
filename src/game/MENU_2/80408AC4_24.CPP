#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"

#if defined(VERSION_DE)
#include "SYSTEM_2/8025E280.H"
#include "MENU_2/SCROLL.H"
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
struct MenuResourceWidget;
extern struct MenuResourceWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern Shared_OptionsScreen *D_800E4518;
extern Shared_MenuReply D_80154020;
/* Localized label pointers for the memory-mode list (rev1 D_800D2134..D_800D213C). */
extern u8 *D_auto_800D3488[1];
extern u8 *D_auto_800D348C;
extern u8 *D_auto_800D3490;
extern void *Cache_AllocateMemory(s32);
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void Frontend_SetWidgetFlag100(void *, s32);
extern void func_8025E384_de(void);
extern s32 Defs_GetMemorySize(void);
extern MenuListWidget *SmpButton_CreateListWidget(s32, s32);
extern void SmpButton_AppendListText(struct MenuListWidget *, u8 *);
extern void SmpButton_SelectListEntry(struct MenuListWidget *, s32);
extern MenuSliderWidget *SmpSlider_CreateSliderWidget(s32, s32, s32);
extern void SmpSlider_SetSliderItem(Scroll *, s32);
extern s32 ScenarioSetup_IsCupSelected(void);
extern void Menu_ConfigureOptionsCamera(void);
extern void Tsmos_DeactivateControllerState(void);
extern void Frontend_InitMenuImage(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void Frontend_StartMenuImageTransition(Shared_OptionsScreen *);
/* German Menu_OpenOptionsScreen: the same options screen without the first (language) list; the
   widget resource ids are 6..0x14 lower and settings is first taken after the memory-mode labels. */
s32 func_804224E0_de(void *node) {
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

    D_800E4518 = Cache_AllocateMemory(0x6C);
    D_800E4518->sound = func_8025E2C4_de();
    func_8025E2D4_de(0x34);
    func_8025E384_de();
    func_8025E214_de(-1);
    D_800E4518->page = 1;
    D_800E4518->pages = 4;
    D_800E4518->leftTab = Frontend_FindWidgetByResourceId(node, 0x37B);
    D_800E4518->leftTab->x -= D_800E4518->leftTab->width;
    D_800E4518->leftStep = D_800E4518->leftTab->width / 4;
    rem = D_800E4518->leftTab->width - D_800E4518->leftStep * 4;
    D_800E4518->leftTab->x += rem;
    D_800E4518->rightTab = Frontend_FindWidgetByResourceId(node, 0x382);
    D_800E4518->rightTab->x += D_800E4518->rightTab->width;
    D_800E4518->rightStep = D_800E4518->rightTab->width / 4;
    rem = D_800E4518->rightTab->width - D_800E4518->rightStep * 4;
    D_800E4518->rightTab->x -= rem;
    D_800E4518->title = SmpFlicker_CreateFlickerWidget(0x36F, 0x6E);
    marker = Frontend_FindWidgetByResourceId(node, 0x36E);
    D_800E4518->marker = marker;
    Frontend_SetWidgetFlag08(marker, 0);
    (Frontend_FindWidgetByResourceId(node, 0x380))->alpha = 0x6E;
    header = Frontend_FindWidgetByResourceId(node, 0x381);
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = Frontend_FindWidgetByResourceId(node, 0x36C);
    rumble = Frontend_FindWidgetByResourceId(node, 0x37E);
    D_800E4518->rumbleIcon = rumble;
    Frontend_SetWidgetFlag08(rumble, 1);
    (Frontend_FindWidgetByResourceId(node, 0x37F))->alpha = 0x6E;
    pak = Frontend_FindWidgetByResourceId(node, 0x370);
    D_800E4518->pakIcon = pak;
    Frontend_SetWidgetFlag08(pak, 0);
    SmpButton_WrapButtonWidget(0x379);
    SmpButton_WrapButtonWidget(0x37A);
    secondListHandle = SmpButton_CreateListWidget(0x377, 0x378);
    D_800E4518->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, D_auto_800D3488[0]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4518->secondList, D_auto_800D348C);
        SmpButton_AppendListText(D_800E4518->secondList, D_auto_800D3490);
    }
    settings = &D_801462C8;
    SmpButton_SelectListEntry(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = SmpSlider_CreateSliderWidget(0x371, 0x372, 0x80);
    D_800E4518->slider = slider;

    SmpSlider_SetSliderItem(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (ScenarioSetup_IsCupSelected() == 0) {
            Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(node, 0x374), 1);
        }
        handle = Frontend_FindWidgetByResourceId(node, 0x376);
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
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(node, 0x376), 1);
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(node, 0x374), 1);
        break;
    }
    SmpButton_WrapButtonWidget(0x376);
    SmpButton_WrapButtonWidget(0x373);
    SmpButton_WrapButtonWidget(0x374);
    SmpButton_WrapButtonWidget(0x375);
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
    prompt = Frontend_FindWidgetByResourceId(node, 0x36D);
    D_800E4518->prompt = prompt;
    Frontend_SetWidgetFlag08(prompt, 1);
    return 0;
}
#endif
