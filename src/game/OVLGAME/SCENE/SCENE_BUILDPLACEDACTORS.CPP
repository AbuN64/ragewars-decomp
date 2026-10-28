#include "COMMON/OBJB.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/PPDECOM_UNPACKRESOURCE.H"
#include "COMMON/LEVEL_SPAWN.H"
#include "MENU/8044ACCC.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/WORLD.H"
#include "COMMON/PROPGEOMETRY.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_INITIALIZEPLACEDACTOR.H"
#include "particle/INSTHDR.H"
#include "WEAPONS/BARREL_GETEYEDISTANCESQUARED.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "ENGINE/SCENE_3.H"
extern void Cache_ReplaceResourceBlock(s32 arg0, struct Shape_typemap_165 **handle, struct Shape_typemap_165 *block);

extern struct Shape_typemap_165 *Cache_AllocResourceBlock(s32 arg0, void *handle, s32 size);

extern void *Scene_GetActorDefinition(void *world, s32 id);


extern s32 Scene_FindNearestPlacedObject(World *world, void *data, s32 group, void *buf);

/* Loads every still-empty cell of the level's tile grid: for each row and column whose cell
   record has no resource, fetches the cell's block through SetN64_LocatePackSection and Cache_RequestResource,
   binds and spawns each object of its two object lists (0xE8- and 0x1C8-byte records) and
   releases the spawned handles and the block. */













extern void Simpinst_RegisterModelVariantResources(ObjB *obj, s32 arg1);

extern void *func_8024F6EC_de(ObjB *obj, s32 type);

extern void Statinst_RegisterGeometryResources(ObjA *obj, s32 arg1);

extern void *Statinst_AcquireGeometry(ResourceOwner *owner,s32 index);


extern void Cache_UnlockResource(s32, void *);

extern void Geometry_UnlockMaterialResources(void *handle);


extern s32 SetN64_LocatePackSection(s32, s32, s32, s32 *);

/* Runs func_8044D054_de and func_8044D0F0_de on a large state block, then clears its word at offset
   0x1B444, sets the word at 0x1B448 to 0x15 and copies D_801462CC into the word at 0x1B44C. */

extern struct Shape_func_8021A2D4_de_2 D_801462CC;

extern void Scene_LoadPreviewBufferA(ItemsPreviewStateA *);

extern void Scene_LoadPreviewBufferB(char *);

