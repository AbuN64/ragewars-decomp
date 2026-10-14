#include "span_1000/code_8027302C.h"
#include "types.h"

extern f32 D_800C99F8;



f32 func_80273EE4_de(f32 fraction, f32 first, f32 second) {
    f32 var_f3;
    f32 result;

    func_80274020_de(&first);
    func_80274020_de(&second);
    if (first > second) {
        var_f3 = second + *(&D_800C99F8 + 1);
        if ((var_f3 - first) < (first - second)) {
            second = var_f3;
        }
    } else {
        var_f3 = second - D_800C4910_de;
        if ((first - var_f3) < (second - first)) {
            second = var_f3;
        }
    }
    result = first + (fraction * (second - first));
    func_80274020_de(&result);
    return result;
}
