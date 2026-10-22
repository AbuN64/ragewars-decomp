#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "TYPES.H"
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

#if defined(VERSION_EU)
unsigned char D_auto_func_802B0630_eu_padding_B1264[12] = { 0x14, 0x86, 0xFF, 0xFC, 0x24, 0x63, 0x00, 0x14, 0x00, 0x00, 0x80, 0x21 };
#endif
