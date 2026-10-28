#include "AI/SHARED_PICKUPGOALNODE.H"
#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "RENDER/OBJECTSTATE8E.H"
#include "COMMON/OBJECTSTATE18.H"
#include "TYPES.H"
#include "gbi.h"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/EXTERNS_15.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "particle/80271B18_3.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"
#include "RENDER/802192C0.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "RENDER/8026AC38.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "RENDER/CODE_80219A40.H"
#include "COMMON/GAMEPLAY_REACTION_RULES.H"
#include "RENDER/802192C0_7.H"
#include "COMMON/MODEL_RENDER.H"
#include "COMMON/OBJRECV5.H"
#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "RENDER/802192C0_3.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "FX/802631D0.H"
#include "ACHIEVE/80424E30_3.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "AI/PLAYERAI_7.H"

/* 802192C0.CPP */
/* Steps an animation cursor one frame: looks up the clip in D_8011FE88, keeps the previous frame,
   and moves forward in states 1 and 2 or backward in states 3 and 4; at either end a looping clip
   (mode 1) wraps and a ping-pong clip (mode 0) reverses direction. */

extern Clip *Scene_GetPlatformRoute(char *, s32);

void func_802192C0_de(Cursor *cursor) {
    Clip *clip;
    s32 frames;
    s32 state;

    clip = Scene_GetPlatformRoute(&g_world, cursor->clip);
    frames = clip->frames;
    state = cursor->state;
    cursor->previous = cursor->frame;
    switch (state) {
    case 1:
    case 2:
        {
            cursor->state = 1;
            if (++cursor->frame == frames) {
                switch (clip->mode) {
                case 1:
                    cursor->frame = 0;
                    break;
                case 0:
                    cursor->frame = frames - 2;
                    cursor->state = 3;
                    break;
                }
            }
        }
        break;
    case 3:
    case 4:
        {
            cursor->state = 3;
            if (--cursor->frame < 0) {
                switch (clip->mode) {
                case 0:
                    cursor->frame = 1;
                    cursor->state = 1;
                    break;
                case 1:
                    cursor->frame = frames - 1;
                    break;
                }
            }
        }
    }
}

extern s16 Scene_FindNearestRouteFrame(char *arg0);

void func_802193C8_de(Struct802193C8 *cursorState, s8 initialState) {
    cursorState->field0 = 1;
    cursorState->field1 = initialState;
    cursorState->field2 = Scene_FindNearestRouteFrame(&g_world);
    cursorState->field4 = 0;
}

extern void *Scene_GetPlatformRoutePoint(char *a, unsigned char b, short c);

ApproachLocation *func_80219408_de(Cursor *cursor) {
    return Scene_GetPlatformRoutePoint(&g_world, cursor->clip, cursor->frame);
}

void *func_80219434_de(Cursor *cursor) {
    return Scene_GetPlatformRoutePoint(&g_world, cursor->clip, cursor->previous);
}

/** Initialize the compact state record to its default values. */
void func_80219460_de(CompactAnimationState *record) {
    record->active = 1;
    record->state = 0;
    record->cursor = 0;
    record->flags = 0;
    record->clip = -1;
}

void func_80219480_de(void *effect, void *player) {
    char pad[0x10];
}

