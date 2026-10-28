#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/WORLD.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_80103FD0.H"
#include "include_asm.h"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJRECV5.H"
#include "TYPES.H"

/* Runs a player's hold on a carried object: while the player has a view at 0x5DC, one frame in five
   on average it tints the view through func_802391AC_de with a random alpha below 7.5 and plays effect
   D_80145088 at the view's position; the hold time at 0x1D4 counts down by the frame time D_800D2988,
   and once it runs out or the hold flag at 0x5E4 is clear the player drops flag 0x800000, is released
   through Player_SetPlayerState, and lets go of the object at 0x13D8 through func_80216488_de (flags 0x30200 when
   the object is a carried actor with option 0x200, 0x4600 otherwise) before forgetting it and applying
   the result through func_80219A40_de. */









#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/INTEGERSTATE244.H"
#include "DATA/OVLDAT6/800CF230.H"

extern void Gsky_StartEmitter(char *, f32, f32, f32, f32, s32, Triple);
extern void Barrel_FillDamagePacket(Slot *, Held *, s32, f32, s32, s32);
extern void func_80219A40_de(SharedPlayer *, char *, Slot *);

void func_80226340_de(SharedPlayer *player) {
    Slot hit;
    ViewCode80225D10 *view;
    Held *owner;
    f32 alpha;
    s32 level;

    if (player->views5DC.view5DC_2.view != 0 && 80.0f < GraphU64_RandomFloat(100.0f)) {
        view = player->views5DC.view5DC_2.view;
        alpha = GraphU64_RandomFloat(7.5f);
        level = (u32) alpha;
        Gsky_StartFade(view, 0xFF, 0xFF, 0, 0, (u8) level, 3, 7);
        Gsky_StartEmitter(&D_80145088, 0.0f, 204.79999f, 0.0f, 512.0f, 0, view->position);
    }
    player->views1C.view1D4_21.holdTime -= D_800D2988;
    if (player->views1C.view1D4_21.holdTime <= 0.0f || player->views5E4.view5E4_4.holding == 0) {
        owner = 0;
        if (player->views13D8.view13D8_1.held->type == 1 && (player->views13D8.view13D8_1.held->flags & 0x300000)) {
            owner = player->views13D8.view13D8_1.held;
        }
        player->views1C.view100_9.flags &= ~0x800000;
        Player_SetPlayerState(player, player, 2);
        if (owner->options & 0x200) {
            Barrel_FillDamagePacket(&hit, player->views13D8.view13D8_1.held, 0x30200, 25.599998f, 0x80, 0);
        } else {
            Barrel_FillDamagePacket(&hit, player->views13D8.view13D8_1.held, 0x4600, 25.599998f, 0x80, 0);
        }
        player->views13D8.view13D8_1.held = 0;
        func_80219A40_de(player, player->views1C.view170_16.body, &hit);
    }
}







extern void **D_80103FCC;


extern void Player_UpdateViewAngles(void *, void *, void *);
extern Shared_Quad Playerai_ComputeAimRotation(void *, void **, Shared_Quad *);
extern f32 Graphu64_GetPointDistance(f32 *, f32 *);
extern s32 CCollision_SweepPoint(void *, CVector3, CVector3, void *);
extern void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern f32 GraphU64_GetHorizontalAngle(CVector3 *);











