#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_C76B0/data.h"
#include "types.h"
f32 func_802726BC_de(f32 *a, f32 *b);
s32 func_8020C078_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 *arg5, f32 arg6) {
    s32 sp20[64];
    s32 sp120[64];
    f32 sp220;
    f32 *temp_a1;
    f32 *temp_s4;
    f32 temp_fv0f;
    f32 var_fs0;
    s32 *temp_a0;
    s32 *temp_a2;
    s32 *temp_v1_2;
    s32 *temp_v1_3;
    s32 *var_a0_2;
    s32 *var_a2;
    s32 *var_s1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    void *temp_v1;
    void *temp_v1_4;

    var_fs0 = D_800C1D74_de;
    var_fp = -1;
    var_s0 = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v0 = *((s32 *) ((u8 *) (arg0) + 12));
    if (temp_v0 > 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_a2 = *((s32 **) ((u8 *) (arg0) + 8));
        var_a0 = 8;
loop_2:
        temp_v1 = (u8 *)temp_a2 + var_a0;
        var_s0 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if ((*((u16 *) ((u8 *) (temp_v1) + 0)) != arg2) || (*((u8 *) ((u8 *) (temp_v1) + 4)) != (arg3 & 0xFF))) {
            var_a0 += *temp_a2;
            if (var_s0 >= temp_v0) {
                goto block_5;
            }
            goto loop_2;
        }
        return arg2;
    }
block_5:
    var_t0 = 0;
    if (arg4 == 0) {
        return -1;
    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v1_2 = *((s32 **) ((u8 *) (arg0) + 0));
    var_t1 = 0;
    var_a0_2 = sp20;
    temp_s4 = (f32 *)((u8 *)temp_v1_2 + ((arg1 * *temp_v1_2) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if (*((s32 *) ((u8 *) (arg0) + 12)) > 0) {
        var_a2 = sp120;
        do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_v1_3 = *((s32 **) ((u8 *) (arg0) + 8));
            temp_v1_4 = (u8 *)temp_v1_3 + ((var_t0 * *temp_v1_3) + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if (*((u16 *) ((u8 *) (temp_v1_4) + 0)) == arg1) {
                var_t1 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *var_a0_2 = (s32) *((u16 *) ((u8 *) (temp_v1_4) + 2));
                *var_a2 = var_t0;
                var_a2 += 1;
                var_a0_2 += 1;
            }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if (*((u16 *) ((u8 *) (temp_v1_4) + 2)) == arg1) {
                var_t1 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *var_a0_2 = (s32) *((u16 *) ((u8 *) (temp_v1_4) + 0));
                *var_a2 = var_t0;
                var_a2 += 1;
                var_a0_2 += 1;
            }
            var_t0 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        } while (var_t0 < *((s32 *) ((u8 *) (arg0) + 12)));
    }
    var_s0_2 = 0;
    if (var_t1 > 0) {
        var_s1 = sp20;
        do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_a0 = *((s32 **) ((u8 *) (arg0) + 0));
            temp_a1 = (f32 *)((u8 *)temp_a0 + ((*var_s1 * *temp_a0) + 8));
            if (temp_a1 == temp_s4) {
                var_s0_2 += 1;
            } else {
                temp_fv0f = *arg5 + func_802726BC_de(temp_s4, temp_a1);
                sp220 = temp_fv0f;
                if (temp_fv0f < arg6) {
                    var_v0 = func_8020C078_de(arg0, arg2, *var_s1, arg3 & 0xFF, arg4 - 1, &sp220, arg6);
                } else {
                    var_v0 = -1;
                }
                var_s0_2 += 1;
                if ((var_v0 != -1) && (sp220 < var_fs0)) {
                    var_fs0 = sp220;
                    var_fp = var_v0;
                }
            }
            var_s1 += 1;
        } while (var_s0_2 < var_t1);
    }
    if (var_fs0 < arg6) {
        *arg5 = var_fs0;
    }
    return var_fp;
}
