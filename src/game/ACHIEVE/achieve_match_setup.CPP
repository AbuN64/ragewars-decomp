#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GFX.H"
#include "COMMON/WORLD.H"
#include "COMMON/STATERECAT91.H"
#include "TYPES.H"
#include "ACHIEVE/achieve_match_setup.H"

/* Copies a player's enabled options into its option list: unless the player's info (at 0x5D8) is
   locked (byte 0x91 is 1) or absent (byte 0x78 is 0), each of the 22 option flags at 0x4C that is 1
   is recorded as the pair (1, value from 0x62) at 0x602 plus twice its index. */




void func_80426174_de(PlayerRecAt602 *p) {
    int i;

    if (p->info->locked != 1 && p->info->present != 0) {
        for (i = 0; i < 22; i++) {
            if (p->info->enabled[i] == 1) {
                p->options[i].flag = p->info->enabled[i];
                p->options[i].value = p->info->values[i];
            }
        }
    }
}

extern void *func_8028D474_de(void *, s32);

void func_804261DC_de(WeaponPlayer *player) {
    WeaponStatus *status = player->status;
    s32 i;
    u16 *entries;
    s32 id;
    s32 active;

    if (status->out != 1 && status->active != 0) {
        void *table = func_8028D474_de(&D_8011FE88, D_8015402C);
        i = 0;
        active = 1;
        entries = table;
        do {
            id = entries[3];
            if (id >= 0x4C3) {
                id -= 0x4C3;
                player->weapons[id][0] = active;
                player->weapons[id][1] = i;
            }
            i++;
            entries++;
        } while (i < 8);
    }
}

#include "COMMON/CHARACTERSELECTIONROOT.H"
extern MatchMenuApplySlotValueGfx D_801462C8;
extern s32 D_800FF140_de[];

s32 Achieve_MatchQualifies(void) {
    MatchMenuApplySlotValueGfx *match;
    s32 i;
    s32 count;
    s32 result;
    RosterSlot *slot;

    match = &D_801462C8;
    if (match->unk24 <= 0 && match->unk25 <= 0) {
        return 0;
    }
    result = 1;
    count = 0;
    for (i = 0; i < 8; i++) {
        slot = &D_801462C8.slots[i];
        if (slot->active == 1 && slot->m_IsBot != slot->active && D_800FF140_de[i] >= 76) {
            count++;
        }
    }
    if (count < 2) {
        result = 0;
    }
    return result;
}

#if defined(VERSION_EU_X)
char func_80426F98_eu_x_padding_116F98[8] =
    "\002\000(!P@\000\"";
#endif

#if defined(VERSION_DE)
unsigned int func_80426304_de_padding_18C304[3] = {
    0x02202021, 0x00002821, 0x2406013C,
};
#endif
