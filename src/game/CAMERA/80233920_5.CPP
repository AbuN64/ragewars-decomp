#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

/* Rebuilds a camera's view volume when it is active: the eye and the four far corners at depth 0x528 come
 * either from the field of view 0x530 and aspect 0x70 (a perspective camera, radius the slant distance to
 * the far plane) or, while the global orthographic flag is set, from half the view extents 0x74 and 0x78
 * (radius the corner distance); the corners are transformed by the view matrix at 0x160 into 0x260, the
 * clip planes at 0x2F0 and the bounds at 0x350 are rebuilt from them, and a box around the eye of that
 * radius (half again as tall) is stored at 0x368. */



extern const f32 D_800C3200_de[];
extern const f32 D_800C3208_de;


extern f32 Math_Sqrtf(f32);
extern void func_80272944_de(void *, CVector3 *, CVector3 *, s32);
extern void func_802965B0_de(void *, CVector3 *, CVector3 *, CVector3 *, CVector3 *, CVector3 *);
extern void Nav_ComputePointBounds(void *, s32, CVector3 *);







void func_80234DE0_de(GameplayCamera *camera) {
    CVector3 pts[5];
    CVector3 *out;
    f32 radius;
    f32 height;

    if (camera->dirty == 0) {
        return;
    }
    if (D_801462C8.local == 0) {
        radius = camera->farPlane /
                 Math_Cosf(camera->unk530 * camera->aspect * D_800C3200_de[0]);
        pts[0].x = 0.0f;
        pts[0].y = 0.0f;
        pts[0].z = 0.0f;
        pts[1].x = radius * Math_Sinf(camera->unk530 * camera->aspect * D_800C3200_de[0]);
        pts[1].y = pts[1].x / camera->aspect;
        pts[1].z = -camera->farPlane;
        pts[2].x = -pts[1].x;
        pts[2].y = pts[1].y;
        pts[2].z = pts[1].z;
        pts[3].x = pts[1].x;
        pts[3].y = -pts[1].y;
        pts[3].z = pts[1].z;
        pts[4].x = -pts[1].x;
        pts[4].y = -pts[1].y;
        pts[4].z = pts[1].z;
    } else {
        pts[0].x = 0.0f;
        pts[0].y = 0.0f;
        pts[0].z = 0.0f;
        pts[1].x = camera->farHalfWidth * D_800C3200_de[1];
        pts[1].y = camera->farHalfHeight * D_800C3200_de[1];
        pts[1].z = -camera->farPlane;
        pts[2].x = -pts[1].x;
        pts[2].y = pts[1].y;
        pts[2].z = pts[1].z;
        pts[3].x = pts[1].x;
        pts[3].y = -pts[1].y;
        pts[3].z = pts[1].z;
        pts[4].x = -pts[1].x;
        pts[4].y = -pts[1].y;
        pts[4].z = pts[1].z;
        radius = Math_Sqrtf(pts[1].x * pts[1].x + pts[1].y * pts[1].y + pts[1].z * pts[1].z);
    }
    out = &camera->corners[0];
    func_80272944_de(&camera->unk160, pts, out, 5);
    func_802965B0_de(camera->clipPlanes, out, out + 1, out + 2, out + 3, out + 4);
    Nav_ComputePointBounds(camera->clipBounds, 5, out);
    height = radius * D_800C3208_de;
    camera->volumeBounds[0].x = camera->corners[0].x - radius;
    camera->volumeBounds[1].x = camera->corners[0].x + radius;
    camera->volumeBounds[0].y = camera->corners[0].y - height;
    camera->volumeBounds[1].y = camera->corners[0].y + height;
    camera->volumeBounds[0].z = camera->corners[0].z - radius;
    camera->volumeBounds[1].z = camera->corners[0].z + radius;
}
