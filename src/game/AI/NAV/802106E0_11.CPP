#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_11.H"

#if !(defined(VERSION_DE))
/* Drives combat pursuit, retreat and strafing while refreshing target visibility, routes and fire timing. */








extern s32 D_800D297C;
extern char D_8013B364[];

extern void func_80211020_de(CloseAttackBrain *);
extern s32 func_802099B4_de(CloseAttackBrain *, CloseAttackActor *);
extern void func_80209874_de(CloseAttackBrain *, s32);
extern f32 func_802726BC_de(CVector3 *, CVector3 *);
extern f32 func_80209BE0_de(CloseAttackBrain *);
extern f32 func_80209DAC_de(CloseAttackBrain *);
extern f32 Nav_SteerTowardPoint(CloseAttackBrain *, CVector3 *, f32, f32);
extern s32 func_80210EFC_de(f32);
extern void Nav_MeasureWheelClearance(CloseAttackActor *, s32);
extern void func_80209E80_de(CloseAttackBrain *);
extern s32 Nav_GetRouteRelation(char *, s32, s32);


extern void Nav_SteerAlongRoute(CloseAttackBrain *),Nav_UpdatePlayerSteering(CloseAttackBrain *),Nav_SelectPlayerState(CloseAttackBrain *);
extern struct {char pad[0xC];unsigned short flags;} *Nav_GetGraphPoint(char *,int);
extern float D_800C22D0_eu[];

void func_80211490_eu(CloseAttackActor *actor) {
 char *routes;int mine,theirs,dir; CloseAttackActor *player;
    CloseAttackActor *target;
    CloseAttackActor *temp_s0;
    CloseAttackActor *temp_v1_3;
    CloseAttackBrain *brain;
    CVector3 *temp_s0_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f21;
    f32 distance;
    f32 temp_f2_2;
    s32 route;
    s32 temp_v0;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 pattern;
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;

    brain = actor->self->brain;
    func_80211020_de(brain);
    target = brain->target;routes=D_8013B364;
    if (target != 0) {
        if (!(brain->frames & 3)) {
            brain->visible = func_802099B4_de(brain, target);
        }
        brain->frames += 1;
        temp_s0 = brain->target->self;
        mine=brain->player->flags&0x3000;theirs=(temp_s0->flags&0x3000)!=0;
        if (mine && !theirs) {
            func_80209874_de(brain,12);return;
        }
        route = temp_s0->brain->route;
        if (Nav_GetGraphPoint(routes, route)->flags & 0x400) {
            brain->target = 0;
            Nav_SelectPlayerState(brain);
            return;
        }
        if (brain->visible != 0) {
            temp_f21 = func_80209BE0_de(brain);
            temp_v0 = brain->timer - 1;
            temp_f20 = temp_f21 * 0.6f;
            brain->timer = temp_v0;
            if (temp_v0 <= 0) {
                brain->timer=Nav_NextRandom()%4+12;
                brain->pattern = Nav_NextRandom() % 2;
                brain->distance = (Nav_NextRandom() % 250000) + 0x57E40;
            }
            temp_s0_2 = &temp_s0->pos;
            Nav_SteerTowardPoint(brain, temp_s0_2, 2.0f, func_80209DAC_de(brain));
            temp_f0 = func_802726BC_de(temp_s0_2, &brain->player->pos);
            temp_f1 = temp_f0 + 10000.0f;
            distance = (f32) brain->distance;
            if (temp_f1 < 0.0f) {
                if (distance < -temp_f1) {
                    goto block_19;
                }
                goto block_23;
            }
            if (distance < temp_f1) {
block_19:
                dir = func_80210EFC_de(brain->player->yaw - 3.1415927f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    Nav_MeasureWheelClearance(player, dir);
                }
                if (!(brain->walk[dir] < 100.0f)) {
                    brain->player->forward = 1.0f;
                } else {
                    goto block_31;
                }
            } else {
block_23:
                temp_f1_2 = temp_f0 - 10000.0f;
                temp_f2_2 = (f32) brain->distance;
                if (temp_f1_2 < 0.0f) {
                    if (-temp_f1_2 < temp_f2_2) {
                        goto block_27;
                    }
                    goto block_31;
                }
                if (temp_f1_2 < temp_f2_2) {
block_27:
                    dir = func_80210EFC_de(brain->player->yaw);
                    player = brain->player;
                    if ((player->slot % 2) == D_800D297C) {
                        Nav_MeasureWheelClearance(player, dir);
                    }
                    if (!(brain->walk[dir] < 100.0f)) {
                        brain->player->forward = -1.0f;
                    } else {
                        goto block_31;
                    }
                } else {
block_31:
                    brain->player->forward = 0.0f;
                }
            }
            pattern = brain->pattern;
            if (pattern == 0) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) - 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    Nav_MeasureWheelClearance(player, dir);
                }
                if (!(brain->walk[dir] < 100.0f)) {
                    brain->player->strafe = -temp_f20;
                } else {
                    goto block_41;
                }
            } else if (pattern == 1) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) + 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    Nav_MeasureWheelClearance(player, dir);
                }
                if (brain->walk[dir] < 100.0f) {
block_41:
                    brain->player->strafe = 0.0f;
                    brain->pattern = 2;
                } else {
                    brain->player->strafe = temp_f20;
                }
            } else {
                brain->player->strafe = 0.0f;
            }
            brain->routeNodes[0] = -1;
            temp_v0_6 = brain->fireTimer - 1;
            brain->fireTimer = temp_v0_6;
            if ((temp_v0_6 == 0) && ((Nav_NextRandom() % 100) < (s32) temp_f21)) {
                temp_v1_3 = brain->player;
                temp_v1_3->buttons |= 0x10;
            }
            if (brain->fireTimer < 0) {
                brain->fireTimer = ((Nav_NextRandom() % 2) + 2) * 0xF;
            }
            func_80209E80_de(brain);
        } else {
            brain->destination = route;
            Nav_SteerAlongRoute(brain);
            Nav_UpdatePlayerSteering(brain);
        }
        if (route != brain->node) {
            brain->node = route;
            if (Nav_GetRouteRelation(routes, brain->route, route) == 0) {
                func_80209874_de(brain,1);
            }
        }
    }
}
#endif
