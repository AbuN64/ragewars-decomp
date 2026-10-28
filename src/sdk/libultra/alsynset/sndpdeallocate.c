#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
#include "TYPES.H"

void alSndpDeallocate(void *a, s16 b) {
    void *soundState;
    soundState = (b * 0x30) + (((struct ObjRecAt40V3 *) ((s8 *) a))->unk40);
    if ((((struct Shared_GameMode *) ((s8 *) soundState))->unk28) == 0) {
        (((struct Shared_GameMode *) ((s8 *) soundState))->unk1C) = 0;
        if ((((struct ObjRecAt40V3 *) ((s8 *) a))->unk3C) == b) {
            (((struct ObjRecAt40V3 *) ((s8 *) a))->unk3C) = -1;
        }
    }
}

#if defined(VERSION_US)
char rodata_unresolved_802B2544[12] =
    "CLoaderEntry";
#endif
