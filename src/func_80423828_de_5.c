#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80423280.h"
#include "types.h"

/* Calls func_8029973C_de, sets the word at offset 0x20 of the object D_800E4510 points to to -1,
   calls func_8041A430_de on the object's first word with 2 and then func_80422FC0_de, returning zero. */


extern struct State_func_804232AC_de *D_800E4510;
extern void func_8029973C_de();
extern void func_8041A430_de(void *, s32);
extern void func_80422FC0_de();

s32 func_804233E8_de(void) {
    struct State_func_804232AC_de *state;

    func_8029973C_de();
    state = D_800E4510;
    state->value = -1;
    func_8041A430_de(state->menu, 2);
    func_80422FC0_de();
    return 0;
}
