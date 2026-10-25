#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "sdk/SCHED/world_actorscan.H"
#include "RENDER_4/8028FD2C_6.H"

s32 func_8028DF90_de(Shared_World *world, s32 arg1) {
    void *temp_v0;
    temp_v0 = Render_GetPackSection(world->bitSections, 1);
    Render_GetPackSection(temp_v0, 0);
    return Render_GetPackSection(temp_v0, 1) + arg1;
}

void func_8028DFE4_de(WorldSortEntry *arg0, WorldSortEntry *arg1) {
    WorldSortEntry tmp;

    tmp = *arg0;
    *arg0 = *arg1;
    *arg1 = tmp;
}

s32 func_8028E020_de(WorldSortEntry *arg0, WorldSortEntry *arg1) {
    s32 result;
    result = 1;
    if ((arg0->distance) < (arg1->distance)) {
        result = -1;
    }
    return result;
}

s32 func_8028E044_de(WorldSortEntry *arg0, WorldSortEntry *arg1)
{
  f32 new_var;
  s32 var_v0;
  new_var = arg0->distance;
  var_v0 = 1;
  if ((arg1->distance) < new_var)
  {
    var_v0 = -1;
  }
  return var_v0;
}

void func_8028E068_de(Shared_World *world) {
    s32 found;
    s32 clear_index;
    LevelActor *record;
    struct Shared_Pickup **clear_ptr;
    struct Shared_Pickup **out;
    s32 wanted_type;

    found = 0;
    clear_index = 15;
    record = world->actors;
    world->specialActorCount = 0;
    do {
        world->specialActors[clear_index] = 0;
        clear_index--;
    } while (clear_index >= 0);

    if (world->actorCount > 0) {
        clear_index = 0;
        wanted_type = 14;
        do {
            if (((struct Def *)record->definition)->type == wanted_type) {
                world->specialActors[found] = record;
                found++;
            }
            if (found >= 16) {
                break;
            }
            clear_index++;
            if (clear_index >= world->actorCount) {
                break;
            }
            record++;
        } while (1);
    }
    world->specialActorCount = found;
}

extern LevelActor *D_800F3CF8[4];
extern LevelActor *D_800F3D08;
extern s32 func_8028B25C_de(Shared_World *world, s32 id);
void World_FindTrackedActors(Shared_World *world) {
    LevelActor *actor = world->actors;
    s32 i;
    D_800F3D08 = 0;
    for (i = 0; i < 4; i++) {
        D_800F3CF8[i] = 0;
    }
    for (i = 0; i < world->actorCount; actor++, i++) {
        struct Def *def = (struct Def *)actor->definition;
        if (def->type == 3) {
            if (func_8028B25C_de(&g_world, def->id) == 0xBD7) {
                D_800F3D08 = actor;
                return;
            }
        } else if (def->type == 10) {
            switch (actor->type) {
            case 0x653:
                D_800F3CF8[0] = actor;
                break;
            case 0x654:
                D_800F3CF8[1] = actor;
                break;
            case 0x655:
                D_800F3CF8[2] = actor;
                break;
            case 0x656:
                D_800F3CF8[3] = actor;
                break;
            }
        }
    }
}
