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

#ifdef NON_MATCHING
#define AC_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))
extern void *func_8028FDB4_de(void *, s32);
s32 func_80277C54_de(void *bounds, void **outList, s32 *outCount) {
    f32 *box = bounds;
    u8 **out = (u8 **)outList;
    u8 *items[0x40];
    s32 keys[0x40];
    s32 flag = 0;
    s32 matches = 0;
    s32 count = 0;
    s32 i;
    s32 k;
    s32 n;
    s32 j;
    s32 sum;
    s32 dup;
    u8 *item;
    u8 *table;
    u8 *entry;
    f32 *other;
    for (i = 0; i < AC_FIELD(&D_8011FE88, s32, 0x1500); i++) {
        item = (u8 *)&D_8011FE88 + 0x1508 + i * 0xC;
        other = AC_FIELD(item, f32 *, 4);
        if (box[0] < other[2] && other[0] < box[3] && box[2] < other[3] && other[1] < box[5]) {
            items[matches++] = item;
        }
    }
    if (matches == 1) {
        table = func_8028FDB4_de(**(void ***)items[0], 2);
        entry = table + 8;
        for (n = AC_FIELD(table, s32, 4) - 1; n != -1; n--, entry += 0xC0) {
            if (AC_FIELD(entry, f32, 0xA0) < box[3] && box[0] < AC_FIELD(entry, f32, 0xAC) &&
                AC_FIELD(entry, f32, 0xA8) < box[5] && box[2] < AC_FIELD(entry, f32, 0xB4) &&
                AC_FIELD(entry, f32, 0xA4) < box[4] && box[1] < AC_FIELD(entry, f32, 0xB0)) {
                out[count++] = entry;
                if (AC_FIELD(entry, u8, 0xBA) != 0) {
                    flag = 1;
                }
                if (count == 0x40) {
                    break;
                }
            }
        }
    } else if (matches == 0) {
        *outCount = count;
        return flag;
    } else {
        for (k = 0; k < matches; k++) {
            table = func_8028FDB4_de(**(void ***)items[k], 2);
            entry = table + 8;
            for (n = AC_FIELD(table, s32, 4) - 1; n != -1; n--, entry += 0xC0) {
                if (AC_FIELD(entry, f32, 0xA0) < box[3] && box[0] < AC_FIELD(entry, f32, 0xAC) &&
                    AC_FIELD(entry, f32, 0xA8) < box[5] && box[2] < AC_FIELD(entry, f32, 0xB4) &&
                    AC_FIELD(entry, f32, 0xA4) < box[4] && box[1] < AC_FIELD(entry, f32, 0xB0)) {
                    sum = 0;
                    for (j = 0; j < 16; j++) {
                        sum += AC_FIELD(entry, s32, 0x60 + j * 4);
                    }
                    dup = 0;
                    if (k != 0) {
                        for (j = 0; j < count; j++) {
                            if (keys[j] == sum) {
                                dup = 1;
                                break;
                            }
                        }
                    }
                    if (dup == 0) {
                        out[count] = entry;
                        keys[count] = sum;
                        count++;
                        if (AC_FIELD(entry, u8, 0xBA) != 0) {
                            flag = 1;
                        }
                        if (count == 0x40) {
                            *outCount = count;
                            return flag;
                        }
                    }
                }
            }
        }
    }
    *outCount = count;
    return flag;
}
#else
INCLUDE_ASM("span_1000", func_80277C54_de);
#endif

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

    foundCount = 0;
    result = 0;
    if (table == NULL) {
        return func_80277C54_de(bounds, out, countOut);
    }
    boxTable = func_8028FDB4_de(table, 2);
    idx = boxTable->count;
    idx--;
    box = boxTable->boxes;
    for (; idx != -1; idx--) {
        if (bounds->maxX > box->minX && bounds->minX < box->maxX
            && bounds->maxZ > box->minZ && bounds->minZ < box->maxZ
            && bounds->maxY > box->minY && bounds->minY < box->maxY) {
            if (box->flagBD != 0) {
                found = 0;
                if (*wanted == 1) {
                    found = 1;
                } else {
                    idTable = func_8028FDB4_de(table, 3);
                    if (*idTable > 0) {
                        list = func_8028FDB4_de(idTable, idx);
                        ids = (s16 *)list;
                        len = list->count;
                        ids++;
                        key = func_80250938_de(wanted, table);
                        for (n = 0; n < len; n++) {
                            id = *ids;
                            if (id >= 0x1770) {
                                id -= 0x1770;
                            } else if (id >= 0xFA0) {
                                id -= 0xFA0;
                            } else if (id >= 0x7D0) {
                                id -= 0x7D0;
                            }
                            if (id == key) {
                                found = 1;
                                break;
                            }
                            ids++;
                        }
                    }
                }
            } else {
                found = 1;
            }
            if (found != 0) {
                out[foundCount] = box;
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

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct { s16 x, y, z; u16 flags; s16 s, t; u8 r, g, b, a; } ColorVertex;
typedef struct { s32 tag, count; ColorVertex vertices[1]; } ColorMesh;
typedef struct { f32 x, y, z; } VertexColor;
extern u32 D_80142218;
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
    if (*(u32 *)&D_801462C8 & 0x4000) {
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

#ifdef NON_MATCHING
extern u8 D_800C4B1C_de[];
extern f32 D_80111D70[];
extern s32 D_800D2850;
extern u8 *func_8028FDC8_de();
extern u8 **func_8025343C_de();
extern void func_802BD3A0_de();
extern void Actors_AccumulateVertexLighting();
s32 func_802784C0_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 buffer[0x100];
    s32 hasOwner;
    s32 size;
    u8 *model;
    u8 **memory;
    u8 *data;
    u8 *colors = 0;
    u8 *table;
    s32 count;
    s32 i;
    s32 sum;
    s32 word;
    u8 *header;
    func_80278020_de((void *)arg2, (void *)arg1, (void **)buffer, &hasOwner, (u8 *)arg5);
    model = func_8028FDC8_de(arg0, 0, &size);
    count = *(s32 *)(model + 4);
    for (i = 0; i < count; i++) {
        D_80111D70[i * 3] = 0;
        D_80111D70[i * 3 + 1] = 0;
        D_80111D70[i * 3 + 2] = 0;
    }
    if (arg5 != 0) {
        memory = func_8025343C_de(0, 0, size + count * 4 + 0x10, D_800C4B1C_de);
        if (memory == 0) {
            return 0;
        }
        header = *memory;
        *(s32 *)header = 1;
        *(s32 *)(header + 4) = 0x10;
        *(s32 *)(header + 0xC) = 0xDEADBEEF;
        *(s32 *)(header + 8) = size + 0x10;
        data = *memory + *(s32 *)(header + 4);
        colors = *memory + *(s32 *)(header + 8);
    } else {
        memory = func_8025343C_de(0, 0, size + 8, D_800C4B1C_de);
        if (memory == 0) {
            return 0;
        }
        *(s32 *)*memory = 0;
        data = *memory + 8;
    }
    func_802BD3A0_de(data, model, size);
    table = func_8028FDB4_de(arg0, 1);
    if (*(s32 *)(table + 4) != 0) {
        for (i = 0; i < count; i++) {
            word = *(s32 *)(table + 8 + i * 4);
            D_80111D70[i * 3] += (s8)(word >> 16) * 2;
            D_80111D70[i * 3 + 1] += (s8)(word >> 8) * 2;
            D_80111D70[i * 3 + 2] += (s8)word * 2;
        }
    }
    if (D_800D2850 == 0) {
        func_80277A98_de((void *)data, (void *)arg3, (void *)D_80111D70, arg4);
    } else if (hasOwner != 0) {
        Actors_AccumulateVertexLighting(buffer, hasOwner, data, arg3, D_80111D70, arg4);
    } else {
        sum = 0;
        for (i = 0; i < *(s32 *)((u8 *)&D_8011FE88 + 0x1500); i++) {
            sum += *(s32 *)((u8 *)func_8028FDB4_de(**(void ***)((u8 *)&D_8011FE88 + 0x1508 + i * 0xC), 2) + 4);
        }
        if (sum == 0) {
            func_80277A98_de((void *)data, (void *)arg3, (void *)D_80111D70, arg4);
        }
    }
    func_80278274_de((void *)data, (void *)D_80111D70);
    if (arg5 != 0) {
        for (i = 0; i < *(s32 *)(data + 4); i++) {
            u8 *vertex = data + 8 + i * 0x10;
            s32 channel;
            for (channel = 0; channel < 3; channel++) {
                u8 value = vertex[0xC + channel];
                if (value > 0xE1) {
                    value = 0xE1;
                } else if (value < 0x1E) {
                    value = 0x1E;
                }
                colors[i * 4 + channel] = value;
            }
        }
    }
    return (s32)memory;
}
#else
INCLUDE_ASM("span_1000", func_802784C0_de);
#endif
