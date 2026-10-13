#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802393F4.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "shared/gameplay_camera.h"

extern s32 func_80245798_de(void);

extern f32 func_80275DD4_de(s32 arg0, f32 arg1, f32 arg2);

extern s32 D_800CD8D0;









void func_80239FDC_de(void *arg0) {
    s32 object;
    Shared_func_80234FDC_S2 *camera = arg0;
    f32 value;
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    if (func_80245798_de() != 0) {
        camera->unk58 = (Shared_func_80234FDC_S8 *)func_80286728_de(&D_8011FE88, &camera->unk38);
    }
    object = (s32)camera->unk58;
    x = camera->unk38;
    y = camera->unk3C;
    z = camera->unk40;
    w = camera->unk44;
    camera->unk64 = D_800CD8D0;
    if (object != 0 && func_80245798_de() == 0) {
        value = ((y + w) - func_80275DD4_de(object, x, z)) * D_800C3590_de;
        if (value < D_800C3594_de && D_800C3598_de < value) {
            Shared_func_80234FDC_S8 *surface = (Shared_func_80234FDC_S8 *)object;
            camera->unk64 = surface->unk1C;
        }
    }
    if (func_80245798_de() != 0) {
        camera->unk64 = D_800CD8D0;
    }
    if (camera->unk5C > 0.0f) {
        camera->unk64 = D_800CD8D0;
    }
}
