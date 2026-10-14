#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Calls func_8029973C_de, then sets the word at offset 0x14 of the object D_800E58A0 points to to -1 and
   calls func_8041A430_de on the object's first word with 2, returning zero. */


extern struct State_func_80439128_de *D_800E58A0;
extern void func_8029973C_de();
extern void func_8041A430_de(void *, s32);

s32 func_80439174_de(void) {
    struct State_func_80439128_de *state;

    func_8029973C_de();
    state = D_800E58A0;
    state->value = -1;
    func_8041A430_de(state->first, 2);
    return 0;
}
