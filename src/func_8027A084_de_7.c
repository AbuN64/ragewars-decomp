#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027A0F4.h"
#include "types.h"






























/* Sets an actor's field 0x14C to 1 when something is near it: a world object from D_8011FE88 whose field 0x174 is positive within 256 units, a player from the D_80145060 list other than the actor's owner whose field 0x5E4 is positive within 256 units, or another actor of type 0xC or 0x22 from the given list within 512 units (all compared as squared distances). */








extern World_func_80281A9C_de D_8011FE88;
extern SharedPlayer_func_8022A398_de *D_80145060;
extern void func_80271F68_de(Vec3 *out, Vec3 *a, Vec3 *b);

void func_80281A9C_de(s32 unused, Actor_func_80281A9C_de *actor, Actor_func_80281A9C_de **others, s32 count) {
    Vec3 delta;
    World_func_80281A9C_de *world;
    SharedPlayer_func_8022A398_de *player;
    s32 i;
    s32 objectCount;

    world = &D_8011FE88;
    objectCount = world->objectCount;
    for (i = 0; i < objectCount; i++) {
        if (world->objects[i]->count > 0) {
            func_80271F68_de(&delta, &world->objects[i]->position, &actor->position);
            if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z <= 65536.0f) {
                actor->crowded = 1;
                return;
            }
        }
    }
    for (player = D_80145060; player != 0; player = player->views16E0.view16E0_1.next) {
        if (actor->owner != player && player->views5E4.view5E4_2.health > 0) {
            func_80271F68_de(&delta, &player->views0.view8_4.position, &actor->position);
            if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z <= 65536.0f) {
                actor->crowded = 1;
                return;
            }
        }
    }
    for (i = 0; i < count; i++) {
        if (others[i] != actor && (others[i]->type == 0xC || others[i]->type == 0x22)) {
            func_80271F68_de(&delta, &others[i]->position, &actor->position);
            if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z <= 262144.0f) {
                actor->crowded = 1;
                return;
            }
        }
    }
}
