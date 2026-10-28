#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "MENU/OBJECT1C8.H"
#include "MENU/ITEMS/80442BC8_14.H"

/* 80442BC8_13.CPP */
#if defined(VERSION_EU)
#ifdef NON_MATCHING
#include "TYPES.H"

/* Stores what Menu_ClassifyResourceRange returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 1. */
extern s32 D_8013B2BC;
extern s32 Menu_ClassifyResourceRange(s32);

void Items_CacheIdentifierBand(void) {
    D_801540F4 = Menu_ClassifyResourceRange(D_8013B2BC);
    D_801540F0 = 1;
}
#else
INCLUDE_ASM("ovl_80400000", Items_CacheIdentifierBand);
#endif
#endif

#if defined(VERSION_US_REV1)
/* Stores what Menu_ClassifyResourceRange returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 1. */
extern s32 D_8013B2BC;

extern s32 Menu_ClassifyResourceRange(s32);

void Items_CacheIdentifierBand(void) {
    D_801540F4 = Menu_ClassifyResourceRange(D_8013B2BC);
    D_801540F0 = 1;
}
#endif

/* 80443530_2.CPP */
#if defined(VERSION_US)
#include "TYPES.H"
extern s32 D_8013B2BC;
extern s32 Menu_ClassifyResourceRange(s32);

void Items_PrepareMenuReturnUs(void) {
    D_801540F4 = Menu_ClassifyResourceRange(D_8013B2BC);
    D_801540F0 = 1;
}
#endif

/* 80406A88_23.CPP */
#if defined(VERSION_EU_X)
extern int Menu_ClassifyResourceRange(s32);

void Items_PrepareControllerReturnEuX(s32 arg0) {
    D_801540F4 = Menu_ClassifyResourceRange(arg0);
    D_801540F0 = 0;
}
#endif

/* 8043D1DC_7.CPP */
#if defined(VERSION_DE)
extern int D_8013B2BC;
extern int D_801540F4;
extern int D_801540F0;
extern int func_802AD2A8_de(int);

void Items_PrepareMenuReturnDe(void) {
    D_801540F4 = func_802AD2A8_de(D_8013B2BC);
    D_801540F0 = 1;
}
#endif

/* 80442BC8_14.CPP */
#if !(defined(VERSION_EU_X))
/* Stores what Menu_ClassifyResourceRange returns for D_8013B2BC in D_801540F4 and sets D_801540F0 to 0. */
extern s32 D_8013B2BC;
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern s32 Menu_ClassifyResourceRange(s32);
#else
extern s32 func_802AD2A8(s32);
#endif

void Items_PrepareControllerReturn(void) {
    D_801540F4 =
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
Menu_ClassifyResourceRange
#else
func_802AD2A8
#endif
(D_8013B2BC);
    D_801540F0 = 0;
}
#endif

/* 800E2730.CPP */
#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: rodata/shared/800E2730 */
const unsigned char g_fmtDec4Pad[] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
#if defined(VERSION_US)
    0x00, 0x00, 0x00,
#endif
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif
