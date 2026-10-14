#include "span_1000/code_8027302C.h"
#include "types.h"


extern f32 D_800C4918_de[];



f32 func_80273F94_de(f32 arg0, f32 arg1) {
    f32 var_f3;

    func_80274020_de(&arg0);
    func_80274020_de(&arg1);
    if (arg0 > arg1) {
        var_f3 = arg1 + D_800C4914_de;
        if ((var_f3 - arg0) < (arg0 - arg1)) {
            arg1 = var_f3;
        }
    } else {
        var_f3 = arg1 - D_800C4918_de[0];
        if ((arg0 - var_f3) < (arg1 - arg0)) {
            arg1 = var_f3;
        }
    }
    return arg0 - arg1;
}
