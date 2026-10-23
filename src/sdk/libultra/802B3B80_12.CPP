#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
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

#if defined(VERSION_US)
char rodata_unresolved_802B02B8[8] =
    "OMPartic";
#endif
