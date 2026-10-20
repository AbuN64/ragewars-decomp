#include "include_asm.h"
#include "COMMON/ROUTE_CHASE_RECORDS.H"

#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_80212E30_eu);
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
INCLUDE_DATA("span_1000", func_80212FBC_de_padding_13BF4);
#endif
