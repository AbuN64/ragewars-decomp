#include "span_1000/code_802646F4.h"
#include "types.h"

extern void func_80264248_de(void *arg0);
extern s32 D_8010F328;

void func_8026480C_de(void) {
    u8 *var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = (u8 *)&D_8010F328;
    do {
        func_80264248_de(var_s0);
        var_s1 += 1;
        var_s0 += 0x224;
    } while (var_s1 < 4);
}
