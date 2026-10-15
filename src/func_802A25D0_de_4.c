#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"
#include "span_1000/code_8024E914.h"
/* Interpolates morph vertex positions and shades between two key frames. */


















extern void func_80271F9C_de(f32 *out, Key *key, void *frame);

void func_802A274C_de(Actor_func_802A274C_de *actor, ObjRecAt28V1 *clock, Vtx *out, Morph *morph) {
    f32 a[3];
    f32 b[3];
    f32 weight;
    f32 t;
    Blend *blend;
    Shade *from;
    Key *key;
    s32 count;
    u32 grey;
    s32 red;
    s32 green;
    s32 blue;

    weight = 0.5f - func_802B6560_de(clock->unk8 / actor->track->total * 3.1415927f) * 0.5f;
    if (actor->time <= actor->track->span) {
        weight = weight * (0.5f - func_802B6560_de(actor->time / actor->track->span * 3.1415927f) * 0.5f);
    }
    count = morph->count;
    blend = morph->blends;
    t = 1.0f - weight;
    while (--count != -1) {
        key = &morph->second[blend->second];
        func_80271F9C_de(a, &morph->first[blend->first], morph->firstFrame);
        func_80271F9C_de(b, key, morph->secondFrame);
        out->x = (s16) (a[0] + t * (b[0] - a[0]));
        out->y = (s16) (a[1] + t * (b[1] - a[1]));
        out->z = (s16) (a[2] + t * (b[2] - a[2]));
        from = &blend->from;
        if (func_8026E340_de() != 0) {
            blue = blend->from.b;
            green = blend->from.g;
            red = blend->from.r;
            grey = (f32) (blue + green + red)
                 + t * (f32) ((blend->to.b - blue) + (blend->to.g - green) + (blend->to.r - red));
            out->r = 0;
            out->g = 0;
            out->b = grey / 3;
            out->a = (u32) ((f32) from->a + t * (f32) (blend->to.a - from->a));
        } else {
            out->r = (u32) ((f32) blend->from.r + t * (f32) (blend->to.r - blend->from.r));
            out->g = (u32) ((f32) blend->from.g + t * (f32) (blend->to.g - blend->from.g));
            out->b = (u32) ((f32) blend->from.b + t * (f32) (blend->to.b - blend->from.b));
            out->a = (u32) ((f32) from->a + t * (f32) (blend->to.a - from->a));
        }
        blend++;
        out++;
    }
}
