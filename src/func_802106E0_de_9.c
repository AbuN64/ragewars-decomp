/* Runs a computer rider's close attack state: refreshes its view, re-checks line of sight every fourth frame, backs off
   when its target is out of its layer or too close, re-rolls its strafe pattern and steers toward the target. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

struct Brain;

typedef struct Actor {
    char pad0[8];
    Vec3 pos;
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
    f32 walk[8];
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
extern void func_80209874_de(Brain *, s32);
extern f32 func_802726BC_de(Vec3 *, Vec3 *);
extern f32 func_80209BE0_de(Brain *arg0);
extern s32 func_802744D4_de(void);
extern f32 func_80209DAC_de(Brain *arg0);
extern f32 func_80209308_de(Brain *, Vec3 *, f32, f32);
extern s32 func_80210EFC_de(f32);
extern void func_80210964_de(Actor *, s32);
extern void func_80209E80_de(Brain *arg0);
extern s32 func_8020D1CC_de(char *, s32, s32);


extern void func_80208410_de(Brain *arg0), func_80208AAC_de(Brain *arg0);
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
            func_80209874_de(brain, 12);
            return;
        }
        route = target->brain->route;
        if (brain->visible != 0) {
            if (func_802726BC_de(&target->pos, &brain->player->pos) < 360000.0f) {
                brain->combat = 3;
                func_80209874_de(brain, 7);
                return;
            }
            speed = func_80209BE0_de(brain) * 0.4f;
            if (--brain->timer <= 0) {
                brain->timer = func_802744D4_de() % 4 + 12;
                brain->pattern = func_802744D4_de() % 2;
                if (func_802744D4_de() % 2 == 1) {
                    brain->pattern = 2;
                }
            }
            func_80209308_de(brain, &target->pos, 2.0f, func_80209DAC_de(brain));
            pattern = brain->pattern;
            if (pattern == 0) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) - 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (!(brain->walk[dir] < 100.0f)) {
                    brain->player->strafe = -speed;
                } else {
                    goto halt;
                }
            } else if (pattern == 1) {
                dir = func_80210EFC_de((brain->player->yaw - 3.1415927f) + 1.5707964f);
                player = brain->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (brain->walk[dir] < 100.0f) {
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
            func_80208410_de(brain);
            func_80208AAC_de(brain);
        }
        if (route != brain->node) {
            brain->node = route;
            if (func_8020D1CC_de(D_8013B364, brain->route, route) == 0) {
                func_80209874_de(brain, 1);
            }
        }
    }
}
