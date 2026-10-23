#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"
#include "CAMERA/80233920_14.H"

extern f32 D_800C8628;
extern f32 D_800C3534_de;






void func_8023913C_de(GameplayCamera *camera) {
    if (camera != 0) {
        f32 f0 = D_800C352C_de;
        f32 f1 = D_800C3530_de;
        f32 f2 = D_800C3534_de;
        f32 f3 = D_800C8628;

        camera->unk90 = 0;
        camera->unk94 = 0;
        camera->unk88 = f0;
        camera->unk8C = f1;
        camera->unk98 = f2;
        camera->unk9C = f3;
    }
}

void func_80239184_de(void) {
}

void func_8023918C_de(void) {
}
