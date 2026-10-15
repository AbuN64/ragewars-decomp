#include "span_1000/code_802A0AC4.h"
#include "types.h"
s32 func_80414CCC_de(u8 *out, u8 *fmt0, u8 *ap);
extern u8 D_8014D0D0;

u8 *func_802A0C14_eu_x(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_800CD918 = func_80414CCC_de(&D_8014D0D0, arg0, &arg1);
    return &D_8014D0D0;
}
