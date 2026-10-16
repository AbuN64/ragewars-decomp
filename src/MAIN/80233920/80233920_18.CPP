#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80233920.h"
#include "TYPES.H"



extern s32 D_800E28D0;
extern s32 D_800E28D4;
extern void func_80272A10_de(void *, void *, Vec3 *);




void func_80239244_de(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    Vec3 value;
    f32 half;

    func_80272A10_de(arg0 + 0x1E0, arg1, &value);
    half = (f32)(D_800E28D0 / 2);
    *arg2 = value.x * half + half;
    *arg3 = value.y * (f32)(-D_800E28D4 / 2) +
            (f32)(D_800E28D4 / 2);
}
