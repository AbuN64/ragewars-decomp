#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);
extern void func_8028FDF8_de(s32 arg0, s32 arg1);




s32 func_8028DEEC_de(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(((Field_void_80 *)(arg0))->value, 0), arg1), 2);
    func_8028FDB4_de(temp_v0, 0);
    func_8028FDF8_de((s32)temp_v0, 1);
    temp_a0 = (u8 *)func_8028FDB4_de(temp_v0, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}
