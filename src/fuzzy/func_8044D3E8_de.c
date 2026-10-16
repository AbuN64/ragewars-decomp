#include "TYPES.H"

typedef struct SearchPoint {
    f32 position[3];
    u32 fieldC;
    s16 type;
    s16 field12;
} SearchPoint;

typedef struct SearchValues {
    s32 field0;
    s32 count;
    s32 values[0];
} SearchValues;

typedef struct SearchPoints {
    s32 field0;
    s32 field4;
    SearchPoint points[0];
} SearchPoints;

typedef struct SearchOwner {
    u8 pad[0x90];
    void *resource;
} SearchOwner;

extern f32 D_800C52FC_de;
extern void *func_8028FDB4_de(void *resource, s32 index);
extern f32 func_802726F8_de(void *a, void *b);

s32 func_8044D3E8_de(SearchOwner *owner, void *position, s32 type, SearchPoint *out) {
    s32 i = 0;
    s32 best = 0;
    SearchValues *values;
    SearchPoints *points;
    SearchPoint *point;
    s32 count;
    f32 distance;
    f32 minimum;

    values = func_8028FDB4_de(owner->resource, 0);
    count = values->count;
    points = func_8028FDB4_de(owner->resource, 1);
    minimum = D_800C52FC_de;
    point = points->points;
    for (; i < count; i++, point++) {
        if (point->type == type) {
            distance = func_802726F8_de(point, position);
            if (distance < minimum) {
                minimum = distance;
                best = i;
            }
        }
    }
    if (best == 0) {
        return 0;
    }
    *out = points->points[best];
    return values->values[best];
}
