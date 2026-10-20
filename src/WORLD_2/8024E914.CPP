#include "include_asm.h"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PROPGEOMETRY.H"
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

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_8024E964);
#endif
