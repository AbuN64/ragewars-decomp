#include "sdk/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern void *g_nextVideoInterfaceContext;
void osViSetYScale(f32 yScale) {
    void *savedInterruptMask;
    savedInterruptMask = __osDisableInt();
    (((struct ViVerticalScaleView *) ((s8 *) g_nextVideoInterfaceContext))->unk_24) = yScale;
    (((struct ViVerticalScaleView *) ((s8 *) g_nextVideoInterfaceContext))->unk_0) = (u16) ((((struct ViVerticalScaleView *) ((s8 *) g_nextVideoInterfaceContext))->unk_0) | 4);
    __osRestoreInt(savedInterruptMask);
}
