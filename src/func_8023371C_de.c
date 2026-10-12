#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8023330C.h"
#include "types.h"

extern f32 func_80274808_de(f32, f32, s32);
extern s32 func_80214178_de(void *, void *, s32);

extern s32 D_800CA7A0_de;




void func_8023371C_de(void *arg0, struct WeaponFireState *arg1) {
    f32 temp_f0;
    f32 temp_f20;

    temp_f20 = D_800C3078_de;
    temp_f0 = func_80274808_de(arg1->spinStep, temp_f20, D_800CA7A0_de);
    arg1->spinStep = temp_f0;
    if (temp_f20 <= temp_f0) {
        func_80214178_de(arg0, arg1, 2);
    }
}
