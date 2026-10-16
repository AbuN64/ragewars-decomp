#include "sdk/libgultra.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B243C.h"
#include "TYPES.H"





void func_802B25D0_de(void *a, s16 b) {
    void *temp_v1;
    temp_v1 = (b * 0x30) + (((struct ObjRecAt40V3 *) ((s8 *) a))->unk40);
    if ((((struct Shared_GameMode *) ((s8 *) temp_v1))->unk28) == 0) {
        (((struct Shared_GameMode *) ((s8 *) temp_v1))->unk1C) = 0;
        if ((((struct ObjRecAt40V3 *) ((s8 *) a))->unk3C) == b) {
            (((struct ObjRecAt40V3 *) ((s8 *) a))->unk3C) = -1;
        }
    }
}
