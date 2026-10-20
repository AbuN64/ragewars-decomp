#include "include_asm.h"
#include "SYSTEM_2/8025E280.H"

#if defined(VERSION_EU)
INCLUDE_ASM("ovl_80400000", func_804229E0_eu);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU_2/SCROLL.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "TYPES.H"
void *func_8041ABC0_de(s32 arg0, s32 arg1);
void func_8041AD34_de(void *menu);
void func_8041AD10_de(void *menu, s32 index);
u32 func_80265350_de(void);
void *func_8041A580_de(s32 arg0, s32 arg1, s32 arg2);
void func_8041A6EC_de(struct Scroll *scroll, s32 item);
extern SelectionScreenState *D_800E4514;

s32 func_80422C58_eu(void) {
    MenuWidget *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0;

    D_800E4514 = func_8025305C_de(0x10);
    func_8041B110_de(0x1BD);
    func_8041B110_de(0x1C2);
    temp_v0 = func_8041ABC0_de(0x1BB, 0x1BC);
    D_800E4514->unk4 = temp_v0;
    func_8041AD34_de(temp_v0);
    func_8041AD34_de(D_800E4514->unk4);
    func_8041AD34_de(D_800E4514->unk4);
    func_8041AD10_de(D_800E4514->unk4, (s32) D_801462C8.firstListMode);
    temp_v0_2 = func_8041ABC0_de(0x1BE, 0x1BF);
    D_800E4514->players[0].highlight = temp_v0_2;
    func_8041AD34_de(temp_v0_2);
    if (func_80265350_de() != 0x400000) {
        func_8041AD34_de(D_800E4514->players[0].highlight);
        func_8041AD34_de(D_800E4514->players[0].highlight);
    }
    func_8041AD10_de(D_800E4514->players[0].highlight, (s32) D_801462C8.slots[7].secondListMode);
    temp_v0_3 = func_8041A580_de(0x1C0, 0x1C1, 0x80);
    D_800E4514->screen = temp_v0_3;
    func_8041A6EC_de(temp_v0_3, D_801462C8.buttons);
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
typedef struct Shared_OptionsScreen Shared_OptionsScreen;
struct Shared_OptionsScreen {
    u32 unknown00[7];
    s32 cursor;
    MenuWidget *leftTab;
    s32 leftStep;
    MenuWidget *rightTab;
    s32 rightStep;
    s32 page;
    s32 pages;
    s32 title;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *footer;
    MenuWidget *pakIcon;
    MenuWidget *rumbleIcon;
    s32 slider;
    MenuListWidget *firstList;
    MenuListWidget *secondList;
    s32 state;
    s32 selection;
    s32 sound;
    MenuWidget *prompt;
};
typedef struct Shared_MenuReply Shared_MenuReply;
struct Shared_MenuReply {
    s32 value;
    s32 ready;
};
typedef struct Shared_MenuObject Shared_MenuObject;
struct Shared_MenuObject {
    u8 unknown00[0x17C1];
    u8 language;
    u8 unknown17C2[0x2E];
};
typedef struct Shared_MenuData Shared_MenuData;
struct Shared_MenuData {
    u32 unknown00[18];
    Shared_MenuObject object;
    s32 stage;
    u32 unknown183C[6];
    s32 pause;
};

#include "COMMON/SHARED_GAMESLOT.H"

extern Shared_OptionsScreen *D_800E4518;
extern Shared_Game D_801462C8;

extern char *D_800D2124;
extern char *D_800D2128;
extern char *D_800D2134[];
extern char *D_800E1C14[];
extern char *D_800E1C34[];
extern char *D_800E1C44[];
extern u8 D_80152789;
extern char *D_800D2138[];
extern char *D_800D213C[];
extern s32 D_80146894;
extern s32 D_80154020[2];


extern void func_8025E384_de(void);

extern void func_8040E950_de(MenuWidget *, s32);
extern void func_8041B110_de(s32);
extern MenuListWidget *func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(MenuListWidget *, char *);
extern void func_8041AD10_de(MenuListWidget *, s32);
extern s32 func_80265350_de(void);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);
extern s32 func_8042AF28_de(void);
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

    { void *memory = func_8025305C_de(0x6C); D_800E4518 = memory; }
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
    func_8040E8D8_de(marker, 0);
    (func_8040EC30_de(node, 0x386))->alpha = 0x6E;
    header = func_8040EC30_de(node, 0x387);
    D_800E4518->header = header;
    header->alpha = 0x8C;
    D_800E4518->footer = func_8040EC30_de(node, 0x370);
    rumble = func_8040EC30_de(node, 0x384);
    D_800E4518->rumbleIcon = rumble;
    func_8040E8D8_de(rumble, 1);
    (func_8040EC30_de(node, 0x385))->alpha = 0x6E;
    pak = func_8040EC30_de(node, 0x374);
    D_800E4518->pakIcon = pak;
    func_8040E8D8_de(pak, 0);
    func_8041B110_de(0x377);
    func_8041B110_de(0x37C);
    firstListHandle = func_8041ABC0_de(0x375, 0x376);
    D_800E4518->firstList = firstListHandle;
    func_8041AD34_de(firstListHandle, D_800E1C14[D_80152789]);
    func_8041AD34_de(D_800E4518->firstList, D_800E1C34[D_80152789]);
    func_8041AD34_de(D_800E4518->firstList, D_800E1C44[D_80152789]);
    settings = &D_801462C8;
    func_8041AD10_de(D_800E4518->firstList, settings->firstListMode);
    secondListHandle = func_8041ABC0_de(0x378, 0x379);
    D_800E4518->secondList = secondListHandle;
    func_8041AD34_de(secondListHandle, D_800D2134[D_80152789]);
    if (func_80265350_de() != 0x400000) {
        func_8041AD34_de(D_800E4518->secondList, D_800D2138[D_80152789]);
        func_8041AD34_de(D_800E4518->secondList, D_800D213C[D_80152789]);
    }
    func_8041AD10_de(D_800E4518->secondList, settings->slots[7].secondListMode);
    slider = func_8041A580_de(0x37A, 0x37B, 0x80);
    D_800E4518->slider = slider;

    func_8041A6EC_de(slider, settings->buttons);
    switch (settings->controllerMode) {
    case 0:
        if (func_8042AF28_de() == 0) {
            func_8040E950_de(func_8040EC30_de(node, 0x37E), 1);
        }
        handle = func_8040EC30_de(node, 0x380);
        func_8040E950_de(handle, 1);
        for (i = 0; i < 8; i++) {
            if (settings->slots[i].enabled == 1 && settings->slots[i].controller == 1) {
                func_8040E950_de(handle, 0);
                break;
            }
        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        func_8040E950_de(func_8040EC30_de(node, 0x380), 1);
        func_8040E950_de(func_8040EC30_de(node, 0x37E), 1);
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
    func_8040E8D8_de(node, 0);
    D_80146894 = 1;
    D_80154020[1] = 0;
    D_80154020[0] = -1;
    func_804221E8_de();
    prompt = func_8040EC30_de(node, 0x371);
    D_800E4518->prompt = prompt;
    func_8040E8D8_de(prompt, 1);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80422E34_eu);
#endif
#endif
