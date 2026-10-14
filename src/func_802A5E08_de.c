#include "span_1000/code_802A6AC0.h"
#include "types.h"











extern s32 func_802A2FA4_de(s32 arg0, State802A6DF8 *state);
extern void func_802796F4_de(Lists802A6DF8 *lists, State802A6DF8 *state);

void func_802A5E08_de(Owner802A6DF8 *owner) {
    State802A6DF8 *state;
    State802A6DF8 *next;
    u8 *object;

    state = owner->lists.inactive.head;
    if (state != 0) {
        do {
            next = state->next;
            if (func_802A2FA4_de((s32)owner, state) == 0) {
                object = state->object;
                if (object != 0) {
                    if (state->flags & 1) {
                        if (object[0x13B] != 0) {
                            object[0x13B]--;
                        }
                    }
                    if (state->flags & 2) {
                        object = state->object;
                        if (object[0x1D9] != 0) {
                            object[0x1D9]--;
                        }
                    }
                }
                state->object = 0;
                if (state->value < state->node->value) {
                    state->value = state->node->value;
                }
                func_802796F4_de(&owner->lists, state);
            }
            state = next;
        } while (state != 0);
    }
}
