#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80443868.h"
#include "types.h"
#include "stddef.h"
/* Advances the actor inactivity timer and reports pending menu state. */
s32 func_8022B178_de(void *); /* extern */
void func_8044972C_de(void *); /* extern */
extern TutorialProgress D_801468A0[];
s32 func_804438BC_de(StateRecAt1C *arg0) {
    TutorialProgress *state;
    s32 temp_v0;
    s32 var_v0;
    Actor_func_804438BC_de *temp_s0;
    temp_s0 = arg0->unk1C;
    if ((temp_s0->unk1450 == 0) && (func_8022B178_de(temp_s0) != 0)) {
        temp_v0 = temp_s0->unk1340 + 1;
        temp_s0->unk1340 = temp_v0;
        if (temp_v0 >= 0x4C) {
            func_8044972C_de(arg0->unk1C);
            return 1;
        }
    }
    var_v0 = 0;
    state = D_801468A0;
    if (state[0].unk28 || state[0].unk1C || state[0].unk20) var_v0 = 1;
    return var_v0;
}