void Scene_BuildPlacedActors(World *world, struct Shape_typemap_165 **handle) {
    Shared_Placed spawns[8];
    Shared_Placed extra;
    s32 n;
    LevelActor *objects;
    s32 mode;
    struct Shape_typemap_165 *block;
    s32 nspawns;
    LevelNode *node;
    InputRecAt27 *records;
    LevelBlock *hdr;
    s32 i;
    s32 peerIndex;
    s32 playerIndex;
    s32 spawnIndex;
    s32 specialSet;
    s32 *definition;
    InputRecAt27 *rec;
    InputRecAt27 *recWalk;
    LevelActor *objWalk;
    func_8041F2A0_Config *slot;
    s16 value;
    LevelActor *obj;
    LevelActor *other;
    SharedPlayer *player;
    Shared_Placed *spawn;
    f32 angle;
    f32 best;
    f32 dist;

    if (Ppdecom_UnpackResource(handle, 1) != 0) {
        mode = Scene_GetModelSectionTwoRecord(world, 0);
        node = (*handle)->data;
        n = node->count;
        block = Cache_AllocResourceBlock(0, handle, n * (sizeof(LevelActor)) + 8);
        if (block != 0) {
            SetN64_TransposeRecords(node, block->data, 1);
            hdr = block->data;
            hdr->size = sizeof(LevelActor);
            hdr->count = n;
            records = node->records;
            objects = hdr->objects;
            if (world->unk1B41C == 0) {
                world->unk1B434 = Scene_FindNearestPlacedObject(world, node->records[0].vec4, world->unk1B40C, world->pad1B420);
                if (world->unk1B434 != 0) {
                    world->unk1B41C = 1;
                }
            }
            spawnIndex = 0;
            nspawns = 0;
            if (world->unk1B41C != 0) {
                nspawns = Scene_FindPlacedObjectsByKey(world, world->unk1B40C, world->unk1B434, spawns, 8);
            }
            world->unk138 = objects;
            world->unk140 = n;
            i = 0;
            if (i < n) {
                objWalk = objects;
                recWalk = records;
                while (i < n) {
                    rec = recWalk;
                    obj = objWalk;
                    i++;
                    obj->definition = Scene_GetActorDefinition(world, rec->resource22);
                    objWalk = obj + 1;
                    recWalk = rec + 1;
                }
            }
            world->unk13C = 0;
            for (i = 0; i < n; i++) {
                rec = &records[i];
                obj = &objects[i];
                specialSet = 0xC1D;
                Gobjinst_InitializePlacedActor(obj, rec, mode, i);
                definition = Scene_GetActorDefinition(world, rec->resource22);
                if (*definition != 0xB && i != 0) {
                    continue;
                }
                world->unk13C++;
                memcpy(&g_spawnReferencePosition, rec->vec4, sizeof(CVector3));
                g_spawnReferencePosition.y += 204.79998779296875f;
                g_spawnReferenceFloorPolygon = Scene_FindFloorPolygon(world, rec->vec4);
                playerIndex = 0;
                if (playerIndex < D_80145048) {
                    slot = g_playerSettings;
                    do {
                        player = &D_80140F84[playerIndex];
                        if (nspawns != 0) {
                            if (slot->kind == 0xC && player->views1450.view1450_1.computer != 0 && world->unk1B40C == 9) {
                                Scene_FindPlacedObjectsByKey(world, 9, specialSet, &extra, 1);
                                spawn = &extra;
                            } else {
                                spawn = &spawns[spawnIndex];
                            }
                            rec->resource20 = (u16)spawn->pad12;
                            Graphu64_WrapPeriodicValue(&spawn->unkC);
                            angle = spawn->unkC;
                            if (!(angle > 3.1415927f)) {
                                if (!(angle < -3.1415927f)) {
                                    if (!(angle > 3.1415927f)) {
                                        value = angle * 10430.06f;
                                    } else {
                                        value = 0x7FFF;
                                    }
                                } else {
                                    value = -0x7FFF;
                                }
                            } else {
                                value = 0x7FFF;
                            }
                            rec->amount24 = value;
                            memcpy(rec->vec4, &spawn->pos, sizeof(CVector3));
                            world->unk1B614 = 0;
                            world->unk1B618 = 0;
                            world->unk1B61C = 0;
                            spawnIndex++;
                            if (spawnIndex >= nspawns) {
                                spawnIndex = 0;
                            }
                        }
                        Player_InitActorParts(player, rec, mode, i);
                        slot++;
                        playerIndex++;
                    } while (playerIndex < D_80145048);
                }
            }
            for (i = world->unk13C; i < n; i++) {
                obj = &objects[i];
                best = 3.4028235e38f;
                obj->controller = 0;
                if (Insthdr_GetModelPropertyFlag2(obj) == 0) {
                    continue;
                }
                for (peerIndex = world->unk13C; peerIndex < n; peerIndex++) {
                    other = &objects[peerIndex];
                    if (obj->definition->kind == other->definition->kind && Insthdr_GetModelPropertyFlag1(other) != 0 && obj != other) {
                        if (obj->controller != 0) {
                            dist = Barrel_GetEyeDistanceSquared(obj, other->position0);
                            if (dist < best) {
                                obj->controller = other;
                                best = dist;
                            }
                        } else {
                            obj->controller = other;
                            best = Barrel_GetEyeDistanceSquared(obj, other->position0);
                        }
                    }
                }
            }
        }
        Cache_ReplaceResourceBlock(0, handle, block);
        world->unkF58 = 0;
    }
}

