#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"

#if !(defined(VERSION_EU))
void alHeapInit(ALHeap *heap, u8 *base, s32 byteLength) {
    s32 alignmentOffset;
    alignmentOffset = 0x10 - ((s32) base & 0xF);
    if (alignmentOffset != 0x10) {
        (((struct MenuPlayerScissorRect *) ((s8 *) heap))->left) = (s32) (base + alignmentOffset);
    } else {
        (((struct MenuPlayerScissorRect *) ((s8 *) heap))->left) = (s32) base;
    }
    (((struct MenuPlayerScissorRect *) ((s8 *) heap))->right) = byteLength;
    (((struct MenuPlayerScissorRect *) ((s8 *) heap))->bottom) = 0;
    (((struct MenuPlayerScissorRect *) ((s8 *) heap))->top) = (s32) (((struct MenuPlayerScissorRect *) ((s8 *) heap))->left);
}
#endif


