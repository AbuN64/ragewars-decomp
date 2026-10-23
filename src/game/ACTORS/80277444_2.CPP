#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/WORLD.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "ACTORS/80277444.H"
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

typedef struct Bounds {
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
} Bounds;

typedef struct HitBox {
    u8 pad0[0x60];
    u32 signature[16];
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

#ifdef NON_MATCHING
extern void *func_8028FDB4_de(void *, s32);
/* NON_MATCHING: 9 aligned edits / 243 ROM words; remaining: sector address registers and signature-loop base. */
s32 Actors_QueryWorldLightVolumes(Bounds *box, void **out, s32 *outCount) {
    u32 keys[0x40];
    /* A query may intersect every world sector; accepted volumes are capped at 64. */
    WorldSector *items[128];
    s32 flag;
    s32 matches;
    s32 count;
    s32 i;
    s32 n;
    s32 j;
    u32 sum;
    s32 dup;
    WorldSector *item;
    HitBoxTable *table;
    HitBox *entry;
    f32 *other;
    Shared_World *world = &D_8011FE88;
    count = 0;
    matches = 0;
    flag = 0;
    for (i = 0; i < world->sectorEntryCount; i++) {
        item = &world->sectors[i];
        other = item->bounds;
        if (other[2] > box->minX && other[0] < box->maxX && other[3] > box->minZ && other[1] < box->maxZ) {
            items[matches++] = item;
        }
    }
    if (matches == 1) {
        table = func_8028FDB4_de(*(void **)items[0]->resource, 2);
        n = table->count;
        n--;
        entry = table->boxes;
        for (; n != -1; n--) {
            if (box->maxX > entry->minX && box->minX < entry->maxX &&
                box->maxZ > entry->minZ && box->minZ < entry->maxZ &&
                box->maxY > entry->minY && box->minY < entry->maxY) {
                out[count++] = entry;
                if (entry->flagBA != 0) {
                    flag = 1;
                }
                if (count == 0x40) {
                    break;
                }
            }
            entry++;
        }
    } else if (matches < 2) {
        *outCount = count;
        return flag;
    } else {
        for (i = 0; i < matches; i++) {
            table = func_8028FDB4_de(*(void **)items[i]->resource, 2);
            n = table->count;
            n--;
            entry = table->boxes;
            for (; n != -1; n--) {
                if (box->maxX > entry->minX && box->minX < entry->maxX &&
                    box->maxZ > entry->minZ && box->minZ < entry->maxZ &&
                    box->maxY > entry->minY && box->minY < entry->maxY) {
                    sum = 0;
                    for (j = 0; j < 16; j++) {
                        sum += entry->signature[j];
                    }
                    dup = 0;
                    if (i != 0) {
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
                        if (entry->flagBA != 0) {
                            flag = 1;
                        }
                        if (count == 0x40) {
                            *outCount = count;
                            return flag;
                        }
                    }
                }
                entry++;
            }
        }
    }
    *outCount = count;
    return flag;
}
#else
INCLUDE_ASM("span_1000", Actors_QueryWorldLightVolumes);
#endif

#include "TYPES.H"
#include "stddef.h"

/* Filters the 0xC0-byte hit records held in table slot 2 of arg1: keeps those whose box
   (six floats at record offset 0xA0) intersects the given bounds, and which either have no
   byte set at record offset 0xBD, are paired with arg4, or list the key that
   func_80250938_de(arg4, arg1) finds inside the id list at slot arg1-table index of the list
   table in slot 3. Writes the accepted record pointers into arg2 (at most 0x40 of them),
   reports their number through arg3, and returns 1 when any accepted record has its byte at
   record offset 0xBA set. With no table (arg1 null) it defers to Actors_QueryWorldLightVolumes. */

extern s32 Actors_QueryWorldLightVolumes(Bounds *bounds, void **out, s32 *countOut);
extern s32 func_80250938_de(void *wanted, void *table);

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
        return Actors_QueryWorldLightVolumes(bounds, out, countOut);
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

void func_80278274_de(ColorMesh *mesh, VertexColor *colors) {
    f32 blend, c;
    VertexColor color;
    ColorVertex *v;
    s32 count, i, n;
    if (1.0f < (f32)D_80142218 * (1.0f / 255.0f)) {
        blend = 1.0f;
    } else {
        blend = (f32)D_80142218 * (1.0f / 255.0f);
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
            c = color.x;
            if (!(c <= 255.0f)) c = 255.0f;
            if (!(5.0f <= c)) c = 5.0f;
            color.x = c * (1.0f - blend) + blend * 255.0f;
            c = color.y;
            if (!(c <= 255.0f)) c = 255.0f;
            if (!(5.0f <= c)) c = 5.0f;
            color.y = c * (1.0f - blend) + blend * 255.0f;
            c = color.z;
            if (!(c <= 255.0f)) c = 255.0f;
            if (!(5.0f <= c)) c = 5.0f;
            color.z = c * (1.0f - blend) + blend * 255.0f;
            if (!(v->flags & 0x80)) {
                n = (s32)color.x;
                n = (n < 256) ? ((n < 0) ? 0 : n) : 255;
                v->r = n;
                n = (s32)color.y;
                n = (n < 256) ? ((n < 0) ? 0 : n) : 255;
                v->g = n;
                n = (s32)color.z;
                n = (n < 256) ? ((n < 0) ? 0 : n) : 255;
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
/* NON_MATCHING: 180 aligned edits / 244 ROM words; remaining: register allocation and scheduling.
 * The query return selects the color trailer; the output count selects the light list.
 * The allocator takes the byte count before the flags. */
s32 Actors_BuildLitModel(s32 deref2, s32 arg1, void *bounds, void *matrices, s32 arg4, void *wanted) {
    u8 buffer[0x100];
    s32 hasOwner;
    s32 needsColors;
    s32 size;
    u8 *model;
    u8 **memory;
    u8 *data;
    u8 *colors = 0;
    u8 *table;
    s32 count;
    s32 clearIndex, colorIndex, sectorIndex, trailerIndex;
    s32 sum;
    s32 word;
    u8 *header;
    needsColors = func_80278020_de((void *)bounds, (void *)arg1, (void **)buffer, &hasOwner, (u8 *)wanted);
    model = func_8028FDC8_de(deref2, 0, &size);
    count = *(s32 *)(model + 4);
    for (clearIndex = 0; clearIndex < count; clearIndex++) {
        D_80111D70[clearIndex * 3] = 0;
        D_80111D70[clearIndex * 3 + 1] = 0;
        D_80111D70[clearIndex * 3 + 2] = 0;
    }
    if (needsColors != 0) {
        memory = func_8025343C_de(0, size + (*(s32 *)(model + 4) * 4 + 0x10), 0, D_800C4B1C_de);
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
        memory = func_8025343C_de(0, size + 8, 0, D_800C4B1C_de);
        if (memory == 0) {
            return 0;
        }
        *(s32 *)*memory = 0;
        data = *memory + 8;
    }
    func_802BD3A0_de(data, model, size);
    table = func_8028FDB4_de(deref2, 1);
    if (*(s32 *)(table + 4) != 0) {
        for (colorIndex = 0; colorIndex < count; colorIndex++) {
            word = *(s32 *)(table + 8 + colorIndex * 4);
            D_80111D70[colorIndex * 3] += (s8)(word >> 16) * 2;
            D_80111D70[colorIndex * 3 + 1] += (s8)(word >> 8) * 2;
            D_80111D70[colorIndex * 3 + 2] += (s8)word * 2;
        }
    }
    if (D_800D2850 == 0) {
        func_80277A98_de((void *)data, (void *)matrices, (void *)D_80111D70, arg4);
    } else if (hasOwner != 0) {
        Actors_AccumulateVertexLighting(buffer, hasOwner, data, matrices, D_80111D70, arg4);
    } else {
        sum = 0;
        for (sectorIndex = 0; sectorIndex < *(s32 *)((u8 *)&D_8011FE88 + 0x1500); sectorIndex++) {
            sum += *(s32 *)((u8 *)func_8028FDB4_de(**(void ***)((u8 *)&D_8011FE88 + 0x1508 + sectorIndex * 0xC), 2) + 4);
        }
        if (sum == 0) {
            func_80277A98_de((void *)data, (void *)matrices, (void *)D_80111D70, arg4);
        }
    }
    func_80278274_de((void *)data, (void *)D_80111D70);
    if (needsColors != 0) {
        for (trailerIndex = 0; trailerIndex < *(s32 *)(data + 4); trailerIndex++) {
            u8 *vertex = data + 8 + trailerIndex * 0x10;
            s32 channel;
            for (channel = 0; channel < 3; channel++) {
                u8 value = vertex[0xC + channel];
                if (value > 0xE1) {
                    value = 0xE1;
                } else if (value < 0x1E) {
                    value = 0x1E;
                }
                colors[trailerIndex * 4 + channel] = value;
            }
        }
    }
    return (s32)memory;
}
#else
INCLUDE_ASM("span_1000", Actors_BuildLitModel);
#endif
