#include "span_1000/code_8029EB74.h"
#include "types.h"








f32 func_8029DD78_de(f32 arg0) {
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f1;

    var_f1 = arg0;
    if (arg0 < 0.0f) {
        var_f1 = -arg0;
    }
    temp_f3 = (var_f1 - D_800C5BD8_de) / (var_f1 + D_800C5BD8_de);
    temp_f2 = temp_f3 * temp_f3;
    var_f0 = (((((((((((((((temp_f2 * D_800C5BDC_de) + D_800C5BE0_de) * temp_f2) - *(&D_800C5BE0_de + 1)) * temp_f2) + D_800C5BE8_de) * temp_f2) - *(&D_800C5BE8_de + 1)) * temp_f2) + D_800C5BF0_de) * temp_f2) - *(&D_800C5BF0_de + 1)) * temp_f2) + D_800C5BF8_de) * temp_f3) + *(&D_800C5BF8_de + 1);
    if (arg0 < 0.0f) {
        var_f0 = -var_f0;
    }
    return var_f0;
}
