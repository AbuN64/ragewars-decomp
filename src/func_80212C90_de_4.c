#include "shared/route_chase_records.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "common/unused.h"
#include "types.h"
#include "span_1000/code_802106E0.h"
/* Runs a computer player's patrol step: starts its route at 0x224 on the first route of D_8011FE88,
   or random roaming (-2) when there are none; once within D_800C23B0_eu_x of its goal node it advances the
   route position at 0x228 (wrapping at the route length) and drops the goal; a dropped goal is then
   taken from the route through func_8028D244_de and func_8020CB3C_de, or a random node of D_8013B364 when
   roaming; finally runs func_80208410_de, func_80211020_de and func_80208AAC_de. */













extern RoutePatrolNodes D_8013B364;



extern Clip *func_8028D218_de(PatrolRouteSet *set, s32 route);
extern s32 func_8028D244_de(PatrolRouteSet *set, s32 route, s32 pos);
extern s32 func_8020CB3C_de(RoutePatrolNodes *list, s32 id);
extern void *func_8020C994_de(RoutePatrolNodes *list, s32 index);
extern void *func_8020993C_de(PatrolBot *bot);
extern f32 func_802726F8_de(void *a, void *b);
extern void func_80208410_de(PatrolBot *bot);
extern void func_80211020_de(PatrolBot *bot);
extern void func_80208AAC_de(PatrolBot *bot);

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
            func_8028D218_de(routes, bot->route);
        } else {
            bot->route = -2;
            bot->routePos = -1;
        }
        bot->goal = -1;
    }
    if (bot->node == bot->goal) {
        pos = func_8020993C_de(bot);
        if (func_802726F8_de(pos, func_8020C994_de(nodes, bot->goal)) < D_800C23B0_eu_x) {
            if (bot->route >= 0) {
                route = func_8028D218_de(&D_8011FE88, bot->route);
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
            bot->goal = func_802744D4_de() % nodes->count;
        } else {
            bot->goal = func_8020CB3C_de(nodes, func_8028D244_de(&D_8011FE88, bot->route, bot->routePos));
        }
    }
    func_80208410_de(bot);
    func_80211020_de(bot);
    func_80208AAC_de(bot);
}

