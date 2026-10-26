#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
#include "COMMON/ACTIVE.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "FRONTEND/8042E080_22.H"
#include "SYSTEM_2/8025E280.H"
#include "ACHIEVE/80424E30_3.H"

/* Prepares a match: stops the current screen, starts screen 2, resets the eight player status
   records (clearing bytes 0x94 and 0x95 and, for human slots, the team byte 0x92) while counting
   active humans, clears the match counters, and outside mode 0 looks up the stage default for the
   first active player through Achieve_CopyPreset and resets the round state. It then runs the setup of
   the current rule set D_8014DD98, copies each active human's name and the five profile bytes at 0x189
   of their player record into status bytes 0x7B, 0x7D, 0x79, 0x7A and 0x82, sets the game mode (team mode 2 falls back to 1 with fewer than two
   humans) and, when func_8025E2C4_de allows, picks a random arena 0x38 to 0x3B. */







extern struct RecordRecAt189 D_80102B00[];
/* The stage entry of the current match: seven opponent records from +5. */
struct Stage {
    char pad0[5];
    u8 opponents[7][4];
};
extern struct Stage *D_800E4680;
extern s32 D_8015402C;

extern void MarkMenuEventHandled(void);
extern void SmXlate_SwitchScreen(s32);
extern void Tsmos_RequestFrontendShutdown(void);





extern void XPlus_CopyString(char *, char *);
extern void Frontend_RequestScreenMode(s32);
extern s32 GraphU64_NextRandom(void);


void Frontend_StartConfiguredMatch(void) {
    u8 *settings;
    u8 *config;
    struct StatusRecAt95 *status;
    s32 humans;
    s32 i;
    s32 first;
    CGameStatus *match;

    MarkMenuEventHandled();
    SmXlate_SwitchScreen(2);
    Tsmos_RequestFrontendShutdown();
    humans = 0;
    settings = (u8 *)&D_801462C8;
    for (i = 0; i < 8; i++) {
        status = (struct StatusRecAt95 *)(settings + 0xD0 + i * 0x96);
        status->lives = 0;
        status->score = 0;
        if (status->computer == 0) {
            status->team = 0xFF;
        }
        if (status->computer == 0 && status->joined == 1) {
            humans++;
        }
    }
    match = &D_801462C8.counters;
    match->enabled = 0;
    match->m_bPhoenixRoomActive = 0;
    D_800E4680 = 0;
    if (settings[0xD] != 0) {
        first = 0;
        while (((struct StatusRecAt95 *)(settings + 0xD0 + first * 0x96))->joined == 0) {
            first++;
        }
        status = (struct StatusRecAt95 *)(settings + 0xD0 + first * 0x96);
        switch (settings[0xD]) {
        case 1:
            D_800E4680 = Achieve_CopyPreset(D_8015402C, 0, status->kind);
            break;
        case 2:
            D_800E4680 = Achieve_CopyPreset(D_8015402C, 1, 0);
            break;
        case 3:
            D_800E4680 = Achieve_CopyPreset(D_8015402C, 3, 0);
            break;
        case 4:
            D_800E4680 = Achieve_CopyPreset(D_8015402C, 2, 0);
            break;
        }
        D_801462C8.counters.humanWon = 0;
        Frontend_PlaceStageOpponents();
    }
    switch (D_8014DD98.kind) {
    case 0:
        Frontend_StartCaptureTheFlagMatch();
        break;
    case 1:
        Frontend_StartFragTagMatch();
        break;
    case 2:
        Frontend_StartIndividualMatch();
        break;
    case 3:
        Frontend_StartTeamMatch();
        break;
    }
    for (i = 0; i < 4; i++) {
        status = (struct StatusRecAt95 *)(settings + 0xD0 + i * 0x96);
        if (status->joined == 1 && status->computer == 0) {
            XPlus_CopyString(status->name, D_80102B00[i].name);
            if (settings[0xD] != 0) {
                status->team = 0;
            } else {
                status->team = 0xFF;
            }
            status->unk7B = D_80102B00[i].profile[0];
            status->unk7D = D_80102B00[i].profile[1];
            status->unk79 = D_80102B00[i].profile[2];
            status->unk7A = D_80102B00[i].profile[3];
            status->unk82 = D_80102B00[i].profile[4];
        }
    }
    config = (u8 *)&D_801462C8;
    if (config[0x580] == 2 && humans >= 2) {
        Frontend_RequestScreenMode(1);
    } else {
        Frontend_RequestScreenMode(config[0x580]);
    }
    if (func_8025E2C4_de() != 0) {
        func_8025E2D4_de(GraphU64_NextRandom() % 4 + 0x38);
    }
}

/* Places the computer opponents of the stage entry D_800E4680: first frees the player settings
   records still marked joined and locked, then for each of the entry's seven opponent records with a
   nonzero kind places it through Frontend_AddStageOpponent and, by kind, sets the returned slot's controlMode
   and the match counters: kind 12 sets 2 with enabled, timer 100 and cooldown -1; 13 sets 1 with
   enabled; 16 sets 2; 14 sets 1 with enabled for the first such opponent and 0 afterwards; 15 sets 1
   with enabled and clears unk9C; any other kind sets 0 and, once a kind 15 opponent was placed,
   marks the slot active. */
extern s32 Frontend_AddStageOpponent(u8 *);
void Frontend_PlaceStageOpponents(void) {
    CGameStatus *match;
    Shared_PlayerSettingsRecord *player;
    s32 boss;
    s32 escorted;
    s32 i;
    s32 slot;
    s32 on;
    Shared_Game *game;

    boss = 0;
    escorted = 0;
    match = &D_801462C8.counters;
    for (i = 0; i < 8; i++) {
        player = &D_801462C8.playerSettings[i];
        if (player->enabled == 1 && player->locked == player->enabled) {
            player->enabled = 0;
            player->locked = 0;
        }
    }
    for (i = 0; i < 7; i++) {
        on = 1;
        game = &D_801462C8;
        if (D_800E4680->opponents[i][0] == 0) {
            continue;
        }
        switch (D_800E4680->opponents[i][0]) {
        case 12:
            match->enabled = on;
            slot = Frontend_AddStageOpponent(D_800E4680->opponents[i]);
            (game->playerSettings + slot)->controlMode = 2;
            match->m_nBastilleShield = 100;
            match->m_nBastilleTimer = -1;
            break;
        case 13:
            match->enabled = on;
            slot = Frontend_AddStageOpponent(D_800E4680->opponents[i]);
            (game->playerSettings + slot)->controlMode = on;
            break;
        case 16:
            slot = Frontend_AddStageOpponent(D_800E4680->opponents[i]);
            (game->playerSettings + slot)->controlMode = 2;
            break;
        case 14:
            slot = Frontend_AddStageOpponent(D_800E4680->opponents[i]);
            if (boss == 0) {
                boss = 1;
                match->enabled = on;
                (game->playerSettings + slot)->controlMode = on;
            } else {
                (game->playerSettings + slot)->controlMode = 0;
            }
            break;
        case 15:
            escorted = 1;
            match->enabled = on;
            match->m_nTalsetLives = 0;
            slot = Frontend_AddStageOpponent(D_800E4680->opponents[i]);
            (game->playerSettings + slot)->controlMode = on;
            break;
        default:
            slot = Frontend_AddStageOpponent(D_800E4680->opponents[i]);
            game->playerSettings[slot].controlMode = 0;
            if (escorted) {
                game->playerSettings[slot].active = on;
            }
            break;
        }
    }
}
