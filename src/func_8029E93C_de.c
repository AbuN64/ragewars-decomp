#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029EB74.h"
#include "types.h"







void func_8029E93C_de(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Vec3 delta;
    f32 numerator;
    f32 denominator;
    f32 fraction;

    delta.x = arg2->x - arg1->x;
    delta.y = arg2->y - arg1->y;
    delta.z = arg2->z - arg1->z;
    numerator = -((arg3 * arg1->x) + (arg4 * arg1->y) + (arg5 * arg1->z) + arg6);
    denominator = (arg3 * delta.x) + (arg4 * delta.y) + (arg5 * delta.z);
    if (!(denominator < D_800C5CAC_de) || (fraction = D_800C5CB4_de, !(D_800C5CB0_de < denominator))) {
        fraction = numerator / denominator;
    }
    arg0->x = arg1->x + (fraction * delta.x);
    arg0->y = arg1->y + (fraction * delta.y);
    arg0->z = arg1->z + (fraction * delta.z);
}
