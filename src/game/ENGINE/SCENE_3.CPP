#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/80286050.H"
#include "SCENE/802508E0_4.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"

/* Tag of the cell grid packs (the first .rodata of this unit; the items overlay reads it too). */
const char D_800C5210_de[] = "grid section";
extern DraftStreamPair D_801031F8;
extern char D_00285160[];
extern s32 Render_LocatePackSection(void *, s32, s32, s32 *);
extern void **func_80254408_de(s32, void *, s32, s32, void *, void *, void *);
extern void Scene_LockResource(void *, Node80253610 *);
extern void Scene_UnlockResource(void *, Node80253610 *);

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

    viewers = (void *)D_80140FE8_de.camera;
    if (viewers) {
        firstX = count = 0;
        table = Render_GetPackSection(world->grid, 0);
        firstZ=0;
        xLow = table->data.coordinates;
        xCount = table->count;
        table = Render_GetPackSection(world->grid, 1);
        xHigh = table->data.coordinates;
        lastX = xCount - 1;
        table = Render_GetPackSection(world->grid, 2);
        zLow = table->data.coordinates;
        zCount = table->count;
        table = Render_GetPackSection(world->grid, 3);
        zHigh = table->data.coordinates;
        table = Render_GetPackSection(world->grid, 4);
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
                world->resourceKey, world, D_00285160, "Vis Info");
            Scene_LockResource(0, (void *)world->special);
            System_DecodeRegionGrid(world->specialState, focusX, focusZ, world->special->data, &viewers->position);
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
                    loaded = Render_LocatePackSection(world->table, world->key, slot, &size);
                    resource = Scene_RequestResource(0, loaded, loaded, size, 8, world,
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
                        } else Scene_UnlockResource(0,(void *)resource);
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

