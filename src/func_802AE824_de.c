#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"
/* Scales the float argument by the unsigned rate at offset 0x40 of the object behind arg0 times a constant, divides by the unsigned third argument, and returns the quotient converted to unsigned. Adapted from func_802AE7BC_de with the second argument changed to a float, the product and quotient reordered so the rate term multiplies and the third argument divides, and the result converted to u32 with the explicit 2^31 split. */








u32 func_802AE824_de(void **arg0, f32 arg1, s32 arg2) {
    f64 val;
    f64 div;
    f32 arg1f;
    f32 scaled;
    f32 value;
    s32 temp_v0;
    s32 converted;

    temp_v0 = ((ObjRecAt40V1 *)((*arg0)))->unk40;
    arg1f = arg1;
    val = (f64)temp_v0;
    if (temp_v0 < 0) {
        val += D_800C7328_de;
    }
    scaled = arg1f * ((f32)val * D_800C7330_de);
    div = (f64)arg2;
    if (arg2 < 0) {
        div += D_800C7338_de;
    }
    value = scaled / (f32)div;
    if (!(D_800C7340_de <= value)) {
        converted = (s32)value;
    } else {
        converted = (s32)(value - D_800C7340_de);
        converted |= 0x80000000;
    }
    return converted;
}
