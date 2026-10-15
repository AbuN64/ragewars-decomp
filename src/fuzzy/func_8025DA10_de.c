#include "common/types_1dc8418c21db.h"
#include "packed_float.h"
#include "resident_event_handler.h"
#include "shared/func_8044DA54_de_closed.h"
#include "stddef.h"
#include "types.h"
s32 func_802654E8_de(void *arg0, s32 arg1, s32 arg2);
extern f32 D_800C4008_de;

s32 func_8025DA10_de(void *arg0, s32 arg1) {
    f32 temp_fv0;
    s32 temp_s0;
    s32 temp_v0_2;
    s8 *temp_s0_2;
    s8 *temp_v0_3;
    s8 *var_v0;
    void *temp_v0;

    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v0 = *((void **) ((u8 *) (arg0) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v0_2 = func_802654E8_de(*((void **) ((u8 *) (temp_v0) + 11104)), *((s32 *) ((u8 *) (temp_v0) + 11108)), arg1);
    temp_s0 = temp_v0_2 * 2;
    if (temp_v0_2 != -1) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_s0_2 = func_8028FDB4_de(*((s32 **) ((u8 *) (*((void **) ((u8 *) (arg0) + 0))) + 11088)), temp_s0 | 1);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_v0_3 = func_8028FDB4_de(*((s32 **) ((u8 *) (*((void **) ((u8 *) (arg0) + 0))) + 11088)), temp_s0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((s32 *) ((u8 *) (arg0) + 36)) = (s32) *((s32 *) ((u8 *) (temp_v0_3) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0 = func_802B2350((s32) *((u16 *) ((u8 *) (temp_v0_3) + 4)));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 48)) = temp_fv0;
        if (temp_fv0 <= 0.0f) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            *((f32 *) ((u8 *) (arg0) + 48)) = (f32) D_800C4008_de;
        }
        var_v0 = temp_s0_2;
    } else {
        var_v0 = NULL;
    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 12)) = var_v0;
    return var_v0 != NULL;
}
