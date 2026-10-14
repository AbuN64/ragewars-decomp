#include "shared/level_actor.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022A274.h"
#include "types.h"

extern f32 func_8024D284_de(void);





f32 func_8022ADF0_de(void *arg0) {
    if (((LevelActor *)arg0)->definition != 0) {
        return func_8024D284_de();
    } else {
        return D_800C2D08_de;
    }
}
