#include "COMMON/EFFECTCONTRIBUTION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "RENDER_3/802A35C0_7.H"

extern func_802A6A54_S2 D_800D15E0;

extern func_802A6A54_S3 D_800D15F0;

void func_802A5A54_de(void *arg0, int arg1) {
    Animator *animation = arg0;
    animation->mode = 0;
    animation->loop = (f32 *)arg1;
    animation->script = (f32 *)arg1;
}

void func_802A5A64_de(EffectContribution *arg0) {
    if (arg0->weight != 0.0f) {
        D_800D15E0.unk4 = arg0->x;
        D_800D15E0.unk8 = arg0->y;
        D_800D15E0.unkC = arg0->z;
    } else {
        D_800D15E0.unk4 = 0.0f;
        D_800D15E0.unk8 = 0.0f;
        D_800D15E0.unkC = 0.0f;
    }
    D_800D15F0.unk0 = arg0->weight;
    D_800D15F0.unk4 = arg0->scale;
}