void Scene_LoadGridCells(Level_func_8044CD8C_de *level) {
    s32 size;
    s32 width;
    s32 row;
    s32 lastCol;
    s32 lastRow;
    s32 rows;
    DraftStreamCell *cells;
    DraftStreamCell *cell;
    s32 col;
    s32 firstCol;
    s32 key;
    void **block;
    void *node;
    ResourceManagerState *list;
    s32 i;
    s32 n;
    s32 m;
    ObjA *a;
    ObjA *objsA;
    ObjB *objsB;
    ObjB *b;
    void *handle;

    width = ((ResourceManagerState *) SetN64_GetPackSection(level->grid, 0))->count;
    row = 0;
    rows = ((ResourceManagerState *) SetN64_GetPackSection(level->grid, 2))->count;
    cells = (DraftStreamCell *) ((ResourceManagerState *) SetN64_GetPackSection(level->grid, 4) + 1);
    lastRow = rows - 1;
    lastCol = width - 1;
    /* scan every cell: columns firstCol..lastCol of each row */
    firstCol = 0;
    for (; row <= lastRow; row++) {
        for (col = firstCol; col <= lastCol; col++) {
            cell = &cells[col + row * width];
            if (cell->occupied != 0) {
                continue;
            }
            key = SetN64_LocatePackSection(level->file, level->key, col + row * width, &size);
            block = Cache_RequestResource(0, key, key, size, 4, level, D_0028798C, D_800C5210_de, 1);
            if (block == 0) {
                continue;
            }
            node = *block;
            if (*(s32 *) node != 0) {
                list = SetN64_GetPackSection(node, 0);
                n = list->count;
                objsA = (ObjA *) (list + 1);
                for (i = 0; i < n; i++) {
                    a = &objsA[i];
                    a->block = block;
                    Statinst_RegisterGeometryResources(a, 0);
                    handle = Statinst_AcquireGeometry(a, a->type);
                    if (handle != 0) {
                        Geometry_UnlockMaterialResources(handle);
                        Cache_UnlockResource(0, handle);
                    }
                }
                list = SetN64_GetPackSection(node, 1);
                m = list->count;
                objsB = (ObjB *) (list + 1);
                for (i = 0; i < m; i++) {
                    b = &objsB[i];
                    b->block = block;
                    Simpinst_RegisterModelVariantResources(b, 0);
                    handle = func_8024F6EC_de(b, b->type);
                    if (handle != 0) {
                        Geometry_UnlockMaterialResources(handle);
                        Cache_UnlockResource(0, handle);
                    }
                }
            }
            Cache_UnlockResource(0, block);
        }
    }
}

void Scene_InitPreview(Shared_World *world, s32 level) {
    Scene_LoadPreviewBufferA((ItemsPreviewStateA *)world);
    Scene_LoadPreviewBufferB((char *)world);
    world->previewState = 0;
    world->previewTimer = 0x15;
    world->previewStart = D_801462CC.field_0;
}

extern void Cache_ReleaseResource(void *, void *); /* extern */

/* Loads a selected resource into the shared buffer and releases the temporary allocation. */

struct ItemsPreviewStateA;

/* extern */
extern s32 Control_IsSnapshotActive(void); /* extern */
extern void *func_802BD3A0_de(void *, const void *, int); /* extern */
extern char D_00285160;
extern char g_loadSavePersistentData;

void Scene_LoadPreviewBufferA(ItemsPreviewStateA *previewToLoad) {
    s32 *persistentDataResource;
    s32 temp_a1;

    if (Control_IsSnapshotActive() == 0) {
        persistentDataResource = Cache_RequestResource(0, previewToLoad->unk38, previewToLoad->unk38, previewToLoad->unk44, 0, 0, &D_00285160, &g_loadSavePersistentData, 1);
        func_802BD3A0_de(&D_800F91F0, (const void *)*persistentDataResource, 0x5800);
        Cache_ReleaseResource(0, persistentDataResource);
        previewToLoad->unk4 = 1;
    }
}
