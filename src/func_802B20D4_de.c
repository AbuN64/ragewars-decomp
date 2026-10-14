#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B243C.h"
#include "types.h"




extern f32 D_800CC740;

f32 func_802B20D4_de(ObjRecAt18V1 *arg0, s32 arg1, s32 arg2) {
    f64 v;
    f32 new_var;

    v = (f64)arg2;
    new_var = (f32)arg1;
    if (arg2 < 0) {
        v = v + D_800C74E8_de;
    }
    return (new_var * (f32)v) / ((f32)arg0->field18 * D_800CC740);
}
