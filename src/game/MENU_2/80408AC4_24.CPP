#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "MENU_2/SCROLL.H"
#include "TYPES.H"
#include "SYSTEM_2/8025E280.H"
#include "MENU/OPTIONS_TYPES.H"



#include "COMMON/SHARED_GAMESLOT.H"

extern Shared_OptionsScreen *D_800E4518;

extern char *D_800D2124;
extern char *D_800D2128;
extern char *D_auto_800D3488;
extern char *D_auto_800D348C;
extern char *D_auto_800D3490;
extern char *D_800D2138;
extern char *D_800D213C;
extern s32 D_80154020[2];


extern void func_8025E384_de(void);

extern void Frontend_SetWidgetFlag100(MenuWidget *, s32);
extern void func_8041B110_de(s32);
extern MenuListWidget *func_8041ABC0_de(s32, s32);
extern void SmpButton_AppendListText(MenuListWidget *, char *);
extern void SmpButton_SelectListEntry(MenuListWidget *, s32);
extern s32 Defs_GetMemorySize(void);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);
extern s32 ScenarioSetup_IsCupSelected(void);
extern void func_8043C210_de(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void func_8043C278_de(Shared_OptionsScreen *);

s32 func_804224E0_de(void *node) {
    Shared_Game *settings;
    MenuWidget *handle;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *rumble;
    MenuWidget *pak;
    MenuWidget *prompt;
    MenuListWidget *firstListHandle;
    MenuListWidget *secondListHandle;
    s32 slider;
    s32 i;
    s32 rem;

    { void *memory = Cache_AllocateMemory(0x6C); D_800E4518 = memory; }
    D_800E4518->sound = func_8025E2C4_de();
    func_8025E2D4_de(0x34);
    func_8025E384_de();
    func_8025E214_de(-1);
    D_800E4518->page = 1;
    D_800E4518->pages = 4;
    D_800E4518->leftTab = Frontend_FindWidgetByResourceId(node, 0x37b);
    D_800E4518->leftTab->x -= D_800E4518->leftTab->width;
    D_800E4518->leftStep = D_800E4518->leftTab->width / 4;
    rem = D_800E4518->leftTab->width - D_800E4518->leftStep * 4;
    D_800E4518->leftTab->x += rem;
    D_800E4518->rightTab = Frontend_FindWidgetByResourceId(node, 0x382);
    D_800E4518->rightTab->x += D_800E4518->rightTab->width;
    D_800E4518->rightStep = D_800E4518->rightTab->width / 4;
    rem = D_800E4518->rightTab->width - D_800E4518->rightStep * 4;
    D_800E4518->rightTab->x -= rem;
    D_800E4518->title = func_80419E54_de(0x36f, 0x6E);
    marker = Frontend_FindWidgetByResourceId(node, 0x36e);
    D_800E4518->marker = marker;
    Frontend_SetWidgetFlag08(marker, 0);
    (Frontend_FindWidgetByResourceId(node, 0x380))->alpha = 0x6E;
    header = Frontend_FindWidgetByResourceId(node, 0x381);
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = Frontend_FindWidgetByResourceId(node, 0x36c);
    rumble = Frontend_FindWidgetByResourceId(node, 0x37e);
    D_800E4518->rumbleIcon = rumble;
    Frontend_SetWidgetFlag08(rumble, 1);
    (Frontend_FindWidgetByResourceId(node, 0x37f))->alpha = 0x6E;
    pak = Frontend_FindWidgetByResourceId(node, 0x370);
    D_800E4518->pakIcon = pak;
    Frontend_SetWidgetFlag08(pak, 0);
    func_8041B110_de(0x379);
    func_8041B110_de(0x37a);
    settings = &D_801462C8;
    secondListHandle = func_8041ABC0_de(0x377, 0x378);
    D_800E4518->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, D_auto_800D3488);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4518->secondList, D_auto_800D348C);
        SmpButton_AppendListText(D_800E4518->secondList, D_auto_800D3490);
    }
    SmpButton_SelectListEntry(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = func_8041A580_de(0x371, 0x372, 0x80);
    D_800E4518->slider = slider;

    func_8041A6EC_de(slider, settings->buttons);
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
    func_8041B110_de(0x376);
    func_8041B110_de(0x373);
    func_8041B110_de(0x374);
    func_8041B110_de(0x375);
    D_800E4518->state = 0;
    Tsmos_DeactivateControllerState();
    func_8043C210_de(D_800E4518, 0x67, 0, 0, 0);
    func_8043C278_de(D_800E4518);
    D_800E4518->cursor = 0;
    D_800E4518->selection = -1;
    Frontend_SetWidgetFlag08(node, 0);
    D_8011FAC0.clockPaused = 1;
    D_80154020[1] = 0;
    D_80154020[0] = -1;
    Menu_ConfigureOptionsCamera();
    prompt = Frontend_FindWidgetByResourceId(node, 0x36d);
    D_800E4518->prompt = prompt;
    Frontend_SetWidgetFlag08(prompt, 1);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804224E0_de);
#endif
#endif
