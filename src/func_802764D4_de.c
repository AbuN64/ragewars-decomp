#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80275E44.h"
#include "types.h"

extern void func_80276510_de(void *arg0, s32 arg1, void *arg2);






void func_802764D4_de(void *arg0, s32 arg1, void *arg2) {
    f32 *bounds = arg0;
    Vec3 *points = arg2;
    f32 temp_f0;
    f32 temp_f0_2;

    if (arg1 != 0) {
        temp_f0 = points->x;
        bounds[2] = temp_f0;
        bounds[0] = temp_f0;
        temp_f0_2 = points->z;
        bounds[3] = temp_f0_2;
        bounds[1] = temp_f0_2;
        func_80276510_de(arg0, arg1 - 1, points + 1);
    }
}
