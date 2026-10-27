#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/EXTERNS_20.H"
#include "TYPES.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Marks two loading-screen hint slots (0x1D9 and 0x1DA) unused. */



s32 Frontend_ClearLoadingHints(void) {
    SmpButton_WrapButtonWidget(0x1D9);
    SmpButton_WrapButtonWidget(0x1DA);
    return 0;
}
#endif
