#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "TYPES.H"




s32 func_802B0340_de(s32 a, s32 b, void *c, s32 d, s32 e) {
    ALHeap *heap = c;
    u32 temp_a1;
    u32 temp_v1;
    u32 var_a3;

    temp_a1 = (u32)heap->cur;
    temp_v1 = temp_a1 + (((d * e) + 0xF) & ~0xF);
    var_a3 = 0;
    if ((u32)((s32)heap->base + heap->len) >= temp_v1) {
        var_a3 = temp_a1;
        heap->cur = (u8 *)temp_v1;
    }
    return (s32) var_a3;
}
