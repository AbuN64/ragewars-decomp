#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"
void func_802A2480_de(void *arg0) {
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;

    if (arg0 != NULL) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_a0 = *((void **) ((u8 *) (arg0) + 4));
        if (temp_a0 != NULL) {
            func_802A2480_de(temp_a0);
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_a0_2 = *((void **) ((u8 *) (arg0) + 8));
        if (temp_a0_2 != NULL) {
            func_802A2480_de(temp_a0_2);
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if (*((u16 *) ((u8 *) (arg0) + 14)) == 8) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_a0_3 = *((void **) ((u8 *) (arg0) + 44));
            if (temp_a0_3 != NULL) {
                func_802A2480_de(temp_a0_3);
            }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_a0_4 = *((void **) ((u8 *) (arg0) + 52));
            if (temp_a0_4 != NULL) {
                func_802A2480_de(temp_a0_4);
            }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            temp_a0_5 = *((void **) ((u8 *) (arg0) + 48));
            if (temp_a0_5 != NULL) {
                func_802A2480_de(temp_a0_5);
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if (*((s32 *) ((u8 *) (arg0) + 40)) == 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if (*((u16 *) ((u8 *) (arg0) + 14)) == 4) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((f32 *) ((u8 *) (arg0) + 32)) = (f32) D_800C5DB8_de;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((f32 *) ((u8 *) (arg0) + 36)) = (f32) D_800C5DBC_de;
            } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s16 *) ((u8 *) (arg0) + 20)) = (s16) (s32) ((f32) *((s16 *) ((u8 *) (arg0) + 20)) * D_800C5DB8_de);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s16 *) ((u8 *) (arg0) + 22)) = (s16) (s32) ((f32) *((s16 *) ((u8 *) (arg0) + 22)) * D_800C5DBC_de);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s16 *) ((u8 *) (arg0) + 24)) = (s16) (s32) ((f32) *((s16 *) ((u8 *) (arg0) + 24)) * D_800C5DB8_de);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s16 *) ((u8 *) (arg0) + 26)) = (s16) (s32) ((f32) *((s16 *) ((u8 *) (arg0) + 26)) * D_800C5DBC_de);
            }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            *((s32 *) ((u8 *) (arg0) + 40)) = 1;
        }
    }
}
