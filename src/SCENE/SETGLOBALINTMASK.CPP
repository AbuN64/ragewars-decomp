#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "SCENE/SETGLOBALINTMASK.H"
#include "../../sdk/include/os.h"



void Scene_SetGlobalInterruptMask(s32 interruptMask) {
    u32 mask;
    s32 *p;

    mask = __osDisableInt();
    p = &g_globalInterruptMask;
    *p |= interruptMask;
    __osRestoreInt(mask);
}
