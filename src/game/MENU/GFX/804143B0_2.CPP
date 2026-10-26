#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/SITYPE.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
f64 Gfx_GetConvertedCounterRatio(void) {
    return func_802C6970_us_rev1(func_802BADC0_de()) / func_802C6970_us_rev1(D_80149B00);
}
#endif
