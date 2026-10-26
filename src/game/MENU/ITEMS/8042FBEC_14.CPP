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
