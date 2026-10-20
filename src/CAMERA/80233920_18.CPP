#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VIEWFLAGS.H"
#include "TYPES.H"

extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern void func_80272A10_de(void *, void *, CVector3 *);




void func_80239244_de(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    CVector3 value;
    f32 half;

    func_80272A10_de(arg0 + 0x1E0, arg1, &value);
    half = (f32)(D_800E28D0 / 2);
    *arg2 = value.x * half + half;
    *arg3 = value.y * (f32)(-D_800E28D4 / 2) +
            (f32)(D_800E28D4 / 2);
}
