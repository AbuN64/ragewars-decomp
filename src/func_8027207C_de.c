#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80271B18.h"
#include "types.h"

extern f32 func_802B72B0_de(f32);
extern char D_800C48A8_de;
extern f32 D_800C48AC_de;




void func_8027207C_de(f32 *arg0) {
    f32 mag;
    f32 scale;

    mag = func_802B72B0_de((arg0[0] * arg0[0]) + (arg0[1] * arg0[1]) + (arg0[2] * arg0[2]));
    if (mag != 0.0f) {
        scale = D_800C48AC_de / mag;
        arg0[0] = arg0[0] * scale;
        arg0[1] = arg0[1] * scale;
        arg0[2] = arg0[2] * scale;
    }
}

/** Intersect a line segment with a horizontal plane and write the point. */
void func_80272104_de(Vec3 *out, Vec3 *a, Vec3 *b, f32 y) {
    f32 dy = b->y - a->y;

    if (dy == 0.0f) {
        *out = *a;
        return;
    }

    {
        f32 t = (y - a->y) / dy;
        out->x = a->x + (t * (b->x - a->x));
        out->y = y;
        out->z = a->z + (t * (b->z - a->z));
    }
}

void *func_80272180_de(void *arg0, void *arg1, void *arg2, f32 arg3) {
    Vec3 tmp;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = ((Vec3 *)arg1)->x;
    temp_f4 = ((Vec3 *)arg2)->x;
    temp_f3 = (temp_f5 * temp_f4) + (((Vec3 *)arg1)->y * ((Vec3 *)arg2)->y) + (((Vec3 *)arg1)->z * ((Vec3 *)arg2)->z);
    temp_f2 = (arg3 * temp_f3) + temp_f3;
    tmp.x = temp_f5 - (temp_f2 * temp_f4);
    tmp.y = ((Vec3 *)arg1)->y - (temp_f2 * ((Vec3 *)arg2)->y);
    tmp.z = ((Vec3 *)arg1)->z - (temp_f2 * ((Vec3 *)arg2)->z);
    *(Vec3 *)arg0 = tmp;
    return arg0;
}

void *func_80272214_de(void *arg0, void *arg1, void *arg2) {
    Vec3 tmp;
    f32 temp_f2;
    f32 temp_f4;
    f32 temp_f5;

    temp_f5 = ((Vec3 *)arg1)->x;
    temp_f4 = ((Vec3 *)arg2)->x;
    temp_f2 = (temp_f5 * temp_f4) + (((Vec3 *)arg1)->y * ((Vec3 *)arg2)->y) + (((Vec3 *)arg1)->z * ((Vec3 *)arg2)->z);
    tmp.x = temp_f5 - (temp_f2 * temp_f4);
    tmp.y = ((Vec3 *)arg1)->y - (temp_f2 * ((Vec3 *)arg2)->y);
    tmp.z = ((Vec3 *)arg1)->z - (temp_f2 * ((Vec3 *)arg2)->z);
    *(Vec3 *)arg0 = tmp;
    return arg0;
}
