#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "packed_float.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "types.h"
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x30, 0x34, 0x38, 0x48, 0x4c, 0x50, 0x54], gap at: 0x3c. */
void func_802849F0_de(void *arg0) {
    Vec3 sp10;
    Vec3 direction;
    Vec3 *temp_s0;
    f32 temp_fa0;
    f32 temp_fs0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    s32 var_condition_bit;

    func_80228DC4_de(&D_80145040, arg0);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0 = func_802B2350((s32) *((u16 *) ((u8 *) (*((void **) ((u8 *) (*((void **) ((u8 *) (arg0) + 280))) + 48))) + 16)));
    if (temp_fv0 != 0.0f) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        direction.x = *((f32 *) ((u8 *) (arg0) + 372));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        direction.y = *((f32 *) ((u8 *) (arg0) + 376));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        direction.z = *((f32 *) ((u8 *) (arg0) + 380));
        func_80271F9C_de(&sp10, &direction, temp_fv0);
        temp_s0 = arg0 + 0x1C;
        func_80271F34_de(temp_s0, temp_s0, &sp10);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0f = *((f32 *) ((u8 *) (arg0) + 28));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0_2 = *((f32 *) ((u8 *) (arg0) + 32));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fa0 = *((f32 *) ((u8 *) (arg0) + 36));
        temp_fs0 = func_802B72B0_de((temp_fv0f * temp_fv0f) + (temp_fv0_2 * temp_fv0_2) + (temp_fa0 * temp_fa0));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_fv0_3 = func_802B2350((s32) *((u16 *) ((u8 *) (*((void **) ((u8 *) (*((void **) ((u8 *) (arg0) + 280))) + 48))) + 18)));
        if (temp_fv0 > 0.0f) {
            var_condition_bit = temp_fv0_3 < temp_fs0;
        } else {
            var_condition_bit = temp_fs0 < temp_fv0_3;
        }
        if (var_condition_bit) {
            func_80271F9C_de(temp_s0, &direction, temp_fv0_3);
        }
    }
    func_80279DD0_de(arg0, 1.0f);
}
