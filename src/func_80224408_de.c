#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8021CD70.h"
#include "types.h"




























/* Runs a player's standing and walking state for its body: settles the weapon sway through
   func_80223E34_de, turns the view through func_802231D4_de with the crouching tuning D_800CE7FC while the
   crouch at 0x718 is past 5.12 or the standing tuning D_800CE7E4 otherwise, and unless a jump releases
   the player into mode 5 it hands strafing at 0x6A4 or lifting at 0x6A8 (outside zoom mode 2) to mode
   3; then, unless an unfinished pickup, reload or wave animation is playing, it picks the animation at
   0x86C: for the idle character D_800CE47C the fidget animations 1 and 2 alternate after 12 and 21 time
   units at 0x104, and otherwise the turning animations follow the heading change this frame (0xA28
   while the body is falling, with a separate set for the character D_800CED30). */










extern char D_800CE7E4;
extern char D_800CE7FC;
extern char D_800CED30;
extern void func_80223E34_de(SharedPlayer_func_80224408_de *, Body_func_80224408_de *);
extern void func_802231D4_de(SharedPlayer_func_80224408_de *, Body_func_80224408_de *, char *);
extern void func_802227F4_de(SharedPlayer_func_80224408_de *, Body_func_80224408_de *, s32);

static inline s32 try_jump(SharedPlayer_func_80224408_de *player, Body_func_80224408_de *body) {
    if (player->views5E8.view7E8_106.zoomed == 0 && !(11.25f < player->views5E8.view6E4_62.depth) && !(body->flags & 0xC0000)
        && (body->surface->unk14 & 2) && (player->views5E8.view6B0_47.input & 0x10) && player->views5E8.view11D8_149.stun <= 0.0f) {
        func_802227F4_de(player, body, 5);
        return 1;
    }
    return 0;
}

void func_80224408_de(SharedPlayer_func_80224408_de *player, Body_func_80224408_de *body) {
    f32 heading;
    s32 crouching;
    s32 animate;

    func_80223E34_de(player, body);
    heading = body->heading;
    crouching = 5.12f < player->views5E8.view718_70.crouch;
    if (crouching) {
        func_802231D4_de(player, body, &D_800CE7FC);
    } else {
        func_802231D4_de(player, body, &D_800CE7E4);
    }
    heading = body->heading - heading;
    if (try_jump(player, body)) {
        return;
    }
    if (player->views5E8.view6A4_42.strafe != 0.0f || (player->views5E8.view7E8_106.zoomed != 2 && player->views5E8.view6A8_44.lift != 0.0f)) {
        func_802227F4_de(player, body, 3);
    }
    animate = 1;
    if ((player->views5E8.view86C_127.animation == 0x1130 || player->views5E8.view86C_127.animation == 0x1135) && player->views1C.view10E_13.idle == 0) {
        animate = 0;
    }
    if ((player->views5E8.view86C_127.animation == 0x5E56 || player->views5E8.view86C_127.animation == 0x5E5E) && player->views1C.view10E_13.idle == 0) {
        animate = 0;
    }
    if ((player->views5E8.view86C_127.animation == 0xFA0 || player->views5E8.view86C_127.animation == 0x1004) && player->views1C.view10E_13.idle == 0) {
        animate = 0;
    }
    if (animate) {
        if (player->views1C.viewE4_7.kind == D_800CE47C) {
            if (player->views5E8.view86C_127.animation == 1 && 12.0f <= player->views1C.view104_11.idleTime) {
                player->views5E8.view86C_127.animation = 2;
            } else if (player->views5E8.view86C_127.animation == 2 && 21.0f <= player->views1C.view104_11.idleTime) {
                player->views5E8.view86C_127.animation = 1;
            } else if ((u32) (player->views5E8.view86C_127.animation - 1) >= 2) {
                player->views5E8.view86C_127.animation = 1;
            }
        } else if (player->views13B4.view13B4_3.character == &D_800CED30) {
            if (body->flags & 0xC0000) {
                player->views5E8.view86C_127.animation = 0xA28;
            } else if (0.017453294f < heading) {
                player->views5E8.view86C_127.animation = 0x5E26;
            } else if (heading < -0.017453294f) {
                player->views5E8.view86C_127.animation = 0x5E25;
            } else {
                player->views5E8.view86C_127.animation = 0x5E24;
            }
        } else {
            if (body->flags & 0xC0000) {
                player->views5E8.view86C_127.animation = 0xA28;
            } else if (0.017453294f < heading) {
                player->views5E8.view86C_127.animation = 0xB5E;
            } else if (heading < -0.017453294f) {
                player->views5E8.view86C_127.animation = 0xB54;
            } else {
                player->views5E8.view86C_127.animation = 1;
            }
        }
    }
}
