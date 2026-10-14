#include "shared/gameplay_transition.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"

extern s32 func_8024E7DC_de(void *);







void func_8022C080_de(void *arg0, void *arg1) {
    void *result;
    f32 t0;
    f32 t1;

    result = (void *)func_8024E7DC_de(arg1);
    if (result != 0) {
        t0 = ((ModelBlend *)result)->blend;
        t1 = ((Shared_ActorView *)arg0)->modelBlend;
        t0 = t0 - t1;
        t0 = t0 * D_800C2D28_de;
        t1 = t1 + t0;
        ((Shared_ActorView *)arg0)->modelBlend = t1;
    }
}
