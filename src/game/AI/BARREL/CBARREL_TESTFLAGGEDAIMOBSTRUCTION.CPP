#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo g_particleCollisionProbeResult;
extern f32 Gobjinst_GetActorHeight(Instance8020CD74 *);
extern s32 CCollision_SweepPoint(Instance8020CD74 *actorStorage, CVector3 current, CVector3 desired, CollisionInfo *motionSettings);

s32 Cbarrel_TestFlaggedAimObstruction(Instance8020CD74 *probingActor, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    CVector3 desired;
    f32 scale;

    saved = *probingActor;
    scale = g_barrelFlaggedAimProbeScale;
    ((DraftAimPlayer *)probingActor)->position.y += Gobjinst_GetActorHeight(probingActor) * scale;
    ((DraftAimPlayer *)probingActor)->position.y += ((DraftAimPlayer *)probingActor)->height;

    desired = ((ActorBarrelIsTargetInViewCone *)(target))->position;
    desired.y += Gobjinst_GetActorHeight(target) * scale;
    desired.y += ((ActorBarrelIsTargetInViewCone *)(target))->eye;

    CCollision_SweepPoint(probingActor, ((Player *)(probingActor))->pos, desired, &g_particleCollisionProbeResult);
    *probingActor = saved;

    if (g_collisionProbeActorOne != 0 && (g_collisionProbeActorOne->flags & 2)) {
        return 1;
    }
    if (g_collisionProbeActorTwo != 0 && (g_collisionProbeActorTwo->flags & 2)) {
        return 1;
    }
    return 0;
}