extern void SetN64_ClearDepthRect(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);
extern void TranslateMatrix(char *object, f32 x, f32 y, f32 z);
extern void SwapMatrixUpForward(void *object);
extern void CopyMatrix(f32 *arg0, f32 *arg1);
extern void Graphu64_ScaleMatrixWorld(void *arg0, s32 arg1, f32 arg2, f32 arg3);
extern void Graphu64_ConvertMatrixToFixed(void *arg0, void *arg1);
extern void Geometry_QueueDirectModel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_80219490_de(char *object, char *camera) {
    f32 first[16];
    f32 second[16];
    s32 output[4];
    Gfx *command;
    f32 x;
    f32 y;
    f32 z;
    f32 w;
    char *matrix;

    Geometry_InvalidateMaterialKeys();
    if (((AnimationSprite *)(object))->model == 0 || ((AnimationSprite *)(object))->active == 0) {
        return;
    }

    Geometry_SetColorDither(0xC0);
    Geometry_SetPrimitiveAlphaOverride(1, 0x20);

    command = g_displayListCursor++;
    gDPSetTexturePersp(command, G_TP_PERSP);
    command = g_displayListCursor++;
    gDPSetTextureFilter(command, G_TF_BILERP);
    Geometry_BeginModelBatch();

    x = ((GameplayCamera *)(camera))->viewLeft;
    y = ((GameplayCamera *)(camera))->viewTop;
    z = ((GameplayCamera *)(camera))->viewHeight + y;
    w = ((GameplayCamera *)(camera))->viewWidth + x;
    SetN64_ClearDepthRect(&D_8011FAC0, (s32)x, (s32)w, (s32)y, (s32)z, 0);

    Graphu64_BuildScaleMatrix(first, ((AnimationSprite *)(object))->scaleX,
                   ((AnimationSprite *)(object))->scaleY, ((AnimationSprite *)(object))->scaleZ);
    YawMatrix(first, ((AnimationSprite *)(object))->yaw);
    PitchMatrix(first, ((AnimationSprite *)(object))->pitch);
    TranslateMatrix((char *)first, ((AnimationSprite *)(object))->position.x,
                   ((AnimationSprite *)(object))->position.y, ((AnimationSprite *)(object))->position.z);
    SwapMatrixUpForward(first);

    matrix = (char *)second;
    CopyMatrix(second, first);
    if (D_800E28D8 == 2) {
        Graphu64_ScaleMatrixWorld(matrix, D_800C94E8_de, D_800C22D0_de, D_800C22D0_de);
    }
    {
        s32 offset = (D_800D297C << 6) + 0x10;
        Graphu64_ConvertMatrixToFixed(matrix, object + offset);
    }
    Graphu64_TransformPoint(first, object + 0xA8, output);
    {
        s32 offset = (D_800D297C << 6) + 0x10;
        Geometry_QueueDirectModel(((AnimationSprite *)(object))->model, (s32)(object + offset),
                       (s32)&D_800CBC90, 0, -1);
    }
    Geometry_FlushModelBatch();
    Geometry_SetColorDither(0);
    Geometry_SetPrimitiveAlphaOverride(0, 0x20);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_800D3A40[], *D_800D3A44[], *D_800D3A48[], *D_800D3A54[];
static inline char *reactionText(void *text, MenuSettings *settings) { return ((char **)text)[settings->language]; }
#else
extern char *D_800D3A40, *D_800D3A44, *D_800D3A48, *D_800D3A54;
static inline char *reactionText(void *text, MenuSettings *settings) { return *(char **)text; }
#endif
extern void SetN64_CopyString(char *,const char *);
extern void Gsky_PostScaledScreenMessage(void *,void *,char *,f32);
static inline void nextMessage(s32 *next) {
    (*next)++;
    *next %= 4;
}

void Player_PostKillMessages(Shared_ReactionPlayer *a,Shared_ReactionPlayer *b,Shared_ReactionInteraction *unused) {
    MenuSettings *settings = &D_80145088.settings;
    MatchModes *modes;
    if (!settings->local) return;
    if (a!=b) {
        if (!a->unk5D8->unk8F) return;
        modes = &D_80145088.modes;
        if (modes->tag) {
            SetN64_CopyString(a->messages[a->messageNext], reactionText(&D_800D3A40, settings));
            SetN64_CopyString(a->messages[a->messageNext]+10, b->unk5D8->name);
            if (a->owner) Gsky_PostScaledScreenMessage(&D_80145088,a->owner,a->messages[a->messageNext],1.5f);
            nextMessage(&a->messageNext);
            SetN64_CopyString(b->messages[b->messageNext], reactionText(&D_800D3A44, settings));
            SetN64_CopyString(b->messages[b->messageNext]+11, a->unk5D8->name);
            if (b->owner) Gsky_PostScaledScreenMessage(&D_80145088,b->owner,b->messages[b->messageNext],1.5f);
        } else {
            if (!modes->captureFlag) return;
            SetN64_CopyString(a->messages[a->messageNext], reactionText(&D_800D3A48, settings));
            SetN64_CopyString(a->messages[a->messageNext]+10, b->unk5D8->name);
            if (a->owner) Gsky_PostScaledScreenMessage(&D_80145088,a->owner,a->messages[a->messageNext],1.5f);
            nextMessage(&a->messageNext);
            SetN64_CopyString(a->messages[a->messageNext], reactionText(&D_800D3A54, settings));
            if (a->owner) Gsky_PostScaledScreenMessage(&D_80145088,a->owner,a->messages[a->messageNext],1.5f);
            nextMessage(&a->messageNext);
            SetN64_CopyString(b->messages[b->messageNext], reactionText(&D_800D3A44, settings));
            SetN64_CopyString(b->messages[b->messageNext]+11, a->unk5D8->name);
            if (b->owner) Gsky_PostScaledScreenMessage(&D_80145088,b->owner,b->messages[b->messageNext],1.5f);
            nextMessage(&b->messageNext);
            SetN64_CopyString(b->messages[b->messageNext], reactionText(&D_800D3A58, settings));
            if (b->owner) Gsky_PostScaledScreenMessage(&D_80145088,b->owner,b->messages[b->messageNext],1.5f);
        }
    }
    nextMessage(&b->messageNext);
}

/* CODE_80219A40.CPP */
/* TurretPlayerRelation, interaction and score views used to select reactions and record statistics. */

/* Selects and records a player's reaction to an interaction. */

/* Reaction thresholds are loaded from the cartridge's shared float table. */
void Playerai_ApplyStun(void *, f32);
void func_80229FA0_de(void *, void *);
s32 Player_GetPlayerIndex(void *, unsigned int);
s32 Player_GetMaxHealth(void *);
int func_8022B178_de(void *);
void Particle_ReleaseOwnerListOneEffects(void *, s32);
void * Scene_GetModelRecordByIndexPointer(Shared_World *, u16 *);
s32 XPlus_NextRandomInteger(void);

extern s32 D_8011D8D0;
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
            sourceFlags = Scene_GetModelRecordByIndexPointer(&g_world, sourceHandle);
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
                    Playerai_ApplyStun(damagedPlayer, 2.5f);
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
                        clampedHealth = Player_GetMaxHealth(damagedPlayer);
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
                            facingSine = Gu_Sinf(attacker->unk6C);
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
                            killerPlayerIndex = Player_GetPlayerIndex(&D_80145040, (u32) creditedPlayer);
                            victimKillStatistics = (void *)damagedPlayer->unk5D8;
                            if ((victimKillStatistics->unk8F == 1) && ((((struct Shared_ReactionMatchState *)(&D_80145040))->unk18B4) != 0)) {
                                victimKillStatistics->kills_special[killerPlayerIndex]++;
                            } else {
                                damagedPlayer->unk5D8->kills_normal[killerPlayerIndex]++;
                            }
                            victimPlayerIndex = Player_GetPlayerIndex(&D_80145040, (u32) damagedPlayer);
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
                                damagedPlayer->unk12F0 = (s32) (XPlus_NextRandomInteger() % 7);
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
                                actorStatisticsNode = Portal_FindSearchNode(&D_8013B364, damagedPlayer->unk1454->unk4);
                                actorStatisticsNode->unk38 = (s32) (actorStatisticsNode->unk38 + 1);
                                actorStatisticsNode = Portal_FindSearchNode(&D_8013B364, creditedPlayer->unk1454->unk4);
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
                            Particle_ReleaseOwnerListOneEffects(&D_8011D8D0, (s32) damagedPlayer);
                        }
                    }
                }
            }
        }
    }
}

