#include "include_asm.h"
#include "COMMON/OBJ.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GROUP.H"
#include "COMMON/S1_6.H"
#include "TYPES.H"
#include "COMMON/VIEWFLAGS.H"
#include "FRONTEND/8042E080_70.H"
#include "RESMGR/802A0888.H"
#include "BULKYDCMP/BULKYDCMP.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/S2.H"
#include "COMMON/SHAPE_TYPEMAP_14.H"

/* 800C7C6C.CPP */

/* 80225D10_3.CPP */
/** Allocate and clear the player array and its per-player state blocks, linking each player to its block. */
extern void **Cache_AllocateResource(int, int, int, char *);

void Player_AllocPlayerList(PlayerList *list, int count) {
    int playerSize = count * sizeof(Players);
    int stateSize = count * 0x330;
    char *states;
    void **handle;
    int i;

    handle = Cache_AllocateResource(0, playerSize + stateSize, 0x23, s_playersText);
    list->handle = handle;
    list->count = count;
    list->players = *handle;
    states = (char *)list->players + playerSize;
    XPlus_FillMemory(list->players, 0, playerSize);
    XPlus_FillMemory(states, 0, stateSize);
    for (i = 0; i < count; i++) {
        list->players[i].state = states + i * 0x330;
    }
}

/* Updates every player in a world for one frame unless the game state D_8014687C is 8 or 11: turns
   the world's spin at 0x40 by 5 degrees, then for each player in the list from 0x20 runs its body
   through ContPad_BuildControllerState (restoring the frame time D_800D2988 it may change), its team logic through
   func_8022C490_de when either team rule is set, its controls through func_80220ED4_de unless input is
   frozen by D_80146894, and its camera through func_80220A80_de; a second pass opens the pause menu
   through Cinema_RequestSequenceFade for a paused player or one whose controller at 0x698 asks while a menu is
   possible, or otherwise starts the in-game menu for a live player with a view not already showing
   one (unless the match forbids it), before the match end check func_802283B8_de and the world updates
   Player_UpdateFragTagSelection and Player_ReleaseWaitingPlayer run and the frame time is restored. */

extern f32 D_800D2988;
extern MenuWeaponsUpdateWorldPlayers D_8014561C;
extern Game D_8014687C;
extern void func_8022C490_de(SharedPlayer *);
extern void func_80220ED4_de(SharedPlayer *);
extern void Player_UpdatePlayerCamera(SharedPlayer *, SharedPlayer *);

extern s32 Control_IsStartPressed(Shared_Effect *);

extern s32 Tsmos_IsFrontendActive(void);
extern s32 Menu_CountLiveNodes(MenuWeaponsUpdateWorldPlayers *);
extern void func_80218464_de(char *);

extern void func_802283B8_de(WorldWeaponsUpdateWorldPlayers *);
extern void Player_UpdateFragTagSelection(WorldWeaponsUpdateWorldPlayers *);
extern void Player_ReleaseWaitingPlayer(WorldWeaponsUpdateWorldPlayers *);

void Player_UpdateWorldPlayers(WorldWeaponsUpdateWorldPlayers *world) {
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
            ContPad_BuildControllerState((struct ControllerInput *)player->views5E8.view688_33.body, (Player *)player);
            D_800D2988 = frameTime;
            if (rules->teams != 0 || rules->teamRule != 0) {
                func_8022C490_de(player);
            }
            if (D_8011FAC0.clockPaused == 0) {
                func_80220ED4_de(player);
            }
            Player_UpdatePlayerCamera(player, player);
        }
        for (player = world->players; player != 0; player = player->views16E0.view16E0_2.next) {
            if (Cinema_IsSequenceActive() != 0 && (player->views5E8.view6B0_48.state & 0x8000)) {
                Cinema_RequestSequenceFade();
            } else if (Control_IsStartPressed(player->views5E8.view698_36.controller) != 0) {
                if (Cinema_IsSequenceActive() != 0 || Cinema_HasSequenceResource() != 0) {
                    Cinema_RequestSequenceFade();
                } else if (Tsmos_IsFrontendActive() == 0 && Menu_CountLiveNodes(&D_8014561C) == 0 && player->views5E4.view5E4_3.alive != 0
                           && player->views5DC.view5DC_2.view != 0 && player->views5DC.view5DC_2.view->unk564 == 0
                           && ((&D_8014561C.rules)->locked == 0 || D_8014561C.allowed == 0)) {
                    D_8014561C.open = 1;
                    func_8025E360_de();
                    func_8025E3A8_de();
                    func_80218464_de(player->views5E8.view938_130.strokes);
                    player->views5E8.viewF54_132.selection = -1;
                    player->views5E8.viewF90_134.choice = -1;
                    Frontend_OpenGameplayFrontend();
                }
            }
        }
        func_802283B8_de(world);
        Player_UpdateFragTagSelection(world);
        Player_ReleaseWaitingPlayer(world);
        D_800D2988 = frameTime;
    }
}

extern void MultiplyQuaternions(CQuatern *out, CQuatern *a, CQuatern *b);

