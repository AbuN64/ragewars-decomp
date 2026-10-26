#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_14.H"

#if !(defined(VERSION_DE))
void Nav_InitPursuitStrafe(void *closeAttackActor) {
    CloseAttackActor *actor = closeAttackActor;
    CloseAttackActor *level1 = actor->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2;

    inner->state = 0;
    Nav_ResetBehaviorState(inner);

    r1 = Nav_NextRandom();
    inner->timer = r1 % 4 + 0xC;

    r2 = Nav_NextRandom();
    inner->pattern = r2 % 2;
}
#endif
