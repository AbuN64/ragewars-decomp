#include "shared/world.h"

/** Return an indexed record from the world's strided table. */
void *func_8028CE78_de(Shared_World *world, s32 index) {
    StridedTable *table = world->stridedRecords;
    void *base = table;
    char *bytes = base;
    s32 stride = table->stride;
    return bytes + (index * stride + 8);
}
