#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
void alHeapInit(ALHeap *heapStorage, u8 *base, s32 byteCount) {
    s32 alignmentBytes;
    alignmentBytes = 0x10 - ((s32) base & 0xF);
    if (alignmentBytes != 0x10) {
        (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->left) = (s32) (base + alignmentBytes);
    } else {
        (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->left) = (s32) base;
    }
    (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->right) = byteCount;
    (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->bottom) = 0;
    (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->top) = (s32) (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->left);
}
#endif

