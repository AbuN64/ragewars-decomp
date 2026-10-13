#include "shared/gameplay_camera.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80233920.h"
#include "types.h"



extern f32 D_800C8628;
extern f32 D_800C3534_de;






void func_8023913C_de(void *arg0) {
    if (arg0 != 0) {
        f32 f0 = D_800C352C_de;
        f32 f1 = D_800C3530_de;
        f32 f2 = D_800C3534_de;
        f32 f3 = D_800C8628;

        ((Shared_func_80234FDC_S2 *)arg0)->unk90 = 0;
        ((Shared_func_80234FDC_S2 *)arg0)->unk94 = 0;
        ((Shared_func_80234FDC_S2 *)arg0)->unk88 = f0;
        ((Shared_func_80234FDC_S2 *)arg0)->unk8C = f1;
        ((Shared_func_80234FDC_S2 *)arg0)->unk98 = f2;
        ((Shared_func_80234FDC_S2 *)arg0)->unk9C = f3;
    }
}

void func_80239184_de(void) {
}

void func_8023918C_de(void) {
}
