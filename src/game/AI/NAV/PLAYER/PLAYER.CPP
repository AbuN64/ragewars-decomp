#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/NAVIGATION_GRAPH.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "FX/80271B18.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
#include "AI/NAV/CODE_80208158.H"
#include "COMMON/SHAREDPLAYER.H"

/* 80208000.CPP */
/* Resets a player controller: marks the active, requested and committed selections empty, sets the
   request kind to 0xB, clears the four link words at 0x14 to -1, resets the stage counters at 0x1BC
   and 0x1C8 and the target list, installs the default table D_800CE040 through Scaled_SetBehaviorTable and mode
   2 through func_80209874_de, zeroes the tracking values from 0x23C to 0x260, runs the resets
   Nav_ResetWheelProbeState, Scaled_ResetBehaviorState and Scaled_ClearAuxiliaryBehaviorState, and clears the remaining state words. */

extern void Scaled_SetBehaviorTable(void *, char *, s32);
extern void Scaled_SetBehaviourState(void *, s32);
extern void Nav_ResetWheelProbeState(void *);

extern void Scaled_ClearAuxiliaryBehaviorState(void *);

void Nav_ResetPlayerState(s32 *state) {
    s32 i;
    s32 none;

    state[1] = -1;
    state[2] = -1;
    state[3] = 0xB;
    state[4] = -1;
    state[11] = 0;
    state[12] = 0;
    state[13] = 0;
    none = -1;
    for (i = 3; i >= 0; i--) {
        state[5 + i] = none;
    }
    state[10] = -1;
    state[0x1BC / 4] = 0xFFFF;
    state[0x220 / 4] = 0;
    state[0x1C8 / 4] = 0;
    state[14] = 1;
    state[15] = 0;
    state[25] = 0;
    state[0x28C / 4] = 0;
    state[26] = 0;
    state[0xBC / 4] = -1;
    state[0x224 / 4] = -1;
    state[0x228 / 4] = 0;
    for (i = 0; i < 10; i++) {
        state[15 + i] = 0;
        state[27 + i] = 0;
        state[37 + i] = 0;
    }
    state[0x238 / 4] = 0;
    Scaled_SetBehaviorTable(state, &D_800CE040, none);
    Scaled_SetBehaviourState(state, 2);
    ((f32 *) state)[0x244 / 4] = 0.0f;
    state[0x23C / 4] = 0;
    state[0x240 / 4] = 0;
    ((f32 *) state)[0x250 / 4] = ((f32 *) state)[0x254 / 4] = ((f32 *) state)[0x248 / 4] =
        ((f32 *) state)[0x24C / 4] = ((f32 *) state)[0x258 / 4] = ((f32 *) state)[0x25C / 4] =
        ((f32 *) state)[0x260 / 4] = ((f32 *) state)[0x244 / 4];
    Nav_ResetWheelProbeState(state);
    Scaled_ResetBehaviorState(state);
    Scaled_ClearAuxiliaryBehaviorState(state);
    state[0x318 / 4] = 0;
    state[0x31C / 4] = 0;
    state[0x320 / 4] = -1;
    state[0x324 / 4] = 0;
    state[0x328 / 4] = 0;
    state[0x2D8 / 4] = 0;
    state[0x2E4 / 4] = 0;
    state[0x2EC / 4] = 0;
    state[0x2E8 / 4] = 0;
    state[0x2DC / 4] = 0;
    state[0x2E0 / 4] = 0;
    state[0x32C / 4] = -1;
}

/* CODE_80208158.CPP */
/* Updates a computer player's brain for the frame: fixes its route start, runs its planner through Scaled_UpdateTargetPitch and its state callback, counts down its cooldown at 0x324, and for a displayed player sets the health meter from its health over the character's maximum (400 for kinds 11 and 12, 300 for 13 and 14, otherwise func_8022AC00_de), as a percentage, rescaled for kind 14 by the difficulty D_8014693C; in the tutorial (D_801468A0) kind 11 also shows the timer and refills its ammunition, then the meter is drawn through OnScreen_SetFirstBarTarget or OnScreen_SetSecondBarTarget; finally it restarts a stalled player (state 0x12) through Scaled_HandlePlayerTimeout. */

