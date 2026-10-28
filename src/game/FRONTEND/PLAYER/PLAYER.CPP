#include "include_asm.h"
#include "COMMON/SCREEN.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "FRONTEND/WIDGET_FINDWIDGETATPOINT.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "TYPES.H"
#include "FRONTEND/ENTRYRECAT4D4.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "FRONTEND/FRONTEND_DRAWMODELPREVIEW.H"
#include "FRONTEND/MENU_IMAGE.H"
#include "FRONTEND/EQUIP_ACTIVATEEQUIPMENTPANEL.H"
#include "FRONTEND/PLAYER.H"
#include "gbi.h"

/* 800E1FC0.CPP */
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80439EC4_E2BC0_us_rev1.c */
const unsigned int D_blob_9c12cf7de65376bb1f33[1] = {
    0x3F800000,
};
#endif

/* 800E1FC4.CPP */
const unsigned int D_auto_src_rw_pool_8043A330_E2BC4_us_rev1[7] = {
    0x3B656042, 0x40A00000, 0xC2C80000, 0x41E00000, 0x41400000, 0xC0400000, 0xC1900000,
};

/* 8043A0B0_6.CPP */

/* CODE_8043A0B0.CPP */
extern struct FourPlayerResultsScreen *D_800E59E0;
extern Shared_PlayerSettingsRecord g_playerSettings[];
extern struct RowRecAt54 D_800E3A58[];
extern struct StateFlags D_800E59E6[][19];
extern f32 D_800DDF90_de;
extern void *Cache_AllocateMemory(s32);
extern void *SmpOverlay_CreateOverlayNode(void *, s32);
extern void SmpOverlay_ShowSlotById(void *, s32, s32);
extern MenuWidget *Node_FindWidgetByResourceId(void *, s32);
extern void Widget_SetWidgetFlag08(MenuWidget *, s32);
extern s32 Key_FindKeyIndex(s32);
extern void *SmpFlicker_CreateFlickerWidget(s32, s32);
extern void Tsmos_DeactivateControllerState(void);
extern struct StateFlags D_800E5A06[][19];
extern s32 SmpFlicker_IsFlickerIdle(void *);
extern void SmpFlicker_RestoreFlickerValue(void *);
extern void SmpFlicker_StartFlicker(void *, int);
extern void SmXlate_SwitchScreen(s32);
extern void Tsmos_ActivateControllerState(void);

/* Construct the four-player results/loadout menu and animate its panels into view. */
s32 Player_CreateFourPlayerResults(void *window) {
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
        bar = Node_FindWidgetByResourceId(D_800E59E0->window, D_800E59E6[player][1].value);
        D_800E59E0->panels[player].item = bar;
        bar->alpha = 0x64;
        Widget_SetWidgetFlag08(bar, 0);
        widget = Node_FindWidgetByResourceId(D_800E59E0->window, D_800E59E6[player][0].value);
        widget->alpha = 0x6E;
        config = &g_playerSettings[player];
        if (config->enabled == 1) {
            row = Key_FindKeyIndex(config->character);
            scale.x = D_800E3A58[row].scale[player];
            scale.y = D_800E3A58[row].scale[player];
            scale.z = D_800E3A58[row].scale[player];
            Preview_InitModelPreview(&D_800E59E0->panels[player], 9, config->character + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[player], D_800E3A58[row].distance[player], D_800E3A58[row].light[player]);
        }
    }
    D_800E59E0->state = 1;
    D_800E59E0->timer = 4;
    D_800E59E0->leftArrow = Node_FindWidgetByResourceId(window, leftResource);
    D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x - (u16)D_800E59E0->leftArrow->width;
    D_800E59E0->leftStep = D_800E59E0->leftArrow->width / 4;
    delta = D_800E59E0->leftArrow->width - D_800E59E0->leftStep * 4;
    D_800E59E0->leftArrow->x = (u16)D_800E59E0->leftArrow->x + delta;
    D_800E59E0->rightArrow = Node_FindWidgetByResourceId(window, rightResource);
    D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x + (u16)D_800E59E0->rightArrow->width;
    D_800E59E0->rightStep = D_800E59E0->rightArrow->width / 4;
    delta = D_800E59E0->rightArrow->width - D_800E59E0->rightStep * 4;
    D_800E59E0->rightArrow->x = (u16)D_800E59E0->rightArrow->x - delta;
    Node_FindWidgetByResourceId(window, titleResource)->alpha = 0x6E;
    D_800E59E0->resource = SmpFlicker_CreateFlickerWidget(messageResource, 0xFF);
    widget = Node_FindWidgetByResourceId(window, messageResource);
    D_800E59E0->message = widget;
    Widget_SetWidgetFlag08(widget, 0);
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
    Frontend_ResetEquipmentFromCharacter();
    for (player = 0; player < 4; player++) {
        config = &g_playerSettings[player];
        if (config->enabled == 1) {
            Equip_ActivateEquipmentPanel(player);
        }
    }
    D_800E59E0->next = -1;
    Tsmos_DeactivateControllerState();
    return 0;
}

