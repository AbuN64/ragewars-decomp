#include "COMMON/INTEGERSTATEB0.H"
#include "RENDER/80293A04.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/WORLD.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/MENURECAT24.H"
#include "RENDER/80293A04_2.H"
#include "GFX/TEXT/802A8A94_5.H"

s32 Control_DisableAllControllerPaks();

extern void SetN64_ResetSessionPlayerPools(void *session, s32 count, s32 force_active);



extern u8 D_801468A0;


extern u32 Defs_GetMemorySize(void);

/* Emits a set-color-image display list command for the current frame buffer, then draws image 0x388
 * scaled to fill the screen dimensions over the image's returned width and height, when both are nonzero. */





extern Gfx *g_displayListCursor;

#include "COMMON/DISPLAY.H"



/* Clears D_800D29C8 when SetN64_CheckTimedSessionTransition accepts its argument with 4.0 and two fours. */

/** Perform no work for callers at VRAM 0x80293DDC. */
void SetN64_OnMode5DrawComplete(s32 session) {
}

void SetN64_InitializeFrontendScreenState(GameSession *gameSession) {
    D_800E28C8 = -1;
    D_80146D70 = 0;
    Frontend_RequestScreenMode(0);
    D_800CD774 = 1;
    D_80146D60 = 1;
    D_800E28CC = 1;
    D_8014AD94 = 0;
    gameSession->timer = D_800C54C0_de;
    SmXlate_SwitchScreen(0x1D);
}

void SetN64_ExitSessionAndDisablePaks(void *arg0) {
    if (D_8014ADA0 != 0) {
        SetN64_SetTransitionTarget(arg0, 1);
        Control_DisableAllControllerPaks();
    }
}

/** Thin wrapper around SetN64_DrawSessionWithRoundTimeout. */
void SetN64_DrawRoundTimeoutSession(GameSession *session) {
    SetN64_DrawSessionWithRoundTimeout(session);
}

void SetN64_ResetSceneForIntro(void *arg0) {
    s8 *p1;
    s8 *p2;
    int new_var;

    func_8025E2D4_de(0);
    new_var = 0x5D8;
    p1 = ((s8 *)(&D_801468A0)) - new_var;
    ((struct IntegerStateB0 *) ((char *) (&D_801468A0)))->unk_AC = 0;
    ((struct IntegerStateB0 *) ((char *) (&D_801468A0)))->unk_88 = 0;
    p1[0xB2] = 1;
    p1[0x1D] = 0;
    p1[0x1E] = 1;
    SetN64_ResetSessionPlayerPools(arg0, 0, 0);
    Scene_LoadLevelResources(&g_world, 0, 0);
    p2 = ((s8 *)(&D_801468A0)) - 0x1818;
    Items_ResetActorPools(p2, 1);
    ((IntegerState164 *)(p2))->unk_160 = 0;
    Textload_SetTextureEffect(0);
}

void SetN64_AdvanceIntroForMemorySize(GameSession *session) {
    s32 eight;
    s32 call_result;
    u32 result;

    result = Defs_GetMemorySize();
    eight = 4;
    if ((result > 0x400000U) && (D_800D29C8 != 0)) {
        eight = 3;
    }
    if (session->transitionTime > D_800C54C4_de) {
        D_800CD77C = 0;
    }
    if (D_800CD77C != 0) {
        call_result = SetN64_CheckTimedSessionTransition(session, 12.0f, eight, -1);
    } else {
        call_result = SetN64_CheckTimedSessionTransition(session, 12.0f, eight, eight);
    }
    if (call_result != 0) {
        D_800CD77C = 0;
    }
}

void SetN64_DrawIntroBackdrop(void) {
    s32 width;
    s32 height;
    Gfx *cmd;

    width = 0;
    height = 0;
    gDPSetColorImage(g_displayListCursor++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)D_8011BDC0->colorImage);
    OnScreen_GetImageDimensions(0x388, 0, &width, &height);
    if ((width != 0) && (height != 0)) {
        OnScreen_SetupSpriteMode(0xFA);
        OnScreen_DrawSpriteResource(0x388, 0, 0, 0, (f32)D_800E28D0 / (f32)width, (f32)D_800E28D4 / (f32)height, 1);
    }
}

void SetN64_ClearSessionPlayerPools(void *arg0) {
    SetN64_ResetSessionPlayerPools(arg0, 0, 0);
}

void SetN64_AdvanceToModeFour(struct GameSession *value) {
    if (SetN64_CheckTimedSessionTransition(value, 4.0f, 4, 4) != 0) {
        D_800D29C8 = 0;
    }
}

/** Preserve the empty hook at VRAM 0x80294120. */
void SetN64_InitializeMode2(void) {
}

void SetN64_AdvanceToModeFive(struct GameSession *session)
{
  s32 five;
  five = 5;
  SetN64_CheckTimedSessionTransition(session, 14.0f, five, five);
}
