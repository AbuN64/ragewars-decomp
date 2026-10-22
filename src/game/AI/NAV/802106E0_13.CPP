#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_13.H"

#if !(defined(VERSION_DE))
/* Runs a computer player's chase state: refreshes its view through func_80211020_de and, without a target, returns to roaming (state 2); otherwise re-checks the target's visibility every fourth frame through func_802099B4_de, backs off (state 12) when only it is on the upper layer, switches to close combat (state 7, sub-state 13) within 600 units, re-rolls its strafe pattern through func_802744D4_de when its timer runs out, steers at the target through func_80209308_de and strafes left or right at 0.4 of its speed while func_80210964_de reports room to walk, stopping otherwise, then drives through func_80209E80_de; losing sight of the target or failing to re-route to the target's new node through func_8020D1CC_de also returns it to roaming. */








extern s32 D_800D297C;
extern char D_8013B364[];

extern void func_80211020_de(Brain_func_802120A8_eu *);
extern s32 func_802099B4_de(Brain_func_802120A8_eu *, Self *);
extern void func_80209874_de(Brain_func_802120A8_eu *, s32);
extern f32 func_802726BC_de(CVector3 *, CVector3 *);
extern f32 func_80209BE0_de(Brain_func_802120A8_eu *);
extern f32 func_80209DAC_de(Brain_func_802120A8_eu *);
extern f32 func_80209308_de(Brain_func_802120A8_eu *, CVector3 *, f32, f32);
extern s32 func_80210EFC_de(f32);
extern void func_80210964_de(Self *, s32);
extern void func_80209E80_de(Brain_func_802120A8_eu *);
extern s32 func_8020D1CC_de(char *, s32, s32);

void func_802120A8_eu(Self *actor) {
    Brain_func_802120A8_eu *brain;
    s32 mine;
    Self *target;
    s32 node;
    f32 speed;
    s32 dir;
    s32 roll;
    s32 theirs;

    brain = actor->self->brain;
    func_80211020_de(brain);
    if (brain->target == 0) {
        brain->target = 0;
        func_80209874_de(brain, 2);
        return;
    }
    if (!(brain->frames & 3)) {
        brain->visible = func_802099B4_de(brain, brain->target);
    }
    brain->frames++;
    target = brain->target->self;
    mine = brain->player->flags & 0x3000;
    theirs = (target->flags & 0x3000) != 0;
    if (mine && !theirs) {
        func_80209874_de(brain, 12);
        return;
    }
    node = target->brain->route;
    if (brain->visible != 0) {
        if (func_802726BC_de(&target->pos, &brain->player->pos) < 360000.0f) {
            brain->combat = 13;
            func_80209874_de(brain, 7);
            return;
        }
        speed = func_80209BE0_de(brain) * 0.4f;
        if (--brain->timer <= 0) {
            brain->timer = func_802744D4_de() % 4 + 12;
            brain->pattern = func_802744D4_de() % 2;
            roll = func_802744D4_de();
            if (roll / 2 * 2 == roll - 1) {
                brain->pattern = 2;
            }
        }
        func_80209308_de(brain, &target->pos, 2.0f, func_80209DAC_de(brain));
        if (brain->pattern == 0) {
            dir = func_80210EFC_de(brain->player->yaw - 3.1415927f - 1.5707964f);
            if (brain->player->slot % 2 == D_800D297C) {
                func_80210964_de(brain->player, dir);
            }
            if (brain->walk[dir] < 100.0f) {
                goto stop;
            }
            brain->player->strafe = -speed;
        } else if (brain->pattern == 1) {
            dir = func_80210EFC_de(brain->player->yaw - 3.1415927f + 1.5707964f);
            if (brain->player->slot % 2 == D_800D297C) {
                func_80210964_de(brain->player, dir);
            }
            if (brain->walk[dir] < 100.0f) {
            stop:
                brain->player->strafe = 0.0f;
                brain->pattern = 2;
            } else {
                brain->player->strafe = speed;
            }
        } else {
            brain->player->strafe = 0.0f;
        }
        brain->routeNodes[0] = -1;
        func_80209E80_de(brain);
    } else {
        brain->target = 0;
        func_80209874_de(brain, 2);
    }
    if (node != brain->node) {
        brain->node = node;
        if (func_8020D1CC_de(D_8013B364, brain->route, node) == 0) {
            brain->target = 0;
            func_80209874_de(brain, 2);
        }
    }
}
#endif
