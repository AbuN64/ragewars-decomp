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










void func_80238F24_de(GameplayCamera *camera, s32 bobSuppression, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 floorSampleX,
                   f32 floorSampleY, f32 floorSampleZ, f32 floorHeightOffset, Shared_Quad arg10, s32 floorPolygon, f32 requestedZoomBlend,
                   f32 requestedZoomFov) {
    s32 object;
    f32 value;
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    camera->unk24 = bobSuppression;
    camera->unk28 = arg2;
    camera->unk2C = arg3;
    camera->unk30 = arg4;
    camera->unk34 = arg5;
    camera->unk38 = floorSampleX;
    camera->unk3C = floorSampleY;
    camera->unk40 = floorSampleZ;
    camera->unk44 = floorHeightOffset;
    camera->unk48 = arg10;
    camera->floorPoly = (void *)floorPolygon;
    camera->zoomBlend = requestedZoomBlend;
    camera->zoomFov = requestedZoomFov;
    if (Camera_IsSequenceInWindow() != 0) {
        camera->floorPoly = (void *)Scene_FindFloorPolygon(&g_world, &camera->unk38);
    }
    object = (s32)camera->floorPoly;
    x = camera->unk38;
    y = camera->unk3C;
    z = camera->unk40;
    w = camera->unk44;
    camera->floorSurface = D_800CD8D0;
    if (object != 0 && Camera_IsSequenceInWindow() == 0) {
        value = ((y + w) - Anim_GetPolygonHeight(object, x, z)) * D_800C8610;
        if (value < D_800C3524_de && D_800C3528_de < value) {
            camera->floorSurface = ((MenuRules *)(object))->locked;
        }
    }
    if (Camera_IsSequenceInWindow() != 0) {
        camera->floorSurface = D_800CD8D0;
    }
    if (camera->zoomBlend > 0.0f) {
        camera->floorSurface = D_800CD8D0;
    }
}
