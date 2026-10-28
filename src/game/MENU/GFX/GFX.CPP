#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/SITYPE.H"

/* 804143B0.CPP */
#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
/* Ratio of the cycle counter Audio_ReadSystemTime returns to the counter rate D_80149B00, each converted to a double. */
extern u64 Audio_ReadSystemTime(void);
extern double func_802C1880_de(s64 value);
f64 Gfx_GetNormalizedCounter(void) {
    return func_802C1880_de(Audio_ReadSystemTime()) / func_802C1880_de(D_80149B00);
}
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_8041447C[1] = {
    0x5F47524F,
};
#endif

/* 804143B0_2.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
f64 Gfx_GetConvertedCounterRatio(void) {
    return func_802C6970_us_rev1(Audio_ReadSystemTime()) / func_802C6970_us_rev1(D_80149B00);
}
#endif
