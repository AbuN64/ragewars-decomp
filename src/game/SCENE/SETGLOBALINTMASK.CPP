#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SCENE/SETGLOBALINTMASK.H"
#include "sdk/os.h"



void Scene_SetGlobalInterruptMask(s32 interruptMask) {
    u32 mask;
    s32 *p;

    mask = __osDisableInt();
    p = &D_800D5258;
    *p |= interruptMask;
    __osRestoreInt(mask);
}
