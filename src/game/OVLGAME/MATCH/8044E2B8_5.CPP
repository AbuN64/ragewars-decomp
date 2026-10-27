#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/LEVEL.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/UNUSED.H"
#include "OVLGAME/8044E2B8_5.H"
#include "COMMON/LEVEL_TRACK.H"
#include "include_asm.h"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"

s32 Ovlgame_InitParticleQuad(void) {
    Vtx *vertices = (Vtx *)&g_particleQuadVertices;
    s32 i = 0;
    s32 more;

    vertices[0].x = -1;
    vertices[0].z = 1;
    vertices[0].s = 0;
    vertices[0].t = 0;
    vertices[1].x = 1;
    vertices[1].z = 1;
    vertices[1].s = 1024;
    vertices[1].t = 0;
    vertices[2].x = 1;
    vertices[2].z = -1;
    vertices[2].s = 1024;
    vertices[2].t = 1024;
    vertices[3].x = -1;
    vertices[3].z = -1;
    vertices[3].s = 0;
    vertices[3].t = 1024;
    do {
        vertices[i].y = 0;
        vertices[i].flag = 0;
        vertices[i].r = 255;
        vertices[i].g = 255;
        vertices[i].b = 255;
        vertices[i].a = 255;
        i++;
        more = i < 4;
    } while (more);
    return more;
}

/* Resets a match: calls func_80264854_de with zero, func_80285D30_de on D_8010EC90 and func_8022A880_de on
   D_80145040, clears five state words of D_801468A0, and sets the byte at offset 0x26DC1 of the
   match block to 2 and its word at 0x26DBC to one. */


extern char D_8010EC90[];
extern char D_80145040[];

extern void Rumble_FreeAllPoolNodes(void *);
struct Context;
extern void Player_ResetPlayerControllers(struct Context *);




void Ovlgame_ResetMatchControllerState(char *match) {
    CGameStatus *state;

    Control_SetControllerMode(0);
    Rumble_FreeAllPoolNodes(D_8010EC90);
    Player_ResetPlayerControllers(D_80145040);
    state = &D_801462C8.counters;
    state->teams = 0;
    state->m_bFragTagOn = 0;
    state->m_bCTFOn = 0;
    state->first = 0;
    state->transitionActive = 0;
    ((GameSession *)match)->phase = 2;
    ((GameSession *)match)->target = 1;
}

/* Asks func_8044D220_de about D_8011FE88 with a minus-one selector, clears the words of D_801468A0 and puts the object at arg0 into state 0xC with byte 0x26DC1 set to two and the selector, or zero when the lookup failed, stored at 0x26DD8. Adapted from SetN64_SelectSpawnAndStartSession with the selector fixed at minus one, the word at 0x26DDC cleared before the last word of D_801468A0 instead of set after the selector, and the state 0xC instead of 0xD changed. */







void Ovlgame_ResetGameClockAndSelectSpawn(GameSession *gameSession) {
    Shared_Placed spawn;
    s32 var_s0;

    var_s0 = -1;
    if (OvlScene_FindPlacedObjectsByKey(&g_world, var_s0, var_s0, &spawn, 1) == 0) {
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
   OvlScene_FindPlacedObjectsByKey finds a placed object for it (else 0), restarts the game clock and targets mode 13
   when the local player has a transition pending, otherwise mode 12. */
void Ovlgame_StartMatchTransition(GameSession *session, s32 key) {
    Shared_Placed spawn;
    if (OvlScene_FindPlacedObjectsByKey(&g_world, -1, key, &spawn, 1) == 0) {
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

#if defined(VERSION_EU)
unsigned char D_auto_func_8044F224_eu_padding_1C5224[12] = { 0xA2, 0x23, 0x06, 0x0B, 0xA2, 0x23, 0x06, 0x08, 0xA2, 0x23, 0x06, 0x16 };
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_8044DF54_de_padding_1B3F54[12] = { 0x26, 0x45, 0x75, 0x34, 0x24, 0x06, 0x00, 0x1C, 0x0C, 0x09, 0xE5, 0x6C };
#endif
