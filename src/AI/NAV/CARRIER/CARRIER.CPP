#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/SELF.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "AI/NAV/CARRIER.H"

void Nav_InitCarrierRoute(AiTarget *aiTarget) {
    AiController *controller;
    controller = aiTarget->player->controller;
    ((CloseAttackBrain *)controller)->state = 0;
    Scaled_ResetBehaviorState(controller);
    controller->behaviorResetFlag = 0;
}

extern s32 Scaled_SetBehaviourState(void *, s32);
extern void Nav_RunBehaviorHandler(void *);
extern f32 Scaled_DistanceToNode(s32 *, s32);
extern void Nav_SteerAlongRoute(void *);
extern void Nav_UpdateTargetSteering(s32 *);
extern char g_playerViewRenderContext;






void Nav_FollowMarkerCarrierRoute(AiTarget *aiTarget) {
    AiController *controller;
    void *v0;

    controller = aiTarget->player->controller;
    v0 = Playerai_FindPlayerWithMarker(&g_playerViewRenderContext);
    if (v0 == 0 || v0 != (void *)controller->player) {
        Scaled_SetBehaviourState(controller, 2);
        return;
    }
    controller = aiTarget->player->controller;
    Nav_RunBehaviorHandler(controller);
    Scaled_DistanceToNode(controller, controller->mode);
    Nav_SteerAlongRoute(controller);
    Nav_UpdateTargetSteering(controller);
}



