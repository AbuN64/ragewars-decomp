#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "TYPES.H"
#include "../../include/libultra/os/setglobalintmask.h"
#include "../../include/os.h"



void __osSetGlobalIntMask(s32 interruptMask) {
    u32 mask;
    s32 *p;

    mask = __osDisableInt();
    p = &__OSGlobalIntMask;
    *p |= interruptMask;
    __osRestoreInt(mask);
}
