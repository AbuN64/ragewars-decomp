#include "span_16E000/code_8040C780.h"
extern s32 D_800DEA60, D_800E2AB4_de;

/* Propagate widget opacity and scale, compute its bounds, then clip the hit box. */
s32 func_8040E0D4_de(struct Shape_typemap_165 *arg0, struct Shape_typemap_165 *arg1, Widget_func_8040CF8C_de *arg2, DrawArgs *arg3) {
    f32 temp_ft0;
    f32 temp_ft1f;
    f32 temp_ft2;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1f;
    s16 temp_a0_2;
    s32 temp_ft2f;
    s32 temp_ft2f_2;
    s32 temp_ft2f_3;
    s32 temp_ft2f_4;
    s32 temp_t0;
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t7;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 var_t2;
    s32 var_t3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u16 temp_a0;
    u16 temp_v0;

    temp_a0 = arg2->flags;
    temp_t0 = arg3->flags;
    temp_ft1f = arg3->scaleX;
    temp_ft2 = arg3->scaleY;
    temp_t5 = temp_a0 & 0x400 & 0xFFFF;
    temp_t6 = (s32) (((u16)arg2->width) << 0x10) >> 0x11;
    temp_t7 = (s32) (((u16)arg2->height) << 0x10) >> 0x11;
    if (!(temp_t0 & 0x4000)) {
        arg3->flags = (s32) (temp_t0 | (temp_a0 & 0x140));
    }
    arg3->flags = (s32) (arg3->flags | (arg2->flags & 0x609));
    if ((u8) arg2->alpha < 0xFFU) {
        arg3->alpha = (u8) ((arg3->alpha * arg2->alpha) / 255);
    }
    if (arg3->flags & 1) {
        arg3->alpha = (u8) ((u8) arg3->alpha >> 1);
    }
    var_v0 = 0;
    if (arg3->alpha != 0) {
        if (!(arg2->flags & 8)) {
            return 0;
        }
        if ((arg3->scaleX != 1.0f) || (arg3->scaleY != 1.0f) || (arg2->scaleX != 1.0f) || (arg2->scaleY != 1.0f)) {
            temp_fv0f = arg3->scaleX;
            temp_fv0f_2 = temp_fv0f * arg2->scaleX;
            arg3->scaleX = temp_fv0f_2;
            temp_ft0 = arg3->scaleY * arg2->scaleY;
            temp_fv1f = ((f32) (arg2->y + arg2->offsetY) + ((f32) (s16) ((u16)arg2->height) * 0.5f)) * arg3->scaleY;
            arg3->scaleY = temp_ft0;
            temp_ft2f = (s32) (((f32) (arg2->x + arg2->offsetX) + ((f32) (s16) ((u16)arg2->width) * 0.5f)) * temp_fv0f);
            temp_ft2f_2 = (s32) temp_fv1f;
            var_t2 = (s32) ((f32) (s16) ((u16)arg2->width) * temp_fv0f_2 * 0.5f);
            arg0->field_0 = (s32) ((temp_ft2f - var_t2) + arg3->x);
            var_t3 = (s32) ((f32) (s16) ((u16)arg2->height) * temp_ft0 * 0.5f);
            arg0->field_4 = (s32) (temp_ft2f + var_t2 + arg3->x);
            arg0->field_8 = (s32) ((temp_ft2f_2 - var_t3) + arg3->y);
            arg0->field_C = (s32) (temp_ft2f_2 + var_t3 + arg3->y);
        } else {
            arg0->field_0 = (s32) (arg3->x + arg2->x + arg2->offsetX);
            arg0->field_8 = (s32) (arg3->y + arg2->y + arg2->offsetY);
            arg0->field_4 = (s32) ((arg0->field_0 + (s16) ((u16)arg2->width)) - 1);
            arg0->field_C = (s32) ((arg0->field_8 + (s16) ((u16)arg2->height)) - 1);
            var_t2 = (s32) (((u16)arg2->width) << 0x10) >> 0x11;
            var_t3 = (s32) (((u16)arg2->height) << 0x10) >> 0x11;
        }
        temp_a0_2 = arg2->x;
        temp_v0 = ((u16)arg2->height);
        temp_ft2f_3 = (s32) ((f32) (temp_a0_2 + ((s16) ((u16)arg2->width) / 2)) * temp_ft1f);
        temp_ft2f_4 = (s32) ((f32) (arg2->y + ((s32) ((s16) temp_v0 + ((u32) (temp_v0 << 0x10) >> 0x1F)) >> 1)) * temp_ft2);
        if (temp_a0 & 0x800 & 0xFFFF) {
            if (temp_t5 != 0) {
                arg1->field_0 = (s32) arg0->field_0;
                arg1->field_4 = (s32) arg0->field_4;
                arg1->field_8 = (s32) arg0->field_8;
                arg1->field_C = (s32) arg0->field_C;
            } else {
                arg1->field_0 = (s32) ((temp_ft2f_3 - var_t2) + arg3->x);
                arg1->field_8 = (s32) ((temp_ft2f_4 - var_t3) + arg3->y);
                arg1->field_4 = (s32) (temp_ft2f_3 + var_t2 + arg3->x);
                var_v0_2 = temp_ft2f_4 + var_t3 + arg3->y;
                goto block_29;
            }
        } else {
            if (temp_t5 == 0) {
                if (temp_ft1f != 1.0f) {
                    var_v0_3 = (s32) ((f32) temp_a0_2 * temp_ft1f) + arg3->x;
                } else {
                    var_v0_3 = temp_a0_2 + arg3->x;
                }
                arg1->field_0 = var_v0_3;
                arg1->field_4 = (s32) (arg1->field_0 + (s16) ((u16)arg2->width));
                if (temp_ft2 != 1.0f) {
                    var_v0_4 = (s32) ((f32) arg2->y * temp_ft2) + arg3->y;
                } else {
                    var_v0_4 = arg2->y + arg3->y;
                }
                arg1->field_8 = var_v0_4;
                var_v0_2 = arg1->field_8 + (s16) ((u16)arg2->height);
            } else {
                arg1->field_0 = (s32) ((temp_ft2f_3 - temp_t6) + arg2->offsetX + arg3->x);
                arg1->field_8 = (s32) ((temp_ft2f_4 - temp_t7) + arg2->offsetY + arg3->y);
                arg1->field_4 = (s32) (temp_ft2f_3 + temp_t6 + arg2->offsetX + arg3->x);
                var_v0_2 = temp_ft2f_4 + temp_t7 + arg2->offsetY + arg3->y;
            }
block_29:
            arg1->field_C = var_v0_2;
        }
        temp_v1 = arg1->field_0;
        if (temp_v1 < 0) {
            arg1->field_0 = 0;
            goto block_34;
        }
        var_v0 = 0;
        if (D_800DEA60 >= temp_v1) {
block_34:
            temp_v0_2 = arg1->field_4;
            if (temp_v0_2 < 0) {
                return 0;
            }
            if (D_800DEA60 < temp_v0_2) {
                arg1->field_4 = (s32) D_800DEA60;
            }
            temp_v1_2 = arg1->field_8;
            if (temp_v1_2 < 0) {
                arg1->field_8 = 0;
                goto block_43;
            }
            var_v0 = 0;
            if (D_800E2AB4_de >= temp_v1_2) {
block_43:
                temp_v0_3 = arg1->field_C;
                if (temp_v0_3 < 0) {
                    return 0;
                }
                if (D_800E2AB4_de < temp_v0_3) {
                    arg1->field_C = (s32) D_800E2AB4_de;
                }
                temp_v1_3 = arg1->field_0;
                if (temp_v1_3 >= arg1->field_4) {
                    arg1->field_4 = (s32) (temp_v1_3 + 1);
                }
                temp_v1_4 = arg1->field_8;
                if (temp_v1_4 >= arg1->field_C) {
                    arg1->field_C = (s32) (temp_v1_4 + 1);
                }
                arg3->x = (s32) arg0->field_0;
                var_v0 = 1;
                arg3->y = (s32) arg0->field_8;
                arg3->v[0] = (s32) arg0->field_0;
                arg3->v[1] = (s32) arg0->field_4;
                arg3->v[2] = (s32) arg0->field_8;
                arg3->v[3] = (s32) arg0->field_C;
                return var_v0;
            }
            return var_v0;
        }
        return var_v0;
    }
    return var_v0;
}
