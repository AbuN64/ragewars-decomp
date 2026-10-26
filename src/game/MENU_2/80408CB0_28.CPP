#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/LONE/D_80152789.H"
#include "SYSTEM_2/8025E280.H"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#define func_8041A280_de fz_func_8041A280_de
#define func_8041B110_de fz_func_8041B110_de
#define func_8041ABC0_de fz_func_8041ABC0_de
#define func_8041A580_de fz_func_8041A580_de
#define func_8041A6EC_de fz_func_8041A6EC_de
#define func_80419E54_de fz_func_80419E54_de
#define func_8040EC30_de fz_func_8040EC30_de
typedef struct EuOptsPage_eu { void *title; void *list; void *bar; void *rowC; void *row10; void *row14; s32 pad18, pad1C, sel, count; } EuOptsPage_eu;
extern EuOptsPage_eu *g_optionsPage;
extern char *D_800E1C14[], *D_800E1C34[], *D_800E1C44[], *D_auto_800E1C54[], *D_auto_800E1C64[], *D_800D2134[], *D_800D2138[], *D_800D213C[];
extern void *Cache_AllocateMemory(); extern void *func_8041A280_de(); extern void func_8041B110_de(); extern void *func_8041ABC0_de();
extern void SmpButton_AppendListText(); extern void SmpButton_SelectListEntry(); extern u32 Defs_GetMemorySize(); extern void *func_8041A580_de();
extern void func_8041A6EC_de(); extern void *func_80419E54_de(); extern void *func_8040EC30_de();
extern char *D_auto_800DDB08[];
/* Builds the options page (0x28-byte state g_optionsPage): title, the three toggle rows (ids 0x59/0x55/0x51) labelled in the
   current language and set from the option bytes 0x1B, 0x1F and 0x580 of D_801462C8, the volume bar 0x53 and its list. Returns 0. */
s32 func_804229E0_eu(void) {
    u8 lang = D_801462C8.language;
    g_optionsPage = Cache_AllocateMemory(0x28);
    g_optionsPage->title = func_8041A280_de(0x4D, 0x4E);
    func_8041B110_de(0x57);
    func_8041B110_de(0x58);
    g_optionsPage->rowC = func_8041ABC0_de(0x59, 0x5A);
    SmpButton_AppendListText(g_optionsPage->rowC, D_800E1C14[lang]);
    SmpButton_AppendListText(g_optionsPage->rowC, D_800E1C34[lang]);
    SmpButton_AppendListText(g_optionsPage->rowC, D_800E1C44[lang]);
    SmpButton_SelectListEntry(g_optionsPage->rowC, *((u8 *)&D_801462C8 + 0x1B));
    g_optionsPage->row10 = func_8041ABC0_de(0x55, 0x56);
    SmpButton_AppendListText(g_optionsPage->row10, D_auto_800E1C54[lang]);
    SmpButton_AppendListText(g_optionsPage->row10, D_auto_800E1C64[lang]);
    SmpButton_SelectListEntry(g_optionsPage->row10, *((u8 *)&D_801462C8 + 0x1F));
    g_optionsPage->row14 = func_8041ABC0_de(0x51, 0x52);
    SmpButton_AppendListText(g_optionsPage->row14, D_800D2134[lang]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(g_optionsPage->row14, D_800D2138[lang]);
        SmpButton_AppendListText(g_optionsPage->row14, D_800D213C[lang]);
        SmpButton_SelectListEntry(g_optionsPage->row14, *((u8 *)&D_801462C8 + 0x580));
    }
    g_optionsPage->bar = func_8041A580_de(0x53, 0x54, 0x80);
    func_8041A6EC_de(g_optionsPage->bar, *(s32 *)((u8 *)&D_801462C8 + 0x10));
    func_8041B110_de(0x50);
    g_optionsPage->list = func_80419E54_de(0x4F, 0x6E);
    g_optionsPage->count = 3;
    g_optionsPage->sel = -1;
    return 0;
}
#undef func_8041A280_de
#undef func_8041B110_de
#undef func_8041ABC0_de
#undef func_8041A580_de
#undef func_8041A6EC_de
#undef func_80419E54_de
#undef func_8040EC30_de
#else
INCLUDE_ASM("ovl_80400000", func_804229E0_eu);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "TYPES.H"
extern MenuListWidget *func_8041ABC0_de(s32, s32);
extern void SmpButton_AppendListText(); /* draft callers pass the list, and the second draft also a text */
extern void SmpButton_SelectListEntry(MenuListWidget *, s32);
extern s32 Defs_GetMemorySize(void);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);
extern SelectionScreenState *D_800E4514;

s32 func_80422C58_eu(void) {
    MenuWidget *widget;
    void *scroll;
    void *temp_v0;

    D_800E4514 = Cache_AllocateMemory(0x10);
    func_8041B110_de(0x1BD);
    func_8041B110_de(0x1C2);
    temp_v0 = func_8041ABC0_de(0x1BB, 0x1BC);
    D_800E4514->unk4 = temp_v0;
    SmpButton_AppendListText(temp_v0);
    SmpButton_AppendListText(D_800E4514->unk4);
    SmpButton_AppendListText(D_800E4514->unk4);
    SmpButton_SelectListEntry(D_800E4514->unk4, (s32) D_801462C8.firstListMode);
    widget = func_8041ABC0_de(0x1BE, 0x1BF);
    D_800E4514->players[0].highlight = widget;
    SmpButton_AppendListText(widget);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4514->players[0].highlight);
        SmpButton_AppendListText(D_800E4514->players[0].highlight);
    }
    SmpButton_SelectListEntry(D_800E4514->players[0].highlight, (s32) D_801462C8.slots[7].secondListMode);
    scroll = func_8041A580_de(0x1C0, 0x1C1, 0x80);
    D_800E4514->screen = scroll;
    func_8041A6EC_de(scroll, D_801462C8.buttons);
    func_8041B110_de(0x1C3);
    func_8041B110_de(0x1C4);
    D_800E4514->players[0].unk4 = 0;
    func_802A2394_de();
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80422C58_eu);
#endif
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "MENU_2/SCROLL.H"
#include "TYPES.H"
#include "MENU/OPTIONS_TYPES.H"



