#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_86.H"

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E55C8, an actor kind at D_800E55CC and a handler at D_800E55D0: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from N64Eng_DispatchNumericWidgetEvent. */

typedef s32 (*Handler8043630C)(void *, s32, s32, s32, s32);


extern FieldRow D_800E55C8[];
extern FieldRow D_800E55CC[];
extern Handler8043630C D_800E55D0;




s32 Frontend_DispatchConfirmationEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler8043630C *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E55D0 != 0) {
        wildcard = 0x7530;
        entry = &D_800E55D0;
        index = 0;
        do {
            if (D_800E55C8[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E55CC[index].value;
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
