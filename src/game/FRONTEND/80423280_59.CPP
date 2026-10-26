#include "COMMON/RECRECAT4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "FRONTEND/80423280_59.H"
#include "RENDER_2/8025DE50_5.H"
#include "SCENE/802508E0_13.H"
extern SettingsScreenState *D_800E5430;
extern void func_8041A430_de(void *, s32);

/* Releases the object D_800E5430 holds through Cache_FreeMemory, clears D_800E5430 and returns zero. */



/* Runs the screen D_800E5430 each frame: past stage 1 of D_800E28E0 it only calls Tsmos_DeactivateControllerState;
   otherwise it calls Tsmos_ActivateControllerState and, while its menu reports 3, counts the delay at 0xC down and
   on expiry scrolls the list at 0x8 back one row, wrapping to the menu's own row count, and
   restarts the delay at 3; when the menu reports 4 it calls MarkMenuEventHandled and leaves through
   func_80298368_de with the stored target or func_802998A8_de when that is -1. Returns zero. Written
   from the assembly as a switch on the menu result, matching on the first trial. */








extern void Tsmos_DeactivateControllerState();

extern void Tsmos_ActivateControllerState();

extern s32 func_8041A470_de(struct Menu_func_804241BC_de *);

extern void MarkMenuEventHandled();

extern void func_80298368_de(s32);


/* Activates the requested player slots and creates any missing players when entering the screen. */







extern SlotRecAt7F g_playerSettings[];

extern s8 D_80102B0D[];

extern void MarkMenuEventHandled(void);

/* Calls MarkMenuEventHandled, then sets the word at offset 0x10 of the object D_800E5430 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */




/* When the fourth argument is one, calls MarkMenuEventHandled, advances the word at 0x20 of the object D_800E5430 holds while Control_IsControllerConnected reports one for it and it is below func_80264690_de's limit, formats that word into the object's text at 0x14 through XStdio_FormatBuffer with D_800E1B60, and plays sound 0xE81 through SoundElement_PlayFlatSound; returns zero.
   Adapted from Menu_StartOptionsImageTransition with the object chain changed to a guarded counter increment, text format and sound call. */








extern void XStdio_FormatBuffer(char *, char *, s32);


/* Slider-down handler: when the fourth argument is one, calls MarkMenuEventHandled, lowers the value at
   offset 0x20 of the object D_800E5430 points to by one while it is at least 2, formats it into the
   text at offset 0x14 with D_800E1B60 through XStdio_FormatBuffer and plays sound 0xE81. Returns zero. */




/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5434, an actor kind at D_800E5438 and a handler at D_800E543C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler8042DFF0)(void *, s32, s32, s32, s32);



extern Handler8042DFF0 D_800E543C;

s32 func_8042DAC8_de(void) {
    Cache_FreeMemory(D_800E5430);
    D_800E5430 = 0;
    return 0;
}

s32 func_8042DAF8_de(void) {
    s32 result;

    if (D_800E28E0 >= 2) {
        Tsmos_DeactivateControllerState();
        return 0;
    }
    Tsmos_ActivateControllerState();
    switch (result = func_8041A470_de(D_800E5430->head.menu)) {
    case 3:
        if (--D_800E5430->head.delay <= 0) {
            D_800E5430->head.list->unk16--;
            if (D_800E5430->head.list->unk16 + D_800E5430->head.list->unk1A < 0) {
                D_800E5430->head.list->unk16 = D_800E5430->head.menu->list->unk1A;
            }
            D_800E5430->head.delay = result;
        }
        break;
    case 4:
        MarkMenuEventHandled();
        if (D_800E5430->head.target != -1) {
            func_80298368_de(D_800E5430->head.target);
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
    int i;
    SlotRecAt7F *slot;

    MarkMenuEventHandled();
    D_800E5430->head.target = 7;
    func_8041A430_de(D_800E5430->head.menu, 2);
    for (i = 0; i < D_800E5430->count; i++) {
        slot = &g_playerSettings[i];
        slot->active = 1;
        slot->index = i;
        if (D_80102B0D[i * 400] < 0) {
            Player_InitializeProfileSlot(i);
        }
    }
    return 0;
}

s32 func_8042DCC4_de(void) {
    SettingsScreenState *state;

    MarkMenuEventHandled();
    state = D_800E5430;
    state->head.target = -1;
    func_8041A430_de(state->head.menu, 2);
    return 0;
}

s32 func_8042DD00_de(void *a0, void *a1, void *a2, s32 press) {
    SettingsScreenState *object;

    if (press != 1) {
        return 0;
    }
    MarkMenuEventHandled();
    if (Control_IsControllerConnected(D_800E5430->count) == press) {
        object = D_800E5430;
        if (object->count < Control_CountConnectedControllers()) {
            D_800E5430->count++;
        }
    }
    XStdio_FormatBuffer(D_800E5430->text, D_800E1B60, D_800E5430->count);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}

s32 func_8042DDA8_de(void *first, void *second, void *third, s32 fourth) {
    s32 value;

    if (fourth != 1) {
        return 0;
    }
    MarkMenuEventHandled();
    value = D_800E5430->count;
    if (value >= 2) {
        D_800E5430->count = value - 1;
    }
    XStdio_FormatBuffer(D_800E5430->text, D_800E1B60, D_800E5430->count);
    SoundElement_PlayFlatSound(0xE81);
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
