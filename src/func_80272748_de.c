#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"
#include "types.h"



extern f32 func_802B72B0_de(f32);

void func_80272748_de(Vec3 *arg0, f32 arg1) {
    f32 magSq;
    f32 mag;
    f32 scale;

    magSq = (arg0->x * arg0->x) + (arg0->y * arg0->y) + (arg0->z * arg0->z);
    if ((arg1 * arg1) < magSq) {
        mag = func_802B72B0_de(magSq);
        scale = arg1 / mag;
        arg0->x = arg0->x * scale;
        arg0->y = arg0->y * scale;
        arg0->z = arg0->z * scale;
    }
}
