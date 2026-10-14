#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804251F4.h"
#include "types.h"
#include "stddef.h"
/* Marks available inventory entries with their slot indices. */
s32 func_8022F4DC_de(void *, s32); /* extern */
extern char D_80102B00[];
void func_80426090_de(Arg *arg0) {
    s32 temp_s0;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s1;
    StateRecAt91 *temp_a0;
    Model *var_s2;
    temp_a0 = arg0->unk5D8;
    if (temp_a0->unk91 != 1) {
        var_s1 = 0;
        if (temp_a0->unk78 != 0) {
            var_s2 = (Model *)arg0->unk18;
            temp_s3 = temp_a0->unk7F * 0x190;
            do {
                temp_s0 = var_s2->slots[var_s1];
                if (temp_s0 >= 0x4C3) {
                    temp_s0 = temp_s0 - 0x4C3;
                    temp_v0 = func_8022F4DC_de(temp_s3 + D_80102B00, temp_s0);
                    if (temp_v0 == 1) {
                        arg0->slots[temp_s0].available = temp_v0;
                        arg0->slots[temp_s0].slot = var_s1;
                    }
                }
                var_s1 += 1;
            } while (var_s1 < 8);
        }
    }
}
