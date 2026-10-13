#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80294C64.h"
#include "types.h"

extern s32 D_800D2AE0;
extern u8 D_8014AEB0;
extern char D_8014AEC8[];

extern Selection_func_802955EC_us_rev1 D_8014AECC;
extern s32 *D_8014AED4;




void func_802955EC_us_rev1(s32 arg0, s32 **arg1) {
    s32 enabled;
    s32 choose;

    if ((D_800D2AE0 != 0) && (*arg1 != 0) && (*(s32 *)&D_8014AEC8[0] == 0)) {
        enabled = 0;
        if (D_8014AEB0 != 0) {
            enabled = (u32)D_800D2AE0 > 0U;
        }
        if (enabled != 0) {
            choose = (*(s32 *)&D_8014AEC8[0x21A0] % 10) < 3;
        } else {
            choose = 1;
        }
        if (arg0 == D_8014AECC.value) {
            if (choose != 0) {
                *arg1 = &D_8014AECC.alternative;
                return;
            }
            *arg1 = D_8014AED4;
        }
    }
}
