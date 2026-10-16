#include "span_1000/code_8027302C.h"
#include "TYPES.H"
#include "shared/func_80214624_de_closed.h"
#include "span_1000/code_8027A0F4.h"
#include "shared/world.h"
#include "span_C76B0/data.h"

typedef struct { Vec3 vector; f32 w; } Vec4;
void func_8027DAD0_de(void *, Vec3 *, Vec3 *);
void func_80272018_de(void *, void *, void *);
void func_80272E3C_de(f32 *, f32, f32, f32);
void func_802727D8_de(void *);
void func_8026F620_de(f32 *, f32 *, f32 *);
void func_8028C6D4_de(void *, Vec3 *, struct Shared_ParticleLighting *);
void func_80273760_de(void *, f32);
void func_80273448_de(void *, f32, f32, f32);
f32 func_80275DD4_de(void *, f32, f32);
f32 func_8027525C_de(void *, f32, f32);
s32 func_8027254C_de(f32 *, f32);
void func_8027347C_de(void *, f32, f32, f32);
void func_80273D6C_de(void *);
void *func_8027D97C_de(void *, void *);
void func_8027302C(f32 *, f32 *);
void func_80272C60_de(void *, f32, f32, f32);
void func_80273A98_de(void *, f32);
void func_802738C0_de(void *, f32);
void func_80272828_de(f32 *);
void func_8027027C_de(f32 *, void *);
extern f32 D_800C4CD4_de, D_800C4CD8_de, D_800C4CDC_de, D_800C4CE0_de, D_800C4CE4_de;
extern f32 D_800C9D88;
extern s32 D_800D297C;

