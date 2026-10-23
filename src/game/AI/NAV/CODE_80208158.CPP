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
extern void func_802636B0_de(char *);
extern void func_802227F4_de(SharedPlayer_func_80208158_de *, SharedPlayer_func_80208158_de *, s32);
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
                meter = (3 - D_8014693C) * 33;
            } else {
                meter *= 0.33333334f;
                meter += (2 - D_8014693C) * 33;
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
                    func_802636B0_de((char *)brain->player + 0x688);
                    brain->w23C = 0;
                    brain->w240 = 0;
                }
                if (tutorial->cooldown == 0 && brain->player->views5E4.view5E4_2.health > 0) {
                    tutorial->timer = 100;
                    tutorial->cooldown = -1;
                    func_802227F4_de(brain->player, brain->player, 2);
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
float func_802726F8_de(void *, void *);
void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
float func_80209308_de(AiController *, CVector3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(CNavData *,s32);
NavigationPortal *func_8020C9B0_de(CNavData *,s32);
NavigationSearchNode *func_8020CFE0_de(CNavData *,s32);
s32 func_8020CC0C_de(CNavData *,s32,s32);
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
                point = func_8020C994_de(graph, controller->queue[0]);
                pos = &controller->player->pos;
                distance = func_802726F8_de(pos, point);
                controller->unk304 = (navigation_attributes(point) & 0x300000) != 0;
                if (controller->queue[0] == controller->current) {
                    link = func_8020CC0C_de(graph, controller->previous, controller->queue[0]);
                } else {
                    link = func_8020CC0C_de(graph, controller->current, controller->queue[0]);
                }
                if (link > 0) {
                    portal = func_8020C9B0_de(graph, link);
                    if (portal->kind == 4) {
                        controller->unk30C = 1;
                    }
                    if (portal->kind == 8) {
                        func_802726F8_de(pos, func_8020C994_de(graph, controller->current));
                        goal = func_8020C994_de(graph, controller->queue[0]);
                        controller->unk308 = 1;
                        if (link != controller->unk32C) {
                            controller->unk314 = 0;
                            controller->unk32C = link;
                        }
                        if (controller->unk314 == 0) {
                            start = func_8020C994_de(graph, controller->current);
                            func_80271F68_de(&delta, pos, &start->position);
                            if (!(func_802B72B0_de(delta.x * delta.x + delta.z * delta.z) < D_800C1BB8_de)) {
                                controller->destination = start->position;
                                return;
                            }
                            controller->unk314 = 1;
                        }
                        if (controller->unk314 == 1) {
                            controller->destination = goal->position;
                            offset = func_80209308_de(controller, &controller->destination, 2.0f, 0.0f);
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
                            entry = func_8020C994_de(graph, controller->current);
                            if (!(func_802726F8_de(pos, entry) < D_800C1BC4_de)) {
                                controller->destination = entry->position;
                                return;
                            }
                            controller->unk314 = 1;
                        }
                        if (controller->unk314 == 1) {
                            node = func_8020CFE0_de(graph, controller->current);
                            if (func_802726F8_de(&node->platform->pos, &node->endpoint) < D_800C1BC8_de) {
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
                            func_80271F68_de(&delta, pos, &func_8020CFE0_de(graph, controller->current)->platform->pos);
                            gap = func_802B72B0_de(delta.x * delta.x + delta.z * delta.z);
                            if (riding != 0 && gap < D_800C1BCC_de) {
                                controller->unk314 = 3;
                            } else {
                                controller->destination = func_8020CFE0_de(graph, controller->current)->platform->pos;
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
                            point = func_8020C994_de(graph, controller->queue[0]);
                            node = func_8020CFE0_de(graph, controller->queue[0]);
                            if (func_802726F8_de(&node->platform->pos, &node->endpoint) < D_800C1BD0_de) {
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
        point = func_8020C994_de(graph, controller->queue[0]);
        if (navigation_point_flags(point) & 2) {
            controller->destination = controller->home;
            return;
        }
        controller->destination = point->position;
    }
}

#ifdef NON_MATCHING
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
extern CNavData D_8013B364;
float func_802726F8_de(void *, void *);
void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
float func_80209308_de(AiController *, CVector3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(CNavData *,s32);
NavigationPortal *func_8020C9B0_de(CNavData *,s32);
NavigationSearchNode *func_8020CFE0_de(CNavData *,s32);
s32 func_8020CC0C_de(CNavData *,s32,s32);
s32 func_80209828_de(AiController *);

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
/* 76/257 aligned edits; remaining: saved-register allocation and float scheduling. */
void Nav_UpdatePlayerSteering(AiController *controller) {
    CNavData *graph = &D_8013B364;
    CVector3 delta;
    CVector3 desired;
    CVector3 facing;
    CVector3 tangent;
    CVector3 *destination;
    CVector3 *position;
    Player *player;
    f32 value;
    f32 distance;
    f32 projection;
    s32 jumping;
    s32 falling;

    if (controller->unk300 == 0) {
        destination = &controller->destination;
        player = controller->player;
        position = &controller->player->pos;
        jumping = player->movementFlags & 0x2000;
        falling = player->movementFlags & 0x1000;
        func_80271F68_de(&delta, destination, position);
        distance = func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        if (falling) {
            if (D_800C1BDC_de < distance) {
                f32 angle;
                value = 0.0f;
                angle = func_80209308_de(controller, destination, 2.0f, value);
                if (angle < value ? -angle < D_800C1BE0_de : angle < D_800C1BE4_de) {
                    player->forward = D_800C1BE8_de;
                }
                if ((jumping || falling) && controller->unk304) {
                    value = delta.y;
                    func_80209910_de(controller, func_8029C044_de(value, func_802B72B0_de(delta.x * delta.x + delta.z * delta.z)), 1);
                    player->forward = D_800C1BEC_de;
                }
            }
        } else {
            f32 angle;
            value = 0.0f;
            func_80209308_de(controller, destination, 2.0f, value);
            angle = controller->player->heading + D_800C1BF0_de;
            facing.x = func_802B7130_de(angle);
            facing.y = value;
            facing.z = func_802B6560_de(angle);
            angle = func_8029C044_de(controller->destination.z - position->z, controller->destination.x - position->x);
            desired.x = func_802B6560_de(angle);
            desired.y = value;
            desired.z = func_802B7130_de(angle);
            player->forward = desired.x * facing.x + desired.y * facing.y + desired.z * facing.z;
            tangent = func_8020C994_de(graph, controller->current)->position;
            tangent.x -= controller->destination.x;
            tangent.z -= controller->destination.z;
            navigationTurnLeft(&tangent);
            value = func_8029C044_de(tangent.z, tangent.x);
            tangent.x = func_802B6560_de(value);
            tangent.z = func_802B7130_de(value);
            projection = desired.x * tangent.x + desired.y * tangent.y + desired.z * tangent.z;
            tangent.x *= projection;
            tangent.z *= projection;
            navigationTurnRight(&facing);
            tangent.z = tangent.x * facing.x + tangent.z * facing.z;
            player->strafe = tangent.z;
        }
        if ((jumping || falling) && controller->unk304) {
            value = delta.y;
            func_80209910_de(controller, func_8029C044_de(value, func_802B72B0_de(delta.x * delta.x + delta.z * delta.z)), 1);
            player->forward = D_800C1BF4_de;
        }
        if (controller->player->pose == 0xF) {
            if (controller->destination.y < position->y) {
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
#else
INCLUDE_ASM("span_1000", Nav_UpdatePlayerSteering);
#endif

#ifdef NON_MATCHING
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
extern CNavData D_8013B364;
float func_802726F8_de(void *, void *);
void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
float func_80209308_de(AiController *, CVector3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(CNavData *,s32);
NavigationPortal *func_8020C9B0_de(CNavData *,s32);
NavigationSearchNode *func_8020CFE0_de(CNavData *,s32);
s32 func_8020CC0C_de(CNavData *,s32,s32);
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

void func_80208EB0_de(AiController *controller) {
    CNavData *graph;
    CVector3 *playerPosition;
    CVector3 sp10;
    CVector3 v20;
    CVector3 v30;
    CVector3 v40;
    CVector3 extra;
    AiTarget *temp_v1;
    NavigationPoint *temp_v0_3;
    Player *temp_v0;
    CVector3 *temp_s2;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0f;
    f32 temp_ft0;
    f32 value;
    f32 temp_fv0_2;
    f32 temp_fv0_4;
    f32 temp_fv0_5;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1f;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_v0_2;

    temp_v1 = controller->target;
    if (temp_v1 == 0) {
        goto block_6;
    }
    if ((controller->unk308 != 0) || (controller->unk30C != 0) || (controller->unk314 != 0)) {
block_6:
        func_80209308_de(controller, &controller->destination, 2.0f, 0.0f);
    } else {
        func_80209308_de(controller, &temp_v1->player->pos, 2.0f, 0.0f);
        func_80209E80_de(controller);
    }
    if (controller->unk300 == 0) {
        temp_s2 = &controller->destination;
        temp_v0 = controller->player;
        playerPosition = &temp_v0->pos;
        temp_v0_2 = temp_v0->movementFlags;
        temp_s6 = temp_v0_2 & 0x2000;
        temp_s4 = temp_v0_2 & 0x1000;
        func_80271F68_de(&sp10, temp_s2, playerPosition);
        temp_fv0f = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
        graph = &D_8013B364;
        if (temp_s4 != 0) {
            if (D_800C1C00 < temp_fv0f) {
                value = 0.0f;
                temp_fs0f = func_80209308_de(controller, temp_s2, 2.0f, value);
                if (temp_fs0f < value) {
                    if (-temp_fs0f < D_800C1C04) {
                        goto block_15;
                    }
                } else if (temp_fs0f < D_800C1C08) {
block_15:
                    temp_v0->forward = D_800C1C0C;
                }
                if (((temp_s6 != 0) || (temp_s4 != 0)) && (controller->unk304 != 0)) {
                    value = sp10.y;
                    func_80209910_de(controller, func_8029C044_de(value, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
                    temp_v0->forward = D_800C1C10;
                }
            }
        } else {
            temp_fs0f = controller->player->heading + D_800C1C14;
            v30.x = func_802B7130_de(temp_fs0f);
            v30.y = 0.0f;
            v30.z = func_802B6560_de(temp_fs0f);
            v20.x = controller->destination.x - playerPosition->x;
            v20.y = 0.0f;
            v20.z = controller->destination.z - playerPosition->z;
            temp_v0_3 = func_8020C994_de(graph, controller->current);
            v40 = temp_v0_3->position;
            v40.x -= controller->destination.x;
            v40.z -= controller->destination.z;
            navigationTurnLeft(&v40);
            value = func_8029C044_de(v40.z, v40.x);
            v40.x = func_802B6560_de(value);
            temp_fv0_4 = func_802B7130_de(value);
            temp_fv1 = (v20.x * v40.x) + (v20.y * v40.y) + (v20.z * temp_fv0_4);
            temp_ft0 = v40.x * temp_fv1;
            temp_fv1_2 = temp_fv0_4 * temp_fv1;
            v40.z = temp_fv0_4;
            extra.y = 0.0f;
            v40.x = temp_ft0;
            v40.z = temp_fv1_2;
            extra.x = v20.x + temp_ft0;
            extra.z = v20.z + temp_fv1_2;
            func_8027207C_de(&extra);
            temp_v0->forward = (extra.x * v30.x) + (extra.y * v30.y) + (extra.z * v30.z);
            navigationTurnRight(&v30);
            temp_v0->strafe = extra.x * v30.x + extra.z * v30.z;
        }
        if (((temp_s6 != 0) || (temp_s4 != 0)) && (controller->unk304 != 0)) {
            value = sp10.y;
                    func_80209910_de(controller, func_8029C044_de(value, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
            temp_v0->forward = D_800C1C18;
        }
        if (controller->player->pose == 0xF) {
            if (controller->destination.y < playerPosition->y) {
                temp_v0->forward = D_800C1C1C;
            } else {
                temp_v0->forward = D_800C1C20;
            }
        }
        if (controller->unk310 != 0) {
            temp_v0->strafe = 0.0f;
            temp_v0->forward = 0.0f;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_80208EB0_de);
#endif
