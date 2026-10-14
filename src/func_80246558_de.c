#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80245980.h"
#include "types.h"









extern CollisionState D_801041F0;
extern s32 func_80243A90_de(Instance8020CD74 *, Vec3Words, CollisionInfo_func_80246558_de *);

s32 func_80246558_de(Instance8020CD74 *arg0, Vec3Words arg1, CollisionInfo_func_80246558_de *arg2) {
    Instance8020CD74 saved;
    CollisionInfo_func_80246558_de collision_info;
    s32 collisions;

    saved = *arg0;
    collision_info = *arg2;
    collision_info.ground_behavior = 0;
    collision_info.instance_behavior = 1;
    func_80243A90_de(arg0, arg1, &collision_info);
    *arg0 = saved;

    collisions = D_801041F0.active0 || D_801041F0.active9c;
    return !collisions;
}
