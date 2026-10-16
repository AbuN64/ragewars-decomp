#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80213ED4.h"
#include "TYPES.H"
typedef struct CollisionInfo CollisionInfo;





extern CollisionInfo D_80100030;
extern Instance8020CD74 *D_801041F0;
extern f32 func_8024D284_de(Instance8020CD74 *arg0);
extern s32 func_802444A4_de(Instance8020CD74 *arg0, Vec3 current, Vec3 desired, CollisionInfo *arg3);








s32 func_80216BF4_de(Instance8020CD74 *arg0, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    Vec3 desired;
    s32 collisions;

    saved = *arg0;
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += func_8024D284_de(arg0);
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += ((Actor_func_80214310_de *)(target))->eye;

    desired = ((Actor_func_80214310_de *)(target))->position;
    desired.y += func_8024D284_de(target);
    desired.y += ((Actor_func_80214310_de *)(target))->eye;

    collisions = func_802444A4_de(arg0, ((struct Actor_func_80214DD4_de *)arg0)->pos, desired, &D_80100030);
    if (D_801041F0 == target)
        collisions = 0;

    *arg0 = saved;
    return collisions;
}
