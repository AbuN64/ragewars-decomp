#include "COMMON/NAVIGATION_GRAPH.H"
#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/SELF.H"
#include "AI/NAV/80212C90_15.H"

/* Runs a computer player's think step: when it has reached its goal node or the goal at 0x22C is past
   the node count D_8013B368, it picks a new goal as Nav_InitRoamingWithJumps does (Nav_SelectFlaggedRoamingGoal for a player
   flagged at 0x94 in mode 12, otherwise up to ten random nodes of D_8013B364 not flagged 0x400); then
   it counts down the jump timer at 0x320 and on expiry makes its player jump (bit 0x10 at 0x6B0)
   unless the player is in state 0xF, holds input bits 0x3000 or the bot is busy at 0x314, rerolls an
   expired timer to 15 times 3 to 9 frames, and runs Nav_RunBehaviorHandler, Nav_SteerAlongRoute and Nav_UpdatePlayerSteering. */

extern s32 D_8013B364;


extern void *Nav_GetGraphPoint(void *, s32);
extern void Nav_RunBehaviorHandler(void *);
extern void Nav_SteerAlongRoute(void *);
extern void Nav_UpdatePlayerSteering(void *);
















void Nav_UpdateRoamingWithJumps(Shared_Actor *arg0) {
    void *actor = ((Shared_ActorView *)(arg0->entity))->owner;
    void *player;
    s32 busy;
    s32 held;
    s32 state;

    if (((Brain_func_80212D78_eu_x *)(actor))->node == ((Brain_func_80212D78_eu_x *)(actor))->goal
        || !(((Brain_func_80212D78_eu_x *)(actor))->goal < D_8013B368)) {
        void *data = ((Shared_ActorView *)(*(void **) actor))->controls;
        if (((RecordRecAt94 *)(data))->display && ((RecordRecAt94 *)(data))->kind == 12) {
            Nav_SelectFlaggedRoamingGoal(actor);
        } else {
            s32 global_count = D_8013B368;
            s32 *table = &D_8013B364;
            s32 tries = 0;
            s32 candidate;

            if (global_count >= 2) {
                candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
loop:
                if (tries < 10) {
                    candidate = GraphU64_NextRandom() % table[1];
                    if (navigation_point_flags((NavigationPoint *)(Nav_GetGraphPoint(table, candidate))) & 0x400) {
                        candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
                    }
                    tries++;
                    if (candidate != ((Brain_func_80212D78_eu_x *)(actor))->goal) {
                        goto store_both;
                    }
                    goto loop;
                } else {
                    ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
                    goto store_c;
                }
            } else {
                candidate = 1;
            }
store_both:
            ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
store_c:
            ((Brain_func_80212D78_eu_x *)(actor))->nextNode = candidate;
        }
    }
    if (--((Brain_func_80212D78_eu_x *)(actor))->jumpTimer == 0) {
        player = *(void **) actor;
        state = ((Shared_ActorView *)(player))->action != 0xF;
        busy = ((Brain_func_80212D78_eu_x *)(actor))->busy != 0;
        held = (((Shared_ActorView *)(player))->unk_0x0038 & 0x3000) != 0;
        if (state && !held && !busy) {
            ((Shared_ActorView *)(player))->unk_0x06B0 |= 0x10;
        }
    }
    if (((Brain_func_80212D78_eu_x *)(actor))->jumpTimer < 0) {
        ((Brain_func_80212D78_eu_x *)(actor))->jumpTimer = (GraphU64_NextRandom() % 7 + 3) * 15;
    }
    Nav_RunBehaviorHandler(actor);
    Nav_SteerAlongRoute(actor);
    Nav_UpdatePlayerSteering(actor);
}




extern void *Nav_GetGraphPoint(void *, s32);















void Nav_InitRoamingWithJumps(Shared_Actor *arg0)
{
    void *actor = ((Shared_ActorView *)(arg0->entity))->owner;

    ((Brain_func_80212D78_eu_x *)(actor))->unk220 = 0;
    {
        void *data = ((Shared_ActorView *)(*(void **)actor))->controls;
        if (((RecordRecAt94 *)(data))->display && ((RecordRecAt94 *)(data))->kind == 12) {
            Nav_SelectFlaggedRoamingGoal(actor);
        } else {
            s32 global_count = D_8013B368;
            s32 *table = &D_8013B364;
            s32 tries = 0;
            s32 candidate;

            if (global_count >= 2) {
                candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
loop:
                if (tries < 10) {
                    candidate = GraphU64_NextRandom() % table[1];
                    if (navigation_point_flags((NavigationPoint *)(Nav_GetGraphPoint(table, candidate))) & 0x400) {
                        candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
                    }
                    tries++;
                    if (candidate != ((Brain_func_80212D78_eu_x *)(actor))->goal) {
                        goto store_both;
                    }
                    goto loop;
                } else {
                    ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
                    goto store_c;
                }
            } else {
                candidate = 1;
            }
store_both:
            ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
store_c:
            ((Brain_func_80212D78_eu_x *)(actor))->nextNode = candidate;
        }
    }
    Nav_ResetBehaviorState(actor);
    ((Brain_func_80212D78_eu_x *)(actor))->jumpTimer = -1;
}


extern void *Nav_GetGraphPoint(void *, s32);






void Nav_ChooseNewRoamingGoal(void *arg0)
{
    s32 *table = &D_8013B364;
    s32 tries = 0;
    s32 candidate;

    if (table[1] >= 2) {
        candidate = ((Brain_func_80212D78_eu_x *)(arg0))->goal;
loop:
        if (tries < 10) {
            candidate = GraphU64_NextRandom() % table[1];
            if (navigation_point_flags((NavigationPoint *)(Nav_GetGraphPoint(table, candidate))) & 0x400) {
                candidate = ((Brain_func_80212D78_eu_x *)(arg0))->goal;
            }
            tries++;
            if (candidate != ((Brain_func_80212D78_eu_x *)(arg0))->goal) {
                goto store_both;
            }
            goto loop;
        } else {
            ((Brain_func_80212D78_eu_x *)(arg0))->goal = candidate;
            goto store_c;
        }
    } else {
        candidate = 1;
    }
store_both:
    ((Brain_func_80212D78_eu_x *)(arg0))->goal = candidate;
store_c:
    ((Brain_func_80212D78_eu_x *)(arg0))->nextNode = candidate;
}

#if defined(VERSION_US)
char rodata_unresolved_802138E8[8] =
    "\000\033SFX_WA";
#endif
