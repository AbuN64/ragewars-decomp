#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"

typedef struct CollisionInfo CollisionInfo;





extern CollisionInfo g_defaultProbeMotionSettings;
extern Instance8020CD74 *g_currentActorInstance;
extern f32 Gobjinst_GetActorHeight(Instance8020CD74 *actor);
extern s32 CCollision_SweepPoint(Instance8020CD74 *actorStorage, CVector3 current, CVector3 desired, CollisionInfo *motionSettings);








s32 Cbarrel_TestTargetEyeObstruction(Instance8020CD74 *attacker, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    CVector3 desired;
    s32 collisions;

    saved = *attacker;
    ((struct BarrelAnchorActorView *)attacker)->pos.y += Gobjinst_GetActorHeight(attacker);
    ((struct BarrelAnchorActorView *)attacker)->pos.y += ((ActorBarrelIsTargetInViewCone *)(target))->eye;

    desired = ((ActorBarrelIsTargetInViewCone *)(target))->position;
    desired.y += Gobjinst_GetActorHeight(target);
    desired.y += ((ActorBarrelIsTargetInViewCone *)(target))->eye;

    collisions = CCollision_SweepPoint(attacker, ((struct BarrelAnchorActorView *)attacker)->pos, desired, &g_defaultProbeMotionSettings);
    if (g_currentActorInstance == target)
        collisions = 0;

    *attacker = saved;
    return collisions;
}
