#include "COMMON/EFFECTCONTRIBUTION.H"
#include "RENDER_4/8026AC38.H"
#include "RENDER_3/802A35C0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "RENDER_3/802A35C0_7.H"



void func_802A5A54_de(void *animator, int arg1) {
    Animator *animation = animator;
    animation->mode = 0;
    animation->loop = (f32 *)arg1;
    animation->script = (f32 *)arg1;
}

void func_802A5A64_de(EffectContribution *effectContribution) {
    if (effectContribution->weight != 0.0f) {
        D_800D15E4[0] = effectContribution->x;
        D_800D15E4[1] = effectContribution->y;
        D_800D15E4[2] = effectContribution->z;
    } else {
        D_800D15E4[0] = 0.0f;
        D_800D15E4[1] = 0.0f;
        D_800D15E4[2] = 0.0f;
    }
    D_800D15E4[3] = effectContribution->weight;
    D_800D15E4[4] = effectContribution->scale;
}
