#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_2.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "SYSTEM/8025E280.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)

s32 Pak_RestoreAudioAndCloseMenu(void *first, void *second, void *third) { func_8025E214_de(-1); func_8025E29C_de(0); if (D_800E63B4 != 0) { func_8025E360_de(); } func_8025E2D4_de(D_800E63B0); Control_SetMenuControlFlag(); return Menu_TryCreateMenu(first, second, third); }

s32 Pak_AdjustVolumeSlotTwo(void *first, void *second) { u8 *option = &D_801462C8.volume[2]; s32 value = *option; value = Menu_AdjustValue(second, value, 8, 0, 0xFF, 0); if (value == 0xF7) { value = 0xF8; } *option = value; return 0; }
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Stops sound for a menu: calls func_8025E214_de with -1 and func_8025E29C_de with zero, calls
   func_8025E360_de when D_800E63B4 is set, passes D_800E63B0 to func_8025E2D4_de, calls Control_SetMenuControlFlag and
   returns what Menu_TryCreateMenu gives for the three arguments. */


extern s32 Menu_TryCreateMenu(void *, void *, void *);

s32 Pak_RestoreAudioAndCloseMenu(void *first, void *second, void *third) {
    func_8025E214_de(-1);
    func_8025E29C_de(0);
    if (D_800E63B4 != 0) {
        func_8025E360_de();
    }
    func_8025E2D4_de(D_800E63B0);
    Control_SetMenuControlFlag();
    return Menu_TryCreateMenu(first, second, third);
}

/* Replaces the option byte D_801462E2 with what Menu_AdjustValue returns for the second argument, that byte, 8, 0, 0xFF and 0, turning 0xF7 into 0xF8, and returns zero. */

extern s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Pak_AdjustVolumeSlotTwo(void *first, void *second) {
    u8 *option = &D_801462C8.volume[2];
    s32 value = *option;

    value = Menu_AdjustValue(second, value, 8, 0, 0xFF, 0);
    if (value == 0xF7) {
        value = 0xF8;
    }
    *option = value;
    return 0;
}
#endif
