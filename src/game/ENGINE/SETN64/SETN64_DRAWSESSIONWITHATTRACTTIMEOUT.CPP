#include "COMMON/SHARED_GAMESLOT.H"
#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/ROUND_STATE_VARIANTS.H"
#include "SCENE/SCENE_UPDATEANDDRAWWORLD.H"

/* Requests a switch of the session into mode 0x14: when the pending 0x1000 flag is set outside modes 0xB and 0xC and a target is given it records that target with phase 2 and clears the flags; otherwise, once Cinema_IsSequenceIdle accepts the flags, it saves the current mode, enters mode 0x14 with the given argument at phase 1, and sets the timer when func_80264B6C_de allows. */



extern s32 Cinema_IsSequenceIdle(s32 *flags);

void SetN64_HandleSessionTransitionInput(GameSession *session, s32 cancelTarget, s32 target) {
    s32 pending;
    s32 *flags;

    flags = (s32 *)&D_8010B0E0.pressedButtons;
    pending = *flags & 0x1000;
    if ((unsigned)(session->mode - 0xB) < 2) {
        pending = 0;
    }
    if (pending != 0 && target != -1) {
        session->phase = 2;
        session->target = target;
        *flags = 0;
        return;
    }
    if (Cinema_IsSequenceIdle(flags) != 0) {
        s32 mode = session->mode;

        session->phase = 1;
        session->timer = 0;
        session->mode = 0x14;
        session->target = cancelTarget;
        session->previousMode = mode;
        if (Control_IsSnapshotActive() != 0) {
            session->timer = (1.0f);
        }
    }
}

/* Calls cleanup functions on a game state and optionally transitions control state when conditions change. */




extern void SmXlate_SwitchScreen(s32 arg0);
extern void SetN64_BeginModeTransition(GameSession *arg0, s32 arg1);
extern void Gsky_DrawPlayerListNoOp(void *arg0);
extern void SetN64_DrawSessionFade(struct GameSession *arg0);





void SetN64_DrawSessionWithAttractTimeout(void *session) {
    GameSession *state;
    f32 value;

    state = session;
    if (D_8014288C == 1) {
        value = state->transitionTime;
        if (D_800C54A4_de < value) {
            if (D_800C54A8_de < value) {
                D_8014288C = 0;
                
#if defined(VERSION_EU)
Tsmos_InitializeEuropeanFrontend
#else
InitFrontendMenus
#endif
();
                SmXlate_SwitchScreen(2);
                Frontend_RequestScreenMode(0);
                SetN64_BeginModeTransition(state, 1);
                state->transitionTime = 0;
            } else if (D_8010B0E0.buttons != 0) {
                D_8014288C = 0;
                
#if defined(VERSION_EU)
Tsmos_InitializeEuropeanFrontend
#else
InitFrontendMenus
#endif
();
                SmXlate_SwitchScreen(2);
                SetN64_BeginModeTransition(state, 8);
                state->transitionTime = 0;
            }
        }
    }
    Scene_UpdateAndDrawWorld(&state->world);
    Gsky_DrawPlayerListNoOp(state->players);
    OnScreen_DrawStatusBars(&state->hud);
    /* Only us-rev1 makes this call: us, eu, eu-x and de go straight on to SetN64_DrawSessionFade, two
       instructions shorter, as each cartridge's own bytes show. */
#ifdef VERSION_US_REV1
    Tengine_UpdateArtsendTexturePreview();
#endif
    SetN64_DrawSessionFade(state);
}

#include "COMMON/SESSIONHANDLERROW.H"








void SetN64_AdvanceGameClock(GameSession *world) {
    f32 t1;
    f32 t2;
    f32 t3;

    if (world->clockPaused == 0) {
        t1 = D_801462C8.counters.m_GameTimeFifteenth + D_800D2988;
        D_801462C8.counters.m_GameTimeFifteenth = t1;
        if (D_800C54AC_de <= t1) {
            t2 = D_801462C8.counters.m_GameTimeSeconds + D_800C54B0_de;
            D_801462C8.counters.m_GameTimeFifteenth = t1 - D_800C54AC_de;
            D_801462C8.counters.m_GameTimeSeconds = t2;
            if (D_800C54B4_de <= t2) {
                t3 = D_801462C8.counters.m_GameTimeMinutes + D_800C54B0_de;
                D_801462C8.counters.m_GameTimeSeconds = t2 - D_800C54B4_de;
                D_801462C8.counters.m_GameTimeMinutes = t3;
                if (D_800C54B4_de <= t3) {
                    D_801462C8.counters.m_GameTimeMinutes = t3 - D_800C54B4_de;
                    D_801462C8.counters.m_GameTimeHours = D_801462C8.counters.m_GameTimeHours + D_800C54B0_de;
                }
            }
        }
    }
}

#include "COMMON/SESSIONHANDLERROW.H"
extern f32 D_800C54B8_de, D_800C54BC_de;
extern void Gsky_DrawPlayerListNoOp(void *);
extern void SmXlate_SwitchScreen(s32);
extern void SetN64_BeginModeTransition(GameSession *, s32);
extern void SetN64_DrawSessionFade(GameSession *);

void SetN64_DrawSessionWithRoundTimeout(GameSession *session) {
    CGameStatus *counters = &D_801462C8.counters;
    f32 time;
    if (counters->transitionActive == 1) {
        time = session->transitionTime;
        if (D_800C54B8_de < time) {
            if (D_800C54BC_de < time) {
                counters->transitionActive = 0;
                stopRoundPlatform();
                SmXlate_SwitchScreen(2);
                Frontend_RequestScreenMode(0);
                SetN64_BeginModeTransition(session, 1);
                session->transitionTime = 0;
            } else if (D_8010B0E0.buttons != 0) {
                counters->transitionActive = 0;
                stopRoundPlatform();
                SmXlate_SwitchScreen(2);
                SetN64_BeginModeTransition(session, 8);
                session->transitionTime = 0;
            }
        }
    }
    Scene_UpdateAndDrawWorld(&session->world);
    Gsky_DrawPlayerListNoOp(session->players);
    OnScreen_DrawStatusBars(&session->hud);
#ifdef VERSION_US_REV1
    Tengine_UpdateArtsendTexturePreview();
#endif
    SetN64_DrawSessionFade(session);
}
