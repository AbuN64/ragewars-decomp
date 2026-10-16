#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_80286050.h"
void func_802897B4_de(World37 *world, Vec3 *point, Item37 **output, s32 *total) {
    Region37 *region;
    s32 i, found, regionCount, itemCount;
    f32 x, z;
    Items37 *items;
    Item37 *item, *base;
    region = 0;
    i = 0;
    found = 0;
    x = point->x; z = point->z;
    regionCount = world->count;
    for (; i < regionCount; i++) {
        Bounds2D37 *bounds = world->regions[i].bounds;
        if (bounds->maxX < x || x < bounds->minX ||
            bounds->maxZ < z || z < bounds->minZ) continue;
        region = &world->regions[i];
        break;
    }
    if (region == 0) {
        *total = 0;
    } else {
        items = func_8028FDB4_de(region->resource->data, 2);
        itemCount = items->count;
        base = items->items;
        for (i = 0; i < itemCount; i++) {
            Bounds37 *bounds;
            item = &base[i];
            bounds = &item->bounds;
            if (bounds->maxX > point->x && bounds->maxY > point->y && bounds->maxZ > point->z &&
                bounds->minX <= point->x && bounds->minY <= point->y && bounds->minZ <= point->z) {
                output[found++] = item;
                if (found == 10) break;
            }
        }
        *total = found;
    }
}
