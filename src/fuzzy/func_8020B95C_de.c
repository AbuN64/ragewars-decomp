#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "stddef.h"
#include "types.h"
f32 func_802726BC_de(f32 *a, f32 *b);
s32 func_8020B95C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    s32 sp10;
    f32 *temp_s0_2;
    f32 *var_s7;
    f32 temp_fs0;
    s32 *temp_s0;
    s32 *temp_v1;
    s32 *temp_v1_2;
    s32 *var_a3;
    s32 *var_s1;
    s32 *var_s6;
    s32 temp_v0;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s2;
    s32 var_s4;
    s32 var_s5;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_a0;
    u8 temp_a0_2;
    void *temp_v1_3;

    if (arg2 != -1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_v1 = *((s32 **) ((u8 *) (arg0) + 0));
        var_s7 = (f32 *)((u8 *)temp_v1 + ((arg2 * *temp_v1) + 8));
    } else {
        var_s7 = NULL;
    }
    var_t0 = 0;
    var_s4 = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if (*((s32 *) ((u8 *) (arg0) + 12)) > 0) {
        var_a3 = arg3;
        do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_v1_2 = *((s32 **) ((u8 *) (arg0) + 8));
            temp_v1_3 = (u8 *)temp_v1_2 + ((var_t0 * *temp_v1_2) + 8);
            if (arg4 != 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((u16 *) ((u8 *) (temp_v1_3) + 2)) == arg1) {
                    var_s4 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    *var_a3 = (s32) *((u16 *) ((u8 *) (temp_v1_3) + 0));
                    var_a3 += 1;
                }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((u16 *) ((u8 *) (temp_v1_3) + 0)) == arg1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_a0 = *((u8 *) ((u8 *) (temp_v1_3) + 4));
                    if (temp_a0 != 4) {
                        if ((s32) temp_a0 < 5) {
                            var_v0 = 0;
                            if (temp_a0 != 1) {

                            } else {
                                goto block_14;
                            }
                        } else {
                            var_v0 = 0;
                            if (temp_a0 == 7) {
                                goto block_14;
                            }
                        }
                    } else {
block_14:
                        var_v0 = 1;
                    }
                    if (var_v0 != 0) {
                        var_s4 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        *var_a3 = (s32) *((u16 *) ((u8 *) (temp_v1_3) + 2));
                        var_a3 += 1;
                    }
                }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if ((arg2 != -1) && (*((u16 *) ((u8 *) (temp_v1_3) + 0)) == arg1) && (*((u16 *) ((u8 *) (temp_v1_3) + 2)) == arg2) && (var_s7 != NULL) && (*((u16 *) ((u8 *) (var_s7) + 12)) & 2)) {
                    *var_a3 = arg2;
                    var_a3 += 1;
                    var_s4 += 1;
                }
            } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if ((*((u16 *) ((u8 *) (temp_v1_3) + 0)) == arg1) && (*((u8 *) ((u8 *) (temp_v1_3) + 4)) != 6)) {
                    var_s4 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    *var_a3 = (s32) *((u16 *) ((u8 *) (temp_v1_3) + 2));
                    var_a3 += 1;
                }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((u16 *) ((u8 *) (temp_v1_3) + 2)) == arg1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_a0_2 = *((u8 *) ((u8 *) (temp_v1_3) + 4));
                    if (temp_a0_2 != 4) {
                        if ((s32) temp_a0_2 < 5) {
                            var_v0_2 = 0;
                            if (temp_a0_2 != 1) {

                            } else {
                                goto block_32;
                            }
                        } else {
                            var_v0_2 = 0;
                            if (temp_a0_2 == 7) {
                                goto block_32;
                            }
                        }
                    } else {
block_32:
                        var_v0_2 = 1;
                    }
                    if (var_v0_2 != 0) {
                        var_s4 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        *var_a3 = (s32) *((u16 *) ((u8 *) (temp_v1_3) + 0));
                        var_a3 += 1;
                    }
                }
            }
            var_t0 += 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        } while (var_t0 < *((s32 *) ((u8 *) (arg0) + 12)));
    }
    if (arg2 != -1) {
        temp_v0 = var_s4 - 1;
        if (var_s7 != NULL) {
            var_s5 = 0;
            if (temp_v0 > 0) {
                var_s6 = arg3;
                sp10 = temp_v0;
                do {
                    var_s2 = var_s5 + 1;
                    if (var_s2 < var_s4) {
                        var_s1 = arg3 + var_s2;
                        do {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                            temp_s0 = *((s32 **) ((u8 *) (arg0) + 0));
                            temp_v1_4 = *temp_s0;
                            temp_s0_2 = (f32 *)((u8 *)temp_s0 + ((*var_s1 * temp_v1_4) + 8));
                            temp_fs0 = func_802726BC_de(var_s7, (f32 *)((u8 *)temp_s0 + ((*var_s6 * temp_v1_4) + 8)));
                            var_s2 += 1;
                            if (func_802726BC_de(var_s7, temp_s0_2) < temp_fs0) {
                                temp_v1_5 = *var_s6;
                                *var_s6 = *var_s1;
                                *var_s1 = temp_v1_5;
                            }
                            var_s1 += 1;
                        } while (var_s2 < var_s4);
                    }
                    var_s5 += 1;
                    var_s6 += 1;
                } while (var_s5 < sp10);
            }
        }
    }
    return var_s4;
}
