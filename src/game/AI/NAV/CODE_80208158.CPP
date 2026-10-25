#include "COMMON/NAVIGATION_GRAPH.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "FX_2/80271B18.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
#include "AI/NAV/CODE_80208158.H"

/* Updates a computer player's brain for the frame: fixes its route start, runs its planner through func_802095F8_de and its state callback, counts down its cooldown at 0x324, and for a displayed player sets the health meter from its health over the character's maximum (400 for kinds 11 and 12, 300 for 13 and 14, otherwise func_8022AC00_de), as a percentage, rescaled for kind 14 by the difficulty D_8014693C; in the tutorial (D_801468A0) kind 11 also shows the timer and refills its ammunition, then the meter is drawn through func_802AA794_de or func_802AA79C_de; finally it restarts a stalled player (state 0x12) through func_80209CD8_de. */









extern char D_801376F8[];


extern void func_802095F8_de(Brain *);
extern s32 func_8022AC00_de(SharedPlayer_func_80208158_de *);
extern void func_802AA79C_de(char *, s32);
extern void Fx_ClearControllerInput(char *);
extern void Weapons_SetPlayerState(SharedPlayer_func_80208158_de *, SharedPlayer_func_80208158_de *, s32);
extern void func_80209CD8_de(Brain *, SharedPlayer_func_80208158_de *);

void func_80208158_de(Brain *brain) {
    s32 health;
    s32 maximum;
    f32 meter;
    s32 kind;
    CGameStatus *tutorial;
    SharedPlayer_func_80208158_de *player;

    if (brain->player->views1450.view1450_1.computer == 0) {
        return;
    }
    if (brain->route == -1) {
        brain->route = brain->start;
    }
    func_802095F8_de(brain);
    if (brain->behaviour->update != 0) {
        brain->behaviour->update(brain->player, 0);
    }
    if (brain->cooldown > 0) {
        brain->cooldown--;
    }
    if (brain->player->views5D8.view5D8_1.record->display != 0) {
        health = brain->player->views5E4.view5E4_2.health >> 8;
        kind = brain->player->views5D8.view5D8_1.record->kind;
        if (kind == 11) {
            maximum = 400;
        } else if (kind == 12) {
            maximum = 400;
        } else if (kind == 14) {
            maximum = 300;
        } else if (kind == 13) {
            maximum = 300;
        } else {
            maximum = func_8022AC00_de(brain->player) >> 8;
        }
        meter = (f32)health / (f32)maximum * 100.0f;
        if (brain->player->views5D8.view5D8_1.record->kind == 14) {
            if (meter == 0.0f) {
                meter = (3 - D_801462C8.counters.unk9C) * 33;
            } else {
                meter *= 0.33333334f;
                meter += (2 - D_801462C8.counters.unk9C) * 33;
            }
            if (meter < 0.0f) {
                meter = 0.0f;
            }
        }
        tutorial = &D_801462C8.counters;
        if (tutorial->enabled != 0) {
            if (brain->player->views5D8.view5D8_1.record->kind == 11) {
                func_802AA794_de(D_801376F8, (f32)tutorial->timer);
                if (tutorial->cooldown > 0) {
                    tutorial->cooldown--;
                    Fx_ClearControllerInput((char *)brain->player + 0x688);
                    brain->w23C = 0;
                    brain->w240 = 0;
                }
                if (tutorial->cooldown == 0 && brain->player->views5E4.view5E4_2.health > 0) {
                    tutorial->timer = 100;
                    tutorial->cooldown = -1;
                    Weapons_SetPlayerState(brain->player, brain->player, 2);
                }
            }
            if (brain->player->views5D8.view5D8_1.record->display == 1) {
                func_802AA794_de(D_801376F8, meter);
            } else {
                func_802AA79C_de(D_801376F8, meter);
            }
        }
    }
    player = brain->player;
    if (player->views5E8.view650_16.state == 0x12) {
        player->views1340.view1340_1.stalls++;
        func_80209CD8_de(brain, player);
    }
}

