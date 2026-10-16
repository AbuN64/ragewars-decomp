#include "shared/level_actor.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024E914.h"
#include "TYPES.H"


extern int func_8028B25C_de(void *arg0, int arg1);




int func_8024E924_de(void *arg0) {
    if (((LevelActor *)arg0)->kind == 1) {
        return ((LevelActor *)arg0)->type;
    }
    return func_8028B25C_de(&D_8011FE88, (u16)((LevelActor *)arg0)->modelIndex);
}

/** Return the selected record field, or negative one for another type. */
int func_8024E968_de(void *record) {
    int result = -1;
    if (((LevelActor *)record)->kind == 1) {
        result = ((LevelActor *)record)->motionIndex;
    }
    return result;
}
