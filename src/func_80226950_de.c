#include "common/unused.h"
#include "span_1000/code_80225D10.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80243A80.h"
#include "span_16E000/code_80435CE4.h"
#include "types.h"

/** Allocate and clear the player array and its per-player state blocks, linking each player to its block. */
extern char D_800C2B68_de[];
extern void **func_8025343C_de(int, int, int, char *);
extern void func_802A001C_de(void *, int, int);

void func_80226950_de(PlayerList *list, int count) {
    int playerSize = count * sizeof(Player_func_80226950_de);
    int stateSize = count * 0x330;
    char *states;
    void **handle;
    int i;

    handle = func_8025343C_de(0, playerSize + stateSize, 0x23, D_800C2B68_de);
    list->handle = handle;
    list->count = count;
    list->players = *handle;
    states = (char *)list->players + playerSize;
    func_802A001C_de(list->players, 0, playerSize);
    func_802A001C_de(states, 0, stateSize);
    for (i = 0; i < count; i++) {
        list->players[i].state = states + i * 0x330;
    }
}

/* Updates every player in a world for one frame unless the game state D_8014687C is 8 or 11: turns
   the world's spin at 0x40 by 5 degrees, then for each player in the list from 0x20 runs its body
   through func_802631B0_de (restoring the frame time D_800D2988 it may change), its team logic through
   func_8022C490_de when either team rule is set, its controls through func_80220ED4_de unless input is
   frozen by D_80146894, and its camera through func_80220A80_de; a second pass opens the pause menu
   through func_8024570C_de for a paused player or one whose controller at 0x698 asks while a menu is
   possible, or otherwise starts the in-game menu for a live player with a view not already showing
   one (unless the match forbids it), before the match end check func_802283B8_de and the world updates
   func_80227038_de and func_80227E8C_de run and the frame time is restored. */
















extern f32 D_800D2988;
extern Menu_func_80226A34_de D_8014561C;
extern Game D_8014687C;
extern s32 D_80146894;
extern void func_802631B0_de(char *, SharedPlayer_func_80226A34_de *);
extern void func_8022C490_de(SharedPlayer_func_80226A34_de *);
extern void func_80220ED4_de(SharedPlayer_func_80226A34_de *);
extern void func_80220A80_de(SharedPlayer_func_80226A34_de *, SharedPlayer_func_80226A34_de *);
extern s32 func_80245784_de(void);

extern s32 func_8026435C_de(void *);

extern s32 func_802A23B4_de(void);
extern s32 func_80442A28_de(Menu_func_80226A34_de *);
extern void func_8025E360_de(void);
extern void func_8025E3A8_de(void);
extern void func_80218464_de(char *);

extern void func_802283B8_de(World_func_80226A34_de *);
extern void func_80227038_de(World_func_80226A34_de *);
extern void func_80227E8C_de(World_func_80226A34_de *);

void func_80226A34_de(World_func_80226A34_de *world) {
    f32 frameTime;
    SharedPlayer_func_80226A34_de *player;
    Rules *rules;

    if (D_8014687C.state != 0xB && D_8014687C.state != 8) {
        frameTime = D_800D2988;
        world->spin += 5;
        if (world->spin >= 360) {
            world->spin = 0;
        }
        rules = &D_8014687C.rules;
        for (player = world->players; player != 0; player = player->views16E0.view16E0_2.next) {
            func_802631B0_de(player->views5E8.view688_33.body, player);
            D_800D2988 = frameTime;
            if (rules->teams != 0 || rules->teamRule != 0) {
                func_8022C490_de(player);
            }
            if (D_80146894 == 0) {
                func_80220ED4_de(player);
            }
            func_80220A80_de(player, player);
        }
        for (player = world->players; player != 0; player = player->views16E0.view16E0_2.next) {
            if (func_80245784_de() != 0 && (player->views5E8.view6B0_48.state & 0x8000)) {
                func_8024570C_de();
            } else if (func_8026435C_de(player->views5E8.view698_36.controller) != 0) {
                if (func_80245784_de() != 0 || func_8024576C_de() != 0) {
                    func_8024570C_de();
                } else if (func_802A23B4_de() == 0 && func_80442A28_de(&D_8014561C) == 0 && player->views5E4.view5E4_3.alive != 0
                           && player->views5DC.view5DC_2.view != 0 && player->views5DC.view5DC_2.view->unk564 == 0
                           && ((&D_8014561C.rules)->locked == 0 || D_8014561C.allowed == 0)) {
                    D_8014561C.open = 1;
                    func_8025E360_de();
                    func_8025E3A8_de();
                    func_80218464_de(player->views5E8.view938_130.strokes);
                    player->views5E8.viewF54_132.selection = -1;
                    player->views5E8.viewF90_134.choice = -1;
                    func_80435B10_de();
                }
            }
        }
        func_802283B8_de(world);
        func_80227038_de(world);
        func_80227E8C_de(world);
        D_800D2988 = frameTime;
    }
}
