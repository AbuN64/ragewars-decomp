#include "COMMON/LEVEL_TRACK.H"
#include "include_asm.h"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEVEL.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"

/* Asks func_8044D220_de about D_8011FE88 with a minus-one selector, clears the words of D_801468A0 and puts the object at arg0 into state 0xC with byte 0x26DC1 set to two and the selector, or zero when the lookup failed, stored at 0x26DD8. Adapted from func_80293284_de with the selector fixed at minus one, the word at 0x26DDC cleared before the last word of D_801468A0 instead of set after the selector, and the state 0xC instead of 0xD changed. */







void func_8044DDD4_de(GameSession *gameSession) {
    Shared_Placed spawn;
    s32 var_s0;

    var_s0 = -1;
    if (Items_FindPlacedObjectsByKey(&D_8011FE88, var_s0, var_s0, &spawn, 1) == 0) {
        var_s0 = 0;
    }
    D_801462C8.counters.m_GameTimeFifteenth = 0;
    D_801462C8.counters.m_GameTimeSeconds = 0;
    D_801462C8.counters.m_GameTimeMinutes = 0;
    D_801462C8.counters.m_GameTimeHours = 0;
    gameSession->selectionActive = 0;
    D_801462C8.counters.first = 0;
    gameSession->phase = 2;
    gameSession->selector = var_s0;
    gameSession->target = 0xC;
}

/* Starts the fade out of the session into the match: keeps key as the session selector when
   Items_FindPlacedObjectsByKey finds a placed object for it (else 0), restarts the game clock and targets mode 13
   when the local player has a transition pending, otherwise mode 12. */
void Ovlgame_StartMatchTransition(GameSession *session, s32 key) {
    Shared_Placed spawn;
    if (Items_FindPlacedObjectsByKey(&D_8011FE88, -1, key, &spawn, 1) == 0) {
        key = 0;
    }
    D_801462C8.counters.m_GameTimeFifteenth = 0;
    D_801462C8.counters.m_GameTimeSeconds = 0;
    D_801462C8.counters.m_GameTimeMinutes = 0;
    D_801462C8.counters.m_GameTimeHours = 0;
    D_801462C8.counters.first = 0;
    session->selectionActive = 0;
    session->selector = key;
    if (session->local != 0) {
        if (D_801462C8.counters.transitionActive != 0) {
            session->phase = 2;
            session->target = 13;
        } else {
            session->phase = 2;
            session->target = 12;
        }
    } else {
        session->phase = 2;
        session->target = 12;
    }
}
