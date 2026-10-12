#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/world.h"
#include "span_1000/code_8027A0F4.h"
#include "span_1000/code_8028B64C.h"
#include "span_C76B0/data.h"
#include "stddef.h"
#include "types.h"
void func_8027DAD0_de(void *actor, Vec3 *outPosition, Vec3 *outHeading);
void func_80272018_de(Vec3 *out, Vec3 *a, Vec3 *b);
void func_80272E3C_de(f32 *m, f32 x, f32 y, f32 z);
void func_802727D8_de(void *arg0);
void func_8026F620_de(f32 *out, f32 *left, f32 *right);
void func_8028C6D4_de(void *owner, Vec3 *position, void *out);
void func_80273760_de(void *arg0, f32 arg1);
void func_802733B4_de(void *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80273448_de(char *object, float x, float y, float z);
f32 func_80275DD4_de(Node75 *node, f32 x, f32 z);
f32 func_8027525C_de(Node75_func_802750B0_de *node, f32 x, f32 z);
s32 func_8027254C_de(f32 *arg0, f32 arg1);
void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
void func_80273D6C_de(void *object);
void *func_8027D97C_de(void *arg0, void *arg1);
void func_8027302C(float *arg0, float *arg1);
void func_80272C60_de(void *arg0, f32 arg1, f32 arg2, f32 arg3);
void func_80273A98_de(void *arg0, f32 arg1);
void func_802738C0_de(void *arg0, f32 arg1);
void func_80272828_de(f32 *arg0);
void func_8027027C_de(f32 *src, PackedMatrixWords *dst);



extern f32 D_800C4CD4_de;
extern f32 D_800C4CD8_de;
extern f32 D_800C4CDC_de;
extern f32 D_800C4CE0_de;
extern f32 D_800C4CE4_de;
extern f32 D_800C9D88;
extern s32 D_800D297C;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x1f0, 0x1f4, 0x1f8, 0x1fc, 0x200, 0x204, 0x208, 0x20c, 0x210, 0x220, 0x224, 0x230, 0x234], gap at: 0x214. */
void func_8027DD48_de(Shared_Particle *arg0, PackedMatrixWords *arg1, void *arg2, f32 arg3) {
    Object_func_804220A8_de *camera = arg2;
    f32 sp10[16], sp50[16], sp90[16], spD0[16], sp110[16];
    Vec3 sp150, axis, heading, basis, sp170, sp180, sp190;
    Vec3 sp1B0, sp1C0, sp1E0;
    f32 *temp_v0_3;
    f32 *var_a0;
    f32 temp_fs0;
    f32 temp_fs0_2;
    f32 temp_fs0_3;
    f32 temp_fs0_4;
    f32 temp_fs0_5;
    f32 temp_fs0_6;
    f32 temp_fs0f;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 var_fs0f;
    f32 var_fs1;
    f32 var_fs1f;
    f32 var_ft0;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0f;
    s32 temp_v0_2;
    s8 temp_a0;
    s8 temp_v0;
    s8 temp_v1;
    u16 temp_v1_2;
    Shared_ParticleDesc *temp_s5;

    temp_s5 = arg0->desc;
    if (arg2 != NULL) {
        if (temp_s5->flags & 4) {
            temp_fv0f = arg3 - D_800C4C68_de;
            var_fv0 = 0.0f;
            if (!(temp_fv0f < 0.0f)) {
                var_fv0 = D_800C4C70_de;
                if (!(D_800C4C70_de < (temp_fv0f * D_800C4C6C_de))) {
                    var_fv0 = 0.0f;
                    if (!(temp_fv0f < 0.0f)) {
                        var_fv0 = temp_fv0f * D_800C4C74_de;
                    }
                }
            }
            var_ft0 = arg3 * (temp_s5->distanceRange->minimum + ((temp_s5->distanceRange->maximum - temp_s5->distanceRange->minimum) * var_fv0)) * D_800C4C78_de;
        } else {
            var_ft0 = D_800C4C7C_de;
        }
        temp_fv1 = camera->width;
        var_fs1f = var_ft0 * D_800C4C88_de * (temp_fv1 + ((D_800C4C80_de - temp_fv1) * D_800C4C84_de));
    } else {
        var_fs1f = D_800C4C8C_de;
    }
    if (temp_s5->flags & 8) {
        var_fs1 = arg0->size.y * arg0->size.z * var_fs1f;
    } else {
        var_fs1 = 0.0f;
    }
    func_8027DAD0_de(arg0, &sp150, &sp170);
    if (!(arg0->flags & 0x30000)) {
        temp_fv0f_2 = arg0->time;
        if (temp_fv0f_2 > 0.0f) {
            temp_v0 = temp_s5->oscillation->ramp;
            var_fs0f = D_800C4C90_de;
            if (temp_v0 != 0) {
                temp_fv0 = (f32) temp_v0;
                if (temp_fv0f_2 < temp_fv0) {
                    var_fs0f = temp_fv0f_2 / temp_fv0;
                }
            }
            heading.x = arg0->unk174.x;
            heading.y = arg0->unk174.y;
            heading.z = arg0->unk174.z;
            if (arg0->amplitudeA < 0.0f) {
                axis.x = 0;
                axis.z = 0;
                axis.y = D_800C4C94_de;
                func_80272018_de(&sp1C0, &axis, &heading);
                func_80271F9C_de(&sp1E0, &sp1C0, func_802B7130_de(arg0->phaseA) * -arg0->amplitudeA * var_fs0f);
                func_80271F34_de(&sp150, &sp150, &sp1E0);
            }
            if (arg0->amplitudeB < 0.0f) {
                axis.x = 0;
                axis.z = 0;
                axis.y = D_800C9D88;
                func_80272018_de(&sp1B0, &axis, &heading);
                func_80272018_de(&sp1C0, &sp1B0, &heading);
                func_80271F9C_de(&sp1E0, &sp1C0, func_802B7130_de(arg0->phaseB) * -arg0->amplitudeB * var_fs0f);
                func_80271F34_de(&sp150, &sp150, &sp1E0);
            }
        }
    }
    if (arg0->desc->renderModel != 0) {
        if (arg0->unk1D0 == -7) {
            func_80272E3C_de(sp10, arg0->rot.x + D_800C4C9C_de, arg0->rot.y, arg0->rot.z);
            if ((sp170.x == 0.0f) && (sp170.y == 0.0f) && (sp170.z == 0.0f)) {
                basis.x = arg0->unk174.x;
                basis.y = arg0->unk174.y;
                basis.z = arg0->unk174.z;
            } else {
                basis.x = sp170.x;
                basis.y = sp170.y;
                basis.z = sp170.z;
            }
            func_8027207C_de(&basis.x);
            axis.x = 0;
            axis.z = 0;
            axis.y = D_800C4CA0_de;
            func_80272018_de(&sp180, &axis, &basis);
            func_80272018_de(&sp190, &sp180, &basis);
            func_802727D8_de(sp50);
            func_8027207C_de(&sp180.x);
            func_8027207C_de(&sp190.x);
            func_8027207C_de(&basis.x);
            sp50[0] = sp180.x;
            sp50[1] = sp180.y;
            sp50[2] = sp180.z;
            sp50[4] = sp190.x;
            sp50[5] = sp190.y;
            sp50[6] = sp190.z;
            sp50[8] = basis.x;
            sp50[9] = basis.y;
            sp50[10] = basis.z;
            func_8026F620_de(sp90, sp10, sp50);
        } else {
            func_80272E3C_de(sp90, arg0->rot.x, arg0->rot.y + D_800C4CA4_de, arg0->rot.z);
        }
        func_8028C6D4_de(&D_8011FE88, &arg0->inst.pos, &arg0->lighting[D_800D297C]);
    } else if ((arg0->rot.x == 0.0f) && (arg0->rot.y == 0.0f)) {
        func_80273760_de(sp90, arg0->rot.z);
    } else {
        func_80273760_de(sp90, arg0->rot.z);
        temp_v0_2 = arg0->desc->renderModel;
        var_fv0_2 = 0.0f;
        if (temp_v0_2 == 0) {
            var_fv0_2 = arg0->rot.x;
        }
        var_fv0f = 0.0f;
        if (temp_v0_2 == 0) {
            var_fv0f = arg0->rot.y;
        }
        func_802733B4_de(sp90, -var_fv0_2, -var_fv0f, 0.0f);
    }
    if (var_fs1 != 0.0f) {
        func_802733B4_de(sp90, 0.0f, var_fs1, 0.0f);
        func_80273448_de((char *)sp90, 0.0f, -var_fs1, 0.0f);
    }
    temp_v1 = (u8) arg0->unk1D0 + 8;
    arg0->flags &= 0xFF7FFFFF;
    if ((u32) temp_v1 < 0xBU) {
        switch (temp_v1) {
        case 0:
            sp150.x = sp150.x + (arg0->unk174.x * D_800C4CD4_de);
            sp150.y += arg0->unk174.y * D_800C4CD4_de;
            sp150.z += arg0->unk174.z * D_800C4CD4_de;
            break;
        case 3:
            if (temp_s5->clampToGround != 0) {
                temp_fs0 = D_800C4CD8_de;
                if ((func_80275DD4_de(NULL, sp150.x, sp150.z) + temp_fs0) < sp150.y) {
                    var_fv0_3 = sp150.y;
                } else {
                    var_fv0_3 = func_80275DD4_de(NULL, sp150.x, sp150.z) + temp_fs0;
                }
block_61:
                sp150.y = var_fv0_3;
            }
            break;
        case 5:
            temp_fv1_2 = func_80275DD4_de(NULL, sp150.x, sp150.z);
            if (temp_s5->flags & 0x400) {
                if (sp150.y < (temp_fv1_2 + D_800C4CDC_de)) {
                    sp150.y = temp_fv1_2;
                    arg0->flags |= 0x800000;
                }
            } else {
                temp_fv0_2 = temp_fv1_2 + D_800C4CE0_de;
                if (!(sp150.y <= temp_fv0_2)) {
                    var_fv0_3 = sp150.y;
                    goto block_61;
                }
                sp150.y = temp_fv0_2;
            }
            break;
        case 6:
            if (temp_s5->clampToGround != 0) {
                temp_fs0_2 = D_800C4CE4_de;
                if (sp150.y < (func_8027525C_de(NULL, sp150.x, sp150.z) - temp_fs0_2)) {
                    var_fv0_3 = sp150.y;
                } else {
                    var_fv0_3 = func_8027525C_de(NULL, sp150.x, sp150.z) - temp_fs0_2;
                }
                goto block_61;
            }
            break;
        case 2:
        case 4:
        case 7:
            var_fv0_3 = sp150.y + var_fs1;
            goto block_61;
        }
    }
    func_8027254C_de(&sp150.x, 20000.0f);
    if ((temp_s5->flags & 0x80000) && (temp_s5->animMode == 1)) {
        var_fs1f = var_fs1f * D_800C4CE8_de * (f32) arg0->opacity;
    }
    if (arg0->desc->renderModel != 0) {
        temp_v1_2 = arg0->inst.type;
        temp_fs0_3 = var_fs1f * arg0->size.z * D_800C4CEC_de;
        if ((temp_v1_2 == 0x40B) || (temp_v1_2 == 0x40F) || (temp_v1_2 == 0x41E) || (temp_v1_2 == 0x40B) || (temp_v1_2 == 0x436)) {
            func_8027347C_de(sp90, D_800C4CF0_de, D_800C4CF0_de, D_800C4CF0_de);
        }
        func_8027347C_de(sp90, arg0->size.x * temp_fs0_3, arg0->size.y * temp_fs0_3, temp_fs0_3 * D_800C4CF4_de);
        func_80273D6C_de(sp90);
    } else {
        temp_fs0_4 = var_fs1f * arg0->size.z;
        func_8027347C_de(sp90, arg0->size.x * temp_fs0_4, arg0->size.y * temp_fs0_4, temp_fs0_4 * D_800C4CF8_de);
    }
    temp_v0_3 = func_8027D97C_de(arg0, arg2);
    if (temp_v0_3 != NULL) {
        func_8026F620_de(spD0, sp90, temp_v0_3);
    } else {
        func_8027302C(spD0, sp90);
    }
    func_80273448_de((char *)spD0, sp150.x, sp150.y, sp150.z);
    if (arg0->flags & 0x20000) {
        temp_a0 = arg0->unk1D1;
        if (temp_a0 != 0) {
            temp_fs0_5 = (f32) temp_a0 * D_800C4CFC_de;
            temp_fs0_6 = temp_fs0_5 * temp_fs0_5;
            temp_fs0f = temp_fs0_6 * D_800C4D00_de;
            func_80272C60_de(sp110, 0, 0, -66.56f);
            func_80273A98_de(sp110, temp_fs0f * (func_802B7130_de(temp_fs0_6 * D_800C4D04_de) * D_800C4D08_de));
            func_802738C0_de(sp110, temp_fs0f * func_802B7130_de(temp_fs0_6 * D_800C4D0C_de));
            func_80273448_de((char *)sp110, 0.0f, 0.0f, 66.56f);
            func_8026F620_de(sp10, sp110, spD0);
            func_80272828_de(sp10);
            var_a0 = sp10;
        } else {
            goto block_81;
        }
    } else {
block_81:
        func_80272828_de(spD0);
        var_a0 = spD0;
    }
    func_8027027C_de(var_a0, arg1);
}
