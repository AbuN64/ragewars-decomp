#include "span_1000/code_8025D948.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "TYPES.H"

/** Calls func_80257360_de with &D_8010C080 as its argument. */





struct ContextRecAt2BC0;
extern s32 func_80258A7C_de(struct ContextRecAt2BC0 *arg0, s32 arg1, Vec3 arg2,
                         s32 arg3, s32 arg4, f32 arg5);







void func_8025DE30_de(void) {
    extern char D_8010C080[];
    func_80257360_de(D_8010C080);
}

s32 func_8025DE54_de(s16 arg0, Vec3 arg1, s32 arg4, s32 arg5) {
    extern s32 D_8010C080;
    if (D_801427D0 != 0) {
        return -1;
    }
    return func_80257DD4_de(&D_8010C080, arg0, arg1, arg4, arg5);
}

s32 func_8025DEC0_de(s32 arg0, Vec3 arg1, s32 arg4, s32 arg5, f32 arg6) {
    extern s32 D_8010C080;
    if (D_801427D0 != 0) {
        return -1;
    }
    return func_80258A7C_de(&D_8010C080, (s16)arg0, arg1, arg4, arg5, arg6);
}

s32 func_8025DF34_de(s32 arg0) {
    extern s32 D_8010C080;
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

s32 func_8025DFE8_de(s32 arg0, Vec3 arg1, s32 arg2) {
    extern s32 D_8010C080;
    if (D_801427D0 != 0) {
        return -1;
    }
    return func_8025826C_de(&D_8010C080, arg0, arg1, arg2);
}

int func_8025E04C_de(int arg0) {
    extern signed char D_8010C080;
    int temp_s0;
    int temp_s1;

    if (D_801427D0 != 0) {
        return -1;
    }
    {
        Vec3 vec;
        register float zero = (float)0;

        vec.z = zero;
        vec.y = zero;
        vec.x = zero;
        temp_s1 = func_80258D10_de(&D_8010C080);
        func_80258D08_de(&D_8010C080, 1);
        temp_s0 = func_8025826C_de(&D_8010C080, arg0, vec, 0);
        func_80258D08_de(&D_8010C080, temp_s1);
    }
    return temp_s0;
}
