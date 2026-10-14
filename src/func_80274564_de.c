#include "span_C76B0/data.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8027451C.h"
#include "types.h"
#include "shared/func_802745D0_de_closed.h"

/** LCG PRNG step scaled into [0, arg0 * D_800C9A38) as a float. */
f32 func_80274564_de(f32 arg0) {
    f64 var_f1;
    s32 temp_v0;
    u32 temp_v1;

    temp_v1 = (D_80111D24 * 0xA84A5B53) + 0x58348C2D;
    temp_v0 = (s32)((temp_v1 >> 0x10) & 0x7FFF);
    var_f1 = (f64)temp_v0;
    D_80111D24 = temp_v1;
    if (temp_v0 < 0) {
        var_f1 = var_f1 + D_800C4940_de;
    }
    return (f32)var_f1 * arg0 * D_800C9A38;
}

f32 func_802745D0_de(f32 arg0) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_f4;
    s32 var_v1;

    var_v1 = 1;
    if (arg0 < 0.0f) {
        temp_f1 = arg0 * D_800C494C_de;
    } else {
        temp_f1 = arg0 * D_800C4950_de;
        var_v1 = 0;
    }
    temp_f4 = (s32) temp_f1;
    if ((f32) temp_f4 < D_800C4954_de) {
        temp_f2_2 = D_800CC3DC[temp_f4];
        temp_f2 = temp_f2_2 + ((temp_f1 - (f32) temp_f4) * (D_800CC3E0[temp_f4] - temp_f2_2));
        if (var_v1 != 0) {
            return D_800C4958_de - temp_f2;
        }
        return temp_f2;
    }
    if (var_v1 != 0) {
        temp_f1 = D_800CD3D8;
        return D_800C495C_de - temp_f1;
    }
    return D_800CD3D8;
}

extern f32 D_800C4960_de;
extern f32 D_800D2988;

f32 func_802746A0_de(f32 arg0, f32 arg1, f32 arg2) {
    if (arg1 < 0.0f) {
        if (arg0 <= -arg2) {
            return arg0;
        }
    }
    if (0.0f < arg1) {
        if (arg2 <= arg0) {
            return arg0;
        }
    }
    if ((arg0 < 0.0f && 0.0f < arg1) ||
        (0.0f < arg0 && arg1 < 0.0f)) {
        arg1 *= D_800C4960_de;
    }
    arg0 += arg1 * D_800D2988;
    if (arg1 < 0.0f) {
        if (arg0 < -arg2) {
            arg0 = -arg2;
        }
    } else if (arg2 < arg0) {
        arg0 = arg2;
    }
    return arg0;
}
