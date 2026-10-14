#include "span_1000/code_80275E44.h"
#include "types.h"

extern f32 func_8027631C_de(u16 *arg0, f32 arg1, u16 arg2);

f32 func_802761EC_de(u16 *arg0, f32 arg1) {
    f32 result = arg1;
    if (arg0 != 0) {
        result = func_8027631C_de(arg0, arg1, *arg0);
    }
    return result;
}
