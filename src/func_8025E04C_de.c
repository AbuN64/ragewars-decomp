#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025D948.h"



extern signed char D_8010C080;
extern int func_80258D10_de(void *arg0);
extern void func_80258D08_de(void *arg0, int arg1);
extern int func_8025826C_de(void *arg0, int arg1, Vec3 arg2, int arg3);

int func_8025E04C_de(int arg0) {
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
