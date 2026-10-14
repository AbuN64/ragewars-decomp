#include "span_16E000/code_80429C10.h"
#include "types.h"
#include "stddef.h"
/* Hides each primary and optional secondary selection widget. */
void func_8040E8D8_de(s32, s32); /* extern */
s32 func_8040EC30_de(s32, u16); /* extern */
extern s32 *D_800E4F60;
extern char D_800E0F16;
extern char D_800E0F18;
extern char D_800E0F1A;
void func_8042B0A4_de(void) {
    s32 var_s0;
    s32 var_s1;
    var_s1 = 0;
    do {
        var_s0 = var_s1 * 0x10;
        func_8040E8D8_de(func_8040EC30_de(*D_800E4F60, *(u16 *)(&D_800E0F16 + var_s0)), 0);
        if (*(s32 *)(&D_800E0F18 + var_s0) != -1) {
            func_8040E8D8_de(func_8040EC30_de(*D_800E4F60, *(u16 *)(&D_800E0F1A + var_s0)), 0);
        }
            var_s1 += 1;
    } while (var_s1 < 0x28);
}
