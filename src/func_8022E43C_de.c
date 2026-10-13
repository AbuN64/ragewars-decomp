#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022D944.h"
#include "types.h"
typedef struct CollisionInfo CollisionInfo;







extern f32 D_800C2E10_de[];
extern CollisionInfo D_80100030;
extern f32 func_8024D284_de(Instance8020CD74 *);
extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, CollisionInfo *);





s32 func_8022E43C_de(Instance8020CD74 *arg0, Vec3 *arg1) {
    Instance8020CD74 saved;
    s32 moved;

    saved = *arg0;
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += func_8024D284_de(arg0) * D_800C2E10_de[1];
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += ((struct Actor_func_80214DD4_de *)arg0)->height;
    func_80243A90_de(arg0, *arg1, &D_80100030);

    moved = (arg1->x != ((struct Actor_func_80214DD4_de *)arg0)->pos.x) ||
            (arg1->y != ((struct Actor_func_80214DD4_de *)arg0)->pos.y) ||
            (arg1->z != ((struct Actor_func_80214DD4_de *)arg0)->pos.z);
    *arg1 = ((struct Actor_func_80214DD4_de *)arg0)->pos;
    *arg0 = saved;

    return moved;
}
