#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80217388.h"
#include "types.h"
/* Runs a player's weapon menu each frame: the menu button (0x8000 of the controller at 0x698) counts
   only while func_8022C460_de allows and the controller is not paused through D_801468F4, which instead
   closes the menu (state 3), as does holding the button while the value at 0x4 is positive; from a
   closed state holding it clears the pending weapon at 0xCC0, rebuilds the menu through func_802181FC_de
   and opens it, while releasing it with a weapon pending outside category 8 rebuilds it and marks it
   open; with no category the slot under the cursor from func_80217B3C_de, when it changes, plays sound
   0xD4D for an unowned weapon, forgets an empty slot, moves the cursor at 0x37C and requests the
   slot's weapon at 0x770 unless it is current, switching the slot to the weapon's alternate at 0xC of
   its D_800D052C record when the player holds that one and input bit 0x1000 is clear. */




extern s32 D_801468F4;
extern void *D_800D052C[];
extern s32 func_8022C460_de(void *);
extern void func_802181FC_de(void *, s32, void *);
extern s32 func_80217B3C_de(void *);
extern void func_8025DF34_de(s32);






void func_80217D74_de(s32 *menu, void *player) {
    s32 held;
    s32 slot;
    s32 category;
    Entry34 *entry;
    s16 weapon;
    s16 alternate;
    char *ammo;

    held = ((struct func_8021846C_S3 *) ((ObjectLinks11B8 *) player)->unk_698)->unkB0 & 0x8000;
    if (func_8022C460_de(player) != 0) {
        held = 0;
    }
    if (D_801468F4 != 0 && ((struct func_8020EA10_S3 *) ((ObjectLinks11B8 *) player)->unk_5D8)->unk8F == 1) {
        held = 0;
        menu[0] = 3;
    }
    if (held && ((struct func_802077F4_S2 *) menu)->unk4 > 0.0f) {
        menu[0] = 3;
    }
    if (menu[0] == 0 || menu[0] == 3) {
        if (!held) {
            if (((ObjectLinks11B8 *)(player))->unk_CC0 != -1 && menu[0x388 / 4] != 8) {
                func_802181FC_de(menu, 0, player);
                menu[0] = 1;
            }
            return;
        }
        ((ObjectLinks11B8 *)(player))->unk_CC0 = -1;
        func_802181FC_de(menu, held, player);
        ((ObjectLinks11B8 *)(player))->unk_11B4 = 1;
        menu[0] = 1;
    }
    category = menu[0x388 / 4];
    if (category != -1) {
        return;
    }
    slot = func_80217B3C_de(player);
    if (slot == menu[0x390 / 4]) {
        return;
    }
    if (slot != category) {
        entry = (Entry34 *)&((Block24 *)menu)[slot];
        weapon = entry->weapon;
        if (entry->owned == 0) {
            func_8025DF34_de(0xD4D);
            return;
        }
        if (weapon < 0) {
            menu[0x390 / 4] = category;
            return;
        }
        if (slot != menu[0x37C / 4]) {
            menu[0x37C / 4] = slot;
        }
        if (weapon == ((ObjectLinks11B8 *)(player))->unk_62E) {
            menu[0x390 / 4] = slot;
            return;
        }
        ((ObjectLinks11B8 *)(player))->unk_770 = weapon;
        if (!(((ObjectLinks11B8 *)(player))->unk_38 & 0x1000)) {
            alternate = ((WeaponInfo *)(D_800D052C[weapon]))->alternate;
            if (alternate != category && (ammo = (char *) player + alternate * 2)[0x602] != 0) {
                entry->weapon = alternate;
            }
        }
    }
    menu[0x390 / 4] = slot;
}
