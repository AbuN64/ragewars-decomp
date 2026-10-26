#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
#include "include_asm.h"

#if defined(VERSION_US_REV1)
s32 func_80439F10_us_rev1(void) {
    SmpButton_WrapButtonWidget(0x3DA);
    SmpButton_WrapButtonWidget(0x3DB);
    return 0;
}
#endif

#if defined(VERSION_US)

int func_80439F10_us(void) { SmpButton_WrapButtonWidget(0x3DA); SmpButton_WrapButtonWidget(0x3DB); return 0; }
#endif

#if defined(VERSION_EU)

int func_8043AC00_eu(void) {
    SmpButton_WrapButtonWidget(0x3da);
    SmpButton_WrapButtonWidget(0x3db);
    return 0;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_EU_X)

int func_80439D30_de(void) {
    SmpButton_WrapButtonWidget(0x3d4);
    SmpButton_WrapButtonWidget(0x3d5);
    return 0;
}
#endif