#include "COMMON/SHARED_GAMESLOT.H"

extern Shared_OptionsScreen *D_800E4518;

extern char *D_800D2124;
extern char *D_800D2128;
extern char *D_800D2134[];
extern char *D_800E1C14[];
extern char *D_800E1C34[];
extern char *D_800E1C44[];
extern char *D_800D2138[];
extern char *D_800D213C[];
extern s32 D_80154020[2];


extern void func_8025E384_de(void);

extern void Frontend_SetWidgetFlag100(MenuWidget *, s32);
extern void func_8041B110_de(s32);
extern s32 ScenarioSetup_IsCupSelected(void);
extern void func_8043C210_de(Shared_OptionsScreen *, s32, s32, s32, s32);
extern void func_8043C278_de(Shared_OptionsScreen *);

s32 func_80422E34_eu(void *node) {
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
    D_800E4518->leftTab = func_8040EC30_de(node, 0x381);
    D_800E4518->leftTab->x -= D_800E4518->leftTab->width;
    D_800E4518->leftStep = D_800E4518->leftTab->width / 4;
    rem = D_800E4518->leftTab->width - D_800E4518->leftStep * 4;
    D_800E4518->leftTab->x += rem;
    D_800E4518->rightTab = func_8040EC30_de(node, 0x388);
    D_800E4518->rightTab->x += D_800E4518->rightTab->width;
    D_800E4518->rightStep = D_800E4518->rightTab->width / 4;
    rem = D_800E4518->rightTab->width - D_800E4518->rightStep * 4;
    D_800E4518->rightTab->x -= rem;
    D_800E4518->title = func_80419E54_de(0x373, 0x6E);
    marker = func_8040EC30_de(node, 0x372);
    D_800E4518->marker = marker;
    Frontend_SetWidgetFlag08(marker, 0);
    (func_8040EC30_de(node, 0x386))->alpha = 0x6E;
    header = func_8040EC30_de(node, 0x387);
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = func_8040EC30_de(node, 0x370);
    rumble = func_8040EC30_de(node, 0x384);
    D_800E4518->rumbleIcon = rumble;
    Frontend_SetWidgetFlag08(rumble, 1);
    (func_8040EC30_de(node, 0x385))->alpha = 0x6E;
    pak = func_8040EC30_de(node, 0x374);
    D_800E4518->pakIcon = pak;
    Frontend_SetWidgetFlag08(pak, 0);
    func_8041B110_de(0x377);
    func_8041B110_de(0x37C);
    firstListHandle = func_8041ABC0_de(0x375, 0x376);
    D_800E4518->firstList = firstListHandle;
    SmpButton_AppendListText(firstListHandle, D_800E1C14[g_languageIndex]);
    SmpButton_AppendListText(D_800E4518->firstList, D_800E1C34[g_languageIndex]);
    SmpButton_AppendListText(D_800E4518->firstList, D_800E1C44[g_languageIndex]);
    settings = &D_801462C8;
    SmpButton_SelectListEntry(D_800E4518->firstList, settings->firstListMode);
    secondListHandle = func_8041ABC0_de(0x378, 0x379);
    D_800E4518->secondList = secondListHandle;
    SmpButton_AppendListText(secondListHandle, D_800D2134[g_languageIndex]);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText(D_800E4518->secondList, D_800D2138[g_languageIndex]);
        SmpButton_AppendListText(D_800E4518->secondList, D_800D213C[g_languageIndex]);
    }
    SmpButton_SelectListEntry(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = func_8041A580_de(0x37A, 0x37B, 0x80);
    D_800E4518->slider = slider;

    func_8041A6EC_de(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (ScenarioSetup_IsCupSelected() == 0) {
            Frontend_SetWidgetFlag100(func_8040EC30_de(node, 0x37E), 1);
        }
        handle = func_8040EC30_de(node, 0x380);
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
        Frontend_SetWidgetFlag100(func_8040EC30_de(node, 0x380), 1);
        Frontend_SetWidgetFlag100(func_8040EC30_de(node, 0x37E), 1);
        break;
    }
    func_8041B110_de(0x380);
    func_8041B110_de(0x37D);
    func_8041B110_de(0x37E);
    func_8041B110_de(0x37F);
    D_800E4518->state = 0;
    func_802A2394_de();
    func_8043C210_de(D_800E4518, 0x67, 0, 0, 0);
    func_8043C278_de(D_800E4518);
    D_800E4518->cursor = 0;
    D_800E4518->selection = -1;
    Frontend_SetWidgetFlag08(node, 0);
    D_8011FAC0.clockPaused = 1;
    D_80154020[1] = 0;
    D_80154020[0] = -1;
    func_804221E8_de();
    prompt = func_8040EC30_de(node, 0x371);
    D_800E4518->prompt = prompt;
    Frontend_SetWidgetFlag08(prompt, 1);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80422E34_eu);
#endif
#endif
