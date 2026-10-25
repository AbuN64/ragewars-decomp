#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/VECTOR4F.H"
#include "TYPES.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "RENDER_2/802192C0_3.H"

/* Starts a player's run: in a multiplayer session (D_801462E5) picks the lap count from the chosen track through func_8022F454_de in mode 1 or from the loaded course in mode 4 for a human player, sets the run type at 0x5EA (1, or 3 in single player), clears 0x13C8 and 0x85C around func_8044952C_de, then starts its vehicle through Render_PlacePlayerAtSpawnPoint with model 0xC1D for a computer player in state 12 during stage 9 and its own model otherwise, doubled when D_80145048 is two or more. */






extern char D_80102B00[];
extern Course *D_800E4680;
extern s32 D_801371D4;

extern s32 func_8022F454_de(char *, s32);
extern void func_8044952C_de(SharedPlayer *);

extern u8 D_801462D5; /* MIXED func_8044972C_de */
extern u8 D_801462E5; /* MIXED func_8044972C_de */
void func_8044972C_de(SharedPlayer *player) {
    s32 scale;

    scale = (D_80145048 >= 2) * 2;
    if (D_801462E5 != 0) {
        if (D_801462D5 == 1 && player->views1450.view1450_1.computer == 0) {
            player->views133C.view133C_1.laps = ((u8)func_8022F454_de(D_80102B00 + player->views1C.view5D4_46.slot * 0x190, player->views5D8.view5D8_1.record->unk80) >> 1) + 1;
        }
        if (D_801462D5 == 4 && player->views1450.view1450_1.computer == 0 && D_800E4680 != 0) {
            player->views133C.view133C_1.laps = D_800E4680->laps;
        }
        player->views5E8.view5EA_4.runType = 1;
    } else {
        player->views5E8.view5EA_4.runType = 3;
    }
    player->views13C8.view13C8_1.w13C8 = 0;
    func_8044952C_de(player);
    player->views5E8.view85C_120.w85C = 0;
    if (player->views5DC.view5E0_9.state == 12 && player->views1450.view1450_1.computer != 0 && D_801371D4 == 9) {
        Render_PlacePlayerAtSpawnPoint(player, 0xC1D, scale, 1);
    } else {
        Render_PlacePlayerAtSpawnPoint(player, player->views5E8.view5EC_6.model, scale, 1);
    }
}

/* Ends a human player's run: counts down the result timer (0x133C) and, when it runs out, clears humanWon and
 * calls func_8022A748_de; then either respawns the player with the chosen model or settles the run (func_802227F4_de).
 * NON_MATCHING: 80/80 words, only the order of the a1 load and the a2 move before Render_PlacePlayerAtSpawnPoint differs. */
#ifdef NON_MATCHING
#include "COMMON/SHARED_GAMESLOT.H"
#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "MENU/PAK_LOAD.H"
/* View of the player fields the end-of-run check reads. */
typedef struct {
    u8 pad0[0x10E]; s8 mode; u8 pad10F[0x4C9]; struct AiProfile *profile;
    u8 pad5DC[0x10]; s32 model; u8 pad5F0[0xD4C];
    s32 timer; s32 state; u8 pad1344[0x10C]; s32 computer;
} RunEndView;
#define RUN_END(p) ((RunEndView *)(p))
extern void func_8022A748_de(void *);
void Ovlgame_UpdateRunEndPlayer(SharedPlayer *player)
{
    s32 modelScale = ((D_80145048 < 2) ^ 1) << 1;
    if (!(D_80145040.game.flags & 2) || D_80145040.game.local) {
        if ((D_80145040.game.controllerMode == 1 || D_80145040.game.controllerMode == 4) && RUN_END(player)->computer == 0) {
            if (RUN_END(player)->timer > 0) RUN_END(player)->timer--;
            if (RUN_END(player)->timer == 0) {
                D_80145040.game.humanWon = 0;
                func_8022A748_de(&D_80145040);
            }
        }
    }
    {
        Shared_Game *settings = &D_80145040.game;
        if ((settings->controllerMode == 1 || settings->controllerMode == 4) && RUN_END(player)->computer == 0) {
            if (RUN_END(player)->timer <= 0) {
                if (settings->local && RUN_END(player)->mode == 0 && RUN_END(player)->profile->bonus == 0) return;
                func_802227F4_de(player, player, 0x12);
                RUN_END(player)->state = 0;
            } else {
                Render_PlacePlayerAtSpawnPoint(player, RUN_END(player)->model, modelScale, 1);
                func_8044952C_de(player);
                RUN_END(player)->state = 0;
            }
        } else {
            func_802227F4_de(player, player, 0x12);
            RUN_END(player)->state = 0;
        }
    }
}
#else
INCLUDE_ASM("ovl_80400000", Ovlgame_UpdateRunEndPlayer);
#endif
