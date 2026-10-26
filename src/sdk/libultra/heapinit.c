#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"

#if !(defined(VERSION_EU))
void alHeapInit(void *heap, u8 *base, s32 byteLength) {
    s32 alignmentOffset;
    alignmentOffset = 0x10 - ((s32) base & 0xF);
    if (alignmentOffset != 0x10) {
        (((struct Shape_typemap_6 *) ((s8 *) heap))->field_0) = (s32) (base + alignmentOffset);
    } else {
        (((struct Shape_typemap_6 *) ((s8 *) heap))->field_0) = (s32) base;
    }
    (((struct Shape_typemap_6 *) ((s8 *) heap))->field_8) = byteLength;
    (((struct Shape_typemap_6 *) ((s8 *) heap))->field_C) = 0;
    (((struct Shape_typemap_6 *) ((s8 *) heap))->field_4) = (s32) (((struct Shape_typemap_6 *) ((s8 *) heap))->field_0);
}
#endif

#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
unsigned short func_802B03C4_de_padding_B12A4[6] = {
    0x0043, 0x1021, 0xA050, 0x000A, 0x8E51, 0x0064,
};
#endif
#endif

#if defined(VERSION_DE)
unsigned int func_802B03C4_de_padding_B0FC4[3] = {
    0xAFB00018, 0x00808021, 0xAFB1001C,
};
#endif
