#include "include_asm.h"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ARG.H"
#include "TYPES.H"
#include "COMMON/OBJECTSTATE96.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
void func_8044799C_de(u8 cmd);

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
        __osSiRawStartDma(1, (u8 *)&D_80154110);
        func_802BB2A0_de(arg0, &sp20, 1);
        temp_s6 = __osSiRawStartDma(0, (u8 *)&D_80154110);
        func_802BB2A0_de(arg0, &sp20, 1);
        func_80447A38_de(&sp24, &sp10);
        var_a0 = 0;
        if (D_8014D46C[0] != 0) {
            var_v1 = &sp10;
loop_3:
            if (var_v1->team & 4) {
                var_a0 += 1;
                var_v1 += 4;
                if (var_a0 < (s32) D_8014D46C[0]) {
                    goto loop_3;
                }
            } else {
                var_s0 -= 1;
            }
        }
        if (var_a0 == D_8014D46C[0]) {
            var_s0 = 0;
        }
    } while (var_s0 > 0);
    var_a0_2 = 0;
    if (D_8014D46C[0] != 0) {
        var_v1_2 = &sp10;
        do {
            if ((var_v1_2->slot == 0) && (var_v1_2->team & 1)) {
                var_s2 |= 1 << var_a0_2;
            }
            var_a0_2 += 1;
            var_v1_2 += 4;
        } while (var_a0_2 < (s32) D_8014D46C[0]);
    }
    func_802B9C80_de();
    *arg1 = var_s2;
    return temp_s6;
}
#else
INCLUDE_ASM("ovl_80400000", func_80447818_de);
#endif
#endif
