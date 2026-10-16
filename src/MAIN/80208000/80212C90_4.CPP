#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80212C90.h"
#include "TYPES.H"

extern void func_80211020_de(void *);
extern void func_80208410_de(void *);
extern void func_80208AAC_de(void *arg0);














void func_80212D94_de(void *arg0)
{
    AiTarget *actor = arg0;
    AiController *state;
    AiTarget *peer;
    AiController *peer_state;
    s32 value;

    state = actor->player->controller;
    peer = state->target;
    if (peer == 0) {
        func_80211020_de(state);
        return;
    }
    peer_state = peer->player->controller;
    value = peer_state->current;
    if (value != state->fallback) {
        state->fallback = value;
    }
    func_80208410_de(state);
    func_80211020_de(state);
    func_80208AAC_de(state);
}
