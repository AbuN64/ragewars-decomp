#include "include_asm.h"
#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "AI/NAV/NAV_RESETOBJECTARRIVALCHASE.H"

/* 80212C90_8.CPP */
#if !defined(VERSION_DE)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
/* Runs a computer player's chase step toward the object at 0x68: without a target id at 0xBC it
   switches to mode 2 and without an object it only updates; farther than g_objectChaseRouteDistanceLimit from its goal
   node it heads there through Nav_SteerAlongRoute, otherwise it takes mode 8 once arrived or copies the
   object's position to 0x2C; then, within g_objectChaseArrivalDistance of the object and not yet arrived, it marks
   arrival at 0x238 and plans a new route through Portal_CollectDirectedNeighbors to pick the next goal node. */
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"

extern RouteChaseGraph g_navigationGraph;

extern void Scaled_SetBehaviourState(RouteChaseBot *bot, s32 mode);
extern void Nav_RunBehaviorHandler(RouteChaseBot *bot);
extern f32 Scaled_DistanceToNode(RouteChaseBot *bot, s32 node);
extern void Nav_SteerAlongRoute(RouteChaseBot *bot);
extern void Nav_UpdateTargetSteering(RouteChaseBot *bot);
extern f32 Graphu64_GetPointDistance(CVector3 *a, CVector3 *b);
extern s32 Portal_CollectDirectedNeighbors(RouteChaseGraph *graph, s32 from, s32 to, s32 *path, s32 flags);
extern void Scaled_ClearNodeQueue(RouteChaseBot *bot);

void Nav_UpdateObjectArrivalChase(RouteChaseActor *actor)
{
    s32 path[64];
    RouteChaseBot *bot = actor->player->bot;
    RouteChaseGraph *graph = &g_navigationGraph;
    f32 dist;
    s32 i;
    s32 len;
    s32 start;
    s32 none;

    if (bot->targetId == -1) {
        Scaled_SetBehaviourState(bot, 2);
        return;
    }
    if (bot->target == 0) {
        Nav_RunBehaviorHandler(bot);
        return;
    }
    dist = Scaled_DistanceToNode(bot, bot->goal);
    if (bot->node != bot->goal && g_objectChaseRouteDistanceLimit < dist) {
        Nav_SteerAlongRoute(bot);
    } else if (bot->arrived != 0) {
        Scaled_SetBehaviourState(bot, 8);
    } else {
        bot->dest = bot->target->pos;
    }
    Nav_RunBehaviorHandler(bot);
    if (bot->target != 0) {
        Nav_UpdateTargetSteering(bot);
        if (Graphu64_GetPointDistance(&bot->self->pos, &bot->target->pos) < g_objectChaseArrivalDistance && bot->arrived == 0) {
            bot->arrived = 1;
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            Portal_CollectDirectedNeighbors(graph, bot->goal, bot->goal, path, 0);
            start = path[0];
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            len = Portal_CollectDirectedNeighbors(graph, start, bot->goal, path, 0);
            Scaled_ClearNodeQueue(bot);
            bot->goal = path[len - 1];
        }
    }
}
#endif

/* 80212C90_9.CPP */
void Nav_ResetObjectArrivalChase(void *actor) {
    void *brain;
    brain = (((struct NavigationActorBrainView *) ((s8 *) ((struct ActorPlayerControllerView *) ((s8 *) actor))->player))->brain);
    (((struct NavigationChaseResetView *) ((s8 *) brain))->target) = 0;
    (((struct NavigationChaseResetView *) ((s8 *) brain))->arrived) = 0;
    (((struct NavigationChaseResetView *) ((s8 *) brain))->resetWord220) = 0;
    Scaled_ResetBehaviorState(brain);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int func_802131D8_de_padding_13DF8[2] = {
    0x8E020030, 0x460005C6,
};
#endif
#if defined(VERSION_EU_X)
unsigned int func_802131D8_de_padding_13DF8[2] = {
    0x8E220030, 0x10400006,
};
#endif
#endif

/* 800C6E84_2.CPP */
#if defined(VERSION_DE)
const float g_Nav_ResetPatrolRouteSelectionConstantWords[2] = {
    102.399994f, 51.199997f,
};
#endif

#if defined(VERSION_DE)
unsigned int k_NavUpdateobjectarrivalchaseEncodedWords[2] = {
    0x24040001, 0xAFBF0028,
};
#endif
