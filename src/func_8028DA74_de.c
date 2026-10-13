#include "shared/world.h"

extern void func_80253838_de(void *, void *);

void func_8028DA74_de(Shared_World *world) {
    void *handle;

    handle = world->resourceHandle;
    if (handle != 0) {
        func_80253838_de(0, handle);
        world->resourceHandle = 0;
        world->resourceKey = -1;
    }
}
