#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "TYPES.H"

s32 func_802B2620_de(void *arg0) {
    return (((struct ObjRecAt28V2 *) ((s8 *) ((((struct ObjRecAt40V3 *) ((s8 *) arg0))->unk3C * 0x30) + ((struct ObjRecAt40V3 *) ((s8 *) arg0))->unk40)))->unk28);
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802B2574);
#endif
