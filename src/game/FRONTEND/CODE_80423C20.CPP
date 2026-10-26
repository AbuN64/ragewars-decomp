#include "FRONTEND/8040B45C_33.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "SCENE/802508E0_13.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PLAYERPROFILES.H"
#include "RESMGR/802A0888.H"

#if defined(VERSION_EU_X)
INCLUDE_ASM("ovl_80400000", Frontend_InitPlayModeMenu);
#endif

#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "COMMON/ALAUXBUS_S.H"

extern s32 D_800E4680;

/* D_80146398 is the hub's func_8041F2A0_Config array: eight 0x96-byte records at Game+0xD0.
   This unit reaches them only as settings->playerSettings and declares nothing here. */

extern void MarkMenuEventHandled(void);

extern s32 Smos_GetFocusedElementId(void);

extern void Player_InitializeProfile(char *);

extern void PAKInterface_SetScreenPhase(s32);

extern void Player_SetAchievementFlag7(char *, s32);

extern void SmpSlider_SetTransitionMode(void *, s32);

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

extern s8 D_800FEB0E[];
extern u8 D_8010EB7D[];
extern void ScenarioSetup_SetCupCategory(int);
extern void Frontend_SetSelectedStage(s32, s32);
extern void Tsmos_SetIdleTimer(f32);
extern void Tsmos_ActivateControllerState(void);
extern void *Cache_AllocateMemory(s32);
extern s32 Defs_TestBit(u8 *, s32);
extern void Frontend_SetWidgetFlag100(void *, s32);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void SmpButton_WrapButtonWidget(s32);
extern void Frontend_AdvanceActiveSlot(int *);
extern s32 Control_IsControllerConnected(s32);
extern void *SmpFade_CreateFadeWidget(s32, s32);
extern void SmpSlider_DisableTransition(void *);
extern MenuWidget *SmpFlicker_CreateFlickerWidget(s32, s32);
extern u32 Smos_GetBlockedScreenOwner(void);
extern void Frontend_RequestScreenMode(s32);
#if !defined(VERSION_EU_X)
/* Builds the options screen: clears the per-player settings, retires bots that are no longer wanted, allocates
 * the screen record in D_800E4600 and picks the button layout. The layout is 3 when any human is on a pad
 * that Defs_TestBit reports in group 0 (or the game flag 0x20000000 is set), 2 for group 1, else the
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

    ScenarioSetup_SetCupCategory(-1);
    Frontend_SetSelectedStage(0, 0);
    counters->humanWon = 0;
    Tsmos_SetIdleTimer(0.0f);
    D_801462C8.local = 1;

    for (i = 0; i < 8; i++) {
        { Shared_PlayerSettingsRecord *entry = &D_801462C8.playerSettings[i];
        entry->enabled = 0;
        entry->locked = 0; }
    }
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].player >= 0 && D_800FEB0E[i * sizeof(Profile)] == 1) {
            Player_InitializeProfile((char *)&D_80102B00[i]);
            D_80102B00[i].player = -1;
            D_800FEB0E[i * sizeof(Profile)] = 0;
        }
        XPlus_FillMemory((char *)&D_80102B00[i] + 0x83, 0, 5);
    }
    D_800E4600 = Cache_AllocateMemory(0x1C);
    Tsmos_ActivateControllerState();
    groupA = 0;
    groupB = 0;
    groupC = 0;
    for (i = 0; i < 4; i++) {
        if (D_80102B00[i].player >= 0) {
            groupA = groupA || Defs_TestBit(&D_8010EB7D[i * sizeof(Profile)], 0);
            groupB = groupB || Defs_TestBit(&D_8010EB7D[i * sizeof(Profile)], 1);
            groupC = groupC || Defs_TestBit(&D_8010EB7D[i * sizeof(Profile)], 2);
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
    title = Frontend_FindWidgetByResourceId(menu, 0x42);
    switch (layout) {
    case 2:
        SmpButton_WrapButtonWidget(0x48);
        widget = Frontend_FindWidgetByResourceId(menu, 0x4A);
        Frontend_SetWidgetFlag100(widget, 1);
        Frontend_SetWidgetFlag08(widget, 0);
        title->y = 0x33;
        title->height = 0x78;
        break;
    case 3:
        SmpButton_WrapButtonWidget(0x4A);
        SmpButton_WrapButtonWidget(0x48);
        title->y = 0x2A;
        title->height = 0x88;
        break;
    default:
        widget = Frontend_FindWidgetByResourceId(menu, 0x48);
        Frontend_SetWidgetFlag100(widget, 1);
        Frontend_SetWidgetFlag08(widget, 0);
        widget = Frontend_FindWidgetByResourceId(menu, 0x4A);
        Frontend_SetWidgetFlag100(widget, 1);
        Frontend_SetWidgetFlag08(widget, 0);
        title->y = 0x3C;
        title->height = 0x68;
        break;
    }
    i = -1;
    Frontend_AdvanceActiveSlot(&i);
    if (i < 0) {
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(menu, 0x4C), 1);
    }
    mode = Control_IsControllerConnected(0);
    if (mode != 1 || Control_IsControllerConnected(1) != mode) {
        Frontend_SetWidgetFlag100(Frontend_FindWidgetByResourceId(menu, 0x49), 1);
    }
    D_800E4600->music = SmpFade_CreateFadeWidget(0x42, 0x24);
    SmpSlider_DisableTransition(D_800E4600->music);
    SmpButton_WrapButtonWidget(0x45);
    SmpButton_WrapButtonWidget(0x46);
    SmpButton_WrapButtonWidget(0x49);
    SmpButton_WrapButtonWidget(0x4B);
    SmpButton_WrapButtonWidget(0x4C);
    SmpButton_WrapButtonWidget(0x47);
    D_800E4600->title = Frontend_FindWidgetByResourceId(menu, 0x43);
    D_800E4600->title->alpha = 0xF;
    D_800E4600->prompt = SmpFlicker_CreateFlickerWidget(0x44, 0x6E);
    if (Smos_GetBlockedScreenOwner() == 2) {
        D_800E4600->mode = 9;
    } else {
        D_800E4600->mode = 1;
    }
    D_800E4600->state = 3;
    Frontend_RequestScreenMode(0);
    return 0;
}
#endif

s32 Frontend_ApplyModeChoice(void) {
    Shared_PlayerSettingsRecord *status;
    Shared_Game *settings;

    s32 i;

    MarkMenuEventHandled();
    switch (Smos_GetFocusedElementId()) {
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
                Player_InitializeProfileSlot(i);
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
        Player_InitializeProfile((char *)D_80102B00);
        PAKInterface_SetScreenPhase(7);
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
            Player_InitializeProfileSlot(0);
            for (i = 0; i < 20; i++) {
                Player_SetAchievementFlag7((char *)D_80102B00, i);
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
            Player_InitializeProfileSlot(0);
        }
        D_801462C8.controllerMode = 4;
        D_800E4680 = 0;
        break;
    default:
        return 0;
    }
    SmpSlider_SetTransitionMode(D_800E4600->music, 2);
    return 0;
}

s32 Frontend_DestroyPlayModeMenu(void) {
    Cache_FreeMemory(D_800E4600);
    D_800E4600 = 0;
    return 0;
}
