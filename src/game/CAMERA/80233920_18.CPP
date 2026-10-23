#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern void func_80272A10_de(void *, void *, CVector3 *);




void func_80239244_de(s32 view, s32 point, f32 *screenX, f32 *screenY) {
    CVector3 value;
    f32 half;

    func_80272A10_de(view + 0x1E0, point, &value);
    half = (f32)(D_800E28D0 / 2);
    *screenX = value.x * half + half;
    *screenY = value.y * (f32)(-D_800E28D4 / 2) +
            (f32)(D_800E28D4 / 2);
}
