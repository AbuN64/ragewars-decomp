#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8027451C.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);
extern f32 D_800C49A4_de;






void func_80274C7C_de(void *arg0)
{
    ObjRecAt2CV1 *o = arg0;
    f32 magSq;
    f32 mag;
    f32 zOut;

    magSq = (o->unk18 * o->unk18) +
            (o->unk1C * o->unk1C) +
            (o->unk20 * o->unk20);
    zOut = 0.0f;
    if (magSq != 0.0f) {
        mag = func_802B72B0_de(magSq);
        magSq = D_800C49A4_de / mag;
        o->unk24 = o->unk18 * magSq;
        o->unk28 = o->unk1C * magSq;
        zOut = o->unk20 * magSq;
    } else {
        o->unk24 = 0.0f;
        o->unk28 = 0.0f;
    }
    o->unk2C = zOut;
}
