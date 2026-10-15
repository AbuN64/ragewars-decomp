#include "span_16E000/code_80423280.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Releases the object D_800E5430 holds through func_802547E4_de, clears D_800E5430 and returns zero. */


extern void func_802547E4_de(void *);

/* Runs the screen D_800E5430 each frame: past stage 1 of D_800E28E0 it only calls func_802A2394_de;
   otherwise it calls func_802A2360_de and, while its menu reports 3, counts the delay at 0xC down and
   on expiry scrolls the list at 0x8 back one row, wrapping to the menu's own row count, and
   restarts the delay at 3; when the menu reports 4 it calls func_8029973C_de and leaves through
   func_80298368_de with the stored target or func_802998A8_de when that is -1. Returns zero. Written
   from the assembly as a switch on the menu result, matching on the first trial. */







extern s32 D_800E28E0;

extern void func_802A2394_de();

extern void func_802A2360_de();

extern s32 func_8041A470_de(struct Menu_func_804241BC_de *);

extern void func_8029973C_de();

extern void func_80298368_de(s32);

extern void func_802998A8_de();

/* Activates the requested player slots and creates any missing players when entering the screen. */







extern SlotRecAt7F D_80146398[];

extern s8 D_80102B0D[];

extern void func_8029973C_de(void);

/* Calls func_8029973C_de, then sets the word at offset 0x10 of the object D_800E5430 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */




/* When the fourth argument is one, calls func_8029973C_de, advances the word at 0x20 of the object D_800E5430 holds while func_80264614_de reports one for it and it is below func_80264690_de's limit, formats that word into the object's text at 0x14 through func_802A0C08_de with D_800E1B60, and plays sound 0xE81 through func_8025DF34_de; returns zero.
   Adapted from func_80422340_de with the object chain changed to a guarded counter increment, text format and sound call. */





extern char D_800E1B60[];

extern s32 func_80264614_de(s32);

extern s32 func_80264690_de();

extern void func_802A0C08_de(char *, char *, s32);

extern void func_8025DF34_de(s32);

/* Slider-down handler: when the fourth argument is one, calls func_8029973C_de, lowers the value at
   offset 0x20 of the object D_800E5430 points to by one while it is at least 2, formats it into the
   text at offset 0x14 with D_800E1B60 through func_802A0C08_de and plays sound 0xE81. Returns zero. */




/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5434, an actor kind at D_800E5438 and a handler at D_800E543C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8042DFF0)(void *, s32, s32, s32, s32);

extern FieldRow D_800E5434[];

extern FieldRow D_800E5438[];

extern Handler8042DFF0 D_800E543C;

s32 func_8042DAC8_de(void) {
    extern void *D_800E5430;
    func_802547E4_de(D_800E5430);
    D_800E5430 = 0;
    return 0;
}

s32 func_8042DAF8_de(void) {
    extern struct State_func_8042DAF8_de *D_800E5430;
    s32 result;

    if (D_800E28E0 >= 2) {
        func_802A2394_de();
        return 0;
    }
    func_802A2360_de();
    switch (result = func_8041A470_de(D_800E5430->menu)) {
    case 3:
        if (--D_800E5430->delay <= 0) {
            D_800E5430->list->unk16--;
            if (D_800E5430->list->unk16 + D_800E5430->list->unk1A < 0) {
                D_800E5430->list->unk16 = D_800E5430->menu->list->unk1A;
            }
            D_800E5430->delay = result;
        }
        break;
    case 4:
        func_8029973C_de();
        if (D_800E5430->target != -1) {
            func_80298368_de(D_800E5430->target);
            return 0;
        }
        func_802998A8_de();
        break;
    default:
        return 0;
    }
    return 0;
}

int func_8042DC04_de(void) {
    extern void func_8041A430_de(int, int);
    extern Screen_func_8042DC04_de *D_800E5430;
    int i;
    SlotRecAt7F *slot;

    func_8029973C_de();
    D_800E5430->state = 7;
    func_8041A430_de(D_800E5430->window, 2);
    for (i = 0; i < D_800E5430->count; i++) {
        slot = &D_80146398[i];
        slot->active = 1;
        slot->index = i;
        if (D_80102B0D[i * 400] < 0) {
            func_8022F204_de(i);
        }
    }
    return 0;
}

s32 func_8042DCC4_de(void) {
    extern void func_8041A430_de(void *, s32);
    extern struct State_func_80421D94_de *D_800E5430;
    struct State_func_80421D94_de *state;

    func_8029973C_de();
    state = D_800E5430;
    state->value = -1;
    func_8041A430_de(state->first, 2);
    return 0;
}

s32 func_8042DD00_de(void *a0, void *a1, void *a2, s32 press) {
    extern struct Object_func_8042DD00_de *D_800E5430;
    struct Object_func_8042DD00_de *object;

    if (press != 1) {
        return 0;
    }
    func_8029973C_de();
    if (func_80264614_de(D_800E5430->value) == press) {
        object = D_800E5430;
        if (object->value < func_80264690_de()) {
            D_800E5430->value++;
        }
    }
    func_802A0C08_de(D_800E5430->text, D_800E1B60, D_800E5430->value);
    func_8025DF34_de(0xE81);
    return 0;
}

s32 func_8042DDA8_de(void *first, void *second, void *third, s32 fourth) {
    extern struct Object_func_8042DD00_de *D_800E5430;
    s32 value;

    if (fourth != 1) {
        return 0;
    }
    func_8029973C_de();
    value = D_800E5430->value;
    if (value >= 2) {
        D_800E5430->value = value - 1;
    }
    func_802A0C08_de(D_800E5430->text, D_800E1B60, D_800E5430->value);
    func_8025DF34_de(0xE81);
    return 0;
}

s32 func_8042DE10_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8042DFF0 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E543C != 0) {
        wildcard = 0x7530;
        entry = &D_800E543C;
        index = 0;
        do {
            if (D_800E5434[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5438[index].value;
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
