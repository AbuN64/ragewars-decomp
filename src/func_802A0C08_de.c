#include "span_1000/code_802A0AC4.h"
#include "types.h"


extern s32 func_80414CCC_de(void *arg0, s32 arg1, s32 arg2);

/** Pass the variadic tail address to the formatter and retain its result. */
s32 func_802A0C08_de(void *arg0, s32 arg1, ...) {
    s32 result;
    char *args;

    args = __builtin_next_arg(arg1);
    result = func_80414CCC_de(arg0, arg1, (s32)args);
    D_800CD918 = result;
    return result;
}
