#include "audio_callbacks.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "gfx.h"
#include "resident_event_handler.h"
#include "gbi.h"
#include "span_1000/code_80291054.h"
#include "span_16E000/code_804143D8.h"
#include "span_C76B0/data.h"
#include "types.h"
void func_80417034_de(s32 mode);
void func_80416CF4_de(int mode);
void func_80416ECC_de(s32 mode);
void func_80415C90_de(f32 x, f32 y, f32 w, f32 h, u32 col0, u32 col1, u32 col2, u32 col3);
void func_802A1898_de(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3);
void func_804181A4_de(s32, s32, s32, s32, f32, f32, f32, f32);
extern s32 D_800DF274;
extern s32 D_800DF280;
extern s32 D_800DF28C;
extern s32 D_800DF290;
extern Rec_func_8024C92C_de D_80153F60;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x30, 0x34, 0x38, 0x3c, 0x40, 0x48, 0x4c, 0x58, 0x5c, 0x70, 0x74, 0x78, 0x7c], gap at: 0x50. */
void func_80417B20_de(f32 x, f32 y, s32 unused, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, u32 arg9) {
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    Gfx *temp_a0;
    Gfx *temp_a0_2;
    Gfx *temp_a0_3;
    Gfx *temp_a1;
    Gfx *temp_v1;
    Gfx *temp_v1_2;
    Gfx *temp_v1_3;
    Gfx *temp_v1_4;
    Gfx *temp_v1_6;
    Gfx *var_v1;
    f32 temp_fs3;
    f32 temp_fs3f;
    f32 temp_fv0;
    f32 temp_fv0_3;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 var_fs1;
    f32 var_fs1f;
    f32 var_fs2;
    f32 temp_fv0_2;
    f32 temp_fv0_4;
    s32 var_a0;
    s32 var_a0_2;
    f32 var_fs0;
    f32 var_fs0f;
    f32 var_fs2f;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    u32 temp_v1_5;

    var_fs2f = arg3;
    var_fs2 = arg4;
    var_fs0 = arg5;
    var_fs0f = arg6;
    var_fs1 = arg7;
    temp_fs3 = x;
    var_fs1f = arg8;
    temp_fs3f = y;
    if ((D_80153F68 == 0) || (D_80153F60.y == 0)) {
        D_800DF290 = 0;
        D_800E32E4 = 0;
        func_80417034_de(0xC);
        func_80416CF4_de(5);
        if (D_800DF274 != 7) {
            D_800DF274 = 7;
            if (D_800E32E4 == 0) {
                D_800E32E4 = 1;
                temp_v1 = D_80110634;
                D_80110634 = (Gfx *)D_80110634 + 1;
                gDPPipeSync(temp_v1);
                
            }
            temp_a0 = D_80110634;
            D_80110634 = (Gfx *)D_80110634 + 1;
            gDPSetTexturePersp(temp_a0, G_TP_NONE);
            
        }
        if (D_800DF280 != 0xE) {
            D_800DF280 = 0xE;
            if (D_800E32E4 == 0) {
                D_800E32E4 = 1;
                temp_v1_2 = D_80110634;
                D_80110634 = (Gfx *)D_80110634 + 1;
                gDPPipeSync(temp_v1_2);
                
            }
            temp_v1_3 = D_80110634;
            D_80110634 = (Gfx *)D_80110634 + 1;
            gSPTexture(temp_v1_3, 0x8000, 0x8000, 0, 0, G_OFF);
            
        }
        if (D_80153F60.x == 0) {
            func_80416ECC_de(9);
            func_80415C90_de(temp_fs3, temp_fs3f, (var_fs2f), var_fs2, (u32) arg9, (u32) arg9, (u32) arg9, (u32) arg9);
        }
    } else if (D_80153F60.x == 0) {
        D_800E32E4 = 0;
        func_80417034_de(0xC);
        var_a0 = 0xD;
        if (D_80153F68 == 0) {
            var_a0 = 0xE;
        }
        if (var_a0 != D_800DF280) {
            D_800DF280 = var_a0;
            if (D_800E32E4 == 0) {
                D_800E32E4 = 1;
                temp_v1_4 = D_80110634;
                D_80110634 = (Gfx *)D_80110634 + 1;
                gDPPipeSync(temp_v1_4);
                
            }
            if (var_a0 == 0xD || var_a0 == 0xE) {
                var_v1 = D_80110634;
                D_80110634 = var_v1 + 1;
                gSPTexture(var_v1, 0x8000, 0x8000, 0, 0, var_a0 == 0xD ? G_ON : G_OFF);
            }
        }
        if (arg9 != D_800DF28C) {
            D_800DF28C = arg9;
            temp_a1 = D_80110634;
            temp_a0_2 = (Gfx *)D_80110634 + 1;
            D_80110634 = temp_a0_2 + 1;
            gDPSetEnvColor(temp_a1, arg9 >> 16, arg9 >> 8, arg9, 0);
            gDPSetPrimColor(temp_a0_2, 0, 0, arg9 >> 16, arg9 >> 8, arg9, arg9 >> 24);
        }
        if (D_800DF274 != 7) {
            D_800DF274 = 7;
            if (D_800E32E4 == 0) {
                D_800E32E4 = 1;
                temp_v1_6 = D_80110634;
                D_80110634 = (Gfx *)D_80110634 + 1;
                gDPPipeSync(temp_v1_6);
                
            }
            temp_a0_3 = D_80110634;
            D_80110634 = (Gfx *)D_80110634 + 1;
            gDPSetTexturePersp(temp_a0_3, G_TP_NONE);
            
        }
        var_a0_2 = 2;
        if (D_800DF26C_de != 0) {
            var_a0_2 = 1;
        }
        func_80416CF4_de(var_a0_2);
        var_s0 = (s32) temp_fs3;
        var_s1 = (s32) temp_fs3f;
        D_800DF290 = 0x13;
        var_s2 = (s32) ((temp_fs3 + (var_fs2f)) - D_800DD400_de);
        var_s3 = (s32) ((temp_fs3f + var_fs2) - D_800DD400_de);
        if (var_s2 < var_s0) {
            temp_fv0 = (f32) var_s0;
            var_s0 = var_s2;
            var_s2 = (s32) temp_fv0;
            temp_fv0_2 = var_fs0;
            var_fs0 = (var_fs1);
            var_fs1 = (temp_fv0_2);
            var_fs2f = (-(var_fs2f));
        }
        if (var_s3 < var_s1) {
            temp_fv0_3 = (f32) var_s1;
            var_s1 = var_s3;
            var_s3 = (s32) temp_fv0_3;
            temp_fv0_4 = var_fs0f;
            var_fs0f = (var_fs1f);
            var_fs1f = (temp_fv0_4);
            var_fs2 = -var_fs2;
        }
        func_802A1898_de(&sp20, &sp24, &sp28, &sp2C);
        if ((sp28 < var_s2) || (var_s0 < sp20) || (sp2C < var_s3) || (var_s1 < sp24)) {
            if ((sp28 >= var_s0) && (sp2C >= var_s1) && (var_s2 >= sp20) && (var_s3 >= sp24)) {
                if (var_s1 < sp24) {
                    temp_fv0f = ((f32) (sp24 - var_s1) / var_fs2) * (var_fs1f - (var_fs0f));
                    var_s1 = sp24;
                    var_fs2 = (f32) ((var_s3 - var_s1) + 1);
                    var_fs0f = (((var_fs0f) + temp_fv0f));
                }
                if (sp2C < var_s3) {
                    var_s3 = sp2C;
                    var_fs1f = (var_fs0f) + (((f32) (sp2C - var_s1) / var_fs2) * (var_fs1f - (var_fs0f)));
                }
                if (var_s0 < sp20) {
                    temp_fv0f_2 = ((f32) (sp20 - var_s0) / (var_fs2f)) * (var_fs1 - (var_fs0));
                    var_s0 = sp20;
                    var_fs2f = ((f32) ((var_s2 - var_s0) + 1));
                    var_fs0 = (((var_fs0) + temp_fv0f_2));
                }
                if (sp28 < var_s2) {
                    var_s2 = sp28;
                    var_fs1 = (var_fs0) + (((f32) (sp28 - var_s0) / (var_fs2f)) * (var_fs1 - (var_fs0)));
                }
                goto block_51;
            }
        } else {
block_51:
            if (!(var_fs1 < (var_fs0))) {
                if (!(var_fs1f < (var_fs0f))) {
                    if (D_800DF260_de != 0) {
                        goto block_54;
                    }
                    func_80419278_de(var_s0, var_s1, var_s2, var_s3, (var_fs0), (var_fs0f), var_fs1, var_fs1f);
                } else {
                    goto block_55;
                }
            } else {
block_54:
block_55:
                func_804181A4_de(var_s0, var_s1, var_s2, var_s3, (var_fs0), (var_fs0f), var_fs1, var_fs1f);
            }
        }
    }
}
