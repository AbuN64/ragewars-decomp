#include "span_1000/code_802A25C4.h"
#include "span_1000/code_802A6AC0.h"
#include "types.h"

void func_802A62BC_de(void *arg0) {
    State_func_802A2FA4_de *state = arg0;
    f32 accum;
    f32 delta;
    ChildB4 *node;

    if (state->amount > 0.0f) {
        accum = 0.0f;
        node = (ChildB4 *)state->nodes;
        if (node != 0) {
            do {
                node->fraction = accum / state->amount;
                delta = node->length;
                node = node->unk_4;
                accum += delta;
            } while (node != 0);
        }
    }
}
