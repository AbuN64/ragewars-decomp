#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"

typedef struct CollisionInfo CollisionInfo;





extern CollisionInfo D_80100030;
extern Instance8020CD74 *D_801041F0;
extern f32 Particle_GetActorHeight(Instance8020CD74 *arg0);
extern s32 func_802444A4_de(Instance8020CD74 *arg0, CVector3 current, CVector3 desired, CollisionInfo *arg3);








s32 func_80216BF4_de(Instance8020CD74 *arg0, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    CVector3 desired;
    s32 collisions;

    saved = *arg0;
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += Particle_GetActorHeight(arg0);
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += ((Actor_func_80214310_de *)(target))->eye;

    desired = ((Actor_func_80214310_de *)(target))->position;
    desired.y += Particle_GetActorHeight(target);
    desired.y += ((Actor_func_80214310_de *)(target))->eye;

    collisions = func_802444A4_de(arg0, ((struct Actor_func_80214DD4_de *)arg0)->pos, desired, &D_80100030);
    if (D_801041F0 == target)
        collisions = 0;

    *arg0 = saved;
    return collisions;
}
