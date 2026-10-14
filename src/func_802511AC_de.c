#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"

extern s32 D_80101140;
extern s32 D_80101134[];




extern s32 D_80101160;


extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);
extern s32 func_802BB420_de(void *, s32, s32);
extern s32 func_802BB2A0_de(s32, s32, s32);

void func_802511AC_de(void) {
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    u32 temp_a0;
    u32 temp_v0;

    var_s1 = 0;
    var_s0 = 0;
    do {
        if (D_80101134[var_s0] != 0) {
            if (D_801005A8 != var_s0) {
                var_s1 += 1;
                D_801005A0[var_s0] = 1;
                goto block_7;
            }
            D_80100598[var_s0] = 0;
            func_80254D44_de(0, var_s0);
            var_s0 += 1;
        } else {
block_7:
            var_s0 += 1;
        }
    } while (var_s0 < 2);
    if (var_s1 != 0) {
        temp_v0 = func_802BCF30_de();
        temp_v1 = D_8010515C - 1;
        D_8010515C = temp_v1;
        if (temp_v1 != 0) {
            func_802BCF50_de(temp_v0);
            func_802BB420_de(&D_80101140, 0, 1);
            var_s0_2 = 0;
        } else {
            func_802BCF50_de(temp_v0);
            var_s0_2 = 0;
        }
        if (var_s1 > 0) {
            do {
                func_802BB2A0_de((s32) &D_80101160, 0, 1);
                var_s0_2 += 1;
            } while (var_s0_2 < var_s1);
        }
        temp_a0 = func_802BCF30_de();
        temp_v1_2 = D_8010515C + 1;
        D_8010515C = temp_v1_2;
        if (temp_v1_2 != 1) {
            func_802BCF50_de(temp_a0);
            func_802BB2A0_de((s32) &D_80101140, 0, 1);
            return;
        }
        func_802BCF50_de(temp_a0);
    }
}
