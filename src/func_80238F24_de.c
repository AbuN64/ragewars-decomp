#include "shared/gameplay_camera.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80233920.h"
#include "types.h"
/* Stores its parameters into the object at arg0 offsets 0x24 through 0x60, then refreshes the object's ground reference and picks its surface value at 0x64 from the ground under it. Adapted from func_80239FDC_de with the parameter block stores added and the D_800C8610 thresholds changed. */



extern s32 func_80245798_de(void);

extern f32 func_80275DD4_de(s32 arg0, f32 arg1, f32 arg2);

extern s32 D_800CD8D0;









void func_80238F24_de(Shared_func_80234FDC_S2 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                   f32 arg7, f32 arg8, f32 arg9, Shared_Quad arg10, s32 arg11, f32 arg12,
                   f32 arg13) {
    s32 object;
    f32 value;
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    arg0->unk24 = arg1;
    arg0->unk28 = arg2;
    arg0->unk2C = arg3;
    arg0->unk30 = arg4;
    arg0->unk34 = arg5;
    arg0->unk38 = arg6;
    arg0->unk3C = arg7;
    arg0->unk40 = arg8;
    arg0->unk44 = arg9;
    arg0->unk48 = arg10;
    arg0->unk58 = (void *)arg11;
    arg0->unk5C = arg12;
    arg0->unk60 = arg13;
    if (func_80245798_de() != 0) {
        arg0->unk58 = (void *)func_80286728_de(&D_8011FE88, &arg0->unk38);
    }
    object = (s32)arg0->unk58;
    x = arg0->unk38;
    y = arg0->unk3C;
    z = arg0->unk40;
    w = arg0->unk44;
    arg0->unk64 = D_800CD8D0;
    if (object != 0 && func_80245798_de() == 0) {
        value = ((y + w) - func_80275DD4_de(object, x, z)) * D_800C8610;
        if (value < D_800C3524_de && D_800C3528_de < value) {
            arg0->unk64 = ((MenuRules *)(object))->locked;
        }
    }
    if (func_80245798_de() != 0) {
        arg0->unk64 = D_800CD8D0;
    }
    if (arg0->unk5C > 0.0f) {
        arg0->unk64 = D_800CD8D0;
    }
}
