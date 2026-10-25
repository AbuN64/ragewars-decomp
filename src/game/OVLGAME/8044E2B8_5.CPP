#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/LEVEL.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/UNUSED.H"
#include "OVLGAME/8044E2B8_5.H"

s32 func_8044DCC0_de(void) {
    Vtx *vertices = (Vtx *)&D_801469A0;
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

extern void func_80285D30_de(void *);
struct Context;
extern void func_8022A880_de(struct Context *);




void func_8044DD50_de(char *match) {
    CGameStatus *state;

    Render_SetControllerMode(0);
    func_80285D30_de(D_8010EC90);
    func_8022A880_de(D_80145040);
    state = &D_801462C8.counters;
    state->teams = 0;
    state->m_bFragTagOn = 0;
    state->m_bCTFOn = 0;
    state->first = 0;
    state->transitionActive = 0;
    ((GameSession *)match)->phase = 2;
    ((GameSession *)match)->target = 1;
}
