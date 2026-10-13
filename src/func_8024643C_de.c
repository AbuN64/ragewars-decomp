#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80245980.h"
#include "types.h"
typedef struct CollisionInfo CollisionInfo;








extern char D_80103FD0;
extern f32 func_8024D284_de(Instance8020CD74 *);
extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, CollisionInfo *);






s32 func_8024643C_de(Instance8020CD74 *arg0, Instance8020CD74 *arg1) {
    Instance8020CD74 saved;
    Vec3 desired;
    f32 scale;
    s32 collisions;

    saved = *arg0;
    scale = D_800C3828_de;
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += func_8024D284_de(arg0) * scale;
    desired = ((struct Actor_func_80214DD4_de *)arg1)->pos;
    desired.y += func_8024D284_de(arg1) * scale;
    collisions = func_80243A90_de(arg0, desired, &D_80103FD0);
    *arg0 = saved;

    return collisions == 0;
}
