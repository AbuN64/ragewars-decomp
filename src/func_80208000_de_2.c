#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80208000.h"
#include "types.h"






























/* Updates a computer player's brain for the frame: fixes its route start, runs its planner through func_802095F8_de and its state callback, counts down its cooldown at 0x324, and for a displayed player sets the health meter from its health over the character's maximum (400 for kinds 11 and 12, 300 for 13 and 14, otherwise func_8022AC00_de), as a percentage, rescaled for kind 14 by the difficulty D_8014693C; in the tutorial (D_801468A0) kind 11 also shows the timer and refills its ammunition, then the meter is drawn through func_802AA794_de or func_802AA79C_de; finally it restarts a stalled player (state 0x12) through func_80209CD8_de. */









extern Tutorial D_801468A0;
extern char D_801376F8[];


extern void func_802095F8_de(Brain *);
extern s32 func_8022AC00_de(SharedPlayer_func_80208158_de *);
extern void func_802AA794_de(char *, s32);
extern void func_802AA79C_de(char *, s32);
extern void func_802636B0_de(char *);
extern void func_802227F4_de(SharedPlayer_func_80208158_de *, SharedPlayer_func_80208158_de *, s32);
extern void func_80209CD8_de(Brain *, SharedPlayer_func_80208158_de *);

void func_80208158_de(Brain *brain) {
    s32 health;
    s32 maximum;
    f32 meter;
    s32 kind;
    Tutorial *tutorial;
    SharedPlayer_func_80208158_de *player;

    if (brain->player->views1450.view1450_1.computer == 0) {
        return;
    }
    if (brain->route == -1) {
        brain->route = brain->start;
    }
    func_802095F8_de(brain);
    if (brain->behaviour->update != 0) {
        brain->behaviour->update(brain->player, 0);
    }
    if (brain->cooldown > 0) {
        brain->cooldown--;
    }
    if (brain->player->views5D8.view5D8_1.record->display != 0) {
        health = brain->player->views5E4.view5E4_2.health >> 8;
        kind = brain->player->views5D8.view5D8_1.record->kind;
        if (kind == 11) {
            maximum = 400;
        } else if (kind == 12) {
            maximum = 400;
        } else if (kind == 14) {
            maximum = 300;
        } else if (kind == 13) {
            maximum = 300;
        } else {
            maximum = func_8022AC00_de(brain->player) >> 8;
        }
        meter = (f32)health / (f32)maximum * 100.0f;
        if (brain->player->views5D8.view5D8_1.record->kind == 14) {
            if (meter == 0.0f) {
                meter = (3 - D_8014693C) * 33;
            } else {
                meter *= 0.33333334f;
                meter += (2 - D_8014693C) * 33;
            }
            if (meter < 0.0f) {
                meter = 0.0f;
            }
        }
        tutorial = &D_801468A0;
        if (tutorial->active != 0) {
            if (brain->player->views5D8.view5D8_1.record->kind == 11) {
                func_802AA794_de(D_801376F8, (f32)tutorial->timer);
                if (tutorial->refills > 0) {
                    tutorial->refills--;
                    func_802636B0_de((char *)brain->player + 0x688);
                    brain->w23C = 0;
                    brain->w240 = 0;
                }
                if (tutorial->refills == 0 && brain->player->views5E4.view5E4_2.health > 0) {
                    tutorial->timer = 100;
                    tutorial->refills = -1;
                    func_802227F4_de(brain->player, brain->player, 2);
                }
            }
            if (brain->player->views5D8.view5D8_1.record->display == 1) {
                func_802AA794_de(D_801376F8, meter);
            } else {
                func_802AA79C_de(D_801376F8, meter);
            }
        }
    }
    player = brain->player;
    if (player->views5E8.view650_16.state == 0x12) {
        player->views1340.view1340_1.stalls++;
        func_80209CD8_de(brain, player);
    }
}
