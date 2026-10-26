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


void Items_ResetActorPools(void *owner, s32 count);

void func_804499B0_de(void *pool, s32 count, s32 force_active);

void func_8029311C_de(void *unused, u8 *color, s32 left, s32 top, s32 right, s32 bottom) {
    if (color[3] != 0) {
        gDPPipeSync(g_displayListCursor++);
        gDPSetCycleType(g_displayListCursor++, G_CYC_1CYCLE);
        Render_SetModePreset(0x13);
        Render_SetCombineMode(0x19);
        gDPSetPrimColor(g_displayListCursor++, 255, 255, color[0], color[1], color[2], color[3]);
        {
            Gfx *cmd = g_displayListCursor++;
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

/** Thin wrapper around Control_CommitControllerInputs. */
void func_80293268_de(void *unused) {
    Control_CommitControllerInputs();
}

void func_80293284_de(GameSession *gameSession, s32 target) {
    Shared_Placed spawn;
    s32 selectionValues;

    selectionValues = target;
    if (Items_FindPlacedObjectsByKey(&g_world, -1, selectionValues, &spawn, 1) == 0) {
        selectionValues = 0;
    }
    D_801462C8.counters.m_GameTimeFifteenth = 0;
    D_801462C8.counters.m_GameTimeSeconds = 0;
    D_801462C8.counters.m_GameTimeMinutes = 0;
    D_801462C8.counters.m_GameTimeHours = 0;
    D_801462C8.counters.first = 0;
    gameSession->phase = 2;
    gameSession->selector = selectionValues;
    gameSession->selectionActive = 1;
    gameSession->target = 0xD;
}

void func_80293334_de(void *owner, s32 count, s32 force_active) {
    GameSession *session = owner;
    Items_ResetActorPools(session->players, count);
    func_804499B0_de(session->menu, count, force_active);
}
