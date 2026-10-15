#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"




























/* Runs a player's floating movement state for its body: sets the movement mode at 0x650 to 11 when
   still and 12 when moving (speed at 0x6C8), turns the view through func_802231D4_de with tuning
   D_800CE874, sways the weapon on three sine waves of the state time at 0x658, moves the body through
   func_802238E0_de with tuning D_800CE850, and once the state time passes 2 without the body's flag
   0x1000 it ends the state: clears the strokes at 0x938 and the body's 0x20, plays sound 0x2DE, clears
   0x840 and hands the player to func_802227F4_de (mode 2 when body flags 3 are set, else 10); it then
   picks the animation at 0x86C from the vertical speed at 0x6C0 (kept while idle animation 0x1144
   plays) and, while moving faster than 5.12, plays the tuning's stroke sound and sound 0x2E0 whenever
   the sound timer at 0x11C4 passes 45, restarting it at a random value below 15. */








extern Tuning D_800CE850;
extern char D_800CE874;
extern f32 D_800D2988;
extern void func_802231D4_de(SharedPlayer_func_80224F5C_de *, Body_func_80224F5C_de *, char *);

extern void func_802238E0_de(SharedPlayer_func_80224F5C_de *, Body_func_80224F5C_de *, Tuning *);
extern void func_80218464_de(char *);
extern s32 func_8025DE54_de(s16, s32, s32, s32, s32, s32);
extern void func_802227F4_de(SharedPlayer_func_80224F5C_de *, Body_func_80224F5C_de *, s32);


void func_80224F5C_de(SharedPlayer_func_80224F5C_de *player, Body_func_80224F5C_de *body) {
    s32 idle;

    if (player->views5E8.view6C8_57.speed == 0.0f) {
        player->views5E8.view650_18.mode = 0xB;
    } else {
        player->views5E8.view650_18.mode = 0xC;
    }
    func_802231D4_de(player, body, &D_800CE874);
    player->views5E8.view730_79.sway[0] = 2.0f * func_802B7130_de(player->views5E8.view658_24.swimTime * 0.06981318f) * 0.017453294f;
    player->views5E8.view730_79.sway[1] = 2.0f * func_802B7130_de(player->views5E8.view658_24.swimTime * 0.08726647496f) * 0.017453294f;
    player->views5E8.view730_79.sway[2] = 2.0f * func_802B7130_de(player->views5E8.view658_24.swimTime * 0.10471976548f) * 0.017453294f;
    func_802238E0_de(player, body, &D_800CE850);
    if (!(body->flags & 0x1000) && 2.0f < player->views5E8.view658_24.swimTime) {
        func_80218464_de(player->views5E8.view938_129.strokes);
        body->stroke = 0;
        func_8025DE54_de(0x2DE, body->x, body->y, body->z, 0, -1);
        player->views5E8.view840_118.surfaced = 0;
        if (body->flags & 3) {
            func_802227F4_de(player, body, 2);
        } else {
            func_802227F4_de(player, body, 0xA);
        }
    }
    idle = 0;
    if (player->views5E8.view86C_127.animation == 0x1144) {
        idle = player->views1C.view10E_13.idle == 0;
    }
    if (player->views1C.viewE4_7.kind == D_800CE47C) {
        player->views5E8.view86C_127.animation = 0x8A2;
    } else if (!idle) {
        if (1.024f <= player->views5E8.view6C0_52.climb) {
            player->views5E8.view86C_127.animation = 0x8A2;
        } else if (player->views5E8.view6C0_52.climb <= -1.024f) {
            player->views5E8.view86C_127.animation = 0x8A7;
        } else {
            player->views5E8.view86C_127.animation = 0x14;
        }
    }
    player->views5E8.view11C4_144.soundTime += D_800D2988;
    if (5.12f < player->views5E8.view6C8_57.speed && 45.0f < player->views5E8.view11C4_144.soundTime) {
        player->views5E8.view11C4_144.soundTime = func_80274564_de(15.0f);
        func_8025DE54_de(D_800CE850.strokeSound, body->x, body->y, body->z, 0, -1);
        func_8025DE54_de(0x2E0, body->x, body->y, body->z, 0, -1);
    }
}
