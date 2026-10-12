#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_80246E34.h"
#include "types.h"
s32 func_80204308_de(void *, void *, void *);
void func_80214178_de(void *, void *, s32);
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x3c, 0x48, 0x4c, 0x58, 0x5c, 0x60, 0x64], gap at: 0x40. */
void func_8028A27C_de(void *arg0, void *arg1, Vec3 *arg2, Vec3 *arg3) {
    s32 sp10;
    s32 sp14;
    f32 temp_fs0f;
    f32 temp_fs0f_2;
    f32 temp_fs1;
    f32 temp_fs1f;
    f32 temp_fs2;
    f32 temp_ft0;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv1;
    f32 temp_fv1f;
    f32 var_fs0;
    f32 var_ft0f;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    void *temp_a0;
    void *temp_s0;

    if ((arg2->x != arg3->x) || (arg2->y != arg3->y) || (arg2->z != arg3->z)) {
        temp_v0 = *((s32 **) arg1)[24 / sizeof(s32 *)];
        sp10 = temp_v0 == 0xB;
        sp14 = temp_v0 == 1;
        temp_fs1f = ((f32 *) arg1)[12 / sizeof(f32)] + func_8024E420_de(arg1);
        var_s5 = 0;
        temp_fs2 = temp_fs1f + func_8024D284_de(arg1);
        if (((s32 *) arg0)[4060 / sizeof(s32)] > 0) {
            do {
                temp_s0 = *((void **) ((u8 *) ((arg0 + (var_s5 * 4))) + 3932));
                var_s4 = 0;
                if (temp_s0 != arg1) {
                    var_s1 = 0;
                    temp_fs0f = ((f32 *) temp_s0)[12 / sizeof(f32)] + func_8024E420_de(temp_s0);
                    temp_a0 = ((void **) temp_s0)[24 / sizeof(void *)];
                    temp_v1 = ((s32 *) temp_a0)[0 / sizeof(s32)];
                    temp_fv0 = temp_fs0f + func_8024D284_de(temp_s0);
                    if (temp_v1 != 7) {
                        if (temp_v1 < 8) {
                            var_s2 = 0;
                            if (temp_v1 != 6) {
                                goto block_14;
                            }
                            var_s4 = 1;
                            var_s3 = 1;
                            temp_v0_2 = ((s32 *) temp_a0)[20 / sizeof(s32)];
                            var_ft0f = ((f32 *) temp_a0)[32 / sizeof(f32)];
                            var_fs0 = ((f32 *) temp_a0)[36 / sizeof(f32)];
                            var_a0 = temp_v0_2 & 4;
                            var_v1 = temp_v0_2 & 8;
                            var_a2 = temp_v0_2 & 0x10;
                            var_a1 = temp_v0_2 & 0x20;
                        } else {
                            var_s2 = 0;
                            if (temp_v1 != 0xA) {
block_14:
                                var_ft0f = 0.0f;
                                var_a0 = 0;
                                var_v1 = 0;
                                var_s3 = 0;
                                var_a2 = 0;
                                var_a1 = 0;
                                var_fs0 = 0.0f;
                            } else {
                                var_s2 = 1;
                                var_s3 = 0;
                                var_a2 = 0;
                                var_a1 = 0;
                                var_s1 = 1;
                                temp_v0_3 = ((s32 *) temp_a0)[20 / sizeof(s32)];
                                var_ft0f = ((f32 *) temp_a0)[36 / sizeof(f32)];
                                var_fs0 = 0.0f;
                                var_a0 = temp_v0_3 & 4;
                                var_v1 = temp_v0_3 & 8;
                            }
                        }
                    } else {
                        var_s2 = 1;
                        var_s3 = 0;
                        var_a2 = 0;
                        var_a1 = 0;
                        var_s1 = 1;
                        temp_v0_4 = ((s32 *) temp_a0)[20 / sizeof(s32)];
                        var_ft0f = ((f32 *) temp_a0)[40 / sizeof(f32)];
                        var_fs0 = 0.0f;
                        var_a0 = temp_v0_4 & 8;
                        var_v1 = temp_v0_4 & 0x10;
                    }
                    if ((var_s1 != 0) && ((var_v0 = 0, (temp_fs2 < temp_fs0f)) || (temp_fv0 < temp_fs1f))) {
                        var_s1_2 = 0;
                    } else {
                        var_v0 = 0;
                        if (sp10 != 0) {
                            if (var_a0 != 0) {
                                var_v0 = 1;
                            } else {
                                goto block_23;
                            }
                        } else {
block_23:
                            if ((sp14 != 0) && (var_v1 != 0)) {
                                var_v0 = 1;
                            }
                        }
                        var_s1_2 = 0;
                        if (((sp10 != 0) && (var_a2 != 0)) || ((sp14 != 0) && (var_a1 != 0))) {
                            var_s1_2 = 1;
                        }
                    }
                    if ((var_v0 != 0) || (var_s1_2 != 0)) {
                        temp_fv0_2 = ((f32 *) temp_s0)[8 / sizeof(f32)];
                        temp_fv1f = arg2->x - temp_fv0_2;
                        temp_ft0 = ((f32 *) temp_s0)[16 / sizeof(f32)];
                        temp_fv1 = arg2->z - temp_ft0;
                        temp_fv0f = arg3->x - temp_fv0_2;
                        temp_fv0_3 = arg3->z - temp_ft0;
                        temp_fs1 = (temp_fv1f * temp_fv1f) + (temp_fv1 * temp_fv1);
                        temp_fs0f_2 = (temp_fv0f * temp_fv0f) + (temp_fv0_3 * temp_fv0_3);
                        if (var_v0 != 0) {
                            if (var_s4 != 0) {
                                temp_fv0_4 = var_ft0f * var_ft0f;
                                var_v1_2 = 0;
                                if (temp_fv0_4 < temp_fs1) {
                                    if (temp_fs0f_2 <= temp_fv0_4) {
                                        var_v1_2 = 1;
                                    }
                                }
                            } else {
                                var_v1_2 = 1;
                                if (!(temp_fs0f_2 <= (var_ft0f * var_ft0f))) {
                                    var_v1_2 = 0;
                                }
                            }
                            if (var_v1_2 != 0) {
                                if ((*((s32 *) ((u8 *) (((void **) temp_s0)[24 / sizeof(void *)]) + 0)) == 0xA) && (var_s2 == 1)) {
                                    var_v1_2 = func_80204308_de(temp_s0, temp_s0 + 0x170, arg1);
                                }
                                if (var_v1_2 != 0) {
                                    func_80214178_de(temp_s0, temp_s0 + 0x170, var_s2);
                                }
                            }
                        }
                        if (var_s1_2 != 0) {
                            if (var_s4 != 0) {
                                temp_fv0_5 = var_fs0 * var_fs0;
                                var_v1_3 = 0;
                                if (temp_fs1 <= temp_fv0_5) {
                                    if (temp_fv0_5 < temp_fs0f_2) {
                                        var_v1_3 = 1;
                                    }
                                }
                            } else {
                                var_v1_3 = 1;
                                if (!((var_fs0 * var_fs0) < temp_fs0f_2)) {
                                    var_v1_3 = 0;
                                }
                            }
                            if (var_v1_3 != 0) {
                                func_80214178_de(temp_s0, temp_s0 + 0x170, var_s3);
                            }
                        }
                    }
                }
                var_s5 += 1;
            } while (var_s5 < ((s32 *) arg0)[4060 / sizeof(s32)]);
        }
    }
}