extern char D_801376F8[];

extern void Scaled_UpdateTargetPitch(Brain *);
extern s32 Player_GetMaxHealth(SharedPlayer *);
extern void OnScreen_SetSecondBarTarget(char *, s32);
extern void ContPad_ClearControllerInput(char *);
extern void Scaled_HandlePlayerTimeout(Brain *, SharedPlayer *);

void Nav_UpdateComputerPlayerStatus(Brain *brain) {
    s32 health;
    s32 maximum;
    f32 meter;
    s32 kind;
    CGameStatus *tutorial;
    SharedPlayer *player;

    if (brain->player->views1450.view1450_1.computer == 0) {
        return;
    }
    if (brain->route == -1) {
        brain->route = brain->start;
    }
    Scaled_UpdateTargetPitch(brain);
    if (brain->behaviour->update != 0) {
        brain->behaviour->update(brain->player, 0);
    }
    if (brain->cooldown > 0) {
        brain->cooldown--;
    }
    if (brain->player->views5D8.view5D8_1.record->display != 0) {
        health = brain->player->views5E4.view5E4_2.health >> 8;
        kind = brain->player->views5D8.view5D8_1.record->unk80;
        if (kind == 11) {
            maximum = 400;
        } else if (kind == 12) {
            maximum = 400;
        } else if (kind == 14) {
            maximum = 300;
        } else if (kind == 13) {
            maximum = 300;
        } else {
            maximum = Player_GetMaxHealth(brain->player) >> 8;
        }
        meter = (f32)health / (f32)maximum * 100.0f;
        if (brain->player->views5D8.view5D8_1.record->unk80 == 14) {
            if (meter == 0.0f) {
                meter = (3 - D_801462C8.counters.m_nTalsetLives) * 33;
            } else {
                meter *= 0.33333334f;
                meter += (2 - D_801462C8.counters.m_nTalsetLives) * 33;
            }
            if (meter < 0.0f) {
                meter = 0.0f;
            }
        }
        tutorial = &D_801462C8.counters;
        if (tutorial->enabled != 0) {
            if (brain->player->views5D8.view5D8_1.record->unk80 == 11) {
                OnScreen_SetFirstBarTarget(D_801376F8, (f32)tutorial->m_nBastilleShield);
                if (tutorial->m_nBastilleTimer > 0) {
                    tutorial->m_nBastilleTimer--;
                    ContPad_ClearControllerInput((char *)brain->player + 0x688);
                    brain->w23C = 0;
                    brain->w240 = 0;
                }
                if (tutorial->m_nBastilleTimer == 0 && brain->player->views5E4.view5E4_2.health > 0) {
                    tutorial->m_nBastilleShield = 100;
                    tutorial->m_nBastilleTimer = -1;
                    Player_SetPlayerState(brain->player, brain->player, 2);
                }
            }
            if (brain->player->views5D8.view5D8_1.record->display == 1) {
                OnScreen_SetFirstBarTarget(D_801376F8, meter);
            } else {
                OnScreen_SetSecondBarTarget(D_801376F8, meter);
            }
        }
    }
    player = brain->player;
    if (player->views5E8.view650_16.state == 0x12) {
        player->views1340.view1340_1.stalls++;
        Scaled_HandlePlayerTimeout(brain, player);
    }
}

