#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/UNUSED.H"
#include "sdk/AUDIO/802BD1A8_19.H"
#include "RENDER_4/8028FD2C_6.H"

#if defined(VERSION_US_REV1)
/* Edits a byte, integer, or float option and propagates it to the active resource records. */
 /* extern */
s32 func_8028B2F8_de(Shared_World *, s32); /* extern */
s32 Pak_CountLineChars(void *); /* extern */
s32 func_80442384_de(void *, void *, s32); /* extern */
s32 Pak_AdjustValue(void *, s32, s32, s32, s32, s32); /* extern */

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
                temp_s0 = func_8028B2F8_de(&g_world, temp_a1_2) + arg4;
                switch (arg3) { /* irregular */
                case 0:
                    var_s1 = *temp_s0;
                    var_s1 = Pak_AdjustValue(arg1, var_s1, arg5, 0, arg6, 1);
                    *temp_s0 = var_s1;
                    break;
                case 1:
                    var_s1 = *(s32 *)temp_s0;
                    var_s1 = Pak_AdjustValue(arg1, var_s1, arg5, 0, arg6, arg3);
                    *(s32 *)temp_s0 = var_s1;
                    break;
                case 2:
                    var_s1 = (s32)*(f32 *)temp_s0;
                    var_v1 = arg6;
                    var_s1 = Pak_AdjustValue(arg1, var_s1, arg5, 0, var_v1, 1);
                    *(f32 *)temp_s0 = var_s1;
                    break;
                }
                temp_s0_2 = *arg0->unk_14;
                length=Pak_CountLineChars(arg0);
                length-=6;
                func_802BD320_de(temp_s0_2 + length, &g_pakFormatInt06, (s32) ((f32) var_s1 / arg7));
                if (D_800E63AC != 0) {
                    temp_v0_2 = Render_GetPackSection(D_8011FEF4, 0);
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
#endif