void Player_BuildPlayerOrientation(Player *player, CQuatern *output)
{
    CQuatern pitchRotation;
    CQuatern yawRotation;
    CQuatern rollRotation;
    CQuatern orientation;
    CQuatern pitchYaw;
    CQuatern oriented;
    f32 pitch, yaw, roll, scale, heading;
    f32 rollAngle, pitchAngle, yawAngle;
    pitch = player->pitchOffset + player->sway[0] - player->state708;
    yaw = player->kickYaw + player->sway[1];
    roll = player->lean + player->sway[2];
    heading = player->heading;
    scale = 0.5f;
    rollAngle = roll * scale;
    orientation = player->orientation;
    D_80115DEC = Gu_Sinf(rollAngle);
    rollRotation.x = 0.0f;
    rollRotation.y = 0.0f;
    rollRotation.z = D_80115DEC;
    rollRotation.w = Math_Cosf(rollAngle);
    pitchAngle = pitch * scale;
    D_80115DEC = Gu_Sinf(pitchAngle);
    pitchRotation.x = D_80115DEC;
    pitchRotation.y = 0.0f;
    pitchRotation.z = 0.0f;
    pitchRotation.w = Math_Cosf(pitchAngle);
    yawAngle = (heading + yaw) * scale;
    D_80115DEC = Gu_Sinf(yawAngle);
    yawRotation.x = 0.0f;
    yawRotation.y = D_80115DEC;
    yawRotation.z = 0.0f;
    yawRotation.w = Math_Cosf(yawAngle);
    MultiplyQuaternions(&pitchYaw, &pitchRotation, &yawRotation);
    MultiplyQuaternions(&oriented, &pitchYaw, &orientation);
    MultiplyQuaternions(output, &rollRotation, &oriented);
}

extern void MatrixFromQuaternion(CQuatern *rotation, f32 matrix[4][4]);
extern void Graphu64_BuildTranslationMatrix(f32 matrix[4][4], f32 x, f32 y, f32 z);
extern void Graphu64_MultiplyAffineMatrices(f32 out[4][4], f32 a[4][4], f32 b[4][4]);
/* Builds a player view matrix: the eye height (base height plus camera offset less the crouch depth,
   at least 40.96) and the view pitch, yaw and roll (each with its kick and sway, the pitch less the
   head bob) become one half-angle quaternion per axis, combined roll * (pitch * yaw), then the
   matrix is rotation * eye-height lift * body orientation * translation to the player position plus
   its side and forward weapon offsets. */
void Player_BuildPlayerViewTransform(Player *player, f32 out[4][4])
{
    CQuatern pitchRotation;
    CQuatern yawRotation;
    CQuatern rollRotation;
    CQuatern orientation;
    CQuatern pitchYaw;
    CQuatern rotation;
    f32 viewRotation[4][4];
    f32 lift[4][4];
    f32 bodyRotation[4][4];
    f32 placement[4][4];
    f32 lifted[4][4];
    f32 oriented[4][4];
    f32 eyeHeight, height, pitch, yaw, roll, x, y, z, scale, heading;
    f32 rollAngle, pitchAngle, yawAngle;
    eyeHeight = player->baseHeight + player->cameraOffset - player->crouchDepth;
    pitch = player->pitchOffset + player->sway[0] - player->state708;
    yaw = player->kickYaw + player->sway[1];
    roll = player->lean + player->sway[2];
    x = player->pos.x + player->sideOffset;
    z = player->pos.z + player->forwardOffset;
    heading = player->heading;
    y = player->pos.y;
    height = (eyeHeight < 40.96f) ? 40.96f : eyeHeight;
    scale = 0.5f;
    rollAngle = roll * scale;
    orientation = player->orientation;
    D_80115DEC = Gu_Sinf(rollAngle);
    rollRotation.x = 0.0f;
    rollRotation.y = 0.0f;
    rollRotation.z = D_80115DEC;
    rollRotation.w = Math_Cosf(rollAngle);
    pitchAngle = pitch * scale;
    D_80115DEC = Gu_Sinf(pitchAngle);
    pitchRotation.x = D_80115DEC;
    pitchRotation.y = 0.0f;
    pitchRotation.z = 0.0f;
    pitchRotation.w = Math_Cosf(pitchAngle);
    yawAngle = (heading + yaw) * scale;
    D_80115DEC = Gu_Sinf(yawAngle);
    yawRotation.x = 0.0f;
    yawRotation.y = D_80115DEC;
    yawRotation.z = 0.0f;
    yawRotation.w = Math_Cosf(yawAngle);
    MultiplyQuaternions(&pitchYaw, &pitchRotation, &yawRotation);
    MultiplyQuaternions(&rotation, &rollRotation, &pitchYaw);
    MatrixFromQuaternion(&rotation, viewRotation);
    Graphu64_BuildTranslationMatrix(lift, 0.0f, height, 0.0f);
    MatrixFromQuaternion(&orientation, bodyRotation);
    Graphu64_MultiplyAffineMatrices(lifted, viewRotation, lift);
    Graphu64_MultiplyAffineMatrices(oriented, lifted, bodyRotation);
    Graphu64_BuildTranslationMatrix(placement, x, y, z);
    Graphu64_MultiplyAffineMatrices(out, oriented, placement);
}
