#include "sdk/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern void *D_800D4414;
void osViSetYScale(f32 yScale) {
    void *savedInterruptMask;
    savedInterruptMask = __osDisableInt();
    (((struct ObjectState28 *) ((s8 *) D_800D4414))->unk_24) = yScale;
    (((struct ObjectState28 *) ((s8 *) D_800D4414))->unk_0) = (u16) ((((struct ObjectState28 *) ((s8 *) D_800D4414))->unk_0) | 4);
    __osRestoreInt(savedInterruptMask);
}
