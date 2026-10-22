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
/* Bootstraps a local multiplayer session: shuffles a 40-word stack array,
 * clears player status flags, configures joining and spectator players,
 * and sets global mode state. */
void func_8042E5EC_de(void) {
    s32 stack[40];
    s32 i, idx1, idx2, temp;
    s32 numJoining, numSpectators, variant;
    Shared_PlayerSettingsRecord *player;
    Shared_Game *settings;

    for (i = 0; i < 40; i++) {
        stack[i] = i;
    }
    for (i = 0; i < 100; i++) {
        idx1 = func_802744D4_de();
        if (idx1 < 0) idx1 += 3;
        idx1 %= 4;
        idx2 = func_802744D4_de();
        if (idx2 < 0) idx2 += 3;
        idx2 %= 4;
        temp = stack[16 + idx1];
        stack[16 + idx1] = stack[16 + idx2];
        stack[16 + idx2] = temp;
    }
    numJoining = func_802744D4_de() % 5 + 2;
    if (numJoining == 3) {
        numJoining = 2;
    }
    settings = &D_801462C8;
    for (i = 0; i < 8; i++) {
        player = &settings->playerSettings[i];
        player->enabled = 0;
        player->active = 0;
        player->locked = 0;
        player->character = 0;
    }
    if (numJoining > 0) {
        for (i = 0; i < numJoining; i++) {
            player = &settings->playerSettings[i];
            player->active = 1;
            player->locked = 0;
            player->slot = 2;
            player->character = stack[16 + (i - numJoining) % 4];
            variant = func_802744D4_de() % 3;
            player->variant = (u8)variant;
            func_802A025C_de(player->name,
                (u8 *)D_800DF7D0[((s8)variant * 0x11) + func_8041F140_de(player->character)].names);
        }
    }
    numSpectators = numJoining - 2;
    if (numSpectators > 0) {
        for (i = 0; i < numSpectators; i++) {
            player = &settings->playerSettings[i + 4];
            player->enabled = 1;
            player->locked = 1;
            player->active = 2;
            player->character = stack[16 + (i + numJoining) % 4];
            variant = func_802744D4_de() % 3;
            player->variant = (u8)variant;
            func_802A025C_de(player->name,
                (u8 *)D_800DF7D0[((s8)variant * 0x11) + func_8041F140_de(player->character)].names);
        }
    }
    D_8014288C = 1;
    settings->local = 1;
    settings->mode1E = 8;
    settings->controllerMode = 0;
    settings->reserved20[4] = 0;
    settings->reserved20[5] = 0;
    i = func_802744D4_de();
    *(volatile s32 *)0x8014DD98 = i;
    if (i < 0) i += 3;
    *(volatile s32 *)(0x8014DD98 + 4) = stack[4 + (i % 4)];
}
#else
INCLUDE_ASM("ovl_80400000", func_8042E5EC_de);
#endif
