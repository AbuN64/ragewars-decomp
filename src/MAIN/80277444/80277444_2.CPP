#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "span_C76B0/data.h"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_80214624_de_closed.h"
#include "span_1000/code_80277444.h"
extern void func_80270910_de(f32 *, PackedMatrixWords *);
extern void func_80272B38_de(void *, void *, void *);
void func_80277A98_de(Vertices38 *data, PackedMatrixWords *matrices, Vec3 *output, s32 skin) {
    Vec3 light;
    f32 matrix[16];
    Vec3 normal, transformed;
    Light38 *source;
    Vertex38 *vertex, *base;
    Vec3 *dest;
    s32 drawn;
    s32 count, i;
    f32 dot, intensity;
    count = data->count;
    base = data->vertices;
    func_80270910_de(matrix, matrices);
    source = D_80137078;
    light.x = source->x;
    light.y = source->y;
    light.z = source->z;
    func_8027207C_de(&light);
    drawn = 0;
    for (i = 0; i < count; i++) {
        vertex = &base[i];
        dest = &output[drawn];
        if (!(vertex->flags & 0x80)) {
            f32 red, green, blue;
            if (skin) func_80270910_de(matrix, &matrices[vertex->flags >> 8]);
            normal.x = vertex->x;
            normal.y = vertex->y;
            normal.z = vertex->z;
            func_80272B38_de(matrix, &normal, &transformed);
            dot = transformed.x * light.x + transformed.y * light.y + transformed.z * light.z;
            intensity = ((dot < 0.0f) ? 0.2196078598f : (dot + 0.2196078598f)) * 255.0f;
            dot = intensity;
            red = dest->x + dot;
            green = dest->y + dot;
            blue = dest->z + dot;
            dest->x = red;
            dest->y = green;
            dest->z = blue;
            drawn++;
        }
    }
}
