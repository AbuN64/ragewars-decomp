#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_12.H"

#if !(defined(VERSION_DE))
/* Drives close-range combat: pursuit, retreat and strafing around a target, bailing out when it gets too far away. */









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
void func_80211A9C_eu(CloseAttackActor *actor) {
    char *routes;
    s32 mine, theirs, dir, route;
    CloseAttackActor *player;
    CloseAttackActor *target;
    CloseAttackBrain *brain;
    CVector3 *pos;
    f32 dist, near, far, range, speed, strafe;
    s32 pattern;

    brain = actor->self->brain;
    func_80211020_de(brain);
    player = brain->target;
    routes = D_8013B364;
    if (player != 0) {
        if (!(brain->frames & 3)) {
            brain->visible = func_802099B4_de(brain, player);
        }
        brain->frames += 1;
        target = brain->target->self;
        mine = brain->player->flags & 0x3000;
        theirs = (target->flags & 0x3000) != 0;
        if (mine && !theirs) {
            func_80209874_de(brain, 12);
            return;
        }
        route = target->brain->route;
        if (Nav_GetGraphPoint(routes, route)->flags & 0x400) {
            brain->target = 0;
            Nav_SelectPlayerState(brain);
            return;
        }
        if (brain->visible != 0) {
            speed = func_80209BE0_de(brain);
            strafe = speed;
            if (--brain->timer <= 0) {
                brain->timer = Nav_NextRandom() % 4 + 2;
                brain->pattern = Nav_NextRandom() % 2;
                brain->distance = Nav_NextRandom() % 32400 + 10000;
            }
            pos = &target->pos;
            Nav_SteerTowardPoint(brain, pos, 2.0f, func_80209DAC_de(brain));
            dist = func_802726BC_de(pos, &brain->player->pos);
            if (dist > 377487.3f) {
                brain->combat = 5;
                func_80209874_de(brain, 6);
                return;
            }
            near = dist + 10000.0f;
            range = (f32)brain->distance;
            if (near < 0.0f) {
                if (range < -near) {
                    goto fwd;
                }
                goto back_test;
            }
            if (range < near) {
fwd:
                dir = func_80210EFC_de(brain->player->yaw - 3.1415927f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    Nav_MeasureWheelClearance(player, dir);
                }
                if (!(brain->clearance[dir] < 100.0f)) {
                    brain->player->forward = 1.0f;
                } else {
                    goto stop;
                }
            } else {
back_test:
                far = dist - 10000.0f;
                range = (f32)brain->distance;
                if (far < 0.0f) {
                    if (-far < range) {
                        goto back;
                    }
                    goto stop;
                }
                if (far < range) {
back:
                    dir = func_80210EFC_de(brain->player->yaw);
                    player = brain->player;
                    if ((player->slot % 2) == D_800D297C) {
                        Nav_MeasureWheelClearance(player, dir);
                    }
                    if (!(brain->clearance[dir] < 100.0f)) {
                        brain->player->forward = -1.0f;
                    } else {
                        goto stop;
                    }
                } else {
stop:
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
                if (!(brain->clearance[dir] < 100.0f)) {
                    brain->player->strafe = -strafe;
                } else {
                    goto halt;
                }
            } else if (pattern == 1) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) + 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    Nav_MeasureWheelClearance(player, dir);
                }
                if (brain->clearance[dir] < 100.0f) {
halt:
                    brain->player->strafe = 0.0f;
                    brain->pattern = 2;
                } else {
                    brain->player->strafe = strafe;
                }
            } else {
                brain->player->strafe = 0.0f;
            }
            brain->routeNodes[0] = -1;
            if (--brain->fireTimer == 0 && (Nav_NextRandom() % 100) < (s32)speed) {
                brain->player->buttons |= 0x10;
            }
            if (brain->fireTimer < 0) {
                brain->fireTimer = ((Nav_NextRandom() % 1) + 2) * 0xF;
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
                func_80209874_de(brain, 1);
            }
        }
    }
}
#endif
