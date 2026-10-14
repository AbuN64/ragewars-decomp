#include "span_1000/code_802A0AC4.h"
#include "types.h"

s32 func_80414CCC_de(s32 *, s32, s32);

extern s32 D_8014D0D0;

s32 func_802A0B20_de(s32 arg0, ...) {
    char *args;

    args = __builtin_next_arg(arg0);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, (s32) args);
    if (D_800CD91C != 0) {
        ((s32 (*)(s32 *)) D_800CD91C)(&D_8014D0D0);
    }
    return D_800CD918;
}
