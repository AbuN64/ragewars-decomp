#include "include_asm.h"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PROPGEOMETRY.H"
#include "TYPES.H"

extern int Scene_GetModelIdAtIndex(void *arg0, int arg1);




int InstHdr_GetActorType(void *prop) {
    if (((LevelActor *)prop)->kind == 1) {
        return ((LevelActor *)prop)->type;
    }
    return Scene_GetModelIdAtIndex(&g_world, (u16)((LevelActor *)prop)->modelIndex);
}

/** Return the selected record field, or negative one for another type. */
int InstHdr_GetActorMotionIndex(void *record) {
    int result = -1;
    if (((LevelActor *)record)->kind == 1) {
        result = ((LevelActor *)record)->motionIndex;
    }
    return result;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8024E964[3] = {
    0x46540200, 0x00009410, 0x000B0000,
};
#endif
