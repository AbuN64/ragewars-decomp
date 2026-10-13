#include "span_1000/code_8020AF9C.h"
#include "shared/world.h"
extern NavigationPlatform *D_8011BF00;
extern s32 D_8011BF08;
extern f32 D_800C1D4C_de, D_800C1D50_de;
extern PlatformRoute *func_8028D218_de(void *, s32);
extern Vec3 *func_8028D244_de(void *, s32, s32);
extern f32 func_802726F8_de(void *, void *);

void func_8020ABF0_de(NavigationGraph *graph) {
    NavigationPlatform *platforms[30];
    Vec3 chosenPosition, start, end;
    NavigationSearchNode *node;
    NavigationPoint *point;
    NavigationPlatform *actor, *chosen;
    ActorMotionState *motion;
    ActorMotionDefinition *definition;
    PlatformRoute *route;
    Vec3 *position;
    f32 distance, best, sentinel;
    s32 i, count, j;

    for (i = 29; i >= 0; i--) platforms[i] = 0;
    count = 0;
    for (i = 0; i < D_8011BF08; i++) {
        actor = &D_8011BF00[i];
        if (actor->objectId == 0x642) platforms[count++] = actor;
    }
    node = graph->nodes;
    if (node != 0) {
        sentinel = D_800C1D4C_de;
        do {
            point = navigationRecord(graph->points, node->key);
            chosen = 0;
            if (point->attributes.halves.flags & 0x200) {
                best = D_800C1D50_de;
                for (i = 0; i < count; i++) {
                    actor = platforms[i];
                    motion = &actor->motion;
                    definition = &actor->resource->motion;
                    if (motion->mode == 4) {
                        route = func_8028D218_de(&D_8011FE88, motion->route);
                        if (route != 0) {
                            for (j = 0; j < route->count; j++) {
                                position = func_8028D244_de(&D_8011FE88, motion->route, j);
                                distance = func_802726F8_de(point, position);
                                if (distance < best || best == sentinel) {
                                    chosen = platforms[i];
                                    best = distance;
                                    chosenPosition = *position;
                                }
                            }
                        }
                    } else {
                        start = motion->base;
                        end = motion->base;
                        end.y += definition->height;
                        if (definition->radial != 0) {
                            end.x += definition->radius * func_802B7130_de(definition->heading);
                            end.z += definition->radius * func_802B6560_de(definition->heading);
                        }
                        distance = func_802726F8_de(point, &start);
                        if (distance < best || best == sentinel) {
                            chosen = platforms[i];
                            best = distance;
                            chosenPosition = start;
                        }
                        distance = func_802726F8_de(point, &end);
                        if (distance < best || best == sentinel) {
                            chosen = platforms[i];
                            best = distance;
                            chosenPosition = end;
                        }
                    }
                }
                if (chosen == 0) {
                    node->platform = 0;
                    point->attributes.halves.flags &= 0xFDFF;
                } else {
                    node->platform = chosen;
                    node->endpoint = chosenPosition;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
