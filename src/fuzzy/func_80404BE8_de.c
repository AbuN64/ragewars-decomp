#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_80404D84_de_closed.h"
#include "stddef.h"
#include "TYPES.H"
s32 func_802A037C_de(const void *arg0, const void *arg1);
extern u8 D_800DE80C[];

s32 func_80404BE8_de(void *arg0, s32 arg1, s32 *arg2) {
    u8 sp10[16];
    u8 *sp20;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a3;
    s32 var_s0;
    s32 var_s1;
    s8 *var_v0;
    u8 *temp_v1_2;
    u8 *var_a1;
    u8 *var_a2;
    u8 temp_v0;
    u8 temp_v1;

    var_s0 = 0;
    var_s1 = 4;
loop_1:
    if (D_801534F0[arg1] == 3) {
        sp20 = (u8 *)D_800E2854 + (arg1 * 0x204) + var_s1 + 0xE;
    }
    var_a0 = 0xF;
    var_v0 = (s8 *)&sp10[15];
    do {
        *var_v0 = 0;
        var_a0 -= 1;
        var_v0 -= 1;
    } while (var_a0 >= 0);
    var_a3 = 0;
    var_a0_2 = 0;
    var_a1 = sp10;
    var_a2 = sp20;
    do {
        temp_v1 = *var_a2;
        if (temp_v1 >= 0x42U) {
            *var_a1 = 0x7E;
        } else if ((temp_v1 == 0) && (var_a3 == 0)) {
            *var_a1 = 0x20;
        } else {
            var_a3 = 1;
            *var_a1 = D_800DE80C[*var_a2];
        }
        var_a1 += 1;
        var_a0_2 += 1;
        var_a2 += 1;
    } while (var_a0_2 < 0x10);
    var_a0_3 = 0xF;
loop_15:
    temp_v1_2 = &(sp10)[var_a0_3];
    temp_v0 = *temp_v1_2;
    var_a0_3 -= 1;
    if ((temp_v0 == 0x20) || (temp_v0 == 0)) {
        *temp_v1_2 = 0;
        if (var_a0_3 >= 0) {
            goto loop_15;
        }
    }
    sp10[15] = 0;
    if (func_802A037C_de(sp10, arg0) != 0) {
        var_s0 += 1;
        var_s1 += 0x20;
        if (var_s0 >= 0x10) {
            return 0;
        }
        goto loop_1;
    }
    if (arg2 != NULL) {
        *arg2 = var_s0;
    }
    return 1;
}
