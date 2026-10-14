#include "span_1000/code_802646F4.h"
#include "types.h"

extern s32 D_800CBC18;
extern void func_80264248_de(void *arg0);
extern s32 D_8010F328;
extern s32 D_8010BC18[4];
extern u8 D_8010B3F4;
extern s32 D_8010EC90;
extern void func_80285D30_de(s32 *);

void func_8026495C_de(void) {
    u8 *var_s0;
    s32 var_s1;
    s32 var_v1;
    s32 var_a0;
    s32 temp_v0;

    if (D_800CBC18 != 0) {
        var_s1 = 0;
        var_s0 = &D_8010F328;
        do {
            func_80264248_de(var_s0);
            var_s1 += 1;
            var_s0 += 0x224;
        } while (var_s1 < 4);
        var_v1 = 0;
        var_a0 = 0;
        do {
            temp_v0 = D_8010BC18[var_v1];
            var_v1 += 1;
            *(s32 *)(&D_8010B3F4 + var_a0) = temp_v0;
            var_a0 += 0x224;
        } while (var_v1 < 4);
        func_80285D30_de(&D_8010EC90);
        D_800CBC18 = 0;
    }
}
