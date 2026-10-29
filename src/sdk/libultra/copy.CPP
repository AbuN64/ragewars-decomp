#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"

s32 alHeapDBAlloc(s32 a, s32 b, void *c, s32 d, s32 e) {
    ALHeap *heap = c;
    u32 allocationStart;
    u32 allocationEnd;
    u32 allocatedAddress;

    allocationStart = (u32)heap->cur;
    allocationEnd = allocationStart + (((d * e) + 0xF) & ~0xF);
    allocatedAddress = 0;
    if ((u32)((s32)heap->base + heap->len) >= allocationEnd) {
        allocatedAddress = allocationStart;
        heap->cur = (u8 *)allocationEnd;
    }
    return (s32) allocatedAddress;
}

#if defined(VERSION_US)
char s_CopyOMParticText[8] =
    "OMPartic";
#endif
