#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/TRIPLE.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "MENU/PLAYERSETTINGS.H"
#include "TYPES.H"
#include "MENU/MISC/8043DF84_3.H"

/** Dispatches to func_80264770_de or func_80264788_de with a byte read from arg0->unk20->unk4, chosen by arg1. */

extern void Control_EnableControllerPak(s32 arg);
extern void Control_DisableControllerPak(s32 arg);






void func_8043DEF8_de(void *arg0, s32 arg1) {
    s32 val;
    MenuRecAt20V2 *menu = arg0;

    val = menu->widget->unk4;
    if (arg1 != 0) {
        Control_EnableControllerPak(val);
    } else {
        Control_DisableControllerPak(val);
    }
}

#include "COMMON/SESSIONHANDLERROW.H"
extern f32 D_800DE324_de;

void func_8043DF34_de(f32 duration, s32 mode, s32 option, s32 teams, s32 last) {
    s32 i;
    CGameStatus *state = &D_801462C8.counters;
    CGameStatus *result;
    state->m_bFragTagOn = option;
    state->teams = teams;
    state->m_CTFPlayerWithFlag = 0;
    state->timeLimit = duration * D_800DE320;
    state->mask = 0xA00;
    state->mode = mode;
    state->elapsed = 0;
    state->m_bCTFOn = last;
    for (i = 0; i < 5; i++) {
        state->scores[i] = 0;
        state->counts[i] = 0;
    }
    result = &D_801462C8.counters;
    result->round = 0;
    result->state = 0;
    if (result->timeLimit == 0.0f) {
        result->timeLimit = D_800DE324_de;
    }
}
