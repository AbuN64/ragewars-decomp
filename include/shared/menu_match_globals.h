#ifndef RW_MENU_MATCH_GLOBALS_H
#define RW_MENU_MATCH_GLOBALS_H
#include "types.h"

/* The retained match-state consumers identify the same resident root:
 * US-rev1 D_80145088, input byte +0x125D, status word +0x180C.
 * These are persistent state fields, with the actual root storage between. */
typedef struct MenuMatchGlobals {
    u8 unobserved0[0x125D];
    u8 menuInput;
    u8 unobserved125E[0x17F0 - 0x125E];
    s32 status[8];
    u8 unobserved1810[0x186C - 0x1810];
    s32 regenPaused; /* menuInput + MultiplayerOptions.session + SessionState.paused */
} MenuMatchGlobals;
extern MenuMatchGlobals D_80145088;
#define D_801462E5 D_80145088.menuInput
#define D_80146894 D_80145088.status[7]

#endif
