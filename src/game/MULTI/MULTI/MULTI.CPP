#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "MULTI/MULTI_COMPLETEGAMEOVERDELAY.H"
#include "COMMON/GAME_SESSION.H"
#include "include_asm.h"

/* 8043E9A8_6.CPP */
/* When the timer D_801468B0 has run out, calls Match_ResetMatchControllerState on D_8011FAC0 and returns one;
   otherwise returns zero. */
extern void Match_ResetMatchControllerState(void *);

s32 Multi_CompleteGameOverDelay(void) {
    if (D_801462C8.counters.m_GameOverTimer <= 0.0f) {
        Match_ResetMatchControllerState(&D_8011FAC0);
        return 1;
    }
    return 0;
}

/* Counts the timer at offset 0x10 of D_801468A0 down by D_800D2988, stopping at zero, and returns
   zero. */

s32 Multi_DecreaseGameOverTimer(void) {
    CGameStatus *state = &D_801462C8.counters;
    f32 timer = state->m_GameOverTimer - D_800D2988;

    state->m_GameOverTimer = timer;
    if (timer < 0.0f) {
        state->m_GameOverTimer = 0.0f;
    }
    return 0;
}

/* 8042FBEC_16.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_8043FCFC_eu_padding_1B5CFC[4] = { 0x03, 0xE0, 0x00, 0x08 };
#endif
