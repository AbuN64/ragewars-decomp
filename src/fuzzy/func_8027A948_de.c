#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "packed_float.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_C76B0/data.h"
#include "TYPES.H"
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0xc0, 0xc4, 0xc8, 0xcc, 0xd8, 0xdc, 0xe0, 0xe4], gap at: 0xd0. */
void func_8027A948_de(void *arg0, Vec3 *arg1) {
    Vec3 sp10;
    Vec3 sp20;
    Vector4f sp30;
    Vector4f sp40;
    Vector4f sp50;
    f32 sp60[16];
    Vec3 spA0;
    Vec3 spB0;
    Vec3 *temp_s1;
    f32 temp_fa0;
    f32 temp_fa0_2;
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 var_fv0f;
    f32 var_fv0f_2;
    s32 var_condition_bit;
    void *temp_s0;

    func_80271F68_de(&sp10, arg1, arg0 + 8);
    temp_fv0 = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
    if (temp_fv0 <= D_800C4BA8_de) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 8)) = (f32) arg1->x;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 12)) = (f32) arg1->y;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 16)) = (f32) arg1->z;
        return;
    }
    func_8027207C_de(&sp10.x);
    func_80271818_de(/* return */ &sp40, &sp10.x);
    func_80271818_de(/* return */ &sp30, arg0 + 0x174);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0f = *((f32 *) ((u8 *) (arg0) + 28));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0_2 = *((f32 *) ((u8 *) (arg0) + 32));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fa0 = *((f32 *) ((u8 *) (arg0) + 36));
    temp_fs0f = func_802B72B0_de((temp_fv0f * temp_fv0f) + (temp_fv0_2 * temp_fv0_2) + (temp_fa0 * temp_fa0));
    if (temp_fv0 < D_800C4BAC_de) {
        temp_fv0f_2 = temp_fv0 - D_800C4BB0_de;
        if (temp_fv0f_2 < 0.0f) {
            var_fv0f = 0.0f;
        } else {
            var_fv0f = temp_fv0f_2 * D_800C4BB4_de;
        }
        var_fv0f_2 = D_800C4BBC_de - (var_fv0f * D_800C4BB8_de);
    } else {
        var_fv0f_2 = D_800C4BC0_de;
    }
    func_80270CD0_de(&sp50, var_fv0f_2, &sp30, &sp40);
    func_80274244_de(&sp50.x, sp60);
    temp_s0 = arg0 + 0x174;
    sp20.x = 0.0f;
    sp20.y = 0.0f;
    sp20.z = D_800C4BC4_de;
    func_80272898_de(sp60, &sp20, temp_s0);
    temp_s1 = arg0 + 0x1C;
    func_80271F9C_de(temp_s1, temp_s0, temp_fs0f);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0_3 = func_802B2350((s32) *((u16 *) ((u8 *) (*((void **) ((u8 *) (*((void **) ((u8 *) (arg0) + 280))) + 48))) + 16)));
    if (temp_fv0_3 != 0.0f) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        spB0.x = *((f32 *) ((u8 *) (arg0) + 372));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        spB0.y = *((f32 *) ((u8 *) (arg0) + 376));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        spB0.z = *((f32 *) ((u8 *) (arg0) + 380));
        func_80271F9C_de(&spA0, &spB0, temp_fv0_3);
        func_80271F34_de(temp_s1, temp_s1, &spA0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0f_3 = *((f32 *) ((u8 *) (arg0) + 28));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0_4 = *((f32 *) ((u8 *) (arg0) + 32));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fa0_2 = *((f32 *) ((u8 *) (arg0) + 36));
        temp_fs0 = func_802B72B0_de((temp_fv0f_3 * temp_fv0f_3) + (temp_fv0_4 * temp_fv0_4) + (temp_fa0_2 * temp_fa0_2));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0_5 = func_802B2350((s32) *((u16 *) ((u8 *) (*((void **) ((u8 *) (*((void **) ((u8 *) (arg0) + 280))) + 48))) + 18)));
        if (temp_fv0_3 > 0.0f) {
            var_condition_bit = temp_fv0_5 < temp_fs0;
        } else {
            var_condition_bit = temp_fs0 < temp_fv0_5;
        }
        if (var_condition_bit) {
            func_80271F9C_de(temp_s1, &spB0, temp_fv0_5);
        }
    }
    func_80279DD0_de(arg0, 1.0f);
}
