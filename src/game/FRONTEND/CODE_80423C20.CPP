#include "include_asm.h"
#include "SCENE/802508E0_13.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PLAYERPROFILES.H"
#include "RESMGR/802A0888.H"


#if !defined(NON_MATCHING) && !defined(VERSION_US_REV1)
INCLUDE_ASM("ovl_80400000", Frontend_InitPlayModeMenu);
#endif


#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "COMMON/ALAUXBUS_S.H"
struct CompactOptionsScreen {
    s32 slider;
    s32 first_list;
    s32 second_list;
    s32 state;
};

extern s32 D_800E4680;

/* D_80146398 is the hub's func_8041F2A0_Config array: eight 0x96-byte records at Game+0xD0.
   This unit reaches them only as settings->playerSettings and declares nothing here. */

extern void MarkMenuEventHandled(void);

extern s32 func_80299A08_de(void);

extern void func_8022EF30_de(char *);

extern void func_80434FB4_de(s32);

extern void func_8022F5A4_de(char *, s32);

extern void func_8041A430_de(void *, s32);

/* Applies the play mode picked on the front-end menu: sets the next screen, the controller mode and which players
 * join, then hands the screen record on. */
/* The options screen record D_800E4600 (Frontend_InitPlayModeMenu allocates its 0x1C bytes): the menu music handle, the
 * prompt and title widgets, the controller mode, the screen state and the screen Frontend_ApplyModeChoice goes to. */
typedef struct OptionsScreen {
    void *music;
    void *prompt;
    MenuWidget *title;
    s32 mode;
    s32 pad10;
    s32 state;
    s32 nextScreen;
} OptionsScreen;
extern OptionsScreen *D_800E4600;

#if defined(NON_MATCHING) || defined(VERSION_US_REV1)
#if 1
extern u8 D_801462E5;
extern u8 D_801468A0[];
extern s8 D_800FEB0E[];
extern u8 D_8010EB7D[];
extern void func_8042AFC0_de(int);
extern void func_8042E9A0_de(s32, s32);
extern void func_802A2400_de(f32);
extern void func_802A2360_de(void);
extern void *func_8025305C_de(s32);
extern s32 func_80265650_de(u8 *, s32);
extern MenuWidget *func_8040EC30_de(void *, s32);
extern void func_8040E950_de(void *, s32);
extern void func_8040E8D8_de(void *, s32);
extern void func_8041B110_de(s32);
extern void func_8041DB30_de(int *);
extern s32 func_80264614_de(s32);
extern void *func_8041A280_de(s32, s32);
extern void func_8041A488_de(void *);
extern MenuWidget *func_80419E54_de(s32, s32);
extern u32 func_802999F4_de(void);
extern void func_8040C428_de(s32);
/* Builds the options screen: clears the per-player settings, retires bots that are no longer wanted, allocates
 * the screen record in D_800E4600 and picks the button layout. The layout is 3 when any human is on a pad
 * that func_80265650_de reports in group 0 (or the game flag 0x20000000 is set), 2 for group 1, else the
 * default; it positions the first widget and shows or hides the sibling widgets. */
