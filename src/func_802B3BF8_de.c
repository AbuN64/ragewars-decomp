#include "span_1000/code_802B369C.h"



extern func_802B8CC8_S1 *D_800D4070;

void *func_802B3BF8_de(void) {
    void *temp_v0;
    void *var_v1;

    temp_v0 = D_800D4070->unk2C;
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = temp_v0;
        D_800D4070->unk2C = *(void **)var_v1;
        *(void **)var_v1 = 0;
    }
    return var_v1;
}
