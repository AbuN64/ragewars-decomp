#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
#include "include_asm.h"

#if defined(VERSION_US_REV1)
s32 Frontend_WrapNodePairUsRev1(void) {
    SmpButton_WrapButtonWidget(0x3DA);
    SmpButton_WrapButtonWidget(0x3DB);
    return 0;
}
#endif

#if defined(VERSION_US)

int Frontend_WrapNodePairUs(void) { SmpButton_WrapButtonWidget(0x3DA); SmpButton_WrapButtonWidget(0x3DB); return 0; }
#endif

#if defined(VERSION_EU)

int Frontend_WrapNodePairEuropean(void) {
    SmpButton_WrapButtonWidget(0x3da);
    SmpButton_WrapButtonWidget(0x3db);
    return 0;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_EU_X)

int Frontend_WrapNodePairGerman(void) {
    SmpButton_WrapButtonWidget(0x3d4);
    SmpButton_WrapButtonWidget(0x3d5);
    return 0;
}
#endif
