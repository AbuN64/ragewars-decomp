#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_8027302C.h"
#include "span_C76B0/data.h"
#include "types.h"
void func_80274380_de(void *arg0, f32 *arg1) {
    Vector4f vector;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 var_fv0;

    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_fv0 = func_802745D0_de((*((f32 *) ((u8 *) (arg0) + 0)) * *((f32 *) ((u8 *) (arg1) + 0))) + (*((f32 *) ((u8 *) (arg0) + 4)) * *((f32 *) ((u8 *) (arg1) + 4))) + (*((f32 *) ((u8 *) (arg0) + 8)) * *((f32 *) ((u8 *) (arg1) + 8))) + (*((f32 *) ((u8 *) (arg0) + 12)) * *((f32 *) ((u8 *) (arg1) + 12))));
    if (temp_fv0 != 0.0f) {
        temp_fv0f = D_800C493C - ((temp_fv0 - (((temp_fv0 * D_800C4934_de) + D_800C4938_de) * D_800D2988)) / temp_fv0);
        var_fv0 = D_800C493C;
        if (!(D_800C493C < temp_fv0f)) {
            var_fv0 = 0.0f;
            if (!(temp_fv0f < 0.0f)) {
                var_fv0 = D_800C493C;
                goto block_4;
            }
        } else {
block_4:
            if (!(var_fv0 < temp_fv0f)) {
                var_fv0 = temp_fv0f;
            }
        }
        func_80270CD0_de(&vector, var_fv0, arg0, (void *)arg1);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 0)) = ((f32 *)&vector)[0];
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 4)) = ((f32 *)&vector)[1];
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 8)) = ((f32 *)&vector)[2];
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        *((f32 *) ((u8 *) (arg0) + 12)) = ((f32 *)&vector)[3];
    }
}
