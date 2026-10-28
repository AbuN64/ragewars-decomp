#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "COMMON/CHANNEL.H"

extern f32 D_800D2988;


extern void Graphu64_EaseValueToward(f32 *value, f32 target, f32 rate);

extern void GraphU64_ScaleVector(CVector3 *, CVector3 *, f32);

extern void GraphU64_AddVec3(CVector3 *, CVector3 *, CVector3 *);

/* Runs a player's standing and walking state for its body: settles the weapon sway through
   func_80223E34_de, turns the view through Player_UpdateViewAngles with the crouching tuning D_800CE7FC while the
   crouch at 0x718 is past 5.12 or the standing tuning D_800CE7E4 otherwise, and unless a jump releases
   the player into mode 5 it hands strafing at 0x6A4 or lifting at 0x6A8 (outside zoom mode 2) to mode
   3; then, unless an unfinished pickup, reload or wave animation is playing, it picks the animation at
   0x86C: for the idle character D_800CE47C the fidget animations 1 and 2 alternate after 12 and 21 time
   units at 0x104, and otherwise the turning animations follow the heading change this frame (0xA28
   while the body is falling, with a separate set for the character D_800CED30). */












extern char D_800CED30;

extern void func_80223E34_de(SharedPlayer *, BodyPlayerUpdateStandingState *);

extern void Player_UpdateViewAngles(SharedPlayer *, BodyPlayerUpdateStandingState *, char *);

static inline s32 try_jump(SharedPlayer *player, BodyPlayerUpdateStandingState *body) {
    if (player->views5E8.view7E8_106.zoomed == 0 && !(11.25f < player->views5E8.view6E4_62.depth) && !(body->flags & 0xC0000)
        && (body->surface->unk14 & 2) && (player->views5E8.view6B0_47.input & 0x10) && player->views5E8.view11D8_149.stun <= 0.0f) {
        Player_SetPlayerState(player, body, 5);
        return 1;
    }
    return 0;
}

