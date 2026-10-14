#include "shared/level_actor.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80204E78.h"
#include "types.h"






extern void func_80267198_de(void *, void *, s32, Vec3, ResourceManagerState);
extern void func_80285DB0_de(void *, void *, s32);




/** Submit an object's three-word record, then attach it to the global owner. */
void func_80204F10_de(void *arg0) {
    ResourceManagerState pair;

    pair.active = 0;
    func_80267198_de(arg0, arg0, 7, ((LevelActor *)arg0)->position0, pair);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}
