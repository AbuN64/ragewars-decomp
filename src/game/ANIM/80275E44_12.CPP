#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS4_2.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/UNUSED.H"
#include "FX_2/80271B18.H"

#ifdef NON_MATCHING
#define SK_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
typedef struct SkelVec { f32 x; f32 y; f32 z; } SkelVec;
extern f32 D_800C4A60_de, D_800C4A64_de, D_800C4A68_de, D_800C4A6C_de, D_800C4A70_de, D_800C4A74_de;
extern f32 D_800C4A78_de, D_800C4A7C_de, D_800C4A80_de, D_800C4A84_de, D_800C4A88_de, D_800C4A8C_de;
extern f32 D_800C4A98_de, D_800C4AB0_de, D_800C4AB4_de, D_800C4AB8_de, D_800C4ABC_de;
extern s32 D_801462C8;
extern void func_802727D8_de(void *);
extern void func_80273C68_de(void *, f32);
extern void func_80273A98_de(void *, f32);
extern void func_80272A10_de(void *, void *, void *);
extern void func_802735A8_de(void *, f32, f32, f32);
extern void func_802738C0_de(void *, f32);
extern void func_80273448_de(void *, f32, f32, f32);
extern void func_8026EF58_de(void *, void *);
extern void func_80275954_de(void *, s32, void *);
void func_80276CB0_de(u8 *self, u8 *src) {
    SkelVec translation;
    SkelVec rotation;
    SkelVec scale;
    SkelVec corners[8];
    SkelVec up;
    SkelVec tilt;
    SkelVec probe;
    u8 *matrix;
    s32 inside;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    SK_FIELD(self, u8, 0xBB) = SK_FIELD(src, u8, 0x2F);
    translation.x = SK_FIELD(src, s32, 0) * 2.38418579e-05f;
    translation.y = SK_FIELD(src, s32, 4) * 2.38418579e-05f;
    translation.z = SK_FIELD(src, s32, 8) * 2.38418579e-05f;
    if (SK_FIELD(self, u8, 0xBB) != 1) {
        rotation.x = SK_FIELD(src, s32, 0xC) * 9.31322575e-09f;
        rotation.y = SK_FIELD(src, s32, 0x10) * 9.31322575e-09f;
        rotation.z = SK_FIELD(src, s32, 0x14) * 9.31322575e-09f;
    } else {
        up.x = 0;
        up.y = (-1.0f);
        up.z = 0;
        tilt.y = SK_FIELD(src, s32, 0xC) * 9.31322575e-09f;
        tilt.z = SK_FIELD(src, s32, 0x10) * 9.31322575e-09f;
        matrix = self + 0x60;
        func_802727D8_de(matrix);
        func_80273C68_de(matrix, tilt.y);
        func_80273A98_de(matrix, tilt.z);
        func_80272A10_de(matrix, &up, self + 0x14);
        rotation.x = 0;
        rotation.y = 0;
        rotation.z = 0;
    }
    inside = 1;
    if (rotation.x < 0) {
        if (-rotation.x > 0.00999999978f) {
            inside = 0;
        }
    } else if (rotation.x > 0.00999999978f) {
        inside = 0;
    }
    if (rotation.y < 0) {
        if (-rotation.y > 0.00999999978f) {
            inside = 0;
        }
    } else if (rotation.y > 0.00999999978f) {
        inside = 0;
    }
    SK_FIELD(self, u8, 0xB9) = 0;
    if (rotation.z < 0) {
        if (-rotation.z > 0.00999999978f) {
            inside = 0;
        }
    } else if (rotation.z > 0.00999999978f) {
        inside = 0;
    }
    if (inside != 0) {
        SK_FIELD(self, u8, 0xB9) = 1;
    }
    scale.x = SK_FIELD(src, s32, 0x18) * 2.38418579e-05f;
    scale.y = SK_FIELD(src, s32, 0x1C) * 2.38418579e-05f;
    scale.z = SK_FIELD(src, s32, 0x20) * 2.38418579e-05f;
    SK_FIELD(self, f32, 0) = (f32)SK_FIELD(src, s32, 0x24) * 2 * 4.65661287e-10f;
    SK_FIELD(self, f32, 4) = (f32)SK_FIELD(src, s32, 0x28) * 2 * 4.65661287e-10f;
    if (D_801462C8 & 0x4000) {
        SK_FIELD(self, s32, 8) = 0;
        SK_FIELD(self, s32, 0xC) = 0;
        SK_FIELD(self, s32, 0x10) = 0;
    } else {
        SK_FIELD(self, f32, 8) = (f32)SK_FIELD(src, u32, 0x3C) * 2.37487257e-06f;
        SK_FIELD(self, f32, 0xC) = (f32)SK_FIELD(src, u32, 0x40) * 2.37487257e-06f;
        SK_FIELD(self, f32, 0x10) = (f32)SK_FIELD(src, u32, 0x44) * 2.37487257e-06f;
    }
    matrix = self + 0x60;
    SK_FIELD(self, u8, 0xB8) = SK_FIELD(src, u8, 0x37);
    SK_FIELD(self, u8, 0xBA) = SK_FIELD(src, u8, 0x3B);
    SK_FIELD(self, u8, 0xBD) = SK_FIELD(src, u8, 0x4B);
    func_802727D8_de(matrix);
    func_802735A8_de(matrix, scale.x, scale.y, scale.z);
    func_80273C68_de(matrix, rotation.z);
    func_80273A98_de(matrix, rotation.y);
    func_802738C0_de(matrix, rotation.x);
    func_80273448_de(matrix, translation.x, translation.y, translation.z);
    func_8026EF58_de(self + 0x20, matrix);
    for (i = 0; i < 8; i++) {
        x = (i & 1) ? (-1.0f) : 1.0f;
        y = (i & 2) ? (-1.0f) : 1.0f;
        z = (i & 4) ? (-1.0f) : 1.0f;
        probe.x = x;
        probe.y = y;
        probe.z = z;
        func_80272A10_de(self + 0x60, &probe, &corners[i]);
    }
    func_80275954_de(self + 0xA0, 8, corners);
}
#else
INCLUDE_ASM("span_1000", func_80276CB0_de);
#endif





