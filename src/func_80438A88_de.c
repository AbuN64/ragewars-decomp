#include "span_16E000/code_804379C8.h"
#include "types.h"

/* Resets three words of the object D_800E5830 points to: the words at 0x9C and 0xB0 to -1 and
   the word at 0x188 to zero. */


extern struct State_func_80438A88_de *D_800E5830;

void func_80438A88_de(void) {
    struct State_func_80438A88_de *state = D_800E5830;

    state->first = -1;
    state->second = -1;
    state->third = 0;
}
