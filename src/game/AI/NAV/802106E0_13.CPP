#include "include_asm.h"

#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_13.H"

/* Runs a computer player's chase state: refreshes its view through Nav_RunBehaviorHandler and, without a target, returns to roaming (state 2); otherwise re-checks the target's visibility every fourth frame through func_802099B4_de, backs off (state 12) when only it is on the upper layer, switches to close combat (state 7, sub-state 13) within 600 units, re-rolls its strafe pattern through func_802744D4_de when its timer runs out, steers at the target through func_80209308_de and strafes left or right at 0.4 of its speed while Nav_MeasureWheelClearance reports room to walk, stopping otherwise, then drives through Nav_DispatchActorBehavior; losing sight of the target or failing to re-route to the target's new node through Nav_GetRouteRelation also returns it to roaming. */








extern char D_8013B364[];

extern void Nav_RunBehaviorHandler(BrainNavUpdateVisiblePursuit *);
extern s32 Nav_HasLineOfSight(BrainNavUpdateVisiblePursuit *, Self *);
extern void Nav_SetBehaviourState(BrainNavUpdateVisiblePursuit *, s32);
extern f32 GraphU64_GetSquaredDistance(CVector3 *, CVector3 *);
extern f32 Nav_ScaleCharacterSettingByDifficulty(BrainNavUpdateVisiblePursuit *);
extern f32 Nav_UpdateDifficultyAimJitter(BrainNavUpdateVisiblePursuit *);
extern f32 Nav_SteerTowardPoint(BrainNavUpdateVisiblePursuit *, CVector3 *, f32, f32);
extern s32 Nav_GetDirectionSector(f32);
extern void Nav_MeasureWheelClearance(Self *, s32);
extern void Nav_DispatchActorBehavior(BrainNavUpdateVisiblePursuit *);
extern s32 Nav_GetRouteRelation(char *, s32, s32);

void Nav_UpdateVisiblePursuit(Self *actor) {
    BrainNavUpdateVisiblePursuit *brain;
    s32 mine;
    Self *target;
    s32 node;
    f32 speed;
    s32 dir;
    s32 roll;
    s32 theirs;

    brain = actor->self->brain;
    Nav_RunBehaviorHandler(brain);
    if (brain->target == 0) {
        brain->target = 0;
        Nav_SetBehaviourState(brain, 2);
        return;
    }
    if (!(brain->frames & 3)) {
        brain->visible = Nav_HasLineOfSight(brain, brain->target);
    }
    brain->frames++;
    target = brain->target->self;
    mine = brain->player->flags & 0x3000;
    theirs = (target->flags & 0x3000) != 0;
    if (mine && !theirs) {
        Nav_SetBehaviourState(brain, 12);
        return;
    }
    node = target->brain->route;
    if (brain->visible != 0) {
        if (GraphU64_GetSquaredDistance(&target->pos, &brain->player->pos) < 360000.0f) {
            brain->combat = 13;
            Nav_SetBehaviourState(brain, 7);
            return;
        }
        speed = Nav_ScaleCharacterSettingByDifficulty(brain) * 0.4f;
        if (--brain->timer <= 0) {
            brain->timer = GraphU64_NextRandom() % 4 + 12;
            brain->pattern = GraphU64_NextRandom() % 2;
            roll = GraphU64_NextRandom();
            if (roll / 2 * 2 == roll - 1) {
                brain->pattern = 2;
            }
        }
        Nav_SteerTowardPoint(brain, &target->pos, 2.0f, Nav_UpdateDifficultyAimJitter(brain));
        if (brain->pattern == 0) {
            dir = Nav_GetDirectionSector(brain->player->yaw - 3.1415927f - 1.5707964f);
            if (brain->player->slot % 2 == D_800D297C) {
                Nav_MeasureWheelClearance(brain->player, dir);
            }
            if (brain->clearance[dir] < 100.0f) {
                goto stop;
            }
            brain->player->strafe = -speed;
        } else if (brain->pattern == 1) {
            dir = Nav_GetDirectionSector(brain->player->yaw - 3.1415927f + 1.5707964f);
            if (brain->player->slot % 2 == D_800D297C) {
                Nav_MeasureWheelClearance(brain->player, dir);
            }
            if (brain->clearance[dir] < 100.0f) {
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
        Nav_DispatchActorBehavior(brain);
    } else {
        brain->target = 0;
        Nav_SetBehaviourState(brain, 2);
    }
    if (node != brain->node) {
        brain->node = node;
        if (Nav_GetRouteRelation(D_8013B364, brain->route, node) == 0) {
            brain->target = 0;
            Nav_SetBehaviourState(brain, 2);
        }
    }
}
