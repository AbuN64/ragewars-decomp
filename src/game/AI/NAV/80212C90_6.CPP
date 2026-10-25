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
   taken from the route through Engine_GetPlatformRoutePoint and func_8020CB3C_de, or a random node of D_8013B364 when
   roaming; finally runs Nav_SteerAlongRoute, func_80211020_de and Nav_UpdatePlayerSteering. */













extern RoutePatrolNodes D_8013B364;



extern Clip *Engine_GetPlatformRoute(PatrolRouteSet *set, s32 route);
extern s32 Engine_GetPlatformRoutePoint(PatrolRouteSet *set, s32 route, s32 pos);
extern s32 func_8020CB3C_de(RoutePatrolNodes *list, s32 id);
extern void *Nav_GetGraphPoint(RoutePatrolNodes *list, s32 index);
extern void *func_8020993C_de(PatrolBot *bot);
extern f32 Particle_GetPointDistance(void *a, void *b);
extern void Nav_SteerAlongRoute(PatrolBot *bot);
extern void func_80211020_de(PatrolBot *bot);
extern void Nav_UpdatePlayerSteering(PatrolBot *bot);

void func_80212E30_eu_x(PatrolActor *actor)
{
    PatrolBot *bot = actor->player->bot;
    RoutePatrolNodes *nodes = &D_8013B364;
    void *pos;
    Clip *route;

    if (bot->route == -1) {
        Shared_World *routes = &D_8011FE88;

        if (*routes->routeCount > 0) {
            bot->route = 0;
            bot->routePos = 0;
            Engine_GetPlatformRoute(routes, bot->route);
        } else {
            bot->route = -2;
            bot->routePos = -1;
        }
        bot->goal = -1;
    }
    if (bot->node == bot->goal) {
        pos = func_8020993C_de(bot);
        if (Particle_GetPointDistance(pos, Nav_GetGraphPoint(nodes, bot->goal)) < D_800C23B0_eu_x) {
            if (bot->route >= 0) {
                route = Engine_GetPlatformRoute(&D_8011FE88, bot->route);
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
            bot->goal = Nav_NextRandom() % nodes->count;
        } else {
            bot->goal = func_8020CB3C_de(nodes, Engine_GetPlatformRoutePoint(&D_8011FE88, bot->route, bot->routePos));
        }
    }
    Nav_SteerAlongRoute(bot);
    func_80211020_de(bot);
    Nav_UpdatePlayerSteering(bot);
}
#endif
