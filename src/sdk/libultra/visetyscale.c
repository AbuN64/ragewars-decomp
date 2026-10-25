#include "sdk/libgultra.h"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/os.h"

extern void *D_800D4414;
void osViSetYScale(f32 arg0) {
    void *temp_v0;
    temp_v0 = __osDisableInt();
    (((struct ObjectState28 *) ((s8 *) D_800D4414))->unk_24) = arg0;
    (((struct ObjectState28 *) ((s8 *) D_800D4414))->unk_0) = (u16) ((((struct ObjectState28 *) ((s8 *) D_800D4414))->unk_0) | 4);
    __osRestoreInt(temp_v0);
}
