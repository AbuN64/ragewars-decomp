#include "span_1000/code_80206258.h"
#include "span_1000/code_80265370.h"
extern f32 D_800D2988;
extern f32 D_800C1B04_de, D_800C1B08_de, D_800C1B0C_de;

void func_80206A20_de(Actor_func_80206DD4_de *arg0, RiderCode80206258 *arg1) {
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 temp_fv0f_4;
    f32 temp_fv0f_5;
    f32 temp_fv1;
    f32 var_fv0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s8 temp_s3;
    SegmentRecAt5C *temp_s0;

    temp_s3 = arg1->state;
    temp_s0 = &arg0->motionTrack->segment;
    if ((u32) temp_s3 < 5U) {
        switch (temp_s3) {
        case 0:
            temp_v1 = temp_s0->flags;
            if (temp_v1 & 0xC00000) {
                if (temp_v1 & 0x04000000) {
                    if (!(arg0->inputFlags & 0x40)) {
                        arg1->triggerTime = 0.0f;
                    } else {
                        var_fv0 = D_800D2988 + arg1->triggerTime;
                        goto block_11;
                    }
                } else {
                    temp_fv0f = arg1->triggerTime;
                    if ((temp_fv0f > 0.0f) || (arg0->inputFlags & 0x20)) {
                        var_fv0 = temp_fv0f + D_800D2988;
block_11:
                        arg1->triggerTime = var_fv0;
                    }
                    if (temp_s0->triggerDelay <= arg1->triggerTime) {
                        arg1->timer = 0.0f;
                        temp_v1_2 = temp_s0->flags;
                        if (temp_v1_2 & 0x01000000) {
                            arg1->state = 3;
                        } else if (!(temp_v1_2 & 0x400000)) {
block_21:
                            if (temp_s0->flags & 0x800000) {
                                arg1->state = 4;
                            }
                        } else {
block_19:
                            arg1->state = 1;
                        }
                    }
                }
            }
            break;
        case 3:
            temp_fs0 = D_800C1B04_de;
            temp_fs0f = D_800C1B08_de;
            arg1->shake.x = func_80274A90_de(temp_fs0, temp_fs0f);
            arg1->shake.y = func_80274A90_de(temp_fs0, temp_fs0f);
            temp_fv1 = arg1->timer + D_800D2988;
            arg1->shake.z = func_80274A90_de(temp_fs0, temp_fs0f);
            arg1->timer = temp_fv1;
            if (D_800C1B0C_de < temp_fv1) {
                arg1->timer = 0.0f;
                if (temp_s0->flags & 0x400000) {
                    goto block_19;
                }
                goto block_21;
            }
            break;
        case 1:
            temp_fv0f_2 = arg1->timer;
            temp_fv0 = temp_s0->duration;
            if (temp_fv0f_2 < temp_fv0) {
                arg1->timer = (f32) (temp_fv0f_2 + D_800D2988);
            } else if (temp_s0->flags & 0x02000000) {
                arg0->flags = (s32) (arg0->flags & ~0x2000);
            } else {
                arg1->timer = temp_fv0;
                if (!(temp_s0->flags & 0x08000000) || (var_a0 = 0, ((arg0->inputFlags & 0x40) != 0))) {
                    var_a0 = 1;
                    if (temp_s0->flags & 0x10000000) {
                        var_a0 = (u32) (arg0->inputFlags & 0x40) < 1U;
                    }
                }
                if (var_a0 != 0) {
                    arg1->state = 2;
                }
            }
            if (temp_s0->duration > 0.0f) {
block_41:
                arg1->shake.y = (f32) (-temp_s0->displacement * func_80265714_de(arg1->timer / temp_s0->duration));
            } else {
block_42:
                arg1->shake.y = (f32) -temp_s0->displacement;
            }
            break;
        case 2:
            temp_fv0f_3 = arg1->timer;
            if (!(temp_fv0f_3 > 0.0f)) {
                arg1->state = 0;
                arg1->triggerTime = 0.0f;
            } else {
                arg1->timer = (f32) (temp_fv0f_3 - D_800D2988);
            }
            if (temp_s0->duration > 0.0f) {
                goto block_41;
            }
            goto block_42;
        case 4:
            temp_fv0f_4 = arg1->timer;
            if (temp_fv0f_4 < temp_s0->duration) {
                arg1->timer = (f32) (temp_fv0f_4 + D_800D2988);
            }
            temp_fv0f_5 = temp_s0->duration;
            if (temp_fv0f_5 > 0.0f) {
                arg1->shake.y = (f32) (-temp_s0->displacement * func_80265714_de(arg1->timer / temp_fv0f_5));
            } else {
                arg1->shake.y = (f32) -temp_s0->displacement;
            }
            if (temp_s0->flags & 0x02000000) {
                arg0->flags = (s32) (arg0->flags & ~0x2000);
            }
            break;
        }
    }
    if (temp_s3 != arg1->state) {
        arg1->animation = -1;
    }
}
