#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "COMMON/EXTERNS_20.H"
#include "TYPES.H"

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* Marks two loading-screen hint slots (0x1D9 and 0x1DA) unused. */



s32 func_80429178_us_rev1(void) {
    func_8041B110_de(0x1D9);
    func_8041B110_de(0x1DA);
    return 0;
}
#endif
