#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
typedef struct DraftConfigAB97C { u8 pad[0x8F]; u8 mode; } DraftConfigAB97C;
typedef struct DraftChoiceAB97C { s8 enabled, kind; } DraftChoiceAB97C;
typedef struct DraftWeaponAB97C { u8 pad[0x14]; u32 flags; } DraftWeaponAB97C;
typedef struct DraftPlayerAB97C {
    u8 pad[8]; Vec3 position; u8 pad14[0x24]; u32 flags;
    u8 pad3C[0x59C]; DraftConfigAB97C *config; void *ui;
    u8 pad5E0[0x22]; DraftChoiceAB97C choices[22]; s16 current;
    u8 pad630[0x140]; s16 next;
} DraftPlayerAB97C;
typedef struct DraftPickupAB97C { u8 **text; s16 pad4, sound, event, padA, index, arg1, arg2; } DraftPickupAB97C;
extern u8 D_801462E5;
extern s32 D_801468F4;
extern DraftWeaponAB97C *D_800D052C[];
#include "shared/menu_match_globals.h"
extern s32 func_80222BE8_de(void *, s32, s32), func_8025DE54_de(s16, Vec3, s32, s32);
extern void func_802391AC_de(void *, s32, s32, s32, s32, s32, s32, s32);
extern void *func_80237E80_de(void *, void *, u8 *);
s32 func_802AB97C_de(DraftPlayerAB97C *player, DraftPickupAB97C *pickup)
{
    s32 changed = 0;
    s8 owned;
    u32 flags;
    u8 **text;
    s16 sound, event;
    if (pickup->arg1 != -1 && player->choices[pickup->index].enabled) {
        changed = func_80222BE8_de(player, pickup->arg1, pickup->arg2);
        if (!changed && !(D_801462E5 && player->config->mode && D_801468F4)) return 0;
    }
    flags = D_800D052C[pickup->index]->flags;
    if (D_801462E5) { if (!(flags & 8)) return 0; }
    else if (flags & 8) return 0;
    owned = player->choices[pickup->index].enabled;
    player->choices[pickup->index].enabled = 1;
    if (player->current < pickup->index) {
        if (player->flags & 0x1000) flags = D_800D052C[pickup->index]->flags & 2;
        else flags = D_800D052C[pickup->index]->flags & 1;
        if (flags && !D_801462E5 && !owned) player->next = pickup->index;
    }
    text = pickup->text; sound = pickup->sound; event = pickup->event;
    if (player->ui) {
        func_802391AC_de(player->ui, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) func_80237E80_de(&D_80145088, player->ui, *text);
    }
    if (sound) func_8025DE54_de(sound, player->position, 0, -1);
    if (event) func_8025E11C_de(event);
    if (!changed) func_80222BE8_de(player, pickup->arg1, pickup->arg2);
    return 1;
}
