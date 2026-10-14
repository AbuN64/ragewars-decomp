#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"

/* Returns whether any of the words at offsets 0x28, 0x1C and 0x20 of D_801468A0 is set. */


extern struct State_func_8043E254_de D_801468A0;

s32 func_8043E530_de(void) {
    struct State_func_8043E254_de *state = &D_801468A0;

    return state->unk28 != 0 || state->unk1C != 0 || state->unk20 != 0;
}
