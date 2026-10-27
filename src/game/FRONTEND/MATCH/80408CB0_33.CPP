#include "COMMON/EXTERNS_20.H"

#if defined(VERSION_EU)
/* Marks two loading-screen hint slots (0x1D9 and 0x1DA) unused. */
#include "TYPES.H"
#include "COMMON/OWNERRECAT8V1.H"


s32 Frontend_ClearEuLoadingHints(void) {
    SmpButton_WrapButtonWidget(0x1D9);
    SmpButton_WrapButtonWidget(0x1DA);
    return 0;
}
#endif
