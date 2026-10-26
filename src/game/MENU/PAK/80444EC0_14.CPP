#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/80409A88.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/UNUSED.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/PAK_MENU.H"

s32 Pak_SelectMusicPreview(s32 arg0, Shared_PakMenu *pThis) {
    s32 selection = D_800E63B8;
    if (pThis->owner->unkB0 & 0x20202) {
        selection--;
        if (selection < 0) {
            selection = 22;
        } else if (selection == 14) {
            selection = 11;
        }
    }
    if (pThis->owner->unkB0 & 0x4D101) {
        selection++;
        if (selection >= 23) {
            selection = 0;
        } else if (selection == 12) {
            selection = 15;
        }
    }
    D_800E63B8 = selection;
    func_8025E2D4_de(selection);
    return 0;
}
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Cycles a menu selection from directional input while skipping reserved entries. */
 /* extern */
s32 Pak_SelectMusicPreview(s32 unused, struct RecordRecAt20V1 *menu) {
    s32 musicSelection;
    musicSelection = D_800E63B8;
    if (menu->inner->unkB0 & 0x20202) {
        musicSelection -= 1;
        if (musicSelection < 0) {
            musicSelection = 0x16;
        } else if (musicSelection == 0xE) {
            musicSelection = 0xB;
        }
    }
    if (menu->inner->unkB0 & 0x4D101) {
        musicSelection += 1;
        if (musicSelection >= 0x17) {
            musicSelection = 0;
        } else if (musicSelection == 0xC) {
            musicSelection = 0xF;
        }
    }
    D_800E63B8 = musicSelection;
    func_8025E2D4_de(musicSelection);
    return 0;
}
#endif
