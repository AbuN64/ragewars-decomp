#include "span_1000/code_8029BBA0.h"
#include "types.h"


extern f32 func_802B72B0_de(void);

f32 func_8029D8E8_de(f32 arg0) {
    f32 var_f0;

    if (arg0 <= 0.0f) {
        var_f0 = 0.0f;
    } else {
        var_f0 = func_802B72B0_de();
    }
    return D_800C5B0C_de / var_f0;
}
