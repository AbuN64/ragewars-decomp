#include "span_1000/code_8028B64C.h"
#include "types.h"

/* Searches the counted pointer list at offset 0x1B620 of a world record for the first entry whose definition id at 0x18->0xC equals the given id, returning it or null. */







EntryRecAt18V4 *func_8028C108_de(World_func_8028C108_de *world, s32 id) {
    s32 i;
    EntryRecAt18V4 *found = 0;

    for (i = 0; i < world->count; i++) {
        if (world->list[i]->def->unkC == id) {
            found = world->list[i];
            break;
        }
    }
    return found;
}
