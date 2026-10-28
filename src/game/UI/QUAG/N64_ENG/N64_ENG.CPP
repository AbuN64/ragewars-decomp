#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/GFX_INITIALIZEFRONTENDSERVICES.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/TEXTURE.H"
#include "MENU/GFX/GFX_GETCONVERTEDCOUNTERRATIO.H"
#include "MATH/802A2870.H"
#include "MENU/GFX/RECT.H"
#include "MATH/SMSMNGR_INITIALIZESCREENMANAGER.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
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

/** Perform no operation. */
void N64Eng_RenderNoop(void) {
}

void N64Eng_ResetRenderState(void) { Rect_ResetRenderState(); }

/** Copy the global two-word record into the two output pointers. */
void N64Eng_GetScreenSize(int *arg0, int *arg1) {
    *arg0 = D_800E28D0;
    *arg1 = D_800E28D4;
}

int N64Eng_GetFrameCounter(void) {
    return D_800D2C18;
}

/** Increment the global counter D_800D2C18. */
void N64Eng_AdvanceFrameCounter(void) {
    D_800D2C18 += 1;
}

void N64Eng_RegisterNumericWidgetClass(void) {
    SmSmngr_RegisterElementHandlers(0xB65, D_002A1B50, D_002A1BE0, 3);
}

/* ROM-grounded data: rodata/writable/800D2C18 */
#ifdef VERSION_DE
unsigned int D_blob_phase2_346e9edb07d1cfeff80c[2] = {
    0x00000000, 0x0000000F,
};
#endif
#ifdef VERSION_EU
unsigned int D_blob_phase2_346e9edb07d1cfeff80c[2] = {
    0x00000000, 0x00000000,
};
#endif
#ifdef VERSION_EU_X
unsigned int D_blob_phase2_346e9edb07d1cfeff80c[2] = {
    0x00000000, 0x74000000,
};
#endif
#ifdef VERSION_US
unsigned int D_blob_phase2_346e9edb07d1cfeff80c[2] = {
    0x00000000, 0x50414354,
};
#endif
#ifdef VERSION_US_REV1
unsigned int D_blob_phase2_346e9edb07d1cfeff80c[2] = {
    0x00000000, 0x20626F72,
};
#endif
