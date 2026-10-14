#include "span_1000/code_802AE028.h"
#include "types.h"





extern s32 func_802AE030_de(RuntimeState *state, u32 index, DecodeResult_func_802AE6BC_de *result);
extern u32 func_802AEA2C_de(RuntimeState *state, u32 index);

void func_802AE6BC_de(RuntimeState *state, DecodeResult_func_802AE6BC_de *result) {
    u32 minimum;
    u32 index;
    u32 selected;
    u32 decrement;

    minimum = -1;
    index = 0;
    decrement = state->previous;
    do {
        if ((state->active >> index) & 1) {
            if (state->first != 0) {
                state->results[index] -= decrement;
            }
            if (state->results[index] < minimum) {
                minimum = state->results[index];
                selected = index;
            }
        }
        index++;
    } while (index < 16);

    func_802AE030_de(state, selected, result);
    result->value = minimum;
    state->previous = minimum;
    state->total += minimum;
    if (result->type != 0x12) {
        u32 delta;

        delta = func_802AEA2C_de(state, selected);
        state->results[selected] += delta;
    }
    state->first = 1;
}
