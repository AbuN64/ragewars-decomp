#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/SELF.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU))
/* Runs a computer player's patrol step: starts its route at 0x224 on the first route of D_8011FE88,
   or random roaming (-2) when there are none; once within D_800C23B0_eu_x of its goal node it advances the
   route position at 0x228 (wrapping at the route length) and drops the goal; a dropped goal is then
   taken from the route through Scene_GetPlatformRoutePoint and func_8020CB3C_de, or a random node of D_8013B364 when
   roaming; finally runs Nav_SteerAlongRoute, Nav_RunBehaviorHandler and Nav_UpdatePlayerSteering. */













extern RoutePatrolNodes D_8013B364;



extern Clip *Scene_GetPlatformRoute(PatrolRouteSet *set, s32 route);
extern s32 Scene_GetPlatformRoutePoint(PatrolRouteSet *set, s32 route, s32 pos);
extern s32 Nav_FindNearestPointIndex(RoutePatrolNodes *list, s32 id);
extern void *Nav_GetGraphPoint(RoutePatrolNodes *list, s32 index);
extern void *Nav_GetControllerPosition(PatrolBot *bot);
extern f32 GraphU64_GetPointDistance(void *a, void *b);
extern void Nav_SteerAlongRoute(PatrolBot *bot);
extern void Nav_RunBehaviorHandler(PatrolBot *bot);
extern void Nav_UpdatePlayerSteering(PatrolBot *bot);

void Nav_UpdatePatrolRoute(PatrolActor *actor)
{
    PatrolBot *bot = actor->player->bot;
    RoutePatrolNodes *nodes = &D_8013B364;
    void *pos;
    Clip *route;

    if (bot->route == -1) {
        Shared_World *routes = &g_world;

        if (*routes->routeCount > 0) {
            bot->route = 0;
            bot->routePos = 0;
            Scene_GetPlatformRoute(routes, bot->route);
        } else {
            bot->route = -2;
            bot->routePos = -1;
        }
        bot->goal = -1;
    }
    if (bot->node == bot->goal) {
        pos = Nav_GetControllerPosition(bot);
        if (GraphU64_GetPointDistance(pos, Nav_GetGraphPoint(nodes, bot->goal)) < D_800C23B0_eu_x) {
            if (bot->route >= 0) {
                route = Scene_GetPlatformRoute(&g_world, bot->route);
                bot->routePos++;
                if (bot->routePos == route->frames) {
                    bot->routePos = 0;
                }
            }
            bot->goal = -1;
        }
    }
    if (bot->goal == -1) {
        if (bot->route == -2) {
            bot->goal = GraphU64_NextRandom() % nodes->count;
        } else {
            bot->goal = Nav_FindNearestPointIndex(nodes, Scene_GetPlatformRoutePoint(&g_world, bot->route, bot->routePos));
        }
    }
    Nav_SteerAlongRoute(bot);
    Nav_RunBehaviorHandler(bot);
    Nav_UpdatePlayerSteering(bot);
}
#endif
