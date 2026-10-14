#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E130.h"
#include "shared/level_actor.h"



/** Return the low three mode bits when the record type is one. */
int func_8024E62C_de(void *arg0) {
    LevelActor *actor = arg0;
    if (actor->kind == 1) {
        return actor->motionState & 7;
    }
    return 0;
}
