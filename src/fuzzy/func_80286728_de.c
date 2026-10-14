#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8044DA54_de_closed.h"
#include "stddef.h"
#include "types.h"
f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);
f32 func_8027525C_de(Node75_func_802750B0_de *node, f32 x, f32 z);
extern s32 D_800CD764_de;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x40, 0x44, 0x48, 0x4c], gap at: 0x38. */
s32 func_80286728_de(void *arg0, void *arg1) {
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fs0f;
    f32 var_fv0;
    s32 temp_fp;
    s32 temp_s7;
    s32 var_s4;
    s32 var_s6;
    s8 *temp_v0;
    u32 var_s2;
    void *var_s0;
    void *var_s5;
    void *var_s1;

    if (D_800CD764_de == 0) {
        return 0;
    }
    var_s4 = 0;
    var_s6 = 0;
    var_fs0f = 0.0f;
    var_s5 = NULL;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fp = func_8028FDB4_de(*((s32 **) ((u8 *) (arg0) + 108)), 2) + 8;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v0 = func_8028FDB4_de(*((s32 **) ((u8 *) (arg0) + 108)), 3);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_s7 = *((s32 *) ((u8 *) (temp_v0) + 4));
    if (temp_s7 > 0) {
        var_s1 = temp_v0 + 8;
loop_4:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0f = *((f32 *) ((u8 *) (arg1) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if ((*((f32 *) ((u8 *) (var_s1) + 0)) <= temp_fv0f) && (temp_fv0f <= *((f32 *) ((u8 *) (var_s1) + 8)))) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_fv0f_2 = *((f32 *) ((u8 *) (arg1) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if ((*((f32 *) ((u8 *) (var_s1) + 4)) <= temp_fv0f_2) && (temp_fv0f_2 <= *((f32 *) ((u8 *) (var_s1) + 12)))) {
                var_s2 = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((u32 *) ((u8 *) (var_s1) + 16)) != 0) {
                    var_s0 = (var_s4 << 5) + temp_fp;
loop_10:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    if (func_80275B10_de(var_s0, *((f32 *) ((u8 *) (arg1) + 0)), *((f32 *) ((u8 *) (arg1) + 8))) != 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        temp_fs0 = func_80275DD4_de(var_s0, *((f32 *) ((u8 *) (arg1) + 0)), *((f32 *) ((u8 *) (arg1) + 8)));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        if (*((u16 *) ((u8 *) (var_s0) + 2)) & 0x40) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_fv0 = func_8027525C_de(var_s0, *((f32 *) ((u8 *) (arg1) + 0)), *((f32 *) ((u8 *) (arg1) + 8)));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_fv0f_3 = *((f32 *) ((u8 *) (arg1) + 4));
                            if ((temp_fs0 <= temp_fv0f_3) && (temp_fv0f_3 <= temp_fv0)) {
                                return (s32) var_s0;
                            }
                            goto block_20;
                        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        var_fv0 = *((f32 *) ((u8 *) (arg1) + 4)) - temp_fs0;
                        if (var_fv0 < 0.0f) {
                            var_fv0 = -var_fv0;
                        }
                        if ((var_s5 == NULL) || (var_fv0 < var_fs0f)) {
                            var_s5 = var_s0;
                            var_fs0f = var_fv0;
                        }
                        goto block_20;
                    }
block_20:
                    var_s0 += 0x20;
                    var_s2 += 1;
                    var_s4 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    if (var_s2 >= (u32) *((u32 *) ((u8 *) (var_s1) + 16))) {
                        var_s1 += 0x14;
                        goto block_24;
                    }
                    goto loop_10;
                }
                goto block_23;
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_s4 += *((u32 *) ((u8 *) (var_s1) + 16));
block_23:
        var_s1 += 0x14;
block_24:
        var_s6 += 1;
        if (var_s6 >= temp_s7) {
            goto block_25;
        }
        goto loop_4;
    }
block_25:
    return (s32) var_s5;
}
