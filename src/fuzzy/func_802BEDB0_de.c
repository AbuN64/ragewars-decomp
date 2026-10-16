#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_802BE0D0.h"
#include "TYPES.H"
#include "MAIN/802BD1A8.H"
extern u16 D_800D5350[];
extern u16 D_800D5374[];
extern u16 D_8014AE00;

u16 func_802BEDB0_de(u16 *arg0, u16 arg1, s32 arg2, s32 arg3, void *arg4) {
    s16 *temp_a3_2;
    s16 temp_a0_3;
    s16 temp_v0_2;
    s16 var_t1;
    s32 temp_a0;
    s32 temp_t0;
    s32 temp_t7;
    s32 var_v0;
    u16 *temp_a3;
    u16 *temp_t4;
    u16 *temp_t6;
    u16 *temp_v0;
    u16 *temp_v0_3;
    u16 temp_a0_2;
    u16 temp_v1_2;
    u16 var_v0_2;
    u32 temp_t5;

    var_v0 = arg2 & 0xFFFF;
    if (D_800D54B8 == 0) {
        temp_v0 = ((u16 **) arg4)[0x14 / sizeof(u16 *)];
        ((u16 **) arg4)[0x14 / sizeof(u16 *)] = temp_v0 + 1;
        D_800D54B8 = 0x10;
        D_8014AE00 = *temp_v0;
        var_v0 = arg2 & 0xFFFF;
    }
    var_t1 = 0;
    if (var_v0 != 0) {
        temp_t7 = (s32) (arg3 << 0x10) >> 0x10;
        temp_t5 = arg1 & 0xFFFF;
        temp_t6 = &D_800D5374[temp_t5];
        temp_t4 = &D_800D5350[temp_t5];
        do {
            if ((u16) D_800D54B8 < temp_t5) {
                temp_t0 = arg1 - D_800D54B8;
                temp_a3 = arg0 + (s16) var_t1;
                temp_a0 = temp_t0 & 0xFFFF;
                *temp_a3 = (D_8014AE00 & D_800D5350[D_800D54B8 & 0xFFFF]) << temp_a0;
                temp_v0_3 = ((u16 **) arg4)[0x14 / sizeof(u16 *)];
                temp_v1_2 = *temp_v0_3;
                ((u16 **) arg4)[0x14 / sizeof(u16 *)] = temp_v0_3 + 1;
                D_8014AE00 = temp_v1_2;
                temp_a0_2 = *temp_a3 | (((s32) (temp_v1_2 & 0xFFFF) >> (0x10 - temp_a0)) & D_800D5350[temp_a0]);
                *temp_a3 = temp_a0_2;
                if (temp_t7 != 0) {
                    if (!((s16) temp_a0_2 & *temp_t6)) {
                        var_v0_2 = 0x10 - temp_t0;
                    } else {
                        *temp_a3 = temp_a0_2 | ~*temp_t4;
                        goto block_10;
                    }
                } else {
block_10:
                    var_v0_2 = 0x10 - temp_t0;
                }
            } else {
                temp_a0_3 = ((s32) D_8014AE00 >> (D_800D54B8 - temp_t5)) & *temp_t4;
                temp_a3_2 = (s16 *) arg0 + (s16) var_t1;
                *temp_a3_2 = temp_a0_3;
                if ((temp_t7 != 0) && (temp_a0_3 & *temp_t6)) {
                    *temp_a3_2 = temp_a0_3 | ~*temp_t4;
                }
                var_v0_2 = D_800D54B8 - arg1;
            }
            D_800D54B8 = var_v0_2;
            temp_v0_2 = var_t1 + 1;
            var_t1 = temp_v0_2;
        } while (temp_v0_2 < (arg2 & 0xFFFF));
    }
    return 1U;
}
