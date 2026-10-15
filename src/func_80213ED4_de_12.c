#include "span_1000/code_80213ED4.h"
#include "types.h"
#include "shared/func_8021E2A0_de_closed.h"



extern f32 func_80215868_de(void *arg0, f32 arg1, f32 arg2, f32 arg3,
                        void *arg4, f32 arg5);


void func_802168B8_de(void *arg0, s32 arg1, VecRecAt10 *arg2, f32 arg3) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    if (arg2 != 0) {
        f1 = func_80215868_de(arg0, arg2->x, arg2->y, arg2->z,
                           arg2, D_800C21C8_de);
        f3 = f1;
        if (arg3 < f1) {
            f1 = arg3;
        } else {
            f0 = -arg3;
            if (f1 < f0) {
                f1 = f0;
            }
        }
        f1 = f1 * D_800D2988;
        f2 = f1;
        if (f1 < 0.0f) {
            f2 = -f1;
        }
        if (f3 < 0.0f) {
            if (-f3 < f2) {
                goto clamp;
            }
        } else if (f3 < f2) {
clamp:
            f1 = f3;
        }
        func_80217074_de(arg0, f1);
    }
}
