#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_802453D4_de_closed.h"
#include "shared/func_8028C568_de_closed.h"
#include "span_1000/code_802A8A94.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "TYPES.H"
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x40, 0x44, 0x58, 0x5c], gap at: 0x48. */
void func_80238050_de(s32 arg0, void *arg1) {
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 temp_fs1f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    s32 temp_v1;
    void *temp_s1;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;
    void *var_s1;
    void *var_v1;

    temp_fs0 = D_800C33F8_de;
    if (arg1 != NULL) {
        func_802A84F8_de();
        func_802A8800_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_s1 = *((void **) ((u8 *) (arg1) + 3648));
        if (var_s1 != NULL) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            var_s0 = *((void **) ((u8 *) (var_s1) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            *((f32 *) ((u8 *) (var_s1) + 52)) = (f32) ((f32) D_800E28D4 * D_800C33FC_de);
            if (var_s0 != NULL) {
                do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_fv0 = *((f32 *) ((u8 *) (var_s1) + 52)) + temp_fs0;
                    var_s1 = var_s0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    *((f32 *) ((u8 *) (var_s0) + 52)) = temp_fv0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    var_s0 = *((void **) ((u8 *) (var_s0) + 4));
                } while (var_s0 != NULL);
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_s0_2 = *((void **) ((u8 *) (arg1) + 3652));
        if (var_s0_2 != NULL) {
            temp_fs0_2 = D_800C3400_de;
            do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                func_802A8F28_de(*((s32 *) ((u8 *) (var_s0_2) + 36)), (s32) *((f32 *) ((u8 *) (var_s0_2) + 48)), (s32) *((f32 *) ((u8 *) (var_s0_2) + 52)), *((s32 *) ((u8 *) (var_s0_2) + 24)), 1, 1, temp_fs0_2, temp_fs0_2);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                var_s0_2 = *((void **) ((u8 *) (var_s0_2) + 0));
            } while (var_s0_2 != NULL);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            var_s0_2 = *((void **) ((u8 *) (arg1) + 3652));
        }
        if (var_s0_2 != NULL) {
            temp_fs1f = D_800C3404_de;
            temp_fs1 = D_800C3408_de;
            temp_fs0f = D_800C340C_de;
            do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_v1 = *((s32 *) ((u8 *) (var_s0_2) + 20));
                temp_fs0_3 = D_800D2988 * D_800C3410_de;
                if (temp_v1 != 2) {
                    if (temp_v1 < 3) {
                        if (temp_v1 == 1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            *((s32 *) ((u8 *) (var_s0_2) + 24)) = 0;
                        } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            *((s32 *) ((u8 *) (var_s0_2) + 24)) = 0;
                            goto block_28;
                        }
                    } else if (temp_v1 != 3) {
                        if (temp_v1 != 4) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            *((s32 *) ((u8 *) (var_s0_2) + 24)) = 0;
block_28:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            *((s32 *) ((u8 *) (var_s0_2) + 20)) = 0;
                        } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_fv0_2 = func_802B6560_de(*((f32 *) ((u8 *) (var_s0_2) + 40)) * temp_fs1f) * temp_fs1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_fv0f = *((f32 *) ((u8 *) (var_s0_2) + 40)) + temp_fs0_3;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            *((f32 *) ((u8 *) (var_s0_2) + 40)) = temp_fv0f;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            *((s32 *) ((u8 *) (var_s0_2) + 24)) = (s32) temp_fv0_2;
                            if (temp_fs0f < temp_fv0f) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                var_v1 = *((void **) ((u8 *) (arg1) + 3648));
                                if (var_v1 != NULL) {
                                    do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                        if (*((s32 *) ((u8 *) (var_v1) + 20)) == 1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                            *((s32 *) ((u8 *) (var_v1) + 20)) = 2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                            *((s32 *) ((u8 *) (var_v1) + 40)) = 0;
                                        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                        var_v1 = *((void **) ((u8 *) (var_v1) + 4));
                                    } while (var_v1 != NULL);
                                }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                *((s32 *) ((u8 *) (var_s0_2) + 20)) = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                                *((f32 *) ((u8 *) (var_s0_2) + 40)) = 0.0f;
                            }
                        }
                    } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        *((s32 *) ((u8 *) (var_s0_2) + 24)) = 0xFF;
                    }
                } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_fv0_3 = func_802B7130_de(*((f32 *) ((u8 *) (var_s0_2) + 40)) * temp_fs1f) * temp_fs1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_fv0f_2 = *((f32 *) ((u8 *) (var_s0_2) + 40)) + temp_fs0_3;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    *((f32 *) ((u8 *) (var_s0_2) + 40)) = temp_fv0f_2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    *((s32 *) ((u8 *) (var_s0_2) + 24)) = (s32) temp_fv0_3;
                    if (temp_fs0f < temp_fv0f_2) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        *((s32 *) ((u8 *) (var_s0_2) + 20)) = 3;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        *((f32 *) ((u8 *) (var_s0_2) + 40)) = 0.0f;
                    }
                }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                var_s0_2 = *((void **) ((u8 *) (var_s0_2) + 0));
            } while (var_s0_2 != NULL);
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_s0_3 = *((void **) ((u8 *) (arg1) + 3652));
        if (var_s0_3 != NULL) {
            do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_s1 = *((void **) ((u8 *) (var_s0_3) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((s32 *) ((u8 *) (var_s0_3) + 20)) == 0) {
                    func_80255ED8_de(arg1 + 0xE40, (s32) var_s0_3);
                    func_80255CB8_de(arg0 + 0xF24, (s32) var_s0_3);
                }
                var_s0_3 = temp_s1;
            } while (var_s0_3 != NULL);
        }
    }
}
