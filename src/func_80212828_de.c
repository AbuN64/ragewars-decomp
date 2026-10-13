#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802106E0.h"
#include "types.h"

extern f32 D_800C20C0_de[];
extern char D_8013B364[];

extern void func_80211020_de(void *);
extern s32 func_8020D1CC_de(void *, s32, s32);
extern void func_80209874_de(void *, s32);
extern f32 func_802726BC_de(f32 *, f32 *);
extern void func_80208410_de(void *);
extern void func_80208EB0_de(void *);
















void func_80212828_de(void *arg0)
{
    CloseAttackBrain *state;
    CloseAttackActor *peer;
    CloseAttackActor *peer_actor;
    CloseAttackBrain *peer_state;
    s32 value;

    state = ((CloseAttackActor *)arg0)->self->brain;
    peer = state->target;
    if (peer == 0) {
        func_80211020_de(state);
        return;
    }

    peer_actor = peer->self;
    peer_state = peer_actor->brain;
    value = peer_state->route;
    state->destination = value;
    if (value != state->node) {
        state->node = value;
        if (!func_8020D1CC_de(D_8013B364, state->route, value)) {
            func_80209874_de(state, 1);
            return;
        }
    }

    func_80211020_de(state);
    func_80208410_de(state);
    func_80208EB0_de(state);
    if (func_802726BC_de(&peer_actor->pos.x,
                       &state->player->pos.x) < D_800C20C0_de[1] ||
        state->route == state->destination) {
        func_80209874_de(state, state->combat);
    }
}
