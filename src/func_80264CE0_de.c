#include "shared/world.h"
#include "span_1000/code_802646F4.h"
#include "types.h"

/* Snapshots every actor into the global replay table: copies its 0x70-byte block at 0x5E0, its position, its value at 0x6C and the handle func_8028B350_de finds for its identifier. */











extern ActorList D_80145040;
extern Snapshot D_8010BC40;

extern s32 func_8028B350_de(void *table, s32 id);

void func_80264CE0_de(void) {
    s32 i;
    ActorRecAt5E0 *actor;
    Snapshot *snapshot;
    ActorList *list;

    list = &D_80145040;
    snapshot = &D_8010BC40;
    for (i = 0; i < list->count; i++) {
        actor = &list->actors[i];
        snapshot->blocks[i] = actor->block;
        snapshot->positions[i] = actor->position;
        snapshot->values[i] = actor->field6C;
        snapshot->handles[i] = func_8028B350_de(&D_8011FE88, actor->id);
        list = &D_80145040;
    }
}
