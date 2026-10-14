#include "span_1000/code_8023330C.h"
#include "types.h"








extern f32 D_800D2988;

u32 func_802337D0_de(StateRecAt10 *state) {
    f32 scale;
    f32 step;

    if (state->value > state->limit) {
        state->limit = state->value;
    }
    if (state->rate == 0.0f) {
        state->accumulator = D_800C3080_de;
    }
    if (state->rate < state->limit + state->limit) {
        state->rate = state->limit + state->limit;
    }

    step = D_800D2988;
    scale = D_800C3084_de;
    state->value = func_802747A0_de(state->value, step * scale);
    state->limit = func_802747A0_de(state->limit, D_800D2988 * scale);

    switch (state->mode) {
    case 1:
        if (state->rate > 0.0f) {
            state->accumulator += (state->rate + state->rate) * (D_800D2988 * scale);
            state->rate = func_802747A0_de(state->rate, D_800C3088_de);
        }
        break;
    case 0:
        if (state->rate > 0.0f) {
            state->rate = func_802747A0_de(state->rate, D_800C308C_de);
        }
        break;
    }

    return state->rate == 0.0f;
}