extern CNavData D_8013B364;
float Particle_GetPointDistance(void *, void *);
void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
float Nav_SteerTowardPoint(AiController *, CVector3 *,float,float);
void Nav_SetPitchFromAngle(AiController *,float,s32);
void func_80209E80_de(AiController *);
float Math_Sqrtf(float);
NavigationPoint *Nav_GetGraphPoint(CNavData *,s32);
NavigationPortal *func_8020C9B0_de(CNavData *,s32);
NavigationSearchNode *Nav_FindSearchNode(CNavData *,s32);
s32 Nav_FindLinkIndex(CNavData *,s32,s32);
s32 func_80209828_de(AiController *);
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
                point = Nav_GetGraphPoint(graph, controller->queue[0]);
                pos = &controller->player->pos;
                distance = Particle_GetPointDistance(pos, point);
                controller->unk304 = (navigation_attributes(point) & 0x300000) != 0;
                if (controller->queue[0] == controller->current) {
                    link = Nav_FindLinkIndex(graph, controller->previous, controller->queue[0]);
                } else {
                    link = Nav_FindLinkIndex(graph, controller->current, controller->queue[0]);
                }
                if (link > 0) {
                    portal = func_8020C9B0_de(graph, link);
                    if (portal->kind == 4) {
                        controller->unk30C = 1;
                    }
                    if (portal->kind == 8) {
                        Particle_GetPointDistance(pos, Nav_GetGraphPoint(graph, controller->current));
                        goal = Nav_GetGraphPoint(graph, controller->queue[0]);
                        controller->unk308 = 1;
                        if (link != controller->unk32C) {
                            controller->unk314 = 0;
                            controller->unk32C = link;
                        }
                        if (controller->unk314 == 0) {
                            start = Nav_GetGraphPoint(graph, controller->current);
                            Particle_SubtractVectors(&delta, pos, &start->position);
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
                            entry = Nav_GetGraphPoint(graph, controller->current);
                            if (!(Particle_GetPointDistance(pos, entry) < D_800C1BC4_de)) {
                                controller->destination = entry->position;
                                return;
                            }
                            controller->unk314 = 1;
                        }
                        if (controller->unk314 == 1) {
                            node = Nav_FindSearchNode(graph, controller->current);
                            if (Particle_GetPointDistance(&node->platform->pos, &node->endpoint) < D_800C1BC8_de) {
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
                            Particle_SubtractVectors(&delta, pos, &Nav_FindSearchNode(graph, controller->current)->platform->pos);
                            gap = Math_Sqrtf(delta.x * delta.x + delta.z * delta.z);
                            if (riding != 0 && gap < D_800C1BCC_de) {
                                controller->unk314 = 3;
                            } else {
                                controller->destination = Nav_FindSearchNode(graph, controller->current)->platform->pos;
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
                            point = Nav_GetGraphPoint(graph, controller->queue[0]);
                            node = Nav_FindSearchNode(graph, controller->queue[0]);
                            if (Particle_GetPointDistance(&node->platform->pos, &node->endpoint) < D_800C1BD0_de) {
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
                    if (func_80209828_de(controller) == 0) {
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
        point = Nav_GetGraphPoint(graph, controller->queue[0]);
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
        Particle_SubtractVectors(&delta, destination, position);
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
                    Nav_SetPitchFromAngle(controller, func_8029C044_de(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
                    player->forward = D_800C1BEC_de;
                }
            }
        } else {
            Nav_SteerTowardPoint(controller, destination, 2.0f, 0.0f);
            angle = controller->player->heading + D_800C1BF0_de;
            facing.x = Math_Sinf(angle);
            facing.y = 0.0f;
            facing.z = Math_Cosf(angle);
            angle = func_8029C044_de(controller->destination.z - position->z, controller->destination.x - position->x);
            desired.x = Math_Cosf(angle);
            desired.y = 0.0f;
            desired.z = Math_Sinf(angle);
            player->forward = desired.x * facing.x + desired.y * facing.y + desired.z * facing.z;
            if (graph != 0 && controller->current != -1) {
                angle = 0.0f;
            }
            tangent = Nav_GetGraphPoint(graph, controller->current)->position;
            tangent.x -= controller->destination.x;
            tangent.z -= controller->destination.z;
            navigationTurnLeft(&tangent);
            value = func_8029C044_de(tangent.z, tangent.x);
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
            Nav_SetPitchFromAngle(controller, func_8029C044_de(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
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

#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
extern CNavData D_8013B364;
float Particle_GetPointDistance(void *, void *);
void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
float Nav_SteerTowardPoint(AiController *, CVector3 *,float,float);
void Nav_SetPitchFromAngle(AiController *,float,s32);
void func_80209E80_de(AiController *);
float Math_Sqrtf(float);
NavigationPoint *Nav_GetGraphPoint(CNavData *,s32);
NavigationPortal *func_8020C9B0_de(CNavData *,s32);
NavigationSearchNode *Nav_FindSearchNode(CNavData *,s32);
s32 Nav_FindLinkIndex(CNavData *,s32,s32);
s32 func_80209828_de(AiController *);

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
        func_80209E80_de(controller);
    }
    if (controller->unk300 == 0) {
        destination = &controller->destination;
        jumping = controller->player->movementFlags & 0x2000;
        player = controller->player;
        position = &player->pos;
        falling = player->movementFlags & 0x1000;
        Particle_SubtractVectors(&delta, destination, position);
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
                    Nav_SetPitchFromAngle(controller, func_8029C044_de(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
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
            tangent = Nav_GetGraphPoint(graph, controller->current)->position;
            tangent.x -= controller->destination.x;
            tangent.z -= controller->destination.z;
            navigationTurnLeft(&tangent);
            value = func_8029C044_de(tangent.z, tangent.x);
            tangent.x = Math_Cosf(value);
            tangent.z = Math_Sinf(value);
            projection = desired.x * tangent.x + desired.y * tangent.y + desired.z * tangent.z;
            tangent.x *= projection;
            tangent.z *= projection;
            steer.x = desired.x + tangent.x;
            steer.y = 0.0f;
            steer.z = desired.z + tangent.z;
            Particle_NormalizeVec3(&steer);
            player->forward = steer.x * facing.x + steer.y * facing.y + steer.z * facing.z;
            navigationTurnRight(&facing);
            player->strafe = steer.x * facing.x + steer.z * facing.z;
        }
        if ((jumping || falling) && controller->unk304) {
            value = delta.y;
            Nav_SetPitchFromAngle(controller, func_8029C044_de(value, Math_Sqrtf(delta.x * delta.x + delta.z * delta.z)), 1);
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
