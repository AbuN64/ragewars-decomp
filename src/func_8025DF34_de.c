#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025D948.h"
#include "types.h"




extern s32 D_8010C080;

extern s32 func_80258D10_de(void *arg0);
extern void func_80258D08_de(void *arg0, s32 arg1);
extern s32 func_80257DD4_de(void *, s32, Vec3, s32, s32);

s32 func_8025DF34_de(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;

    if (D_801427D0 != 0) {
        return -1;
    }
    {
        Vec3 vec;
        register f32 zero = 0.0f;

        vec.z = zero;
        vec.y = zero;
        vec.x = zero;
        temp_s1 = func_80258D10_de(&D_8010C080);
        func_80258D08_de(&D_8010C080, 1);
        temp_s0 = func_80257DD4_de(&D_8010C080, (s16)arg0, vec, 0, -1);
        func_80258D08_de(&D_8010C080, temp_s1);
    }
    return temp_s0;
}
