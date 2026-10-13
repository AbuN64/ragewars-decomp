#ifndef RW_ROUND_STATE_VARIANTS_H
#define RW_ROUND_STATE_VARIANTS_H
#include "types.h"
extern void func_802954E0_us_rev1(void), func_80294F1C_us_rev1(void);
extern s32 D_800D2970;
extern f32 D_800CA5C4, D_800C54D8_de;
extern void func_802A2224_de(void), func_802A2344_eu(void), func_802A2374_eu_x(void), func_802A2164_us(void);
static inline void resetRoundExtra(void) {
#if defined(VERSION_US_REV1)
func_802954E0_us_rev1();
#endif
}
static inline void clearRoundExtra(void) {
#if defined(VERSION_US_REV1)
D_800D2970 = 0;
#endif
}
static inline f32 roundTimerConstant(void) {
#if defined(VERSION_US_REV1)
return D_800CA5C4;
#else
return D_800C54D8_de;
#endif
}
static inline void updateRoundExtra(void) {
#if defined(VERSION_US_REV1)
func_80294F1C_us_rev1();
#endif
}
static inline void stopRoundPlatform(void) {
#if defined(VERSION_DE)
func_802A2224_de();
#elif defined(VERSION_EU)
func_802A2344_eu();
#elif defined(VERSION_EU_X)
func_802A2374_eu_x();
#else
func_802A2164_us();
#endif
}

#endif
