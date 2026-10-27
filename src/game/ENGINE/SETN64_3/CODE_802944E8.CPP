#include "RENDER/80293A04_2.H"
#include "include_asm.h"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WORLD.H"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "TYPES.H"
#include "RENDER/CODE_802944E8.H"
#include "RENDER/80263760_8.H"
#include "COMMON/ROUND_STATE_VARIANTS.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAME_SESSION.H"

extern void SetN64_HandleSessionTransitionInput(s32 arg0, s32 arg1, s32 arg2);


/* Resets the menu viewport and selects the row identified by the owner's current index. */


extern void SetN64_CommitSessionInputs(void *arg0);

extern void func_8023EE00_de(void);


extern void OvlScene_SetSelection(void *arg0, s32 arg1, s32 arg2);


extern s32 D_800CD730;

extern void SetN64_ResetSessionPlayerPools(void *session, s32 count, s32 force_active);

void SetN64_HandleMode11Input(s32 session) {
    SetN64_HandleSessionTransitionInput(session, 0xC, 0xC);
}

void SetN64_DrawMode11Session(void *session) { SetN64_DrawSessionWithAttractTimeout(session); }

void SetN64_ResetMode10Items(s32 arg0) {
    Scene_ResetTransitionViewport();
    ((s32 (*)(s32, s32))SetN64_ResetPlayerItems)(arg0, 0x6F);
}

void SetN64_HandleMode10Input(s32 session) {
    SetN64_HandleSessionTransitionInput(session, 0xD, 8);
}

void SetN64_DrawMode10Session(void *session) { SetN64_DrawSessionWithAttractTimeout(session); }

void SetN64_ResetMode12Items(int arg0) {
    Scene_ResetTransitionViewport();
    SetN64_ResetPlayerItems(arg0, ((ObjRecAt26DD8 *)arg0)->unk26DD8 + 0x259);
}

void SetN64_HandleMode12Input(s32 session) {
    SetN64_HandleSessionTransitionInput(session, 0xD, 0xD);
}

void SetN64_DrawMode12Session(void *session) { SetN64_DrawSessionWithAttractTimeout(session); }

void SetN64_ResumeSelectedSession(GameSession *arg0) {
    void *dst;
    s32 field;
    f32 f;

    D_801462C8.counters.first = 0;
    D_800CD730 = 0;
    SetN64_CommitSessionInputs(arg0);
    func_8023EE00_de();
#if defined(VERSION_US_REV1)
    TextLoad_ResetArtsendTextureState();
#endif
    dst = &g_world;
#if defined(VERSION_US_REV1)
    f = (1.0f);
#else
    f = (1.0f);
#endif
    field = arg0->selector;
#if defined(VERSION_US_REV1)
    D_800D2970 = 0;
#endif
    D_800CD744_de = f;
    D_800D298C = f;
    D_800CD740_de = f;
    OvlScene_SetSelection(dst, field, 0);
    arg0->mode = 0xD;
    D_80154048 = 0;
}

/* Prepares a session for a new round: clears the round flag, resets the round state, records the round seed when func_80264B6C_de allows, resets the scoreboard and player slot, restarts the arena with the session's arena setting, resets the camera timers and reloads the session's sound bank and music. */
void SetN64_StartRound(GameSession *session) {
    CGameStatus *counters;
    Shared_Game *game;

    D_800CD730 = 0;
    SetN64_CommitSessionInputs(session);
    if (Control_IsSnapshotActive() != 0) {
        session->selector = Control_GetSnapshotActorId();
    }
    counters = &D_801462C8.counters;
    counters->state = 0;
    counters->m_FragTagSelectionType = 3;
    game = &D_801462C8;
    game->local = 1;
    game->mode1E = 8;
    SetN64_ResetSessionPlayerPools(session, session->arena, 0);
    if (Control_IsSnapshotActive() != 0) {
        Control_RestoreActorSnapshot();
    }
    func_8023EE00_de();
    resetRoundExtra();
    clearRoundExtra();
    D_800CD744_de = roundTimerConstant();
    D_800D298C = roundTimerConstant();
    D_800CD740_de = roundTimerConstant();
    OvlScene_InitPreview(&g_world, session->resource);
    OvlScene_SetSelection(&g_world, session->selector, 0);
}

#if !(defined(VERSION_US_REV1))
const unsigned int rodata_func_802946A4_de_800C54D8[1] = {
    0x3F800000,
};
#endif