void func_80226548_de(void *player, void *body) {
    Shared_Quad aimRotation;
    Shared_Quad aimWords;
    CVector3 toTarget;
    void *aimTarget;
    f32 targetAngle;
    f32 *position;
    f32 comparisonAngle;

    Player_UpdateViewAngles(player, body, &D_800CE7E4);
    if (((Shared_ActorView *)player)->targeting != 0) {
        aimRotation = Playerai_ComputeAimRotation(player, &aimTarget, &aimWords);
        if (aimTarget != 0) {
            position = &((Shared_ActorView *)player)->position.vector.x;
            if (!(D_800C2B48_de[1] < Graphu64_GetPointDistance(position, &((Shared_ActorView *)aimTarget)->position.vector.x))) {
                if (CCollision_SweepPoint(player, ((Shared_ActorView *)player)->position.vector,
                                     ((Shared_ActorView *)aimTarget)->position.vector,
                                     &D_80103FD0) == 0 ||
                    *D_80103FCC == aimTarget) {
                    GraphU64_SubtractVectors(&toTarget, &((Shared_ActorView *)aimTarget)->position.vector, (CVector3 *)position);
                    targetAngle = GraphU64_GetHorizontalAngle(&toTarget);
                    Graphu64_WrapPeriodicValue(&targetAngle);
                    Graphu64_WrapPeriodicValue(&((LevelActor *)body)->yaw);
                    comparisonAngle = ((LevelActor *)body)->yaw;
                    if (D_800C2B50_de < comparisonAngle) {
                        if (targetAngle < D_800C2B54_de) {
                            targetAngle += D_800C2B58_de;
                        } else {
                            goto positive;
                        }
                    } else {
positive:
                        comparisonAngle = targetAngle;
                        if (D_800C2B5C_de < comparisonAngle &&
                            ((LevelActor *)body)->yaw < D_800C2B60_de) {
                            ((LevelActor *)body)->yaw =
                                ((LevelActor *)body)->yaw + D_800C2B64_de;
                        }
                    }
                    GraphU64_EaseValueToward(&((LevelActor *)body)->yaw, targetAngle, D_800C9FEC);
                }
            }
        }
    }
}

#include "TYPES.H"

typedef struct { u8 pad0[0x18]; s32 health; u8 pad1C[0xE0]; f32 x, y, z; } ActorTemplate;
typedef struct { u8 pad0[0x80]; s8 kind; u8 pad81[0xE]; u8 special; u8 pad90[4]; u8 boosted; } PlayerInfo;
typedef struct {
    u8 pad0[3]; s8 alpha; u8 pad4[0x14]; ActorTemplate *model;
    u8 pad1C[0x34]; f32 x, y, z; u8 pad5C[0x118]; s32 health;
    u8 pad178[0x45C]; s32 slot; PlayerInfo *info; s32 pad5DC;
    s32 modelId; s32 maxHealth; u8 pad5E8[0xE68]; s32 bot;
} BonusPlayer;
typedef struct { s32 value; u8 pad4[0x18C]; } PlayerBonus;
struct Shared_World;
extern void *Scene_FindActorDefinition(struct Shared_World *, s32, s32);

/* D_801468F4 and D_80146938 are game option words, read through an option view. */
typedef struct { s32 enabled; } GameOption;
static inline s32 optionEnabled(GameOption *option) {
    return option->enabled;
}
static inline ActorTemplate *findModel(s32 kind, s32 id) {
    return Scene_FindActorDefinition(&g_world, kind, id);
}
static inline s32 startHealth(BonusPlayer *player) {
    s32 health;
    s8 kind;
    if (optionEnabled((GameOption *)&D_801462C8.counters.enabled) && player->info->boosted != 0) {
        kind = player->info->kind;
        if (kind == 0xB) health = 0x19000;
        else if (kind == 0xC) health = 0x19000;
        else if (kind == 0xE) health = 0x12C00;
        else if (kind == 0xD) health = 0x12C00;
        else health = player->model->health << 8;
    } else {
        health = player->model->health << 8;
    }
    if (D_801462C8.controllerMode == 1 && player->bot == 0) health += ((PlayerBonus *)D_800FEB10)[player->slot].value;
    return health;
}
void Playerai_InitializePlayerHealth(BonusPlayer *player) {
    ActorTemplate *model;
    s32 id;
    id = player->modelId;
    if (optionEnabled((GameOption *)&D_801462C8.counters.m_bFragTagOn) && player->info->special == 1) id = 0x13;
    model = findModel(0xB, id);
    if (model == 0) {
        model = findModel(0xB, -1);
        if (model == 0) model = findModel(-1, -1);
    }
    player->model = model;
    player->x = model->x; player->y = model->y; player->z = model->z;
    if (optionEnabled((GameOption *)&D_801462C8.counters.m_bFragTagOn) && player->info->special != 0) {
        player->maxHealth = 0xA00;
        player->health = 0xA00;
        return;
    }
    player->maxHealth = startHealth(player);
    player->health = startHealth(player);
    player->alpha = 0xFF;
}
