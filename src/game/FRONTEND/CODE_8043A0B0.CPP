#include "include_asm.h"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "RENDER_4/8026AC38.H"
#include "FRONTEND/8040B45C_32.H"
#include "RENDER_2/8025DE50_5.H"

#include "TYPES.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "FRONTEND/8041BEA8_6.H"
extern struct FourPlayerResultsScreen *D_800E59E0;
extern Shared_PlayerSettingsRecord g_playerSettings[];
extern struct RowRecAt54 D_800E3A58[];
extern struct StateFlags D_800E59E6[][19];
extern f32 D_800DDF90_de;
extern void *Cache_AllocateMemory(s32);
extern void *SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern MenuWidget *Frontend_FindWidgetByResourceId(void *, s32);
extern void Frontend_SetWidgetFlag08(MenuWidget *, s32);
extern s32 Frontend_FindKeyIndex(s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void func_8043B96C_de(void);
extern void func_8043B0CC_de(s32);
extern void Tsmos_DeactivateControllerState(void);
extern struct StateFlags D_800E5A06[][19];
extern s32 SmpFlicker_IsFlickerIdle(void *);
extern void SmpFlicker_RestoreFlickerValue(void *);
extern void SmpFlicker_StartFlicker(void *, int);
extern void SmXlate_SwitchScreen(s32);
extern void Tsmos_ActivateControllerState(void);
extern void MarkMenuEventHandled(void);

/* Construct the four-player results/loadout menu and animate its panels into view. */
s32 Frontend_CreateFourPlayerResults(void *window) {
#if defined(VERSION_DE)
    enum { slotResource = 0xC6, leftResource = 0xCC, rightResource = 0xF4,
           titleResource = 0xC9, messageResource = 0xC7 };
#elif defined(VERSION_EU_X)
    enum { slotResource = 0xCC, leftResource = 0xD2, rightResource = 0xFA,
           titleResource = 0xCF, messageResource = 0xCD };
#else
    enum { slotResource = 0xC8, leftResource = 0xCE, rightResource = 0xF6,
           titleResource = 0xCB, messageResource = 0xC9 };
#endif
    s32 player;
    s32 delta;
    struct FourPlayerResultsScreen *screen;
    MenuWidget *widget;
    MenuWidget *bar;
    s32 row;
    CVector3 scale;
    Shared_PlayerSettingsRecord *config;

    D_800E59E0 = Cache_AllocateMemory(sizeof(struct FourPlayerResultsScreen));
    D_800E59E0->window = window;
    D_800E59E0->menu = SmpOverlay_CreateOverlayNode(window, 4);
    SmpOverlay_ShowSlotById(window, 0, slotResource);
    SmpOverlay_ShowSlotById(window, 1, slotResource);
    SmpOverlay_ShowSlotById(window, 2, slotResource);
    SmpOverlay_ShowSlotById(window, 3, slotResource);
    scale.x = D_800DDF90_de;
    scale.y = D_800DDF90_de;
    scale.z = D_800DDF90_de;
    for (player = 0; player < 4; player++) {
        Shared_PlayerSettingsRecord *config;
        D_800E59E0->panels[player].state = 0;
        D_800E59E0->panels[player].selection = 5;
        bar = Frontend_FindWidgetByResourceId(D_800E59E0->window, D_800E59E6[player][1].value);
        D_800E59E0->panels[player].item = bar;
        bar->alpha = 0x64;
        Frontend_SetWidgetFlag08(bar, 0);
        widget = Frontend_FindWidgetByResourceId(D_800E59E0->window, D_800E59E6[player][0].value);
        widget->alpha = 0x6E;
        config = &g_playerSettings[player];
        if (config->enabled == 1) {
            row = Frontend_FindKeyIndex(config->character);
            scale.x = D_800E3A58[row].scale[player];
            scale.y = D_800E3A58[row].scale[player];
            scale.z = D_800E3A58[row].scale[player];
            Frontend_InitModelPreview(&D_800E59E0->panels[player], 9, config->character + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[player], D_800E3A58[row].distance[player], D_800E3A58[row].light[player]);
        }
    }
    D_800E59E0->state = 1;
    D_800E59E0->timer = 4;
    D_800E59E0->leftArrow = Frontend_FindWidgetByResourceId(window, leftResource);
    D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x - (u16)D_800E59E0->leftArrow->width;
    D_800E59E0->leftStep = D_800E59E0->leftArrow->width / 4;
    delta = D_800E59E0->leftArrow->width - D_800E59E0->leftStep * 4;
    D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x + delta;
    D_800E59E0->rightArrow = Frontend_FindWidgetByResourceId(window, rightResource);
    D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x + (u16)D_800E59E0->rightArrow->width;
    D_800E59E0->rightStep = D_800E59E0->rightArrow->width / 4;
    delta = D_800E59E0->rightArrow->width - D_800E59E0->rightStep * 4;
    D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x - delta;
    Frontend_FindWidgetByResourceId(window, titleResource)->alpha = 0x6E;
    D_800E59E0->resource = SmpFlicker_CreateFlickerWidget(messageResource, 0xFF);
    widget = Frontend_FindWidgetByResourceId(window, messageResource);
    D_800E59E0->message = widget;
    Frontend_SetWidgetFlag08(widget, 0);
    screen = D_800E59E0;
    for (player = 0; player < 4; player++) {
        config = &g_playerSettings[player];
        if (config->enabled == 1) {
            switch (config->character) {
            case 14:
            case 17:
            case 18:
                screen->panels[player].mode = 0;
                break;
            default:
                screen->panels[player].mode = 2;
                break;
            }
        }
    }
    func_8043B96C_de();
    for (player = 0; player < 4; player++) {
        config = &g_playerSettings[player];
        if (config->enabled == 1) {
            func_8043B0CC_de(player);
        }
    }
    D_800E59E0->next = -1;
    Tsmos_DeactivateControllerState();
    return 0;
}


#if defined(NON_MATCHING) || defined(VERSION_US_REV1)
extern s32 func_80439B5C_de(void *, s32, CVector3, CVector3);
extern void func_80439BE0_de(void *, CVector3);
extern void func_80439C30_de(void *, CVector3);
extern f32 D_800E1FC4, D_800DDF98_de, D_800DDF9C, D_800E1FD0, D_800E1FD4, D_800DDFA8, D_800DDFAC_de;
extern u16 D_800E19DE[];
/* Initialize four rotating result badges and reveal enabled player cards. */
s32 Frontend_StartFourPlayerResults(void) {
    CVector3 scale;
    CVector3 position;
    CVector3 rotation;
    CVector3 angularVelocity;
    struct FourPlayerResultsScreen *screen;
    MenuWidget *widget;
    s32 i;
    s32 baseAngle;
    s32 badgeOffset;
    Shared_PlayerSettingsRecord *config;
    Tsmos_SetModeOneFlag(1);
    i = 0;
    badgeOffset = (s32)&((struct FourPlayerResultsScreen *)0)->badges;
    scale.x = D_800E1FC4;
    scale.y = D_800E1FC4;
    scale.z = D_800E1FC4;
    rotation.x = 0;
    rotation.y = 0;
    rotation.z = 0;
    angularVelocity.x = 0;
    angularVelocity.z = 0;
    position.x = 0;
    position.y = 0;
    angularVelocity.y = D_800DDF98_de;
    position.z = D_800DDF9C;
    baseAngle = i;
    for (; i < 4; i++) {
        switch (i) {
        case 0:
            position.y = D_800E1FD0;
            break;
        case 1:
            position.y = D_800E1FD4;
            break;
        case 2:
            position.y = D_800DDFA8;
            break;
        case 3:
            position.y = D_800DDFAC_de;
            break;
        }
        rotation.y = (f32)(baseAngle + GraphU64_NextRandom() % 10);
        baseAngle += 0x2D;
        func_80439B5C_de((u8 *)D_800E59E0 + badgeOffset, 0, scale, position);
        func_80439BE0_de((u8 *)D_800E59E0 + badgeOffset, rotation);
        func_80439C30_de((u8 *)D_800E59E0 + badgeOffset, angularVelocity);
        badgeOffset += sizeof(D_800E59E0->badges[0]);
    }
    for (i = 0; i < 4; i++) {
        config = &g_playerSettings[i];
        if (config->enabled == 1) {
            widget = Frontend_FindWidgetByResourceId(D_800E59E0->window, D_800E19DE[i * 0x26]);
            Frontend_SetWidgetFlag40(widget, 0);
            widget->alpha = 0x23;
            screen = D_800E59E0;
            switch (screen->panels[i].mode) {
            case 0:
                func_8043BA5C_de(i, screen->panels[i].selection = 5);
                break;
            case 1:
                screen->panels[i].selection = 0;
                func_8043BA5C_de(i, 0);
                break;
            case 2:
                screen->panels[i].selection = 0;
                func_8043BA5C_de(i, 0);
                break;
            }
        }
    }
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Frontend_StartFourPlayerResults);
#endif

/* Advance the four-player results screen one frame: slide the arrows, count the timer down, step the state. */
s32 Frontend_UpdateFourPlayerResults(void) {
    s32 i;
    s32 player;
    s32 left;
    s32 timer;
    struct FourPlayerResultsScreen *screen;
    switch (D_800E59E0->state) {
    case 1:
        D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x + (u16)D_800E59E0->leftStep;
        D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x - (u16)D_800E59E0->rightStep;
        D_800E59E0->timer--;
        if (D_800E59E0->timer <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            Frontend_SetWidgetFlag08(D_800E59E0->message, 1);
            SmpFlicker_StartFlicker(D_800E59E0->resource, 4);
            D_800E59E0->state = 4;
            D_800E59E0->timer = 4;
        }
        break;
    case 2:
        D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x - (u16)D_800E59E0->leftStep;
        D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x + (u16)D_800E59E0->rightStep;
        D_800E59E0->timer--;
        if (D_800E59E0->timer <= 0) {
            D_800E59E0->state = 3;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(D_800E59E0->next);
            return 0;
        }
        break;
    case 3:
        Tsmos_ActivateControllerState();
        return 0;
    case 4:
        screen = D_800E59E0;
        timer = screen->timer;
        left = timer - 1;
        if (left >= 0) {
            left = timer - (timer < left ^ 1);
        } else {
            left = 0;
        }
        screen->timer = left;
        if (D_800E59E0->timer <= 0) {
            if (SmpFlicker_IsFlickerIdle(D_800E59E0->resource)) {
                SmpFlicker_RestoreFlickerValue(D_800E59E0->resource);
                D_800E59E0->state = 3;
            }
        }
        return 0;
    case 5:
        SoundElement_PlayFlatSound(0xE78);
        D_800E59E0->state = 2;
        D_800E59E0->timer = 4;
        Frontend_SetWidgetFlag08(D_800E59E0->message, 0);
        for (player = 0; player < 4; player++) {
            for (i = 0; i < 5; i++) {
                Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E59E0->window, D_800E5A06[player][i].value), 0);
            }
            Frontend_SetWidgetFlag08(D_800E59E0->panels[player].item, 0);
        }
        break;
    case 6:
    case 7:
        break;
    }
    return 0;
}

