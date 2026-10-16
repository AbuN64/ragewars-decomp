#include "span_1000/code_8023A284.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "gbi.h"
#include "gfx.h"
#include "n64sdk.h"
#include "span_1000/code_80255BEC.h"
#include "span_C76B0/data.h"
#include "TYPES.H"
#include "shared/func_8021E2A0_de_closed.h"
#include "span_1000/code_80291054.h"

/* Sorts and draws scene translucent objects in two groups around the view depth. */










extern void func_8026925C_de(s32);

extern void func_802852C0_de(char *, u32, u32, void *, void *);

extern void func_8023A4E0_de(ObjectRecAt220 *, ClipView *);

extern void func_80295E84_de(s32 *arg0, s32 arg1);

/* Updates a rotor: while the control mask bit is held its throttle at 0x208 rises by the descriptor rate up
 * to D_800C86E0, otherwise it falls to zero (returning 1 once idle); the value phase advances, the two wrap
 * angles at 0x1C and 0x20 advance and wrap at D_800C86E8, and the speed at 0x210 becomes the descriptor
 * base plus trim, plus the boost when requested and the host is not stalled, or else the host's speed
 * scaled by the descriptor (flag 1) or the fallback speed (flag 2). Returns 0 while active. */











void func_8023B3F8_de(Scene *scene, ClipView *view) {
    ObjectRecAt220 *near[4];
    ObjectRecAt220 *far[4];
    ObjectRecAt220 *object;
    s32 nearCount;
    s32 farCount;
    s32 i;

    if (scene->count == 0 || view->hidden != 0) {
        return;
    }
    gDPPipeSync(D_80110634++);
    gSPMatrix(D_80110634++, (u32)(((u32)&D_80142C60)), G_MTX_LOAD);
    gSPMoveWord(D_80110634++, G_MW_CLIP, 4, (u32)((2)));
    gSPMoveWord(D_80110634++, G_MW_CLIP, 12, (u32)((2)));
    gSPMoveWord(D_80110634++, G_MW_CLIP, 20, (u32)((0xFFFE)));
    gSPMoveWord(D_80110634++, G_MW_CLIP, 28, (u32)((0xFFFE)));
    gSPGeometryMode(D_80110634++, G_FOG, 0);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    func_8026925C_de(0xD);
    gSPGeometryMode(D_80110634++, G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN, 0);
    gSPGeometryMode(D_80110634++, 0, G_SHADE | G_SHADING_SMOOTH);
    gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    nearCount = 0;
    farCount = 0;
    for (object = scene->objects; object != 0; object = object->next) {
        if (object->depth > view->depth) {
            near[nearCount++] = object;
        } else {
            far[farCount++] = object;
        }
    }
    func_802852C0_de((char *)near, nearCount, 4, D_0023B94C, D_0023B938);
    func_802852C0_de((char *)far, farCount, 4, D_0023B978_de, D_0023B938);
    for (i = 0; i < nearCount; i++) {
        func_8023A4E0_de(near[i], view);
    }
    for (i = 0; i < farCount; i++) {
        func_8023A4E0_de(far[i], view);
    }
}

void func_8023B694_de(Effect *effect, s16 *definition, s16 mask, f32 scale,
                   f32 offset0, f32 offset1, f32 offset2) {
    effect->definition = definition;
    effect->mask = mask;
    func_80295E84_de(&effect->resource, *definition);
    effect->angle0 = 0;
    effect->angle1 = 0;
    effect->timer = 0;
    effect->velocity = 0;
    effect->scale = scale;
    effect->offset0 = offset0;
    effect->offset1 = offset1;
    effect->offset2 = offset2;
}

s32 func_8023B718_de(Rotor *rotor, s32 mask, f32 fallback, s32 boosting, f32 boost, Host *host) {
    DescriptorRecAt29 *descriptor;
    f32 throttle;
    f32 value;
    f32 angle;
    f32 speed;
    f32 lowered;
    f32 zero;
    f32 wrap;

    descriptor = rotor->descriptor;
    if (rotor->mask & mask) {
        throttle = rotor->throttle + descriptor->throttleRate * D_800D2988;
        if (D_800C86E0 < throttle) {
            throttle = D_800C86E0;
        }
        rotor->throttle = throttle;
    } else {
        zero = 0.0f;
        value = rotor->throttle;
        if (value == zero) {
            return 1;
        }
        lowered = value - descriptor->throttleRate * D_800D2988;
        if (lowered < zero) {
            lowered = zero;
        }
        rotor->throttle = lowered;
    }
    rotor->phase += D_800D2988 * descriptor->phaseRate * rotor->phaseScale;
    value = D_800D2988 * D_800CD744_de * descriptor->spinRate;
    angle = rotor->angleA + value * D_800C35F4_de;
    wrap = D_800C86E8;
    rotor->angleA = angle;
    if (wrap < angle) {
        rotor->angleA = angle - wrap;
    }
    angle = rotor->angleB + value * D_800C35FC_de;
    rotor->angleB = angle;
    if (wrap < angle) {
        rotor->angleB = angle - wrap;
    }
    speed = descriptor->baseSpeed + rotor->trim;
    if (boosting != 0 && host->stalled == 0) {
        speed += boost;
    } else if (descriptor->flags & 1) {
        speed += host->speed * descriptor->hostScale;
    } else if (descriptor->flags & 2) {
        speed += fallback;
    }
    rotor->speed = speed;
    return 0;
}

void *func_8023B8AC_de(struct IntegerState8A4 *arg0) {
    void *temp_s0;

    temp_s0 = arg0->unk_8A0.head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&arg0->unk_8A0, temp_s0);
        func_80255D14_de(&arg0->unk_8B4, temp_s0);
    }
    return temp_s0;
}