s32 Frontend_InitPlayModeMenu(void *menu) {
    CGameStatus *counters = &D_801462C8.counters;
    MenuWidget *title;
    MenuWidget *widget;
    s32 i;
    s32 layout;
    s32 groupA;
    s32 groupB;
    s32 groupC;
    s32 mode;

    func_8042AFC0_de(-1);
    func_8042E9A0_de(0, 0);
    counters->humanWon = 0;
    func_802A2400_de(0.0f);
    D_801462C8.local = 1;

    for (i = 0; i < 8; i++) {
        { Shared_PlayerSettingsRecord *entry = &D_801462C8.playerSettings[i];
        entry->enabled = 0;
        entry->locked = 0; }
    }
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].player >= 0 && D_800FEB0E[i * sizeof(Profile)] == 1) {
            func_8022EF30_de((char *)&D_80102B00[i]);
            D_80102B00[i].player = -1;
            D_800FEB0E[i * sizeof(Profile)] = 0;
        }
        Resmgr_FillMemory((char *)&D_80102B00[i] + 0x83, 0, 5);
    }
    D_800E4600 = func_8025305C_de(0x1C);
    func_802A2360_de();
    groupA = 0;
    groupB = 0;
    groupC = 0;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].player >= 0) {
            groupA = groupA || func_80265650_de(&D_8010EB7D[i * sizeof(Profile)], 0);
            groupB = groupB || func_80265650_de(&D_8010EB7D[i * sizeof(Profile)], 1);
            groupC = groupC || func_80265650_de(&D_8010EB7D[i * sizeof(Profile)], 2);
        }
    }
    if (D_801462C8.flags & 0x20000000) {
        groupC = 1;
        groupB = 1;
    }
    layout = 0;
    if (groupC == 1) {
        layout = 3;
    } else if (groupB == 1) {
        layout = 2;
    }
    title = func_8040EC30_de(menu, 0x42);
    switch (layout) {
    case 2:
        func_8041B110_de(0x48);
        widget = func_8040EC30_de(menu, 0x4A);
        func_8040E950_de(widget, 1);
        func_8040E8D8_de(widget, 0);
        title->y = 0x33;
        title->height = 0x78;
        break;
    case 3:
        func_8041B110_de(0x4A);
        func_8041B110_de(0x48);
        title->y = 0x2A;
        title->height = 0x88;
        break;
    default:
        widget = func_8040EC30_de(menu, 0x48);
        func_8040E950_de(widget, 1);
        func_8040E8D8_de(widget, 0);
        widget = func_8040EC30_de(menu, 0x4A);
        func_8040E950_de(widget, 1);
        func_8040E8D8_de(widget, 0);
        title->y = 0x3C;
        title->height = 0x68;
        break;
    }
    i = -1;
    func_8041DB30_de(&i);
    if (i < 0) {
        func_8040E950_de(func_8040EC30_de(menu, 0x4C), 1);
    }
    mode = func_80264614_de(0);
    if (mode != 1 || func_80264614_de(1) != mode) {
        func_8040E950_de(func_8040EC30_de(menu, 0x49), 1);
    }
    D_800E4600->music = func_8041A280_de(0x42, 0x24);
    func_8041A488_de(D_800E4600->music);
    func_8041B110_de(0x45);
    func_8041B110_de(0x46);
    func_8041B110_de(0x49);
    func_8041B110_de(0x4B);
    func_8041B110_de(0x4C);
    func_8041B110_de(0x47);
    D_800E4600->title = func_8040EC30_de(menu, 0x43);
    D_800E4600->title->alpha = 0xF;
    D_800E4600->prompt = func_80419E54_de(0x44, 0x6E);
    if (func_802999F4_de() == 2) {
        D_800E4600->mode = 9;
    } else {
        D_800E4600->mode = 1;
    }
    D_800E4600->state = 3;
    func_8040C428_de(0);
    return 0;
}
#endif
#endif

s32 Frontend_ApplyModeChoice(void) {
    Shared_PlayerSettingsRecord *status;
    Shared_Game *settings;

    s32 i;

    MarkMenuEventHandled();
    switch (func_80299A08_de()) {
    #if defined(VERSION_EU_X)
    case 0x47:
#else
    case 0x45:
#endif
        D_800E4600->nextScreen = 0x1A;
        D_801462C8.controllerMode = 0;
        break;
    #if defined(VERSION_EU_X)
    case 0x4C:
#else
    case 0x49:
#endif
        settings = &D_801462C8;
        status = settings->playerSettings;
        D_800E4600->nextScreen = 7;
        settings->controllerMode = 2;
        for (i = 0; i < 2; i++) {
            status[i].enabled = 1;
            status[i].slot = i;
            if (D_80102B00[i].player < 0) {
                func_8022F204_de(i);
            }
        }
        break;
    #if defined(VERSION_EU_X)
    case 0x48:
#else
    case 0x46:
#endif
        status = D_801462C8.playerSettings;
        status->enabled = 1;
        status[0].slot = 0;
        func_8022EF30_de((char *)D_80102B00);
        func_80434FB4_de(7);
        D_800E4600->nextScreen = 0x13;
        D_801462C8.controllerMode = 1;
        break;
    #if defined(VERSION_EU_X)
    case 0x49:
#else
    case 0x4B:
#endif
        D_800E4600->nextScreen = 0x1B;
        break;
    #if defined(VERSION_EU_X)
    case 0x4B:
#else
    case 0x47:
#endif
        D_800E4600->nextScreen = 4;
        break;
    #if defined(VERSION_EU_X)
    case 0x4A:
#else
    case 0x4C:
#endif
        D_800E4600->nextScreen = 0x10;
        break;
    #if defined(VERSION_EU_X)
    case 0x4D:
#else
    case 0x48:
#endif
        status = D_801462C8.playerSettings;
        D_800E4600->nextScreen = 7;
        status->enabled = 1;
        status[0].slot = 0;
        if (D_80102B00[0].player < 0) {
            func_8022F204_de(0);
            for (i = 0; i < 20; i++) {
                func_8022F5A4_de((char *)D_80102B00, i);
            }
        }
        D_801462C8.controllerMode = 3;
        break;
    #if defined(VERSION_EU_X)
    case 0x4E:
#else
    case 0x4A:
#endif
        status = D_801462C8.playerSettings;
        D_800E4600->nextScreen = 0xA;
        status->enabled = 1;
        status[0].slot = 0;
        if (D_80102B00[0].player < 0) {
            func_8022F204_de(0);
        }
        D_801462C8.controllerMode = 4;
        D_800E4680 = 0;
        break;
    default:
        return 0;
    }
    func_8041A430_de(D_800E4600->music, 2);
    return 0;
}

s32 func_8042418C_de(void) {
    func_802547E4_de(D_800E4600);
    D_800E4600 = 0;
    return 0;
}
