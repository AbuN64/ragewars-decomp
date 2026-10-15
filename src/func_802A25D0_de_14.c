#include "span_1000/code_802A25C4.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "types.h"

extern func_802A6A54_S2 D_800D15E0;

extern func_802A6A54_S3 D_800D15F0;

void func_802A5A54_de(void *arg0, int arg1) {
    Animator *animation = arg0;
    animation->mode = 0;
    animation->loop = (f32 *)arg1;
    animation->script = (f32 *)arg1;
}

void func_802A5A64_de(void *arg0) {
    if (((EffectContribution *)arg0)->weight != 0.0f) {
        D_800D15E0.unk4 = ((EffectContribution *)arg0)->x;
        D_800D15E0.unk8 = ((EffectContribution *)arg0)->y;
        D_800D15E0.unkC = ((EffectContribution *)arg0)->z;
    } else {
        D_800D15E0.unk4 = 0.0f;
        D_800D15E0.unk8 = 0.0f;
        D_800D15E0.unkC = 0.0f;
    }
    D_800D15F0.unk0 = ((EffectContribution *)arg0)->weight;
    D_800D15F0.unk4 = ((EffectContribution *)arg0)->scale;
}
