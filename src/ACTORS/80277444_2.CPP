#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "FX_2/80271B18.H"
#include "RENDER_4/8028FD2C_6.H"

extern void func_80270910_de(f32 *, PackedMatrixWords *);
extern void func_80272B38_de(void *, void *, void *);
void func_80277A98_de(Vertices38 *data, PackedMatrixWords *matrices, CVector3 *output, s32 skin) {
    CVector3 light;
    f32 matrix[16];
    CVector3 normal, transformed;
    Light38 *source;
    Vertex38 *vertex, *base;
    CVector3 *dest;
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

INCLUDE_ASM("span_1000", func_80277C54_de);

#ifdef NON_MATCHING
#include "TYPES.H"
#include "stddef.h"

/* Filters the 0xC0-byte hit records held in table slot 2 of arg1: keeps those whose box
   (six floats at record offset 0xA0) intersects the given bounds, and which either have no
   byte set at record offset 0xBD, are paired with arg4, or list the key that
   func_80250938_de(arg4, arg1) finds inside the id list at slot arg1-table index of the list
   table in slot 3. Writes the accepted record pointers into arg2 (at most 0x40 of them),
   reports their number through arg3, and returns 1 when any accepted record has its byte at
   record offset 0xBA set. With no table (arg1 null) it defers to func_80277C54_de. */

extern s32 func_80277C54_de(void *bounds, void **out, s32 *countOut);
extern s32 func_80250938_de(void *wanted, void *table);

typedef struct Bounds {
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
} Bounds;

typedef struct HitBox {
    u8 pad0[0xA0];
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
    u8 padB8[2];
    u8 flagBA;
    u8 padBB[2];
    u8 flagBD;
    u8 padBE[2];
} HitBox;

typedef struct HitBoxTable {
    s32 unk0;
    s32 count;
    HitBox boxes[1];
} HitBoxTable;

typedef struct IdList {
    u16 count;
    s16 ids[1];
} IdList;

s32 func_80278020_de(Bounds *bounds, void *table, void **out, s32 *countOut, u8 *wanted) {
    s32 foundCount;
    s32 result;
    s32 idx;
    s32 found;
    s32 n;
    s32 *idTable;
    s32 key;
    s32 id;
    s16 *ids;
    s16 len;
    IdList *list;
    HitBoxTable *boxTable;
    HitBox *box;
    void **outAt;

    foundCount = 0;
    result = 0;
    if (table == NULL) {
        return func_80277C54_de(bounds, out, countOut);
    }
    boxTable = func_8028FDB4_de(table, 2);
    idx = boxTable->count - 1;
    box = boxTable->boxes;
    outAt = out;
    for (; idx != -1; idx--) {
        if (bounds->maxX > box->minX && bounds->minX < box->maxX
            && bounds->maxZ > box->minZ && bounds->minZ < box->maxZ
            && bounds->maxY > box->minY && bounds->minY < box->maxY) {
            if (box->flagBD != 0 && *wanted != 1) {
                found = 0;
                idTable = func_8028FDB4_de(table, 3);
                if (*idTable > 0) {
                    list = func_8028FDB4_de(idTable, idx);
                    len = list->count;
                    ids = list->ids;
                    key = func_80250938_de(wanted, table);
                    n = 0;
                    if (found < len) {
                        do {
                            id = *ids;
                            if (id >= 0x1770) {
                                id -= 0x1770;
                            } else if (id >= 0xFA0) {
                                id -= 0xFA0;
                            } else if (id >= 0x7D0) {
                                id -= 0x7D0;
                            }
                            n++;
                            if (id == key) {
                                found = 1;
                                break;
                            }
                            ids++;
                        } while (n < len);
                    }
                }
            } else {
                found = 1;
            }
            if (found != 0) {
                *outAt = box;
                outAt++;
                foundCount++;
                if (box->flagBA != 0) {
                    result = 1;
                }
                if (foundCount == 0x40) {
                    break;
                }
            }
        }
        box++;
    }
    *countOut = foundCount;
    return result;
}
#else
INCLUDE_ASM("span_1000", func_80278020_de);
#endif

#ifdef NON_MATCHING
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
#else
INCLUDE_ASM("span_1000", func_80278274_de);
#endif

INCLUDE_ASM("span_1000", func_802784C0_de);
