#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_80225D10.h"
#include "span_1000/code_802624A0.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"


extern f32 D_800C42A4_de;
extern f32 D_800C42A8_de;
extern f32 D_800C42B0_de;
extern f32 D_800C42B4_de;
extern f32 D_800C42C0_de;
extern f32 D_800C42C4_de;
extern f32 D_800C42CC_de;
extern f32 D_800C42D0_de;
extern s32 D_800CBB70;

void func_802631B0_de(char *arg0, SharedPlayer *arg1) {
    void *temp_s1;
    f32 temp_fa1;
    f32 temp_ft0;
    f32 temp_ft0f;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 var_fa1;
    f32 var_fv0;
    f32 var_fv0f;
    f32 var_fv1f;
    s32 *var_a2;
    s32 temp_a0;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_condition_bit;
    s8 temp_v0;
    s8 temp_v1;
    s8 temp_v1_3;
    void *temp_a3;

    temp_s1 = arg1->views5D8.view5D8_0.unk5D8;
    temp_ft0 = D_800C4298_de - (arg1->views5E8.view7EC_132.unk7EC * D_800C4290_de);
    temp_a3 = ((void **) arg0)[16 / sizeof(void *)];
    temp_ft0f = (((((f32) ((u8 *) temp_s1)[0x7A] * D_800C4294_de) - D_800C4298_de) * D_800C42A0_de) + D_800C4298_de) * (D_800D2988 * (temp_ft0 * D_800C429C_de));
    temp_v1 = ((s8 *) temp_s1)[0x7B];
    var_a2 = NULL;
    if ((temp_v1 < 2) && (temp_v1 >= 0) && (((u8 *) temp_s1)[0x7C] == 1)) {
        var_a2 = &D_800CBB70;
    }
    if (var_a2 != NULL) {
        ((s32 *) arg0)[36 / sizeof(s32)] = 0;
        ((s32 *) arg0)[40 / sizeof(s32)] = 0;
        ((s32 *) arg0)[44 / sizeof(s32)] = 0;
        ((s32 *) arg0)[48 / sizeof(s32)] = 0;
        ((s32 *) arg0)[52 / sizeof(s32)] = 0;
        if (*var_a2 != 0) {
loop_6:
            temp_v1_2 = ((s32 *) var_a2)[0 / sizeof(s32)];
            temp_a0 = ((s32 *) var_a2)[4 / sizeof(s32)];
            if (((s32 *) temp_a3)[176 / sizeof(s32)] & temp_v1_2) {
                ((s32 *) arg0)[36 / sizeof(s32)] = (s32) (((s32 *) arg0)[36 / sizeof(s32)] | temp_a0);
            }
            if (((s32 *) temp_a3)[180 / sizeof(s32)] & temp_v1_2) {
                ((s32 *) arg0)[40 / sizeof(s32)] = (s32) (((s32 *) arg0)[40 / sizeof(s32)] | temp_a0);
            }
            if (((s32 *) temp_a3)[184 / sizeof(s32)] & temp_v1_2) {
                ((s32 *) arg0)[44 / sizeof(s32)] = (s32) (((s32 *) arg0)[44 / sizeof(s32)] | temp_a0);
            }
            if (((s32 *) temp_a3)[188 / sizeof(s32)] & temp_v1_2) {
                ((s32 *) arg0)[48 / sizeof(s32)] = (s32) (((s32 *) arg0)[48 / sizeof(s32)] | temp_a0);
            }
            var_a2 += 8;
            if (((s32 *) temp_a3)[192 / sizeof(s32)] & temp_v1_2) {
                ((s32 *) arg0)[52 / sizeof(s32)] = (s32) (((s32 *) arg0)[52 / sizeof(s32)] | temp_a0);
            }
            if (*var_a2 != 0) {
                goto loop_6;
            }
        }
    } else {
        ((s32 *) arg0)[36 / sizeof(s32)] = (s32) ((s32 *) temp_a3)[176 / sizeof(s32)];
        ((s32 *) arg0)[40 / sizeof(s32)] = (s32) ((s32 *) temp_a3)[180 / sizeof(s32)];
        ((s32 *) arg0)[44 / sizeof(s32)] = (s32) ((s32 *) temp_a3)[184 / sizeof(s32)];
        ((s32 *) arg0)[48 / sizeof(s32)] = (s32) ((s32 *) temp_a3)[188 / sizeof(s32)];
        ((s32 *) arg0)[52 / sizeof(s32)] = (s32) ((s32 *) temp_a3)[192 / sizeof(s32)];
    }
    temp_v1_3 = ((s8 *) temp_s1)[0x7B];
    switch (temp_v1_3) {                            /* irregular */
    case 0:
        temp_v1_4 = ((s32 *) arg0)[36 / sizeof(s32)];
        if (temp_v1_4 & 1) {
            ((f32 *) arg0)[8 / sizeof(f32)] = (f32) D_800C42A4_de;
        } else if (!(temp_v1_4 & 2)) {
            ((f32 *) arg0)[8 / sizeof(f32)] = 0.0f;
        } else {
            ((f32 *) arg0)[8 / sizeof(f32)] = (f32) D_800C42A8_de;
        }
        temp_v1_5 = ((s32 *) arg0)[36 / sizeof(s32)];
        ((f32 *) arg0)[0 / sizeof(f32)] = (f32) ((f32) ((s8 *) temp_a3)[198 / sizeof(s8)] * D_800C42AC_de);
        if (temp_v1_5 & 8) {
            ((f32 *) arg0)[12 / sizeof(f32)] = (f32) D_800C42B0_de;
        } else if (!(temp_v1_5 & 4)) {
            ((f32 *) arg0)[12 / sizeof(f32)] = 0.0f;
        } else {
            ((f32 *) arg0)[12 / sizeof(f32)] = (f32) D_800C42B4_de;
        }
        if (((u8 *) temp_s1)[0x7D] != 0) {
            ((f32 *) arg0)[4 / sizeof(f32)] = (f32) ((f32) ((s8 *) temp_a3)[199 / sizeof(s8)] * D_800C42B8_de);
        } else if (arg1->views5E8.view11B4_135.unk11B4 == 0) {
            temp_v0 = ((s8 *) temp_a3)[199 / sizeof(s8)];
            if (temp_v0 != 0) {
                ((f32 *) arg0)[4 / sizeof(f32)] = (f32) (((f32 *) arg0)[4 / sizeof(f32)] + (temp_ft0f * D_800C42BC_de * (f32) temp_v0));
            }
            temp_fv0 = ((f32 *) arg0)[4 / sizeof(f32)];
            if (D_800C42C0_de < temp_fv0) {
                ((f32 *) arg0)[4 / sizeof(f32)] = (f32) D_800C42C0_de;
            } else if (temp_fv0 < D_800C42C4_de) {
                ((f32 *) arg0)[4 / sizeof(f32)] = (f32) D_800C42C4_de;
            }
        }
        break;
    case 1:
        temp_v1_6 = ((s32 *) arg0)[36 / sizeof(s32)];
        ((f32 *) arg0)[0 / sizeof(f32)] = (f32) ((f32) ((s8 *) temp_a3)[198 / sizeof(s8)] * D_800C42C8_de);
        if (temp_v1_6 & 1) {
            ((f32 *) arg0)[8 / sizeof(f32)] = (f32) D_800C42CC_de;
        } else if (!(temp_v1_6 & 2)) {
            ((f32 *) arg0)[8 / sizeof(f32)] = 0.0f;
        } else {
            ((f32 *) arg0)[8 / sizeof(f32)] = (f32) D_800C42D0_de;
        }
        if (arg1->views5E8.view11B4_135.unk11B4 != 0) {
            ((f32 *) arg0)[12 / sizeof(f32)] = 0.0f;
        } else {
            ((f32 *) arg0)[12 / sizeof(f32)] = (f32) ((f32) ((s8 *) temp_a3)[199 / sizeof(s8)] * D_800C42D4_de);
        }
        temp_v1_7 = ((s32 *) arg0)[36 / sizeof(s32)];
        if (!(temp_v1_7 & 0x10)) {
            if (temp_v1_7 & 8) {
                var_fv0f = ((f32 *) arg0)[4 / sizeof(f32)] + (temp_ft0f * D_800C42D8_de);
                var_fv0 = D_800C42DC_de;
                var_condition_bit = var_fv0 < var_fv0f;
                goto block_59;
            }
            if (temp_v1_7 & 4) {
                var_fv0f = ((f32 *) arg0)[4 / sizeof(f32)] - (temp_ft0f * D_800C42E0_de);
                var_fv0 = D_800C42E4_de;
                var_condition_bit = var_fv0f < var_fv0;
block_59:
                if (var_condition_bit) {
                    var_fv0f = var_fv0;
                }
                ((f32 *) arg0)[4 / sizeof(f32)] = var_fv0f;
            } else if (((u8 *) temp_s1)[0x7D] != 0) {
                temp_fa1 = ((f32 *) arg0)[12 / sizeof(f32)];
                if ((temp_fa1 != 0.0f) && (arg1->views5E8.view7E8_105.unk7E8 == 0)) {
                    var_fa1 = temp_fa1 * (temp_ft0 * D_800C42E8_de);
                    if (var_fa1 < 0.0f) {
                        var_fa1 = -var_fa1;
                    }
                    ((f32 *) arg0)[4 / sizeof(f32)] = func_802747A0_de(((f32 *) arg0)[4 / sizeof(f32)], var_fa1);
                }
            }
        }
        break;
    }
    temp_fv1 = ((f32 *) arg0)[8 / sizeof(f32)];
    temp_fv0f = temp_fv1 * temp_fv1;
    if (temp_fv0f < 0.0f) {
        var_fv1f = temp_fv1 * -temp_fv0f;
    } else {
        var_fv1f = temp_fv1 * temp_fv0f;
    }
    temp_fv1_2 = ((f32 *) arg0)[0 / sizeof(f32)];
    temp_fv0f_2 = temp_fv1_2 * temp_fv1_2;
    ((f32 *) arg0)[28 / sizeof(f32)] = var_fv1f;
    if (temp_fv0f_2 < 0.0f) {
        ((f32 *) arg0)[20 / sizeof(f32)] = (f32) (temp_fv1_2 * -temp_fv0f_2);
    } else {
        ((f32 *) arg0)[20 / sizeof(f32)] = (f32) (temp_fv1_2 * temp_fv0f_2);
    }
    ((f32 *) arg0)[32 / sizeof(f32)] = (f32) ((f32 *) arg0)[12 / sizeof(f32)];
    ((f32 *) arg0)[24 / sizeof(f32)] = (f32) ((f32 *) arg0)[4 / sizeof(f32)];
}
/* Warning: struct Character is not defined (only forward-declared) */
/* Warning: struct TeamInfo is not defined (only forward-declared) */
