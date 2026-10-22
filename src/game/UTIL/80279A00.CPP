#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"

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

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802799E4);
#endif
