#include "sdk/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern void *g_nextVideoInterfaceContext;
void osViSetYScale(f32 yScale) {
    void *savedInterruptMask;
    savedInterruptMask = __osDisableInt();
    (((struct ViVerticalScaleView *) ((s8 *) g_nextVideoInterfaceContext))->yScaleFactor) = yScale;
    (((struct ViVerticalScaleView *) ((s8 *) g_nextVideoInterfaceContext))->state) = (u16) ((((struct ViVerticalScaleView *) ((s8 *) g_nextVideoInterfaceContext))->state) | 4);
    __osRestoreInt(savedInterruptMask);
}
