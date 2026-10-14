/* Spawns level objects and players, then links each eligible object to its nearest active peer of the same kind. */
#include "types.h"

#include "shared/level_spawn.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_8044DA54_de_closed.h"
#include "shared/level_track.h"
#include "span_16E000/code_8044ACCC.h"


extern void func_80253D10_de(s32 arg0, struct Shape_typemap_165 **handle, struct Shape_typemap_165 *block);
extern struct Shape_typemap_165 *func_80254480_de(s32 arg0, void *handle, s32 size);
extern void *func_8028CF6C_de(void *world, s32 id);
extern s32 func_8044D220_de(Track_func_8044D220_de *world, s32 group, s32 set, Object_func_8044D220_de *out, s32 max);
extern s32 func_8044D3E8_de(Track_func_8044D220_de *world, void *data, s32 group, void *buf);

void func_8044C7B8_de(Track_func_8044D220_de *world, struct Shape_typemap_165 **handle) {
    Object_func_8044D220_de spawns[8];
    Object_func_8044D220_de extra;
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
    Object_func_8044D220_de *spawn;
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
                memcpy(&D_80141040, rec->vec4, sizeof(Vec3));
                D_80141040.y += 204.79998779296875f;
                D_80141060 = func_80286728_de(world, rec->vec4);
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
                            func_80274020_de(&spawn->angle);
                            angle = spawn->angle;
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
                            memcpy(rec->vec4, &spawn->pos, sizeof(Vec3));
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
                    if (*obj->definition == *other->definition && func_8024DD8C_de(other) != 0 && obj != other) {
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
