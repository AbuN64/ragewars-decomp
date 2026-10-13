#include "span_1000/code_8029BBA0.h"
#include "span_C76B0/data.h"
#include "types.h"
extern f64 D_800E1118;
extern f64 D_800E1130;
extern f64 D_800E1148;
extern f64 D_800E11F0;

s32 func_80414400_de(u8 *arg0, f64 value, s32 arg4, s32 arg5, s32 arg6) {
    u8 fraction[128];
    u8 integer[128];
    u8 exponent[16];
    f64 sp120;
    f64 sp128;
    f64 sp130;
    f64 sp138;
    u8 sp140;
    s32 sp144;
    f64 temp_fa0;
    f64 temp_fa0_2;
    f64 temp_fa0_3;
    f64 temp_fa0_4;
    f64 temp_fs0;
    f64 temp_fs0_2;
    f64 temp_fs0_3;
    f64 temp_fs1;
    f64 temp_fv0;
    f64 var_fa0;
    f64 var_fs0;
    f64 var_fs0f;
    f64 var_fv0;
    f64 var_fv0_2;
    f64 var_fv0_3;
    f64 var_fv0f;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a1_2;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_10;
    s32 var_v1_3;
    s32 var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    u32 temp_a1;
    u8 *temp_s1;
    u8 *temp_s7;
    u8 *var_a0;
    u8 *var_a1;
    u8 *var_s2;
    u8 *var_s2_2;
    u8 *var_s3;
    u8 *var_s7;
    u8 *var_v1_2;
    u8 *var_v1_4;
    u8 *var_v1_5;
    u8 *var_v1_6;
    u8 temp_v0;
    u8 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    u8 temp_v0_6;
    u8 temp_v0_7;
    u8 var_v0_3;

    var_s5 = arg6;
    var_s2 = fraction;
    var_s3 = &integer[127];
    var_s7 = &exponent[15];
    temp_s1 = var_s3;
    integer[127] = 0;
    exponent[15] = 0;
    var_fa0 = value;
    sp140 = arg4;
    sp144 = 1;
    if (!(var_fa0 < D_800E1118)) {
        sp144 = 0;
    }
    if (sp144 != 0) {
        var_fa0 = -var_fa0;
    }
    if (var_s5 >= 0x7F) {
        var_s5 = 0x7E;
    }
    var_a0_2 = 0;
    if (var_s5 == 6) {
        var_fs0 = D_800DD0F0;
    } else {
        var_fv0 = D_800DD0F8_de;
        var_v1 = var_s5;
        if (var_s5 == 0) {
            var_fs0 = D_800E1130;
            var_a0_2 = 0;
        } else {
            if (var_s5 < 0) {
                var_v1 = -var_s5;
                var_fv0 = D_800DD108_de;
            }
            var_fv0f = D_800DD110_de;
            var_v0 = var_v1 & 1;
loop_13:
            var_v1 = var_v1 >> 1;
            if (var_v0 != 0) {
                var_fv0f *= var_fv0;
                }
            var_v0 = var_v1 & 1;
            if (var_v1 != 0) {
                var_fv0 *= var_fv0;
                goto loop_13;
            }
            var_fs0 = var_fv0f;
            var_a0_2 = 0;
        }
    }
    var_fs0f = D_800E1148 / var_fs0;
    if (sp140 != 0x66) {
        var_s6 = 0;
        if (sp140 == 0x67) {
            if (var_fa0 == D_800DD120_de) {
                var_a0_2 = 1;
                goto block_27;
            }
            var_s4 = 0;
            if ((D_800DD128_de <= var_fa0) && (var_fa0 < var_fs0)) {
                goto block_26;
            }
        } else {
            goto block_27;
        }
    } else {
block_26:
        var_a0_2 = 1;
        var_s6 = 0;
block_27:
        var_s4 = 0;
    }
    var_fp = 0;
    if (var_a0_2 != 0) {
        temp_fv0 = func_8029DAA0_de(var_fa0, &sp120);
        if ((var_fs0f <= temp_fv0) || (sp140 != 0x67)) {
            temp_fa0 = temp_fv0 + var_fs0f;
            var_fv0_2 = temp_fa0;
            if (D_800DD130_de <= temp_fa0) {
                sp120 += D_800DD130_de;
                var_fv0_2 = temp_fa0 - D_800DD130_de;
            }
            var_s0 = 0;
            if (var_s5 > 0) {
                temp_fs0 = D_800DD138_de;
                do {
                    var_s4 += 1;
                    var_fv0_2 = func_8029DAA0_de(var_fv0_2 * temp_fs0, &sp128);
                    var_s0 += 1;
                    *var_s2 = (s32) sp128 + 0x30;
                    var_s2 += 1;
                } while (var_s0 < var_s5);
            }
            if (sp140 == 0x67) {
                var_v1_2 = var_s2 - 1;
                if ((u32) var_v1_2 >= (u32) fraction) {
loop_39:
                    if (*var_v1_2 == 0x30) {
                        *var_v1_2 = 0;
                        var_v1_2 -= 1;
                        var_s4 -= 1;
                        if ((u32) var_v1_2 >= (u32) fraction) {
                            goto loop_39;
                        }
                    }
                }
            }
        }
        if (sp120 == D_800DD140_de) {
            if ((sp140 != 0x67) || (var_s4 < var_s5) || (var_s4 < arg5)) {
                var_s3 -= 1;
                *var_s3 = 0x30;
                var_s6 = 1;
            }
        } else if (sp120 <= D_800DD148_de) {
            var_a0_3 = (s32) sp120;
            if (var_a0_3 != 0) {
                do {
                    var_s3 -= 1;
                    var_s6 += 1;
                    temp_v0 = (var_a0_3 % 10) + 0x30;
                    var_a0_3 /= 0xA;
                    *var_s3 = temp_v0;
                } while (var_a0_3 != 0);
            }
        } else if (D_800DD150_de < sp120) {
            temp_fs1 = D_800DD158_de;
            temp_fs0_2 = D_800DD168_de;
            do {
                var_s3 -= 1;
                *var_s3 = (s32) ((func_8029DAA0_de(sp120 * temp_fs1, &sp120) + D_800DD160_de) * temp_fs0_2) + 0x30;
                var_s6 += 1;
            } while (D_800DD150_de < sp120);
        }
        var_v1_3 = var_s5;
        if (sp140 == 0x67) {
            if (var_v1_3 < arg5) {
                var_v1_3 = arg5;
            }
            var_a3 = (var_s6 + var_s4) - var_v1_3;
            if (var_s4 < var_a3) {
                var_a3 = var_s4;
            }
            if (var_a3 > 0) {
                var_a1 = &fraction[var_s4 - 1];
                if ((u32) var_a1 >= (u32) fraction) {
loop_63:
                    if (var_a3 > 0) {
                        var_s4 -= 1;
                        temp_v0 = *var_a1;
                        *var_a1 = 0;
                        if ((u32) (temp_v0 & 0xFF) >= 0x36U) {
                            var_v1_4 = var_a1 - 1;
                            var_a0_4 = 1;
                            if ((u32) var_v1_4 >= (u32) fraction) {
loop_67:
                                if (var_a0_4 != 0) {
                                    temp_v0_2 = *var_v1_4 + 1;
                                    *var_v1_4 = temp_v0_2;
                                    if ((u32) (temp_v0_2 & 0xFF) < 0x3AU) {
                                        var_a0_4 = 0;
                                    } else {
                                        *var_v1_4 = 0x30;
                                    }
                                    var_v1_4 -= 1;
                                    if ((u32) var_v1_4 < (u32) fraction) {
                                        goto block_73;
                                    }
                                    goto loop_67;
                                }
                            } else {
block_73:
                                if (var_a0_4 != 0) {
                                    var_v1_5 = temp_s1 - 1;
                                    if ((u32) var_v1_5 >= (u32) var_s3) {
loop_75:
                                        if (var_a0_4 != 0) {
                                            temp_v0_3 = *var_v1_5 + 1;
                                            *var_v1_5 = temp_v0_3;
                                            if ((u32) (temp_v0_3 & 0xFF) < 0x3AU) {
                                                var_a0_4 = 0;
                                            } else {
                                                *var_v1_5 = 0x30;
                                            }
                                            var_v1_5 -= 1;
                                            if ((u32) var_v1_5 < (u32) var_s3) {
                                                goto block_81;
                                            }
                                            goto loop_75;
                                        }
                                    } else {
block_81:
                                        if (var_a0_4 != 0) {
                                            var_s3 -= 1;
                                            *var_s3 = 0x31;
                                            var_s6 += 1;
                                            var_a3 -= 1;
                                        }
                                    }
                                }
                            }
                        }
                        var_a1 -= 1;
                        var_a3 -= 1;
                        if ((u32) var_a1 >= (u32) fraction) {
                            goto loop_63;
                        }
                    }
                }
            }
        }
    } else {
        var_s1 = 0;
        if (D_800DD170_de <= var_fa0) {
            do {
                var_fa0 *= D_800DD178_de;
                var_s1 += 1;
            } while (D_800DD170_de <= var_fa0);
        }
        if (D_800DD180_de < var_fa0) {
loop_90:
            if (var_fa0 < (D_800DD188_de - var_fs0f)) {
                var_fa0 *= D_800DD190_de;
                var_s1 -= 1;
                if (D_800DD180_de < var_fa0) {
                    goto loop_90;
                }
            }
        }
        temp_fa0_2 = func_8029DAA0_de(var_fa0, &sp130);
        if (sp140 == 0x67) {
            var_s5 -= 1;
            var_fs0 *= D_800DD198_de;
            var_fs0f = D_800DD1A0 / var_fs0;
        }
        if ((var_fs0f <= temp_fa0_2) || (sp140 != 0x67)) {
            temp_fa0_3 = temp_fa0_2 + var_fs0f;
            var_fv0_3 = temp_fa0_3;
            if (D_800DD1A8_de <= temp_fa0_3) {
                temp_fa0_4 = temp_fa0_3 - D_800DD1A8_de;
                sp130 += D_800DD1A8_de;
                var_fv0_3 = temp_fa0_4;
                if (D_800DD1B0 <= sp130) {
                    var_s1 += 1;
                    sp130 *= D_800DD1B8;
                    var_fv0_3 = temp_fa0_4 * D_800DD1B8;
                }
            }
            var_s0_2 = 0;
            if (var_s5 > 0) {
                temp_fs0_3 = D_800E11F0;
                do {
                    var_s4 += 1;
                    var_fv0_3 = func_8029DAA0_de(var_fv0_3 * temp_fs0_3, &sp138);
                    var_s0_2 += 1;
                    *var_s2 = (s32) sp138 + 0x30;
                    var_s2 += 1;
                } while (var_s0_2 < var_s5);
            }
            if (sp140 == 0x67) {
                var_v1_6 = var_s2 - 1;
                if ((u32) var_v1_6 >= (u32) fraction) {
loop_104:
                    if (*var_v1_6 == 0x30) {
                        *var_v1_6 = 0;
                        var_v1_6 -= 1;
                        var_s4 -= 1;
                        if ((u32) var_v1_6 >= (u32) fraction) {
                            goto loop_104;
                        }
                    }
                }
            }
        }
        temp_a1 = (u32) var_s1 >> 0x1F;
        if (var_s1 < 0) {
            var_s1 = -var_s1;
        }
        var_v0_2 = 0 < 2;
        if (var_s1 > 0) {
            do {
                var_s7 -= 1;
                var_fp += 1;
                temp_v0_4 = (var_s1 % 10) + 0x30;
                var_s1 /= 0xA;
                *var_s7 = temp_v0_4;
            } while (var_s1 > 0);
            var_v0_2 = var_fp < 2;
        }
        if (var_v0_2 != 0) {
            do {
                var_s7 -= 1;
                var_fp += 1;
                *var_s7 = 0x30;
            } while (var_fp < 2);
        }
        temp_s7 = var_s7 - 1;
        if (temp_a1 & 0xFF) {
            var_v0_3 = 0x2D;
        } else {
            var_v0_3 = 0x2B;
        }
        *temp_s7 = var_v0_3;
        var_s7 = temp_s7 - 1;
        var_fp += 2;
        var_s3 -= 1;
        *var_s7 = 0x65;
        var_s6 = 1;
        *var_s3 = (s32) sp130 + 0x30;
    }
    var_a3_2 = 0;
    if ((sp140 != 0x67) || (var_s4 > 0)) {
        var_a3_2 = 1;
    }
    var_a1_2 = arg5 - (sp144 + var_s6 + var_a3_2 + var_s4 + var_fp);
    if (var_a1_2 < 0) {
        var_a1_2 = 0;
    }
    var_a0 = arg0;
    var_v1_7 = 0;
    if (var_a1_2 > 0) {
        do {
            *var_a0 = 0x20;
            var_v1_7 += 1;
            var_a0 += 1;
        } while (var_v1_7 < var_a1_2);
    }
    if (sp144 != 0) {
        *var_a0 = 0x2D;
        var_a0 += 1;
    }
    var_v1_8 = 0;
    if (var_s6 > 0) {
        do {
            temp_v0_5 = *var_s3;
            var_s3 += 1;
            var_v1_8 += 1;
            *var_a0 = temp_v0_5;
            var_a0 += 1;
        } while (var_v1_8 < var_s6);
    }
    if (var_a3_2 != 0) {
        *var_a0 = 0x2E;
        var_a0 += 1;
        var_s2_2 = fraction;
        var_v1_9 = 0;
        if (var_s4 > 0) {
            do {
                temp_v0_6 = *var_s2_2;
                var_s2_2 += 1;
                var_v1_9 += 1;
                *var_a0 = temp_v0_6;
                var_a0 += 1;
            } while (var_v1_9 < var_s4);
        }
    }
    var_v1_10 = 0;
    if (var_fp > 0) {
        do {
            temp_v0_7 = *var_s7;
            var_s7 += 1;
            var_v1_10 += 1;
            *var_a0 = temp_v0_7;
            var_a0 += 1;
        } while (var_v1_10 < var_fp);
    }
    *var_a0 = 0;
    return var_a0 - arg0;
}
