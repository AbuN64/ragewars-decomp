#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ROUND_STATE_VARIANTS.H"

/* Player state, projectiles, effects and linked-actor transitions. */
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/VECTOR4F.H"
#include "RENDER_2/OBJECTSTATE8E.H"
#include "COMMON/RESULTS.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"
#include "RENDER_2/802192C0_3.H"
/* Apply player transitions, regional control gates, and localized linked-actor notifications. */






extern const Shared_HeightBonuses D_800C2608_eu;
extern const f32 D_800C22A0_us;
extern const f32 D_800C22A4_us;
extern s32 D_800C9228_de[2];



                                                  /* size = 0x18 */




void *Nav_GetGraphPoint(void *, s32);
s32 func_8020CB3C_de(void *, void *);
s32 Weapons_SetPlayerState(void *, void *, s32);
#ifndef NON_MATCHING
void *Camera_PostScreenMessage(void *, void *, u8 *);
#endif
void *Camera_PostScaledScreenMessage(void *, void *, void *, f32); CQuatern func_8024796C_de(char *);
s32 func_8024BE80_de(void *);
void func_8024E79C_de(void *, Triple, void *, s32 *, s32, s32); /* extern */
s32 Render_PlaySoundAtPosition(s16, CVector3, s32, s32); /* extern */
void func_802647E8_de(void *, s32);
void func_80278D78_de(void *, s32, void *);
void func_80278E04_de(s32, s32, void *);
s32 func_802800C0_de(void *, void *, void *, s32 *, s32, s32, CVector3, CQuatern, CVector3, CVector3 *, s32, s32); /* extern */
void func_80283278_de(void *, s32);
s32 func_8028B21C_de(struct Shared_World *, s32);
void func_8028B898_de(void *, void *, s32);
void *func_8028FFD0_de(void *, s32 *, s32, CVector3, CVector3, s32, f32); /* extern */
struct ListNode80290528;
void func_80290548_de(struct ListNode80290528 *);
s32 func_802A01E8_de(void);
s32 Ovlgame_ResetPlayerForRound(void *, s8, s32);         /* extern */
void func_8044972C_de(void *);
void Items_ReleaseObjectHandles(void *);


extern s32 D_8011D8D0;


extern s32 D_8013B364;
extern struct Shared_GlobalRuntimeState D_80145060;










 /* unable to generate initializer: non-zero padding; const */








