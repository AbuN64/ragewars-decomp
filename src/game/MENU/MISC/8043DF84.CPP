#include "MENU/PLAYERSETTINGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU/MISC/8043DF84.H"

/* Clears eight player active flags, then marks the first settings slot whose controller profile is active. */
extern StatusStep D_80142622[];

extern PlayerSettings D_80146398[];

extern s32 func_8026437C_de(ControllerProfile *);

/* Finds the first of the four slots in D_8010F328 that func_8026437C_de accepts, writing its index to out and returning it, or writing -1 and returning NULL when none does. */


extern s32 func_8026437C_de(ControllerProfile *slot);

/** Count how many of the 4 flagged entries in D_8010F328 also have a nonzero unk148 in the
 *  matching D_801462C8 record, returning 0 early on the first flagged entry that does not. */



/* Advances the frame timer D_8015404C by D_800D2988 and, once it reaches
   threshold D_800E2358, clears a flag at D_801468A0+0x24 and reports the
   round over through func_8022A748_de on the world 0x1860 bytes before it. */



extern f32 D_800D2988;

void func_8022A748_de(void *arg0);

/* Sets arg0's unk14 field to the address of D_800D76C8 and returns 0. */



extern char D_800D76C8;

/* Sets arg0's unk14 field to the address of D_800D76CC and returns 0. */



extern char D_800D76CC;

/* Clears D_80146914, runs func_80264788_de on the value at 0x4 of the menu's widget and then func_80264248_de and func_802647E8_de(widget, 1) on the widget itself, clears the flag at 0x85C of the owner at 0x1C, and returns 1. */







extern s32 D_80146914;

extern void func_80264788_de(s8);


extern void func_802647E8_de(PakMenuSlot *, s32);

/** Report whether the tutorial-progress flags (at 0x1c, 0x20, 0x28) hold any nonzero bit. */




/** Runs func_804423BC_de on a byte in arg1->unk1C->unk5D8[0x83] and writes the result back into that byte. */

extern s32 func_804423BC_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

void func_8043DFC8_de(void) {
    StatusStep *status;
    PlayerSettings *settings;
    s32 i;
    s32 active;
    i = 7;
    status = D_80142622;
    for (; i >= 0; i--) {
        ((StatusView *)status)->active = 0;
        status--;
    }
    i = 0;
    active = 1;
    settings = D_80146398;
    for (; i < 4; i++) {
        if (func_8026437C_de(&D_8010F328[i]) != 0) {
            settings[i].active = active;
            settings[i].selected = i;
            break;
        }
    }
}

ControllerProfile *func_8043E05C_de(s32 *out) {
    s32 i;
    ControllerProfile *s;
    i = 0;
    s = D_8010F328;
    while (i < 4) {
        if (func_8026437C_de(s) != 0) {
            *out = i;
            return s;
        }
        i++;
        s++;
    }
    *out = -1;
    return 0;
}

s32 func_8043E0CC_de(void) {
    char *var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v1;

    var_a2 = 0;
    var_a1 = 0;
    var_a0 = (char *)&D_801462C8;
    var_v1 = 0;
loop_1:
    if (*(s32 *) ((char *) D_8010F328 + var_v1) != 0) {
        var_a2 += 1;
        if (((FlaggedRosterView *)var_a0)->flag == 0) {
            return 0;
        }
    }
    var_a0 += 0x96;
    var_a1 += 1;
    var_v1 += 0x224;
    if (var_a1 >= 4) {
        return var_a2;
    }
    goto loop_1;
}

/** Clears the global counter/flag D_8015404C. */
void func_8043E124_de(void) {
    D_8015404C = 0;
}

s32 func_8043E134_de(void) {
    f32 time;
    CGameStatus *base;

    time = D_8015404C + D_800D2988;
    D_8015404C = time;
    if ((120.0f) <= time) {
        base = &D_801462C8.counters;
        base->teams = 0;
        func_8022A748_de((void *) ((char *) base - 0x1860));
        return 1;
    }
    return 0;
}

s32 func_8043E190_de(ObjRecAt14V1 *arg0) {
    arg0->unk14 = &D_800D76C8;
    return 0;
}

s32 func_8043E1A4_de(ObjRecAt14V1 *arg0) {
    arg0->unk14 = &D_800D76CC;
    return 0;
}

/* Always returns 0. */

s32 func_8043E1B8_de(void) {
    return 0;
}

/** True if any of three flags inside the D_801468A0 record are set. */
s32 func_8043E1C0_de(void) {
    CGameStatus *base = &D_801462C8.counters;
    s32 result;

    result = 0;
    if ((base->round != 0) || (base->elapsed != 0) || (base->state != 0)) {
        result = 1;
    }
    return result;
}

s32 func_8043E1F8_de(s32 arg0, MenuRecAt20V2 *menu) {
    PakMenuSlot **slot;

    D_80146914 = 0;
    slot = &menu->widget;
    func_80264788_de((*slot)->unk4);
    func_80264248_de(*slot);
    func_802647E8_de(*slot, 1);
    menu->owner->unk85C = 0;
    return 1;
}

s32 func_8043E254_de(void) {
    s32 var_a0;
    CGameStatus *state;

    state = &D_801462C8.counters;
    var_a0 = 0;
    if ((state->round != 0) || (state->elapsed != 0) || (state->state != 0)) {
        var_a0 = 1;
    }
    return var_a0;
}

s32 func_8043E28C_de(void *arg0, void *arg1) {
    Shared_ActorView *p;
    u8 *bytep;
    s32 result;

    p = (void *)((MenuRecAt20V2 *)arg1)->owner;
    bytep = &p->controls->selection;
    result = func_804423BC_de(arg1, *bytep, 1, 0, 0xA, 0);
    *bytep = (u8)result;
    return 0;
}
