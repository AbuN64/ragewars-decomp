#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024D018.h"
#include "types.h"






s32 func_8024DF5C_de(void *arg0) {
    ModelBlend *temp_a1;
    s32 var_v1;

    temp_a1 = ((LevelActor *)arg0)->definition;
    if (temp_a1->kind == 1) {
        var_v1 = 0;
        if (((LevelActor *)arg0)->active <= 0 || (temp_a1->collisionOptions & 4)) {
            var_v1 = 1;
        }
        return var_v1;
    }
    return 0;
}
