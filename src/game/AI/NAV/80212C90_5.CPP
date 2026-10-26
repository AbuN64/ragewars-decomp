#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "AI/NAV/80212C90_5.H"

#if defined(VERSION_DE)
#include "COMMON/SELF.H"

void Nav_ResetTargetFollowStateDe(void *object) {
    CloseAttackActor *actor = object;
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Nav_ResetBehaviorState(brain);
    brain->reset2FC = 0;
}
#endif

#if !(defined(VERSION_EU))
extern void Nav_RunBehaviorHandler(void *);
extern void Nav_SteerAlongRoute(void *);
extern void Nav_UpdatePlayerSteering(void *arg0);














void Nav_UpdateTargetRouteFollow(void *arg0)
{
    AiTarget *actor = arg0;
    AiController *state;
    AiTarget *peer;
    AiController *peer_state;
    s32 value;

    state = actor->player->controller;
    peer = state->target;
    if (peer == 0) {
        Nav_RunBehaviorHandler(state);
        return;
    }
    peer_state = peer->player->controller;
    value = peer_state->current;
    if (value != state->fallback) {
        state->fallback = value;
    }
    Nav_SteerAlongRoute(state);
    Nav_RunBehaviorHandler(state);
    Nav_UpdatePlayerSteering(state);
}
#endif

#if defined(VERSION_EU_X)
unsigned int func_80212E24_eu_x_padding_13A24[3] = {
    0x0C09CA69, 0x24070001, 0x02202021,
};
#endif

#if defined(VERSION_DE)
unsigned int func_80212E04_de_padding_13A04[3] = {
    0x3C02800D, 0x8C428130, 0x27BDFFB8,
};
#endif
