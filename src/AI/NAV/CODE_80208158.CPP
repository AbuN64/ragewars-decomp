#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "FX_2/80271B18.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"

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
    RenderCounters *tutorial;
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

extern NavigationGraph D_8013B364;
float func_802726F8_de(void *, void *);
void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
float func_80209308_de(AiController *, CVector3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(NavigationGraph *,s32);
NavigationPortal *func_8020C9B0_de(NavigationGraph *,s32);
NavigationSearchNode *func_8020CFE0_de(NavigationGraph *,s32);
s32 func_8020CC0C_de(NavigationGraph *,s32,s32);
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
void Nav_SteerAlongRoute(AiController *arg0) {
    NavigationGraph *graph = &D_8013B364;
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

    player = arg0->player;
    if (arg0->mode != -1) {
        arg0->unk300 = 0;
        arg0->unk310 = 0;
        arg0->unk304 = 0;
        arg0->unk308 = 0;
        arg0->unk30C = 0;
        if (arg0->queue[0] != -1) {
                point = func_8020C994_de(graph, arg0->queue[0]);
                pos = &arg0->player->pos;
                distance = func_802726F8_de(pos, point);
                arg0->unk304 = (navigation_attributes(point) & 0x300000) != 0;
                if (arg0->queue[0] == arg0->current) {
                    link = func_8020CC0C_de(graph, arg0->previous, arg0->queue[0]);
                } else {
                    link = func_8020CC0C_de(graph, arg0->current, arg0->queue[0]);
                }
                if (link > 0) {
                    portal = func_8020C9B0_de(graph, link);
                    if (portal->kind == 4) {
                        arg0->unk30C = 1;
                    }
                    if (portal->kind == 8) {
                        func_802726F8_de(pos, func_8020C994_de(graph, arg0->current));
                        goal = func_8020C994_de(graph, arg0->queue[0]);
                        arg0->unk308 = 1;
                        if (link != arg0->unk32C) {
                            arg0->unk314 = 0;
                            arg0->unk32C = link;
                        }
                        if (arg0->unk314 == 0) {
                            start = func_8020C994_de(graph, arg0->current);
                            func_80271F68_de(&delta, pos, &start->position);
                            if (!(func_802B72B0_de(delta.x * delta.x + delta.z * delta.z) < D_800C1BB8_de)) {
                                arg0->destination = start->position;
                                return;
                            }
                            arg0->unk314 = 1;
                        }
                        if (arg0->unk314 == 1) {
                            arg0->destination = goal->position;
                            offset = func_80209308_de(arg0, &arg0->destination, 2.0f, 0.0f);
                            if (offset < 0.0f ? D_800C1BBC_de < -offset : D_800C1BC0_de < offset) {
                                arg0->unk310 = 1;
                                return;
                            }
                            arg0->unk314 = 2;
                        }
                        if (arg0->unk314 == 2) {
                            arg0->destination = goal->position;
                            arg0->unk314 = 3;
                            return;
                        }
                        if (arg0->unk314 == 3) {
                            arg0->destination = goal->position;
                            arg0->unk314 = 4;
                            return;
                        }
                        if (arg0->unk314 == 4) {
                            arg0->destination = goal->position;
                            arg0->unk314 = 5;
                            return;
                        }
                        if (arg0->unk314 == 5) {
                            arg0->destination = goal->position;
                            player->actionFlags |= 0x10;
                            arg0->unk314 = 6;
                            return;
                        }
                        if (arg0->unk314 == 6) {
                            {
                            s32 jumping, falling;
                            moving = arg0->player->movementFlags;
                            jumping = moving & 0x2000;
                            falling = moving & 0x1000;
                            if (jumping || falling) {
                                arg0->unk314 = 2;
                            }
                            }
                            arg0->destination = goal->position;
                        }
                    } else if (portal->kind == 5) {
                        if (arg0->unk314 == 0) {
                            entry = func_8020C994_de(graph, arg0->current);
                            if (!(func_802726F8_de(pos, entry) < D_800C1BC4_de)) {
                                arg0->destination = entry->position;
                                return;
                            }
                            arg0->unk314 = 1;
                        }
                        if (arg0->unk314 == 1) {
                            node = func_8020CFE0_de(graph, arg0->current);
                            if (func_802726F8_de(&node->platform->pos, &node->endpoint) < D_800C1BC8_de) {
                                arg0->destination = node->platform->pos;
                                player->actionFlags |= 0x10;
                                arg0->unk314 = 2;
                                return;
                            }
                            arg0->destination = node->endpoint;
                            arg0->unk310 = 1;
                        }
                        if (arg0->unk314 == 2) {
                            riding = 0;
                            ground = func_8024E6A0_de(arg0->player);
                            if (ground != 0) {
                                riding = ground->resource->kind == 2;
                            }
                            func_80271F68_de(&delta, pos, &func_8020CFE0_de(graph, arg0->current)->platform->pos);
                            gap = func_802B72B0_de(delta.x * delta.x + delta.z * delta.z);
                            if (riding != 0 && gap < D_800C1BCC_de) {
                                arg0->unk314 = 3;
                            } else {
                                arg0->destination = func_8020CFE0_de(graph, arg0->current)->platform->pos;
                                return;
                            }
                        }
                        if (arg0->unk314 == 3) {
                            riding = 0;
                            ground = func_8024E6A0_de(arg0->player);
                            if (ground != 0) {
                                riding = ground->resource->kind == 2;
                            }
                            if (riding == 0) {
                                arg0->unk314 = 0;
                            }
                            point = func_8020C994_de(graph, arg0->queue[0]);
                            node = func_8020CFE0_de(graph, arg0->queue[0]);
                            if (func_802726F8_de(&node->platform->pos, &node->endpoint) < D_800C1BD0_de) {
                                arg0->destination = point->position;
                                player->actionFlags |= 0x10;
                            } else {
                                arg0->destination = point->position;
                                arg0->unk310 = 1;
                                return;
                            }
                        }
                    } else {
                        arg0->unk314 = 0;
                    }
                } else {
                    arg0->unk314 = 0;
                }
                if (arg0->queue[1] == -1) {
                    reach = D_800C1BD8_de;
                } else {
                    reach = D_800C1BD4_de;
                    if (point->flags & 0x100) {
                        reach = D_800C1BD8_de;
                    }
                }
                if (distance < reach && arg0->current == arg0->queue[0]) {
                    if (func_80209828_de(arg0) == 0) {
                        return;
                    }
                }
        } else {
            arg0->unk300 = 1;
            return;
        }
    } else {
        arg0->unk300 = 1;
        return;
    }
    if (arg0->queue[0] != -1) {
        point = func_8020C994_de(graph, arg0->queue[0]);
        if (point->flags & 2) {
            arg0->destination = arg0->home;
            return;
        }
        arg0->destination = point->position;
    }
}

#ifdef NON_MATCHING
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
extern NavigationGraph D_8013B364;
float func_802726F8_de(void *, void *);
void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
float func_80209308_de(AiController *, CVector3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(NavigationGraph *,s32);
NavigationPortal *func_8020C9B0_de(NavigationGraph *,s32);
NavigationSearchNode *func_8020CFE0_de(NavigationGraph *,s32);
s32 func_8020CC0C_de(NavigationGraph *,s32,s32);
s32 func_80209828_de(AiController *);
typedef struct GroundObject { char pad[0x18]; ActorMotionResource *resource; } GroundObject;
GroundObject *func_8024E6A0_de(Player *);

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
void func_80208AAC_de(AiController *arg0) {
    NavigationGraph *graph;
    CVector3 *playerPosition;
    CVector3 sp10;
    CVector3 v20;
    CVector3 v30;
    CVector3 v40;
    NavigationPoint *temp_v0_3;
    Player *temp_v0;
    CVector3 *temp_s0;
    f32 temp_fa0;
    f32 temp_fa1;
    f32 temp_fs0f;
    f32 temp_ft0;
    f32 temp_ft1;
    f32 value;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0_6;
    f32 temp_fv0_7;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv0f_3;
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1f;
    s32 temp_s3;
    s32 temp_s6;
    s32 temp_v0_2;

    if (arg0->unk300 == 0) {
        temp_s0 = &arg0->destination;
        temp_v0 = arg0->player;
        playerPosition = &temp_v0->pos;
        temp_v0_2 = temp_v0->movementFlags;
        temp_s6 = temp_v0_2 & 0x2000;
        temp_s3 = temp_v0_2 & 0x1000;
        func_80271F68_de(&sp10, temp_s0, playerPosition);
        temp_fv0f = func_802B72B0_de((sp10.x * sp10.x) + (sp10.y * sp10.y) + (sp10.z * sp10.z));
        graph = &D_8013B364;
        if (temp_s3 != 0) {
            if (D_800C1BDC_de < temp_fv0f) {
                value = 0.0f;
                temp_fs0f = func_80209308_de(arg0, temp_s0, 2.0f, value);
                if (temp_fs0f < value) {
                    if (-temp_fs0f < D_800C1BE0_de) {
                        goto block_7;
                    }
                } else if (temp_fs0f < D_800C1BE4_de) {
block_7:
                    temp_v0->forward = D_800C1BE8_de;
                }
                if (((temp_s6 != 0) || (temp_s3 != 0)) && (arg0->unk304 != 0)) {
                    value = sp10.y;
                    func_80209910_de(arg0, func_8029C044_de(value, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
                    temp_v0->forward = D_800C1BEC_de;
                }
            }
        } else {
            value = 0.0f;
            func_80209308_de(arg0, temp_s0, 2.0f, value);
            temp_fs0f = arg0->player->heading + D_800C1BF0_de;
            v30.x = func_802B7130_de(temp_fs0f);
            v30.y = value;
            v30.z = func_802B6560_de(temp_fs0f);
            temp_fs0f = func_8029C044_de(arg0->destination.z - playerPosition->z, arg0->destination.x - playerPosition->x);
            v20.x = func_802B6560_de(temp_fs0f);
            v20.y = value;
            temp_fv0_3 = func_802B7130_de(temp_fs0f);
            v20.z = temp_fv0_3;
            temp_v0->forward = (v20.x * v30.x) + (v20.y * v30.y) + (temp_fv0_3 * v30.z);
            temp_v0_3 = func_8020C994_de(graph, arg0->current);
            v40 = temp_v0_3->position;
            v40.x -= arg0->destination.x;
            v40.z -= arg0->destination.z;
            navigationTurnLeft(&v40);
            value = func_8029C044_de(v40.z, v40.x);
            v40.x = func_802B6560_de(value);
            temp_fv0_6 = func_802B7130_de(value);
            temp_fv1 = (v20.x * v40.x) + (v20.y * v40.y) + (v20.z * temp_fv0_6);
            temp_ft0 = v40.x * temp_fv1;
            temp_fv1_2 = temp_fv0_6 * temp_fv1;
            temp_fv0f_2 = temp_ft0 * v30.z;
            temp_fv1f = v30.x;
            v40.z = temp_fv0_6;
            temp_fv0_7 = -temp_fv1f;
            temp_ft1 = temp_fv1_2 * temp_fv0_7;
            v30.x = v30.z;
            v30.y = temp_fv1f;
            v30.y = 0.0f;
            v30.z = temp_fv0_7;
            temp_fv0f_3 = temp_fv0f_2 + temp_ft1;
            v40.x = temp_ft0;
            v40.z = temp_fv1_2;
            v40.z = temp_fv0f_3;
            temp_v0->strafe = temp_fv0f_3;
        }
        if (((temp_s6 != 0) || (temp_s3 != 0)) && (arg0->unk304 != 0)) {
            value = sp10.y;
                    func_80209910_de(arg0, func_8029C044_de(value, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
            temp_v0->forward = D_800C1BF4_de;
        }
        if (arg0->player->pose == 0xF) {
            if (arg0->destination.y < playerPosition->y) {
                temp_v0->forward = D_800C1BF8_de;
            } else {
                temp_v0->forward = D_800C1BFC;
            }
        }
        if (arg0->unk310 != 0) {
            temp_v0->strafe = 0.0f;
            temp_v0->forward = 0.0f;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_80208AAC_de);
#endif

#ifdef NON_MATCHING
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/REC.H"
extern NavigationGraph D_8013B364;
float func_802726F8_de(void *, void *);
void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);
float func_80209308_de(AiController *, CVector3 *,float,float);
void func_80209910_de(AiController *,float,s32);
void func_80209E80_de(AiController *);
float func_802B72B0_de(float);
NavigationPoint *func_8020C994_de(NavigationGraph *,s32);
NavigationPortal *func_8020C9B0_de(NavigationGraph *,s32);
NavigationSearchNode *func_8020CFE0_de(NavigationGraph *,s32);
s32 func_8020CC0C_de(NavigationGraph *,s32,s32);
s32 func_80209828_de(AiController *);
typedef struct GroundObject { char pad[0x18]; ActorMotionResource *resource; } GroundObject;
GroundObject *func_8024E6A0_de(Player *);

extern f32 D_800C1C00;
extern f32 D_800C1C04;
extern f32 D_800C1C08;
extern f32 D_800C1C0C;
extern f32 D_800C1C10;
extern f32 D_800C1C14;
extern f32 D_800C1C18;
extern f32 D_800C1C1C;
extern f32 D_800C1C20;

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
void func_80208EB0_de(AiController *arg0) {
    NavigationGraph *graph;
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

    temp_v1 = arg0->target;
    if (temp_v1 == 0) {
        goto block_6;
    }
    if ((arg0->unk308 != 0) || (arg0->unk30C != 0) || (arg0->unk314 != 0)) {
block_6:
        func_80209308_de(arg0, &arg0->destination, 2.0f, 0.0f);
    } else {
        func_80209308_de(arg0, &temp_v1->player->pos, 2.0f, 0.0f);
        func_80209E80_de(arg0);
    }
    if (arg0->unk300 == 0) {
        temp_s2 = &arg0->destination;
        temp_v0 = arg0->player;
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
                temp_fs0f = func_80209308_de(arg0, temp_s2, 2.0f, value);
                if (temp_fs0f < value) {
                    if (-temp_fs0f < D_800C1C04) {
                        goto block_15;
                    }
                } else if (temp_fs0f < D_800C1C08) {
block_15:
                    temp_v0->forward = D_800C1C0C;
                }
                if (((temp_s6 != 0) || (temp_s4 != 0)) && (arg0->unk304 != 0)) {
                    value = sp10.y;
                    func_80209910_de(arg0, func_8029C044_de(value, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
                    temp_v0->forward = D_800C1C10;
                }
            }
        } else {
            temp_fs0f = arg0->player->heading + D_800C1C14;
            v30.x = func_802B7130_de(temp_fs0f);
            v30.y = 0.0f;
            v30.z = func_802B6560_de(temp_fs0f);
            v20.x = arg0->destination.x - playerPosition->x;
            v20.y = 0.0f;
            v20.z = arg0->destination.z - playerPosition->z;
            temp_v0_3 = func_8020C994_de(graph, arg0->current);
            v40 = temp_v0_3->position;
            v40.x -= arg0->destination.x;
            v40.z -= arg0->destination.z;
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
        if (((temp_s6 != 0) || (temp_s4 != 0)) && (arg0->unk304 != 0)) {
            value = sp10.y;
                    func_80209910_de(arg0, func_8029C044_de(value, func_802B72B0_de((sp10.x * sp10.x) + (sp10.z * sp10.z))), 1);
            temp_v0->forward = D_800C1C18;
        }
        if (arg0->player->pose == 0xF) {
            if (arg0->destination.y < playerPosition->y) {
                temp_v0->forward = D_800C1C1C;
            } else {
                temp_v0->forward = D_800C1C20;
            }
        }
        if (arg0->unk310 != 0) {
            temp_v0->strafe = 0.0f;
            temp_v0->forward = 0.0f;
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_80208EB0_de);
#endif
