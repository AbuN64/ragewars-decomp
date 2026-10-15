#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80213ED4.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"
#include "common/unused.h"

typedef struct CollisionInfo CollisionInfo;

extern CollisionInfo D_80103FD0;
extern f32 func_8024D284_de(Instance8020CD74 *);
extern s32 func_802444A4_de(Instance8020CD74 *arg0, Vec3 current, Vec3 desired, CollisionInfo *arg3);

s32 func_80216A6C_de(Instance8020CD74 *arg0, void *unused, Instance8020CD74 *target) {
    Instance8020CD74 saved;
    Vec3 desired;
    f32 scale;

    saved = *arg0;
    scale = D_800C21CC_de;
    ((DraftAimPlayer *)arg0)->position.y += func_8024D284_de(arg0) * scale;
    ((DraftAimPlayer *)arg0)->position.y += ((DraftAimPlayer *)arg0)->height;

    desired = ((Actor_func_80214310_de *)(target))->position;
    desired.y += func_8024D284_de(target) * scale;
    desired.y += ((Actor_func_80214310_de *)(target))->eye;

    func_802444A4_de(arg0, ((Player *)(arg0))->pos, desired, &D_80103FD0);
    *arg0 = saved;

    if (D_8010028C != 0 && (D_8010028C->flags & 2)) {
        return 1;
    }
    if (D_801002A4 != 0 && (D_801002A4->flags & 2)) {
        return 1;
    }
    return 0;
}