void func_8027DD48_de(Shared_Particle *arg0, void *arg1, ParticleView *arg2, f32 arg3) {
    f32 m10[16], m50[16], m90[16], mD0[16], m110[16];
    Vec4 v150;
    Vec4 v160;
    Vec3 v170;
    Vec4 v180;
    Vec4 v190;
    Vec3 v1A0;
    Vec4 v1B0;
    Vec4 v1C0;
    Vec3 v1D0;
    Vec4 v1E0;
    f32 *temp_v0_3;
    f32 *var_a0;
    f32 age;
    f32 temp_f0;
    f32 blend_start;
    f32 case3_step;
    f32 case6_step;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f0;
    f32 var_f1;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f21;
    f32 var_f22;
    f32 var_f23;
    f32 var_f4;
    s32 temp_v0_2;
    s8 temp_a0;
    s8 temp_v0;
    s32 temp_v1;
    u16 temp_v1_2;
    struct Shared_ParticleDesc *temp_s5;
    struct Shared_ParticleDesc *interpolation;
    temp_s5 = arg0->desc;
    if (arg2 != ((void *)0)) {
        interpolation = temp_s5;
        if (temp_s5->flags & 4) {
            var_f4 = arg3;
            temp_f1 = var_f4 - D_800C4C68_de;
            blend_start = 0.0f;
            var_f0 = 0.0f;
            if (!(temp_f1 < var_f0)) {
                var_f0 = temp_f1 * D_800C4C6C_de;
                temp_f2_2 = D_800C4C70_de;
                if (var_f0 > temp_f2_2) {
                    var_f0 = temp_f2_2;
                } else {
                    if (temp_f1 < blend_start) {
                        var_f0 = 0.0f;
                    } else {
                        var_f0 = temp_f1 * D_800C4C74_de;
                    }
                }
            }
            temp_f2_2 = interpolation->distanceRange->maximum;
            blend_start = interpolation->distanceRange->minimum;
            temp_f2_2 -= blend_start;
            temp_f2_2 *= var_f0;
            blend_start += temp_f2_2;
            var_f4 *= blend_start;
            var_f4 *= D_800C4C78_de;
        } else {
            var_f4 = D_800C4C7C_de;
        }
        temp_f2 = arg2->width;
        var_f23 = var_f4 * D_800C4C88_de * (temp_f2 + ((D_800C4C80_de - temp_f2) * D_800C4C84_de));
    } else {
        var_f23 = D_800C4C8C_de;
    }
    if (temp_s5->flags & 8) {
        var_f22 = arg0->size.y * arg0->size.z * var_f23;
    } else {
        var_f22 = 0.0f;
    }
    func_8027DAD0_de(arg0, &v150.vector, &v170);
    if (!(arg0->flags & 0x30000)) {
        age = arg0->time;
        if (age > 0.0f) {
            temp_v0 = temp_s5->oscillation->ramp;
            var_f21 = D_800C4C90_de;
            if (temp_v0 != 0) {
                temp_f0 = (f32) temp_v0;
                if (age < temp_f0) {
                    var_f21 = age / temp_f0;
                }
            }
            v1D0 = arg0->unk174;
            if (arg0->amplitudeA < 0.0f) {
                v160.vector.x = 0;
                v160.vector.z = 0;
                v160.vector.y = D_800C4C94_de;
                func_80272018_de(&v1C0.vector, &v160.vector, &v1D0);
                func_80271F9C_de(&v1E0.vector, &v1C0.vector, func_802B7130_de(arg0->phaseA) * -arg0->amplitudeA * var_f21);
                func_80271F34_de(&v150.vector, &v150.vector, &v1E0.vector);
            }
            if (arg0->amplitudeB < 0.0f) {
                v160.vector.x = 0;
                v160.vector.z = 0;
                v160.vector.y = D_800C9D88;
                func_80272018_de(&v1B0.vector, &v160.vector, &v1D0);
                func_80272018_de(&v1C0.vector, &v1B0.vector, &v1D0);
                func_80271F9C_de(&v1E0.vector, &v1C0.vector, func_802B7130_de(arg0->phaseB) * -arg0->amplitudeB * var_f21);
                func_80271F34_de(&v150.vector, &v150.vector, &v1E0.vector);
            }
        }
    }
    if (arg0->desc->renderModel != 0) {
        if (arg0->unk1D0 == -7) {
            func_80272E3C_de(m10, arg0->rot.x + D_800C4C9C_de, arg0->rot.y, arg0->rot.z);
            if ((v170.x == 0.0f) && (v170.y == 0.0f) && (v170.z == 0.0f)) {
                v1A0 = arg0->unk174;
            } else {
                v1A0 = v170;
            }
            func_8027207C_de(&v1A0.x);
            v160.vector.x = 0;
            v160.vector.z = 0;
            v160.vector.y = D_800C4CA0_de;
            func_80272018_de(&v180.vector, &v160.vector, &v1A0);
            func_80272018_de(&v190.vector, &v180.vector, &v1A0);
            func_802727D8_de(m50);
            func_8027207C_de(&v180.vector.x);
            func_8027207C_de(&v190.vector.x);
            func_8027207C_de(&v1A0.x);
            m50[0] = v180.vector.x;
            m50[1] = v180.vector.y;
            m50[2] = v180.vector.z;
            m50[4] = v190.vector.x;
            m50[5] = v190.vector.y;
            m50[6] = v190.vector.z;
            m50[8] = v1A0.x;
            m50[9] = v1A0.y;
            m50[10] = v1A0.z;
            func_8026F620_de(m90, m10, m50);
        } else {
            func_80272E3C_de(m90, arg0->rot.x, arg0->rot.y + D_800C4CA4_de, arg0->rot.z);
        }
        func_8028C6D4_de(&D_8011FE88, &arg0->inst.pos, &arg0->lighting[D_800D297C]);
    } else if ((arg0->rot.x == 0.0f) && (arg0->rot.y == 0.0f)) {
        func_80273760_de(m90, arg0->rot.z);
    } else {
        func_80273760_de(m90, arg0->rot.z);
        temp_v0_2 = arg0->desc->renderModel;
        var_f0_2 = 0.0f;
        if (temp_v0_2 == 0) {
            var_f0_2 = arg0->rot.x;
        }
        var_f0_2 = -var_f0_2;
        var_f1 = 0.0f;
        if (temp_v0_2 == 0) {
            var_f1 = arg0->rot.y;
        }
        func_802733B4_de(m90, var_f0_2, -var_f1, 0.0f);
    }
    if (var_f22 != 0.0f) {
        func_802733B4_de(m90, 0.0f, var_f22, 0.0f);
        func_80273448_de(m90, 0.0f, -var_f22, 0.0f);
    }
    temp_v1 = (s8) ((u8) arg0->unk1D0 + 8);
    arg0->flags = (s32) (arg0->flags & 0xFF7FFFFF);
    switch (temp_v1) {
    case 0: goto sw_0;
    case 3: goto sw_3;
    case 5: goto sw_5;
    case 6: goto sw_6;
    case 2: case 4: case 7: goto sw_2;
    case 1: case 8: case 9: case 10: default: goto sw_done;
    }
    do {
    sw_0:
        v150.vector.x += arg0->unk174.x * D_800C4CD4_de;
        v150.vector.y += arg0->unk174.y * D_800C4CD4_de;
        v150.vector.z += arg0->unk174.z * D_800C4CD4_de;
        goto sw_done;
    sw_3:
        if (temp_s5->clampToGround != 0) {
            case3_step = D_800C4CD8_de;
            v150.vector.y = (func_80275DD4_de(((void *)0), v150.vector.x, v150.vector.z) + case3_step) < v150.vector.y
                ? v150.vector.y : func_80275DD4_de(((void *)0), v150.vector.x, v150.vector.z) + case3_step;
        }
        goto sw_done;
    sw_5:
        temp_f2_2 = func_80275DD4_de(((void *)0), v150.vector.x, v150.vector.z);
        if (temp_s5->flags & 0x400) {
            if (v150.vector.y < (temp_f2_2 + D_800C4CDC_de)) {
                v150.vector.y = temp_f2_2;
                arg0->flags = (s32) (arg0->flags | 0x800000);
            }
        } else {
            temp_f0_2 = temp_f2_2 + D_800C4CE0_de;
            temp_f1 = v150.vector.y;
            if (!(temp_f1 <= temp_f0_2)) {
                var_f0_3 = temp_f1;
                goto sw_store;
            }
            v150.vector.y = temp_f0_2;
        }
        goto sw_done;
    sw_6:
        if (temp_s5->clampToGround != 0) {
            case6_step = D_800C4CE4_de;
            v150.vector.y = v150.vector.y < (func_8027525C_de(((void *)0), v150.vector.x, v150.vector.z) - case6_step)
                ? v150.vector.y : func_8027525C_de(((void *)0), v150.vector.x, v150.vector.z) - case6_step;
        }
        goto sw_done;
    sw_2:
    sw_4:
    sw_7:
        v150.vector.y += var_f22;
        goto sw_done;
    } while (0);
    goto sw_done;
sw_store:
    v150.vector.y = var_f0_3;
sw_done:
    func_8027254C_de(&v150.vector.x, 20000.0f);
    if ((temp_s5->flags & 0x80000) && (temp_s5->animMode == 1)) {
        var_f23 = var_f23 * D_800C4CE8_de * (f32) arg0->opacity;
    }
    if (arg0->desc->renderModel != 0) {
        temp_v1_2 = arg0->inst.type;
        temp_f20 = var_f23 * arg0->size.z * D_800C4CEC_de;
        if ((temp_v1_2 == 0x40B) || (temp_v1_2 == 0x40F) || (temp_v1_2 == 0x41E) || (temp_v1_2 == 0x40B) || (temp_v1_2 == 0x436)) {
            func_8027347C_de(m90, D_800C4CF0_de, D_800C4CF0_de, D_800C4CF0_de);
        }
        func_8027347C_de(m90, arg0->size.x * temp_f20, arg0->size.y * temp_f20, temp_f20 * D_800C4CF4_de);
        func_80273D6C_de(m90);
    } else {
        temp_f20 = var_f23 * arg0->size.z;
        func_8027347C_de(m90, arg0->size.x * temp_f20, arg0->size.y * temp_f20, temp_f20 * D_800C4CF8_de);
    }
    temp_v0_3 = func_8027D97C_de(arg0, arg2);
    if (temp_v0_3 != ((void *)0)) {
        func_8026F620_de(mD0, m90, temp_v0_3);
    } else {
        func_8027302C(mD0, m90);
    }
    func_80273448_de(mD0, v150.vector.x, v150.vector.y, v150.vector.z);
    if (arg0->flags & 0x20000) {
        temp_a0 = arg0->unk1D1;
        if (temp_a0 != 0) {
            temp_f20_3 = (f32) temp_a0 * D_800C4CFC_de;
            temp_f20_4 = temp_f20_3 * temp_f20_3;
            temp_f21 = temp_f20_4 * D_800C4D00_de;
            func_80272C60_de(m110, 0.0f, 0.0f, -66.56f);
            func_80273A98_de(m110, temp_f21 * (func_802B7130_de(temp_f20_4 * D_800C4D04_de) * D_800C4D08_de));
            func_802738C0_de(m110, temp_f21 * func_802B7130_de(temp_f20_4 * D_800C4D0C_de));
            func_80273448_de(m110, 0.0f, 0.0f, 66.56f);
            func_8026F620_de(m10, m110, mD0);
            func_80272828_de(m10);
            var_a0 = m10;
        } else {
            goto block_81;
        }
    } else {
block_81:
        func_80272828_de(mD0);
        var_a0 = mD0;
    }
    func_8027027C_de(var_a0, arg1);
}
