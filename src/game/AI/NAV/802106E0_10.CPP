
#if !(defined(VERSION_DE))
/* Runs a computer rider's close attack state: refreshes its view, re-checks line of sight every fourth frame, backs off
   when its target is out of its layer or too close, re-rolls its strafe pattern and steers toward the target. */
#include "TYPES.H"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} CVector3;

struct Brain;

typedef struct Actor {
    char pad0[8];
    CVector3 pos;
    char pad14[0x24];
    s32 flags;
    char pad3C[0x30];
    f32 yaw;
    char pad70[0x168];
    struct Actor *self;
    char pad1DC[0x3F8];
    s32 slot;
    char pad5D8[0xCC];
    f32 strafe;
    f32 forward; s32 w6AC,buttons; char pad6B4[0xDA0];
    struct Brain *brain;
} Actor;

typedef struct Brain {
    Actor *player;
    s32 route;
    s32 w8,destination;
    s32 node;
    s32 w14;
    char pad18[0x4C];
    Actor *target;
    char pad68[0x188];
    f32 clearance[8];
    char pad210[0x20];
    s32 combat;
    char pad234[0xA4];
    s32 timer;
    s32 pattern;
    s32 distance;char pad2E4[0x34];
    s32 frames;
    s32 visible,fireTimer;
} Brain;

extern s32 D_800D297C;
extern char D_8013B364[];

extern void func_80211020_de(Brain *arg0);
extern s32 func_802099B4_de(Brain *, Actor *);
extern void Nav_SetBehaviourState(Brain *, s32);
extern f32 func_802726BC_de(CVector3 *, CVector3 *);
extern f32 func_80209BE0_de(Brain *arg0);
extern s32 Nav_NextRandom(void);
extern f32 func_80209DAC_de(Brain *arg0);
extern f32 Nav_SteerTowardPoint(Brain *, CVector3 *, f32, f32);
extern s32 func_80210EFC_de(f32);
extern void Nav_MeasureWheelClearance(Actor *, s32);
extern void func_80209E80_de(Brain *arg0);
extern s32 Nav_GetRouteRelation(char *, s32, s32);


extern void Nav_SteerAlongRoute(Brain *arg0), Nav_UpdatePlayerSteering(Brain *arg0);
void func_8021113C_eu(Actor *actor) {
    s32 mine, theirs, dir, route;
    Actor *player;
    Actor *target;
    Brain *brain;
    f32 speed;
    s32 pattern;

    brain = actor->self->brain;
    func_80211020_de(brain);
    player = brain->target;
    if (player != 0) {
        if (!(brain->frames & 3)) {
            brain->visible = func_802099B4_de(brain, player);
        }
        brain->frames += 1;
        target = brain->target->self;
        mine = brain->player->flags & 0x3000;
        theirs = (target->flags & 0x3000) != 0;
        if (mine && !theirs) {
            Nav_SetBehaviourState(brain, 12);
            return;
        }
        route = target->brain->route;
        if (brain->visible != 0) {
            if (func_802726BC_de(&target->pos, &brain->player->pos) < 360000.0f) {
                brain->combat = 3;
                Nav_SetBehaviourState(brain, 7);
                return;
            }
            speed = func_80209BE0_de(brain) * 0.4f;
            if (--brain->timer <= 0) {
                brain->timer = Nav_NextRandom() % 4 + 12;
                brain->pattern = Nav_NextRandom() % 2;
                if (Nav_NextRandom() % 2 == 1) {
                    brain->pattern = 2;
                }
            }
            Nav_SteerTowardPoint(brain, &target->pos, 2.0f, func_80209DAC_de(brain));
            pattern = brain->pattern;
            if (pattern == 0) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) - 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    Nav_MeasureWheelClearance(player, dir);
                }
                if (!(brain->clearance[dir] < 100.0f)) {
                    brain->player->strafe = -speed;
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
                    brain->player->strafe = speed;
                }
            } else {
                brain->player->strafe = 0.0f;
            }
            brain->w14 = -1;
            func_80209E80_de(brain);
        } else {
            brain->destination = route;
            Nav_SteerAlongRoute(brain);
            Nav_UpdatePlayerSteering(brain);
        }
        if (route != brain->node) {
            brain->node = route;
            if (Nav_GetRouteRelation(D_8013B364, brain->route, route) == 0) {
                Nav_SetBehaviourState(brain, 1);
            }
        }
    }
}
#endif
