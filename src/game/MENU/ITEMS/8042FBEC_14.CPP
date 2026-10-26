#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"

#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/SHAREDRECAT224.H"

s32 Items_ForwardRulesLock(void *unused, MenuRules *rules) {
    Ovlgame_PlacePlayerForRound(rules->locked);
    return 1;
}
#endif

#if defined(VERSION_EU)
#ifdef NON_MATCHING
extern char D_8011FAC0[];
extern void Ovlgame_ResetMatchControllerState(void *);
/* Pak/option page handler: while D_80145070 is 1 it runs Ovlgame_ResetMatchControllerState on the session, otherwise it clears the
   flag word at 0x5D0 of the record at 0x1C of its second argument. Returns one. */
s32 Items_HandleSessionOptionPage(void *unused, void **menu) {
    if (D_80145070 == 1) {
        Ovlgame_ResetMatchControllerState(D_8011FAC0);
    } else {
        *(s32 *)((u8 *)menu[7] + 0x5D0) = 0;
    }
    return 1;
}
#else
INCLUDE_ASM("ovl_80400000", Items_HandleSessionOptionPage);
#endif
#ifdef NON_MATCHING
extern u8 D_80152235_eu, D_80152236_eu, D_80152237_eu, D_80152238_eu, D_80152239_eu, D_8015223A_eu, D_8015223B_eu, D_8015223D_eu;
extern char *D_auto_800E3EA4[], *D_auto_800E3EB4[], *D_auto_800E3EC4[], *D_auto_800E3ED4[], *D_auto_800E3EE4[],
    *D_auto_800E3EF4[], *D_auto_800E3F04[], *D_auto_800E3F14[], *D_auto_800E3F24[], *D_auto_800E3F34[],
    *D_auto_800E3F44[], *D_auto_800E3F54[], *D_auto_800E3F64[], *D_auto_800E3F74[], *D_auto_800E3F84[], *D_auto_800E3F94[];
/* Picks the label for each of the eight option rows (ids 2..9): the first text when the row's flag is set, else the second. */
typedef struct { s32 id; u8 pad4[0x10]; char ***text; } OptionRowEu;
s32 Items_SelectOptionRowLabel(OptionRowEu *row) {
    switch (row->id) {
    case 2: row->text = D_80152235_eu ? D_auto_800E3EA4 : D_auto_800E3EB4; break;
    case 3: row->text = D_80152236_eu ? D_auto_800E3EC4 : D_auto_800E3ED4; break;
    case 4: row->text = D_80152237_eu ? D_auto_800E3EE4 : D_auto_800E3EF4; break;
    case 5: row->text = D_80152238_eu ? D_auto_800E3F04 : D_auto_800E3F14; break;
    case 6: row->text = D_80152239_eu ? D_auto_800E3F24 : D_auto_800E3F34; break;
    case 7: row->text = D_8015223A_eu ? D_auto_800E3F44 : D_auto_800E3F54; break;
    case 8: row->text = D_8015223B_eu ? D_auto_800E3F64 : D_auto_800E3F74; break;
    case 9: row->text = D_8015223D_eu ? D_auto_800E3F84 : D_auto_800E3F94; break;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Items_SelectOptionRowLabel);
#endif
#endif

#if defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_8043EF1C_us_rev1[12] = { 0x00431023U, 0x3C01800EU, 0xC4202390U, 0x3C018014U, 0xE42068B0U, 0x8C84000CU, 0x3C03FBFFU, 0x8C820030U, 0x3463FFFFU, 0x00431024U, 0x03E00008U, 0xAC820030U };
#endif

#if defined(VERSION_US)
unsigned int D_auto_rodata_unresolved_8043EF1C[12] = {
    0x41444745, 0x3C01800E, 0xC420D010, 0x3C018014, 0xE42007F0, 0x8C84000C, 0x3C03FBFF, 0x8C820030,
    0x3463FFFF, 0x00431024, 0x03E00008, 0xAC820030,
};
#endif

#if defined(VERSION_EU)
const unsigned int D_auto_rodata_unresolved_800EE934[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E9B35[3] = {
    0x00, 0x00, 0x00,
};
#endif
