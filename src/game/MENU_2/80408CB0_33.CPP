#include "COMMON/EXTERNS_20.H"

#if defined(VERSION_EU)
/* Marks two loading-screen hint slots (0x1D9 and 0x1DA) unused. */
#include "TYPES.H"
#include "COMMON/OWNERRECAT8V1.H"


s32 func_80429B00_eu(void) {
    func_8041B110_de(0x1D9);
    func_8041B110_de(0x1DA);
    return 0;
}
#endif
