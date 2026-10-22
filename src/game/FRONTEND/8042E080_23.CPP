#include "include_asm.h"
#include "FRONTEND/JOIN_PLAYER_NAMES.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/SELF.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/ACTIVE.H"
#include "COMMON/RECTANGLE_DRAW.H"
#include "COMMON/CONTROL.H"
#include "COMMON/UNUSED.H"
#include "FRONTEND/8042E080_23.H"
#include "FRONTEND/8042E080_25.H"

extern u8 *func_802A025C_de(u8 *dst, u8 *name);

/* Seats a joining player (request: kind+1, team, rank) in the highest free player slot, filling its index, kind (random for 20), team (random for 3, at most 2), rank and name (per language on the European cartridges); returns the slot or -1 when all are taken. */
s32 func_8042E460_de(u8 *request) {
    s32 i;
    s32 kind;
    s32 team;
    u8 *name;
    s32 result;
    Shared_PlayerSettingsRecord *player;
    Shared_Game *settings;

    for (i = 7; i > 0; i--) {
        settings = &D_801462C8;
        if (settings->playerSettings[i].enabled != 1) {
            break;
        }
    }
    result = -1;
    if (i >= 0) {
        player = &D_801462C8.playerSettings[i];
        player->locked = 1;
        player->enabled = 1;
        player->slot = i;
        kind = request[0] - 1;
        if (kind == 19) {
            player->character = func_8042EE94_de();
        } else {
            player->character = kind;
        }
        team = request[1];
        if (team == 3) {
            player->pad92[1] = func_802744D4_de() % 3;
        } else {
            player->pad92[1] = team;
        }
        if ((u8)player->pad92[1] >= 3) {
            player->pad92[1] = 2;
        }
        player->variant = (u8)player->pad92[1];
        player->pad92[0] = request[2];
        switch (player->character) {
        case 15:
            name = joinName15();
            break;
        case 16:
            name = joinName16();
            break;
        default:
            name = joinTeamName((u8)player->pad92[1] * 17 + func_8041F140_de(player->character));
            break;
        }
        func_802A025C_de(player->name, name);
        result = i;
    }
    return result;
}

#ifdef NON_MATCHING
/* Sets up the attract-mode demo match: shuffles the character/level tables, seats 2-4 random players (the first group of
 * 1-2 as unlocked, the rest locked) with random costumes and names, and picks the level goal in D_8014DD98. */
void func_8042E5EC_de(void) {
    s32 table[8] = { 0, 3, 8, 5, 0, 3, 0x1B, 1 };
    s32 i, a, b, tmp;
    s32 total, first, costume;
    Shared_PlayerSettingsRecord *player;

    for (i = 0; i < 100; i++) {
        a = func_802744D4_de() % 4;
        b = func_802744D4_de() % 4;
        tmp = table[a];
        table[a] = table[b];
        table[b] = tmp;
    }
    total = func_802744D4_de() % 3 + 2;
    first = func_802744D4_de() % total + 1;
    if (first == 3) {
        first = 2;
    }
    for (i = 0; i < 8; i++) {
        player = &D_801462C8.playerSettings[i];
        player->active = 0;
        player->pad92[2] = 0;
        player->enabled = 0;
        player->locked = 0;
    }
    for (i = 0; i < first; i++) {
        player = &D_801462C8.playerSettings[4 + i];
        player->enabled = 1;
        player->character = table[i];
        player->locked = 0;
        player->pad92[1] = 2;
        costume = func_802744D4_de() % 3;
        player->variant = costume;
        func_802A025C_de(player->name, joinTeamName((s8)player->variant * 17 + func_8041F140_de(player->character)));
    }
    for (i = 0; i < total - first; i++) {
        player = &D_801462C8.playerSettings[4 + first + i];
        player->enabled = 1;
        player->character = table[first + i];
        player->locked = 1;
        player->pad92[1] = 2;
        costume = func_802744D4_de() % 3;
        player->variant = costume;
        func_802A025C_de(player->name, joinTeamName((s8)player->variant * 17 + func_8041F140_de(player->character)));
    }
    D_8014288C = 1;
    D_801462C8.local = 1;
    D_801462C8.mode1E = 8;
    D_801462C8.controllerMode = 0;
    D_801462C8.laps = 0;
    D_801462C8.players = 0;
    D_8014DD98 = 2;
    (&D_8014DD98)[1] = table[4 + func_802744D4_de() % 4];
}
#else
INCLUDE_ASM("ovl_80400000", func_8042E5EC_de);
#endif
