#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_80103FD0;
extern f32 Gobjinst_GetActorHeight(Instance8020CD74 *);
extern s32 CCollision_SweepPoint(Instance8020CD74 *actorStorage, CVector3 current, CVector3 desired, CollisionInfo *motionSettings);

s32 Cbarrel_TestFlaggedAimObstruction(Instance8020CD74 *arg0, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    CVector3 desired;
    f32 scale;

    saved = *arg0;
    scale = D_800C21CC_de;
    ((DraftAimPlayer *)arg0)->position.y += Gobjinst_GetActorHeight(arg0) * scale;
    ((DraftAimPlayer *)arg0)->position.y += ((DraftAimPlayer *)arg0)->height;

    desired = ((ActorBarrelIsTargetInViewCone *)(target))->position;
    desired.y += Gobjinst_GetActorHeight(target) * scale;
    desired.y += ((ActorBarrelIsTargetInViewCone *)(target))->eye;

    CCollision_SweepPoint(arg0, ((Player *)(arg0))->pos, desired, &D_80103FD0);
    *arg0 = saved;

    if (D_8010028C != 0 && (D_8010028C->flags & 2)) {
        return 1;
    }
    if (D_801002A4 != 0 && (D_801002A4->flags & 2)) {
        return 1;
    }
    return 0;
}
