#include "span_1000/code_802A0AC4.h"
#include "stdarg.h"
#include "TYPES.H"
s32 func_80414CCC_de(u8 *out, u8 *fmt0, u8 *ap);
extern u8 D_8014D0D0;

u8 *func_802A0C14_eu_x(u8 *arg0, ...) {
    va_list args;
    va_start(args, arg0);
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, args);
    va_end(args);
    return &D_8014D0D0;
}
