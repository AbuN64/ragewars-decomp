#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENURECAT20V1.H"
#include "MULTI/804453C4.H"
#include "TYPES.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "MENU/PAK/pak_menu_entries.H"
#include "MULTI/804453C4_9.H"

#if !(defined(VERSION_US))
/* Sets a player state to 2, then in multiplayer (D_801462E5) clears and otherwise sets bit 0x800000 in both of its actor's visibility masks at 0x80 and 0xA8, and refreshes the audio state through func_8025CC6C_de and func_8025CAB0_de with that mask. */





extern s32 func_8025CC6C_de(s32 mask);
extern void func_8025CAB0_de(s32 value);

void func_8044560C_de(PlayerRecAtC *player) {
    s32 mask;

    player->state = 2;
    Control_SaveControllerSetup();
    mask = 0x800000;
    if (D_801462C8.local != 0) {
        mask = 0xFF7FFFFF;
        player->actor->mask80 &= mask;
        player->actor->maskA8 &= mask;
    } else {
        player->actor->mask80 |= mask;
        player->actor->maskA8 |= mask;
    }
    func_8025CAB0_de(func_8025CC6C_de(mask));
}

/* Calls func_8026495C_de and nothing else. */

void func_8044569C_de(void) {
    Control_RestoreControllerSetup();
}

/* Calls Pak_DrawMenuEntries and nothing else. */

void func_804456B8_de(struct MenuStyle *menu, s8 *member) {
    Pak_DrawMenuEntries(menu, member);
}
#endif

#if defined(VERSION_EU_X)
unsigned int func_80446A4C_eu_x_padding_136A4C[1] = {
    0x0C111ECF,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8044691C_eu_padding_1BC91C[1] = {
    0x46010001,
};
#endif
