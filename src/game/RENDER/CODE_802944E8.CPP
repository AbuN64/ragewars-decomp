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

extern void func_80293A20_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_8028D90C_de(void);

extern void func_80293B28_de(void *session);

/* Resets the menu viewport and selects the row identified by the owner's current index. */


extern void func_80293268_de(void *arg0);

extern void func_8023EE00_de(void);

extern void func_802954E0_us_rev1(void);

extern void func_8044D528_de(void *arg0, s32 arg1, s32 arg2);

extern s32 D_800D2970;

extern s32 D_800CD730;

extern f32 D_800D2988;
extern f32 D_800CD740_de;
extern s32 func_80264B6C_de(void);
extern void func_80264B8C_de(void);
extern void func_80293334_de(void *session, s32 count, s32 force_active);

void func_802944F4_de(s32 arg0) {
    func_80293A20_de(arg0, 0xC, 0xC);
}

void Render_DrawMode11Session(void *session) { func_80293B28_de(session); }

void func_80294530_de(s32 arg0) {
    func_8028D90C_de();
    ((s32 (*)(s32, s32))func_80293998_de)(arg0, 0x6F);
}

void func_80294560_de(s32 arg0) {
    func_80293A20_de(arg0, 0xD, 8);
}

void Render_DrawMode10Session(void *session) { func_80293B28_de(session); }

void func_8029459C_de(int arg0) {
    func_8028D90C_de();
    func_80293998_de(arg0, ((ObjRecAt26DD8 *)arg0)->unk26DD8 + 0x259);
}

void func_802945D8_de(s32 arg0) {
    func_80293A20_de(arg0, 0xD, 0xD);
}

void Render_DrawMode12Session(void *session) { func_80293B28_de(session); }

struct func_802077F4_S2;

void func_80294614_de(GameSession *arg0) {
    void *dst;
    s32 field;
    f32 f;

    D_80142868 = 0;
    D_800CD730 = 0;
    func_80293268_de(arg0);
    func_8023EE00_de();
#if defined(VERSION_US_REV1)
    func_802954E0_us_rev1();
#endif
    dst = &D_8011FE88;
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
    func_8044D528_de(dst, field, 0);
    arg0->mode = 0xD;
    D_80154048 = 0;
}

/* Prepares a session for a new round: clears the round flag, resets the round state, records the round seed when func_80264B6C_de allows, resets the scoreboard and player slot, restarts the arena with the session's arena setting, resets the camera timers and reloads the session's sound bank and music. */
void Render_StartRound(GameSession *session) {
    CGameStatus *counters;
    Shared_Game *game;

    D_800CD730 = 0;
    func_80293268_de(session);
    if (func_80264B6C_de() != 0) {
        session->selector = func_80264B5C_de();
    }
    counters = &D_801462C8.counters;
    counters->state = 0;
    counters->m_FragTagSelectionType = 3;
    game = &D_801462C8;
    game->local = 1;
    game->mode1E = 8;
    func_80293334_de(session, session->arena, 0);
    if (func_80264B6C_de() != 0) {
        func_80264B8C_de();
    }
    func_8023EE00_de();
    resetRoundExtra();
    clearRoundExtra();
    D_800CD744_de = roundTimerConstant();
    D_800D298C = roundTimerConstant();
    D_800CD740_de = roundTimerConstant();
    func_8044CFF8_de(&D_8011FE88, session->resource);
    func_8044D528_de(&D_8011FE88, session->selector, 0);
}

#if !(defined(VERSION_US_REV1))
const unsigned int rodata_func_802946A4_de_800C54D8[1] = {
    0x3F800000,
};
#endif