s32 func_80277128_de(ObjectRecAtBC *arg0, u32 arg1, u32 arg2, u32 arg3,
                  CVector3 *arg4, f32 *arg5) {
    f32 temp_f0;
    f32 var_f0;
    f32 var_f1;
    f32 var_f20;
    f32 var_f3;
    u8 temp_v1;

    var_f3 = *(f32 *)&arg1;
    var_f20 = 0.0f;
    if (!(D_800C4AC0_de <= var_f3) && !(var_f3 <= D_800C4AC4_de) &&
        !(D_800C4AC0_de <= *(f32 *)&arg2) && !(*(f32 *)&arg2 <= D_800C4AC4_de) &&
        !(D_800C4AC0_de <= *(f32 *)&arg3) && !(*(f32 *)&arg3 <= D_800C4AC4_de)) {
        temp_v1 = arg0->shape;
        switch (temp_v1) {
        case 0:
            var_f20 = (var_f3 * var_f3) + (*(f32 *)&arg2 * *(f32 *)&arg2) +
                      (*(f32 *)&arg3 * *(f32 *)&arg3);
            if (!(D_800C4AC0_de < var_f20)) {
                var_f20 = D_800CD3F8[(s32)(var_f20 * D_800C4AC8_de)];
                goto shared;
            }
            goto fail;
        case 2:
            if (!(var_f3 <= 0.0f)) {
                var_f20 = (*(f32 *)&arg2 * *(f32 *)&arg2) +
                          (*(f32 *)&arg3 * *(f32 *)&arg3);
                if (!((var_f3 * var_f3) < var_f20)) {
                    var_f20 = D_800CD4FC[(s32)(var_f20 * D_800C4ACC_de)];
                    var_f20 /= var_f3;
                    goto shared;
                }
            }
            goto fail;
        case 1:
            if (var_f3 < 0.0f) {
                var_f3 = -var_f3;
            }
            var_f0 = *(f32 *)&arg2;
            *(f32 *)&arg1 = var_f3;
            if (var_f0 < 0.0f) {
                var_f0 = -var_f0;
            }
            var_f1 = *(f32 *)&arg3;
            *(f32 *)&arg2 = var_f0;
            if (var_f1 < 0.0f) {
                var_f1 = -var_f1;
            }
            *(f32 *)&arg3 = var_f1;
            var_f20 = var_f1;
            if (!(var_f0 <= var_f20)) {
                var_f20 = var_f0;
            }
            if (!(var_f3 <= var_f20)) {
                var_f20 = var_f3;
            }
            goto shared;
        default:
            goto shared;
        }
shared:
        var_f20 = D_800C4AD0_de - var_f20;
        temp_f0 = arg0->falloff;
        if (var_f20 < temp_f0) {
            var_f20 /= temp_f0;
        } else {
            var_f20 = D_800C4AD0_de;
        }
        if (arg0->shape == 1) {
            *arg4 = arg0->axis;
        } else {
            *arg4 = *(CVector3 *)&arg1;
        }
        func_8027207C_de(arg4);
        *arg5 = var_f20;
        return 1;
    } else {
fail:
        arg4->y = 0.0f;
        arg4->z = 0.0f;
        arg4->x = D_800C4AD4_de;
        *arg5 = 0.0f;
        return 0;
    }
}
