#include "COMMON/OBJB.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/LEVEL_SPAWN.H"
#include "COMMON/LEVEL_TRACK.H"
#include "COMMON/WORLD.H"
#include "COMMON/PROPGEOMETRY.H"
#include "TYPES.H"
#include "particle/80246E34_8.H"
#include "particle/8024D018_4.H"
#include "WEAPONS/80213ED4_22.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"

extern void func_80253D10_de(s32 arg0, struct Shape_typemap_165 **handle, struct Shape_typemap_165 *block);

extern struct Shape_typemap_165 *func_80254480_de(s32 arg0, void *handle, s32 size);

extern void *func_8028CF6C_de(void *world, s32 id);


extern s32 func_8044D3E8_de(World *world, void *data, s32 group, void *buf);

/* Loads every still-empty cell of the level's tile grid: for each row and column whose cell
   record has no resource, fetches the cell's block through func_8028FE3C_de and func_8025193C_de,
   binds and spawns each object of its two object lists (0xE8- and 0x1C8-byte records) and
   releases the spawned handles and the block. */











extern char D_0028798C[];

extern char D_800C5210_de[];

extern void func_8024F294_de(ObjB *obj, s32 arg1);

extern void *func_8024F6EC_de(ObjB *obj, s32 type);

extern void func_802509A8_de(ObjA *obj, s32 arg1);

extern void *func_802507AC_de(ResourceOwner *owner,s32 index);


extern void func_80253754_de(s32, void *);

extern void func_8026E158_de(void *handle);


extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

/* Runs func_8044D054_de and func_8044D0F0_de on a large state block, then clears its word at offset
   0x1B444, sets the word at 0x1B448 to 0x15 and copies D_801462CC into the word at 0x1B44C. */

extern struct Shape_func_8021A2D4_de_2 D_801462CC;

extern void func_8044D054_de(char *);

extern void func_8044D0F0_de(char *);

void func_8044C7B8_de(World *world, struct Shape_typemap_165 **handle) {
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

    if (func_80285180_de(handle, 1) != 0) {
        mode = func_8028B394_de(world, 0);
        node = (*handle)->data;
        n = node->count;
        block = func_80254480_de(0, handle, n * (sizeof(LevelActor)) + 8);
        if (block != 0) {
            func_8028FF0C_de(node, block->data, 1);
            hdr = block->data;
            hdr->size = sizeof(LevelActor);
            hdr->count = n;
            records = node->records;
            objects = hdr->objects;
            if (world->unk1B41C == 0) {
                world->unk1B434 = func_8044D3E8_de(world, node->records[0].vec4, world->unk1B40C, world->pad1B420);
                if (world->unk1B434 != 0) {
                    world->unk1B41C = 1;
                }
            }
            spawnIndex = 0;
            nspawns = 0;
            if (world->unk1B41C != 0) {
                nspawns = func_8044D220_de(world, world->unk1B40C, world->unk1B434, spawns, 8);
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
                    obj->definition = func_8028CF6C_de(world, rec->resource22);
                    objWalk = obj + 1;
                    recWalk = rec + 1;
                }
            }
            world->unk13C = 0;
            for (i = 0; i < n; i++) {
                rec = &records[i];
                obj = &objects[i];
                specialSet = 0xC1D;
                func_8024B3A8_de(obj, rec, mode, i);
                definition = func_8028CF6C_de(world, rec->resource22);
                if (*definition != 0xB && i != 0) {
                    continue;
                }
                world->unk13C++;
                memcpy(&D_80141040, rec->vec4, sizeof(CVector3));
                D_80141040.y += 204.79998779296875f;
                D_80141060 = Scene_FindFloorPolygon(world, rec->vec4);
                playerIndex = 0;
                if (playerIndex < D_80145048) {
                    slot = D_80146398;
                    do {
                        player = &D_80140F84[playerIndex];
                        if (nspawns != 0) {
                            if (slot->kind == 0xC && player->views1450.view1450_1.computer != 0 && world->unk1B40C == 9) {
                                func_8044D220_de(world, 9, specialSet, &extra, 1);
                                spawn = &extra;
                            } else {
                                spawn = &spawns[spawnIndex];
                            }
                            rec->resource20 = (u16)spawn->pad12;
                            func_80274020_de(&spawn->unkC);
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
                        func_80449970_us_rev1(player, rec, mode, i);
                        slot++;
                        playerIndex++;
                    } while (playerIndex < D_80145048);
                }
            }
            for (i = world->unk13C; i < n; i++) {
                obj = &objects[i];
                best = 3.4028235e38f;
                obj->controller = 0;
                if (func_8024DDB4_de(obj) == 0) {
                    continue;
                }
                for (peerIndex = world->unk13C; peerIndex < n; peerIndex++) {
                    other = &objects[peerIndex];
                    if (obj->definition->kind == other->definition->kind && func_8024DD8C_de(other) != 0 && obj != other) {
                        if (obj->controller != 0) {
                            dist = func_80217224_de(obj, other->position0);
                            if (dist < best) {
                                obj->controller = other;
                                best = dist;
                            }
                        } else {
                            obj->controller = other;
                            best = func_80217224_de(obj, other->position0);
                        }
                    }
                }
            }
        }
        func_80253D10_de(0, handle, block);
        world->unkF58 = 0;
    }
}

