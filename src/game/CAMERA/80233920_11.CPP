#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

/* Stores its parameters into the object at arg0 offsets 0x24 through 0x60, then refreshes the object's ground reference and picks its surface value at 0x64 from the ground under it. Adapted from func_80239FDC_de with the parameter block stores added and the D_800C8610 thresholds changed. */



extern s32 Camera_IsSequenceInWindow(void);

extern f32 Anim_GetPolygonHeight(s32 arg0, f32 arg1, f32 arg2);










void func_80238F24_de(GameplayCamera *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
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
    arg0->floorPoly = (void *)arg11;
    arg0->zoomBlend = arg12;
    arg0->zoomFov = arg13;
    if (Camera_IsSequenceInWindow() != 0) {
        arg0->floorPoly = (void *)Scene_FindFloorPolygon(&D_8011FE88, &arg0->unk38);
    }
    object = (s32)arg0->floorPoly;
    x = arg0->unk38;
    y = arg0->unk3C;
    z = arg0->unk40;
    w = arg0->unk44;
    arg0->floorSurface = D_800CD8D0;
    if (object != 0 && Camera_IsSequenceInWindow() == 0) {
        value = ((y + w) - Anim_GetPolygonHeight(object, x, z)) * D_800C8610;
        if (value < D_800C3524_de && D_800C3528_de < value) {
            arg0->floorSurface = ((MenuRules *)(object))->locked;
        }
    }
    if (Camera_IsSequenceInWindow() != 0) {
        arg0->floorSurface = D_800CD8D0;
    }
    if (arg0->zoomBlend > 0.0f) {
        arg0->floorSurface = D_800CD8D0;
    }
}
