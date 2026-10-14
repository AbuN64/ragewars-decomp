#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025D948.h"
#include "types.h"




extern s32 D_8010C080;

extern s32 func_80257DD4_de(void *, s32, Vec3, s32, s32);

s32 func_8025DE54_de(s16 arg0, Vec3 arg1, s32 arg4, s32 arg5) {
    if (D_801427D0 != 0) {
        return -1;
    }
    return func_80257DD4_de(&D_8010C080, arg0, arg1, arg4, arg5);
}
