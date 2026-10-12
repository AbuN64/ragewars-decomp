#include "types.h"
typedef struct ColorActor { u8 pad0[0x520]; u8 color[8]; } ColorActor;
extern void func_8027207C_de(f32 *);
extern f64 D_800C30B8_de;
extern f32 D_800C30C0_de;
extern f32 D_800C30C4_de;
extern f32 D_800C30C8_de;
extern f32 D_800C30CC_de;
extern f32 D_800C30D0_de;
extern f32 D_800C30D4_de;
extern u8 D_800CBC90[];
extern s32 D_800CD730;
extern f32 D_800C30D8_de;
extern u8 D_800CBC92[];
extern f32 D_800C30DC_de;
extern f32 D_800C30E0_de;
extern u8 D_800D0EEA[];
extern f64 D_800C30E8_de;
extern f32 D_800C30F0_de;
extern f64 D_800C30F8_de;
extern f64 D_800C81F0;
extern f32 D_800C3108_de;
extern f32 D_800C310C_de;
extern u8 D_800CBC9C[];
extern f32 D_800C3110_de;
extern s8 D_800CBCA1;
extern f32 D_800C3114_de;
extern s8 D_800CBCA2;
extern f64 D_800C3118_de;
extern f32 D_800C3120_de;
extern f32 D_800C3124_de;
extern f32 D_800C3128_de;
extern f32 D_800C312C_de;
extern f64 D_800C3130_de;
extern f32 D_800C3138_de;
extern f32 D_800C313C_de;
extern f32 D_800C3140_de;
extern f32 D_800C3144_de;
extern f64 D_800C3148_de;
extern f32 D_800C3150_de;
extern f32 D_800C3154_de;
extern f32 D_800C3158_de;
extern f32 D_800C315C_de;
void func_80233DFC_de(ColorActor *arg0) {
    f32 vector[3];
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs1;
    f32 temp_fs1f;
    f32 temp_fs2;
    f32 temp_fs2f;
    f32 temp_fs3;
    f32 temp_fs3f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv1f;
    f64 temp_fs0f;
    f64 var_fa0;
    f64 var_fa0_2;
    f64 var_fa0_3;
    f64 var_fa0_4;
    f64 var_fa0_5;
    f64 var_fa0_6;
    f64 var_fa0_7;
    f64 var_fa0_8;
    s32 temp_cond;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s0;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s8 var_v0_3;
    s8 var_v0_4;
    s8 var_v0_5;
    u8 *temp_v1;
    u8 *var_s1;

    temp_fs0f = D_800C30B8_de;
    temp_fs2f = D_800C30C0_de;
    temp_fs2 = D_800C30C4_de;
    temp_fs1f = D_800C30C8_de;
    temp_fs0 = D_800C30CC_de;
    temp_fs3 = D_800C30D0_de;
    temp_fs1 = D_800C30D4_de;
    var_s2 = 0;
    var_s1 = D_800CBC90;
    var_s0 = 2;
    temp_fs3f = temp_fs3;
    do {
        var_fa0 = (f64) D_800CD730;
        if (D_800CD730 < 0) {
            var_fa0 += temp_fs0f;
        }
        temp_fv0 = (temp_fs3f * (func_802B7130_de(temp_fs3 * (f32) var_fa0 * ((f32) var_s0 * temp_fs2f) * temp_fs2) * temp_fs1f)) + temp_fs1f + D_800C30D8_de;
        if (!(temp_fs0 <= temp_fv0)) {
            var_v0 = (s32) temp_fv0;
            var_s1[0] = (u8) var_v0;
        } else {
            var_v0 = (s32) (temp_fv0 - temp_fs0) | 0x80000000;
            var_s1[0] = (u8) var_v0;
        }
        D_800CBC92[var_s0] = (s8) var_v0;
        var_fa0_2 = (f64) D_800CD730;
        if (D_800CD730 < 0) {
            var_fa0_2 += temp_fs0f;
        }
        temp_fv0_2 = (((func_802B7130_de(temp_fs3 * (f32) var_fa0_2 * ((f32) var_s0 * temp_fs2f) * temp_fs2) * temp_fs1) + D_800C30DC_de) - temp_fs1) - D_800C30E0_de;
        temp_v1 = var_s1;
        if (!(temp_fs0 <= temp_fv0_2)) {
            var_v0_2 = (s32) temp_fv0_2;
            var_s1 += 1;
        } else {
            var_v0_2 = (s32) (temp_fv0_2 - temp_fs0) | 0x80000000;
            var_s1 += 1;
        }
        temp_v1[8] = (s8) var_v0_2;
        D_800D0EEA[var_s0] = (u8) var_v0_2;
        var_s2 += 1;
        var_s0 += 1;
    } while (var_s2 < 3);
    temp_v0 = D_800CD730 * 6;
    var_fa0_3 = (f64) temp_v0;
    if (temp_v0 < 0) {
        var_fa0_3 += D_800C30E8_de;
    }
    temp_fs0_2 = D_800C30F0_de;
    vector[0] = func_802B7130_de((f32) var_fa0_3 * temp_fs0_2);
    temp_v0 = D_800CD730 * 8;
    var_fa0_4 = (f64) temp_v0;
    if (temp_v0 < 0) {
        var_fa0_4 += D_800C30F8_de;
    }
    vector[1] = func_802B7130_de((f32) var_fa0_4 * temp_fs0_2);
    temp_v0_2 = D_800CD730 * 0xA;
    var_fa0_5 = (f64) temp_v0_2;
    if (temp_v0_2 < 0) {
        var_fa0_5 += D_800C81F0;
    }
    vector[2] = func_802B6560_de((f32) var_fa0_5 * temp_fs0_2);
    func_8027207C_de(&vector[0]);
    vector[0] *= D_800C3108_de;
    vector[1] *= D_800C3108_de;
    vector[2] *= D_800C3108_de;
    D_800CBC9C[4] = (u32)vector[0];
    D_800CBCA1 = (u32)vector[1];
    D_800CBCA2 = (u32)vector[2];
    var_fa0_6 = (f64) D_800CD730;
    if (D_800CD730 < 0) {
        var_fa0_6 += D_800C3118_de;
    }
    temp_fv0_3 = (func_802B7130_de(2.0f * (temp_fs3 * (f32) var_fa0_6) * D_800C3120_de) * D_800C3124_de) + D_800C3128_de;
    var_v0_3 = (u32)temp_fv0_3 & 0xF8;
    arg0->color[0] = var_v0_3;
    arg0->color[4] = var_v0_3;
    var_fa0_7 = (f64) D_800CD730;
    if (D_800CD730 < 0) {
        var_fa0_7 += D_800C3130_de;
    }
    temp_fv0_4 = (func_802B7130_de(temp_fs3 * (f32) var_fa0_7 * D_800C3138_de) * D_800C313C_de) + D_800C3140_de;
    var_v0_4 = (u32)temp_fv0_4 & 0xF8;
    arg0->color[1] = var_v0_4;
    arg0->color[5] = var_v0_4;
    var_fa0_8 = (f64) D_800CD730;
    if (D_800CD730 < 0) {
        var_fa0_8 += D_800C3148_de;
    }
    temp_fv0_5 = (func_802B7130_de(temp_fs3 * (f32) var_fa0_8 * D_800C3150_de) * D_800C3154_de) + D_800C3158_de;
    var_v0_5 = (u32)temp_fv0_5 & 0xF8;
    arg0->color[2] = var_v0_5;
    arg0->color[6] = var_v0_5;
}
