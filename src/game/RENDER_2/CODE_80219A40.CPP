#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "RENDER_4/8026AC38.H"
#include "include_asm.h"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/WORLD.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "RENDER_2/OBJECTSTATE8E.H"
#include "COMMON/TRIPLE.H"

/* Actor, interaction and score views used to select reactions and record statistics. */

#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "RENDER_2/CODE_80219A40.H"
#include "RENDER_2/802192C0.H"

#include "COMMON/GAMEPLAY_REACTION_RULES.H"
#include "TYPES.H"
#include "RENDER_2/802192C0_11.H"
#include "RENDER_2/802192C0_7.H"
/* Selects and records a player's reaction to an interaction. */

/* Reaction thresholds are loaded from the cartridge's shared float table. */
void * Nav_FindSearchNode(char *, s32);
void Player_ApplyStun(void *, f32);
void func_80229FA0_de(void *, void *);
s32 Weapons_GetPlayerIndex(void *, unsigned int);
s32 Weapons_GetMaxHealth(void *);
int func_8022B178_de(void *);
int Cinema_IsSequenceActive(void);
void func_802830CC_de(void *, s32);
void * func_8028B2F8_de(Shared_World *, u16 *);
s32 func_802A01E8_de(void);






extern s32 D_8011D8D0;
extern s8 D_8013B364;
extern Shared_MatchRules D_801468A0[];

 












