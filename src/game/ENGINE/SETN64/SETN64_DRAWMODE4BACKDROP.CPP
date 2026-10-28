#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/AIPROFILE.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "RENDER/80293A04_2.H"
#include "RENDER/80293A04_4.H"
#include "GFX/TEXT/802A8A94_5.H"

/* Clears the map-view-active flag, emits a set-color-image display list command for the current frame
 * buffer, then draws image 0x389 scaled to fill the screen dimensions over the image's returned width
 * and height, when both are nonzero. */





extern Gfx *g_displayListCursor;

#include "COMMON/DISPLAY.H"

extern s32 D_800E28D0;



extern void SetN64_HandleSessionTransitionInput(s32 arg0, s32 arg1, s32 arg2);

extern void SetN64_ResetSessionPlayerPools(void *session, s32 count, s32 force_active);

extern void Scene_LoadLevelResources(void *, void *, void *);

extern void SmXlate_SwitchScreen(s32 arg0);


/* func_80245A00_de: types.abi.declared: reuse existing C; propagated semantic conflicts remain named */

/* Scene_ResetTransitionViewport: types.declaration: solved callee prototype */


void SetN64_ResetMode4Effects(void) {
    D_80141128 = 0;
    TextLoad_SetTextureEffect(0U);
}

void SetN64_AdvanceToModeEight(struct GameSession *session) {
    s32 eight;
    eight = 8;
    SetN64_CheckTimedSessionTransition(session, 12.0f, eight, eight);
}

void SetN64_DrawMode4Backdrop(void) {
    s32 width;
    s32 height;
    Gfx *cmd;

    D_800CC380 = 0;
    width = 0;
    height = 0;
    gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)D_8011BDC0->colorImage);
    OnScreen_GetImageDimensions(0x389, 0, &width, &height);
    if ((width != 0) && (height != 0)) {
        OnScreen_SetupSpriteMode(0xFA);
        OnScreen_DrawSpriteResource(0x389, 0, 0, 0, (f32)D_800E28D0 / (f32)width, (f32)D_800E28D4 / (f32)height, 1);
    }
}

void SetN64_ResetMode5Items(s32 arg0) {
    Scene_ResetTransitionViewport();
    ((s32 (*)(s32, s32))SetN64_ResetPlayerItems)(arg0, 0x5A);
}

void SetN64_HandleMode5Input(s32 session) {
    SetN64_HandleSessionTransitionInput(session, 7, 7);
}

void SetN64_DrawMode5Session(s32 session) {
    SetN64_DrawSessionWithAttractTimeout(session);
    SetN64_OnMode5DrawComplete(session);
}

/** Perform no operation. */
void SetN64_InitializeMode6(void) {
}

/** Perform no operation. */
void SetN64_UpdateMode6(void) {
}

/** Perform no operation. */
void SetN64_DrawMode6(void) {
}

/** Thin wrapper calling func_8025E2D4_de with a fixed argument. */
void SetN64_SetMode7AudioState(void) {
    func_8025E2D4_de(0x10);
}

void SetN64_HandleMode7Transition(struct GameSession *session) {
    SetN64_CheckTimedSessionTransition(session, 20.0f, 9, 8);
}

void SetN64_InitializeMode8Scene(void *arg0) {
    SetN64_ResetSessionPlayerPools(arg0, 0, 0);
    Scene_LoadLevelResources(&g_world, 0, 0);
    D_801462C8.counters.transitionActive = 0;
    SmXlate_SwitchScreen(0x18);
    func_8025E2D4_de(0x34);
}

void SetN64_UpdateMode8(void) {
}

/** Thin wrapper around SetN64_DrawSessionWithRoundTimeout. */
void SetN64_DrawMode8Session(GameSession *session) {
    SetN64_DrawSessionWithRoundTimeout(session);
}

/* func_80293998_de: types.abi.declared: reuse existing C; propagated semantic conflicts remain named */


                                                  /* size = 0x18 */

void SetN64_ResetMode9Items(s32 arg0) {
    D_800CD770 += 1;
    Scene_ResetTransitionViewport();
    Cinema_SetResponse(0.5f);
    SetN64_ResetPlayerItems(arg0, 0x6F);
}

void SetN64_HandleMode9Input(s32 session) {
    SetN64_HandleSessionTransitionInput(session, 7, 8);
}

void SetN64_DrawMode9Session(void *session) {
    SetN64_DrawSessionWithAttractTimeout(session);
}

void SetN64_ResetMode11Items(s32 arg0) {
    Scene_ResetTransitionViewport();
    ((s32 (*)(s32, s32))SetN64_ResetPlayerItems)(arg0, 0x6F);
}
