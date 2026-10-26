#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/SHAREDCALLBACK5.H"

void Nav_ResetTargetFollowStateEu(AiTarget *pThis) {
    AiController *controller = pThis->player->controller;
    controller->handlerIndex = 0;
    Nav_ResetBehaviorState(controller);
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
