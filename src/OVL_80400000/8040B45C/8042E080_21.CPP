#include "shared/join_player_names.h"
#include "TYPES.H"




#include "shared/func_80425674_de_layout.h"
#include "span_1000/code_802106E0.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8042E080.h"

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
        player->pad81[0] = (u8)player->pad92[1];
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
        func_802A025C_de((u8 *)&player->pad81[3], name);
        result = i;
    }
    return result;
}

