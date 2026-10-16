#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802536F4.h"
#include "shared/func_804220A8_de_closed.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_80286050.h"

extern DraftStreamPair D_801031F8;
extern char D_00285160[];
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern void **func_80254408_de(s32, void *, s32, s32, void *, void *, void *);
extern DraftStreamHandle *func_8025193C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);
extern void func_80253670_de(void *, Node80253610 *);
extern void func_80253754_de(void *, Node80253610 *);

void func_80288470_de(DraftStreamWorld *world)
{
    s32 xCount, firstX, count;
    DraftStreamCell *cells;
    DraftStreamViewer *viewers, *viewer;
    DraftStreamTable *table;
    f32 *xLow, *xHigh, *zLow, *zHigh;
    DraftStreamCell *cell;
    DraftStreamHandle *resource;
    DraftStreamEntry *entry;
    s32 zCount, lastX, firstZ, lastZ;
    s32 x, z, row, loaded, size, visible, slot;

    viewers = (void *)D_80140FE8_de.object;
    if (viewers) {
        firstX = count = 0;
        table = func_8028FDB4_de(world->grid, 0);
        firstZ=0;
        xLow = table->data.coordinates;
        xCount = table->count;
        table = func_8028FDB4_de(world->grid, 1);
        xHigh = table->data.coordinates;
        lastX = xCount - 1;
        table = func_8028FDB4_de(world->grid, 2);
        zLow = table->data.coordinates;
        zCount = table->count;
        table = func_8028FDB4_de(world->grid, 3);
        zHigh = table->data.coordinates;
        table = func_8028FDB4_de(world->grid, 4);
        lastZ = zCount - 1;
        cells = table->data.cells;
        while (firstX < xCount && xHigh[firstX] < D_801031F0.min.x) firstX++;
        while (lastX >= 0 && D_801031F8.second < xLow[lastX]) lastX--;
        while (firstZ < zCount && zHigh[firstZ] < D_801031F8.first) firstZ++;
        while (lastZ >= 0 && D_800FF200.second < zLow[lastZ]) lastZ--;
        entry = world->entries;
        { s32 focusX,focusZ;
        if (world->specialEnabled == 1) {
            focusX = (s32)((viewers->position.x - world->originX) / world->cellX);
            focusZ = (s32)((viewers->position.z - world->originZ) / world->cellZ);
        } else focusZ = focusX = -1;
        if (focusX < 0 || focusX >= xCount || focusZ < 0 || focusZ >= zCount) world->specialPresent = 0;
        else {
            world->specialPresent = 1;
            world->special = (void *)func_80254408_de(0, world->specialTable, focusX + focusZ * xCount + 1,
                world->resourceKey, world, D_00285160, D_800C5220_de);
            func_80253670_de(0, (void *)world->special);
            func_80296020_de(world->specialState, focusX, focusZ, world->special->data, &viewers->position);
        }
        }
        z = firstZ;
        if(z<=lastZ) {
        row = z * xCount;
        do {
            for (x = firstX, slot=x+row; x <= lastX; x++,slot=x+row) {
                        cell = &cells[slot];
                if (cell->occupied) continue;
                visible = 0;
                for (viewer = viewers; viewer; viewer = viewer->next) {
                    if (viewer->minimum.x < cell->maxX && cell->minX < viewer->maximum.x &&
                        cell->maxZ > viewer->minimum.z && cell->minZ < viewer->maximum.z) {
                        visible = 1;
                        break;
                    }
                }
                if (visible) {
                    loaded = func_8028FE3C_de(world->table, world->key, slot, &size);
                    resource = func_8025193C_de(0, loaded, loaded, size, 8, world,
                                              D_0028798C, D_800C5210_de, 0);
                    if (resource) {
                        if (resource->data->count) {
                            entry->resource = resource;
                            entry->cell = cell;
                            entry->x = x;
                            entry->z = z;
                            entry++;
                            count++;
                            if (count == 128) goto finished;
                        } else func_80253754_de(0,(void *)resource);
                    }
                }
            }
            row+=xCount; z++;
        } while(z<=lastZ);
        }
finished:
        world->entryCount = count;
        world->activeCount = count;
    }
}
