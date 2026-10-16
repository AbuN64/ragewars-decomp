#include "TYPES.H"

typedef struct { s16 x, y, z; u16 flags; s16 s, t; u8 r, g, b, a; } ColorVertex;
typedef struct { s32 tag, count; ColorVertex vertices[1]; } ColorMesh;
typedef struct { f32 x, y, z; } VertexColor;
extern u32 D_80142218;
extern u32 D_801462C8;
extern f32 D_800C4B00_de, D_800C4B04_de, D_800C4B10_de;
extern f32 D_800C4B14_de, D_800C4B18_de;

void func_80278274_de(ColorMesh *mesh, VertexColor *colors) {
    f32 blend;
    VertexColor color;
    ColorVertex *v;
    s32 count, i, n;
    blend = D_800C4B04_de;
    if (!(D_800C4B04_de < (f32)D_80142218 * D_800C4B00_de)) {
        blend = (f32)D_80142218 * D_800C4B00_de;
    }
    v = mesh->vertices;
    count = mesh->count;
    if (D_801462C8 & 0x4000) {
        for (i = 0; i < count; i++, v++) {
            v->r = 0; v->g = 0; v->b = 0;
        }
    } else {
        for (i = 0; i < count; i++, v++) {
            color = *colors++;
            if (!(color.x <= D_800C4B10_de)) color.x = D_800C4B10_de;
            if (!(D_800C4B14_de <= color.x)) color.x = D_800C4B14_de;
            color.x = color.x * (D_800C4B18_de - blend) + blend * D_800C4B10_de;
            if (!(color.y <= D_800C4B10_de)) color.y = D_800C4B10_de;
            if (!(D_800C4B14_de <= color.y)) color.y = D_800C4B14_de;
            color.y = color.y * (D_800C4B18_de - blend) + blend * D_800C4B10_de;
            if (!(color.z <= D_800C4B10_de)) color.z = D_800C4B10_de;
            if (!(D_800C4B14_de <= color.z)) color.z = D_800C4B14_de;
            color.z = color.z * (D_800C4B18_de - blend) + blend * D_800C4B10_de;
            if (!(v->flags & 0x80)) {
                n = (s32)color.x;
                if (n >= 256) n = 255; else if (n < 0) n = 0;
                v->r = n;
                n = (s32)color.y;
                if (n >= 256) n = 255; else if (n < 0) n = 0;
                v->g = n;
                n = (s32)color.z;
                if (n >= 256) n = 255; else if (n < 0) n = 0;
                v->b = n;
            }
        }
    }
}
