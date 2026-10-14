#include "span_1000/code_802A0AC4.h"
#include "types.h"

s32 func_80414CCC_de(s32 *, s32, s32);

extern s32 D_8014D0D0;

s32 func_802A0B8C_de(s32 arg0, s32 arg1, s32 arg2, ...) {
    char *args;

    args = __builtin_next_arg(arg2);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg2, (s32) args);
    ((s32 (*)(s32 *, s32, s32)) D_800CD920_de)(&D_8014D0D0, arg0, arg1);
    return D_800CD918;
}