void func_8021B468_de(struct Shared_ActorView *player, void *attacker, s32 arg2, s32 state) {
    CVector3 spawnPosition;
    struct CVector3_t spawnVector;
    struct CVector3_t motionVector;
    struct Shared_GlobalPlayers *playersGlobal;
    struct Shared_GlobalFlowState *flow;
    struct Shared_GlobalFlowState *laterFlow;
    struct GameLocalizationState *localization;
    s32 *messageContext;
    CQuatern motionOutput;
    s32 sp90;
    
    s8 *settingsBase;
    struct Shared_PlayerSettingsRecord *var_s1;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s0_4;
    s32 temp_v1_9;
    s16 var_a0_4;
    s16 var_a0_5;
    void *temp_a1_2;
    void *temp_a1_3;
    s32 temp_s0_6;
    void *temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a2;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 i;
    
    s32 loopLimit;
    s32 var_s3_2;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    struct Shared_struct_D_800D34C0_0x18 *temp_v0_10;
    struct Shared_struct_D_800D34C0_0x18 *temp_v0_4;
    struct Shared_struct_D_800D34C0_0x18 *temp_v0_7;
    u16 temp_v1_3;
    u16 temp_v1_5;
    u32 temp_v1;
    void *temp_a1;
    void *temp_s0;
    void *temp_s0_5;
    void *temp_v0;
    void *temp_v1_2;
    void *var_s0;
    void *var_s0_2;

    func_802647E8_de(((struct Shared_ActorView *)player)->controller, 0);
    if (((struct Shared_ActorView *)player)->action == 0x27) {
        Weapons_SetPlayerState(player, attacker, 2);
    }
    ((struct Shared_ActorView *)player)->field1218 = 0;
    func_80278D78_de(attacker, 1, attacker);
    Items_ReleaseObjectHandles(player);
    func_8022B530_de((s32)player);
    ((struct Shared_ActorView *)player)->stun = 0;
    ((struct Shared_ActorView *)player)->markerTime = 0;
    func_80283278_de(&D_8011D8D0, (s32)player);
    flow = &D_80145060.flow;
    if ((flow->active != 0)
        && gameplayTransitionEnabled(player->controls->germanActive)
        && (i = 0, (((struct Shared_ActorView *)player)->controls->mode == 0xE))) {
        flow->count = (s32) (flow->count + 1);
        playersGlobal = (struct Shared_GlobalPlayers *)&D_80145040;
        if (playersGlobal->count > 0) {
            settingsBase = (s8 *)&D_80146398;
            var_s1 = (struct Shared_PlayerSettingsRecord *)settingsBase;
            var_s4 = 0;
settings_loop:
            do {
                temp_s0 = playersGlobal->players + var_s4;
                if (var_s1->active != 0) {
                    if (((struct Shared_PlayerSettingsView *)settingsBase)->state == 1) {
                    ((struct Shared_ActorView *)temp_s0)->actorState = (s32) ((struct Shared_PlayerSettingsView *)settingsBase)->state;
                    Ovlgame_ResetPlayerForRound(temp_s0, var_s1->character, 1);
                    temp_v0 = ((struct Shared_ActorView *)temp_s0)->model;
                    ((struct Shared_ModelView *)temp_v0)->flags = (s32) (((struct Shared_ModelView *)temp_v0)->flags & ~4);
                    Weapons_RequestActorState(&((struct Shared_ActorView *)temp_s0)->weapon, &((struct Shared_ActorView *)temp_s0)->weapon.behaviorFlags, 2);
                    Render_PlacePlayerAtSpawnPoint(temp_s0, ((struct Shared_PlayerSettingsView *)settingsBase)->effect, 0, 0);
                    func_80255ED8_de(playersGlobal->controller, temp_s0);
                    func_80255CB8_de(&playersGlobal->effects, temp_s0);
                    } else if (((struct Shared_PlayerSettingsView *)settingsBase)->state < 3) {
                        func_8044972C_de(temp_s0);
                    }
                }
block_13:
                do {
                    var_s1++;
                } while (0);
                loopLimit = playersGlobal->count;
                do {
                    i += 1;
                } while (0);
                var_s4 += 0x16E8;
                if (i < loopLimit) goto settings_loop;
            } while (0);
        }
        if (D_801462C8.counters.m_nTalsetLives < 3) {
            ((struct Shared_ActorView *)player)->special = 0;
            Weapons_SetPlayerState(player, attacker, 0x2E);
            return;
        } else {
            goto block_17;
        }
    } else {
block_17:
        if (D_80145088.settings.local != 0) {
            if ((((struct Shared_ActorView *)player)->ammo[0] > 0) || (((struct Shared_ActorView *)player)->ammo[1] > 0) || (((struct Shared_ActorView *)player)->ammo[2] > 0)) {
                temp_v1 = ((struct Shared_ActorView *)player)->mode;
                var_s3_2 = 0;
                switch (temp_v1) {
case 0:
default:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBD9;
                    break;
case 1:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBDB;
                    break;
case 2:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBDD;
                    break;
case 3:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBDF;
                    break;
case 4:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE1;
                    break;
case 5:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE3;
                    break;
case 6:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE5;
                    break;
case 7:
                    var_s1_2 = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE7;
                    break;
                }
                func_8028B21C_de(&D_8011FE88, var_s1_2);
                temp_v1_2 = ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex];
                if (temp_v1_2 != 0) {
                    ((struct Shared_ProjectileView *)temp_v1_2)->flags = (u16) (((struct Shared_ProjectileView *)temp_v1_2)->flags | 1);
                    temp_a1 = ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex];
                    if (((struct Shared_ProjectileView *)temp_a1)->flags & 8) {
                        func_80290548_de(temp_a1);
                    } else {
                        func_8028B898_de(&D_8011FE88, temp_a1, 1);
                        func_80278E04_de(((struct Shared_ProjectileView *)((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex])->source, 0x400, player);
                    }
                }
                temp_v1_3 = ((struct Shared_ActorView *)player)->kind;
                if (temp_v1_3 == D_800CE474[0]) {
                    var_s3_2 = 0;
                } else if (temp_v1_3 == D_800CE474[1]) {
                    var_s3_2 = 0;
                } else {
                    switch (func_802A01E8_de() % 3) {            /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        temp_s0_2 = ((struct Shared_ActorView *)player)->ammo[0];
                        var_a0 = 0;
                        if (temp_s0_2 != 0) {
                            temp_v0_2 = func_802A01E8_de();
                            temp_v0_3 = temp_v0_2 / temp_s0_2;
                            if (temp_s0_2 == 0) {

                            }
                            if ((temp_s0_2 == -1) && (temp_v0_3 == 0x80000000)) {

                            }
                            var_a0 = temp_v0_2 % temp_s0_2;
                        }
                        if (var_a0 != 0) {
                            var_s3_2 = 1;
                            temp_v0_4 = &D_800D34C0[((struct Shared_ActorView *)player)->projectileBase + ((struct Shared_ActorView *)player)->projectileIndex];
                            temp_v0_4->unkC = (s16) var_a0;
                            temp_v0_4->unkE = 0;
                            temp_v0_4->unk10 = 0;
                        }
                        break;
                    case 1:                         /* switch 2 */
                        temp_s0_3 = ((struct Shared_ActorView *)player)->ammo[1];
                        var_a0_2 = 0;
                        if (temp_s0_3 != 0) {
                            temp_v0_5 = func_802A01E8_de();
                            temp_v0_6 = temp_v0_5 / temp_s0_3;
                            if (temp_s0_3 == 0) {

                            }
                            if ((temp_s0_3 == -1) && (temp_v0_6 == 0x80000000)) {

                            }
                            var_a0_2 = temp_v0_5 % temp_s0_3;
                        }
                        if (var_a0_2 != 0) {
                            var_s3_2 = 1;
                            temp_v0_7 = &D_800D34C0[((struct Shared_ActorView *)player)->projectileBase + ((struct Shared_ActorView *)player)->projectileIndex];
                            temp_v0_7->unkE = (s16) var_a0_2;
                            temp_v0_7->unkC = 0;
                            temp_v0_7->unk10 = 0;
                        }
                        break;
                    case 2:                         /* switch 2 */
                        temp_s0_4 = ((struct Shared_ActorView *)player)->ammo[2];
                        var_a0_3 = 0;
                        if (temp_s0_4 != 0) {
                            temp_v0_8 = func_802A01E8_de();
                            temp_v0_9 = temp_v0_8 / temp_s0_4;
                            if (temp_s0_4 == 0) {

                            }
                            if ((temp_s0_4 == -1) && (temp_v0_9 == 0x80000000)) {

                            }
                            var_a0_3 = temp_v0_8 % temp_s0_4;
                        }
                        if (var_a0_3 != 0) {
                            var_s3_2 = 1;
                            temp_v0_10 = &D_800D34C0[((struct Shared_ActorView *)player)->projectileBase + ((struct Shared_ActorView *)player)->projectileIndex];
                            temp_v0_10->unk10 = (s16) var_a0_3;
                            temp_v0_10->unkC = 0;
                            temp_v0_10->unkE = 0;
                        }
                        break;
                    }
                }
                if (var_s3_2 != 0) {
                    temp_s0_5 = Nav_GetGraphPoint(&D_8013B364, func_8020CB3C_de(&D_8013B364, &player->position.vector));
                    func_8024E79C_de(player, player->position.words, &spawnPosition, &sp90, 0, 0);
                    if (temp_s0_5 != 0) {
                        spawnPosition = *(CVector3 *)temp_s0_5;
                    }
                    spawnVector.x = 0;
                    spawnVector.y = 0.0f;
                    spawnVector.z = 0;
                    temp_v0_11 = func_8028FFD0_de(&D_80131600, 0, var_s1_2, spawnVector, spawnPosition, 0, 0);
                    if (temp_v0_11 != 0) {
                        spawnPosition.y += D_800C2608_eu.spawn;
                        ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex] = (void *)temp_v0_11;
                    }
                } else {
                    ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex] = 0;
                }
                ((struct Shared_ActorView *)player)->projectileIndex = (s32) (((struct Shared_ActorView *)player)->projectileIndex == 0);
            }
            if ((((struct Shared_ActorView *)player)->controls->transientFlag != 0) && (laterFlow = &D_80145060.flow, laterFlow->transition != 0)) {
                if (D_800F3D08 != 0) {
                    Weapons_RequestActorState(D_800F3D08, ((struct Shared_SpecialObjectView *)D_800F3D08)->segment, 1);
                    ((struct Shared_SpecialObjectView *)D_800F3D08)->reset = 0;
                    laterFlow->reset = 0;
                    Render_PlayFlatSound(0x2D0);
                    var_s0 = D_80145060.actorList;
                    if (var_s0 != 0) {
                        messageContext = &D_80145060.messageContext;
                        localization = &D_80145060.localization;
                        do {
                            temp_a1_2 = ((struct Shared_ActorView *)var_s0)->message;
                            if (temp_a1_2 != 0) {
                                Camera_PostScreenMessage(gameplayMessageContext(messageContext), temp_a1_2, gameplayResetMessage(localization->language));
                            }
                            var_s0 = ((struct Shared_ActorView *)var_s0)->next;
                        } while (var_s0 != 0);
                    }
                }
                ((struct Shared_ActorView *)player)->controls->transientFlag = 0U;
                ((struct Shared_ActorView *)player)->controls->resetFlag = 0;
            }
            var_s0_2 = D_80145060.actorList;
            if (var_s0_2 != 0) {
                messageContext = &D_80145060.messageContext;
                localization = &D_80145060.localization;
                do {
                    if ((var_s0_2 != player) && (((struct Shared_ActorView *)var_s0_2)->parent == player)) {
                        temp_a1_3 = ((struct Shared_ActorView *)var_s0_2)->message;
                        ((struct Shared_ActorView *)var_s0_2)->pending = 0;
                        ((struct Shared_ActorView *)var_s0_2)->parent = 0;
                        if (temp_a1_3 != 0) {
                            Camera_PostScaledScreenMessage(gameplayMessageContext(messageContext), temp_a1_3, gameplayReleaseMessage(localization->language), 1.0f);
                        }
                    }
                    var_s0_2 = ((struct Shared_ActorView *)var_s0_2)->next;
                } while (var_s0_2 != 0);
            }
        }
        ((struct Shared_ActorView *)player)->field1238 = -1;
        ((struct Shared_ActorView *)player)->field1230 = 0;
        ((struct Shared_ActorView *)player)->field1234 = 0;
        ((struct Shared_ActorView *)player)->field1240 = 0;
        ((struct Shared_ActorView *)player)->field122C = (s32) (((struct Shared_ActorView *)player)->field122C & 0xFFFF0000);
        if (arg2 & 0x4000) {
            if ((u32) (((struct Shared_ActorView *)player)->state - 0x11) < 2U) {
                ((struct Shared_ActorView *)player)->special = 1;
            }
        }
        if (((struct Shared_ActorView *)player)->special == 0) {
            var_a0_4 = 0x2BC;
            if (state != 0x1F) {
                var_a0_4 = func_80229C0C_de(player, 0x1397);
            }
            Render_PlaySoundAtPosition(var_a0_4, player->position.vector, (s32)&player->position.vector, -1);
        } else {
            Render_PlaySoundAtPosition(0x9FB, player->position.vector, (s32)&player->position.vector, -1);
        }
        Render_PlayFlatSound(0x212);
        if ((((struct Shared_ActorView *)player)->special != 0) || (temp_v1_5 = ((struct Shared_ActorView *)player)->kind, (temp_v1_5 == D_800C9228_de[0])) || (temp_v1_5 == D_800C9228_de[1])) {
            spawnVector.x = player->position.vector.x;
            spawnVector.y = player->position.vector.y + D_800C2608_eu.projectile;
            var_s1_3 = 1;
            spawnVector.z = player->position.vector.z;
            var_v0 = func_802A01E8_de();
            temp_v1_6 = var_v0;
            if (temp_v1_6 < 0) {
                var_v0 = temp_v1_6 + 0x3FF;
            }
            motionVector.x = (f32) (temp_v1_6 - ((var_v0 >> 0xA) << 0xA)) - D_800C22A0_us;
            var_v0_2 = func_802A01E8_de();
            temp_v1_7 = var_v0_2;
            if (temp_v1_7 < 0) {
                var_v0_2 = temp_v1_7 + 0x3FF;
            }
            motionVector.y = (f32) (temp_v1_7 - ((var_v0_2 >> 0xA) << 0xA)) - D_800C22A0_us;
            var_v0_3 = func_802A01E8_de();
            temp_v1_8 = var_v0_3;
            if (temp_v1_8 < 0) {
                var_v0_3 = temp_v1_8 + 0x3FF;
            }
            motionVector.z = (f32) (temp_v1_8 - ((var_v0_3 >> 0xA) << 0xA)) - D_800C22A0_us;
            motionOutput = func_8024796C_de((char *)player);
            temp_s0_6 = ((struct Shared_ActorView *)player)->frameValue;
            if (func_8024BE80_de(player) == 5) {
                var_s1_3 = 3;
            }
            func_802800C0_de(&D_8011D8D0, player, player, 0, temp_s0_6, 0x64, motionVector, motionOutput, spawnVector, 0, -1, var_s1_3);
        }
        if (state != -1) {
            Weapons_SetPlayerState(player, attacker, state);
            return;
        }
        if (((struct Shared_ActorView *)player)->state != 0x11) {
            if (((struct Shared_ActorView *)player)->action == 0xA && (arg2 & 0x4000)) {
                Weapons_SetPlayerState(player, attacker, 0x2A);
                return;
            }
            if (arg2 & 0x4000) {
                Weapons_SetPlayerState(player, attacker, 0x29);
                return;
            }
        }
        var_v0_4 = 1;
        if (!(((struct Shared_ActorView *)player)->speed > D_800C22A4_us)) {
            var_v0_4 = 0;
        }
        if (var_v0_4 != 0) {
            Weapons_SetPlayerState(player, attacker, 0x1C);
            return;
        }
        temp_v1_9 = ((struct Shared_ActorView *)player)->action;
        if ((temp_v1_9 ^ 0xF) == 0) {
            Weapons_SetPlayerState(player, attacker, 0x21);
            return;
        }
        if (temp_v1_9 == 9) {
            Weapons_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (temp_v1_9 == 10) {
            Weapons_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (temp_v1_9 == 11) {
            Weapons_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (temp_v1_9 == 12) {
            Weapons_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (arg2 & 0x1000) {
            Weapons_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (arg2 & 0x200) {
            Weapons_SetPlayerState(player, attacker, 0x19);
            return;
        }
        if ((((struct Shared_ActorView *)player)->state != 0x11) && (((struct Shared_ActorView *)player)->specialState == 1)) {
            Weapons_SetPlayerState(player, attacker, 0x1E);
            return;
        }
        if (((struct Shared_ActorView *)player)->specialState == 2) {
            Weapons_SetPlayerState(player, attacker, 0x1D);
            return;
        }
        Weapons_SetPlayerState(player, attacker, 0x16);
        return;
    }
}

#if defined(VERSION_US) || defined(VERSION_US_REV1) || defined(NON_MATCHING)
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C22A8_us, D_800C22AC_us, D_800C22B0_us;
extern s32 D_800D2A90;
extern char D_801468A0[];
extern s32 func_8022C460_de(void *);
extern s32 func_8022AC00_de(void *);
extern void func_8028CE94_de(void *, void *, s32, CVector3, f32, f32);
extern void func_80239194_de(void *, s32, s32);
extern void func_8022B11C_de(void *, u16);
/* Applies damage to a player: ignored while the game is paused, the player is protected or the damage
 * source is not allowed; scales the amount by one fifth with armour (0x80C); when the health stays above
 * zero and drops through half of the maximum it respawns the weapon (Render_PlacePlayerAtSpawnPoint); lowers the health
 * (with a flash sound at random), starts the knock-back and the hit effect scaled by the damage, and on death
 * reports the kill through func_8021B468_de. */
/* Exact for us and us-rev1; de/eu/eu-x add extra checks (0x1450, 0x94) and keep their asm. */
void Render_ApplyPlayerDamage(void *player, void *attacker, s32 amount, s32 arg3, s32 kind) {
    s32 oldHealth = FIELD(s32, player, 0x5E4);
    s32 health;
    s32 threshold;
    s32 step;
    s32 found;
    s32 dead;
    s32 wasDead;
    s32 intensity;
    s32 delay;
    s32 roll;
    s32 shifted;
    char *state;
    s32 remaining;
    if (Camera_IsSequenceActive() != 0 || func_8022C460_de(player) != 0 || D_8011FE88.frozen != 0) {
        return;
    }
    if ((FIELD(u32, &D_801462C8, 0) & 1) && kind != 0x20) {
        return;
    }
    if (FIELD(u16, player, 0x650) < 2) {
        return;
    }
    if (FIELD(s32, player, 0x80C) != 0) {
        amount = amount / 5;
    }
    if (0.0f < FIELD(f32, player, 0x670) && kind != 0x20) {
        return;
    }
    wasDead = FIELD(s32, player, 0x5E4) == 0;
    if (FIELD(u32, player, 0x122C) & 0x100) {
        health = FIELD(s32, player, 0x5E4) - amount;
        if (health < 0) {
            health = 0;
        }
        step = func_8022AC00_de(player);
        found = 0;
        for (threshold = 2; threshold < 5; threshold++) {
            step = step - step / 2;
            if (step < FIELD(s32, player, 0x5E4) && health < step && health > 0) {
                found = 1;
                break;
            }
        }
        if (found != 0) {
            Render_PlacePlayerAtSpawnPoint(player, FIELD(s32, player, 0x5EC), 0, 1);
        }
    }
    state = D_801468A0;
    if (FIELD(s32, state, 0x98) != 0 && FIELD(s8, FIELD(void *, player, 0x5D8), 0x80) == 0xB && FIELD(s32, state, 0xA0) > 0) {
        FIELD(s32, state, 0xA0) -= amount >> 8;
        if (FIELD(s32, state, 0xA0) <= 0) {
            FIELD(s32, state, 0xA0) = 0;
            switch (FIELD(u8, FIELD(void *, player, 0x5D8), 0x93)) {
            case 0:
                FIELD(s32, state, 0xA4) = 0x4B;
                break;
            case 1:
                FIELD(s32, state, 0xA4) = 0x3C;
                break;
            case 2:
                FIELD(s32, state, 0xA4) = 0x3C;
                break;
            }
            Weapons_SetPlayerState(player, player, 0x2D);
        }
        amount = 0;
    }
    if (FIELD(s32, player, 0x5E4) != 0) {
        FIELD(s32, player, 0x13C8) = FIELD(s32, player, 0x5E4) - amount < -0x1DFF;
    }
    remaining = FIELD(s32, player, 0x5E4) - amount;
    if (remaining < 0) {
        remaining = 0;
    }
    FIELD(s32, player, 0x5E4) = remaining;
    roll = Nav_NextRandom();
    if ((roll % 2) == 1) {
        if (FIELD(s32, player, 0x5E4) > 0) {
            s32 id = func_80229C0C_de((struct Shared_ActorView *)player, 0x138D);
            if (func_8025E4D4_de(id) == 0) {
                Render_PlaySoundAtPosition((s16)id, FIELD(CVector3, player, 0x8), (s32)((char *)player + 8), -1);
            }
        }
    }
    FIELD(s32, player, 0x174) = FIELD(s32, player, 0x5E4);
    FIELD(s32, player, 0x45C) = FIELD(s32, player, 0x5E4);
    dead = FIELD(s32, player, 0x5E4) == 0;
    if (dead != 0) {
        if (wasDead == 0) {
            func_8021B468_de((struct Shared_ActorView *)player, attacker, arg3, kind);
        }
        intensity = 0xFF;
        delay = 0xC;
    } else {
        shifted = amount >> 8;
        intensity = shifted * 255 / 20;
        intensity = ((intensity > 0xFF ? 0xFF : intensity) < 0x80) ? 0x80 : (intensity > 0xFF ? 0xFF : intensity);
        delay = 0x1E;
        if (FIELD(void *, player, 0x5DC) != 0) {
            if (oldHealth > 0xF00 && FIELD(s32, player, 0x5E4) <= 0xF00 && D_80145088.settings.local == 0) {
                Camera_PostScreenMessage(&D_80145088, FIELD(void *, player, 0x5DC), (u8 *)D_800D2A90);
            }
        }
        if ((amount >> 8) != 0) {
            f32 strength;
            CVector3 zero;
            strength = ((f32)(amount >> 8) * D_800C22A8_us > D_800C22AC_us) ? D_800C22AC_us : (f32)(amount >> 8) * D_800C22A8_us;
            zero.x = 0;
            zero.y = 0;
            zero.z = 0;
            func_8028CE94_de(&D_8011FE88, (char *)FIELD(void *, player, 0x698) + 0x140, 0x11, zero, D_800C22B0_us, strength);
        }
    }
    if (dead == 0 && FIELD(s16, player, 0x650) != 0x12 && FIELD(void *, player, 0x5DC) != 0) {
        s32 hit;
        if (FIELD(s32, player, 0x16D4) == 0) {
            func_80239194_de(FIELD(void *, player, 0x5DC), intensity & 0xFF, delay);
        }
        hit = amount * 15;
        if (hit > 100) {
            hit = 100;
        }
        func_8022B11C_de(player, (u16)hit);
    }
    return;
}
#else
INCLUDE_ASM("span_1000", Render_ApplyPlayerDamage);
#endif

#include "COMMON/FIELD_VEC_B0.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"


extern s32 func_8022C460_de(void *arg0);
extern void func_8022B69C_de(void *arg0, f32 arg1, void *arg2);
extern void func_8022B550_de(void *arg0, f32 arg1, f32 arg2, void *arg3,
                          s32 arg4);
extern void func_8022B60C_de(void *arg0, f32 arg1, void *arg2);
extern void func_8022B7F8_de(void *arg0, void *arg1);

void func_8021C45C_de(void *arg0, void *unused1, s32 unused2, void *arg3) {
    Player *actor = arg0;
    Shared_Particle *event = arg3;
    CGameStatus *audio;
    u16 type;

    if (actor->health == 0) {
        return;
    }
    if (func_8022C460_de(actor) != 0) {
        return;
    }
    if (actor->damageCooldown > 0.0f) {
        return;
    }
    audio = &D_801462C8.counters;
    if (audio->enabled != 0 &&
#if defined(VERSION_DE) || defined(VERSION_EU_X)
        actor->profile->enabled != 0 &&
#endif
        actor->profile->character == 0xB &&
        audio->m_nBastilleShield > 0) {
        return;
    }
    if (actor->reactionFlags & 0x8000) {
        return;
    }

    type = event->inst.type;
    switch (type) {
    case 0x3FB:
    case 0x4CD:
        func_8022B69C_de(actor, 0.1f, event->owner);
        return;
    case 0x3FD:
    case 0x4CF:
        func_8022B69C_de(actor, 0.125f, event->owner);
        return;
    case 0x3FE:
    case 0x4D0:
        func_8022B69C_de(actor, 0.3f, event->owner);
        return;
    case 0x432:
    case 0x4E3:
        func_8022B550_de(actor, 80.0f, 2.0f, event->owner, 1);
        return;
    case 0x408:
    case 0x4E0:
        func_8022B60C_de(actor, 0.25f, event->owner);
        return;
    case 0x419:
    case 0x4D3:
        func_8022B7F8_de(actor, event->owner);
        return;
    case 0x129:
        actor->cooldown = 0;
        actor->pending = 0;
        if (!(actor->reactionFlags & 0x8000)) {
            if (actor->reactionOwner == 0) {
                actor->reactionOwner = event->owner;
            }
            Weapons_SetPlayerState(actor, actor, 0x26);
        }
        return;
    }
}
