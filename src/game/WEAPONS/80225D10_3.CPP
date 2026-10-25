#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GROUP.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "COMMON/VIEWFLAGS.H"
#include "FRONTEND/8042E080_70.H"
#include "RESMGR/802A0888.H"

/** Allocate and clear the player array and its per-player state blocks, linking each player to its block. */
extern void **Scene_AllocateResource(int, int, int, char *);

void func_80226950_de(PlayerList *list, int count) {
    int playerSize = count * sizeof(Players);
    int stateSize = count * 0x330;
    char *states;
    void **handle;
    int i;

    handle = Scene_AllocateResource(0, playerSize + stateSize, 0x23, D_800C2B68_de);
    list->handle = handle;
    list->count = count;
    list->players = *handle;
    states = (char *)list->players + playerSize;
    Resmgr_FillMemory(list->players, 0, playerSize);
    Resmgr_FillMemory(states, 0, stateSize);
    for (i = 0; i < count; i++) {
        list->players[i].state = states + i * 0x330;
    }
}

/* Updates every player in a world for one frame unless the game state D_8014687C is 8 or 11: turns
   the world's spin at 0x40 by 5 degrees, then for each player in the list from 0x20 runs its body
   through Fx_BuildControllerState (restoring the frame time D_800D2988 it may change), its team logic through
   func_8022C490_de when either team rule is set, its controls through func_80220ED4_de unless input is
   frozen by D_80146894, and its camera through func_80220A80_de; a second pass opens the pause menu
   through func_8024570C_de for a paused player or one whose controller at 0x698 asks while a menu is
   possible, or otherwise starts the in-game menu for a live player with a view not already showing
   one (unless the match forbids it), before the match end check func_802283B8_de and the world updates
   func_80227038_de and Weapons_ReleaseWaitingPlayer run and the frame time is restored. */
















extern f32 D_800D2988;
extern Menu_func_80226A34_de D_8014561C;
extern Game D_8014687C;
extern s32 D_80146894;
extern void func_8022C490_de(SharedPlayer *);
extern void func_80220ED4_de(SharedPlayer *);
extern void func_80220A80_de(SharedPlayer *, SharedPlayer *);

extern s32 func_8026435C_de(Shared_Effect *);

extern s32 func_802A23B4_de(void);
extern s32 func_80442A28_de(Menu_func_80226A34_de *);
extern void func_8025E360_de(void);
extern void func_8025E3A8_de(void);
extern void func_80218464_de(char *);

extern void func_802283B8_de(World_func_80226A34_de *);
extern void func_80227038_de(World_func_80226A34_de *);
extern void Weapons_ReleaseWaitingPlayer(World_func_80226A34_de *);

