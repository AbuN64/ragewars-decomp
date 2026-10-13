/* Spawns level objects and players, then links each eligible object to its nearest active peer of the same kind. */
#include "types.h"

#include "shared/level_spawn.h"

extern void *memcpy(void *, const void *, unsigned int);
extern Vec3 D_80141040;
extern f32 D_80141044;
extern s32 D_80141060;
extern SharedPlayer *D_80140F84;
extern s32 D_80145048;
extern Shared_PlayerSettingsRecord D_80146398[];

extern f32 func_80217224_de(Actor_func_8024A7A0_de *obj, Vec3 pos);
extern void func_8024B3A8_de(Actor_func_8024A7A0_de *obj, Input_func_8024B3A8_de *rec, s32 mode, s32 index);
extern s32 func_8024DD8C_de(Actor_func_8024A7A0_de *obj);
extern s32 func_8024DDB4_de(Actor_func_8024A7A0_de *obj);
extern void func_80253D10_de(s32 arg0, void ***handle, LevelBlock **block);
extern LevelBlock **func_80254480_de(s32 arg0, void ***handle, s32 size);
extern s32 func_80285180_de(void ***handle, s32 arg1);
extern s32 *func_8028CF6C_de(Shared_func_80286A78_S1 *world, s32 id);
extern void func_8028FF0C_de(void *src, void *dst, s32 arg2);
extern void func_80449970_us_rev1(SharedPlayer *player, Input_func_8024B3A8_de *rec, s32 mode, s32 index);
extern s32 func_8044D220_de(Shared_func_80286A78_S1 *world, s32 group, s32 set, Shared_Placed *out, s32 max);
extern s32 func_8044D3E8_de(Shared_func_80286A78_S1 *world, void *data, s32 group, void *buf);

void func_8044C7B8_de(Shared_func_80286A78_S1 *world, void ***handle) {
    Shared_Placed spawns[8];
    Shared_Placed extra;
    s32 n;
    Actor_func_8024A7A0_de *objects;
    s32 mode;
    LevelBlock **block;
    s32 nspawns;
    LevelNode *node;
    Input_func_8024B3A8_de *records;
    LevelBlock *hdr;
    s32 i;
    s32 j;
    s32 playerIndex;
    s32 k;
    Input_func_8024B3A8_de *rec;
    Input_func_8024B3A8_de *recWalk;
    Actor_func_8024A7A0_de *objWalk;
    Shared_PlayerSettingsRecord *slot;
    s16 value;
    Actor_func_8024A7A0_de *obj;
    Actor_func_8024A7A0_de *other;
    SharedPlayer *player;
    Shared_Placed *spawn;
    f32 angle;
    f32 best;
    f32 dist;

    if (func_80285180_de(handle, 1) != 0) {
        mode = func_8028B394_de(world, 0);
        node = **handle;
        n = node->count;
        block = func_80254480_de(0, handle, n * sizeof(Actor_func_8024A7A0_de) + 8);
        if (block != 0) {
            func_8028FF0C_de(node, *block, 1);
            hdr = *block;
            hdr->size = sizeof(Actor_func_8024A7A0_de);
            hdr->count = n;
            records = node->records;
            objects = hdr->objects;
            if (world->unk1B41C == 0) {
                world->unk1B434 = func_8044D3E8_de(world, node->records[0].vec4, world->unk1B40C, world->pad1B420);
                if (world->unk1B434 != 0) {
                    world->unk1B41C = 1;
                }
            }
            k = 0;
            nspawns = 0;
            if (world->unk1B41C != 0) {
                nspawns = func_8044D220_de(world, world->unk1B40C, world->unk1B434, spawns, 8);
            }
            world->unk138 = objects;
            world->unk140 = n;
            i = 0;
            if (n > 0) {
                objWalk = objects;
                recWalk = records;
                do {
                    rec = recWalk;
                    obj = objWalk;
                    i++;
                    obj->definition = func_8028CF6C_de(world, rec->resource22);
                    objWalk = obj + 1;
                    recWalk = rec + 1;
                } while (i < n);
            }
            world->unk13C = 0;
            for (i = 0; i < n; i++) {
                rec = &records[i];
                obj = &objects[i];
                func_8024B3A8_de(obj, rec, mode, i);
                if (*func_8028CF6C_de(world, rec->resource22) != 0xB && i != 0) {
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
                        if (slot->character == 0xC && player->views1450.view1450_1.computer != 0 && world->unk1B40C == 9) {
                            func_8044D220_de(world, 9, 0xC1D, &extra, 1);
                            spawn = &extra;
                        } else {
                            spawn = &spawns[k];
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
                        memcpy(rec->vec4, &spawn->pos, sizeof(Vec3));
                        world->unk1B614 = 0;
                        world->unk1B618 = 0;
                        world->unk1B61C = 0;
                        k++;
                        if (k >= nspawns) {
                            k = 0;
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
                for (j = world->unk13C; j < n; j++) {
                    other = &objects[j];
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

