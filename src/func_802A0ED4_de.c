#include "span_1000/code_802A0AC4.h"
#include "types.h"

extern s32 (*D_800CD92C_de)(s32, s32, s32);

s32 func_802A0ED4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 lo;
    s32 result;

    lo = arg1 * arg2;
    if (lo == 0) {
        return 0;
    }
    result = D_800CD92C_de(arg3, arg0, lo);
    return result / arg1;
}
