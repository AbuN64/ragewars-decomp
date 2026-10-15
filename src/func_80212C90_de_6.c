#include "shared/route_chase_records.h"
#include "span_C76B0/data.h"
/* Runs a computer player's chase step toward the object at 0x68: without a target id at 0xBC it
   switches to mode 2 and without an object it only updates; farther than D_800C2380_eu from its goal
   node it heads there through func_80208410_de, otherwise it takes mode 8 once arrived or copies the
   object's position to 0x2C; then, within D_800C2384_eu of the object and not yet arrived, it marks
   arrival at 0x238 and plans a new route through func_8020B95C_de to pick the next goal node. */
#include "types.h"
#include "common/types_8a8189af7b05.h"













extern RouteChaseGraph D_8013B364;



extern void func_80209874_de(RouteChaseBot *bot, s32 mode);
extern void func_80211020_de(RouteChaseBot *bot);
extern f32 func_80209948_de(RouteChaseBot *bot, s32 node);
extern void func_80208410_de(RouteChaseBot *bot);
extern void func_80208EB0_de(RouteChaseBot *bot);
extern f32 func_802726F8_de(Vec3 *a, Vec3 *b);
extern s32 func_8020B95C_de(RouteChaseGraph *graph, s32 from, s32 to, s32 *path, s32 flags);
extern void func_80209804_de(RouteChaseBot *bot);

void func_80212FBC_de(RouteChaseActor *actor)
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
        func_80209874_de(bot, 2);
        return;
    }
    if (bot->target == 0) {
        func_80211020_de(bot);
        return;
    }
    dist = func_80209948_de(bot, bot->goal);
    if (bot->node != bot->goal && D_800C2380_eu < dist) {
        func_80208410_de(bot);
    } else if (bot->arrived != 0) {
        func_80209874_de(bot, 8);
    } else {
        bot->dest = bot->target->pos;
    }
    func_80211020_de(bot);
    if (bot->target != 0) {
        func_80208EB0_de(bot);
        if (func_802726F8_de(&bot->self->pos, &bot->target->pos) < D_800C2384_eu && bot->arrived == 0) {
            bot->arrived = 1;
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            func_8020B95C_de(graph, bot->goal, bot->goal, path, 0);
            start = path[0];
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            len = func_8020B95C_de(graph, start, bot->goal, path, 0);
            func_80209804_de(bot);
            bot->goal = path[len - 1];
        }
    }
}


