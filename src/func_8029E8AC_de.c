#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029EB74.h"
#include "types.h"
/* Projects n vectors onto the screen plane: each one with depth above 0.01 becomes (ox + sx * x / z, oy + sy * y / z, z), and any other becomes zero. */



void func_8029E8AC_de(Vec3 *out, Vec3 *in, s32 n, f32 ox, f32 sx, f32 oy, f32 sy) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (in[i].z > 0.01f) {
            out[i].x = ox + sx * (in[i].x / in[i].z);
            out[i].y = oy + sy * (in[i].y / in[i].z);
            out[i].z = in[i].z;
        } else {
            out[i].x = 0.0f;
            out[i].y = 0.0f;
            out[i].z = 0.0f;
        }
    }
}
