#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025D948.h"
#include "types.h"


extern s32 D_8010C080;



extern s32 func_80258A7C_de(void *arg0, s32 arg1, Vec3 arg2,
                         s32 arg3, s32 arg4, f32 arg5);

s32 func_8025DEC0_de(s32 arg0, Vec3 arg1, s32 arg4, s32 arg5, f32 arg6) {
    if (D_801427D0 != 0) {
        return -1;
    }
    return func_80258A7C_de(&D_8010C080, (s16)arg0, arg1, arg4, arg5, arg6);
}
