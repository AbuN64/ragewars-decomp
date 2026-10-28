#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "UTIL/MAP.H"
#include "COMMON/ENTRYRECAT18V3.H"
#include "COMMON/S1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"

void Map_ResetFramePool(void *batch) {
    s32 *p = (s32 *)batch;
    p[2] = p[1];
    p[3] = p[0] + ((p[1] * D_800D297C) << 6);
}

s32 Map_ReserveEntries(void *arg0, s32 arg1) {
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
char rodata_unresolved_802799E4[12] =
    "s_t\004.eos\000\000\000\000";
#endif
