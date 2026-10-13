#include "shared/gameplay_transition.h"
#include "span_1000/code_8022AE90.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"








void *func_8022A504_de(void *arg0, Vec3 position, void *arg4) {
    f32 var_f3;
    Shared_ActorView *var_v1;
    void *var_a1;
    f32 dx, dy, dz, distSq;

    var_f3 = D_800C2CE8_de;
    var_v1 = (void *)((struct Context *)arg0)->head;
    var_a1 = 0;
    if (var_v1 != 0) {
        do {
            if (var_v1->health != 0 && var_v1 != arg4) {
                dx = ((Actor_func_8024A7A0_de *)var_v1)->position0.x - position.x;
                dx = dx * dx;
                dy = ((Actor_func_8024A7A0_de *)var_v1)->position0.y - position.y;
                dy = dy * dy;
                dz = ((Actor_func_8024A7A0_de *)var_v1)->position0.z - position.z;
                dz = dz * dz;
                distSq = (dx + dy) + dz;
                if (distSq < var_f3) {
                    var_f3 = distSq;
                    var_a1 = var_v1;
                }
            }
            var_v1 = var_v1->next;
        } while (var_v1 != 0);
    }
    return var_a1;
}
