#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"

void func_8029AA34_de(void) {
    s32 idx;
    s32 var_a0;
    s32 var_a1;
    Callback *context;

    var_a1 = 0;
    do {
        var_a0 = 0;
        do {
            idx = var_a0 + var_a1 * 4;
            var_a0 += 1;
            context = D_8014D0B0;
            context->flags[idx] = 0;
        } while (var_a0 < 4);
        var_a1 += 1;
    } while (var_a1 < 0x10);
}
