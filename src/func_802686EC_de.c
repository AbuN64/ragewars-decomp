#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80268160.h"
#include "types.h"

/* Forwards a position read from an object to func_8028FFD0_de on the global D_80131600 with a zero offset and a zero trailing weight, returning its result. Adapted from func_8028BFD8_de with the base argument, the source vector, the trailing arguments passed as a by-value struct and the return value changed. */








extern char D_80131600;
extern s32 func_8028FFD0_de(s32, s32, s32, Triple, Triple, s32, f32);

s32 func_802686EC_de(s32 arg0, Input80216D3C *arg1, s32 arg2, Triple arg3, Extra arg6) {
    Vec3 scale;
    Triple zero;

    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    scale.x = arg6.scale;
    scale.y = arg6.scale;
    scale.z = arg6.scale;
    return func_8028FFD0_de((s32)&D_80131600, 0, arg6.id, zero, arg1->vec, 0, 0.0f);
}
