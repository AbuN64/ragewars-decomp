#include "shared/world.h"

extern s32 func_8028FE28_de(s32 *arg0, s32 arg1, s32 arg2);

s32 func_8028C198_de(Shared_World *world, s32 arg1) {
    s32 *directory = world->indexedDirectory;

    if (arg1 < *directory) {
        return func_8028FE28_de(directory, world->indexedBank, arg1);
    }
    return 0;
}
