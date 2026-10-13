#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80435CE4.h"
#include "types.h"

/* Dispatches event arg1 through this file's 12-byte handler table, whose rows hold an event at D_800E5628, an actor kind at D_800E562C and a handler at D_800E5630: the first row whose event equals arg1 and whose kind equals the actor's halfword kind at 0xC, or is the wildcard 0x7530, receives all five arguments and its result is returned; with no such row, or an empty table, the result is zero. Adapted from func_802A1B50_de. */

typedef s32 (*Handler80436634)(void *, s32, s32, s32, s32);


extern FieldRow D_800E5628[];
extern FieldRow D_800E562C[];
extern Handler80436634 D_800E5630;




s32 func_80436454_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80436634 *entry;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;
    func_8021C9B4_S3 *actor;

    if (D_800E5630 != 0) {
        wildcard = 0x7530;
        entry = &D_800E5630;
        index = 0;
        do {
            if (D_800E5628[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E562C[index].value;
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
