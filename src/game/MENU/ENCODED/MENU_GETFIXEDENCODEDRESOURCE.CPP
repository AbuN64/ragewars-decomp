#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"

/* 80406A88_20.CPP */

/* 80408AC4_6.CPP */
#if defined(VERSION_DE)
const unsigned int g_Encoded_HandleUnlockedLevelSelectionConstantWords[35] = {
    0x0043C6C4, 0x0043C6CC, 0x0043C6D4, 0x0043C6DC, 0x0043C6E4, 0x0043C6EC, 0x0043C6F4, 0x0043C6FC,
    0x0043C704, 0x0043C70C, 0x0043C714, 0x00000000, 0x0043C820, 0x0043C828, 0x0043C830, 0x0043C838,
    0x0043C840, 0x0043C848, 0x0043C850, 0x0043C858, 0x0043C860, 0x0043C868, 0x0043C870, 0x00000000,
    0x0043C908, 0x0043C910, 0x0043C918, 0x0043C920, 0x0043C928, 0x0043C930, 0x0043C938, 0x0043C940,
    0x0043C948, 0x0043C950, 0x0043C958,
};
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
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

extern s32 Control_IsAButtonPressed(s32 buttons);

struct GameSession;
extern void SetN64_SelectSpawnAndStartSession(struct GameSession *menu, s32 target);
extern s32 SetN64_IsModeThirteen(void);

extern void Scene_SetSelection(void *menu, s32 target, s32 mode);

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

static inline s32 findUnlocked(s32 level, s32 step) {
    s32 i;

    for (i = 0; i < 11; i++) {
        level += step;
        if (level >= 11) {
            level = 0;
        } else if (level < 0) {
            level = 10;
        }
        if (g_gameSettings.unlockedLevels & levelBit(level)) {
            return level;
        }
    }
    return -1;
}

s32 Encoded_HandleUnlockedLevelSelection(s32 levelId, Shared_MenuInput *pad) {
    s32 target;
    Shared_Game *rules;

    switch (g_encodedSelectedLevelIndex) {
    default:
    case 0:
        target = 1000;
        break;
    case 1:
        target = 2000;
        break;
    case 2:
        target = 3000;
        break;
    case 3:
        target = 4000;
        break;
    case 4:
        target = 5000;
        break;
    case 5:
        target = 6000;
        break;
    case 6:
        target = 7401;
        break;
    case 7:
        target = 7501;
        break;
    case 8:
        target = 7601;
        break;
    case 9:
        target = 7602;
        break;
    case 10:
        target = 8000;
        break;
    }

    if (Control_IsAButtonPressed(pad->buttons) != 0) {
        if (target == 8000) {
            g_gameSettings.mode1E = 1;
            Confirming_SelectConfirmingController(pad);
            SetN64_SetTransitionTarget(&g_gameSession, 0x11);
            return 1;
        }
        if (SetN64_IsModeThirteen() != 0) {
            Scene_SetSelection(&g_world, target, 2);
            return 0;
        }
        rules = &g_gameSettings;
        rules->local = 0;
        rules->mode1E = 1;
        Confirming_SelectConfirmingController(pad);
        SetN64_SelectSpawnAndStartSession(&g_gameSession, target);
        return 1;
    }

    if (((s32 (*)(s32))Control_IsLeftPressed)(pad->buttons) != 0) {
        g_encodedSelectedLevelIndex = findUnlocked(g_encodedSelectedLevelIndex, -1);
    } else if (((s32 (*)(s32))Control_IsRightPressed)(pad->buttons) != 0) {
        g_encodedSelectedLevelIndex = findUnlocked(g_encodedSelectedLevelIndex, 1);
    }
    return 0;
}
#endif

/* 8040C640_13.CPP */

/* 8042FBEC_13.CPP */