void func_80226A34_de(World_func_80226A34_de *world) {
    f32 frameTime;
    SharedPlayer *player;
    Rules *rules;

    if (D_8014687C.state != 0xB && D_8014687C.state != 8) {
        frameTime = D_800D2988;
        world->spin += 5;
        if (world->spin >= 360) {
            world->spin = 0;
        }
        rules = &D_8014687C.rules;
        for (player = world->players; player != 0; player = player->views16E0.view16E0_2.next) {
            Fx_BuildControllerState((struct ControllerInput *)player->views5E8.view688_33.body, (Player *)player);
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
        Weapons_ReleaseWaitingPlayer(world);
        D_800D2988 = frameTime;
    }
}

#ifdef NON_MATCHING
#include "COMMON/AIPROFILE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S2.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"
#include "TYPES.H"

extern float D_800C2B70_de;
extern f32 D_80115DEC;
extern void func_80274098_de(void *arg0, void *arg1, void *arg2);

void Weapons_BuildPlayerOrientation(void *object, CQuatern *output)
{
    CQuatern pitchRotation;
    CQuatern yawRotation;
    CQuatern rollRotation;
    CQuatern orientation;
    CQuatern pitchYaw;
    CQuatern oriented;
    Player *player = object;
    float pitch;
    float roll;
    float heading;
    float yaw;
    float scale;

    heading = player->heading;
    roll = player->lean + player->state738;
    pitch = player->pitchOffset + player->state730;
    pitch -= player->state708;
    orientation = player->orientation;
    scale = D_800C2B70_de;
    yaw = player->state728 + player->state734;
    roll *= scale;

    D_80115DEC = func_802B7130_de(roll);
    pitch *= scale;
    rollRotation.x = 0.0f;
    rollRotation.y = 0.0f;
    rollRotation.z = D_80115DEC;
    rollRotation.w = func_802B6560_de(roll);

    D_80115DEC = func_802B7130_de(pitch);
    pitchRotation.x = D_80115DEC;
    pitchRotation.y = 0.0f;
    pitchRotation.z = 0.0f;
    pitchRotation.w = func_802B6560_de(pitch);

    heading = (heading + yaw) * scale;
    D_80115DEC = func_802B7130_de(heading);
    yawRotation.x = 0.0f;
    yawRotation.y = D_80115DEC;
    yawRotation.z = 0.0f;
    yawRotation.w = func_802B6560_de(heading);

    func_80274098_de(&pitchYaw, &pitchRotation, &yawRotation);
    func_80274098_de(&oriented, &pitchYaw, &orientation);
    func_80274098_de(output, &rollRotation, &oriented);
}
#else
INCLUDE_ASM("span_1000", Weapons_BuildPlayerOrientation);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "FX/EXTERNS.H"
extern f32 D_800C2B74_de, D_800C2B78_de, D_80115DEC;
extern void func_80274098_de(void *, void *, void *), func_80274244_de(void *, void *), func_80272C60_de(void *, f32, f32, f32), func_8026F620_de(void *, void *, void *);
void Weapons_BuildPlayerViewTransform(SharedPlayer *player, f32 out[4][4])
{
    f32 qx[4], qy[4], qz[4];
    Shared_Quad rotation;
    f32 q1[4], q2[4];
    f32 m1[4][4], m2[4][4], m3[4][4], m4[4][4], m5[4][4], m6[4][4];
    f32 height, pitch, yaw, roll, x, y, z, scale, baseYaw, angle;
    height = player->views5E8.view740_83.unk740 + player->views5E8.view780_116.unk780 - player->views5E8.view718_70.crouch;
    pitch = player->views5E8.view724_72.pitch + player->views5E8.view730_78.unk730[0] - player->views5E8.view704_67.viewPitch;
    yaw = player->views5E8.view728_73.unk728 + player->views5E8.view730_78.unk730[1];
    roll = player->views5E8.view72C_75.unk72C + player->views5E8.view730_78.unk730[2];
    x = player->views0.view8_4.position.x + player->views5E8.view73C_80.unk73C;
    z = player->views0.view8_4.position.z + player->views5E8.view744_85.unk744;
    y = player->views0.view8_4.position.y;
    baseYaw = player->views1C.view6C_5.heading;
    if (height < D_800C2B74_de) height = D_800C2B74_de;
    scale = D_800C2B78_de;
    angle = roll * scale;
    rotation = player->views1C.view5C_6.unk5C;
    D_80115DEC = func_802B7130_de(angle);
    qz[0] = 0; qz[1] = 0; qz[2] = D_80115DEC;
    qz[3] = func_802B6560_de(angle);
    angle = pitch * scale;
    D_80115DEC = func_802B7130_de(angle);
    qx[0] = D_80115DEC; qx[1] = 0; qx[2] = 0;
    qx[3] = func_802B6560_de(angle);
    angle = (baseYaw + yaw) * scale;
    D_80115DEC = func_802B7130_de(angle);
    qy[0] = 0; qy[1] = D_80115DEC; qy[2] = 0;
    qy[3] = func_802B6560_de(angle);
    func_80274098_de(q1, qx, qy);
    func_80274098_de(q2, qz, q1);
    func_80274244_de(q2, m1);
    func_80272C60_de(m2, 0.0f, height, 0.0f);
    func_80274244_de(rotation.f, m3);
    func_8026F620_de(m5, m1, m2);
    func_8026F620_de(m6, m5, m3);
    func_80272C60_de(m4, x, y, z);
    func_8026F620_de(out, m6, m4);
}
#else
INCLUDE_ASM("span_1000", Weapons_BuildPlayerViewTransform);
#endif
