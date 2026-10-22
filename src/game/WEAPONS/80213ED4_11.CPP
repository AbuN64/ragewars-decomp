#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "WEAPONS/80213ED4_19.H"

void func_80216808_de(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;

    f0 = arg2;
    f1 = arg3;
    f3 = f1;
    if (f0 < f1 || (f0 = -f0, f1 < f0)) {
        f1 = f0;
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
