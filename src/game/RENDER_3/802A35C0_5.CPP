#include "include_asm.h"
#include "RENDER_4/8026AC38.H"
#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/UNUSED.H"
#include "RENDER_3/802A35C0.H"
#include "COMMON/EXTERNS_6.H"

/* Animator exists in COMMON/UNUSED.H; active owning contract is pending. */




void func_802A4A60_de(Animator *a) {
    s32 next;
    f32 op0;
    f32 op1;
    f32 op2;
    f32 op3;
    f32 op4;
    f32 op5;

    next = 0;
    switch (a->mode) {
    case 0:
        if (a->loop != 0) {
            next = 1;
        }
        break;
    case 1:
        a->time -= D_800D2988;
        if (a->time < 0.0f) {
            next = 1;
        }
        break;
    case 4:
        a->time += D_800D2988;
        if (a->valueDuration <= a->time) {
            a->time = a->valueDuration;
            next = 1;
        }
        op1 = a->time / a->valueDuration;
        op0 = 1.0f - op1;
        a->value = op0 * a->valueFrom + op1 * a->valueTo;
        break;
    case 6:
        a->time += D_800D2988;
        if (a->colourDuration <= a->time) {
            a->time = a->colourDuration;
            next = 1;
        }
        op1 = a->time / a->colourDuration;
        op0 = 1.0f - op1;
        a->rgb[0] = op0 * a->rgbFrom[0] + op1 * a->rgbTo[0];
        a->rgb[1] = op0 * a->rgbFrom[1] + op1 * a->rgbTo[1];
        a->rgb[2] = op0 * a->rgbFrom[2] + op1 * a->rgbTo[2];
        a->alpha = op0 * a->alphaFrom + op1 * a->alphaTo;
        break;
    }
    while (next) {
        a->mode = *a->script++;
        next = 0;
        switch (a->mode) {
        case 0:
            a->script = 0;
            a->loop = 0;
            break;
        case 1:
            op5 = *a->script++;
            a->time = op5;
            break;
        case 2:
            op0 = *a->script++;
            op1 = *a->script++;
            a->mode = 1;
            a->time = func_80274A90_de(op0, op1);
            break;
        case 3:
            next = 1;
            op4 = *a->script++;
            a->value = op4;
            break;
        case 4:
            op4 = *a->script++;
            op5 = *a->script++;
            a->valueFrom = a->value;
            a->time = 0.0f;
            a->valueTo = op4;
            a->valueDuration = op5;
            break;
        case 5:
            next = 1;
            op2 = *a->script++;
            op3 = *a->script++;
            op1 = *a->script++;
            op4 = *a->script++;
            a->rgb[0] = op2;
            a->rgb[1] = op3;
            a->rgb[2] = op1;
            a->alpha = op4;
            break;
        case 6:
            op2 = *a->script++;
            op3 = *a->script++;
            op1 = *a->script++;
            op4 = *a->script++;
            op5 = *a->script++;
            a->rgbFrom[0] = a->rgb[0];
            a->rgbFrom[1] = a->rgb[1];
            a->rgbFrom[2] = a->rgb[2];
            a->alphaFrom = a->alpha;
            a->time = 0.0f;
            a->rgbTo[0] = op2;
            a->rgbTo[1] = op3;
            a->rgbTo[2] = op1;
            a->alphaTo = op4;
            a->colourDuration = op5;
            break;
        case 7:
            next = 1;
            a->script++;
            break;
        case 8:
            next = 1;
            a->script = a->loop;
            break;
        }
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"

extern f32 D_800C5E64_de, D_800C5E68_de, D_800C5E6C_de, D_800C5E70_de, D_800C5E74_de;
extern f32 D_800C5E78_de, D_800C5E7C_de, D_800C5E80_de, D_800C5E84_de;
typedef struct { f32 current, target; } FadeAlpha;

void func_802A4DE8_de(void) {
    FadeAlpha *p;
    f32 tgt, cur, c;
    s32 equal;
    c = D_800D15E4[0];
    if (c < 0.0f) D_800D15E4[0] = 0.0f; else if (D_800C5E64_de < c) D_800D15E4[0] = D_800C5E64_de;
    c = D_800D15E4[1];
    if (c < 0.0f) D_800D15E4[1] = 0.0f; else if (D_800C5E68_de < c) D_800D15E4[1] = D_800C5E68_de;
    c = D_800D15E4[2];
    if (c < 0.0f) D_800D15E4[2] = 0.0f; else if (D_800C5E6C_de < c) D_800D15E4[2] = D_800C5E6C_de;
    c = D_800D15E4[3];
    if (c < 0.0f) D_800D15E4[3] = 0.0f; else if (D_800C5E70_de < c) D_800D15E4[3] = D_800C5E70_de;
    c = D_800D15E4[4];
    if (c < 0.0f) D_800D15E4[4] = 0.0f; else if (D_800C5E74_de < c) D_800D15E4[4] = D_800C5E74_de;
    p = (FadeAlpha *)&D_800D15E4[3];
    tgt = p->target;
    cur = p->current;
    if (tgt == D_800C5E78_de) {
        if (cur == 0.0f) { D_800D15E0 = 0; return; }
        if (tgt == D_800C5E7C_de) goto n1;
    }
    if (cur == 0.0f) {
        D_800D15E0 = 1;
        D_800D15E4[3] = D_800D15E4[4];
        return;
    }
n1:
    if (tgt == D_800C5E80_de) {
        if (cur != 0.0f) { D_800D15E0 = 3; return; }
        if (tgt == D_800C5E84_de) return;
    }
    if (cur != 0.0f) D_800D15E0 = 6;
}
#else
INCLUDE_ASM("span_1000", func_802A4DE8_de);
#endif
