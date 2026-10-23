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
