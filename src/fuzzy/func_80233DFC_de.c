#include "span_1000/code_80233920.h"
#include "shared/particle_lighting.h"
extern void func_8027207C_de(f32 *);
extern f32 D_800C30C0_de;
extern f32 D_800C30C4_de;
extern f32 D_800C30C8_de;
extern f32 D_800C30D0_de;
extern f32 D_800C30D4_de;
extern Shared_ParticleLighting D_800CBC90;
extern u32 D_800CD730;
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
extern u8 D_800CBC9C[];
extern f64 D_800C3118_de;
extern f32 D_800C3120_de;
extern f32 D_800C3124_de;
extern f32 D_800C3128_de;
extern f64 D_800C3130_de;
extern f32 D_800C3138_de;
extern f32 D_800C313C_de;
extern f32 D_800C3140_de;
extern f64 D_800C3148_de;
extern f32 D_800C3150_de;
extern f32 D_800C3154_de;
extern f32 D_800C3158_de;
void func_80233DFC_de(Entity_func_80233C88_de *arg0) {
    f32 vector[3];
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
    f64 var_fa0_3;
    f64 var_fa0_4;
    f64 var_fa0_5;
    f64 var_fa0_6;
    f64 var_fa0_7;
    f64 var_fa0_8;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s2;
    s8 var_v0_3;
    s8 var_v0_4;
    s8 var_v0_5;
    u8 *temp_v1;
    u8 *var_s1;

    temp_fs2f = D_800C30C0_de;
    temp_fs2 = D_800C30C4_de;
    temp_fs1f = D_800C30C8_de;
    temp_fs3 = D_800C30D0_de;
    temp_fs1 = D_800C30D4_de;
    var_s2 = 0;
    temp_fs3f = temp_fs3;
    do {
        temp_fv0 = (temp_fs3f * (func_802B7130_de(temp_fs3 * (f32) D_800CD730 * ((f32) (var_s2 + 2) * temp_fs2f) * temp_fs2) * temp_fs1f)) + temp_fs1f + D_800C30D8_de;
        D_800CBC90.ambientCopy[var_s2] = D_800CBC90.ambient[var_s2] = (u32)temp_fv0;
        temp_fv0_2 = (((func_802B7130_de(temp_fs3 * (f32) D_800CD730 * ((f32) (var_s2 + 2) * temp_fs2f) * temp_fs2) * temp_fs1) + D_800C30DC_de) - temp_fs1) - D_800C30E0_de;
        D_800CBC90.diffuseCopy[var_s2] = D_800CBC90.diffuse[var_s2] = (u32)temp_fv0_2;
        var_s2 += 1;
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
    D_800CBC90.direction[0] = (u32)vector[0];
    D_800CBC90.direction[1] = (u32)vector[1];
    D_800CBC90.direction[2] = (u32)vector[2];
    var_fa0_6 = (f64)(s32)D_800CD730;
    if ((s32)D_800CD730 < 0) var_fa0_6 += D_800C3118_de;
    temp_fv0_3 = (func_802B7130_de(2.0f * (temp_fs3 * (f32)var_fa0_6) * D_800C3120_de) * D_800C3124_de) + D_800C3128_de;
    var_v0_3 = (u32)temp_fv0_3 & 0xF8;
    arg0->color[0] = var_v0_3;
    arg0->secondaryColor[0] = var_v0_3;
    var_fa0_7 = (f64)(s32)D_800CD730;
    if ((s32)D_800CD730 < 0) var_fa0_7 += D_800C3130_de;
    temp_fv0_4 = (func_802B7130_de(temp_fs3 * (f32)var_fa0_7 * D_800C3138_de) * D_800C313C_de) + D_800C3140_de;
    var_v0_4 = (u32)temp_fv0_4 & 0xF8;
    arg0->color[1] = var_v0_4;
    arg0->secondaryColor[1] = var_v0_4;
    var_fa0_8 = (f64)(s32)D_800CD730;
    if ((s32)D_800CD730 < 0) var_fa0_8 += D_800C3148_de;
    temp_fv0_5 = (func_802B7130_de(temp_fs3 * (f32)var_fa0_8 * D_800C3150_de) * D_800C3154_de) + D_800C3158_de;
    var_v0_5 = (u32)temp_fv0_5 & 0xF8;
    arg0->color[2] = var_v0_5;
    arg0->secondaryColor[2] = var_v0_5;
}
