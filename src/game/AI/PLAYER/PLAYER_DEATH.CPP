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
#include "RENDER/OBJECTSTATE8E.H"
#include "COMMON/RESULTS.H"
#include "SYSTEM/LIST.H"
#include "SYSTEM/LIST.H"
#include "WEAPONS/ACTOR_REQUESTACTORSTATE.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"
#include "RENDER/PLAYER_SPAWN_PLACEMENT.H"
/* Apply player transitions, regional control gates, and localized linked-actor notifications. */






extern const Shared_HeightBonuses g_playerDeathHeightOffsets;
extern const f32 g_playerDeathMotionCenter;
extern const f32 g_playerDeathMovingSpeed;
extern s32 D_800C9228_de[2];



                                                  /* size = 0x18 */




void *Portal_GetGraphPoint(void *, s32);
s32 Portal_FindNearestPointIndex(void *, void *);
s32 Player_SetPlayerState(void *, void *, s32);
#ifndef NON_MATCHING
void *Camera_PostScreenMessage(void *, void *, u8 *);
#endif
void *Gsky_PostScaledScreenMessage(void *, void *, void *, f32); CQuatern func_8024796C_de(char *);
s32 func_8024BE80_de(void *);
void InstHdr_CopyActorPositionAndModel(void *, Triple, void *, s32 *, s32, s32); /* extern */
s32 SoundElement_PlaySoundAtPosition(s16, CVector3, s32, s32); /* extern */
void Control_SetProfileMode(void *, s32);
void Link_DispatchActorLinks(void *, s32, void *);
void Link_DispatchObjectLinks(s32, s32, void *);
s32 Particle_SpawnEffectGroup(void *, void *, void *, s32 *, s32, s32, CVector3, CQuatern, CVector3, CVector3 *, s32, s32); /* extern */
void Particle_ReleaseOwnerListTwoEffects(void *, s32);
s32 Scene_FindModelIdIndex(struct Shared_World *, s32);
void Scene_SetLevelRecordStateBit(void *, void *, s32);
void *SetN64_SpawnModelEffect(void *, s32 *, s32, CVector3, CVector3, s32, f32); /* extern */
struct ListNode80290528;
void SetN64_RecycleGlobalEffectNode(struct ListNode80290528 *);
s32 XPlus_NextRandomInteger(void);
s32 Player_ResetPlayerForRound(void *, s8, s32);         /* extern */
void Player_PlacePlayerForRound(void *);
void Player_ReleaseObjectHandles(void *);


extern s32 D_8011D8D0;


extern s32 D_8013B364;
extern struct Shared_GlobalRuntimeState D_80145060;










 /* unable to generate initializer: non-zero padding; const */








