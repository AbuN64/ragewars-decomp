#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80444EC0.h"
#include "types.h"
#include "stddef.h"
/* Edits a byte, integer, or float option and propagates it to the active resource records. */
s32 func_8026435C_de(s32); /* extern */
s32 func_8028B2F8_de(char *, s32); /* extern */
void *func_8028FDB4_de(s32, s32); /* extern */
void func_802BD320_de(s32, char *, s32); /* extern */
s32 func_80441FE8_de(void *); /* extern */
s32 func_80442384_de(void *, void *, s32); /* extern */
s32 func_804423BC_de(void *, s32, s32, s32, s32, s32); /* extern */
extern char D_800E27D0;

extern s32 D_8011FEF4;
s32 func_80444FA0_us_rev1(OptionEditState *arg0, OptionEditState *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7) {
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_s0_2;
    s32 var_v1;
    s32 length;
    u8 *temp_s0;
    s32 var_s1;
    OptionEditState *temp_a1;
    OptionEditState *temp_v0;
    ResourceManagerState *temp_v0_2;
    char *var_a0;
    var_s1 = 0;
    if (func_8026435C_de(arg1->unk_20) != 0) {
        return func_80442384_de(arg0, arg1, arg2);
    }
    temp_v0 = arg1->unk_1C;
    if (temp_v0 != NULL) {
        temp_a1 = temp_v0->unk_5DC;
        if (temp_a1 != NULL) {
            temp_a1_2 = temp_a1->unk_58;
            if (temp_a1_2 != 0) {
                temp_s0 = func_8028B2F8_de(&D_8011FE88, temp_a1_2) + arg4;
                switch (arg3) { /* irregular */
                case 0:
                    var_s1 = *temp_s0;
                    var_s1 = func_804423BC_de(arg1, var_s1, arg5, 0, arg6, 1);
                    *temp_s0 = var_s1;
                    break;
                case 1:
                    var_s1 = *(s32 *)temp_s0;
                    var_s1 = func_804423BC_de(arg1, var_s1, arg5, 0, arg6, arg3);
                    *(s32 *)temp_s0 = var_s1;
                    break;
                case 2:
                    var_s1 = (s32)*(f32 *)temp_s0;
                    var_v1 = arg6;
                    var_s1 = func_804423BC_de(arg1, var_s1, arg5, 0, var_v1, 1);
                    *(f32 *)temp_s0 = var_s1;
                    break;
                }
                temp_s0_2 = *arg0->unk_14;
                length=func_80441FE8_de(arg0);
                length-=6;
                func_802BD320_de(temp_s0_2 + length, &D_800E27D0, (s32) ((f32) var_s1 / arg7));
                if (D_800E63AC != 0) {
                    temp_v0_2 = func_8028FDB4_de(D_8011FEF4, 0);
                    var_v1 = 0;
                    temp_a1_3 = temp_v0_2->count;
                    temp_v0_2=&((OptionEditContext *)(temp_v0_2))->unk_8;
                    if (temp_a1_3 > 0) {
                        do {
                            var_a0 = (char *)temp_v0_2 + var_v1 * 100;
                            temp_s0 = var_a0 + arg4;
                            switch(arg3) {
                            case 0: *temp_s0=var_s1;break;
                            case 1: *(s32 *)temp_s0=var_s1;break;
                            case 2: *(f32 *)temp_s0=var_s1;break;
                            }
                            var_v1 += 1;
                        } while (var_v1 < temp_a1_3);
                    }
                }
            }
        }
    }
    return 0;
}
