#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028469C.h"
#include "TYPES.H"





f32 func_80285630_de(s32 arg0) {
    s32 sp0;
    s32 sp4;
    u32 seed;
    s32 idx;
    f64 var_f2;

    sp0 = (s32) (*(u16 *) &arg0) << 16;
    if (((struct ObjRecAt2V2 *) ((u16 *) (&arg0)))->unk2 == 0) {
        return *(f32 *) &sp0;
    }
    sp4 = (s32) (((struct ObjRecAt2V2 *) ((u16 *) (&arg0)))->unk2) << 16;
    seed = (D_80111D24 * (s32) 0xA84A5B53) + (s32) 0x58348C2D;
    idx = (s32) ((seed >> 16) & 0x7FFF);
    var_f2 = (f64) idx;
    D_80111D24 = seed;
    if (idx < 0) {
        var_f2 += D_800C4EB0_de;
    }
    return *(f32 *) &sp0 + (((f32) var_f2 * *(f32 *) &sp4) * D_800C4EB8_de);
}