void func_8044CD8C_de(Level_func_8044CD8C_de *level) {
    s32 size;
    s32 width;
    s32 row;
    s32 lastCol;
    s32 lastRow;
    s32 rows;
    DraftStreamCell *cells;
    DraftStreamCell *cell;
    s32 col;
    s32 first;
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

    width = ((ResourceManagerState *) func_8028FDB4_de(level->grid, 0))->count;
    row = 0;
    rows = ((ResourceManagerState *) func_8028FDB4_de(level->grid, 2))->count;
    cells = (DraftStreamCell *) ((ResourceManagerState *) func_8028FDB4_de(level->grid, 4) + 1);
    lastRow = rows - 1;
    lastCol = width - 1;
    /* FAKEMATCH: constant-holding local first keeps the column loop's entry test as slt */
    first = 0;
    for (; row <= lastRow; row++) {
        for (col = first; col <= lastCol; col++) {
            cell = &cells[col + row * width];
            if (cell->occupied != 0) {
                continue;
            }
            key = func_8028FE3C_de(level->file, level->key, col + row * width, &size);
            block = func_8025193C_de(0, key, key, size, 4, level, D_0028798C, D_800C5210_de, 1);
            if (block == 0) {
                continue;
            }
            node = *block;
            if (*(s32 *) node != 0) {
                list = func_8028FDB4_de(node, 0);
                n = list->count;
                objsA = (ObjA *) (list + 1);
                for (i = 0; i < n; i++) {
                    a = &objsA[i];
                    a->block = block;
                    func_802509A8_de(a, 0);
                    handle = func_802507AC_de(a, a->type);
                    if (handle != 0) {
                        func_8026E158_de(handle);
                        func_80253754_de(0, handle);
                    }
                }
                list = func_8028FDB4_de(node, 1);
                m = list->count;
                objsB = (ObjB *) (list + 1);
                for (i = 0; i < m; i++) {
                    b = &objsB[i];
                    b->block = block;
                    func_8024F294_de(b, 0);
                    handle = func_8024F6EC_de(b, b->type);
                    if (handle != 0) {
                        func_8026E158_de(handle);
                        func_80253754_de(0, handle);
                    }
                }
            }
            func_80253754_de(0, block);
        }
    }
}

void func_8044CFF8_de(Shared_World *world, s32 level) {
    func_8044D054_de((char *)world);
    func_8044D0F0_de((char *)world);
    world->previewState = 0;
    world->previewTimer = 0x15;
    world->previewStart = D_801462CC.field_0;
}
