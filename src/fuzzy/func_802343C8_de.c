#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"
#include "math_helpers.h"
#include "shared/world.h"
#include "span_1000/code_80233920.h"
extern const f32 D_800C3160_de;
extern const f32 D_800C3164_de;
extern const f32 D_800C3168_de;
extern const f32 D_800C316C_de;
extern const f32 D_800C3170_de;
extern const f32 D_800C3174_de;
extern const f32 D_800C3178_de;
extern const f32 D_800C317C_de;
extern const f32 D_800C3198_de;
extern const f32 D_800C31D0_de;
extern const f32 D_800C31F0_de;
extern const f32 D_800C31F4_de;
extern f32 D_800D2988;
extern s32 D_800CD730;
extern void *func_8028B2F8_de(void *, u16 *);
extern SharedPlayer_func_8022A398_de *D_80145060;

extern const f64 D_800C3180_de, D_800C3188_de, D_800C3190_de;
extern const f64 D_800C31A0_de, D_800C31A8_de, D_800C31B0_de;
extern const f64 D_800C31B8_de, D_800C31C0_de, D_800C31C8_de;
extern const f64 D_800C31D8_de, D_800C31E0_de, D_800C31E8_de;
static inline f32 unsignedFloat(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if ((s32)value<0) result+=*bias;
    return (f32)result;
}
static inline u32 unsignedInt(f32 value,const f32 *bias) {
    u32 result;
    if(*bias<=value) goto high;
    result=(u32)(s32)value;
    goto done;
high:
    result=(u32)(s32)(value-*bias);
    result|=0x80000000;
done:
    return result;
}

void func_802343C8_de(Entity_func_80233C88_de *self) {
    u8 target[4];
    ColorBlendRecord *rec;
    SharedPlayer_func_8022A398_de *node;
    u32 hold;
    u32 freeze;
    u32 fadeA;
    u32 fadeB;
    u32 endN;
    f32 endA;
    f32 endB;
    f32 t;
    f32 k;
    f32 v;
    f32 colorLimit;
    f32 colorBias;
    u32 output;
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

    hold=0; fadeA=hold; fadeB=hold; freeze=hold;
    for (node = D_80145060; node != 0; node = node->views16E0.view16E0_1.next) {
        if (node->views5DC.view5DC_0.unk5DC == self) goto found;
    }
    node=0;
found:
    if (node != 0) {
        SharedPlayer_func_8022A398_de *ownerNode=node;
        hold=0;
        if ((ownerNode->views5E8.view664_27.unk664&0x40) || (ownerNode->views1C.view38_3.flags&0x1000)) hold=1;
        freeze = node->views1C.view38_3.flags & 0x20000;
        fadeA=0;
        if (node->views1C.view38_3.flags & 0x8000) fadeA=fadeA<hold;
        fadeB=0;
        if (node->views1C.view38_3.flags & 0x10000) fadeB=fadeB<hold;
    }

    if (key != 0 && (*key != self->lastKey || hold != 0 || freeze != 0)) {
        if (self->lastKey == -1 || hold != 0 || freeze != 0) {
            self->blendTime = D_800C3160_de;
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
        self->blendTime = D_800C3164_de;
    } else {
        f32 progress;
        progress = self->blendTime + D_800D2988 / (rec->period * D_800C3168_de);
        if (D_800C316C_de < progress) progress=D_800C316C_de;
        self->blendTime=progress;
    }

    t = self->blendTime;
    k = t * (t * D_800C3170_de) * t + t * (t * D_800C3174_de);

    for(i=0;i<4;i++) {
    if(D_800C3178_de < ((f32)self->secondaryColor[i] + k * ((f32)target[i] - (f32)self->secondaryColor[i]))) goto color_high;
    if(((f32)self->secondaryColor[i] + k * ((f32)target[i] - (f32)self->secondaryColor[i]))<0.0f) {output=0; goto color_done;}
    if(D_800C3178_de < ((f32)self->secondaryColor[i] + k * ((f32)target[i] - (f32)self->secondaryColor[i]))) goto color_high;
    output=unsignedInt(((f32)self->secondaryColor[i] + k * ((f32)target[i] - (f32)self->secondaryColor[i])),&D_800C317C_de); goto color_done;
color_high: output=255;
color_done: self->color[i]=output;
    }
    if(D_800C3198_de < (unsignedFloat(self->previousN,&D_800C3180_de) + k * (unsignedFloat(endN,&D_800C3188_de)-unsignedFloat(self->previousN,&D_800C3190_de)))) goto clamp_n;
    if((unsignedFloat(self->previousN,&D_800C31A0_de) + k * (unsignedFloat(endN,&D_800C31A8_de)-unsignedFloat(self->previousN,&D_800C31B0_de))) < 0.0f) { output=0; goto store_n; }
clamp_n:
    if(D_800C31D0_de < (unsignedFloat(self->previousN,&D_800C31B8_de) + k * (unsignedFloat(endN,&D_800C31C0_de)-unsignedFloat(self->previousN,&D_800C31C8_de)))) { output=0x3E3; goto store_n; }
    output=unsignedInt(unsignedFloat(self->previousN,&D_800C31D8_de) + k * (unsignedFloat(endN,&D_800C31E0_de)-unsignedFloat(self->previousN,&D_800C31E8_de)),&D_800C31F0_de);
store_n:
    self->blendN=output;

    if (self->blendOffset > 0.0f) {
        endA += self->blendOffset * D_800C31F4_de;
    }
    self->blendA = self->previousA + k * (endA - self->previousA);
    self->blendB = self->previousB + k * (endB - self->previousB);
}
