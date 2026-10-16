#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80275E44.h"
#include "TYPES.H"
#include "span_1000/code_80277444.h"
#include "common/unused.h"










extern void func_8027207C_de(f32 *);




s32 func_80277128_de(ObjectRecAtBC *arg0, u32 arg1, u32 arg2, u32 arg3,
                  Vec3 *arg4, f32 *arg5) {
    f32 temp_f0;
    f32 var_f0;
    f32 var_f1;
    f32 var_f20;
    f32 var_f3;
    u8 temp_v1;

    var_f3 = *(f32 *)&arg1;
    var_f20 = 0.0f;
    if (!(D_800C4AC0_de <= var_f3) && !(var_f3 <= D_800C4AC4_de) &&
        !(D_800C4AC0_de <= *(f32 *)&arg2) && !(*(f32 *)&arg2 <= D_800C4AC4_de) &&
        !(D_800C4AC0_de <= *(f32 *)&arg3) && !(*(f32 *)&arg3 <= D_800C4AC4_de)) {
        temp_v1 = arg0->shape;
        switch (temp_v1) {
        case 0:
            var_f20 = (var_f3 * var_f3) + (*(f32 *)&arg2 * *(f32 *)&arg2) +
                      (*(f32 *)&arg3 * *(f32 *)&arg3);
            if (!(D_800C4AC0_de < var_f20)) {
                var_f20 = D_800CD3F8[(s32)(var_f20 * D_800C4AC8_de)];
                goto shared;
            }
            goto fail;
        case 2:
            if (!(var_f3 <= 0.0f)) {
                var_f20 = (*(f32 *)&arg2 * *(f32 *)&arg2) +
                          (*(f32 *)&arg3 * *(f32 *)&arg3);
                if (!((var_f3 * var_f3) < var_f20)) {
                    var_f20 = D_800CD4FC[(s32)(var_f20 * D_800C4ACC_de)];
                    var_f20 /= var_f3;
                    goto shared;
                }
            }
            goto fail;
        case 1:
            if (var_f3 < 0.0f) {
                var_f3 = -var_f3;
            }
            var_f0 = *(f32 *)&arg2;
            *(f32 *)&arg1 = var_f3;
            if (var_f0 < 0.0f) {
                var_f0 = -var_f0;
            }
            var_f1 = *(f32 *)&arg3;
            *(f32 *)&arg2 = var_f0;
            if (var_f1 < 0.0f) {
                var_f1 = -var_f1;
            }
            *(f32 *)&arg3 = var_f1;
            var_f20 = var_f1;
            if (!(var_f0 <= var_f20)) {
                var_f20 = var_f0;
            }
            if (!(var_f3 <= var_f20)) {
                var_f20 = var_f3;
            }
            goto shared;
        default:
            goto shared;
        }
shared:
        var_f20 = D_800C4AD0_de - var_f20;
        temp_f0 = arg0->falloff;
        if (var_f20 < temp_f0) {
            var_f20 /= temp_f0;
        } else {
            var_f20 = D_800C4AD0_de;
        }
        if (arg0->shape == 1) {
            *arg4 = arg0->axis;
        } else {
            *arg4 = *(Vec3 *)&arg1;
        }
        func_8027207C_de(arg4);
        *arg5 = var_f20;
        return 1;
    } else {
fail:
        arg4->y = 0.0f;
        arg4->z = 0.0f;
        arg4->x = D_800C4AD4_de;
        *arg5 = 0.0f;
        return 0;
    }
}
