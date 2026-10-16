#include "TYPES.H"

typedef struct ClampVertex {
    char pad0[0xC];
    u8 r, g, b, a;
} ClampVertex;
typedef struct ClampModel {
    s32 unused;
    s32 count;
    ClampVertex vertices[0];
} ClampModel;
typedef struct ClampColor {
    u8 r, g, b, a;
} ClampColor;

void func_80278A08_de(ClampModel *model, ClampColor *out) {
    s32 i, count;
    ClampVertex *vertex;
    ClampColor *color;
    u8 r, g, b;
    i = 0;
    count = model->count;
    vertex = model->vertices;
    if (count > 0) {
        do {
            color = out++;
            r = vertex->r;
            color->r = (r < 225 ? r : 225) > 30 ? (r < 225 ? r : 225) : 30;
            g = vertex->g;
            color->g = (g < 225 ? g : 225) > 30 ? (g < 225 ? g : 225) : 30;
            b = vertex->b;
            color->b = (b < 225 ? b : 225) > 30 ? (b < 225 ? b : 225) : 30;
            i++;
            vertex++;
        } while (i < count);
    }
}
