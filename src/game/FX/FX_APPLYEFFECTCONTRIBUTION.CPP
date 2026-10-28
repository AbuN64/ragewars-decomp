#include "COMMON/EFFECTCONTRIBUTION.H"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "RENDER/ANIMATION_FRAME_AND_RIBBON_VIEWS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "RENDER/FX_APPLYEFFECTCONTRIBUTION.H"



void Fx_SetAnimatorScript(void *animator, int arg1) {
    Animator *animation = animator;
    animation->mode = 0;
    animation->loop = (f32 *)arg1;
    animation->script = (f32 *)arg1;
}

void Fx_ApplyEffectContribution(EffectContribution *effectContribution) {
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
