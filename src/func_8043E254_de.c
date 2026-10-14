#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"

/** Report whether the tutorial-progress flags (at 0x1c, 0x20, 0x28) hold any nonzero bit. */


extern State_func_8043E254_de D_801468A0;

s32 func_8043E254_de(void) {
    s32 var_a0;
    State_func_8043E254_de *state;

    state = &D_801468A0;
    var_a0 = 0;
    if ((state->unk28 != 0) || (state->unk1C != 0) || (state->unk20 != 0)) {
        var_a0 = 1;
    }
    return var_a0;
}
