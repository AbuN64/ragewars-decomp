#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "TYPES.H"


void func_8044A370_de(void *a);

void func_804499B0_de(void *a, void *b, void *c);

void func_8029311C_de(void *unused, u8 *color, s32 left, s32 top, s32 right, s32 bottom) {
    if (color[3] != 0) {
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
        func_8026925C_de(0x13);
        func_80268CE0_de(0x19);
        gDPSetPrimColor(D_80110634++, 255, 255, color[0], color[1], color[2], color[3]);
        {
            Gfx *cmd = D_80110634++;
            s32 x, y, x0, y0;
            u32 high, low, high0;
            x = right;
            if (x < 0) x = 0;
            y = bottom;
            high = _SHIFTL(x,14,10);
            if (y < 0) y = 0;
            low = _SHIFTL(y,2,10) | _SHIFTL(G_FILLRECT,24,8);
            cmd->words.w0 = high | low;
            x0 = left;
            if (x0 < 0) x0 = 0;
            y0 = top;
            high0 = _SHIFTL(x0,14,10);
            if (y0 < 0) y0 = 0;
            cmd->words.w1 = high0 | _SHIFTL(y0,2,10);
        }
    }
}

/** Thin wrapper around func_80264404_de. */
void func_80293268_de(void *unused) {
    func_80264404_de();
}

void func_80293284_de(GameSession *arg0, s32 arg1) {
    Shared_Placed spawn;
    s32 var_s0;

    var_s0 = arg1;
    if (func_8044D220_de(&D_8011FE88, -1, var_s0, &spawn, 1) == 0) {
        var_s0 = 0;
    }
    D_801462C8.counters.ticks = 0;
    D_801462C8.counters.seconds = 0;
    D_801462C8.counters.minutes = 0;
    D_801462C8.counters.hours = 0;
    D_801462C8.counters.first = 0;
    arg0->phase = 2;
    arg0->selector = var_s0;
    arg0->selectionActive = 1;
    arg0->target = 0xD;
}

void func_80293334_de(void *arg0, void *arg1, void *arg2) {
    func_8044A370_de(((GameSession *)arg0)->players);
    func_804499B0_de(((GameSession *)arg0)->menu, arg1, arg2);
}
