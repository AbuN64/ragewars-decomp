#include "MAIN/802555D0.H"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80279208.h"
#include "TYPES.H"
#include "span_1000/code_8022F3E8.h"


void func_80279990_de(void *arg0) {
    s32 *p = (s32 *)arg0;
    p[2] = p[1];
    p[3] = p[0] + ((p[1] * D_800D297C) << 6);
}

s32 func_802799C0_de(void *arg0, s32 arg1) {
    s32 var_a2;
    var_a2 = 0;
    if ((((struct ObjRecAtCV3 *) ((s8 *) arg0))->unk8) >= arg1) {
        var_a2 = (((struct ObjRecAtCV3 *) ((s8 *) arg0))->unkC);
        (((struct ObjRecAtCV3 *) ((s8 *) arg0))->unkC) = (s32) (var_a2 + (arg1 << 6));
        (((struct ObjRecAtCV3 *) ((s8 *) arg0))->unk8) = (s32) ((((struct ObjRecAtCV3 *) ((s8 *) arg0))->unk8) - arg1);
    }
    return var_a2;
}
