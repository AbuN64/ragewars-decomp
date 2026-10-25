#include "include_asm.h"
#include "COMMON/ROUTE_CHASE_RECORDS.H"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
#define func_80212E30_eu_x func_80212E30_eu
#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/SELF.H"
/* Runs a computer player's patrol step: starts its route at 0x224 on the first route of D_8011FE88,
   or random roaming (-2) when there are none; once within D_800C23B0_eu_x of its goal node it advances the
   route position at 0x228 (wrapping at the route length) and drops the goal; a dropped goal is then
   taken from the route through Engine_GetPlatformRoutePoint and func_8020CB3C_de, or a random node of D_8013B364 when
   roaming; finally runs Nav_SteerAlongRoute, func_80211020_de and Nav_UpdatePlayerSteering. */













extern RoutePatrolNodes D_8013B364;



extern Clip *Engine_GetPlatformRoute(PatrolRouteSet *set, s32 route);
extern s32 Engine_GetPlatformRoutePoint(PatrolRouteSet *set, s32 route, s32 pos);
extern s32 Nav_FindNearestPointIndex(RoutePatrolNodes *list, s32 id);
extern void *Nav_GetGraphPoint(RoutePatrolNodes *list, s32 index);
extern void *Nav_GetControllerPosition(PatrolBot *bot);
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
        pos = Nav_GetControllerPosition(bot);
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
            bot->goal = Nav_FindNearestPointIndex(nodes, Engine_GetPlatformRoutePoint(&D_8011FE88, bot->route, bot->routePos));
        }
    }
    Nav_SteerAlongRoute(bot);
    func_80211020_de(bot);
    Nav_UpdatePlayerSteering(bot);
}
#else
INCLUDE_ASM("span_1000", func_80212E30_eu);
#endif
#endif

#if !(defined(VERSION_DE))
/* Reset the two bot state words reached through the actor and player records. */
void func_80212FDC_eu(void *object) {
    RouteChaseActor *actor = object;
    RouteChaseBot *bot = actor->player->bot;
    bot->resetWord220 = 0;
    bot->resetWord224 = -1;
}
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int func_80212FBC_de_padding_13BF4[3] = {
    0x4600B306, 0x4600B03C, 0x00000000,
};
#endif
#if defined(VERSION_EU_X)
unsigned int func_80212FBC_de_padding_13BF4[3] = {
    0xA2220035, 0x822300CA, 0x10650004,
};
#endif
#endif
