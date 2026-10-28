#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"

typedef struct CollisionInfo CollisionInfo;





extern CollisionInfo D_80100030;
extern Instance8020CD74 *D_801041F0;
extern f32 Gobjinst_GetActorHeight(Instance8020CD74 *arg0);
extern s32 CCollision_SweepPoint(Instance8020CD74 *arg0, CVector3 current, CVector3 desired, CollisionInfo *arg3);








s32 Cbarrel_TestTargetEyeObstruction(Instance8020CD74 *attacker, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    CVector3 desired;
    s32 collisions;

    saved = *attacker;
    ((struct Actor_func_80214DD4_de *)attacker)->pos.y += Gobjinst_GetActorHeight(attacker);
    ((struct Actor_func_80214DD4_de *)attacker)->pos.y += ((ActorBarrelIsTargetInViewCone *)(target))->eye;

    desired = ((ActorBarrelIsTargetInViewCone *)(target))->position;
    desired.y += Gobjinst_GetActorHeight(target);
    desired.y += ((ActorBarrelIsTargetInViewCone *)(target))->eye;

    collisions = CCollision_SweepPoint(attacker, ((struct Actor_func_80214DD4_de *)attacker)->pos, desired, &D_80100030);
    if (D_801041F0 == target)
        collisions = 0;

    *attacker = saved;
    return collisions;
}
