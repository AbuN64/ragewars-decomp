#include "span_16E000/code_804251F4.h"
#include "types.h"
#include "stddef.h"
/* Counts the enabled entries in a fifty-entry player table. */
extern unsigned char D_800FEB4A[];
s32 func_80265650_de(void *, s32); /* extern */
s32 func_80426004_de(s32 arg0) {
    s32 temp_s2;
    s32 var_s0;
    s32 var_s1;
    void *var_a0;
    var_s1 = 0;
    var_s0 = 0;
    temp_s2 = arg0 * 0x190;
    var_a0 = temp_s2 + D_800FEB4A;
    do {
        if (func_80265650_de(temp_s2 + D_800FEB4A, var_s0) == 1) {
            var_s1 += 1;
        }
        var_s0 += 1;
        var_a0 = temp_s2 + D_800FEB4A;
    } while (var_s0 < 0x32);
    return var_s1;
}
