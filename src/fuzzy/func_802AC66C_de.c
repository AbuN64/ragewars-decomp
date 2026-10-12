#include "types.h"
#include "common/types_8a8189af7b05.h"
typedef struct DraftConfigAC66C { u8 pad[0x8F]; u8 mode; } DraftConfigAC66C;
typedef struct DraftChoiceAC66C { u8 enabled; s8 kind; } DraftChoiceAC66C;
typedef struct DraftPlayerAC66C {
    u8 pad[8]; Vec3 position; u8 pad14[0xE4-0x14]; u16 id;
    u8 padE6[0x5D8-0xE6]; DraftConfigAC66C *config; void *ui;
    u8 pad5E0[0x602-0x5E0]; DraftChoiceAC66C choices[22];
    u8 pad62E[0xCC0-0x62E]; s32 selection;
} DraftPlayerAC66C;
typedef struct DraftPickupAC66C { u8 **text; s16 pad4, sound, event, padA, index, arg1, arg2; } DraftPickupAC66C;
extern s32 D_801468F4, D_800CE474[2];
extern char D_80145088;
extern void func_802391AC_de(void *, s32, s32, s32, s32, s32, s32, s32);
extern void *func_80237E80_de(void *, void *, u8 *);
extern s32 func_8025DE54_de(s16, Vec3, s32, s32);
extern void func_80222BE8_de(void *, s32, s32);
s32 func_802AC66C_de(DraftPlayerAC66C *player, DraftPickupAC66C *pickup)
{
    s32 free3 = 1, free7 = 1, i;
    u8 **text;
    s16 sound, event;
    if (player->choices[pickup->index].kind == -1 ||
        (player->config->mode && D_801468F4 && player->id != D_800CE474[0] && player->id != D_800CE474[1])) {
        for (i = 0; i < 22; i++) {
            if (player->choices[i].kind == 3) free3 = 0;
            else if (player->choices[i].kind == 7) free7 = 0;
        }
        player->choices[pickup->index].enabled = 1;
        if (!free3 && !free7) return 0;
        if (!player->config->mode || !D_801468F4) {
            player->selection = free3 ? 3 : 7;
            if (free3) player->choices[pickup->index].kind = 3;
            else player->choices[pickup->index].kind = 7;
        }
        text = pickup->text;
        sound = pickup->sound;
        event = pickup->event;
        if (player->ui) {
            func_802391AC_de(player->ui, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (text) func_80237E80_de(&D_80145088, player->ui, *text);
        }
        if (sound) func_8025DE54_de(sound, player->position, 0, -1);
        if (event) func_8025E11C_de(event);
        func_80222BE8_de(player, pickup->arg1, pickup->arg2);
    } else {
        text = pickup->text;
        sound = pickup->sound;
        event = pickup->event;
        if (player->ui) {
            func_802391AC_de(player->ui, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (text) func_80237E80_de(&D_80145088, player->ui, *text);
        }
        if (sound) func_8025DE54_de(sound, player->position, 0, -1);
        if (event) func_8025E11C_de(event);
    }
    return 1;
}
