#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern f32 D_800C2CE0_de[2];






void *func_8022A480_de(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_f3;
    func_8022A470_S2 *var_v1;
    void *var_v0;
    f32 dx, dy, dz, distSq;

    func_80228774_S1 *object;

    var_f3 = D_800C2CE0_de[1];
    object = arg0;
    var_v1 = object->unk20;
    var_v0 = 0;
    if (var_v1 != 0) {
        do {
            dx = var_v1->unk8 - *(f32 *)&arg1;
            dx = dx * dx;
            dy = var_v1->unkC - *(f32 *)&arg2;
            dy = dy * dy;
            dz = var_v1->unk10 - *(f32 *)&arg3;
            dz = dz * dz;
            distSq = (dx + dy) + dz;
            if (distSq < var_f3) {
                var_f3 = distSq;
                var_v0 = var_v1;
            }
            var_v1 = var_v1->unk16E0;
        } while (var_v1 != 0);
    }
    return var_v0;
}
