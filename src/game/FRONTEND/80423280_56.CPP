#include "include_asm.h"
#include "COMMON/RECRECAT4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MENULISTSCREEN.H"
#include "FRONTEND/80423280_53.H"
#include "FRONTEND/80423280_56.H"
#include "FRONTEND/8042E080_42.H"
extern MatchScoreScreen *D_800E53C0;

/* Handles the answer on the screen D_800E53C0. */


extern s32 D_80146894;


extern s32 D_801468F4;

extern void func_8029973C_de();

extern s32 func_8043C308_de(void *);

extern s32 func_80299A08_de();

extern void func_8043C278_de(void *);



extern void func_80298368_de(s32);

/* When the fourth argument is one, calls func_8029973C_de and, while the counter at offset 0xE8 of
   the object D_800E53C0 points to is positive, decrements it and calls Frontend_FillResultRows. Returns zero. */





/* When the fourth argument is one, calls func_8029973C_de and, while the position at offset 0xE8 of
   the object D_800E53C0 points to is more than four below the limit at 0xEC, advances it and calls
   Frontend_FillResultRows. Returns zero. */




/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E53C4, an actor kind at D_800E53C8 and a handler at D_800E53CC: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8042DB38)(void *, s32, s32, s32, s32);



extern Handler8042DB38 D_800E53CC;

s32 func_8042D788_de(void) {
    s32 *paused;
    func_8029973C_de();
    if (func_8043C308_de(D_800E53C0) == 1) {
        return 0;
    }
    paused = &D_80146894;
    *paused = 0;
    switch (func_80299A08_de()) {
#if defined(VERSION_DE)
    case 0x235 - 2:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x239 - 2:
#elif defined(VERSION_EU_X)
    case 0x23E - 2:
#endif
        if (((u8 *)paused)[-0x5BF] == 0) {
            func_8043C278_de(D_800E53C0);
            D_800E53C0->active = 0;
        } else {
            D_80146918 = 0;
            D_801468F4 = 0;
            func_80298368_de(0xF);
        }
        break;
#if defined(VERSION_DE)
    case 0x235 - 1:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x239 - 1:
#elif defined(VERSION_EU_X)
    case 0x23E - 1:
#endif
        func_80434FB4_de(5);
        func_80298368_de(0x13);
        break;
#if defined(VERSION_DE)
    case 0x235 + 3:
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    case 0x239 + 3:
#elif defined(VERSION_EU_X)
    case 0x23E + 3:
#endif
        if (func_8042AF28_de() == 1) {
            func_8042E988_de(0x21);
            return 0;
        }
        if (((u8 *)paused)[-0x5BF] == 0) {
            func_80298368_de(0x14);
        } else {
            func_80298368_de(0xF);
        }
        break;
    default:
        return 0;
    }
    return 0;
}

s32 func_8042D8A4_de(void) {
    func_8029973C_de();
    return 0;
}

s32 func_8042D8C4_de(void *first, void *second, void *third, s32 fourth) {
    MatchScoreScreen *state;

    if (fourth == 1) {
        func_8029973C_de();
        state = D_800E53C0;
        if (state->first > 0) {
            state->first--;
            Frontend_FillResultRows();
            return 0;
        }
    }
    return 0;
}

s32 func_8042D908_de(void *first, void *second, void *third, s32 fourth) {
    MatchScoreScreen *state;
    s32 position;

    if (fourth == 1) {
        func_8029973C_de();
        state = D_800E53C0;
        position = state->first;
        if (position + 4 < state->count) {
            state->first = position + 1;
            Frontend_FillResultRows();
            return 0;
        }
    }
    return 0;
}

s32 func_8042D958_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042DB38 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E53CC != 0) {
        wildcard = 0x7530;
        entry = &D_800E53CC;
        index = 0;
        do {
            if (D_800E53C4[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E53C8[index].value;
                if ((table_kind == actor_kind) || (table_kind == wildcard)) {
                    return (*entry)(arg0, arg1, arg2, arg3, arg4);
                }
            }
            entry += 3;
            index++;
        } while (*entry != 0);
    }
    return 0;
}

#if defined(VERSION_DE)
INCLUDE_DATA("ovl_80400000", func_8042D9E8_de_padding_1939E8);
#endif
