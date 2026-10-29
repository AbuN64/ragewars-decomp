#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/SITYPE.H"

/* 804143B0.CPP */
#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
/* Ratio of the cycle counter Audio_ReadSystemTime returns to the counter rate g_systemClockFrequency, each converted to a double. */
extern u64 Audio_ReadSystemTime(void);
extern double Libc_SignedLongLongToDouble(s64 value);
f64 Gfx_GetNormalizedCounter(void) {
    return Libc_SignedLongLongToDouble(Audio_ReadSystemTime()) / Libc_SignedLongLongToDouble(g_systemClockFrequency);
}
#endif
#if defined(VERSION_US)
unsigned int k_GfxEncodedWordsBlock1[1] = {
    0x5F47524F,
};
#endif

/* 804143B0_2.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
f64 Gfx_GetConvertedCounterRatio(void) {
    return Libc_SignedLongLongToDoubleUsRev1(Audio_ReadSystemTime()) / Libc_SignedLongLongToDoubleUsRev1(g_systemClockFrequency);
}
#endif
