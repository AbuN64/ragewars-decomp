#include "common/types_1dc8418c21db.h"
#include "shared/func_802B80B4_eu_closed.h"
#include "span_1000/code_802B7B80.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"
void func_8044799C_de(u8 cmd);
extern u8 D_8014D46C;

s32 func_80447818_de(OSMesgQueue *arg0, s8 *arg1) {
    EntryRecAt3 sp10;
    void *sp20;
    u8 sp24;
    EntryRecAt3 *var_v1;
    EntryRecAt3 *var_v1_2;
    s32 temp_s6;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s8 var_s2;

    var_s2 = 0;
    var_s0 = 3;
    func_802B9C14_de();
    do {
        func_8044799C_de(0U);
        __osSiRawStartDma(1, (s32) D_80154110);
        func_802BB2A0_de(arg0, &sp20, 1);
        temp_s6 = __osSiRawStartDma(0, (s32) D_80154110);
        func_802BB2A0_de(arg0, &sp20, 1);
        func_80447A38_de(&sp24, &sp10);
        var_a0 = 0;
        if (D_8014D46C != 0) {
            var_v1 = &sp10;
loop_3:
            if (var_v1->team & 4) {
                var_a0 += 1;
                var_v1 += 4;
                if (var_a0 < (s32) D_8014D46C) {
                    goto loop_3;
                }
            } else {
                var_s0 -= 1;
            }
        }
        if (var_a0 == D_8014D46C) {
            var_s0 = 0;
        }
    } while (var_s0 > 0);
    var_a0_2 = 0;
    if (D_8014D46C != 0) {
        var_v1_2 = &sp10;
        do {
            if ((var_v1_2->slot == 0) && (var_v1_2->team & 1)) {
                var_s2 |= 1 << var_a0_2;
            }
            var_a0_2 += 1;
            var_v1_2 += 4;
        } while (var_a0_2 < (s32) D_8014D46C);
    }
    func_802B9C80_de();
    *arg1 = var_s2;
    return temp_s6;
}
