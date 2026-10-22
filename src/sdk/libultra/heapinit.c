#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"

#if !(defined(VERSION_EU))
void alHeapInit(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    temp_v1 = 0x10 - (arg1 & 0xF);
    if (temp_v1 != 0x10) {
        (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_0) = (s32) (arg1 + temp_v1);
    } else {
        (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_0) = arg1;
    }
    (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_8) = arg2;
    (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_C) = 0;
    (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_4) = (s32) (((struct Shape_typemap_6 *) ((s8 *) arg0))->field_0);
}
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_802B03C4_de_padding_B12A4);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("span_1000", func_802B03C4_de_padding_B0FC4);
#endif
