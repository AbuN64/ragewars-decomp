#include "span_16E000/code_80420E90.h"
#include "span_166000/code_80403E88.h"
#include "types.h"

/* Calls func_8029973C_de, then func_8042177C_de when the word at offset 0x34 of the object D_800E4400
   points to is clear, or func_8041A430_de on its first word with 2 and func_804210E8_de otherwise.
   Returns zero. */
struct State_func_804219E0_de;

extern struct State_func_804219E0_de *D_800E4400;
extern void func_8029973C_de();

extern void func_8041A430_de(void *, s32);


s32 func_80421F08_eu(void) {
    struct State_func_804219E0_de *state;

    func_8029973C_de();
    state = D_800E4400;
    if (state->ready == 0) {
        func_8042177C_de();
    } else {
        func_8041A430_de(state->first, 2);
        func_804210E8_de();
    }
    return 0;
}
