#include "span_1000/code_8024E130.h"
#include "shared/legacy_collision_actor.h"



/** Select one of two float fields according to the leading byte. */
float func_8024E678_de(Shared_Func80243A80Actor *object) {
    if (object->type != 1) {
        return object->y;
    }
    return object->groundY;
}