#include "gbi.h"
extern Gfx *g_displayListCursor;
extern s32 D_800E28D0;
extern void Frontend_DrawModelPreview(struct ResultsPlayerPanel *);
extern s32 Frontend_GetModelRecordCount(char *);
#if defined(VERSION_DE)
extern void func_804397F0_auto(char *);
#else
extern void func_804399D0(char *);
#endif
extern struct Shape_typemap_6 D_800E41C0[];
extern struct FourPlayerResultsScreen *D_800E59E0;
/* Draw callback of the four-player results screen: on draw event 1 in state 3 it resets the fill colour D_800D15E0
   and the colour table D_800D15E4, scissors the display list to each active panel rectangle in D_800E41C0 and draws
   the panel, then clips to the full screen and draws the badge of every panel whose state is 1. Returns zero. */
s32 Frontend_DrawFourPlayerResults(void *window, void *item, s32 event) {
    s32 i;
    if (event == 1 && D_800E59E0->state == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 || D_800E59E0->panels[i].state == 2) {
                gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, D_800E41C0[i].field_0, D_800E41C0[i].field_4, D_800E41C0[i].field_8, D_800E41C0[i].field_C);
                Frontend_DrawModelPreview(&D_800E59E0->panels[i]);
            }
        }
        gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 && Frontend_GetModelRecordCount(D_800E59E0->badges[i]) != 0) {
                D_800D15E0 = 1;
                D_800D15E4[3] = 150.0f;
#if defined(VERSION_DE)
                func_804397F0_auto(D_800E59E0->badges[i]);
#else
                func_804399D0(D_800E59E0->badges[i]);
#endif
                D_800D15E0 = 0;
                D_800D15E4[3] = 255.0f;
            }
        }
    }
    return 0;
}
