#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_16E000/code_80423280.h"
#include "types.h"

typedef s32 (*Handler80423930)(void *, s32, s32, s32, s32);

extern FieldRow D_800E4564[];
extern FieldRow D_800E4568[];
extern Handler80423930 D_800E456C;

s32 func_80423758_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Handler80423930 *entry;
    ObjRecAtCV1 *actor;
    s32 index;
    s32 wildcard;
    s32 actor_kind;
    s32 table_kind;

    if (D_800E456C != 0) {
        wildcard = 0x7530;
        entry = &D_800E456C;
        index = 0;
        do {
            if (D_800E4564[index].value == arg1) {
                actor = arg0;
                actor_kind = actor->unkC;
                table_kind = D_800E4568[index].value;
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
