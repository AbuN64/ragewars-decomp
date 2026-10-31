#include "include_asm.h"

/* VisdataEmptyRegionalHooksEncodedWordsUnit.CPP */

/* 80290B90.CPP */
#if defined(VERSION_EU)
void Visdata_EmptyHookEu(void) {}
#endif


/* 80290BC0.CPP */
#if defined(VERSION_EU_X)
/** Perform no operation. */
void Visdata_EmptyHookEuX(void) {
}
#endif

/* 802944E8_8.CPP */
#if defined(VERSION_US)
/** Perform no operation. */
void Visdata_EmptyReleaseHookUs(void) {
}
#endif

#if defined(VERSION_US)
/** Perform no operation. */
void Visdata_EmptyReleaseHookSecondUs(void) {
}
#endif