void func_8021B468_de(struct Shared_ActorView *player, void *attacker, s32 damageFlags, s32 state) {
    CVector3 spawnPosition;
    struct CVector3_t spawnVector;
    struct CVector3_t motionVector;
    struct Shared_GlobalPlayers *playersGlobal;
    struct Shared_GlobalFlowState *flow;
    struct Shared_GlobalFlowState *laterFlow;
    struct GameLocalizationState *localization;
    s32 *messageContext;
    CQuatern motionOutput;
    s32 spawnProbeResult;
    
    s8 *settingsBase;
    struct Shared_PlayerSettingsRecord *playerSettingsRecord;
    s16 firstAmmoCount;
    s16 secondAmmoCount;
    s16 thirdAmmoCount;
    s32 previousAction;
    s16 deathSound;
    s16 var_a0_5;
    void *resetMessageTarget;
    void *releaseMessageTarget;
    s32 deathEffectFrame;
    void *spawnedAmmoPickup;
    s32 temp_v0_12;
    s32 firstAmmoRandom;
    s32 firstAmmoQuotient;
    s32 secondAmmoRandom;
    s32 secondAmmoQuotient;
    s32 thirdAmmoRandom;
    s32 thirdAmmoQuotient;
    s32 temp_v1_4;
    s32 motionRandomX;
    s32 motionRandomY;
    s32 motionRandomZ;
    s32 firstAmmoDrop;
    s32 secondAmmoDrop;
    s32 thirdAmmoDrop;
    s32 var_a2;
    s32 ammoPickupType;
    s32 deathEffectFlags;
    s32 i;
    
    s32 loopLimit;
    s32 hasAmmoDrop;
    s32 playerArrayOffset;
    s32 signedMotionRandomX;
    s32 signedMotionRandomY;
    s32 signedMotionRandomZ;
    s32 movingAtDeath;
    struct Shared_struct_D_800D34C0_0x18 *thirdAmmoDropRecord;
    struct Shared_struct_D_800D34C0_0x18 *firstAmmoDropRecord;
    struct Shared_struct_D_800D34C0_0x18 *secondAmmoDropRecord;
    u16 ammoDropActorKind;
    u16 deathEffectActorKind;
    u32 ammoPickupMode;
    void *retiredAmmoPickup;
    void *roundPlayer;
    void *nearestSpawnPoint;
    void *roundPlayerModel;
    void *existingAmmoPickup;
    void *resetMessageActor;
    void *childActor;

    Control_SetProfileMode(((struct Shared_ActorView *)player)->controller, 0);
    if (((struct Shared_ActorView *)player)->action == 0x27) {
        Player_SetPlayerState(player, attacker, 2);
    }
    ((struct Shared_ActorView *)player)->field1218 = 0;
    Link_DispatchActorLinks(attacker, 1, attacker);
    Player_ReleaseObjectHandles(player);
    func_8022B530_de((s32)player);
    ((struct Shared_ActorView *)player)->stun = 0;
    ((struct Shared_ActorView *)player)->marker.time = 0;
    Particle_ReleaseOwnerListTwoEffects(&D_8011D8D0, (s32)player);
    flow = &D_80145060.flow;
    if ((flow->active != 0)
        && gameplayTransitionEnabled(player->controls->germanActive)
        && (i = 0, (((struct Shared_ActorView *)player)->controls->mode == 0xE))) {
        flow->count = (s32) (flow->count + 1);
        playersGlobal = (struct Shared_GlobalPlayers *)&D_80145040;
        if (playersGlobal->count > 0) {
            settingsBase = (s8 *)&g_playerSettings;
            playerSettingsRecord = (struct Shared_PlayerSettingsRecord *)settingsBase;
            playerArrayOffset = 0;
settings_loop:
            do {
                roundPlayer = playersGlobal->players + playerArrayOffset;
                if (playerSettingsRecord->active != 0) {
                    if (((struct Shared_PlayerSettingsView *)settingsBase)->state == 1) {
                    ((struct Shared_ActorView *)roundPlayer)->actorState = (s32) ((struct Shared_PlayerSettingsView *)settingsBase)->state;
                    Player_ResetPlayerForRound(roundPlayer, playerSettingsRecord->character, 1);
                    roundPlayerModel = ((struct Shared_ActorView *)roundPlayer)->model;
                    ((struct Shared_ModelView *)roundPlayerModel)->flags = (s32) (((struct Shared_ModelView *)roundPlayerModel)->flags & ~4);
                    Actor_RequestActorState(&((struct Shared_ActorView *)roundPlayer)->weapon, &((struct Shared_ActorView *)roundPlayer)->weapon.behaviorFlags, 2);
                    Player_PlacePlayerAtSpawnPoint(roundPlayer, ((struct Shared_PlayerSettingsView *)settingsBase)->effect, 0, 0);
                    func_80255ED8_de(playersGlobal->controller, roundPlayer);
                    func_80255CB8_de(&playersGlobal->effects, roundPlayer);
                    } else if (((struct Shared_PlayerSettingsView *)settingsBase)->state < 3) {
                        Player_PlacePlayerForRound(roundPlayer);
                    }
                }
block_13:
                do {
                    playerSettingsRecord++;
                } while (0);
                loopLimit = playersGlobal->count;
                do {
                    i += 1;
                } while (0);
                playerArrayOffset += 0x16E8;
                if (i < loopLimit) goto settings_loop;
            } while (0);
        }
        if (D_801462C8.counters.m_nTalsetLives < 3) {
            ((struct Shared_ActorView *)player)->special = 0;
            Player_SetPlayerState(player, attacker, 0x2E);
            return;
        } else {
            goto block_17;
        }
    } else {
block_17:
        if (D_80145088.settings.local != 0) {
            if ((((struct Shared_ActorView *)player)->ammo[0] > 0) || (((struct Shared_ActorView *)player)->ammo[1] > 0) || (((struct Shared_ActorView *)player)->ammo[2] > 0)) {
                ammoPickupMode = ((struct Shared_ActorView *)player)->mode;
                hasAmmoDrop = 0;
                switch (ammoPickupMode) {
case 0:
default:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBD9;
                    break;
case 1:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBDB;
                    break;
case 2:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBDD;
                    break;
case 3:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBDF;
                    break;
case 4:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE1;
                    break;
case 5:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE3;
                    break;
case 6:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE5;
                    break;
case 7:
                    ammoPickupType = ((struct Shared_ActorView *)player)->projectileIndex + 0xBE7;
                    break;
                }
                Scene_FindModelIdIndex(&g_world, ammoPickupType);
                existingAmmoPickup = ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex];
                if (existingAmmoPickup != 0) {
                    ((struct Shared_ProjectileView *)existingAmmoPickup)->flags = (u16) (((struct Shared_ProjectileView *)existingAmmoPickup)->flags | 1);
                    retiredAmmoPickup = ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex];
                    if (((struct Shared_ProjectileView *)retiredAmmoPickup)->flags & 8) {
                        SetN64_RecycleGlobalEffectNode(retiredAmmoPickup);
                    } else {
                        Scene_SetLevelRecordStateBit(&g_world, retiredAmmoPickup, 1);
                        Link_DispatchObjectLinks(((struct Shared_ProjectileView *)((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex])->source, 0x400, player);
                    }
                }
                ammoDropActorKind = ((struct Shared_ActorView *)player)->kind;
                if (ammoDropActorKind == D_800CE474[0]) {
                    hasAmmoDrop = 0;
                } else if (ammoDropActorKind == D_800CE474[1]) {
                    hasAmmoDrop = 0;
                } else {
                    switch (XPlus_NextRandomInteger() % 3) {            /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        firstAmmoCount = ((struct Shared_ActorView *)player)->ammo[0];
                        firstAmmoDrop = 0;
                        if (firstAmmoCount != 0) {
                            firstAmmoRandom = XPlus_NextRandomInteger();
                            firstAmmoQuotient = firstAmmoRandom / firstAmmoCount;
                            if (firstAmmoCount == 0) {

                            }
                            if ((firstAmmoCount == -1) && (firstAmmoQuotient == 0x80000000)) {

                            }
                            firstAmmoDrop = firstAmmoRandom % firstAmmoCount;
                        }
                        if (firstAmmoDrop != 0) {
                            hasAmmoDrop = 1;
                            firstAmmoDropRecord = &g_pickupAmmoDefinitions[((struct Shared_ActorView *)player)->projectileBase + ((struct Shared_ActorView *)player)->projectileIndex];
                            firstAmmoDropRecord->unkC = (s16) firstAmmoDrop;
                            firstAmmoDropRecord->unkE = 0;
                            firstAmmoDropRecord->unk10 = 0;
                        }
                        break;
                    case 1:                         /* switch 2 */
                        secondAmmoCount = ((struct Shared_ActorView *)player)->ammo[1];
                        secondAmmoDrop = 0;
                        if (secondAmmoCount != 0) {
                            secondAmmoRandom = XPlus_NextRandomInteger();
                            secondAmmoQuotient = secondAmmoRandom / secondAmmoCount;
                            if (secondAmmoCount == 0) {

                            }
                            if ((secondAmmoCount == -1) && (secondAmmoQuotient == 0x80000000)) {

                            }
                            secondAmmoDrop = secondAmmoRandom % secondAmmoCount;
                        }
                        if (secondAmmoDrop != 0) {
                            hasAmmoDrop = 1;
                            secondAmmoDropRecord = &g_pickupAmmoDefinitions[((struct Shared_ActorView *)player)->projectileBase + ((struct Shared_ActorView *)player)->projectileIndex];
                            secondAmmoDropRecord->unkE = (s16) secondAmmoDrop;
                            secondAmmoDropRecord->unkC = 0;
                            secondAmmoDropRecord->unk10 = 0;
                        }
                        break;
                    case 2:                         /* switch 2 */
                        thirdAmmoCount = ((struct Shared_ActorView *)player)->ammo[2];
                        thirdAmmoDrop = 0;
                        if (thirdAmmoCount != 0) {
                            thirdAmmoRandom = XPlus_NextRandomInteger();
                            thirdAmmoQuotient = thirdAmmoRandom / thirdAmmoCount;
                            if (thirdAmmoCount == 0) {

                            }
                            if ((thirdAmmoCount == -1) && (thirdAmmoQuotient == 0x80000000)) {

                            }
                            thirdAmmoDrop = thirdAmmoRandom % thirdAmmoCount;
                        }
                        if (thirdAmmoDrop != 0) {
                            hasAmmoDrop = 1;
                            thirdAmmoDropRecord = &g_pickupAmmoDefinitions[((struct Shared_ActorView *)player)->projectileBase + ((struct Shared_ActorView *)player)->projectileIndex];
                            thirdAmmoDropRecord->unk10 = (s16) thirdAmmoDrop;
                            thirdAmmoDropRecord->unkC = 0;
                            thirdAmmoDropRecord->unkE = 0;
                        }
                        break;
                    }
                }
                if (hasAmmoDrop != 0) {
                    nearestSpawnPoint = Portal_GetGraphPoint(&D_8013B364, Portal_FindNearestPointIndex(&D_8013B364, &player->position.vector));
                    InstHdr_CopyActorPositionAndModel(player, player->position.words, &spawnPosition, &spawnProbeResult, 0, 0);
                    if (nearestSpawnPoint != 0) {
                        spawnPosition = *(CVector3 *)nearestSpawnPoint;
                    }
                    spawnVector.x = 0;
                    spawnVector.y = 0.0f;
                    spawnVector.z = 0;
                    spawnedAmmoPickup = SetN64_SpawnModelEffect(&D_80131600, 0, ammoPickupType, spawnVector, spawnPosition, 0, 0);
                    if (spawnedAmmoPickup != 0) {
                        spawnPosition.y += g_playerDeathHeightOffsets.spawn;
                        ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex] = (void *)spawnedAmmoPickup;
                    }
                } else {
                    ((struct Shared_ActorView *)player)->projectiles[((struct Shared_ActorView *)player)->projectileIndex] = 0;
                }
                ((struct Shared_ActorView *)player)->projectileIndex = (s32) (((struct Shared_ActorView *)player)->projectileIndex == 0);
            }
            if ((((struct Shared_ActorView *)player)->controls->transientFlag != 0) && (laterFlow = &D_80145060.flow, laterFlow->transition != 0)) {
                if (D_800F3D08 != 0) {
                    Actor_RequestActorState(D_800F3D08, ((struct Shared_SpecialObjectView *)D_800F3D08)->segment, 1);
                    ((struct Shared_SpecialObjectView *)D_800F3D08)->reset = 0;
                    laterFlow->reset = 0;
                    SoundElement_PlayFlatSound(0x2D0);
                    resetMessageActor = D_80145060.actorList;
                    if (resetMessageActor != 0) {
                        messageContext = &D_80145060.messageContext;
                        localization = &D_80145060.localization;
                        do {
                            resetMessageTarget = ((struct Shared_ActorView *)resetMessageActor)->message;
                            if (resetMessageTarget != 0) {
                                Camera_PostScreenMessage(gameplayMessageContext(messageContext), resetMessageTarget, gameplayResetMessage(localization->language));
                            }
                            resetMessageActor = ((struct Shared_ActorView *)resetMessageActor)->next;
                        } while (resetMessageActor != 0);
                    }
                }
                ((struct Shared_ActorView *)player)->controls->transientFlag = 0U;
                ((struct Shared_ActorView *)player)->controls->resetFlag = 0;
            }
            childActor = D_80145060.actorList;
            if (childActor != 0) {
                messageContext = &D_80145060.messageContext;
                localization = &D_80145060.localization;
                do {
                    if ((childActor != player) && (((struct Shared_ActorView *)childActor)->parent == player)) {
                        releaseMessageTarget = ((struct Shared_ActorView *)childActor)->message;
                        ((struct Shared_ActorView *)childActor)->pending = 0;
                        ((struct Shared_ActorView *)childActor)->parent = 0;
                        if (releaseMessageTarget != 0) {
                            Gsky_PostScaledScreenMessage(gameplayMessageContext(messageContext), releaseMessageTarget, gameplayReleaseMessage(localization->language), 1.0f);
                        }
                    }
                    childActor = ((struct Shared_ActorView *)childActor)->next;
                } while (childActor != 0);
            }
        }
        ((struct Shared_ActorView *)player)->field1238 = -1;
        ((struct Shared_ActorView *)player)->field1230 = 0;
        ((struct Shared_ActorView *)player)->field1234 = 0;
        ((struct Shared_ActorView *)player)->field1240 = 0;
        ((struct Shared_ActorView *)player)->field122C = (s32) (((struct Shared_ActorView *)player)->field122C & 0xFFFF0000);
        if (damageFlags & 0x4000) {
            if ((u32) (((struct Shared_ActorView *)player)->state - 0x11) < 2U) {
                ((struct Shared_ActorView *)player)->special = 1;
            }
        }
        if (((struct Shared_ActorView *)player)->special == 0) {
            deathSound = 0x2BC;
            if (state != 0x1F) {
                deathSound = func_80229C0C_de(player, 0x1397);
            }
            SoundElement_PlaySoundAtPosition(deathSound, player->position.vector, (s32)&player->position.vector, -1);
        } else {
            SoundElement_PlaySoundAtPosition(0x9FB, player->position.vector, (s32)&player->position.vector, -1);
        }
        SoundElement_PlayFlatSound(0x212);
        if ((((struct Shared_ActorView *)player)->special != 0) || (deathEffectActorKind = ((struct Shared_ActorView *)player)->kind, (deathEffectActorKind == D_800C9228_de[0])) || (deathEffectActorKind == D_800C9228_de[1])) {
            spawnVector.x = player->position.vector.x;
            spawnVector.y = player->position.vector.y + g_playerDeathHeightOffsets.projectile;
            deathEffectFlags = 1;
            spawnVector.z = player->position.vector.z;
            signedMotionRandomX = XPlus_NextRandomInteger();
            motionRandomX = signedMotionRandomX;
            if (motionRandomX < 0) {
                signedMotionRandomX = motionRandomX + 0x3FF;
            }
            motionVector.x = (f32) (motionRandomX - ((signedMotionRandomX >> 0xA) << 0xA)) - g_playerDeathMotionCenter;
            signedMotionRandomY = XPlus_NextRandomInteger();
            motionRandomY = signedMotionRandomY;
            if (motionRandomY < 0) {
                signedMotionRandomY = motionRandomY + 0x3FF;
            }
            motionVector.y = (f32) (motionRandomY - ((signedMotionRandomY >> 0xA) << 0xA)) - g_playerDeathMotionCenter;
            signedMotionRandomZ = XPlus_NextRandomInteger();
            motionRandomZ = signedMotionRandomZ;
            if (motionRandomZ < 0) {
                signedMotionRandomZ = motionRandomZ + 0x3FF;
            }
            motionVector.z = (f32) (motionRandomZ - ((signedMotionRandomZ >> 0xA) << 0xA)) - g_playerDeathMotionCenter;
            motionOutput = func_8024796C_de((char *)player);
            deathEffectFrame = ((struct Shared_ActorView *)player)->frameValue;
            if (func_8024BE80_de(player) == 5) {
                deathEffectFlags = 3;
            }
            Particle_SpawnEffectGroup(&D_8011D8D0, player, player, 0, deathEffectFrame, 0x64, motionVector, motionOutput, spawnVector, 0, -1, deathEffectFlags);
        }
        if (state != -1) {
            Player_SetPlayerState(player, attacker, state);
            return;
        }
        if (((struct Shared_ActorView *)player)->state != 0x11) {
            if (((struct Shared_ActorView *)player)->action == 0xA && (damageFlags & 0x4000)) {
                Player_SetPlayerState(player, attacker, 0x2A);
                return;
            }
            if (damageFlags & 0x4000) {
                Player_SetPlayerState(player, attacker, 0x29);
                return;
            }
        }
        movingAtDeath = 1;
        if (!(((struct Shared_ActorView *)player)->speed > g_playerDeathMovingSpeed)) {
            movingAtDeath = 0;
        }
        if (movingAtDeath != 0) {
            Player_SetPlayerState(player, attacker, 0x1C);
            return;
        }
        previousAction = ((struct Shared_ActorView *)player)->action;
        if ((previousAction ^ 0xF) == 0) {
            Player_SetPlayerState(player, attacker, 0x21);
            return;
        }
        if (previousAction == 9) {
            Player_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (previousAction == 10) {
            Player_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (previousAction == 11) {
            Player_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (previousAction == 12) {
            Player_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (damageFlags & 0x1000) {
            Player_SetPlayerState(player, attacker, 0x1F);
            return;
        }
        if (damageFlags & 0x200) {
            Player_SetPlayerState(player, attacker, 0x19);
            return;
        }
        if ((((struct Shared_ActorView *)player)->state != 0x11) && (((struct Shared_ActorView *)player)->specialState == 1)) {
            Player_SetPlayerState(player, attacker, 0x1E);
            return;
        }
        if (((struct Shared_ActorView *)player)->specialState == 2) {
            Player_SetPlayerState(player, attacker, 0x1D);
            return;
        }
        Player_SetPlayerState(player, attacker, 0x16);
        return;
    }
}

#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C22A8_us, D_800C22AC_us;
extern s32 D_800D2A90;
extern char D_801468A0[];
extern s32 func_8022C460_de(void *);
extern s32 Player_GetMaxHealth(void *);
extern void CScene_StartEventClips(void *, void *, s32, CVector3, f32, f32);
extern void Gsky_SetDamageEffect(void *, s32, s32);
extern void func_8022B11C_de(void *, u16);
/* Applies damage to a player: ignored while the game is paused, the player is protected or the damage
 * source is not allowed; scales the amount by one fifth with armour (0x80C); when the health stays above
 * zero and drops through half of the maximum it respawns the weapon (Player_PlacePlayerAtSpawnPoint); lowers the health
 * (with a flash sound at random), starts the knock-back and the hit effect scaled by the damage, and on death
 * reports the kill through func_8021B468_de. */
/* Exact for us and us-rev1; de/eu/eu-x add extra checks (0x1450, 0x94) and keep their asm. */
void Player_ApplyPlayerDamage(void *player, void *attacker, s32 amount, s32 damageFlags, s32 kind) {
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
    if (Cinema_IsSequenceActive() != 0 || func_8022C460_de(player) != 0 || g_world.frozen != 0) {
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
        step = Player_GetMaxHealth(player);
        found = 0;
        for (threshold = 2; threshold < 5; threshold++) {
            step = step - step / 2;
            if (step < FIELD(s32, player, 0x5E4) && health < step && health > 0) {
                found = 1;
                break;
            }
        }
        if (found != 0) {
            Player_PlacePlayerAtSpawnPoint(player, FIELD(s32, player, 0x5EC), 0, 1);
        }
    }
#if defined(VERSION_DE) || defined(VERSION_EU_X)
    if (FIELD(s32, player, 0x1450) != 0 && FIELD(s32, state = D_801468A0, 0x98) != 0 &&
#else
    state = D_801468A0;
    if (FIELD(s32, state, 0x98) != 0 &&
#endif
#if defined(VERSION_DE) || defined(VERSION_EU_X)
        FIELD(u8, FIELD(void *, player, 0x5D8), 0x94) != 0 &&
#endif
        FIELD(s8, FIELD(void *, player, 0x5D8), 0x80) == 0xB && FIELD(s32, state, 0xA0) > 0) {
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
            Player_SetPlayerState(player, player, 0x2D);
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
    roll = Graphu64_NextRandom();
    if ((roll % 2) == 1) {
        if (FIELD(s32, player, 0x5E4) > 0) {
            s32 id = func_80229C0C_de((struct Shared_ActorView *)player, 0x138D);
            if (SoundElement_HasActiveOrPendingSound(id) == 0) {
                SoundElement_PlaySoundAtPosition((s16)id, FIELD(CVector3, player, 0x8), (s32)((char *)player + 8), -1);
            }
        }
    }
    FIELD(s32, player, 0x174) = FIELD(s32, player, 0x5E4);
    FIELD(s32, player, 0x45C) = FIELD(s32, player, 0x5E4);
    dead = FIELD(s32, player, 0x5E4) == 0;
    if (dead != 0) {
        if (wasDead == 0) {
            func_8021B468_de((struct Shared_ActorView *)player, attacker, damageFlags, kind);
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
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                Camera_PostScreenMessage(&D_80145088, FIELD(void *, player, 0x5DC), ((u8 **)&D_800D2A90)[*((u8 *)&D_80145088.settings.local + 0x564)]);
#else
                Camera_PostScreenMessage(&D_80145088, FIELD(void *, player, 0x5DC), (u8 *)D_800D2A90);
#endif
            }
        }
        if ((amount >> 8) != 0) {
            f32 strength;
            CVector3 zero;
            strength = ((f32)(amount >> 8) * D_800C22A8_us > D_800C22AC_us) ? D_800C22AC_us : (f32)(amount >> 8) * D_800C22A8_us;
            zero.x = 0;
            zero.y = 0;
            zero.z = 0;
            CScene_StartEventClips(&g_world, (char *)FIELD(void *, player, 0x698) + 0x140, 0x11, zero, D_800C22B0_us, strength);
        }
    }
    if (dead == 0 && FIELD(s16, player, 0x650) != 0x12 && FIELD(void *, player, 0x5DC) != 0) {
        s32 hit;
        if (FIELD(s32, player, 0x16D4) == 0) {
            Gsky_SetDamageEffect(FIELD(void *, player, 0x5DC), intensity & 0xFF, delay);
        }
        hit = amount * 15;
        if (hit > 100) {
            hit = 100;
        }
        func_8022B11C_de(player, (u16)hit);
    }
    return;
}

#include "COMMON/FIELD_VEC_B0.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"


extern s32 func_8022C460_de(void *actorObject);
extern void Player_DrainReserveAndDamage(void *actor, f32 amount, void *damageSource);
extern void func_8022B550_de(void *obj, f32 target, f32 rate, void *kind,
                          s32 tag);
extern void func_8022B60C_de(void *actor, f32 amount, void *source);
extern void Player_StartSourceEffect(void *actor, void *effectSource);

void func_8021C45C_de(void *playerObject, void *unused1, s32 unused2, void *projectileEvent) {
    Player *actor = playerObject;
    Shared_Particle *event = projectileEvent;
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
        Player_DrainReserveAndDamage(actor, 0.1f, event->owner);
        return;
    case 0x3FD:
    case 0x4CF:
        Player_DrainReserveAndDamage(actor, 0.125f, event->owner);
        return;
    case 0x3FE:
    case 0x4D0:
        Player_DrainReserveAndDamage(actor, 0.3f, event->owner);
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
        Player_StartSourceEffect(actor, event->owner);
        return;
    case 0x129:
        actor->cooldown = 0;
        actor->pending = 0;
        if (!(actor->reactionFlags & 0x8000)) {
            if (actor->reactionOwner == 0) {
                actor->reactionOwner = event->owner;
            }
            Player_SetPlayerState(actor, actor, 0x26);
        }
        return;
    }
}
