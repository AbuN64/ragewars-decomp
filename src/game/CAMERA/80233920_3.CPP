#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WORLD.H"
#include "COMMON/VIEWFLAGS.H"
#include "CAMERA/80233920.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "RENDER_4/8028FD2C_6.H"

extern s32 D_800CD730;
extern void *func_8028B2F8_de(Shared_World *, u16 *);

void func_802343C8_de(View *self) {
    u8 target[4];
    ColorBlendRecord *rec;
    SharedPlayer *node;
    SharedPlayer *ownerNode;
    u32 hold;
    u32 freeze;
    u32 fadeA;
    u32 fadeB;
    u32 endN;
    f32 endA;
    f32 endB;
    f32 t;
    f32 k;
    s32 i;
    u16 *key = self->key;

    if (key == 0) {
        if (&D_8011FE88 == 0 || D_8011FE88.mode == 0) {
            return;
        }
        rec = (void *)(func_8028FDB4_de(D_8011FE88.modelSections, 0) + 8);
    } else {
        rec = func_8028B2F8_de(&D_8011FE88, key);
        if (rec == 0) {
            return;
        }
    }

    hold = 0;
    fadeA = hold;
    fadeB = hold;
    freeze = hold;
    for (node = D_80145060.actorList; node != 0; node = node->views16E0.view16E0_1.next) {
        if (node->views5DC.view5DC_0.unk5DC == self) {
            ownerNode = node;
            goto found;
        }
    }
    node = 0;
    ownerNode = 0;
found:
    if (node != 0) {
        hold = 0;
        if ((ownerNode->views5E8.view664_27.unk664 & 0x40) ||
            (ownerNode->views1C.view38_3.flags & 0x1000)) {
            hold = 1;
        }
        freeze = node->views1C.view38_3.flags & 0x20000;
        fadeA = 0;
        if (node->views1C.view38_3.flags & 0x8000) {
            fadeA = fadeA < hold;
        }
        fadeB = 0;
        if (node->views1C.view38_3.flags & 0x10000) {
            fadeB = fadeB < hold;
        }
    }

    if (key != 0 && (*key != self->lastKey || hold != 0 || freeze != 0)) {
        if (self->lastKey == -1 || hold != 0 || freeze != 0) {
            self->blendTime = 1.0f;
        } else {
            self->blendTime = 0.0f;
        }
        self->lastKey = *key;
        for (i = 0; i < 4; i++) {
            self->secondaryColor[i] = self->color[i];
        }
        self->previousA = self->blendA;
        self->previousN = self->blendN;
        self->previousB = self->blendB;
    }

    if (hold != 0 || freeze != 0 || fadeA != 0 || fadeB != 0) {
        for (i = 0; i < 4; i++) {
            target[i] = rec->heldColor[i];
        }
        endN = rec->heldN;
        endA = rec->heldA;
        endB = rec->heldB;
    } else {
        for (i = 0; i < 3; i++) {
            target[i] = rec->color[i];
        }
        target[3] = 0;
        endN = rec->n;
        endA = rec->a;
        endB = rec->b;
    }

    if (D_800CD730 == 0 || rec->period == 0.0f) {
        self->blendTime = 1.0f;
    } else {
        f32 progress;
        progress = self->blendTime + D_800D2988 / (rec->period * 15.0f);
        if (1.0f < progress) {
            progress = 1.0f;
        }
        self->blendTime = progress;
    }

    t = self->blendTime;
    k = t * (t * -2.0f) * t + t * (t * 3.0f);

    /* Clamp the interpolated channels to [0, 255] and the scalar to [0, 995]. */
    for (i = 0; i < 4; i++) {
        self->color[i] = (u32)(
            (255.0f < ((f32)self->secondaryColor[i] +
                       k * ((f32)target[i] - (f32)self->secondaryColor[i]))
                 ? 255.0f
                 : ((f32)self->secondaryColor[i] +
                    k * ((f32)target[i] - (f32)self->secondaryColor[i]))) < 0.0f
                ? 0.0f
                : (255.0f < ((f32)self->secondaryColor[i] +
                             k * ((f32)target[i] - (f32)self->secondaryColor[i]))
                       ? 255.0f
                       : ((f32)self->secondaryColor[i] +
                          k * ((f32)target[i] - (f32)self->secondaryColor[i]))));
    }
    self->blendN = (u32)(
        (995.0f < ((f32)self->previousN + k * ((f32)endN - (f32)self->previousN))
             ? 995.0f
             : ((f32)self->previousN + k * ((f32)endN - (f32)self->previousN))) < 0.0f
            ? 0.0f
            : (995.0f < ((f32)self->previousN + k * ((f32)endN - (f32)self->previousN))
                   ? 995.0f
                   : ((f32)self->previousN + k * ((f32)endN - (f32)self->previousN))));

    if (self->blendOffset > 0.0f) {
        endA += self->blendOffset * 1024.0f;
    }
    self->blendA = self->previousA + k * (endA - self->previousA);
    self->blendB = self->previousB + k * (endB - self->previousB);
}
