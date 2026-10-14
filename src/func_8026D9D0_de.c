#include "span_1000/code_8026AC38.h"
#include "types.h"



extern void func_80253BBC_de(s32 arg0, s32 arg1);
extern void func_80253754_de(s32 arg0, s32 arg1);
extern s32 D_80111310;
extern s32 D_80111318[];

void func_8026D9D0_de(void) {
    s32 temp_s0;
    s32 var_s1;

    func_8026BC60_de();
    var_s1 = 0;
    func_8026C020_de();
    if (D_80111310 > 0) {
        do {
            temp_s0 = D_80111318[var_s1];
            func_80253BBC_de(0, temp_s0);
            func_80253754_de(0, temp_s0);
            var_s1 += 1;
        } while (var_s1 < D_80111310);
    }
}