void Player_UpdateFlyMode(void *player, void *bodyActor) {
    CVector3 direction;
    f32 held;
    f32 value;
    s32 flags;
    s32 result;
    void *data;

    if (((func_80224078_Arg0 *)player)->unk650 == 0 &&
        !(((func_80224078_Arg0 *)player)->unk6AC & 0xE000)) {
        ((func_80224078_Arg0 *)player)->unk650 = 1;
    }
    ((func_80224078_Arg0 *)player)->unk72C = 0;

    held = (&D_800C2960_de)[1];
    Graphu64_EaseValueToward(&((func_80224078_Arg1 *)(bodyActor))->unk6C,
                  ((func_80224078_Arg1 *)bodyActor)->unk6C +
                      (f32)((ControllerRecAtC7 *)((func_80224078_Arg0 *)player)->unk698)->x * D_800C2960_de,
                  held);
    Graphu64_EaseValueToward(&((func_80224078_Arg0 *)(player))->unk724,
                  ((func_80224078_Arg0 *)player)->unk724 +
                      (f32)-((ControllerRecAtC7 *)((func_80224078_Arg0 *)player)->unk698)->y * D_800C2968_de,
                  held);

    value = ((func_80224078_Arg0 *)player)->unk6A8;
    if (value != 0.0f) {
        f32 step;
        f32 limit;
        step = value * (&D_800C2968_de)[1];
        if (value < 0.0f) {
            limit = -value * D_800C2970_de;
        } else {
            limit = value * D_800C2974_de;
        }
        ((func_80224078_Arg0 *)player)->unk6C0 =
            Graphu64_IntegrateBoundedValue(((func_80224078_Arg0 *)player)->unk6C0, step, limit);
    } else {
        ((func_80224078_Arg0 *)player)->unk6C0 =
            Graphu64_DecayToZero(((func_80224078_Arg0 *)player)->unk6C0, D_800C2978_de);
    }

    value = ((func_80224078_Arg0 *)player)->unk6A4;
    if (value != 0.0f) {
        f32 step;
        f32 limit;
        step = value * D_800C297C_de;
        if (value < 0.0f) {
            limit = -value * D_800C2980_de;
        } else {
            limit = value * D_800C2984_de;
        }
        ((func_80224078_Arg0 *)player)->unk6C4 =
            Graphu64_IntegrateBoundedValue(((func_80224078_Arg0 *)player)->unk6C4, step, limit);
    } else {
        ((func_80224078_Arg0 *)player)->unk6C4 =
            Graphu64_DecayToZero(((func_80224078_Arg0 *)player)->unk6C4, D_800C2988_de);
    }

    flags = ((func_80224078_Arg0 *)player)->unk6AC;
    if (flags & 0x10) {
        ((func_80224078_Arg1 *)bodyActor)->unk20 =
            Graphu64_IntegrateBoundedValue(((func_80224078_Arg1 *)bodyActor)->unk20, D_800C298C_de, 71.68f);
    } else if (flags & 0x2020) {
        ((func_80224078_Arg1 *)bodyActor)->unk20 =
            Graphu64_IntegrateBoundedValue(((func_80224078_Arg1 *)bodyActor)->unk20, D_800C2990_de, 71.68f);
    } else {
        ((func_80224078_Arg1 *)bodyActor)->unk20 =
            Graphu64_DecayToZero(((func_80224078_Arg1 *)bodyActor)->unk20, D_800C2994_de);
    }

    {
        f32 angle;
        angle = ((func_80224078_Arg1 *)bodyActor)->unk6C;
        angle += (held = D_800C2998_de);
        direction.x = ((func_80224078_Arg0 *)player)->unk6C0 * Gu_Sinf(angle);
    }
    direction.y = ((func_80224078_Arg1 *)bodyActor)->unk20;
    direction.z = ((func_80224078_Arg0 *)player)->unk6C0 *
                  Math_Cosf(((func_80224078_Arg1 *)bodyActor)->unk6C + held);
    held = D_800C299C_de;
    direction.x += ((func_80224078_Arg0 *)player)->unk6C4 *
                   Gu_Sinf(((func_80224078_Arg1 *)bodyActor)->unk6C - held);
    direction.z += ((func_80224078_Arg0 *)player)->unk6C4 *
                   Math_Cosf(((func_80224078_Arg1 *)bodyActor)->unk6C - held);

    GraphU64_ScaleVector(&direction, &direction, D_800D2988);
    GraphU64_AddVec3(&((func_80224078_Arg0 *)(player))->unk6E8,
                  &((func_80224078_Arg0 *)(player))->unk6E8, &direction);
    result = Scene_FindFloorPolygon(&g_world, &((func_80224078_Arg1 *)bodyActor)->unk8);
    if (result != 0) {
        ((func_80224078_Arg1 *)bodyActor)->unk14 = result;
    }

    if (((func_80224078_Arg0 *)player)->unk650 == 1 &&
        (((func_80224078_Arg0 *)player)->unk6AC & 0xE000) == 0xE000 &&
        (((func_80224078_Arg0 *)player)->unk6B0 & 0xE000)) {
        Player_SetPlayerState(player, bodyActor, 2);
        data = ((func_80224078_Arg0 *)player)->unk5DC;
        if (data != 0) {
            Camera_PostScreenMessage(&D_80145088, data, &s_flyModeOffText);
        }
    }
}

void Player_UpdateStandingState(SharedPlayer *player, BodyPlayerUpdateStandingState *body) {
    f32 heading;
    s32 crouching;
    s32 animate;

    func_80223E34_de(player, body);
    heading = body->heading;
    crouching = 5.12f < player->views5E8.view718_70.crouch;
    if (crouching) {
        Player_UpdateViewAngles(player, body, &D_800CE7FC);
    } else {
        Player_UpdateViewAngles(player, body, &D_800CE7E4);
    }
    heading = body->heading - heading;
    if (try_jump(player, body)) {
        return;
    }
    if (player->views5E8.view6A4_42.strafe != 0.0f || (player->views5E8.view7E8_106.zoomed != 2 && player->views5E8.view6A8_44.lift != 0.0f)) {
        Player_SetPlayerState(player, body, 3);
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
