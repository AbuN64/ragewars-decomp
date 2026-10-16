#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8025B920_de_closed.h"
#include "span_1000/code_802B2EF8.h"
#include "TYPES.H"
s16 func_8025B034_de(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ObjRecAt40V2 *temp_s1;
    s16 temp_t2;
    s16 temp_v1;
    s16 var_a0;
    s16 var_a3;
    s16 var_t0;
    s16 var_v0;
    s32 var_v0_2;
    s8 *var_a2;
    void *temp_a0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_t1;
    void *temp_t3;
    void *temp_v1_2;
    void *var_a1;

    var_a3 = (s16) arg3;
    var_t0 = -1;
    var_a2 = arg0 + 4;
    var_a0 = 0;
    temp_t2 = var_a3;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_t1 = *((void **) ((u8 *) (arg0) + 0));
    temp_t3 = temp_t1 + 0x7C;
    var_a1 = temp_t3;
loop_1:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if (*((s16 *) ((u8 *) (var_a1) + 96)) != -1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_v1 = *((s16 *) ((u8 *) (var_a2) + 56));
        if ((temp_v1 < temp_t2) && (var_a3 >= temp_v1) && (temp_v1 != 0x64)) {
            var_a3 = temp_v1;
            var_t0 = var_a0;
        }
        var_a2 += 0xCC;
        var_a0 += 1;
        var_a1 += 2;
        if (var_a0 >= 0x10) {
            if (var_t0 != -1) {
                if (*((s16 *) ((u8 *) ((temp_t3 + (var_t0 * 2))) + 96)) == -1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_v1_2 = *((void **) ((u8 *) (temp_t1) + 320));
                    var_v0_2 = var_t0 << 0x10;
                    if (temp_v1_2 != (temp_t1 + 0x13C)) {
                        var_v0_2 = var_t0 << 0x10;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        if ((s16) arg3 < *((s16 *) ((u8 *) (temp_v1_2) + 64))) {
                            goto block_11;
                        }
                    }
                    return (s16) (var_v0_2 >> 0x10);
                }
                temp_s0 = (var_t0 * 0xCC) + arg0;
                temp_s0_2 = temp_s0 + 4;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_a0 = *((void **) ((u8 *) (temp_s0_2) + 176));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s32 *) ((u8 *) (temp_s0_2) + 172)) = 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s32 *) ((u8 *) (temp_s0_2) + 80)) = 0;
                temp_s1 = temp_a0 + 0x84;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((s32 *) ((u8 *) (temp_s0_2) + 16)) != *((s32 *) ((u8 *) (temp_a0) + 260))) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    func_802B2F00_de(temp_s1, *((s16 *) ((u8 *) ((temp_a0 + (*((s32 *) ((u8 *) (temp_s0) + 4)) * 2))) + 220)));
                    if (func_802B2620_de(temp_s1) != 0) {
                        alSndpStop(temp_s1);
                    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    *((s32 *) ((u8 *) (temp_s0_2) + 4)) = -1;
                }
                var_v0 = -1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if (*((s32 *) ((u8 *) (arg0) + 3280)) == -1) {
                    var_v0 = 0x10;
                }
                return var_v0;
            }
block_11:
            return -1;
        }
        goto loop_1;
    }
    return var_a0;
}