extern s32 Frontend_InitModelPreviewTransform(void *, s32, CVector3, CVector3);
extern void Frontend_SetPreviewRotation(void *, CVector3);
extern void Frontend_SetPreviewRotationSpeed(void *, CVector3);
#if defined(VERSION_EU)
/* eu keeps these two floats elsewhere: D_800E1FC4/D_800E1FD4 name its string tables */
#define D_800E1FC4 D_800EE614_eu
#define D_800E1FD4 D_800EE624_eu
#endif
extern f32 D_800E1FC4;
extern f32 D_800DDF98_de;
extern f32 D_800E1FD4;
extern f32 D_800DDFA8;
extern f32 D_800DDFAC_de;
/* Initialize four rotating result badges and reveal enabled player cards. */
s32 Player_StartFourPlayerResults(void) {
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
        rotation.y = (f32)(baseAngle + Graphu64_NextRandom() % 10);
        baseAngle += 0x2D;
        Frontend_InitModelPreviewTransform((u8 *)D_800E59E0 + badgeOffset, 0, scale, position);
        Frontend_SetPreviewRotation((u8 *)D_800E59E0 + badgeOffset, rotation);
        Frontend_SetPreviewRotationSpeed((u8 *)D_800E59E0 + badgeOffset, angularVelocity);
        badgeOffset += sizeof(D_800E59E0->badges[0]);
    }
    for (i = 0; i < 4; i++) {
        config = &g_playerSettings[i];
        if (config->enabled == 1) {
            widget = Node_FindWidgetByResourceId(D_800E59E0->window, D_800E19DE[i * 0x26]);
            Widget_SetWidgetFlag40(widget, 0);
            widget->alpha = 0x23;
            screen = D_800E59E0;
            switch (screen->panels[i].mode) {
            case 0:
                Frontend_SelectEquipmentColumn(i, screen->panels[i].selection = 5);
                break;
            case 1:
                screen->panels[i].selection = 0;
                Frontend_SelectEquipmentColumn(i, 0);
                break;
            case 2:
                screen->panels[i].selection = 0;
                Frontend_SelectEquipmentColumn(i, 0);
                break;
            }
        }
    }
    SoundElement_PlayFlatSound(0xE78);
    return 0;
}

/* Advance the four-player results screen one frame: slide the arrows, count the timer down, step the state. */
s32 Player_UpdateFourPlayerResults(void) {
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
            Widget_SetWidgetFlag08(D_800E59E0->message, 1);
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
        Widget_SetWidgetFlag08(D_800E59E0->message, 0);
        for (player = 0; player < 4; player++) {
            for (i = 0; i < 5; i++) {
                Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(D_800E59E0->window, D_800E5A06[player][i].value), 0);
            }
            Widget_SetWidgetFlag08(D_800E59E0->panels[player].item, 0);
        }
        break;
    case 6:
    case 7:
        break;
    }
    return 0;
}

extern Gfx *g_displayListCursor;
extern s32 D_800E28D0;
extern void Preview_DrawModelPreview(struct ResultsPlayerPanel *);
extern s32 Model_GetModelRecordCount(char *);
#if defined(VERSION_DE)
extern void func_804397F0_auto(char *);
#else
extern void func_804399D0(char *);
#endif
extern struct Shape_typemap_6 g_menuPlayerScissorRects[];
/* Draw callback of the four-player results screen: on draw event 1 in state 3 it resets the fill colour D_800D15E0
   and the colour table D_800D15E4, scissors the display list to each active panel rectangle in g_menuPlayerScissorRects and draws
   the panel, then clips to the full screen and draws the badge of every panel whose state is 1. Returns zero. */
s32 Player_DrawFourPlayerResults(void *window, void *item, s32 event) {
    s32 i;
    if (event == 1 && D_800E59E0->state == 3) {
        D_800D15E0 = 0;
        D_800D15E4[0] = 255.0f;
        D_800D15E4[1] = 255.0f;
        D_800D15E4[2] = 255.0f;
        D_800D15E4[3] = 255.0f;
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 || D_800E59E0->panels[i].state == 2) {
                gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, g_menuPlayerScissorRects[i].field_0, g_menuPlayerScissorRects[i].field_4, g_menuPlayerScissorRects[i].field_8, g_menuPlayerScissorRects[i].field_C);
                Preview_DrawModelPreview(&D_800E59E0->panels[i]);
            }
        }
        gDPSetScissor(g_displayListCursor++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
        for (i = 0; i < 4; i++) {
            if (D_800E59E0->panels[i].state == 1 && Model_GetModelRecordCount(D_800E59E0->badges[i]) != 0) {
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

/* DATA_800DCC34.CPP */
#if defined(VERSION_US)
/* ROM-grounded data for us; supplied-list member has no us-rev1 placement. */
unsigned int s_mitetText[4] = {
    0x52595F4D, 0x49544554, 0x00000400, 0x3F800000,
};
#endif
