#include "COMMON/RECRECAT4.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/80423280_33.H"

/* On event 3 with value 0xA, calls MarkMenuEventHandled, sets the word at offset 0x18 of the object
   D_800E4600 points to to 0x1C and calls func_8041A430_de on its first word with 2. Returns zero. */


extern struct State_func_804242D4_de *D_800E4600;

extern void MarkMenuEventHandled();

extern void func_8041A430_de(void *, s32);

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E4604, an actor kind at D_800E4608 and a handler at D_800E460C: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80424528)(void *, s32, s32, s32, s32);

extern Handler80424528 D_800E460C;

s32 func_804242D4_de(void *first, void *second, u32 event, s32 value) {
    struct State_func_804242D4_de *state;

    if ((event >> 16) == 3 && value == 0xA) {
        MarkMenuEventHandled();
        state = D_800E4600;
        state->value = 0x1C;
        func_8041A430_de(state->first, 2);
    }
    return 0;
}

s32 func_80424328_de(void) {
    MarkMenuEventHandled();
    return 0;
}

s32 func_80424348_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80424528 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E460C != 0) {
        wildcard = 0x7530;
        entry = &D_800E460C;
        index = 0;
        do {
            if (D_800E4604[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4608[index].value;
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
