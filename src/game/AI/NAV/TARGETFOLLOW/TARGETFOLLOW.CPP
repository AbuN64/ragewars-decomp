#include "AI/SOURCE.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "AI/NAV/80212C90_3.H"
#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"

/* 80212C90_3.CPP */
#if !(defined(VERSION_DE) || defined(VERSION_EU))
void func_80212D80_eu_x(struct ActorRecAt1D8V2 *actor) {
    Brain_func_80212D78_eu_x *brain = actor->player->brain;

    brain->unk220 = 0;
    Scaled_ResetBehaviorState(brain);
    brain->unk2FC = 0;
}
#endif

#if defined(VERSION_DE)
#include "COMMON/SELF.H"

void Nav_ResetTargetFollowStateDe(void *object) {
    CloseAttackActor *actor = object;
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    Scaled_ResetBehaviorState(brain);
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

/* 80212C90_4.CPP */
#if defined(VERSION_EU)
#include "COMMON/SHAREDCALLBACK5.H"

void Nav_ResetTargetFollowStateEu(AiTarget *pThis) {
    AiController *controller = pThis->player->controller;
    controller->handlerIndex = 0;
    Scaled_ResetBehaviorState(controller);
    controller->unk2FC = 0;
}
#endif

#if defined(VERSION_EU)
extern void Nav_RunBehaviorHandler(AiController *);
extern void Nav_SteerAlongRoute(AiController *);
extern void Nav_UpdatePlayerSteering(AiController *);

void Nav_UpdateTargetRouteFollowEu(AiTarget *pThis) {
    AiController *controller = pThis->player->controller;
    s32 current;
    if (controller->target == 0) {
        Nav_RunBehaviorHandler(controller);
    } else {
        current = controller->target->player->controller->current;
        if (current != controller->fallback) {
            controller->fallback = current;
        }
        Nav_SteerAlongRoute(controller);
        Nav_RunBehaviorHandler(controller);
        Nav_UpdatePlayerSteering(controller);
    }
}
#endif
