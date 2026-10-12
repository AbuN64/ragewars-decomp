#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"
s32 func_80277128_de(void *arg0, u32 arg1, u32 arg2, u32 arg3, Vec3 *arg4, f32 *arg5);
void func_80272A10_de(void *arg0, void *arg1, Vec3 *arg2);
f32 func_80278890_de(void *arg0);
/* A light volume supplies two transforms, RGB strength, and animation flags. */
typedef struct LightingVolume {
    f32 reserved0;
    f32 strength;
    Vec3 color;
    Vec3 heading;
    Matrix inverse;
    Matrix rotation;
    char reservedA0[0x18];
    u8 inverted;
    u8 reservedB9;
    u8 animated;
    u8 shape;
    u8 phase;
} LightingVolume;
typedef struct LightingResult {
    u8 ambient[3]; u8 reserved3;
    u8 ambientCopy[3]; u8 reserved7;
    u8 diffuse[3]; u8 reservedB;
    u8 diffuseCopy[3]; u8 reservedF;
    s8 direction[3]; u8 reserved13[5];
} LightingResult;
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x8d8, 0x8dc, 0x8e0, 0x8e4, 0x8e8, 0x8ec, 0x8f0, 0x8f4, 0x8f8, 0x8fc, 0x908, 0x90c, 0x918, 0x91c, 0x920, 0x924], gap at: 0x900. */
void func_80289970_de(LightingVolume **arg0, s32 arg1, Vec3 *arg2, LightingResult *arg3) {
    f32 weights[128];
    Vec3 directions[128];
    union { Vec3 vector; u32 words[3]; } transformed;
    Vec3 v828, v838, v848, v858, v868, sp878, sp888, sp898, v8A8, sp8B8;
    LightingVolume *sp8C8;
    u32 *sp8CC;
    f32 *sp8D0;
    f32 *sp8D4;
    Vec3 *var_s3;
    f32 *temp_v0;
    f32 *var_s1;
    f32 *var_s2;
    f32 *var_s2_2;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 temp_fs1f;
    f32 temp_ft0f;
    f32 temp_ft1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 var_fs0;
    f32 var_fs0f;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0_4;
    f32 var_fv0_5;
    f32 var_fv0f_2;
    f32 var_fv0f_3;
    f32 var_fv0f_4;
    f32 var_fv0f_5;
    f32 var_fv0f_6;
    f32 var_fv0f_7;
    f32 var_fv0f_8;
    f64 var_fv0f;
    s32 var_s7;
    s32 var_s7_2;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    LightingVolume **var_fp;
    LightingVolume **var_s6;
    LightingVolume *temp_s0;
    LightingVolume *temp_s0_2;

    var_fv0f = (f64) D_801462C8.buttons;
    if (D_801462C8.buttons < 0) {
        var_fv0f += D_800C5240_de;
    }
    sp8C8 = NULL;
    temp_fs1f = (f32) var_fv0f * D_800C5248;
    if (D_801462C8.flags & 0x4000) {
        arg3->ambientCopy[0] = 0;
        arg3->ambient[0] = 0;
        arg3->ambientCopy[1] = 0;
        arg3->ambient[1] = 0;
        arg3->ambientCopy[2] = 0;
        arg3->ambient[2] = 0;
        arg3->diffuseCopy[0] = 0;
        arg3->diffuse[0] = 0;
        arg3->diffuseCopy[1] = 0;
        arg3->diffuse[1] = 0;
        arg3->diffuseCopy[2] = 0;
        arg3->diffuse[2] = 0;
        arg3->direction[0] = 0x7F;
        arg3->direction[1] = 0;
        arg3->direction[2] = 0;
        return;
    }
    var_s7 = 0;
    v828.z = 0.0f;
    v828.y = 0.0f;
    v828.x = 0.0f;
    v848.z = 0.0f;
    v848.y = 0.0f;
    v848.x = 0.0f;
    v858.z = 0.0f;
    v858.y = 0.0f;
    v858.x = 0.0f;
    v868.z = 0.0f;
    v868.y = 0.0f;
    v868.x = 0.0f;
    if (arg1 > 0) {
        var_s2 = &weights[0];
        var_s6 = arg0;
        var_s3 = &directions[0];
        sp8CC = &transformed.words[0];
        do {
            temp_s0 = *var_s6;
            func_80272898_de(temp_s0->inverse.m, arg2, sp8CC);
            if (func_80277128_de(temp_s0, transformed.words[0], transformed.words[1], transformed.words[2], &sp888, var_s2) != 0) {
                func_80271F34_de(&sp898, &sp888, &transformed.vector);
                func_80272A10_de(temp_s0->rotation.m, &sp898, &sp888);
                func_80271F68_de(var_s3, arg2, &sp888);
                func_8027207C_de(&var_s3->x);
                v838.x = temp_s0->color.x;
                v838.y = temp_s0->color.y;
                v838.z = temp_s0->color.z;
                if (temp_s0->animated != 0) {
                    temp_fv0 = func_80278890_de(temp_s0);
                    v8A8.x = temp_fv0;
                    v8A8.y = temp_fv0;
                    v8A8.z = temp_fv0;
                    func_80271F9C_de(&sp878, &v8A8.x, *var_s2 * temp_s0->strength);
                    sp8C8 = temp_s0;
                    if (temp_s0->inverted != 0) {
                        func_80271F9C_de(&sp878, &sp878, -1.0f);
                    }
                    func_80271F34_de(&v848, &v848, &sp878);
                }
                temp_fv0f = temp_s0->strength * D_800C524C;
                temp_fs0 = D_800C5250_de - temp_fv0f;
                func_80271F9C_de(&sp878, &v838.x, *var_s2 * temp_fv0f);
                if (temp_s0->inverted != 0) {
                    func_80271F9C_de(&sp878, &sp878, -1.0f);
                }
                func_80271F34_de(&v848, &v848, &sp878);
                *var_s2 *= temp_fs0;
                var_fv0f_2 = v838.x;
                if (var_fv0f_2 < 0.0f) {
                    var_fv0f_2 = -var_fv0f_2;
                }
                if (!(v838.y < 0.0f)) {
                    var_fv0f_3 = var_fv0f_2 + v838.y;
                } else {
                    var_fv0f_3 = var_fv0f_2 - v838.y;
                }
                if (!(v838.z < 0.0f)) {
                    var_fs0 = var_fv0f_3 + v838.z;
                } else {
                    var_fs0 = var_fv0f_3 - v838.z;
                }
                func_80271F9C_de(&sp878, var_s3, *var_s2);
                func_80271F9C_de(&sp878, &sp878, var_fs0);
                func_80271F34_de(&v828, &v828, &sp878);
                if (temp_s0->inverted != 0) {
                    *var_s2 = -*var_s2;
                }
            } else {
                var_s3->x = 0.0f;
                var_s3->y = 0.0f;
                var_s3->z = 0.0f;
                *var_s2 = 0.0f;
            }
            var_s2 += 1;
            var_s3 += 1;
            var_s7 += 1;
            var_s6 += 1;
        } while (var_s7 < arg1);
    }
    func_8027207C_de(&v828.x);
    var_s7_2 = 0;
    if (arg1 > 0) {
        var_s2_2 = &weights[0];
        var_fp = arg0;
        temp_fs1 = D_800C5254_de;
        var_s1 = var_s2_2;
        sp8D0 = &v838.x;
        sp8D4 = &v8A8.x;
        do {
            temp_v0 = &directions[var_s7_2].x;
            temp_fs0_2 = (v828.x * temp_v0[0]) + (v828.y * temp_v0[1]) + (v828.z * temp_v0[2]);
            temp_s0_2 = *var_fp;
            var_fs0f = temp_fs1 - temp_fs0_2;
            if (temp_fs0_2 < 0.0f) {
                var_fs0f = temp_fs1;
            }
            temp_fs0f = var_fs0f * D_800C5258;
            v838.x = temp_s0_2->color.x;
            v838.y = temp_s0_2->color.y;
            v838.z = temp_s0_2->color.z;
            temp_fs0_3 = temp_fs1 - temp_fs0f;
            if (temp_s0_2 == sp8C8) {
                temp_fv0_2 = func_80278890_de(temp_s0_2);
                v8A8.x = temp_fv0_2;
                v8A8.y = temp_fv0_2;
                v8A8.z = temp_fv0_2;
                func_80271F9C_de(&sp8B8, sp8D4, temp_fs0_3 * *var_s1);
                func_80271F34_de(&v868, &v868, &sp8B8);
                func_80271F9C_de(&sp8B8, sp8D4, temp_fs0f * *var_s1);
                func_80271F34_de(&v858, &v858, &sp8B8);
            }
            func_80271F9C_de(&sp878, sp8D0, temp_fs0_3 * *var_s1);
            func_80271F34_de(&v868, &v868, &sp878);
            var_s2_2 += 3;
            var_fp += 1;
            var_s7_2 += 1;
            func_80271F9C_de(&sp878, sp8D0, temp_fs0f * *var_s1);
            func_80271F34_de(&v858, &v858, &sp878);
            var_s1 += 1;
        } while (var_s7_2 < arg1);
    }
    func_80271F9C_de(&v858, &v858.x, 0.5f);
    func_80271F34_de(&v848, &v848, &v858);
    if (v848.x < 0.0f) {
        v868.x += v848.x;
    }
    if (v848.y < 0.0f) {
        v868.y += v848.y;
    }
    if (v848.z < 0.0f) {
        v868.z += v848.z;
    }
    var_fv0 = v848.x;
    if (!(var_fv0 <= D_800C525C)) {
        var_fv0 = D_800C525C;
    }
    if (!(D_800C5260_de <= var_fv0)) {
        var_fv0 = D_800C5260_de;
    }
    temp_ft0f = temp_fs1f * D_800C525C;
    temp_ft1 = D_800C5264_de - temp_fs1f;
    var_fv0f_4 = v848.y;
    v848.x = (var_fv0 * temp_ft1) + temp_ft0f;
    if (!(var_fv0f_4 <= D_800C525C)) {
        var_fv0f_4 = D_800C525C;
    }
    var_fv0_2 = var_fv0f_4;
    if (!(D_800C5260_de <= var_fv0_2)) {
        var_fv0_2 = D_800C5260_de;
    }
    var_fv0f_5 = v848.z;
    v848.y = (var_fv0_2 * temp_ft1) + temp_ft0f;
    if (!(var_fv0f_5 <= D_800C525C)) {
        var_fv0f_5 = D_800C525C;
    }
    var_fv0_3 = var_fv0f_5;
    if (!(D_800C5260_de <= var_fv0_3)) {
        var_fv0_3 = D_800C5260_de;
    }
    var_fv0f_6 = v868.x;
    v848.z = (var_fv0_3 * temp_ft1) + temp_ft0f;
    if (!(var_fv0f_6 <= D_800C525C)) {
        var_fv0f_6 = D_800C525C;
    }
    var_fv0_4 = var_fv0f_6;
    if (!(D_800C5260_de <= var_fv0_4)) {
        var_fv0_4 = D_800C5260_de;
    }
    var_fv0f_7 = v868.y;
    v868.x = (var_fv0_4 * temp_ft1) + temp_ft0f;
    if (!(var_fv0f_7 <= D_800C525C)) {
        var_fv0f_7 = D_800C525C;
    }
    var_fv0_5 = var_fv0f_7;
    if (!(D_800C5260_de <= var_fv0_5)) {
        var_fv0_5 = D_800C5260_de;
    }
    var_fv0f_8 = v868.z;
    v868.y = (var_fv0_5 * temp_ft1) + temp_ft0f;
    if (!(var_fv0f_8 <= D_800C525C)) {
        var_fv0f_8 = D_800C525C;
    }
    if (!(D_800C5260_de <= var_fv0f_8)) {
        var_fv0f_8 = D_800C5260_de;
    }
    v868.z = (var_fv0f_8 * (D_800C5264_de - temp_fs1f)) + (temp_fs1f * D_800C525C);
    if (!(D_800C5268_de <= v848.x)) {
        var_v1 = (s32) v848.x;
    } else {
        var_v1 = (s32) (v848.x - D_800C5268_de) | 0x80000000;
    }
    arg3->ambientCopy[0] = (s8) var_v1;
    arg3->ambient[0] = (s8) var_v1;
    if (D_800C526C_de <= v848.y) {
        var_v1_2 = (s32) (v848.y - D_800C526C_de) | 0x80000000;
    } else {
        var_v1_2 = (s32) v848.y;
    }
    arg3->ambientCopy[1] = (s8) var_v1_2;
    arg3->ambient[1] = (s8) var_v1_2;
    if (D_800C5270_de <= v848.z) {
        var_v1_3 = (s32) (v848.z - D_800C5270_de) | 0x80000000;
    } else {
        var_v1_3 = (s32) v848.z;
    }
    arg3->ambientCopy[2] = (s8) var_v1_3;
    arg3->ambient[2] = (s8) var_v1_3;
    if (D_800C5274_de <= v868.x) {
        var_v1_4 = (s32) (v868.x - D_800C5274_de) | 0x80000000;
    } else {
        var_v1_4 = (s32) v868.x;
    }
    arg3->diffuseCopy[0] = (s8) var_v1_4;
    arg3->diffuse[0] = (s8) var_v1_4;
    if (D_800C5278_de <= v868.y) {
        var_v1_5 = (s32) (v868.y - D_800C5278_de) | 0x80000000;
    } else {
        var_v1_5 = (s32) v868.y;
    }
    arg3->diffuseCopy[1] = (s8) var_v1_5;
    arg3->diffuse[1] = (s8) var_v1_5;
    if (D_800C527C <= v868.z) {
        var_v1_6 = (s32) (v868.z - D_800C527C) | 0x80000000;
    } else {
        var_v1_6 = (s32) v868.z;
    }
    arg3->diffuseCopy[2] = (s8) var_v1_6;
    arg3->diffuse[2] = (s8) var_v1_6;
    arg3->direction[0] = (s8) (s32) (v828.x * D_800C5280_de);
    arg3->direction[1] = (s8) (s32) (v828.y * D_800C5280_de);
    arg3->direction[2] = (s8) (s32) (v828.z * D_800C5280_de);
}
