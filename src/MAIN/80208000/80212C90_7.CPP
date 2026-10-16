#include "shared/route_chase_records.h"

/* Reset the two bot state words reached through the actor and player records. */
void func_80212FDC_eu(void *object) {
    RouteChaseActor *actor = object;
    RouteChaseBot *bot = actor->player->bot;
    bot->resetWord220 = 0;
    bot->resetWord224 = -1;
}