extern CNavData D_8013B364;
float Graphu64_GetPointDistance(void *, void *);
void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
f32 Nav_SteerTowardPoint(Brain_func_80209308_de *, CVector3 *, f32, f32);
void Scaled_SetPitchFromAngle(Brain_func_80209308_de *, f32, s32);
void Portal_DispatchActorBehavior(AiController *);
float Math_Sqrtf(float);
NavigationPoint *Portal_GetGraphPoint(CNavData *,s32);
NavigationPortal *Portal_GetStridedTableEntry(CNavData *,s32);
NavigationSearchNode *Portal_FindSearchNode(CNavData *,s32);
s32 Portal_FindLinkIndex(CNavData *,s32,s32);
s32 Scaled_AdvanceNodeQueue(AiController *);
typedef struct GroundObject { char pad[0x18]; ActorMotionResource *resource; } GroundObject;
GroundObject *func_8024E6A0_de(Player *);
extern f32 D_800C1BB8_de;
extern f32 D_800C1BBC_de;
extern f32 D_800C1BC0_de;
extern f32 D_800C1BC4_de;
extern f32 D_800C1BC8_de;
extern f32 D_800C1BCC_de;
extern f32 D_800C1BD0_de;
extern f32 D_800C1BD4_de;
extern f32 D_800C1BD8_de;
void Nav_SteerAlongRoute(AiController *controller) {
    CNavData *graph = &D_8013B364;
    CVector3 delta;
    Player *player;
    NavigationPoint *point;
    NavigationPoint *goal;
    NavigationPoint *start;
    NavigationPoint *entry;
    NavigationPortal *portal;
    NavigationSearchNode *node;
    GroundObject *ground;
    CVector3 *pos;
    f32 distance;
    f32 offset;
    f32 reach;
    f32 gap;
    s32 from;
    s32 link;
    s32 riding;
    s32 moving;

    player = controller->player;
    if (controller->mode != -1) {
        controller->unk300 = 0;
        controller->unk310 = 0;
        controller->unk304 = 0;
        controller->unk308 = 0;
        controller->unk30C = 0;
        if (controller->queue[0] != -1) {
                point = Portal_GetGraphPoint(graph, controller->queue[0]);
                pos = &controller->player->pos;
                distance = Graphu64_GetPointDistance(pos, point);
                controller->unk304 = (navigation_attributes(point) & 0x300000) != 0;
                if (controller->queue[0] == controller->current) {
                    link = Portal_FindLinkIndex(graph, controller->previous, controller->queue[0]);
                } else {
                    link = Portal_FindLinkIndex(graph, controller->current, controller->queue[0]);
                }
                if (link > 0) {
                    portal = Portal_GetStridedTableEntry(graph, link);
                    if (portal->kind == 4) {
                        controller->unk30C = 1;
                    }
                    if (portal->kind == 8) {
                        Graphu64_GetPointDistance(pos, Portal_GetGraphPoint(graph, controller->current));
                        goal = Portal_GetGraphPoint(graph, controller->queue[0]);
                        controller->unk308 = 1;
                        if (link != controller->unk32C) {
                            controller->unk314 = 0;
                            controller->unk32C = link;
                        }
                        if (controller->unk314 == 0) {
                            start = Portal_GetGraphPoint(graph, controller->current);
                            GraphU64_SubtractVectors(&delta, pos, &start->position);
                            if (!(Math_Sqrtf(delta.x * delta.x + delta.z * delta.z) < D_800C1BB8_de)) {
                                controller->destination = start->position;
                                return;
                            }
                            controller->unk314 = 1;
                        }
                        if (controller->unk314 == 1) {
                            controller->destination = goal->position;
                            offset = Nav_SteerTowardPoint(controller, &controller->destination, 2.0f, 0.0f);
                            if (offset < 0.0f ? D_800C1BBC_de < -offset : D_800C1BC0_de < offset) {
                                controller->unk310 = 1;
                                return;
                            }
                            controller->unk314 = 2;
                        }
                        if (controller->unk314 == 2) {
                            controller->destination = goal->position;
                            controller->unk314 = 3;
                            return;
                        }
                        if (controller->unk314 == 3) {
                            controller->destination = goal->position;
                            controller->unk314 = 4;
                            return;
                        }
                        if (controller->unk314 == 4) {
                            controller->destination = goal->position;
                            controller->unk314 = 5;
                            return;
                        }
                        if (controller->unk314 == 5) {
                            controller->destination = goal->position;
                            player->actionFlags |= 0x10;
                            controller->unk314 = 6;
                            return;
                        }
                        if (controller->unk314 == 6) {
                            {
                            s32 jumping, falling;
                            moving = controller->player->movementFlags;
                            jumping = moving & 0x2000;
                            falling = moving & 0x1000;
                            if (jumping || falling) {
                                controller->unk314 = 2;
                            }
                            }
                            controller->destination = goal->position;
                        }
                    } else if (portal->kind == 5) {
                        if (controller->unk314 == 0) {
                            entry = Portal_GetGraphPoint(graph, controller->current);
                            if (!(Graphu64_GetPointDistance(pos, entry) < D_800C1BC4_de)) {
                                controller->destination = entry->position;
                                return;
                            }
                            controller->unk314 = 1;
                        }
                        if (controller->unk314 == 1) {
                            node = Portal_FindSearchNode(graph, controller->current);
                            if (Graphu64_GetPointDistance(&node->platform->pos, &node->endpoint) < D_800C1BC8_de) {
                                controller->destination = node->platform->pos;
                                player->actionFlags |= 0x10;
                                controller->unk314 = 2;
                                return;
                            }
                            controller->destination = node->endpoint;
                            controller->unk310 = 1;
                        }
                        if (controller->unk314 == 2) {
                            riding = 0;
                            ground = func_8024E6A0_de(controller->player);
                            if (ground != 0) {
                                riding = ground->resource->kind == 2;
                            }
                            GraphU64_SubtractVectors(&delta, pos, &Portal_FindSearchNode(graph, controller->current)->platform->pos);
                            gap = Math_Sqrtf(delta.x * delta.x + delta.z * delta.z);
                            if (riding != 0 && gap < D_800C1BCC_de) {
                                controller->unk314 = 3;
                            } else {
                                controller->destination = Portal_FindSearchNode(graph, controller->current)->platform->pos;
                                return;
                            }
                        }
                        if (controller->unk314 == 3) {
                            riding = 0;
                            ground = func_8024E6A0_de(controller->player);
                            if (ground != 0) {
                                riding = ground->resource->kind == 2;
                            }
                            if (riding == 0) {
                                controller->unk314 = 0;
                            }
                            point = Portal_GetGraphPoint(graph, controller->queue[0]);
                            node = Portal_FindSearchNode(graph, controller->queue[0]);
                            if (Graphu64_GetPointDistance(&node->platform->pos, &node->endpoint) < D_800C1BD0_de) {
                                controller->destination = point->position;
                                player->actionFlags |= 0x10;
                            } else {
                                controller->destination = point->position;
                                controller->unk310 = 1;
                                return;
                            }
                        }
                    } else {
                        controller->unk314 = 0;
                    }
                } else {
                    controller->unk314 = 0;
                }
                if (controller->queue[1] == -1) {
                    reach = D_800C1BD8_de;
                } else {
                    reach = D_800C1BD4_de;
                    if (navigation_point_flags(point) & 0x100) {
                        reach = D_800C1BD8_de;
                    }
                }
                if (distance < reach && controller->current == controller->queue[0]) {
                    if (Scaled_AdvanceNodeQueue(controller) == 0) {
                        return;
                    }
                }
        } else {
            controller->unk300 = 1;
            return;
        }
    } else {
        controller->unk300 = 1;
        return;
    }
    if (controller->queue[0] != -1) {
        point = Portal_GetGraphPoint(graph, controller->queue[0]);
        if (navigation_point_flags(point) & 2) {
            controller->destination = controller->home;
            return;
        }
        controller->destination = point->position;
    }
}

