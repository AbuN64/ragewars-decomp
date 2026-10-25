#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/VECTOR4F.H"
#include "TYPES.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "RENDER_2/802192C0_3.H"
#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "MENU/PAK_LOAD.H"

/* Starts a player's run: in a multiplayer session (D_801462E5) picks the lap count from the chosen track through func_8022F454_de in mode 1 or from the loaded course in mode 4 for a human player, sets the run type at 0x5EA (1, or 3 in single player), clears 0x13C8 and 0x85C around Ovlgame_ResetRespawnedPlayer, then starts its vehicle through Render_PlacePlayerAtSpawnPoint with model 0xC1D for a computer player in state 12 during stage 9 and its own model otherwise, doubled when D_80145048 is two or more. */






extern char D_80102B00[];
extern Course *D_800E4680;
extern s32 D_801371D4;

extern s32 Weapons_GetLevelProgress(char *, s32);
extern void Ovlgame_ResetRespawnedPlayer(SharedPlayer *);
extern void Weapons_EndRound(void *);

extern u8 D_801462D5; /* MIXED func_8044972C_de */
extern u8 D_801462E5; /* MIXED func_8044972C_de */
void func_8044972C_de(SharedPlayer *player) {
    s32 scale;

    scale = (D_80145048 >= 2) * 2;
    if (D_801462E5 != 0) {
        if (D_801462D5 == 1 && player->views1450.view1450_1.computer == 0) {
            player->views133C.view133C_1.laps = ((u8)Weapons_GetLevelProgress(D_80102B00 + player->views1C.view5D4_46.slot * 0x190, player->views5D8.view5D8_1.record->unk80) >> 1) + 1;
        }
        if (D_801462D5 == 4 && player->views1450.view1450_1.computer == 0 && D_800E4680 != 0) {
            player->views133C.view133C_1.laps = D_800E4680->laps;
        }
        player->views5E8.view5EA_4.runType = 1;
    } else {
        player->views5E8.view5EA_4.runType = 3;
    }
    player->views13C8.view13C8_1.w13C8 = 0;
    Ovlgame_ResetRespawnedPlayer(player);
    player->views5E8.view85C_120.w85C = 0;
    if (player->views5DC.view5E0_9.state == 12 && player->views1450.view1450_1.computer != 0 && D_801371D4 == 9) {
        Render_PlacePlayerAtSpawnPoint(player, 0xC1D, scale, 1);
    } else {
        Render_PlacePlayerAtSpawnPoint(player, player->views5E8.view5EC_6.model, scale, 1);
    }
}

/* Ends a human player's run. Outside a networked session (or as its local host) the countdown at 0x133C ticks
 * down and, on reaching zero, clears humanWon and calls Weapons_EndRound on the menu data. Then a human player with
 * countdown left respawns with the chosen model (scaled when two or more players are in) and resets; otherwise
 * the run is settled through Weapons_SetPlayerState, except for a local idle player whose profile has no bonus. */
void Ovlgame_UpdateRunEndPlayer(struct Player *player)
{
    s32 modelScale = (D_80145048 >= 2) * 2;

    if (!(D_80145040.game.flags & 2) || D_80145040.game.local) {
        if ((D_80145040.game.controllerMode == 1 || D_80145040.game.controllerMode == 4) && player->computer == 0) {
            if (player->countdown > 0) {
                player->countdown--;
            }
            if (player->countdown == 0) {
                D_80145040.game.humanWon = 0;
                Weapons_EndRound(&D_80145040);
            }
        }
    }
    {
        Shared_Game *game = &D_80145040.game;

        if ((game->controllerMode == 1 || game->controllerMode == 4) && player->computer == 0) {
            if (player->countdown <= 0) {
                if (game->local && player->animationDone == 0 && player->profile->bonus == 0) {
                    return;
                }
                Weapons_SetPlayerState(player, player, 0x12);
            } else {
                Render_PlacePlayerAtSpawnPoint(player, player->model, modelScale, 1);
                Ovlgame_ResetRespawnedPlayer(player);
            }
        } else {
            Weapons_SetPlayerState(player, player, 0x12);
        }
        player->resetState = 0;
    }
}
