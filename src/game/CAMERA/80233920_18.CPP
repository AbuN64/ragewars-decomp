#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

extern s32 D_800E28D0;
extern void Particle_ProjectPoint(void *, void *, CVector3 *);




void Camera_ProjectToScreen(s32 view, s32 point, f32 *screenX, f32 *screenY) {
    CVector3 value;
    f32 half;

    Particle_ProjectPoint(view + 0x1E0, point, &value);
    half = (f32)(D_800E28D0 / 2);
    *screenX = value.x * half + half;
    *screenY = value.y * (f32)(-D_800E28D4 / 2) +
            (f32)(D_800E28D4 / 2);
}
