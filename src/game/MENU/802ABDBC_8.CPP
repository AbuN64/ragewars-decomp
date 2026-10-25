#include "include_asm.h"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECATE.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"

/* Returns whether a player actor can use the item picked up through func_8024E924_de: never for non-players or disabled actors, always during a team round when the model says so, and otherwise by the item's table: a D_800D31D0 power-up when the actor's team matches a D_800CE474 entry or its slot is free while not both states 3 and 7 are in use, a D_800D3230 weapon when on those teams or below the level from func_8022ACB8_de, a D_800D32A8 item when func_8022AC00_de exceeds the actor's count at 0x5E4, any D_800D34C0 item, and a D_800D3390 item unless it is item 0xBD6. */
extern s32 D_800CE474[2];
extern s32 func_8024E924_de(s32 arg0);
extern s32 func_8022ACB8_de(Actor_func_802AB400_de *actor, s16 index, s32 arg2);
extern s32 func_8022AC00_de(Actor_func_802AB400_de *actor, s32 id);
static inline EntryRecAtE *find_entry(char *table, s32 count, s32 size, s32 id) {
    EntryRecAtE *entry;
    s32 i;
    entry = (EntryRecAtE *)table;
    for (i=count; i!=-1; --i) {
        if (entry->id == id) return entry;
        entry=(EntryRecAtE *)((char *)entry+size);
    }
    return 0;
}
s32 func_802AB400_de(s32 arg0, Actor_func_802AB400_de *actor) {
    EntryRecAtE *powerup;
    EntryRecAtE *weapon;
    EntryRecAtE *item;
    EntryRecAtE *bonus;
    EntryRecAtE *special;
    s32 id;
    s32 level;
    s32 noState3;
    s32 noState7;
    s32 i;
    Actor_func_802AB400_de *player;
    id = func_8024E924_de(arg0);
    if (((actor)->type == 1 && ((actor)->flags & 0x300000) != 0)) {
        player = actor;
        if (player->count == 0) {
            return 0;
        }
        if (D_801468F4 != 0 && player->model->unk8F != 0) {
            return 1;
        }
        powerup = find_entry(&D_800D31D0, 3, 0x18, id);
        if (powerup != 0) {
            noState3 = 1;
            noState7 = 1;
            if (player->team == D_800CE474[0] || player->team == D_800CE474[1]) {
                return 1;
            }
            if (player->slots[powerup->index].pad1 != -1) {
                return 0;
            }
            for (i = 0; i < 22; i++) {
                if (player->slots[i].pad1 == 3) {
                    noState3 = 0;
                } else if (player->slots[i].pad1 == 7) {
                    noState7 = 0;
                }
            }
            if (noState3 || noState7) {
                return 1;
            }
            return 0;
        }
        weapon = find_entry(&D_800D3230, 5, 0x14, id);
        if (weapon != 0) {
            level = func_8022ACB8_de(player, weapon->index, 0);
            if (player->team == D_800CE474[0] || player->team == D_800CE474[1]) {
                return 1;
            }
            return player->levels[weapon->index] < level;
        }
        item = find_entry(&D_800D32A8, 7, 0x18, id);
        if (item != 0) {
            return player->count < func_8022AC00_de(player, id);
        }
        bonus = find_entry((char *)D_800D34C0, 15, 0x18, id);
        if (bonus != 0) {
            return 1;
        }
        special = find_entry(&D_800D3390, 2, 0x10, id);
        if (special != 0) {
            if ((player->team == D_800CE474[0] || player->team == D_800CE474[1]) && special->id != 0xBD6) {
                return 1;
            }
            return special->id != 0xBD6;
        }
        return 0;
    }
    return ((actor)->type == 1 && ((actor)->flags & 0x300000) != 0);
}
typedef struct Handler Handler;
/* Dispatches an item effect with the given id to an actor that can receive it: looks the id up in each item handler table in turn (D_800D31D0, D_800D3230, D_800D32A8, D_800D3368, D_800D34C0, D_800D33C0 and D_800D3390) and returns the first nonzero handler result, clearing the given target from every actor's two lock-on slots after the D_800D34C0 handler. */
extern Other *D_80145060;
static inline Handler *find_handler(char *table, s32 count, s32 size, s32 id) {
    Handler *entry;
    s32 i;
    entry = (Handler *)table;
    i = count;
    do {
        if (entry->id == id) {
            return entry;
        }
        i--;
        entry = (Handler *)((char *)entry + size);
    } while (i != -1);
    return 0;
}
s32 func_802AB6EC_de(Other *actor, s32 target, s32 id) {
    Handler *entry;
    Other *other;
    s32 result;
    result = 0;
    if (actor->enabled != 0) {
        entry = find_handler(&D_800D31D0, 3, 0x18, id);
        if (entry != 0) {
            result = entry->handle14(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D3230, 5, 0x14, id);
        if (entry != 0) {
            result = entry->handle10(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D32A8, 7, 0x18, id);
        if (entry != 0) {
            result = entry->handle14(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D3368, 1, 0x14, id);
        if (entry != 0) {
            result = entry->handle10(actor, entry);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler((char *)D_800D34C0, 15, 0x18, id);
        if (entry != 0) {
            result = entry->handle14(actor, entry);
        }
        for (other = D_80145060; other != 0; other = other->next) {
            if (other->lockOn[0] == target) {
                other->lockOn[0] = 0;
            } else if (other->lockOn[1] == target) {
                other->lockOn[1] = 0;
            }
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D33C0, 15, 0x10, id);
        if (entry != 0) {
            result = entry->handleC.targeted(actor, entry, target);
        }
        if (result != 0) {
            return result;
        }
        entry = find_handler(&D_800D3390, 2, 0x10, id);
        if (entry != 0) {
            result = entry->handleC.plain(actor, entry);
        }
    }
    return result;
}

#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENU_ABBDC_VERSIONS.H"
typedef struct DraftConfigAB97C { u8 pad[0x8F]; u8 mode; } DraftConfigAB97C;
typedef struct DraftChoiceAB97C { s8 enabled, kind; } DraftChoiceAB97C;
typedef struct DraftWeaponAB97C { u8 pad[0x14]; u32 flags; } DraftWeaponAB97C;
typedef struct DraftPlayerAB97C {
    u8 pad[8]; CVector3 position; u8 pad14[0x24]; u32 flags;
    u8 pad3C[0x59C]; DraftConfigAB97C *config; void *ui;
    u8 pad5E0[0x22]; DraftChoiceAB97C choices[22]; s16 current;
    u8 pad630[0x140]; s16 next;
} DraftPlayerAB97C;
typedef struct DraftPickupAB97C { u8 **label; s16 pad4, sound, event, padA, index, arg1, arg2; } DraftPickupAB97C;
extern DraftWeaponAB97C *D_800D052C[];
#include "COMMON/MENU_MATCH_GLOBALS.H"
extern void *Camera_PostScreenMessage(void *, void *, u8 *);
extern s32 func_80222BE8_de(void *, s32, s32), Render_PlaySoundAtPosition(s16, CVector3, s32, s32);
extern void func_802391AC_de(void *, s32, s32, s32, s32, s32, s32, s32);

s32 Menu_ApplyWeaponPickup(DraftPlayerAB97C *player, DraftPickupAB97C *pickup)
{
    s32 changed = 0;
    s32 owned;
    DraftWeaponAB97C *weapon;
    u8 **label;
    s32 sound, event;
    if (pickup->arg1 != -1 && player->choices[pickup->index].enabled) {
        changed = func_80222BE8_de(player, pickup->arg1, pickup->arg2);
        if (!changed) {
            Shared_Game *game = &D_801462C8;
            if (!(game->local && player->config->mode && game->unk62C)) return 0;
        }
    }
    if (D_801462E5) { if (!(D_800D052C[pickup->index]->flags & 8)) return 0; }
    else if (D_800D052C[pickup->index]->flags & 8) return 0;
    owned = player->choices[pickup->index].enabled;
    player->choices[pickup->index].enabled = 1;
    weapon = D_800D052C[pickup->index];
    if (player->current < pickup->index) {
        if (player->flags & 0x1000 ? weapon->flags & 2 : weapon->flags & 1) {
            if (!D_801462E5 && !owned) player->next = pickup->index;
        }
    }
    label = pickup->label; sound = pickup->sound; event = pickup->event;
    if (player->ui) {
        func_802391AC_de(player->ui, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (label != 0) Camera_PostScreenMessage(&D_80145088, player->ui, label[MENU_LANGUAGE]);
    }
    if (sound) Render_PlaySoundAtPosition(sound, player->position, 0, -1);
    if (event) func_8025E11C_de(event);
    if (!changed) func_80222BE8_de(player, pickup->arg1, pickup->arg2);
    return 1;
}