extern f32 D_800C1BDC_de;
extern f32 D_800C1BE0_de;
extern f32 D_800C1BE4_de;
extern f32 D_800C1BE8_de;
extern f32 D_800C1BEC_de;
extern f32 D_800C1BF0_de;
extern f32 D_800C1BF4_de;
extern f32 D_800C1BF8_de;
extern f32 D_800C1BFC;

static __inline__ void navigationTurnLeft(CVector3 *v) {
    v->y = v->x;
    v->x = -v->z;
    v->z = v->y;
    v->y = 0.0f;
}
static __inline__ void navigationTurnRight(CVector3 *v) {
    v->y = v->x;
    v->x = v->z;
    v->z = -v->y;
    v->y = 0.0f;
}
void Nav_UpdatePlayerSteering(AiController *controller) {
    CNavData *graph;
    CVector3 delta;
    CVector3 desired;
    CVector3 facing;
    CVector3 tangent;
    CVector3 *destination;
    CVector3 *position;
    Player *player;
    f32 value;
    f32 angle;
    f32 distance;
    f32 projection;
    s32 jumping;
    s32 falling;

    if (controller->unk300 == 0) {
        destination = &controller->destination;
        jumping = controller->player->movementFlags & 0x2000;
        player = controller->player;
        position = &player->pos;
        falling = player->movementFlags & 0x1000;
        GraphU64_SubtractVectors(&delta, destination, position);
        distance = Math_Sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        graph = &D_8013B364;
        if (falling) {
            if (D_800C1BDC_de < distance) {
                angle = Nav_SteerTowardPoint(controller, destination, 2.0f, 0.0f);
                if (angle < 0.0f ? -angle < D_800C1BE0_de : angle < D_800C1BE4_de) {
                    player->forward = D_800C1BE8_de;
                }
                if ((jumping || falling) && controller->unk304) {
                    value = delta.y;
                    Scaled_SetPitchFromAngle(controller, XMath_EvaluateArcTangentTwo(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
                    player->forward = D_800C1BEC_de;
                }
            }
        } else {
            Nav_SteerTowardPoint(controller, destination, 2.0f, 0.0f);
            angle = controller->player->heading + D_800C1BF0_de;
            facing.x = Math_Sinf(angle);
            facing.y = 0.0f;
            facing.z = Math_Cosf(angle);
            angle = XMath_EvaluateArcTangentTwo(controller->destination.z - position->z, controller->destination.x - position->x);
            desired.x = Math_Cosf(angle);
            desired.y = 0.0f;
            desired.z = Math_Sinf(angle);
            player->forward = desired.x * facing.x + desired.y * facing.y + desired.z * facing.z;
            if (graph != 0 && controller->current != -1) {
                angle = 0.0f;
            }
            tangent = Portal_GetGraphPoint(graph, controller->current)->position;
            tangent.x -= controller->destination.x;
            tangent.z -= controller->destination.z;
            navigationTurnLeft(&tangent);
            value = XMath_EvaluateArcTangentTwo(tangent.z, tangent.x);
            tangent.x = Math_Cosf(value);
            tangent.z = Math_Sinf(value);
            projection = desired.x * tangent.x + desired.y * tangent.y + desired.z * tangent.z;
            tangent.x *= projection;
            tangent.z *= projection;
            navigationTurnRight(&facing);
            tangent.z = tangent.x * facing.x + tangent.z * facing.z;
            player->strafe = tangent.z;
        }
        if ((jumping || falling) && controller->unk304) {
            value = delta.y;
            Scaled_SetPitchFromAngle(controller, XMath_EvaluateArcTangentTwo(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
            player->forward = D_800C1BF4_de;
        }
        if (controller->player->pose == 0xF) {
            if (position->y > controller->destination.y) {
                player->forward = D_800C1BF8_de;
            } else {
                player->forward = D_800C1BFC;
            }
        }
        if (controller->unk310) {
            player->strafe = 0.0f;
            player->forward = 0.0f;
        }
    }
}

f32 Nav_SteerTowardPoint(Brain_func_80209308_de *, CVector3 *, f32, f32);

extern f32 D_800C1C00;
extern f32 D_800C1C04;
extern f32 D_800C1C08;
extern f32 D_800C1C0C;
extern f32 D_800C1C10;
extern f32 D_800C1C14;
extern f32 D_800C1C18;
extern f32 D_800C1C1C;
extern f32 D_800C1C20;

void Nav_UpdateTargetSteering(AiController *controller) {
    CNavData *graph;
    AiTarget *target;
    CVector3 delta;
    CVector3 desired;
    CVector3 facing;
    CVector3 tangent;
    CVector3 steer;
    CVector3 *destination;
    CVector3 *position;
    Player *player;
    f32 value;
    f32 angle;
    f32 distance;
    f32 projection;
    s32 jumping;
    s32 falling;

    target = controller->target;
    if (target == 0 || controller->unk308 != 0 || controller->unk30C != 0 || controller->unk314 != 0) {
        Nav_SteerTowardPoint(controller, &controller->destination, 2.0f, 0.0f);
    } else {
        Nav_SteerTowardPoint(controller, &target->player->pos, 2.0f, 0.0f);
        Portal_DispatchActorBehavior(controller);
    }
    if (controller->unk300 == 0) {
        destination = &controller->destination;
        jumping = controller->player->movementFlags & 0x2000;
        player = controller->player;
        position = &player->pos;
        falling = player->movementFlags & 0x1000;
        GraphU64_SubtractVectors(&delta, destination, position);
        distance = Math_Sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        graph = &D_8013B364;
        if (falling) {
            if (D_800C1C00 < distance) {
                angle = Nav_SteerTowardPoint(controller, destination, 2.0f, 0.0f);
                if (angle < 0.0f ? -angle < D_800C1C04 : angle < D_800C1C08) {
                    player->forward = D_800C1C0C;
                }
                if ((jumping || falling) && controller->unk304) {
                    value = delta.y;
                    Scaled_SetPitchFromAngle(controller, XMath_EvaluateArcTangentTwo(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
                    player->forward = D_800C1C10;
                }
            }
        } else {
            angle = controller->player->heading + D_800C1C14;
            facing.x = Math_Sinf(angle);
            facing.y = 0.0f;
            facing.z = Math_Cosf(angle);
            desired.x = controller->destination.x - position->x;
            desired.z = controller->destination.z - position->z;
            desired.y = 0.0f;
            if (graph != 0 && controller->current != -1) {
                angle = 0.0f;
            }
            tangent = Portal_GetGraphPoint(graph, controller->current)->position;
            tangent.x -= controller->destination.x;
            tangent.z -= controller->destination.z;
            navigationTurnLeft(&tangent);
            value = XMath_EvaluateArcTangentTwo(tangent.z, tangent.x);
            tangent.x = Math_Cosf(value);
            tangent.z = Math_Sinf(value);
            projection = desired.x * tangent.x + desired.y * tangent.y + desired.z * tangent.z;
            tangent.x *= projection;
            tangent.z *= projection;
            steer.x = desired.x + tangent.x;
            steer.y = 0.0f;
            steer.z = desired.z + tangent.z;
            GraphU64_NormalizeVec3(&steer);
            player->forward = steer.x * facing.x + steer.y * facing.y + steer.z * facing.z;
            navigationTurnRight(&facing);
            player->strafe = steer.x * facing.x + steer.z * facing.z;
        }
        if ((jumping || falling) && controller->unk304) {
            value = delta.y;
            Scaled_SetPitchFromAngle(controller, XMath_EvaluateArcTangentTwo(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
            player->forward = D_800C1C18;
        }
        if (controller->player->pose == 0xF) {
            if (position->y > controller->destination.y) {
                player->forward = D_800C1C1C;
            } else {
                player->forward = D_800C1C20;
            }
        }
        if (controller->unk310) {
            player->strafe = 0.0f;
            player->forward = 0.0f;
        }
    }
}

/* 80208000_3.CPP */
/* Steers a computer player toward a point: measures the heading error to the point through Barrel_GetSignedAngleToPoint plus an offset, wrapped to -pi..pi, and when it exceeds the turn rate in degrees sets the player's steering at 0x69C to full lock beyond 60 degrees or to a half, quarter, eighth or tenth of lock beyond 30, 10 and 4 degrees, in the error's direction; then passes the brain's speed sum (by the player's gear at 0x594) in radians and the turn rate to func_80209910_de and returns the heading error. */

extern f32 Barrel_GetSignedAngleToPoint(Player_func_80209308_de *, CVector3);
extern void Scaled_SetPitchFromAngle(Brain_func_80209308_de *, f32, s32);

const unsigned int D_auto_src_rw_pool_80208410_C78A8_us_rev1[9] = {
    0x42480000, 0x3E860A93, 0x3E860A93, 0x42480000, 0x42480000, 0x42480000, 0x42480000, 0x42C80000,
    0x41F00000,
};
#if !(defined(VERSION_US_REV1))
const unsigned int D_80208AAC_C78CC[9] = {
    0x41200000, 0x3E860A93, 0x3E860A93, 0x3F000000, 0x3F800000, 0x40490FDB, 0x3F800000, 0xBF800000,
    0x3F800000,
};
#endif
#if !(defined(VERSION_US_REV1))
const unsigned int D_80208EB0_C78F0[9] = {
    0x41200000, 0x3E860A93, 0x3E860A93, 0x3F000000, 0x3F800000, 0x40490FDB, 0x3F800000, 0xBF800000,
    0x3F800000,
};
#endif
#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_80208AAC_C78CC_us_rev1[9] = {
    0x41200000, 0x3E860A93, 0x3E860A93, 0x3F000000, 0x3F800000, 0x40490FDB, 0x3F800000, 0xBF800000,
    0x3F800000,
};
#endif
#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_80208EB0_C78F0_us_rev1[9] = {
    0x41200000, 0x3E860A93, 0x3E860A93, 0x3F000000, 0x3F800000, 0x40490FDB, 0x3F800000, 0xBF800000,
    0x3F800000,
};
#endif
f32 Nav_SteerTowardPoint(Brain_func_80209308_de *brain, CVector3 *target, f32 rate, f32 offset) {
    f32 angle;
    f32 direction;
    f32 limit;
    f32 scale;

    angle = Barrel_GetSignedAngleToPoint(brain->player, *target) + offset;
    if (angle > 3.141593f) {
        angle -= 6.283186f;
    } else if (angle < -3.141593f) {
        angle += 6.283186f;
    }
    direction = -1.0f;
    if (angle > 0.0f) {
        direction = 1.0f;
    }
    limit = rate * 0.017453294f;
    if (angle < 0.0f ? limit < -angle : limit < angle) {
        if (angle < 0.0f ? 1.0471977f < -angle : 1.0471977f < angle) {
            brain->player->steer = direction;
        } else {
            if (angle < 0.0f ? 0.52359885f < -angle : 0.52359885f < angle) {
                scale = 0.5f;
            } else if (angle < 0.0f ? 0.17453295f < -angle : 0.17453295f < angle) {
                scale = 0.25f;
            } else if (angle < 0.0f ? 0.06981318f < -angle : 0.06981318f < angle) {
                scale = 0.125f;
            } else {
                scale = 0.1f;
            }
            brain->player->steer = direction * scale;
        }
    }
    Scaled_SetPitchFromAngle(brain, (brain->player->gear == 2 ? brain->speed[1] + brain->speed[3] : brain->speed[0] + brain->speed[2]) * 0.017453294f, rate);
    return angle;
}

/* 800C6CA8.CPP */

/* 800C6CCC.CPP */

/* 800C6CF0.CPP */

/* 800C6D64.CPP */
const unsigned int D_auto_src_rw_pool_802095F8_C7964_us_rev1[5] = {
    0x3F666666, 0x3F333333, 0xC2B40000, 0x42B40000, 0x42652EE0,
};

/* 800C6D78.CPP */
/* ROM-grounded data: src/rw_pool_80209910_C7978_us_rev1.c */
const unsigned int D_blob_0e77fd4c639ef9183fe4[1] = {
    0x3F22F982,
};

/* 800C6D7C.CPP */
/* ROM-grounded data: src/rw_pool_802099B4_C797C_us_rev1.c */
const unsigned int D_blob_789de96649ad15205aab[1] = {
    0x42CCCCCC,
};

/* 800C6D80.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80209AE8_C7980[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80209AE8_C7980_us_rev1.c */
const unsigned int D_blob_6e292876e4716f614682[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

/* 800C6D8C.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80209B64_C798C[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80209B64_C798C_us_rev1.c */
const unsigned int D_blob_0db9d39470b972d797f5[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

/* 800C6D98.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80209BE0_C7998[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_528874f1c086d773[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

/* 800C6DA4.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80209C5C_C79A4[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80209C5C_C79A4_us_rev1.c */
const unsigned int D_blob_f0806fafd081e266cae3[3] = {
    0x3C23D70A, 0x3F666666, 0x3F8CCCCD,
};
#endif

/* 800C6DB0_2.CPP */
/* ROM-grounded data: src/rw_pool_80209DAC_C79B0_us_rev1.c */
const unsigned int D_blob_a2d7485e1df5f3becc88[2] = {
    0x3E860A93, 0x3E860A93,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C1BF8[2] = {
    0x001C0000, 0x00080008,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C1FA8[2] = {
    0x00229F54, 0x3B800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C1F68[2] = {
    0x1440FFFD, 0x00000000,
};
#endif
