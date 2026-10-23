#include "include_asm.h"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/REC.H"
#include "TYPES.H"

extern int func_80285F58_de(char *a, int b);

extern void func_80267198_de(void *, void *, s32, CVector3, ResourceManagerState);


int func_80204E78_de(int arg0) {
    return func_80285F58_de(&D_8011FE88, arg0) == 1;
}

/** Submit an object's three-word record, then attach it in mode one. */
void func_80204EA8_de(LevelActor *actor) {
    ResourceManagerState pair;

    pair.active = 0;
    func_80267198_de(actor, actor, 6, actor->position0, pair);
    func_80285DB0_de(&D_8011FE88, actor, 1);
}

/** Submit an object's three-word record, then attach it to the global owner. */
void func_80204F10_de(LevelActor *actor) {
    ResourceManagerState pair;

    pair.active = 0;
    func_80267198_de(actor, actor, 7, actor->position0, pair);
    func_80285DB0_de(&D_8011FE88, actor, 0);
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

#if defined(VERSION_EU_X)
unsigned int func_802050B4_eu_x_padding_5CB4[3] = {
    0xC44C000C, 0xC44E0010, 0x0C09D2BC,
};
#endif

#if defined(VERSION_DE)
unsigned int func_80205094_de_padding_5C94[3] = {
    0x39000000, 0x04000000, 0x10000000,
};
#endif
