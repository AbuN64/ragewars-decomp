#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Clears the words at offsets 0x78 and 0x54 of D_801468A0 and calls func_80298368_de with 0xF. */


extern struct State_func_8042CFDC_de D_801468A0;
extern void func_80298368_de(s32);

void func_8042D034_de(void) {
    struct State_func_8042CFDC_de *state = &D_801468A0;

    state->second = 0;
    state->first = 0;
    func_80298368_de(0xF);
}
