#include "span_1000/code_80233920.h"
#include "shared/gameplay_camera.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802393F4.h"
#include "types.h"



extern void func_80271F68_de(Vec3 *out, void *arg1, void *arg2);
extern f32 func_802B72B0_de(f32);







f32 func_80239678_de(void *arg0, void *arg1) {
    Vec3 position;
    f32 sum;
    Racer *node;
    f64 divisor;
    s32 count;

    if (((Race *)arg0)->header.views.count == 0) {
        return 0.0f;
    }
    node = ((Race *)arg0)->header.views.head;
    sum = 0.0f;
    if (node != 0) {
        do {
            func_80271F68_de(&position, &((Shared_func_80234FDC_S2 *)node)->position, arg1);
            sum += func_802B72B0_de(
                (position.x * position.x) +
                (position.y * position.y) +
                (position.z * position.z));
            node = node->next;
        } while (node != 0);
    }
    count = ((Race *)arg0)->header.views.count;
    divisor = (f64)count;
    if (count < 0) {
        divisor += D_800C3550_de;
    }
    return sum / (f32)divisor;
}
