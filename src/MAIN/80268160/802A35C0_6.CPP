#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A25C4.h"
#include "TYPES.H"
#include "common/unused.h"
#include "shared/func_8021E2A0_de_closed.h"









extern void func_802A5780_de(s32, State_func_802A2FA4_de *, Nodes *);
extern void func_802A5FF0_de(State_func_802A2FA4_de *);




s32 func_802A2FA4_de(s32 arg0, State_func_802A2FA4_de *state) {
    LevelActor *object;
    Nodes *node;
    Nodes *next;
    f32 saved_step;
    f32 zero;
    f32 decay;
    f32 cutoff;
    f32 value;
    f32 updated;

    saved_step = D_800D2988;
    if (state->flags & 2) {
        D_800D2988 = saved_step * D_800CD740_de;
    }
    if (state->flags & 1) {
        D_800D2988 *= (&D_800D2988)[1];
    }
    if (state->flags & 8) {
        state->retries++;
        if (state->retries >= 3) {
            state->object = 0;
        }
    }

    if (state->count_up >= 0.0f) {
        state->total += D_800D2988;
    }
    state->timer -= D_800D2988;
    if (state->timer < 0.0f) {
        state->timer = 0.0f;
    }

    node = state->nodes;
    if (node != 0) {
        zero = 0.0f;
        decay = D_800C5DE0_de[1];
        cutoff = D_800C5DE8_de[0];
        do {
            next = node->next;
            if (state->timer <= zero && node->value > zero) {
                node->value = zero;
            }
            value = node->value;
            if (value <= zero) {
                updated = value - decay;
                node->value = updated;
                if (updated < cutoff) {
                    func_802A5780_de(arg0, state, node);
                }
            } else {
                updated = value - D_800D2988;
                node->value = updated;
                if (updated < zero) {
                    node->value = zero;
                }
            }
            node = next;
        } while (node != 0);
    }

    object = state->object;
    if (state->object != 0 && (state->flags & 1) &&
        !(object->flags & 0x200)) {
        func_802A5FF0_de(state);
    }
    D_800D2988 = saved_step;

    if (state->active == 0) {
        if (state->timer != 0.0f) {
            if (state->object == 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    return 1;
}
