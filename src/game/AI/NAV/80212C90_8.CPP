#include "include_asm.h"
#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/TRIPLE.H"


#if (defined(VERSION_DE)) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", Nav_UpdateObjectArrivalChase);
#endif

#if !(defined(VERSION_DE)) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
/* Runs a computer player's chase step toward the object at 0x68: without a target id at 0xBC it
   switches to mode 2 and without an object it only updates; farther than D_800C2380_eu from its goal
   node it heads there through Nav_SteerAlongRoute, otherwise it takes mode 8 once arrived or copies the
   object's position to 0x2C; then, within D_800C2384_eu of the object and not yet arrived, it marks
   arrival at 0x238 and plans a new route through Nav_CollectDirectedNeighbors to pick the next goal node. */
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"













extern RouteChaseGraph D_8013B364;



extern void Nav_SetBehaviourState(RouteChaseBot *bot, s32 mode);
extern void Nav_RunBehaviorHandler(RouteChaseBot *bot);
extern f32 Nav_DistanceToNode(RouteChaseBot *bot, s32 node);
extern void Nav_SteerAlongRoute(RouteChaseBot *bot);
extern void Nav_UpdateTargetSteering(RouteChaseBot *bot);
extern f32 GraphU64_GetPointDistance(CVector3 *a, CVector3 *b);
extern s32 Nav_CollectDirectedNeighbors(RouteChaseGraph *graph, s32 from, s32 to, s32 *path, s32 flags);
extern void Nav_ClearNodeQueue(RouteChaseBot *bot);

void Nav_UpdateObjectArrivalChase(RouteChaseActor *actor)
{
    s32 path[64];
    RouteChaseBot *bot = actor->player->bot;
    RouteChaseGraph *graph = &D_8013B364;
    f32 dist;
    s32 i;
    s32 len;
    s32 start;
    s32 none;

    if (bot->targetId == -1) {
        Nav_SetBehaviourState(bot, 2);
        return;
    }
    if (bot->target == 0) {
        Nav_RunBehaviorHandler(bot);
        return;
    }
    dist = Nav_DistanceToNode(bot, bot->goal);
    if (bot->node != bot->goal && D_800C2380_eu < dist) {
        Nav_SteerAlongRoute(bot);
    } else if (bot->arrived != 0) {
        Nav_SetBehaviourState(bot, 8);
    } else {
        bot->dest = bot->target->pos;
    }
    Nav_RunBehaviorHandler(bot);
    if (bot->target != 0) {
        Nav_UpdateTargetSteering(bot);
        if (GraphU64_GetPointDistance(&bot->self->pos, &bot->target->pos) < D_800C2384_eu && bot->arrived == 0) {
            bot->arrived = 1;
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            Nav_CollectDirectedNeighbors(graph, bot->goal, bot->goal, path, 0);
            start = path[0];
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            len = Nav_CollectDirectedNeighbors(graph, start, bot->goal, path, 0);
            Nav_ClearNodeQueue(bot);
            bot->goal = path[len - 1];
        }
    }
}
#endif
