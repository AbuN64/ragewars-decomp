#include "COMMON/CHEATCODE.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "TYPES.H"

#if defined(VERSION_DE)
/* Calls SmpButton_WrapButtonWidget with 0x3D0 and then 0x3D1, and returns zero. */
s32 func_804377E8_de(void) {
#if defined(VERSION_DE)
    SmpButton_WrapButtonWidget(0x3CA);
    SmpButton_WrapButtonWidget(0x3CB);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    SmpButton_WrapButtonWidget(0x3D0);
    SmpButton_WrapButtonWidget(0x3D1);
#elif defined(VERSION_EU_X)
    SmpButton_WrapButtonWidget(0x3D4);
    SmpButton_WrapButtonWidget(0x3D5);
#endif
    return 0;
}
#endif
