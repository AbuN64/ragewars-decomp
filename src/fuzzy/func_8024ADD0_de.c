#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_C76B0/data.h"
#include "TYPES.H"
s32 func_802799C0_de(void *arg0, s32 arg1);
float func_8024E678_de(void *object);
f32 func_8024E2FC_de(Actor_u1 *arg0);
s32 func_8027254C_de(f32 *arg0, f32 arg1);
void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
void func_80273448_de(char *object, float x, float y, float z);
void func_8027027C_de(f32 *src, PackedMatrixWords *dst);
void func_8026992C_de(void *matrix, s32 pass, u32 alpha);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x60, 0x64, 0x68, 0x6c, 0x70, 0x80, 0x84, 0x88, 0x8c], gap at: 0x74. */
void func_8024ADD0_de(void *arg0, void *arg1, s32 arg2) {
    f32 sp10[16];
    f32 sp50[3];
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 temp_fv1;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv1;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    u8 temp_v1;

    temp_v0 = func_802799C0_de(&D_8011FFB0, 1);
    if (temp_v0 != 0) {
        temp_fs0f = func_8024E678_de(arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fs1 = (*((f32 *) ((u8 *) (arg0) + 12)) + *((f32 *) ((u8 *) (arg0) + 112))) - temp_fs0f;
        temp_fv0 = func_8024E2FC_de(arg0);
        temp_fv1 = temp_fs1 * D_800C3AB8_de;
        var_fv0 = temp_fv0 - temp_fv1;
        if (!(var_fv0 <= temp_fv0)) {
            var_fv0 = temp_fv0;
        }
        var_fv0_2 = 0.0f;
        if (!(var_fv0 < 0.0f)) {
            var_fv0_2 = temp_fv0 - temp_fv1;
            if (!(var_fv0_2 <= temp_fv0)) {
                var_fv0_2 = temp_fv0;
            }
        }
        if (arg2 != 0) {
            var_fv0_3 = D_800C3ABC_de;
            var_fv1 = D_800C3AC0_de;
        } else {
            var_fv0_3 = D_800C3AC4_de;
            var_fv1 = 0.0f;
        }
        temp_fs0 = var_fv0_2 * var_fv0_3;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp50[0] = *((f32 *) ((u8 *) (arg0) + 8)) + *((f32 *) ((u8 *) (arg1) + 0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp50[2] = *((f32 *) ((u8 *) (arg0) + 16)) + *((f32 *) ((u8 *) (arg1) + 8));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        sp50[1] = temp_fs0f + var_fv1 + *((f32 *) ((u8 *) (arg1) + 4));
        func_8027254C_de(sp50, 20000.0f);
        func_80274244_de(arg0 + 0x5C, sp10);
        func_8027347C_de(sp10, temp_fs0, 1.0f, temp_fs0);
        func_80273448_de((s8 *) sp10, sp50[0], sp50[1], sp50[2]);
        func_8027027C_de(sp10, (PackedMatrixWords *) temp_v0);
        temp_fv0f = D_800C3ACC_de - (temp_fs1 * D_800C3AC8_de);
        var_v0 = 0xFF;
        if (!(D_800C8BC0 < temp_fv0f)) {
            var_v0 = 0;
            if (!(temp_fv0f < 0.0f)) {
                var_v0 = 0xFF;
                if (!(D_800C8BC0 < temp_fv0f)) {
                    if (D_800C3AD4_de <= temp_fv0f) {
                        var_v0 = (s32) (temp_fv0f - D_800C3AD4_de) | 0x80000000;
                    } else {
                        var_v0 = (s32) temp_fv0f;
                    }
                }
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_v1 = *((u8 *) ((u8 *) (arg0) + 314));
        temp_fv0_2 = (f32) temp_v1 + ((f32) ((var_v0 & 0xFF) - temp_v1) * D_800C3AD8_de);
        if (D_800C3ADC_de <= temp_fv0_2) {
            var_v1 = (s32) (temp_fv0_2 - D_800C3ADC_de) | 0x80000000;
        } else {
            var_v1 = (s32) temp_fv0_2;
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((u8 *) ((u8 *) (arg0) + 314)) = (u8) var_v1;
        func_8026992C_de((void *) temp_v0, arg2 == 0, var_v1 & 0xFF);
    }
}