void func_80219A40_de(struct Shared_ReactionActor *attacker, void *arg1, struct Shared_ReactionInteraction *packet) {
    f32 facingSine;
    f32 sourceForwardProjection;
    f32 accumulatedStun;
    s32 *teamScoreSlot;
    s32 previousKillHistoryCursor;
    s32 healedHealth;
    s32 victimPlayerIndex;
    s32 killerPlayerIndex;
    s32 wasAlive;
    s32 statisticsValue; /* Integer result reused after each score value is stored. */
    s32 previousHealth;
    s32 nextKillHistoryCursor;
    s32 kind;
    s32 signedKillHistoryCursor;
    s32 hasSpecialSourceFlag;
    s32 clampedHealth;
    struct Shared_ReactionSource *damageSource;
    struct Shared_ReactionPlayer *damagedPlayer;
    struct Shared_ReactionPlayer *creditedPlayer;
    u16 *sourceHandle;
    s32 interactionType;
    u16 projectileType;
    s32 hitCounterIndex; 
    s32 specialKillerTeam;
    s32 killerTeam;
    s32 score_owner_6;
    s32 score_owner_8;
    s32 *first_score_slot; 
    s32 suicideTeam;
    u8 sourceKind;
    struct Shared_ReactionObjectKind *interactionObject;
    struct Shared_ReactionPlayer *projectileOwner;
    struct Shared_ReactionSource *reaction_source; 
    struct Shared_ReactionAttribution *attributionSource;
    struct Shared_ReactionPlayerIndex *attributed_actor;
    s32 projectile_present; 
    struct Shared_ReactionStatistics *victimKillStatistics;
    struct Shared_ReactionStatistics *killerTeamStatistics;
    struct Shared_ReactionFlags *sourceFlags;
    struct Shared_ReactionObjectStatistics *actorStatisticsNode;

    struct Shared_ReactionStatistics *suicideStatistics;
    struct Shared_ReactionStatistics *suicideScoreStatistics;
    struct Shared_ReactionStatistics *victimDeathStatistics;
    struct Shared_ReactionStatistics *specialKillStatistics;
    struct Shared_ReactionStatistics *specialScoreStatistics;
    struct Shared_ReactionStatistics *killerScoreStatistics;
    struct Shared_ReactionStatistics *specialHitStatistics;
    struct Shared_ReactionStatistics *countedDeathStatistics;

    creditedPlayer = 0;
    kind = -1;
    if ((Cinema_IsSequenceInWindow() == 0) && (Cinema_IsSequenceActive() == 0) && !(D_801462C8.flags & 1)) {
        damagedPlayer = attacker->unk1D8;
        sourceHandle = damagedPlayer->unk14;
        wasAlive = damagedPlayer->unk5E4 > 0;
        if (sourceHandle == 0) {
            goto flag_clear;
        }
        
        while (sourceHandle != 0) {
            sourceFlags = func_8028B2F8_de(&g_world, sourceHandle);
            hasSpecialSourceFlag = 0;
            if (sourceFlags == 0) {
                break;
            }
            hasSpecialSourceFlag = 1;
            if (sourceFlags->unk52 & 0x40) {
                goto flag_done;
            }
            break;
        }
flag_clear:
        hasSpecialSourceFlag = 0;
flag_done:

        if (hasSpecialSourceFlag != 0) {
            kind = 0x17;
        }
        if (damagedPlayer->unk650 == 0x20) {
            kind = 0x20;
        }
        if (packet != 0) {
            interactionObject = packet->unk0;
            if ((interactionObject != 0) && (interactionObject->unk0 == 2)) {
                interactionType = interactionObject->unk4;
                if (interactionType == 0x432) {
                    goto block_45;
                }
                if (interactionType < 0x433) {
                    if (interactionType == 0x405) {
                        goto block_33;
                    }
                    if (interactionType < 0x406) {
                        if ((interactionType == 0x402) || (interactionType == 0x404)) {
                            goto block_38;
                        }
                        goto block_47;
                    }
                    if (interactionType < 0x41E) {
                        if (interactionType < 0x41B) {
                            goto block_47;
                        }
                        goto block_early_return;
                    }
                    goto block_46;
                }
                if (interactionType < 0x4E0) {
                    if (interactionType >= 0x4DD) {
                        goto block_early_return;
                    }
                    if (interactionType == 0x43C) {
                        goto block_38;
                    }
                    if (interactionType == 0x4DA) {
                        goto block_33;
                    }
                    goto block_47;
                }
                if (interactionType == 0x4E3) {
                    goto block_45;
                }
                goto block_47;
block_early_return:
                if (damagedPlayer->unk5E4 > 0) {
                    Player_ApplyStun(damagedPlayer, 2.5f);
                }
                return;
block_33:
                if (damagedPlayer->unk5E4 > 0) {
                    accumulatedStun = damagedPlayer->unk11E0 + D_800C22D4_de[0];
                    damagedPlayer->unk11E0 = accumulatedStun < D_800C22D8_de ? D_800C22D8_de : accumulatedStun;

                }
                packet->unk4 = 0x100;
                goto block_46;
block_38:
                if (damagedPlayer->unk122C & 0x1000) {
                    previousHealth = damagedPlayer->unk5E4;
                    if (previousHealth <= 0) {
                        packet->unk4 = 0;
                    } else {
                        healedHealth = previousHealth + packet->unk4;
                        clampedHealth = Weapons_GetMaxHealth(damagedPlayer);
                        if (healedHealth < clampedHealth) {
                            clampedHealth = healedHealth;
                        }
                        damagedPlayer->unk5E4 = clampedHealth;
                        goto block_45;
                    }
                }
                goto block_47;
block_45:
                packet->unk4 = 0;
                goto block_46;
            } else {
block_46:
                goto block_47;
            }
        } else {
block_47:
            func_80229FA0_de(damagedPlayer, packet);
            Player_ApplyPlayerDamage(damagedPlayer, attacker, packet->unk4, packet->unkC, kind);

            damageSource = packet->unk0;
            if (damageSource != 0) {
                sourceKind = damageSource->unk0;
                if (sourceKind != 1) {
                    if (sourceKind == 2) {
                        projectileOwner = damageSource->unk12C;
                        reaction_source = damageSource;
                        if (projectileOwner != 0) {
                            if (projectileOwner->unk0 == 1) {
                                if (projectileOwner->unk100 & 0x300000) {
                                    creditedPlayer = projectileOwner;
                                } else if (projectileOwner->unkE4 == 0x40C) {
                                    creditedPlayer = projectileOwner->unk1D8;
                                }
                            }
                            projectileType = reaction_source->unk4;
                            if (((projectileType == 0x3EB) || (projectileType == 0x416)) && (wasAlive != 0) && (func_8022B178_de(damagedPlayer) != 0)) {
                                specialHitStatistics = (void *)creditedPlayer->unk5D8;
                                specialHitStatistics->special_hits = (u16) (specialHitStatistics->special_hits + 1);
                            }
                            facingSine = Math_Sinf(attacker->unk6C);
                            sourceForwardProjection = ((damagedPlayer->unk8 - reaction_source->unk8) * -facingSine) + ((damagedPlayer->unk10 - reaction_source->unk10) * -Math_Cosf(attacker->unk6C));
                            if (sourceForwardProjection < D_800C22DC_de) {

                                damagedPlayer->unk13C4 = 1;
                            } else if (sourceForwardProjection > D_800C22E0_de) {

                                damagedPlayer->unk13C4 = 2;
                            } else {
                                goto block_69;
                            }
                        }
                    }
                } else {
                    if (damageSource->unk100 & 0x300000) {
                        creditedPlayer = damageSource->unk1D8;
                    }
block_69:
                    damagedPlayer->unk13C4 = 0;
                }
            } else {
                creditedPlayer = damagedPlayer;
            }
            if (creditedPlayer != 0) {
                if (packet != 0) {
                    attributionSource = packet->unk0;
                    projectile_present = attributionSource != 0;
                    do { 
                      if (!projectile_present) { break; }
                      if (attributionSource->unk0 == 2) {
                        hitCounterIndex = attributionSource->unk4;
                        switch (hitCounterIndex) {
                            case 0x404:
                            case 0x40F:
                                goto block_88;
                            case 0x402:
                            case 0x427:
                                goto block_87;
                            default:
                                if (!(packet->unkC & 0x100000)) {
                                    hitCounterIndex = creditedPlayer->unk5D4;
                                    goto block_86;
                                }
                                goto block_87;
                        }
                    }
                    } while (0);
                    if ((attributionSource != 0) && (attributionSource->unk0 == 1) && (attributionSource->unk100 & 0x300000)) {
                        attributed_actor = attributionSource->unk1D8;
                        if (!(packet->unkC & 0x100000)) {
                            hitCounterIndex = attributed_actor->unk5D4;
block_86:
                            ++D_800FEAE0[hitCounterIndex];

                        }
                    }
                    goto block_87;
                }
block_87:
                if (creditedPlayer != 0) {
block_88:
                    if ((creditedPlayer != damagedPlayer) && (damagedPlayer->unk1450 != 0)) {
                        damagedPlayer->unk1454->unk328 = creditedPlayer;
                        damagedPlayer->unk1454->unk324 = 0x1F4;
                    }
                    if ((creditedPlayer != 0) && (damagedPlayer->unk5E4 == 0)) {
                        countedDeathStatistics = (void *)damagedPlayer->unk5D8;
                        if (countedDeathStatistics->counted == 0) {
                            countedDeathStatistics->counted = 1U;
                            killerPlayerIndex = Weapons_GetPlayerIndex(&D_80145040, (u32) creditedPlayer);
                            victimKillStatistics = (void *)damagedPlayer->unk5D8;
                            if ((victimKillStatistics->unk8F == 1) && ((((struct Shared_ReactionMatchState *)(&D_80145040))->unk18B4) != 0)) {
                                victimKillStatistics->kills_special[killerPlayerIndex]++;
                            } else {
                                damagedPlayer->unk5D8->kills_normal[killerPlayerIndex]++;
                            }
                            victimPlayerIndex = Weapons_GetPlayerIndex(&D_80145040, (u32) damagedPlayer);
                            if ((damagedPlayer->unk5D8->unk8F == 1) && ((((struct Shared_ReactionMatchState *)(&D_80145040))->unk18B4) != 0)) {
                                creditedPlayer->unk5D8->deaths_special[victimPlayerIndex]++;
                            } else {
                                creditedPlayer->unk5D8->deaths_normal[victimPlayerIndex]++;
                            }
                            Player_PostKillMessages(damagedPlayer, creditedPlayer, packet);
                            if (creditedPlayer != 0) {
                                previousKillHistoryCursor = creditedPlayer->unk1338;
                                nextKillHistoryCursor = previousKillHistoryCursor + 1;
                                signedKillHistoryCursor = nextKillHistoryCursor;
                                if (nextKillHistoryCursor < 0) {
                                    signedKillHistoryCursor = previousKillHistoryCursor + 8;
                                }
                                statisticsValue = nextKillHistoryCursor - ((signedKillHistoryCursor >> 3) * 8);
                                creditedPlayer->unk1338 = statisticsValue;
                                creditedPlayer->unk12CC[statisticsValue] = damagedPlayer;
                                creditedPlayer->unk12F4[creditedPlayer->unk1338] = 0xFF;
                            }
                            if (damagedPlayer != 0) {
                                damagedPlayer->unk12EC = creditedPlayer;
                                damagedPlayer->unk12F0 = (s32) (func_802A01E8_de() % 7);
                            }
                            if (killerPlayerIndex == victimPlayerIndex) {
                                suicideStatistics = (void *)damagedPlayer->unk5D8;
                                suicideStatistics->deaths_self = (u16) (suicideStatistics->deaths_self + 1);
                                suicideScoreStatistics = (void *)damagedPlayer->unk5D8;
                                statisticsValue = suicideScoreStatistics->score - 1;
                                suicideScoreStatistics->score = (u16) statisticsValue;
                                statisticsValue = D_801468C4;
                                if (statisticsValue != 0) {
                                    suicideTeam = damagedPlayer->unk5D8->unk92;
                                    
                                    if (suicideTeam >= 0) {
                                        if (suicideTeam < 5) {
                                            teamScoreSlot = &D_8014280C[suicideTeam];

                                            if (D_80146918 == 0) {
                                                if (D_801468F4 != 0) {

                                                } else {
                                                    goto block_134;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
                                victimDeathStatistics = (void *)damagedPlayer->unk5D8;
                                victimDeathStatistics->deaths_other = (u16) (victimDeathStatistics->deaths_other + 1);
                                actorStatisticsNode = Nav_FindSearchNode(&D_8013B364, damagedPlayer->unk1454->unk4);
                                actorStatisticsNode->unk38 = (s32) (actorStatisticsNode->unk38 + 1);
                                actorStatisticsNode = Nav_FindSearchNode(&D_8013B364, creditedPlayer->unk1454->unk4);
                                actorStatisticsNode->unk3C = (s32) (actorStatisticsNode->unk3C + 1);
                                if (damagedPlayer->unk5D8->unk8F == 1) {
                                    if (D_801468A0->countRule != 0) {
                                        specialKillStatistics = (void *)creditedPlayer->unk5D8;
                                        creditedPlayer->unk12C4 = damagedPlayer;
                                        specialKillStatistics->special_kills = (u16) (specialKillStatistics->special_kills + 1);
                                        specialScoreStatistics = (void *)creditedPlayer->unk5D8;
                                        statisticsValue = specialScoreStatistics->score + 1;
                                        specialScoreStatistics->score = (u16) statisticsValue;
                                        statisticsValue = D_801468C4;
                                        if (statisticsValue != 0) {
                                            specialKillerTeam = creditedPlayer->unk5D8->unk92;
                                            score_owner_6 = damagedPlayer->unk5D8->unk92;
                                            
                                            if (specialKillerTeam >= 0) {
                                                if (specialKillerTeam < 5) {
                                                    first_score_slot = &D_8014280C[specialKillerTeam];

                                                    teamScoreSlot = first_score_slot;
                                                    if (score_owner_6 != specialKillerTeam) {
                                                        do { 
                                                            *first_score_slot = *first_score_slot + 1;
                                                            goto reaction_statistics_done;
                                                        } while (0);
                                                    }
                                                }
                                            }
                                        }
                                    } else if (D_801468A0->squads != 0) {
                                        creditedPlayer->unk12C8 = damagedPlayer;
                                    } else {
                                        goto block_124;
                                    }
                                } else {
block_124:
                                    if (D_801468C4 != 0) {
                                        killerTeamStatistics = (void *)creditedPlayer->unk5D8;
                                        if (killerTeamStatistics->unk92 == damagedPlayer->unk5D8->unk92) {
                                            killerTeamStatistics->score = (u16) (killerTeamStatistics->score - 1);
                                        } else {
                                            killerTeamStatistics->score = (u16) (killerTeamStatistics->score + 1);
                                        }
                                    } else {
                                        killerScoreStatistics = (void *)creditedPlayer->unk5D8;
                                        killerScoreStatistics->score = (u16) (killerScoreStatistics->score + 1);
                                    }
                                    if (D_801468C4 != 0) {
                                        killerTeam = creditedPlayer->unk5D8->unk92;
                                        score_owner_8 = damagedPlayer->unk5D8->unk92;
                                        
                                        if (killerTeam >= 0) {
                                            if (killerTeam < 5) {
                                                teamScoreSlot = &D_8014280C[killerTeam];

                                                if (score_owner_8 != killerTeam) {
                                                    *teamScoreSlot = *teamScoreSlot + 1;
                                                } else {
block_134:
                                                    *teamScoreSlot = *teamScoreSlot - 1;
                                                }

                                            }
                                        }
                                    }
                                }
                            }
reaction_statistics_done:
                            Particle_RetireOwnedActors(&D_8011D8D0, (s32) damagedPlayer);
                            func_802830CC_de(&D_8011D8D0, (s32) damagedPlayer);
                        }
                    }
                }
            }
        }
    }
}

#include "COMMON/MODEL_RENDER.H"
#include "TYPES.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/GAMEPLAY_REACTION_RULES.H"
#include "COMMON/ITEMRECAT20V1.H"
extern Shared_MatchRules D_801468A0[];
extern s32 D_800D297C;
extern const f32 D_800C22E4_de, D_800C22E8_de, D_800C22EC_de, D_800C22F0_de;
extern WeaponInfo *D_800D052C[];
extern void Weapons_DrawTintedPlayer(LevelActor *, s32, Draw *);
extern void **func_8024BFD4_de(LevelActor *, s32);
extern void Cache_UnlockResource(s32, void *);
void Player_DrawPlayerBodyAndWeapon(LevelActor *actor, s32 arg1, Draw *context)
{
    PlayerCode80225D10 *player;
    void **resource;
    s32 temporaryFlag, model;

    player = actor->controller;
    if (0.0f < player->ghost) {
        temporaryFlag = 1;
        if (player->flags & 0x8000) temporaryFlag = 0;
        else player->flags |= 0x8000;
        D_800D15E4[0] = 0.0f;
        D_800D15E0 = 3;
        if (player->flags & 0x4000) {
            D_800D15E4[2] = 0.0f;
            D_800D15E4[1] = D_800C22E4_de;
        } else {
            D_800D15E4[1] = 0.0f;
            D_800D15E4[2] = D_800C22E8_de;
        }
        if (player->fixedAlpha) D_800D15E4[3] = D_800C22EC_de;
        else D_800D15E4[3] = (u8)player->camera->fadeState;
        D_800D15E4[4] = D_800C22F0_de;
        if (D_801468A0->countRule && player->controls->unk8F) actor->team = D_801468A0->teamColour;
        else actor->team = (u8)actor->definition->first;
        Geometry_DrawActorModelParts(context->model, player, actor->fieldB4, 1,
                       &actor->lighting[D_800D297C], 0, actor->field3);
        D_800D15E0 = 0;
        if (temporaryFlag) player->flags &= ~0x8000;
        if ((u32)(player->state - 0x11) < 2) return;
    if (player->state == 15) return;
    if (player->controls->unk8F && D_80145088.modes.tag) return;
    if (player->health == 0) return;
    if (player->kind == D_800CE47C) return;
    if (player->flags & 0x20) return;
    { s32 weaponModel = D_800D052C[player->selectedWeapon]->model;
    model = weaponModel - 0x4B3;
    if (player->selectedWeapon >= 16) model = weaponModel - 0x4B5; }
        goto weapon;
    } else {
        if (D_80145088.settings.local) {
            if (player->controls->unk8F && D_80145088.modes.tag && player->health == 0) return;
            if (D_80145088.settings.local && (player->hidden || player->kind == D_800C9228_de) &&
                player->health == 0) return;
        }
        if (player->flags & 0x20) Weapons_DrawTintedPlayer(actor, arg1, context);
        else {
            if (D_801468A0->countRule && player->controls->unk8F) actor->team = D_801468A0->teamColour;
            else actor->team = (u8)actor->definition->first;
            Geometry_DrawActorModelParts(context->model, player, actor->fieldB4, 1,
                           &actor->lighting[D_800D297C], 0, actor->field3);
            if (0.0f < player->opacity) {
                func_8026D4F0_de(context->model, player, actor->fieldB4, 1,
                    &actor->lighting[D_800D297C], 0, actor->field3, player->red,
                    player->green, player->blue, (s32)player->opacity & 255);
            }
        }
    }
    if ((u32)(player->state - 0x11) < 2) return;
    if (player->state == 15) return;
    if (player->controls->unk8F && D_80145088.modes.tag) return;
    if (player->health == 0) return;
    if (player->kind == D_800CE47C) return;
    if (player->flags & 0x20) return;
    model = D_800D052C[player->selectedWeapon]->model;
    model -= 0x4B3;
    if (player->selectedWeapon >= 16) model -= 2;
weapon:
    if (model >= 0) {
        resource = func_8024BFD4_de(actor, model);
        if (resource) {
            func_8026DA4C_de(resource, actor->fieldB4, 1,
                            &actor->lighting[D_800D297C], 0, actor->field3);
            Cache_UnlockResource(0, resource);
        }
    }
}
