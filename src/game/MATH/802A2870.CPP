#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/EXTERNS_4.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/TEXTURE.H"
#include "MENU/GFX/804143B0_2.H"
#include "MATH/802A2870.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern f64 Gfx_GetConvertedCounterRatio(void);
#else
extern f64 Gfx_GetNormalizedCounter(void);
#endif

/** Store four arguments in the adjacent global state words. */
void N64Eng_SetClipBounds(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) {
    D_800CD990_de = a0;
    D_800CD994 = a1;
    D_800CD998 = a2;
    D_800CD99C = a3;
}

void N64Eng_GetClipBounds(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {

    *arg0 = D_800CD990_de;
    *arg1 = D_800CD994;
    *arg2 = D_800CD998;
    *arg3 = D_800CD99C;
}

f64 N64Eng_GetTimeSeconds(void) {
    return 
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
Gfx_GetConvertedCounterRatio
#else
Gfx_GetNormalizedCounter
#endif
() - (0.0);
}
