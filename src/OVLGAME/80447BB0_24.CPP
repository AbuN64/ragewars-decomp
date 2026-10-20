#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/VECTOR4F.H"
#include "TYPES.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "RENDER_2/802192C0_3.H"

/* Starts a player's run: in a multiplayer session (D_801462E5) picks the lap count from the chosen track through func_8022F454_de in mode 1 or from the loaded course in mode 4 for a human player, sets the run type at 0x5EA (1, or 3 in single player), clears 0x13C8 and 0x85C around func_8044952C_de, then starts its vehicle through func_8021B1E4_de with model 0xC1D for a computer player in state 12 during stage 9 and its own model otherwise, doubled when D_80145048 is two or more. */






extern u8 D_801462E5;
extern char D_80102B00[];
extern Course *D_800E4680;
extern s32 D_801371D4;

extern s32 func_8022F454_de(char *, s32);
extern void func_8044952C_de(SharedPlayer *);

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
        func_8021B1E4_de(player, 0xC1D, scale, 1);
    } else {
        func_8021B1E4_de(player, player->views5E8.view5EC_6.model, scale, 1);
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
typedef struct {
    u8 pad0[0x10E]; s8 mode; u8 pad10F[0x4C9]; struct Record *info;
    u8 pad5DC[0x10]; s32 unk5EC; u8 pad5F0[0xD4C];
    s32 timer; s32 state; u8 pad1344[0x10C]; s32 disabled;
} Actor_u1;
extern Shared_Game D_801462C8;
extern s32 D_80145048;
extern u8 D_80145040[];
extern void func_8022A748_de(void *);
extern void func_8044952C_de(Actor_u1 *);
extern void func_802227F4_de(Actor_u1 *, Actor_u1 *, s32);

void func_80449870_de(Actor_u1 *actor)
{
    s32 option = ((D_80145048 < 2) ^ 1) << 1;
    if (!(D_801462C8.flags & 2) || D_801462C8.local) {
        if ((D_801462C8.controllerMode == 1 || D_801462C8.controllerMode == 4) && actor->disabled == 0) {
            if (actor->timer > 0) actor->timer--;
            if (actor->timer == 0) {
                D_801462C8.humanWon = 0;
                func_8022A748_de(D_80145040);
            }
        }
    }
    if ((D_801462C8.controllerMode == 1 || D_801462C8.controllerMode == 4) && actor->disabled == 0) {
        if (actor->timer > 0) {
            func_8021B1E4_de(actor, actor->unk5EC, option, 1);
            func_8044952C_de(actor);
            actor->state = 0;
            return;
        }
        if (D_801462C8.local && actor->mode == 0 && actor->info->unk8F == 0) return;
    }
    func_802227F4_de(actor, actor, 0x12);
    actor->state = 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80449870_de);
#endif
