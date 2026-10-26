#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MULTI/8043E9A8_6.H"

/* When the timer D_801468B0 has run out, calls func_8044DD50_de on D_8011FAC0 and returns one;
   otherwise returns zero. */
#include "COMMON/GAME_SESSION.H"
extern void func_8044DD50_de(void *);

s32 func_8043EDDC_de(void) {
    if (D_801462C8.counters.m_GameOverTimer <= 0.0f) {
        func_8044DD50_de(&D_8011FAC0);
        return 1;
    }
    return 0;
}

/* Counts the timer at offset 0x10 of D_801468A0 down by D_800D2988, stopping at zero, and returns
   zero. */



s32 func_8043EE24_de(void) {
    CGameStatus *state = &D_801462C8.counters;
    f32 timer = state->m_GameOverTimer - D_800D2988;

    state->m_GameOverTimer = timer;
    if (timer < 0.0f) {
        state->m_GameOverTimer = 0.0f;
    }
    return 0;
}
