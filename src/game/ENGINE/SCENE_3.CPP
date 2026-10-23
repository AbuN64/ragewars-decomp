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

extern DraftStreamPair D_801031F8;
extern char D_00285160[];
extern s32 func_8028FE3C_de(void *, s32, s32, s32 *);
extern void **func_80254408_de(s32, void *, s32, s32, void *, void *, void *);
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

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
typedef struct SceneBuffer { s32 stride,count; u8 data[0]; } SceneBuffer;
typedef struct SceneHandle { s32 *data; s32 rest[3]; } SceneHandle;
typedef struct SceneCell { u8 pad0[16]; s32 loaded; } SceneCell;
typedef struct SceneProp { u8 pad0[0x20]; SceneHandle *resource; u8 pad24[4]; u32 matrix[16]; u8 pad68[0x70]; u16 flags; u8 padDA[14]; } SceneProp;
typedef struct ScenePoint { s16 x,y,z; } ScenePoint;
typedef struct SceneWorld { u8 pad0[0x30]; s32 id; u8 pad34[0x30]; s32 catalog; s32 *grid; u8 pad6C[0x1C]; s32 *packed; u8 pad8C[0x6C]; SceneHandle *handle; u8 padFC[0x1B200]; f32 maximumHeight; } SceneWorld;
extern Gfx *D_80110634;
extern char D_0028798C[],D_800C5210_de[],D_800C522C_de[];
extern void func_8026D980_de(void),func_8026D9D0_de(void);
extern SceneHandle *func_8025343C_de(s32,s32,u32,void *);
extern s32 func_80250A64_de(SceneProp *);
extern s32 func_80250A8C_de(SceneProp *);
extern SceneHandle **func_80250B24_de(SceneProp *,s32,s32,SceneHandle **);
extern void func_802504B0_de(SceneProp *,s32);
extern SceneHandle *func_802507AC_de(SceneProp *,s32);
extern void func_80270910_de(f32 *,u32 *);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
static inline u32 *sceneMatrix(SceneProp *prop) { return prop->matrix; }
/* 106 aligned edits from the 348-word target; remaining: loop scheduling and register allocation. */
void Scene_BuildCachedGeometry(SceneWorld *world) {
    f32 matrix[16];
    CVector3 position;
    CVector3 transformed;
    SceneHandle *resources[3000];
    SceneProp *props[512];
    s32 resourceSize;
    s32 xCount;
    s32 z;
    s32 lastX;
    s32 lastZ;
    SceneCell *cells;
    s32 propCount;
    SceneProp **nextProp;
    Gfx *firstGfx;
    s32 row;
    SceneHandle **nextResource;
    SceneHandle *resource;
    SceneHandle *cache;
    SceneHandle *geometry;
    SceneBuffer *propRecords;
    s32 *resourceData;
    SceneBuffer *points;
    SceneProp *prop;
    SceneProp *propBase;
    ScenePoint *point;
    s32 zCount;
    s32 x;
    s32 cell;
    s32 key;
    s32 p;
    s32 pointIndex;
    s32 pointCount;
    s32 model;
    s32 resourceBytes;
    s32 propBytes;
    s32 gfxBytes;
    s32 propOffset;
    s32 gfxOffset;
    s32 *packed;
    f32 height;
    f32 maximum;

    nextResource = resources;
    nextProp = props;
    z = 0;
    firstGfx = D_80110634;
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RNX, FRUSTRATIO_2);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RNY, FRUSTRATIO_2);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RPX, (u16)-FRUSTRATIO_2);
    gSPMoveWord(D_80110634++, G_MW_CLIP, G_MWO_CLIP_RPY, (u16)-FRUSTRATIO_2);
    func_8026D980_de();
    xCount = ((SceneBuffer *)func_8028FDB4_de(world->grid, 0))->count;
    zCount = ((SceneBuffer *)func_8028FDB4_de(world->grid, 2))->count;
    cells = (SceneCell *)((SceneBuffer *)func_8028FDB4_de(world->grid, 4) + 1);
    lastZ = zCount - 1;
    lastX = xCount - 1;
    for (row = 0; z <= lastZ; z++, row += xCount) {
        for (x = 0; x <= lastX; x++) {
            cell = x + row;
            if (cells[cell].loaded == 0) {
                key = func_8028FE3C_de(world->catalog, world->id, cell, &resourceSize);
                resource = func_8025193C_de(0, key, key, resourceSize, 4, world, D_0028798C, D_800C5210_de, 1);
                if (resource != 0) {
                    resourceData = resource->data;
                    if (*resourceData != 0) {
                        func_80253670_de(0, resource);
                        *nextResource++ = resource;
                        propRecords = func_8028FDB4_de(resourceData, 0);
                        propCount = propRecords->count;
                        propBase = (SceneProp *)(propRecords + 1);
                        for (p = 0; p < propCount; p++) {
                            prop = &propBase[p];
                            if (!(prop->flags & 0x40)) {
                                prop->resource = resource;
                                if ((prop->flags & 4) || func_80250A64_de(prop) < 0) {
                                    *nextProp++ = prop;
                                } else {
                                    model = func_80250A64_de(prop);
                                    nextResource = func_80250B24_de(prop, model, func_80250A8C_de(prop), nextResource);
                                    func_802504B0_de(prop, 0);
                                }
                                geometry = func_802507AC_de(prop, func_80250A8C_de(prop));
                                if (geometry != 0) {
                                    points = func_8028FDB4_de(geometry->data, 0);
                                    pointCount = points->count;
                                    func_80270910_de(matrix, sceneMatrix(prop));
                                    for (pointIndex = 0; pointIndex < pointCount; pointIndex++) {
                                        point = (ScenePoint *)(points->data + pointIndex * points->stride);
                                        position.x = (f32)point->x;
                                        position.y = (f32)point->y;
                                        position.z = (f32)point->z;
                                        func_80272898_de(matrix, &position, &transformed);
                                        height = transformed.y;
                                        maximum = world->maximumHeight;
                                        if (!(height <= maximum)) height = maximum;
                                        world->maximumHeight = height;
                                    }
                                    func_80253754_de(0, geometry);
                                }
                            }
                        }
                    }
                    func_80253754_de(0, resource);
                }
            }
        }
    }
    *nextResource = 0;
    *nextProp++ = 0;
    func_8026D9D0_de();
    nextResource++;
    resourceBytes = (u8 *)nextResource - (u8 *)resources;
    gfxOffset = ((resourceBytes + 7) & ~7) + 0x18;
    propBytes = (u8 *)nextProp - (u8 *)props;
    propOffset = gfxOffset;
    gfxOffset += ((propBytes + 7) & ~7);
    gSPEndDisplayList(D_80110634++);
    gfxBytes = (u8 *)D_80110634 - (u8 *)firstGfx;
    cache = func_8025343C_de(0, gfxOffset + ((gfxBytes + 7) & ~7), 3U, D_800C522C_de);
    world->handle = cache;
    packed = cache->data;
    world->packed = packed;
    *packed = 3;
    world->packed[1] = 0x18;
    world->packed[2] = propOffset;
    world->packed[3] = gfxOffset;
    func_802BD3A0_de(func_8028FDB4_de(world->packed, 0), resources, resourceBytes);
    func_802BD3A0_de(func_8028FDB4_de(world->packed, 1), props, propBytes);
    func_802BD3A0_de(func_8028FDB4_de(world->packed, 2), firstGfx, gfxBytes);
    D_80110634 = firstGfx;
}
#else
INCLUDE_ASM("span_1000", Scene_BuildCachedGeometry);
#endif
