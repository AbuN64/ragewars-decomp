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
void func_80229814_de(void *, f32);
void func_80229FA0_de(void *, void *);
s32 Weapons_GetPlayerIndex(void *, unsigned int);
s32 func_8022AC00_de(void *);
int func_8022B178_de(void *);
int Camera_IsSequenceActive(void);
void func_802830CC_de(void *, s32);
void * func_8028B2F8_de(Shared_World *, u16 *);
s32 func_802A01E8_de(void);






extern s32 D_8011D8D0;
extern s8 D_8013B364;
extern Shared_MatchRules D_801468A0[];

 












void func_80219A40_de(struct Shared_ReactionActor *attacker, void *arg1, struct Shared_ReactionInteraction *packet) {
    f32 temp_f20;
    f32 temp_f3;
    f32 var_f0;
    s32 *var_v1_4;
    s32 temp_a0_5;
    s32 temp_s0;
    s32 temp_s3;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_v0_5; /* Integer result reused after each score value is stored. */
    s32 temp_v1_2;
    s32 temp_v1_9;
    s32 kind;
    s32 var_v0_2;
    s32 var_v1;
    s32 var_v1_2;
    struct Shared_ReactionSource *temp_a0_2;
    struct Shared_ReactionPlayer *temp_s1;
    struct Shared_ReactionPlayer *var_s2;
    u16 *temp_a1;
    s32 temp_v1;
    u16 temp_v1_4;
    s32 temp_v1_6; 
    s32 temp_a0_6;
    s32 temp_a0_8;
    s32 score_owner_6;
    s32 score_owner_8;
    s32 *first_score_slot; 
    s32 temp_v1_12;
    u8 temp_v1_3;
    struct Shared_ReactionObjectKind *temp_a0;
    struct Shared_ReactionPlayer *temp_a1_2;
    struct Shared_ReactionSource *reaction_source; 
    struct Shared_ReactionAttribution *temp_a0_3;
    struct Shared_ReactionPlayerIndex *attributed_actor;
    s32 projectile_present; 
    struct Shared_ReactionStatistics *temp_a0_4;
    struct Shared_ReactionStatistics *temp_a0_7;
    struct Shared_ReactionFlags *temp_v0;
    struct Shared_ReactionObjectStatistics *temp_v0_6;

    struct Shared_ReactionStatistics *temp_v1_10;
    struct Shared_ReactionStatistics *temp_v1_11;
    struct Shared_ReactionStatistics *temp_v1_13;
    struct Shared_ReactionStatistics *temp_v1_14;
    struct Shared_ReactionStatistics *temp_v1_15;
    struct Shared_ReactionStatistics *temp_v1_16;
    struct Shared_ReactionStatistics *temp_v1_5;
    struct Shared_ReactionStatistics *temp_v1_7;

    var_s2 = 0;
    kind = -1;
    if ((Camera_IsSequenceInWindow() == 0) && (Camera_IsSequenceActive() == 0) && !(D_801462C8.flags & 1)) {
        temp_s1 = attacker->unk1D8;
        temp_a1 = temp_s1->unk14;
        temp_s6 = temp_s1->unk5E4 > 0;
        if (temp_a1 == 0) {
            goto flag_clear;
        }
        
        while (temp_a1 != 0) {
            temp_v0 = func_8028B2F8_de(&D_8011FE88, temp_a1);
            var_v1 = 0;
            if (temp_v0 == 0) {
                break;
            }
            var_v1 = 1;
            if (temp_v0->unk52 & 0x40) {
                goto flag_done;
            }
            break;
        }
flag_clear:
        var_v1 = 0;
flag_done:

        if (var_v1 != 0) {
            kind = 0x17;
        }
        if (temp_s1->unk650 == 0x20) {
            kind = 0x20;
        }
        if (packet != 0) {
            temp_a0 = packet->unk0;
            if ((temp_a0 != 0) && (temp_a0->unk0 == 2)) {
                temp_v1 = temp_a0->unk4;
                if (temp_v1 == 0x432) {
                    goto block_45;
                }
                if (temp_v1 < 0x433) {
                    if (temp_v1 == 0x405) {
                        goto block_33;
                    }
                    if (temp_v1 < 0x406) {
                        if ((temp_v1 == 0x402) || (temp_v1 == 0x404)) {
                            goto block_38;
                        }
                        goto block_47;
                    }
                    if (temp_v1 < 0x41E) {
                        if (temp_v1 < 0x41B) {
                            goto block_47;
                        }
                        goto block_early_return;
                    }
                    goto block_46;
                }
                if (temp_v1 < 0x4E0) {
                    if (temp_v1 >= 0x4DD) {
                        goto block_early_return;
                    }
                    if (temp_v1 == 0x43C) {
                        goto block_38;
                    }
                    if (temp_v1 == 0x4DA) {
                        goto block_33;
                    }
                    goto block_47;
                }
                if (temp_v1 == 0x4E3) {
                    goto block_45;
                }
                goto block_47;
block_early_return:
                if (temp_s1->unk5E4 > 0) {
                    func_80229814_de(temp_s1, 2.5f);
                }
                return;
block_33:
                if (temp_s1->unk5E4 > 0) {
                    var_f0 = temp_s1->unk11E0 + D_800C22D4_de[0];
                    temp_s1->unk11E0 = var_f0 < D_800C22D8_de ? D_800C22D8_de : var_f0;

                }
                packet->unk4 = 0x100;
                goto block_46;
block_38:
                if (temp_s1->unk122C & 0x1000) {
                    temp_v1_2 = temp_s1->unk5E4;
                    if (temp_v1_2 <= 0) {
                        packet->unk4 = 0;
                    } else {
                        temp_s0 = temp_v1_2 + packet->unk4;
                        var_v1_2 = func_8022AC00_de(temp_s1);
                        if (temp_s0 < var_v1_2) {
                            var_v1_2 = temp_s0;
                        }
                        temp_s1->unk5E4 = var_v1_2;
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
            func_80229FA0_de(temp_s1, packet);
            Render_ApplyPlayerDamage(temp_s1, attacker, packet->unk4, packet->unkC, kind);

            temp_a0_2 = packet->unk0;
            if (temp_a0_2 != 0) {
                temp_v1_3 = temp_a0_2->unk0;
                if (temp_v1_3 != 1) {
                    if (temp_v1_3 == 2) {
                        temp_a1_2 = temp_a0_2->unk12C;
                        reaction_source = temp_a0_2;
                        if (temp_a1_2 != 0) {
                            if (temp_a1_2->unk0 == 1) {
                                if (temp_a1_2->unk100 & 0x300000) {
                                    var_s2 = temp_a1_2;
                                } else if (temp_a1_2->unkE4 == 0x40C) {
                                    var_s2 = temp_a1_2->unk1D8;
                                }
                            }
                            temp_v1_4 = reaction_source->unk4;
                            if (((temp_v1_4 == 0x3EB) || (temp_v1_4 == 0x416)) && (temp_s6 != 0) && (func_8022B178_de(temp_s1) != 0)) {
                                temp_v1_5 = (void *)var_s2->unk5D8;
                                temp_v1_5->special_hits = (u16) (temp_v1_5->special_hits + 1);
                            }
                            temp_f20 = func_802B7130_de(attacker->unk6C);
                            temp_f3 = ((temp_s1->unk8 - reaction_source->unk8) * -temp_f20) + ((temp_s1->unk10 - reaction_source->unk10) * -func_802B6560_de(attacker->unk6C));
                            if (temp_f3 < D_800C22DC_de) {

                                temp_s1->unk13C4 = 1;
                            } else if (temp_f3 > D_800C22E0_de) {

                                temp_s1->unk13C4 = 2;
                            } else {
                                goto block_69;
                            }
                        }
                    }
                } else {
                    if (temp_a0_2->unk100 & 0x300000) {
                        var_s2 = temp_a0_2->unk1D8;
                    }
block_69:
                    temp_s1->unk13C4 = 0;
                }
            } else {
                var_s2 = temp_s1;
            }
            if (var_s2 != 0) {
                if (packet != 0) {
                    temp_a0_3 = packet->unk0;
                    projectile_present = temp_a0_3 != 0;
                    do { 
                      if (!projectile_present) { break; }
                      if (temp_a0_3->unk0 == 2) {
                        temp_v1_6 = temp_a0_3->unk4;
                        switch (temp_v1_6) {
                            case 0x404:
                            case 0x40F:
                                goto block_88;
                            case 0x402:
                            case 0x427:
                                goto block_87;
                            default:
                                if (!(packet->unkC & 0x100000)) {
                                    temp_v1_6 = var_s2->unk5D4;
                                    goto block_86;
                                }
                                goto block_87;
                        }
                    }
                    } while (0);
                    if ((temp_a0_3 != 0) && (temp_a0_3->unk0 == 1) && (temp_a0_3->unk100 & 0x300000)) {
                        attributed_actor = temp_a0_3->unk1D8;
                        if (!(packet->unkC & 0x100000)) {
                            temp_v1_6 = attributed_actor->unk5D4;
block_86:
                            ++D_800FEAE0[temp_v1_6];

                        }
                    }
                    goto block_87;
                }
block_87:
                if (var_s2 != 0) {
block_88:
                    if ((var_s2 != temp_s1) && (temp_s1->unk1450 != 0)) {
                        temp_s1->unk1454->unk328 = var_s2;
                        temp_s1->unk1454->unk324 = 0x1F4;
                    }
                    if ((var_s2 != 0) && (temp_s1->unk5E4 == 0)) {
                        temp_v1_7 = (void *)temp_s1->unk5D8;
                        if (temp_v1_7->counted == 0) {
                            temp_v1_7->counted = 1U;
                            temp_s5 = Weapons_GetPlayerIndex(&D_80145040, (u32) var_s2);
                            temp_a0_4 = (void *)temp_s1->unk5D8;
                            if ((temp_a0_4->unk8F == 1) && ((((struct Shared_ReactionMatchState *)(&D_80145040))->unk18B4) != 0)) {
                                temp_a0_4->kills_special[temp_s5]++;
                            } else {
                                temp_s1->unk5D8->kills_normal[temp_s5]++;
                            }
                            temp_s3 = Weapons_GetPlayerIndex(&D_80145040, (u32) temp_s1);
                            if ((temp_s1->unk5D8->unk8F == 1) && ((((struct Shared_ReactionMatchState *)(&D_80145040))->unk18B4) != 0)) {
                                var_s2->unk5D8->deaths_special[temp_s3]++;
                            } else {
                                var_s2->unk5D8->deaths_normal[temp_s3]++;
                            }
                            Render_PostKillMessages(temp_s1, var_s2, packet);
                            if (var_s2 != 0) {
                                temp_a0_5 = var_s2->unk1338;
                                temp_v1_9 = temp_a0_5 + 1;
                                var_v0_2 = temp_v1_9;
                                if (temp_v1_9 < 0) {
                                    var_v0_2 = temp_a0_5 + 8;
                                }
                                temp_v0_5 = temp_v1_9 - ((var_v0_2 >> 3) * 8);
                                var_s2->unk1338 = temp_v0_5;
                                var_s2->unk12CC[temp_v0_5] = temp_s1;
                                var_s2->unk12F4[var_s2->unk1338] = 0xFF;
                            }
                            if (temp_s1 != 0) {
                                temp_s1->unk12EC = var_s2;
                                temp_s1->unk12F0 = (s32) (func_802A01E8_de() % 7);
                            }
                            if (temp_s5 == temp_s3) {
                                temp_v1_10 = (void *)temp_s1->unk5D8;
                                temp_v1_10->deaths_self = (u16) (temp_v1_10->deaths_self + 1);
                                temp_v1_11 = (void *)temp_s1->unk5D8;
                                temp_v0_5 = temp_v1_11->score - 1;
                                temp_v1_11->score = (u16) temp_v0_5;
                                temp_v0_5 = D_801468C4;
                                if (temp_v0_5 != 0) {
                                    temp_v1_12 = temp_s1->unk5D8->unk92;
                                    
                                    if (temp_v1_12 >= 0) {
                                        if (temp_v1_12 < 5) {
                                            var_v1_4 = &D_8014280C[temp_v1_12];

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
                                temp_v1_13 = (void *)temp_s1->unk5D8;
                                temp_v1_13->deaths_other = (u16) (temp_v1_13->deaths_other + 1);
                                temp_v0_6 = Nav_FindSearchNode(&D_8013B364, temp_s1->unk1454->unk4);
                                temp_v0_6->unk38 = (s32) (temp_v0_6->unk38 + 1);
                                temp_v0_6 = Nav_FindSearchNode(&D_8013B364, var_s2->unk1454->unk4);
                                temp_v0_6->unk3C = (s32) (temp_v0_6->unk3C + 1);
                                if (temp_s1->unk5D8->unk8F == 1) {
                                    if (D_801468A0->countRule != 0) {
                                        temp_v1_14 = (void *)var_s2->unk5D8;
                                        var_s2->unk12C4 = temp_s1;
                                        temp_v1_14->special_kills = (u16) (temp_v1_14->special_kills + 1);
                                        temp_v1_15 = (void *)var_s2->unk5D8;
                                        temp_v0_5 = temp_v1_15->score + 1;
                                        temp_v1_15->score = (u16) temp_v0_5;
                                        temp_v0_5 = D_801468C4;
                                        if (temp_v0_5 != 0) {
                                            temp_a0_6 = var_s2->unk5D8->unk92;
                                            score_owner_6 = temp_s1->unk5D8->unk92;
                                            
                                            if (temp_a0_6 >= 0) {
                                                if (temp_a0_6 < 5) {
                                                    first_score_slot = &D_8014280C[temp_a0_6];

                                                    var_v1_4 = first_score_slot;
                                                    if (score_owner_6 != temp_a0_6) {
                                                        do { 
                                                            *first_score_slot = *first_score_slot + 1;
                                                            goto reaction_statistics_done;
                                                        } while (0);
                                                    }
                                                }
                                            }
                                        }
                                    } else if (D_801468A0->squads != 0) {
                                        var_s2->unk12C8 = temp_s1;
                                    } else {
                                        goto block_124;
                                    }
                                } else {
block_124:
                                    if (D_801468C4 != 0) {
                                        temp_a0_7 = (void *)var_s2->unk5D8;
                                        if (temp_a0_7->unk92 == temp_s1->unk5D8->unk92) {
                                            temp_a0_7->score = (u16) (temp_a0_7->score - 1);
                                        } else {
                                            temp_a0_7->score = (u16) (temp_a0_7->score + 1);
                                        }
                                    } else {
                                        temp_v1_16 = (void *)var_s2->unk5D8;
                                        temp_v1_16->score = (u16) (temp_v1_16->score + 1);
                                    }
                                    if (D_801468C4 != 0) {
                                        temp_a0_8 = var_s2->unk5D8->unk92;
                                        score_owner_8 = temp_s1->unk5D8->unk92;
                                        
                                        if (temp_a0_8 >= 0) {
                                            if (temp_a0_8 < 5) {
                                                var_v1_4 = &D_8014280C[temp_a0_8];

                                                if (score_owner_8 != temp_a0_8) {
                                                    *var_v1_4 = *var_v1_4 + 1;
                                                } else {
block_134:
                                                    *var_v1_4 = *var_v1_4 - 1;
                                                }

                                            }
                                        }
                                    }
                                }
                            }
reaction_statistics_done:
                            Particle_RetireOwnedActors(&D_8011D8D0, (s32) temp_s1);
                            func_802830CC_de(&D_8011D8D0, (s32) temp_s1);
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
extern s32 D_800CE47C, D_800C9228_de, D_800D297C;
extern const f32 D_800C22E4_de, D_800C22E8_de, D_800C22EC_de, D_800C22F0_de;
extern WeaponInfo *D_800D052C[];
extern void func_80228FB8_de(LevelActor *, s32, Draw *);
extern void **func_8024BFD4_de(LevelActor *, s32);
extern void Scene_UnlockResource(s32, void *);
void Render_DrawPlayerBodyAndWeapon(LevelActor *actor, s32 arg1, Draw *context)
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
        Render_DrawActorModelParts(context->model, player, actor->fieldB4, 1,
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
        if (player->flags & 0x20) func_80228FB8_de(actor, arg1, context);
        else {
            if (D_801468A0->countRule && player->controls->unk8F) actor->team = D_801468A0->teamColour;
            else actor->team = (u8)actor->definition->first;
            Render_DrawActorModelParts(context->model, player, actor->fieldB4, 1,
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
            Scene_UnlockResource(0, resource);
        }
    }
}
