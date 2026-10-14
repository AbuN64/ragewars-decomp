#include "span_16E000/code_8042BD40.h"
#include "types.h"

/* Clears the words at offsets 0x78 and 0x54 of D_801468A0, then calls func_80298368_de with 0x14
   unless func_8042AF28_de and func_8042ACD8_de both report something, in which case it calls
   func_8042DEA0_de. */


extern struct State_func_8042CFDC_de D_801468A0;
extern s32 func_8042AF28_de();
extern s32 func_8042ACD8_de();
extern void func_80298368_de(s32);
extern void func_8042DEA0_de();

void func_8042CFDC_de(void) {
    struct State_func_8042CFDC_de *state = &D_801468A0;

    state->second = 0;
    state->first = 0;
    if (func_8042AF28_de() == 0 || func_8042ACD8_de() == 0) {
        func_80298368_de(0x14);
    } else {
        func_8042DEA0_de();
    }
}
