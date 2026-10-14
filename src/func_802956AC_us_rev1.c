#include "span_1000/code_80294C64.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"

extern s32 D_800D2AE0;
extern u8 D_8014AEB0;
extern ResidentSlot D_8014AEC8;
extern ResidentEntry D_8014AECC;
extern s32 D_8014AED8;

void func_802956AC_us_rev1(s32 arg0, s32 **arg1) {
    s32 var_v1;
    s32 var_v1_2;

    if ((D_800D2AE0 != 0) && (*arg1 != 0)) {
        if (D_8014AEC8.unk0 != 0) {
            return;
        }
        var_v1 = 0;
        if (D_8014AEB0 != 0) {
            var_v1 = (u32)D_800D2AE0 > 0U;
        }
        if (var_v1 != 0) {
            var_v1_2 = (D_8014AEC8.unk21A0 % 10) < 3;
        } else {
            var_v1_2 = 1;
        }
        if (arg0 == D_8014AECC.unk0) {
            if (var_v1_2 != 0) {
                *arg1 = &D_8014AECC.unk2010;
                return;
            }
            *arg1 = (s32 *)D_8014AED8;
        }
    }
}

void func_8029576C_us_rev1(void) {
    s32 temp_v1;

    if (D_auto_800D2AE8++ >= 3) {
        temp_v1 = D_8014AEB8.unk4 + 1;
        D_auto_800D2AE8 = 0;
        D_8014AEB8.unkC = 1;
        D_8014AEB8.unk4 = temp_v1;
        D_8014AEB8.unk4 = temp_v1 % D_8014AEB8.unk0;
    }
}
