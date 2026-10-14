#include "span_1000/code_8022F3E8.h"
#include "types.h"

extern s32 func_80265650_de(s32, s32);

s32 func_8022F55C_de(s32 arg0, s32 arg1) {
    s32 var_a0;
    s32 var_a1 = arg1;

    switch (var_a1) {
    case 16:
        var_a0 = arg0 + 0x78;
        var_a1 = 0;
        break;
    case 17:
        var_a0 = arg0 + 0x78;
        var_a1 = 1;
        break;
    default:
        var_a0 = arg0 + 0x7B;
        break;
    }
    func_80265650_de(var_a0, var_a1);
}
