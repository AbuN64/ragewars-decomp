#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8044DA54_de_closed.h"
#include "types.h"
s32 func_80265964_de(s32 arg0);
s32 func_8023C78C_de(s32 arg0, s32 arg1_unused, s32 arg2);
void func_8025768C_de(void *arg0) {
    s32 *temp_v0_4;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    s8 *temp_s0_3;
    s8 *temp_s0_4;
    s8 *temp_s1;
    s8 *temp_s1_2;
    s8 *temp_s3;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_5;

    temp_s0 = func_80265964_de(0x14);
    temp_s0_2 = temp_s0 - func_80265964_de(0x10);
    temp_v0 = func_8023C78C_de(temp_s0_2, 0, func_80265964_de(0x10));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11080)) = temp_v0;
    temp_s3 = func_8028FDB4_de((s32 *) temp_v0, 0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    func_8028FDB4_de((s32 *) *((s32 *) ((u8 *) (arg0) + 11080)), 1);
    temp_s1 = func_8028FDB4_de((s32 *) temp_s3, 0);
    temp_s0_3 = func_8028FDB4_de((s32 *) temp_s3, 1);
    temp_v0_2 = func_8028FDB4_de((s32 *) temp_s3, 2);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11084)) = temp_v0_2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11096)) = (s8 *) (temp_s1 + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11100)) = (s8 *) (temp_s0_3 + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11092)) = *((s32 *)temp_v0_2);
    temp_s0_4 = func_8028FDB4_de((s32 *) temp_s3, 3);
    temp_s1_2 = func_8028FDB4_de((s32 *) temp_s3, 4);
    temp_v0_3 = func_8028FDB4_de((s32 *) temp_s3, 5);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11120)) = (s8 *) (temp_s0_4 + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11132)) = (s32) *((s32 *) ((u8 *) (temp_s0_4) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11124)) = (s8 *) (temp_s1_2 + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11136)) = (s32) *((s32 *) ((u8 *) (temp_s1_2) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11128)) = (s8 *) (temp_v0_3 + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11140)) = (s32) *((s32 *) ((u8 *) (temp_v0_3) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v0_4 = func_8028FDB4_de((s32 *) *((s32 *) ((u8 *) (arg0) + 11080)), 1);
    temp_v0_5 = func_8028FDB4_de(temp_v0_4, 0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11104)) = (s32) (temp_v0_5 + 8);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s32 *) ((u8 *) (arg0) + 11108)) = (s32) *((s32 *) ((u8 *) (temp_v0_5) + 4));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    *((s8 **) ((u8 *) (arg0) + 11088)) = func_8028FDB4_de(temp_v0_4, 1);
}
