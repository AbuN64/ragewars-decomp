#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "TYPES.H"

s32 func_802B2620_de(void *soundPlayer) {
    return (((struct ObjRecAt28V2 *) ((s8 *) ((((struct ObjRecAt40V3 *) ((s8 *) soundPlayer))->unk3C * 0x30) + ((struct ObjRecAt40V3 *) ((s8 *) soundPlayer))->unk40)))->unk28);
}

#if defined(VERSION_US)
char rodata_unresolved_802B2574[12] =
    "ry_t\004.eosT\000\000";
#endif
