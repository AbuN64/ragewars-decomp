#include "types.h"
#include "common/types_8a8189af7b05.h"

typedef struct DraftStreamCell { f32 minX, minZ, maxX, maxZ; s32 occupied; } DraftStreamCell;
typedef struct DraftStreamTable {
    s32 stride, count;
    union { f32 coordinates[1]; DraftStreamCell cells[1]; } data;
} DraftStreamTable;
typedef struct DraftStreamData { s32 count; } DraftStreamData;
typedef struct DraftStreamHandle { DraftStreamData *data; } DraftStreamHandle;
typedef struct DraftStreamEntry {
    DraftStreamHandle *resource; DraftStreamCell *cell; s16 x, z;
} DraftStreamEntry;
typedef struct DraftStreamViewer {
    s32 pad0; struct DraftStreamViewer *next;
    char pad8[0x120]; Vec3 position;
    char pad134[0x234]; Vec3 minimum, maximum;
} DraftStreamViewer;
typedef struct DraftStreamWorld {
    char pad0[0x30]; s32 key;
    char pad34[0xC]; s32 resourceKey;
    char pad44[0x20]; void *table, *grid;
    char pad6C[0x20]; void *specialTable;
    char pad90[0x1470]; s32 entryCount, activeCount;
    DraftStreamEntry entries[128];
    char pad1B08[0x19BA8]; DraftStreamHandle *special;
    char specialState[0x25C];
    f32 originX, originZ, cellX, cellZ;
    char pad1B920[8]; s32 specialPresent, specialEnabled;
} DraftStreamWorld;
typedef struct DraftStreamPair { f32 first, second; } DraftStreamPair;
extern DraftStreamViewer *D_80140FE8_de;
extern f32 D_801031F0;
extern DraftStreamPair D_801031F8, D_800FF200;
extern char D_00285160[], D_0028798C[], D_800C5220_de[], D_800C5210_de[];
extern void *func_8028FDB4_de(void *, s32);
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern DraftStreamHandle *func_80254408_de(s32, void *, s32, s32, void *, void *, void *);
extern DraftStreamHandle *func_8025193C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
extern void func_80253670_de(s32, DraftStreamHandle *);
extern void func_80253754_de(s32, DraftStreamHandle *);
extern void func_80296020_de(void *, s32, s32, DraftStreamData *, Vec3 *);

void func_80288470_de(void *arg0)
{
    DraftStreamWorld *world = arg0;
    DraftStreamViewer *viewers, *viewer;
    DraftStreamTable *xLow, *xHigh, *zLow, *zHigh, *cells;
    DraftStreamCell *cell;
    DraftStreamHandle *resource;
    DraftStreamEntry *entry;
    s32 xCount, zCount, firstX, lastX, firstZ, lastZ, count;
    s32 x, z, row, loaded, size, visible;

    viewers = D_80140FE8_de;
    if (viewers) {
        firstX = firstZ = count = 0;
        xLow = func_8028FDB4_de(world->grid, 0);
        xCount = xLow->count;
        xHigh = func_8028FDB4_de(world->grid, 1);
        lastX = xCount - 1;
        zLow = func_8028FDB4_de(world->grid, 2);
        zCount = zLow->count;
        zHigh = func_8028FDB4_de(world->grid, 3);
        lastZ = zCount - 1;
        cells = func_8028FDB4_de(world->grid, 4);
        while (firstX < xCount && xHigh->data.coordinates[firstX] < D_801031F0) firstX++;
        while (lastX >= 0 && D_801031F8.second < xLow->data.coordinates[lastX]) lastX--;
        while (firstZ < zCount && zHigh->data.coordinates[firstZ] < D_801031F8.first) firstZ++;
        while (lastZ >= 0 && D_800FF200.second < zLow->data.coordinates[lastZ]) lastZ--;
        entry = world->entries;
        if (world->specialEnabled == 1) {
            x = (s32)((viewers->position.x - world->originX) / world->cellX);
            z = (s32)((viewers->position.z - world->originZ) / world->cellZ);
        } else x = z = -1;
        if (x < 0 || x >= xCount || z < 0 || z >= zCount) world->specialPresent = 0;
        else {
            world->specialPresent = 1;
            world->special = func_80254408_de(0, world->specialTable, x + z * xCount + 1,
                world->resourceKey, world, D_00285160, D_800C5220_de);
            func_80253670_de(0, world->special);
            func_80296020_de(world->specialState, x, z, world->special->data, &viewers->position);
        }
        row = firstZ * xCount;
        for (z = firstZ; z <= lastZ; z++, row += xCount) {
            for (x = firstX; x <= lastX; x++) {
                cell = &cells->data.cells[x + row];
                if (cell->occupied) continue;
                visible = 0;
                for (viewer = viewers; viewer; viewer = viewer->next) {
                    if (viewer->minimum.x < cell->maxX && cell->minX < viewer->maximum.x &&
                        viewer->minimum.z < cell->maxZ && cell->minZ < viewer->maximum.z) {
                        visible = 1;
                        break;
                    }
                }
                if (visible) {
                    loaded = func_8028FE3C_de(world->table, world->key, x + row, &size);
                    resource = func_8025193C_de(0, loaded, loaded, size, 8, world,
                                              D_0028798C, D_800C5210_de, 0);
                    if (resource) {
                        if (!resource->data->count) func_80253754_de(0, resource);
                        else {
                            entry->resource = resource;
                            entry->cell = cell;
                            entry->x = x;
                            entry->z = z;
                            entry++;
                            count++;
                            if (count == 128) goto finished;
                        }
                    }
                }
            }
        }
finished:
        world->entryCount = count;
        world->activeCount = count;
    }
}
