#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/80409A88.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "stddef.h"
#include "COMMON/UNUSED.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/PAK_MENU.H"
extern s32 D_800E63B8;

s32 func_804453F0_de(s32 arg0, Shared_PakMenu *pThis) {
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
s32 func_804453F0_de(s32 arg0, struct RecordRecAt20V1 *arg1) {
    s32 var_a0;
    var_a0 = D_800E63B8;
    if (arg1->inner->unkB0 & 0x20202) {
        var_a0 -= 1;
        if (var_a0 < 0) {
            var_a0 = 0x16;
        } else if (var_a0 == 0xE) {
            var_a0 = 0xB;
        }
    }
    if (arg1->inner->unkB0 & 0x4D101) {
        var_a0 += 1;
        if (var_a0 >= 0x17) {
            var_a0 = 0;
        } else if (var_a0 == 0xC) {
            var_a0 = 0xF;
        }
    }
    D_800E63B8 = var_a0;
    func_8025E2D4_de(var_a0);
    return 0;
}
#endif
