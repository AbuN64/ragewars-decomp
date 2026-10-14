#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"
/* Refreshes every instance owned by the holder and clears their pending flag. */



void func_80220A80_de(Node_func_80449E18_de *, Node_func_80449E18_de *);                 /* extern */
void func_80245864_de(s32);                            /* extern */
s32 func_80264B6C_de(void);                            /* extern */
                           /* extern */
                           /* extern */
                    /* extern */
s32 func_802934F8_de(void);                            /* extern */
void func_804491E8_de(Node_func_80449E18_de *);                         /* extern */

void func_80449E18_de(Node_func_80449E18_de *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    struct IntPair *temp_v1;
    struct IntPair *temp_v1_2;
    Node_func_80449E18_de *var_s0;

    if ((func_802934F8_de() != 0) && (func_80264B6C_de() != 0)) {
        func_80264B8C_de();
        func_80264B7C_de();
    }
    var_s0 = arg0->unk20;
    if (var_s0 != 0) {
        do {
            func_804491E8_de(var_s0);
            temp_v0 = ((s32 (*)(s32 *, s32 *))func_80286728_de)(&D_8011FE88, &var_s0->unk8);
            var_s0->unk2FC = temp_v0;
            var_s0->unk14 = temp_v0;
            func_80220A80_de(var_s0, var_s0);
            temp_a0 = var_s0->unk5DC;
            if (temp_a0 != 0) {
                func_80245864_de(temp_a0);
            }
            temp_v1 = var_s0->unk18;
            temp_v1->field_4 = temp_v1->field_4 & ~4;
            temp_v1_2 = var_s0->unk18;
            temp_v1_2->field_4 = temp_v1_2->field_4 & ~4;
            var_s0 = var_s0->unk16E0;
        } while (var_s0 != 0);
    }
}