extern void **Gobjinst_RequestAnimatedModelVariant(LevelActor *, s32);
extern void Cache_UnlockResource(s32, void *);
void Player_DrawPlayerBodyAndWeapon(LevelActor *actor, s32 animationContext, Draw *context)
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
            D_800D15E4[1] = 150.0f;
        } else {
            D_800D15E4[1] = 0.0f;
            D_800D15E4[2] = 150.0f;
        }
        if (player->fixedAlpha) D_800D15E4[3] = 70.0f;
        else D_800D15E4[3] = (u8)player->camera->fadeState;
        D_800D15E4[4] = 128.0f;
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
    { s32 weaponModel = ((WeaponInfo *)D_800D052C[player->selectedWeapon])->model;
    model = weaponModel - 0x4B3;
    if (player->selectedWeapon >= 16) model = weaponModel - 0x4B5; }
        goto weapon;
    } else {
        if (D_80145088.settings.local) {
            if (player->controls->unk8F && D_80145088.modes.tag && player->health == 0) return;
            if (D_80145088.settings.local && (player->hidden || player->kind == D_800C9228_de) &&
                player->health == 0) return;
        }
        if (player->flags & 0x20) Player_DrawTintedPlayer(actor, animationContext, context);
        else {
            if (D_801468A0->countRule && player->controls->unk8F) actor->team = D_801468A0->teamColour;
            else actor->team = (u8)actor->definition->first;
            Geometry_DrawActorModelParts(context->model, player, actor->fieldB4, 1,
                           &actor->lighting[D_800D297C], 0, actor->field3);
            if (0.0f < player->opacity) {
                Geometry_DrawTintedModelParts(context->model, player, actor->fieldB4, 1,
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
    model = ((WeaponInfo *)D_800D052C[player->selectedWeapon])->model;
    model -= 0x4B3;
    if (player->selectedWeapon >= 16) model -= 2;
weapon:
    if (model >= 0) {
        resource = Gobjinst_RequestAnimatedModelVariant(actor, model);
        if (resource) {
            Geometry_DrawModelResource(resource, actor->fieldB4, 1,
                            &actor->lighting[D_800D297C], 0, actor->field3);
            Cache_UnlockResource(0, resource);
        }
    }
}

/* 802192C0_3.CPP */
extern char D_8010F328[];
void func_8021A78C_de(void *playerObject) {
    char *object = playerObject;
    void *attributes;
    void *state = object + 0x688;
    f32 zero;
    f32 default_value;
    f32 tail_value;
    CVector3 *tail_vector;
    s32 type;
    if (((ObjectLinks16D8 *)(object))->unk_1450 != 0) {
        attributes = D_8010EEB8;
    } else {
        s32 index = ((ObjectLinks16D8 *)(object))->unk_5D4;
        attributes = (void *)(index << 4);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 3);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 2);
        attributes = D_8010F328 + (s32)attributes;
    }
    ContPad_InitControllerInput(state, attributes);
    ((ObjectLinks16D8 *)(object))->unk_6C0 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6C4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6C8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6CC = 0;
    ((ObjectLinks16D8 *)(object))->unk_6D0 = 1;
    ((ObjectLinks16D8 *)(object))->unk_6D4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6D8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6DC = 0;
    ((ObjectLinks16D8 *)(object))->unk_6E4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_758 = 0;
    ((ObjectLinks16D8 *)(object))->unk_75C = 0;
    ((ObjectLinks16D8 *)(object))->unk_11B4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_11B8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_708 = 0;
    ((ObjectLinks16D8 *)(object))->unk_70C = 0;
    ((ObjectLinks16D8 *)(object))->unk_710 = 0;
    ((ObjectLinks16D8 *)(object))->unk_714 = 0;
    ((ObjectLinks16D8 *)(object))->unk_724 = 0;
    ((ObjectLinks16D8 *)(object))->unk_728 = 0;
    ((ObjectLinks16D8 *)(object))->unk_72C = 0;
    ((ObjectLinks16D8 *)(object))->unk_730 = 0;
    ((ObjectLinks16D8 *)(object))->unk_734 = 0;
    ((ObjectLinks16D8 *)(object))->unk_738 = 0;
    ((ObjectLinks16D8 *)(object))->unk_73C = 0;
    ((ObjectLinks16D8 *)(object))->unk_740 = Playerai_GetObjectOwnerHeight(object);
    default_value = D_800C22F8_de;
    ((ObjectLinks16D8 *)(object))->unk_744 = 0;
    (&((ObjectLinks16D8 *)(object))->unk_748)->x = (&((ObjectLinks16D8 *)(object))->unk_748)->y = (&((ObjectLinks16D8 *)(object))->unk_748)->z = 0;
    ((ObjectLinks16D8 *)(object))->unk_754 = default_value;
    ((ObjectLinks16D8 *)(object))->unk_780 = 0;
    ((ObjectLinks16D8 *)(object))->unk_784 = default_value;
    ((ObjectLinks16D8 *)(object))->unk_6E8 = ((ObjectLinks16D8 *)(object))->unk_8;
    ((ObjectLinks16D8 *)(object))->unk_6F8 = ((ObjectLinks16D8 *)(object))->unk_8;
    ((ObjectLinks16D8 *)(object))->unk_658 = 0;
    ((ObjectLinks16D8 *)(object))->unk_668 = 0;
    ((ObjectLinks16D8 *)(object))->unk_66C = 0;
    if (((ObjectLinks16D8 *)(object))->unk_18.v0 != 0) {
        ((ObjectLinks16D8 *)(object))->unk_6F4.v0 = ((struct ModelBlend *) ((ObjectLinks16D8 *) object)->unk_18.v1)->height;
    } else {
        ((ObjectLinks16D8 *)(object))->unk_6F4.v1 = 0;
    }
    tail_vector = &((ObjectLinks16D8 *)(object))->unk_7D8;
    ((ObjectLinks16D8 *)(object))->unk_7B0.v0 = 0;
    zero = ((ObjectLinks16D8 *)(object))->unk_7B0.v1;
    tail_value = D_800C22FC_de;
    type = 2;
    ((ObjectLinks16D8 *)(object))->unk_718 = 0;
    ((ObjectLinks16D8 *)(object))->unk_71C = 0;
    ((ObjectLinks16D8 *)(object))->unk_720 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7EC = 0;
    ((ObjectLinks16D8 *)(object))->unk_7F0 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7E8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_788 = 0;
    ((ObjectLinks16D8 *)(object))->unk_78C = 0;
    ((ObjectLinks16D8 *)(object))->unk_790 = 0;
    ((ObjectLinks16D8 *)(object))->unk_794 = 0;
    ((ObjectLinks16D8 *)(object))->unk_798 = -1;
    ((ObjectLinks16D8 *)(object))->unk_79C = 0;
    ((ObjectLinks16D8 *)(object))->unk_7A0 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7A4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7A8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7AC = 0;
    tail_vector->x = tail_vector->y = tail_vector->z = zero;
    ((ObjectLinks16D8 *)(object))->unk_7E4 = tail_value;
    ((ObjectLinks16D8 *)(object))->unk_7B4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7B8 = -1;
    ((ObjectLinks16D8 *)(object))->unk_7C0 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7C4 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7C8 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7CC = zero;
    ((ObjectLinks16D8 *)(object))->unk_7D0 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7D4 = zero;
    Player_SetPlayerState(object, object, type);
    ((ObjectLinks16D8 *)(object))->unk_80C = 0;
    ((ObjectLinks16D8 *)(object))->unk_838 = zero;
    ((ObjectLinks16D8 *)(object))->unk_83C = zero;
    ((ObjectLinks16D8 *)(object))->unk_840 = zero;
    ((ObjectLinks16D8 *)(object))->unk_848 = 0;
    ((struct ObjectState8E *) ((ObjectLinks16D8 *) object)->unk_5D8)->state = 0;
    ((ObjectLinks16D8 *)(object))->unk_704 = zero;
    ((ObjectLinks16D8 *)(object))->unk_16D4 = 0;
}

extern s32 D_80140FF8;
CQuatern func_8024796C_de(void *actor);
s16 *func_8022AA9C_de(AimPlayer *arg0, s32 arg1);
void Player_GetPlayerViewTranslation(void *arg0, f32 *arg1);
s32 Particle_SpawnEffectGroup(EffectSystem *sys, EffectActor *source, EffectActor *owner, s32 *refCount, s32 arg4, s32 kind, CVector3 arg6, CQuatern rotation, CVector3 pos, CVector3 *aim, s32 arg10, s32 arg11);

static __inline__ s32 containsFire(s16 **entries,s32 effect) {
 s32 i=0; s16 **p=entries;
 search:
  if (*p==0) return 0;
  if ((*p)[2]==effect) return 1;
  i++; p++;
 if(i<3) goto search;
 return 0;
}
void func_8021A9A4_de(AimPlayer *aimPlayer, s32 effect) {

    AimView *weapon;
    s16 *mode;
    s16 **entries;
    CVector3 direction;
    CVector3 position;
    CQuatern aim;
    s32 value; void *extra; f32 timer;
    f32 amount;
    s16 *ammo;
    weapon = aimPlayer->view;
    if (aimPlayer->state < 2 || (s16)aimPlayer->state == 0x10 || (s16)aimPlayer->state == 0x11) return;
    aim = func_8024796C_de(aimPlayer);
    if (effect == 0x439 || effect == 0x4C4 || effect == 0x432 || effect == 0x4E3 ||
        effect == 0x419 || effect == 0x4D3 || effect == 0x425 || effect == 0x4CA) aimPlayer->unk594 = 2;
    mode = func_8022AA9C_de(aimPlayer, aimPlayer->unk62E);
    if (effect == 0x439 || effect == 0x4C4 || effect == 0x432 || effect == 0x4E3 ||
        effect == 0x419 || effect == 0x4D3 || effect == 0x425 || effect == 0x4CA) aimPlayer->unk594 = 1;
    if (mode) {
        WeaponInfo *table = D_800D052C[aimPlayer->unk62E];
        if (!aimPlayer->controlled && D_80140FF8 == 1) entries=&table->weaponClass;
        else entries=table->computerClasses;
        if (containsFire(entries,effect)) goto fire;
    }
    if (aimPlayer->unk62E != 0 && aimPlayer->unk62E != 0x10) goto spawn;
fire:
    if (weapon) aim = aimPlayer->rotation;
    if (aimPlayer->unk62E != 0 && aimPlayer->unk62E != 0x10) {
        ammo = &aimPlayer->ammo[mode[0]];
        *ammo -= (u16)mode[3];
        if (*ammo < 0) *ammo = 0;
        if (*ammo == 0) {
            if (aimPlayer->weapons[aimPlayer->unk62E][1] == 3 || aimPlayer->weapons[aimPlayer->unk62E][1] == 7) {
                aimPlayer->weapons[aimPlayer->unk62E][0] = 0;
                aimPlayer->weapons[aimPlayer->unk62E][1] = -1;
            }
        }
    }
    if (aimPlayer->equippedKind == 0x11) {
        if (aimPlayer->animation == 0x1004) {timer=aimPlayer->animationTimer; amount = D_800C2318_de;}
        else if (aimPlayer->animation == 4000) {timer=aimPlayer->animationTimer; amount = D_800C231C_de;}
        else {
            if (aimPlayer->weaponKind == 8) aimPlayer->animation = 0x1004;
            else aimPlayer->animation = 4000;
            goto clear;
        }
        goto consume;
    }
    if (aimPlayer->animation == 1) aimPlayer->animation = 0x1130;
    else if (aimPlayer->animation == 0x1130) { timer=aimPlayer->animationTimer; amount = D_800C2320_de; goto consume; }
    else if (aimPlayer->animation == 0xA28) aimPlayer->animation = 0x1135;
    else if (aimPlayer->animation == 0x1135) { timer=aimPlayer->animationTimer; amount = D_800C2324_de; goto consume; }
    else if (aimPlayer->animation == 0x14) aimPlayer->animation = 0x1144;
    else if (aimPlayer->animation == 0x1144) { timer=aimPlayer->animationTimer; amount = D_800C2328_de; goto consume; }
    else if (aimPlayer->unk62E == 0 && aimPlayer->weaponKind == 8) aimPlayer->animation = 0x5E5E;
    else {
            if (aimPlayer->animation == 0x5E5E) { timer=aimPlayer->animationTimer; amount = D_800C232C_de; goto consume; }
        if ((u32)(aimPlayer->animation - 0x5E24) < 3) aimPlayer->animation = 0x5E56;
        else if (aimPlayer->animation == 0x5E56) { timer=aimPlayer->animationTimer; amount=D_800C2334_de; goto consume; }
        else if (aimPlayer->animation == 0x5E29) aimPlayer->animation = 0x5E59;
        else if (aimPlayer->animation == 0x5E59) { timer=aimPlayer->animationTimer; amount=D_800C2334_de; goto consume; }
        else if (aimPlayer->animation == 0x5E2A) aimPlayer->animation = 0x5E5A;
        else if (aimPlayer->animation == 0x5E5A) { timer=aimPlayer->animationTimer; amount = D_800C2330_de; goto consume; }
        else if (aimPlayer->animation == 0x5E2B) aimPlayer->animation = 0x5E5B;
        else if (aimPlayer->animation == 0x5E5B) { timer=aimPlayer->animationTimer; amount=D_800C2334_de; goto consume; }
        else if (aimPlayer->animation == 0x5E2C) aimPlayer->animation = 0x5E5C;
        else {
                    if (aimPlayer->animation == 0x5E5C) { timer=aimPlayer->animationTimer; amount=D_800C2334_de; goto consume; }
            if (aimPlayer->animation == 0x5E2D) aimPlayer->animation = 0x5E5D;
            else if (aimPlayer->animation == 0x5E5D) { timer=aimPlayer->animationTimer; amount=D_800C2334_de; goto consume; }
            else { aimPlayer->firing = 0; goto spawn; }
        }
    }
    goto clear;
ordinary:
    timer=aimPlayer->animationTimer; amount = D_800C2334_de;
consume:
    if (!(amount <= timer)) { aimPlayer->firing = 0; goto spawn; }
    aimPlayer->animationTimer = timer-amount;
clear:
    aimPlayer->firing = 0;
spawn:
    if (weapon && weapon->mode != 1) direction = weapon->origin;
    else Player_GetPlayerViewTranslation(aimPlayer, &direction.x);
    position = aimPlayer->position;
    extra = 0;
    if (aimPlayer->unk788 == 2) extra = aimPlayer->unk794;
    Particle_SpawnEffectGroup(&D_8011D8D0, aimPlayer, aimPlayer, 0, extra, effect, position, aim,
                     direction, &aimPlayer->aim, -1, (aimPlayer->movementFlags&0x1000)?5:1);
    if (effect == 0x414 || effect == 0x42D) {
        s32 shots = aimPlayer->shots - 1;
        if (shots < 0) shots = 0;
        aimPlayer->shots = shots;
    }
    if (aimPlayer->unk62E != 9 && aimPlayer->unk62E != 0x15 && aimPlayer->unk62E != 0x14)
        D_800FF140_de[aimPlayer->playerIndex]++;
}

/* Resets a player record for a new round: clears the ammo and the 22 action slots, marks every action but the first
   unavailable when the match is local and the player has a definition and no bonus, calls the setup for the current mode,
   sets the starting ammo by whether the player has a definition, and chooses the starting weapon (fixed for states 17 and
   18, none for a bonus profile, the low half of the second loadout word of the definition when the player is a computer, else the first
   action marked 1) before loading the weapon's animation table and count. */
extern s32 Achieve_ApplyPlayerOptionOverrides(struct Player *);
extern s32 Achieve_EnableLevelWeapons(struct Player *);

void Player_ResetPlayerWeapons(struct Player *player) {
    Shared_Game *game;
    s32 i;
    s32 j;
    s32 k;
    struct WeaponInfo *weaponInfo;
    AiCharacterDefinition *definition;
    for (i = 6; i >= 0; i--) {
        player->ammo[i] = 0;
    }
    for (i = 21; i >= 0; i--) {
        player->actions[i][0] = 0;
    }
    game = &D_801462C8;
    if (game->local == 1 && player->definition != 0) {
        if (game->unk62C == 0 || player->profile->bonus == 0) {
            for (j = 1; j < 22; j++) {
                player->actions[j][0] = 0;
                player->actions[j][1] = -1;
            }
        }
        switch (D_801462C8.controllerMode) {
        case 1:
            Achieve_ApplyProfileWeaponUnlocks(player);
            break;
        case 4:
            Achieve_EnableLevelWeapons(player);
            break;
        default:
            Achieve_ApplyPlayerOptionOverrides(player);
            break;
        }
    }
    if (player->definition == 0) {
        player->ammo[0] = 100;
        player->ammo[1] = 100;
        player->ammo[2] = 50;
    } else {
        player->ammo[0] = 50;
        player->ammo[1] = 0;
        player->ammo[2] = 0;
        player->ammo[3] = 0;
    }
    if (player->state == 17) {
        player->weapon = 16;
        player->selectedAction = 16;
        player->queuedAction = 16;
        player->lastAction = 16;
    } else if (player->state == 18) {
        player->weapon = 17;
        player->selectedAction = 17;
        player->queuedAction = 17;
        player->lastAction = 17;
    } else if (D_801462C8.counters.m_bFragTagOn != 0 && player->profile->bonus != 0) {
        player->selectedAction = 0;
        player->weapon = 0;
        player->queuedAction = 0;
        player->lastAction = player->selectedAction;
    } else {
        if (player->computer != 0) {
            definition = player->definition;
            if (definition != 0 && definition->loadout != 0) {
                player->weapon = (u16)definition->loadout[1] - 0x4C3;
                player->selectedAction = player->weapon;
            } else {
                player->weapon = 0;
                player->selectedAction = 0;
            }
        } else {
            for (k = 0; k < 22; k++) {
                if (player->actions[k][1] == 1) {
                    break;
                }
            }
            if (k < 22) {
                player->weapon = k;
                player->selectedAction = k;
            } else {
                player->weapon = 0;
                player->selectedAction = 0;
            }
        }
        player->queuedAction = player->selectedAction;
        player->lastAction = player->selectedAction;
    }
    if (D_80145088.settings.local != 0) {
        weaponInfo = D_800D052C[player->weapon];
        player->weaponAnimationTable = weaponInfo->animation;
        weaponInfo = D_800D052C[player->selectedAction];
        player->weaponAnimationCount = weaponInfo->animationCount;
    }
}

extern s32 D_801371D4;
extern void Player_ReleaseObjectHandles(void *);
extern void Scene_SetSelection(void *, s32, s32);
extern f32 Graphu64_GetPointDistance(void *, void *);
extern s32 Portal_FindNearestPointIndex(void *, void *);
extern void Control_SetProfileMode(void *, s32);
extern void Player_InitActorHudState(void *);
/* Places the player at the matching level spawn. In multiplayer, choose the last
 * point tied for the greatest distance to its nearest player. Fall back when no
 * point is available, then update the controller's current cell. The single-player arm opens with a dead
 * conditional store: its join label ends cse's path, so the mismatch call keeps passing world (s1) instead
 * of being cross-jumped into the fallback's &D_8011FE88 call; flow and jump2 remove it. */
void Player_PlacePlayerAtSpawnPoint(struct Player *player, s32 model, s32 scale, s32 reset) {
    Shared_World *world;
    Shared_Placed single;
    Shared_Placed points[32];
    s32 count;
    s32 best;
    s32 i;
    f32 bestDistance;
    f32 distance;
    Shared_ActorView *other;
    s32 floor;
    s32 cell;
    Player_ReleaseObjectHandles(player);
    Control_SetProfileMode(((Shared_ActorView *)player)->controller, 0);
    world = &g_world;
    if (reset) {
        ((Shared_ActorView *)player)->field864 = 0;
        ((Shared_ActorView *)player)->field868 = 0;
    }
    if (D_80145088.settings.local) {
        count = Scene_FindPlacedObjectsByKey(world, -1, model, points, 32);
        best = -1;
        bestDistance = 0.0f;
        for (i = 0; i < count; i++) {
            distance = D_800C2340_de;
            for (other = D_80145060.actorList; other; other = other->next) {
                f32 d = Graphu64_GetPointDistance(&points[i].pos, &other->position.vector);
                if (d < distance) distance = d;
            }
            if (bestDistance <= distance) {
                bestDistance = distance;
                best = i;
            }
        }
        if (best == -1) goto fallback;
        ((Shared_ActorView *)player)->weapon.position0 = points[best].pos;
        ((Shared_ActorView *)player)->position.vector = ((Shared_ActorView *)player)->weapon.position0;
        ((LevelActor *)player)->yaw = ((Shared_ActorView *)player)->weapon.yaw = points[best].unkC;
        floor = Scene_FindFloorPolygon(&g_world, &((Shared_ActorView *)player)->position.vector);
    } else {
        if (model != 0 && player != 0) {
            floor = 0;
        }
        if (Scene_FindPlacedObjectsByKey(world, -1, model, &single, 1) == 0) {
            goto fallback;
        }
        if (single.kind != D_801371D4) {
            Scene_SetSelection(world, model, scale);
            goto done;
        }
        ((Shared_ActorView *)player)->weapon.position0 = single.pos;
        ((Shared_ActorView *)player)->position.vector = ((Shared_ActorView *)player)->weapon.position0;
        ((LevelActor *)player)->yaw = ((Shared_ActorView *)player)->weapon.yaw = single.unkC;
        floor = Scene_GetModelSectionTwoRecord(world, single.pad12);
    }
    ((Shared_ActorView *)player)->weapon.model = floor;
    ((Shared_ActorView *)player)->modelId = floor;
    Player_InitActorHudState(player);
    goto done;
fallback:
    Scene_SetSelection(&g_world, model, scale);
done:
    cell = Portal_FindNearestPointIndex(&D_8013B364, &((Shared_ActorView *)player)->position.vector);
    ((AiController *)((Shared_ActorView *)player)->owner)->current = cell;
}

/* 800C73E8.CPP */
/* ROM-grounded data: src/rw_pool_8021A78C_C7FE8_us_rev1.c */
const unsigned int D_blob_87bff964910f8ef44402[2] = {
    0x3F800000, 0x3F800000,
};
