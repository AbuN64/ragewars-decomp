#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80435CE4.h"
#include "TYPES.H"

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E555C, an actor kind at D_800E5560 and a handler at D_800E5564: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80435F70)(void *, s32, s32, s32, s32);


extern FieldRow D_800E555C[];
extern FieldRow D_800E5560[];
extern Handler80435F70 D_800E5564;




s32 func_80435D90_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80435F70 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    ObjRecAtCV1 *actor;

    if (D_800E5564 != 0) {
        wildcard = 0x7530;
        entry = &D_800E5564;
        index = 0;
        do {
            if (D_800E555C[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E5560[index].value;
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
