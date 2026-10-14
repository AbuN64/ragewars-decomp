#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"








f32 func_802AE7BC_de(void **arg0, s32 arg1, s32 arg2) {
    f64 angle;
    f32 arg1f;
    f32 scaled;
    s32 temp_v0;
    f64 val;

    angle = (f64)arg2;
    arg1f = (f32)arg1;
    if (arg2 < 0) {
        angle += D_800C7310_de;
    }
    temp_v0 = ((ObjRecAt40V1 *)((*arg0)))->unk40;
    scaled = arg1f * (f32)angle;
    val = (f64)temp_v0;
    if (temp_v0 < 0) {
        val += D_800C7318_de;
    }
    return scaled / ((f32)val * D_800C7320_de);
}
