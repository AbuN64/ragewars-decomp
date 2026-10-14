#include "span_16E000/code_80423280.h"
#include "types.h"

/* On event 3 with value 0xA, calls func_8029973C_de, sets the word at offset 0x18 of the object
   D_800E4600 points to to 0x1C and calls func_8041A430_de on its first word with 2. Returns zero. */


extern struct State_func_804242D4_de *D_800E4600;
extern void func_8029973C_de();
extern void func_8041A430_de(void *, s32);

s32 func_804242D4_de(void *first, void *second, u32 event, s32 value) {
    struct State_func_804242D4_de *state;

    if ((event >> 16) == 3 && value == 0xA) {
        func_8029973C_de();
        state = D_800E4600;
        state->value = 0x1C;
        func_8041A430_de(state->first, 2);
    }
    return 0;
}
