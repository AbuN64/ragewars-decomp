#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
void alHeapInit(void *heapStorage, u8 *base, s32 byteCount) {
    s32 alignmentBytes;
    alignmentBytes = 0x10 - ((s32) base & 0xF);
    if (alignmentBytes != 0x10) {
        (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->field_0) = (s32) (base + alignmentBytes);
    } else {
        (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->field_0) = (s32) base;
    }
    (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->field_8) = byteCount;
    (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->field_C) = 0;
    (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->field_4) = (s32) (((struct MenuPlayerScissorRect *) ((s8 *) heapStorage))->field_0);
}
#endif

#if defined(VERSION_EU)
unsigned char g_HeapinitTrailingBytes[12] = { 0x14, 0x86, 0xFF, 0xFC, 0x24, 0x63, 0x00, 0x14, 0x00, 0x00, 0x80, 0x21 };
#endif
