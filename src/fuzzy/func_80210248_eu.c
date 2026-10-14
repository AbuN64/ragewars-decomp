#include "stddef.h"
#include "types.h"

typedef struct Team {
    char pad0[0x92];
    u8 id;
} Team;

typedef struct Racer {
    char pad0[0x8];
    f32 pos[3];
    char pad14[0x5D8 - 0x14];
    Team *team;
    char pad5DC[0x5E4 - 0x5DC];
    s32 stateBits;
} Racer;

typedef struct Rules {
    char pad0[0x24];
    s32 teamsEnabled;
} Rules;

typedef struct World {
    char pad0[0x1860];
    Rules rules;
} World;

typedef struct Chaser {
    Racer *self;
    char pad4[0x34];
    s32 count;
    Racer *target[12];
    s32 cost[10];
    s32 dist[10];
} Chaser;

extern World D_80145040;
Racer *func_8022A5F4_de(World *arg0, u32 arg1);
f32 func_802726F8_de(void *arg0, void *arg1);
s32 func_8021035C_de(Chaser *arg0, s32 arg1);

s32 func_80210248_eu(Chaser *arg0) {
    s32 i;
    s32 count;
    Racer *other;
    World *world;
    Rules *rules;

    for (i = 0; i < 10; i++) {
        arg0->target[i] = NULL;
        arg0->cost[i] = 0;
        arg0->dist[i] = -1;
    }
    count = 0;
    i = count;
    world = &D_80145040;
    rules = &world->rules;
    for (; i < 8; i++) {
        other = func_8022A5F4_de(world, i);
        if (other != NULL && other != arg0->self
            && (rules->teamsEnabled == 0 || other->team->id != arg0->self->team->id)
            && (other->stateBits >> 8) > 0) {
            arg0->target[count] = other;
            arg0->dist[count] = func_802726F8_de(&arg0->self->pos, &other->pos);
            arg0->cost[count] = func_8021035C_de(arg0, count);
            count++;
        }
    }
    arg0->count = count;
    return 1;
}
