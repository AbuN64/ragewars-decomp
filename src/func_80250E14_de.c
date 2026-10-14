#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"
#include "shared/level_actor.h"

extern u8 D_801462E5;








s8 func_80250E14_de(void *arg0) {
    void *temp_a1;

    if (D_801462E5 != 0) {
        return ((struct ResourceFadeDefinition *)((LevelActor *)arg0)->definition)->nearValue;
    }
    temp_a1 = ((LevelActor *)arg0)->definition;
    if ((u32)((LevelActor *)arg0)->resourceState < ((struct ResourceFadeDefinition *)temp_a1)->threshold * 2) {
        return ((struct ResourceFadeDefinition *)temp_a1)->nearValue;
    }
    return ((struct ResourceFadeDefinition *)temp_a1)->farValue;
}
