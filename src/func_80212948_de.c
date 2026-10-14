#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

extern f32 D_800C20C8_de;

extern void func_80211020_de(void *);
extern void func_80212670_de(void *arg0);
extern s32 func_80209874_de(void *, s32);
extern f32 func_802726BC_de(f32 *arg0, f32 *arg1);
extern void func_80208410_de(void *);
extern void func_80208EB0_de(s32 *);














void func_80212948_de(void *arg0)
{
    CloseAttackBrain *state;
    CloseAttackActor *actor = arg0;
    s32 old_state;

    state = actor->self->brain;
    if (state->target == 0) {
        func_80211020_de(state);
        return;
    }

    old_state = state->destination;
    if (old_state == -1) {
        func_80212670_de(state);
        if (state->destination == old_state ||
            state->destination == state->route) {
            func_80209874_de(state, 4);
            return;
        }
    }

    if (D_800C20C8_de < func_802726BC_de(
            &state->target->self->pos.x,
            &state->player->pos.x)) {
        func_80209874_de(state, state->combat);
        return;
    }

    func_80211020_de(state);
    func_80208410_de(state);
    func_80208EB0_de(state);
    if (state->route == state->destination) {
        state->destination = -1;
    }
}
