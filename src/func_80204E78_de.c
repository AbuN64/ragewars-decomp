#include "span_1000/code_80204E78.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern int func_80285F58_de(char *a, int b);

extern void func_80267198_de(void *, void *, s32, Vec3, ResourceManagerState);


int func_80204E78_de(int arg0) {
    return func_80285F58_de(&D_8011FE88, arg0) == 1;
}

/** Submit an object's three-word record, then attach it in mode one. */
void func_80204EA8_de(void *arg0) {
    ResourceManagerState pair;

    pair.active = 0;
    func_80267198_de(arg0, arg0, 6, ((LevelActor *)arg0)->position0, pair);
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}

/** Submit an object's three-word record, then attach it to the global owner. */
void func_80204F10_de(void *arg0) {
    ResourceManagerState pair;

    pair.active = 0;
    func_80267198_de(arg0, arg0, 7, ((LevelActor *)arg0)->position0, pair);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}

/** Update the floating state at offsets 0x40 and 0x64 under its range rules. */
void func_80204F78_de(void *unused, char *object, float value) {
    ActorMotionState *state = (void *)object;
    if (value == 0.0f || state->speed < value) {
        if (state->speed == 0.0f) {
            state->timer = 0.0f;
        }
        state->speed = value;
    }
}

/** Report whether the actor on the given cell is within the scaled trigger distance. */




int func_80204FC4_de(ActorRecAt134 *actor, Cell *cell, float scale) {
    if (actor->always == 1) {
        return 1;
    }
    if (actor->x == (signed char)cell->pos && actor->y == (signed char)cell->pos) {
        if (cell->open != 0 && !(actor->flags & 0x400)) {
            return 1;
        }
        if (actor->level < 3 && (actor->flags & 0x400)) {
            if (actor->altLevel * scale <= actor->altRange) {
                return 1;
            }
            return 0;
        }
        if (actor->level * scale <= actor->range) {
            return 1;
        }
    }
    return 0;
}
