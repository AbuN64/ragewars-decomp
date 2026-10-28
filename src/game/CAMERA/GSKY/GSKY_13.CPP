#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"
#include "CAMERA/80233920_14.H"

extern f32 D_800C8628;






void Gsky_ResetHeadBob(GameplayCamera *camera) {
    if (camera != 0) {
        f32 f0 = D_800C352C_de;
        f32 f1 = D_800C3530_de;
        f32 f2 = D_800C3534_de;
        f32 f3 = D_800C8628;

        camera->bobPhaseX = 0;
        camera->bobPhaseY = 0;
        camera->bobAmplitudeX = f0;
        camera->bobAmplitudeY = f1;
        camera->bobRateX = f2;
        camera->bobRateY = f3;
    }
}

void func_80239184_de(void) {
}

void func_8023918C_de(void) {
}