#include "COMMON/GFX.H"
#include "gbi.h"
/* One geometry vertex of a prop's collision mesh (stride from its section header). */
typedef struct ScenePoint { s16 x, y, z; } ScenePoint;
extern Gfx *g_displayListCursor;
extern void Render_BeginModelBatch(void), Render_FlushModelBatch(void);
extern struct Shape_typemap_165 *Scene_AllocateResource(s32, s32, u32, void *);
extern s32 Scene_GetPropModelIndex(Object_func_80288EA8_de *object);
extern s32 Scene_GetPropGeometryIndex(Object_func_80288EA8_de *object);
extern DraftStreamHandle **Scene_CollectPropResources(Object_func_80288EA8_de *object, s32 model, s32 index, DraftStreamHandle **nextResource);
extern void Instance_DrawModel(Object_func_80288EA8_de *object, void *camera);
extern DraftStreamHandle *Instance_AcquireGeometry(Object_func_80288EA8_de *object, s32 index);
extern void Rsp_ConvertMatrixToFloat(f32 *dst, PackedMatrixWords *src);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
void Scene_BuildCachedGeometry(DraftStreamWorld *world) {
    f32 matrix[16];
    CVector3 position;
    CVector3 transformed;
    DraftStreamHandle *resources[3000];
    Object_func_80288EA8_de *props[512];
    s32 resourceSize;
    s32 xCount;
    s32 z;
    s32 lastX;
    s32 lastZ;
    DraftStreamCell *cells;
    DraftStreamCell *cell;
    s32 propCount;
    Object_func_80288EA8_de **nextProp;
    Gfx *firstGfx;
    s32 row;
    DraftStreamHandle **nextResource;
    DraftStreamHandle *resource;
    struct Shape_typemap_165 *handle;
    DraftStreamHandle *geometry;
    DraftStreamTable *table;
    DraftStreamData *resourceData;
    DraftStreamTable *points;
    Object_func_80288EA8_de *prop;
    Object_func_80288EA8_de *objects;
    ScenePoint *point;
    s32 zCount;
    s32 x;
    s32 slot;
    s32 key;
    s32 p;
    s32 i;
    s32 count;
    s32 model;
    s32 resourceBytes;
    s32 propBytes;
    s32 gfxBytes;
    s32 offset;
    s32 *cache;
    f32 height;
    f32 maximum;
    s32 firstX;
    s32 size;

    nextResource = resources;
    nextProp = props;
    firstX = 0;
    firstGfx = g_displayListCursor;
    gDPPipeSync(g_displayListCursor++);
    gDPSetCycleType(g_displayListCursor++, G_CYC_2CYCLE);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RNX, FRUSTRATIO_2);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RNY, FRUSTRATIO_2);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RPX, (u16)-FRUSTRATIO_2);
    gSPMoveWord(g_displayListCursor++, G_MW_CLIP, G_MWO_CLIP_RPY, (u16)-FRUSTRATIO_2);
    z = 0;
    Render_BeginModelBatch();
    xCount = ((DraftStreamTable *)Render_GetPackSection(world->grid, 0))->count;
    zCount = ((DraftStreamTable *)Render_GetPackSection(world->grid, 2))->count;
    cells = ((DraftStreamTable *)Render_GetPackSection(world->grid, 4))->data.cells;
    lastZ = zCount - 1;
    lastX = xCount - 1;
    if (z <= lastZ) {
        row = z * xCount;
        do {
            for (x = firstX; x <= lastX; x++) {
                slot = x + row;
                cell = &cells[slot];
                if (cell->occupied == 0) {
                    key = Render_LocatePackSection(world->table, world->key, slot, &resourceSize);
                    resource = Scene_RequestResource(0, key, key, resourceSize, 4, (s32)world, D_0028798C, D_800C5210_de, 1);
                    if (resource != 0) {
                        resourceData = resource->data;
                        if (resourceData->count != 0) {
                            Scene_LockResource(0, (Node80253610 *)resource);
                            *nextResource++ = resource;
                            table = Render_GetPackSection(resourceData, 0);
                            propCount = table->count;
                            objects = table->data.objects;
                            for (p = 0; p < propCount; p++) {
                                prop = &objects[p];
                                if (!(prop->flags & 0x40)) {
                                    prop->resource = resource;
                                    if ((prop->flags & 4) || Scene_GetPropModelIndex(prop) < 0) {
                                        *nextProp++ = prop;
                                    } else {
                                        model = Scene_GetPropModelIndex(prop);
                                        nextResource = Scene_CollectPropResources(prop, model, Scene_GetPropGeometryIndex(prop), nextResource);
                                        Instance_DrawModel(prop, 0);
                                    }
                                    geometry = Instance_AcquireGeometry(prop, Scene_GetPropGeometryIndex(prop));
                                    if (geometry != 0) {
                                        points = Render_GetPackSection(geometry->data, 0);
                                        count = points->count;
                                        Rsp_ConvertMatrixToFloat(matrix, &prop->transform);
                                        for (i = 0; i < count; i++) {
                                            point = (ScenePoint *)(points->data.bytes + i * points->stride);
                                            position.x = (f32)point->x;
                                            position.y = (f32)point->y;
                                            position.z = (f32)point->z;
                                            Particle_TransformPoint(matrix, &position, &transformed);
                                            height = transformed.y;
                                            maximum = world->maximumHeight;
                                            if (!(height <= maximum)) height = maximum;
                                            world->maximumHeight = height;
                                        }
                                        Scene_UnlockResource(0, (Node80253610 *)geometry);
                                    }
                                }
                            }
                        }
                        Scene_UnlockResource(0, (Node80253610 *)resource);
                    }
                }
            }
            row += xCount;
            z++;
        } while (z <= lastZ);
    }
    *nextResource++ = 0;
    *nextProp++ = 0;
    Render_FlushModelBatch();
    /* Cache blob: header {3 sections, offsets}, then the resource list, the prop list and the display list, each 8-aligned. */
    resourceBytes = (u8 *)nextResource - (u8 *)resources;
    offset = ((resourceBytes + 7) & ~7) + 0x18;
    propBytes = (u8 *)nextProp - (u8 *)props;
    size = propBytes + 7;
    size &= ~7;
    count = offset;
    offset += size;
    gSPEndDisplayList(g_displayListCursor++);
    gfxBytes = (u8 *)g_displayListCursor - (u8 *)firstGfx;
    handle = Scene_AllocateResource(0, offset + ((gfxBytes + 7) & ~7), 3, "Multi player data");
    world->cacheHandle = handle;
    cache = handle->data;
    world->cache = cache;
    cache[0] = 3;
    world->cache[1] = 0x18;
    world->cache[2] = count;
    world->cache[3] = offset;
    func_802BD3A0_de(Render_GetPackSection(world->cache, 0), resources, resourceBytes);
    func_802BD3A0_de(Render_GetPackSection(world->cache, 1), props, propBytes);
    func_802BD3A0_de(Render_GetPackSection(world->cache, 2), firstGfx, gfxBytes);
    g_displayListCursor = firstGfx;
}
