#ifndef COMMON_MENU_MATCH_GLOBALS_H
#define COMMON_MENU_MATCH_GLOBALS_H
#include "TYPES.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/ITEMRECAT20V1.H"

/* The retained match-state consumers identify the same resident root:
 * US-rev1 D_80145088, input byte +0x125D, status word +0x180C.
 * These are persistent state fields, with the actual root storage between. */
typedef struct MenuMatchGlobals {
    u8 unobserved0[0x20];
    GameplayCamera *cameras; /* 0x20 */
    u8 unobserved24[0x40 - 0x24];
    GameplayCamera fallbackCamera; /* 0x40 */
    u8 unobservedED8[0x1200 - 0xED8];
    s32 useFallbackCamera; /* 0x1200 */
    u8 unobserved1204[0x1240 - 0x1204];
    MenuSettings settings; /* 0x1240, menu input byte at settings.padding[0x1D] (+0x125D) */
    u8 unobserved17C2[0x17F0 - 0x17C2];
    s32 status[8];
    u8 unobserved1810[0x186C - 0x1810];
    s32 regenPaused; /* menuInput + MultiplayerOptions.session + SessionState.paused */
} MenuMatchGlobals;
extern MenuMatchGlobals D_80145088;
#define D_801462E5 D_80145088.settings.padding[0x1D]
#define D_80146894 D_80145088.status[7]
#endif
