#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"




























/* Runs a player's wading state for its body: sets the movement mode at 0x650 to 9 when still and 10
   when moving, settles the roll kick at 0x72C, turns the view and moves the body through func_802231D4_de
   and func_802233F0_de with tunings D_800CE7E4 and D_800CE82C, and leaves the state (clearing the strokes
   at 0x938, release mode 3) once the body loses surface flag 0x2000; otherwise looking down past 40
   degrees while lifting at 0x6A8 lowers the eye height at 0x6EC and sets flag 0x100000 of D_80104418
   (cleared otherwise), the weapon sways on three sine waves of the state time at 0x658, a jump input
   0x10 in shallow enough ground that allows it releases the player into mode 5, and otherwise the
   animation at 0x86C follows the vertical speed and a moving player plays the tuning's step sound
   whenever the step timer at 0x11C4 passes 11.25. Adapted from func_80224F5C_de with the jump check as
   an inline function and the D_80104418 flags read as an array. */










extern char D_800CE7E4;
extern Tuning D_800CE82C;
extern s32 D_80104418[];
extern f32 D_800D2988;
extern void func_80274870_de(f32 *, f32, f32);
extern void func_802231D4_de(SharedPlayer_func_80224C4C_de *, Body_func_80224C4C_de *, char *);
extern void func_802233F0_de(SharedPlayer_func_80224C4C_de *, Body_func_80224C4C_de *, Tuning *);

extern void func_80218464_de(char *);
extern s32 func_8025DE54_de(s16, s32, s32, s32, s32, s32);
extern void func_802227F4_de(SharedPlayer_func_80224C4C_de *, Body_func_80224C4C_de *, s32);

static inline s32 try_jump(SharedPlayer_func_80224C4C_de *player, Body_func_80224C4C_de *body) {
    if (player->views5E8.view7E8_106.zoomed == 0 && !(11.25f < player->views5E8.view6E4_62.depth) && !(body->flags & 0xC0000)
        && (body->surface->unk14 & 2) && (player->views5E8.view6B0_47.input & 0x10) && player->views5E8.view11D8_149.stun <= 0.0f) {
        func_802227F4_de(player, body, 5);
        return 1;
    }
    return 0;
}

void func_80224C4C_de(SharedPlayer_func_80224C4C_de *player, Body_func_80224C4C_de *body) {
    s32 idle;

    if (player->views5E8.view6C8_57.speed == 0.0f) {
        player->views5E8.view650_18.mode = 9;
    } else {
        player->views5E8.view650_18.mode = 0xA;
    }
    func_80274870_de(&player->views5E8.view72C_76.kickRoll, 0.0f, 0.25f);
    func_802231D4_de(player, body, &D_800CE7E4);
    func_802233F0_de(player, body, &D_800CE82C);
    if (!(body->flags & 0x2000)) {
        func_80218464_de(player->views5E8.view938_129.strokes);
        func_802227F4_de(player, body, 3);
        return;
    }
    if (player->views5E8.view724_72.pitch * 57.295776f < -40.0f && player->views5E8.view6A8_44.lift > 0.0f) {
        player->views5E8.view6EC_65.height -= 10.24f;
        D_80104418[0] |= 0x100000;
    } else {
        D_80104418[0] &= ~0x100000;
    }
    player->views5E8.view730_79.sway[0] = func_802B7130_de(player->views5E8.view658_24.swimTime * 0.06981318f) * 0.043633237f;
    player->views5E8.view730_79.sway[1] = func_802B7130_de(player->views5E8.view658_24.swimTime * 0.08726647496f) * 0.043633237f;
    player->views5E8.view730_79.sway[2] = func_802B7130_de(player->views5E8.view658_24.swimTime * 0.10471976548f) * 0.043633237f;
    if (!try_jump(player, body)) {
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
        if (5.12f < player->views5E8.view6C8_57.speed && 11.25f < player->views5E8.view11C4_144.soundTime) {
            player->views5E8.view11C4_144.soundTime = 0.0f;
            func_8025DE54_de(D_800CE82C.strokeSound, body->x, body->y, body->z, 0, -1);
        }
    }
}
