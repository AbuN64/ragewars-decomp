#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
#include "ACHIEVE/achieve_match_setup.H"
#include "COMMON/PLAYERPROFILES.H"

/* Awards earned end-of-match unlocks and lists the first two new rewards. */

extern s32 func_80265650_de(void *, s32);

extern void func_80265688_de(u8 *, s32, s32);

extern u8 D_8014222C; /* MIXED func_804243E0_de */
void func_804243E0_de(s32 player, s32 *awarded) {
    func_8041F2A0_Config *status;
    Shared_Game *globals;
    CGameStatus *rules;

    f32 elapsed;

    u32 ok;
    s32 score;
    s32 count;
    s32 i;

    count = 0;
    awarded[0] = -1;
    awarded[1] = -1;
    if (Achieve_MatchQualifies() == 0) {
        return;
    }
    status = &D_80146398[player];
    if (status->active != 1) {
        return;
    }
    if (status->out != 0) {
        return;
    }
    for (i = 0; i < 0x24; i++) {
        if (func_80265650_de(D_80102B00[player].achievementFlags, i) == 0 && D_80102B00[player].plays[i] >= 2) {
            func_80265688_de(D_80102B00[player].achievementFlags, i, 1);
            if (count < 2) {
                awarded[count++] = i;
            }
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x24) == 0) {
        ok = 0;
        if ((D_8014222C - 1U < 5 && status->kills >= 15) ||
            ((rules = &D_801462C8.counters)->timeLimit >= 0.0f && status->kills >= 15 &&
             (elapsed = rules->timeLimit * (1.0f / 15.0f),
              elapsed = (f32) (s32) (elapsed * (1.0f / 60.0f)),
              (f32) D_801462C8.laps - elapsed) <= 5.0f)) {
            ok = 1;
        }
        if (ok == 1) {
            func_80265688_de(D_80102B00[player].achievementFlags, 0x24, 1);
            if (count < 2) {
                awarded[count++] = 0x24;
            }
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x25) == 0) {
        ok = 0;
        if ((D_8014222C - 1U < 10 && status->kills >= 25) ||
            ((rules = &D_801462C8.counters)->timeLimit >= 0.0f && status->kills >= 25 &&
             (elapsed = rules->timeLimit * (1.0f / 15.0f),
              elapsed = (f32) (s32) (elapsed * (1.0f / 60.0f)),
              (f32) D_801462C8.laps - elapsed) <= 10.0f)) {
            ok = 1;
        }
        if (ok == 1) {
            func_80265688_de(D_80102B00[player].achievementFlags, 0x25, 1);
            if (count < 2) {
                awarded[count++] = 0x25;
            }
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x26) == 0 && status->kills == 0 &&
        (globals = &D_801462C8)->laps >= 10 && globals->players >= 20) {
        func_80265688_de(D_80102B00[player].achievementFlags, 0x26, 1);
        if (count < 2) {
            awarded[count++] = 0x26;
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x27) == 0 && status->total >= 5) {
        func_80265688_de(D_80102B00[player].achievementFlags, 0x27, 1);
        if (count < 2) {
            awarded[count++] = 0x27;
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x28) == 0 && (globals = &D_801462C8)->players >= 20) {
        score = status->kills;
        ok = 1;
        for (i = 0; i < 4; i++) {
            if (ok != 1) {
                break;
            }
            if (player != i && (globals->playerSettings[i].enabled != 1 || globals->playerSettings[i].locked != 0 ||
                                globals->playerSettings[i].score - score < 10)) {
                ok = 0;
            }
        }
        if (ok == 1) {
            func_80265688_de(D_80102B00[player].achievementFlags, 0x28, 1);
            if (count < 2) {
                awarded[count++] = 0x28;
            }
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x29) == 0 && D_80102B00[player].statistics.wins > 1000) {
        func_80265688_de(D_80102B00[player].achievementFlags, 0x29, 1);
        if (count < 2) {
            awarded[count++] = 0x29;
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x2A) == 0 && D_80102B00[player].statistics.deaths > 1000) {
        func_80265688_de(D_80102B00[player].achievementFlags, 0x2A, 1);
        if (count < 2) {
            awarded[count++] = 0x2A;
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x2B) == 0 && status->unkA >= 10 &&
        (globals = &D_801462C8)->laps >= 10 && globals->players >= 20) {
        func_80265688_de(D_80102B00[player].achievementFlags, 0x2B, 1);
        if (count < 2) {
            awarded[count++] = 0x2B;
        }
    }
    if (func_80265650_de(D_80102B00[player].achievementFlags, 0x2C) == 0 && status->score == 0 &&
        (globals = &D_801462C8)->laps >= 10 && globals->players >= 20) {
        func_80265688_de(D_80102B00[player].achievementFlags, 0x2C, 1);
        if (count < 2) {
            awarded[count] = 0x2C;
        }
    }
}
