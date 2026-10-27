#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "CAMERA/80233920.H"

/* Clears effect state and initializes its scalar, vector and resource defaults. */
#include "TYPES.H"


extern s32 D_800CD8D0[];
void func_80238EB8_de(State44 *effectState) {
    f32 zeroValue;
    CVector3 *vectorDefaults;

    effectState->unk_20.i = 0;
    zeroValue = effectState->unk_20.f;
    effectState->unk_0 = 1;
    vectorDefaults = &effectState->v;
    effectState->unk_4 = 0;
    effectState->unk_8 = 0;
    effectState->unk_C = 0;
    effectState->unk_10 = 0;
    effectState->unk_14 = 0;
    effectState->unk_18 = 0;
    effectState->unk_1C = 0;
    vectorDefaults->z = zeroValue;
    vectorDefaults->y = zeroValue;
    effectState->v.x = zeroValue;
    effectState->unk_30 = 1.0f;
    effectState->unk_34 = 0;
    effectState->unk_38 = zeroValue;
    effectState->unk_3C = 0.174532949924469f;
    effectState->unk_40 = (s32) *D_800CD8D0;
}
