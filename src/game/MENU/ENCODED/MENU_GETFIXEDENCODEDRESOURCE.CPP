#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"

/* 80406A88_20.CPP */

/* 80408AC4_6.CPP */

#if defined(VERSION_DE)
#ifdef NON_MATCHING
#include "COMMON/RESIDENT_EVENT_HANDLER.H"

/* The asm is 4 words: the decrement is the jr delay slot and sits in the split-off first word of Level_GetScreenEventTable; the compiler drops it and fills the slot with the ori. */
extern s32 g_menuFixedEncodedResource;

s32 *Menu_GetFixedEncodedResource(s32 resourceId) {
    resourceId -= 1;
    return &g_menuFixedEncodedResource;
}
#else
INCLUDE_ASM("ovl_frontendMenu", Menu_GetFixedEncodedResource);
#endif
#endif

#if !(defined(VERSION_DE))
#include "COMMON/SHARED_MENUSELECTION.H"

#include "COMMON/SHARED_GAMESLOT.H"

#include "COMMON/RUNTIME_DECLARATIONS.H"

#include "COMMON/GAME_SESSION.H"
#include "OVLGAME/SHAREDRECAT224.H"


static inline s32 levelBit(s32 level) {
    s32 bit;

    switch (level) {
    default:
    case 0:
        bit = 0x10000;
        break;
    case 1:
        bit = 0x20000;
        break;
    case 2:
        bit = 0x40000;
        break;
    case 3:
        bit = 0x80000;
        break;
    case 4:
        bit = 0x100000;
        break;
    case 5:
        bit = 0x200000;
        break;
    case 6:
        bit = 0x800000;
        break;
    case 7:
        bit = 0x400000;
        break;
    case 8:
        bit = 0x1000000;
        break;
    case 9:
        bit = 0x2000000;
        break;
    case 10:
        bit = 0x4000000;
        break;
    }
    return bit;
}

#include "MENU/HANDLE_UNLOCKED_LEVEL_SELECTION_BODY.H"

#endif

/* 8040C640_13.CPP */

/* 8042FBEC_13.CPP */
