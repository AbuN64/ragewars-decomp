#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/WORLD.H"
#include "COMMON/SHARED_GAMESLOT.H"
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
/* NON_MATCHING: 7 aligned edits / 243 ROM words; remaining: sector address registers. */
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
                    u32 *signatureWords = entry->signature;
                    sum = 0;
                    for (j = 0; j < 16; j++) {
                        sum += signatureWords[j];
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

/* 34/147 aligned edits left (was 64): the u8 clamp ladder (the ROM re-tests value < 256 after the < 0 test, the shape
 * of a distributed MAX(MIN(v, 255), 0)), the z channel's extra clamp copy, and a zeroed a3 in the prologue. */
static inline f32 clampIntensity(f32 c) {
    if (!(c <= 255.0f)) {
        c = 255.0f;
    }
    if (!(5.0f <= c)) {
        c = 5.0f;
    }
    return c;
}
void Actors_ApplyVertexColors(ColorMesh *mesh, VertexColor *colors) {
    f32 whiteBlend, channelIntensity;
    VertexColor color;
    ColorVertex *vertex;
    s32 count, i, channelValue;
    if (1.0f < (f32)D_80142218 * (1.0f / 255.0f)) {
        whiteBlend = 1.0f;
    } else {
        whiteBlend = (f32)D_80142218 * (1.0f / 255.0f);
    }
    vertex = mesh->vertices;
    count = mesh->count;
    if (D_801462C8.flags & 0x4000) {
        for (i = 0; i < count; i++) {
            vertex[i].r = 0;
            vertex[i].g = 0;
            vertex[i].b = 0;
        }
    } else {
        for (i = 0; i < count; i++) {
            color = *colors++;
            color.x = clampIntensity(color.x) * (1.0f - whiteBlend) + whiteBlend * 255.0f;
            color.y = clampIntensity(color.y) * (1.0f - whiteBlend) + whiteBlend * 255.0f;
            color.z = clampIntensity(color.z) * (1.0f - whiteBlend) + whiteBlend * 255.0f;
            if (!(vertex[i].flags & 0x80)) {
                channelValue = (s32)color.x;
                channelValue = (channelValue < 256) ? ((channelValue < 0) ? 0 : channelValue) : 255;
                vertex[i].r = channelValue;
                channelValue = (s32)color.y;
                channelValue = (channelValue < 256) ? ((channelValue < 0) ? 0 : channelValue) : 255;
                vertex[i].g = channelValue;
                channelValue = (s32)color.z;
                channelValue = (channelValue < 256) ? ((channelValue < 0) ? 0 : channelValue) : 255;
                vertex[i].b = channelValue;
            }
        }
    }
}
#else
INCLUDE_ASM("span_1000", Actors_ApplyVertexColors);
#endif

#ifdef NON_MATCHING
extern u8 D_800C4B1C_de[];
extern f32 D_80111D70[], D_80111D74[], D_80111D78[];
extern s32 D_800D2850;
extern u8 *func_8028FDC8_de();
extern u8 **func_8025343C_de();
extern void func_802BD3A0_de();
extern void Actors_AccumulateVertexLighting();
typedef struct LitVertex {
    s16 position[3];
    s16 flags;
    s16 texture[2];
    u8 color[4];
} LitVertex;
typedef struct LitModelAllocation {
    s32 hasColors, modelOffset, colorsOffset;
    u32 guard;
} LitModelAllocation;

static inline u8 clampLitChannel(u8 value) {
    return (u8)(value < 0xE1 ? value : 0xE1) > 0x1E
        ? (value < 0xE1 ? value : 0xE1) : 0x1E;
}

/* NON_MATCHING: 72 aligned edits / 244 ROM words; remaining: model/count (s0/s1) and copiedModel/world (s3/s4) priorities,
 * header offsets re-read after the header stores in the ROM.
 * The query return selects the color trailer; the output count selects the light list.
 * The allocator takes the byte count before the flags. */
s32 Actors_BuildLitModel(s32 modelResource, s32 lightResource, void *bounds, void *matrices, s32 skinned, void *wanted) {
    void *lights[0x40];
    s32 lightCount;
    s32 needsColors;
    s32 modelBytes;
    Vertices38 *model;
    u8 **allocation;
    u8 *copiedModel;
    u8 *colors = 0;
    u8 *table;
    s32 modelVertexCount;
    s32 clearIndex, colorIndex, sectorIndex, trailerIndex;
    s32 worldLightCount;
    s32 packedColor;
    LitModelAllocation *header;
    needsColors = func_80278020_de((void *)bounds, (void *)lightResource, (void **)lights, &lightCount, (u8 *)wanted);
    model = (Vertices38 *)func_8028FDC8_de(modelResource, 0, &modelBytes);
    modelVertexCount = model->count;
    for (clearIndex = 0; clearIndex < modelVertexCount; clearIndex++) {
        D_80111D70[clearIndex * 3] = 0;
        D_80111D74[clearIndex * 3] = 0;
        D_80111D78[clearIndex * 3] = 0;
    }
    if (needsColors != 0) {
        allocation = func_8025343C_de(0, modelBytes + sizeof(LitModelAllocation) + model->count * 4, 0, D_800C4B1C_de);
        if (allocation == 0) {
            return 0;
        }
        header = (LitModelAllocation *)*allocation;
        header->hasColors = 1;
        header->modelOffset = 0x10;
        header->guard = 0xDEADBEEF;
        header->colorsOffset = modelBytes + 0x10;
        copiedModel = *allocation + header->modelOffset;
        colors = *allocation + header->colorsOffset;
    } else {
        allocation = func_8025343C_de(0, modelBytes + 8, 0, D_800C4B1C_de);
        if (allocation == 0) {
            return 0;
        }
        *(s32 *)*allocation = 0;
        copiedModel = *allocation + 8;
    }
    func_802BD3A0_de(copiedModel, model, modelBytes);
    table = func_8028FDB4_de(modelResource, 1);
    if (*(s32 *)(table + 4) != 0) {
        s32 *packed = (s32 *)(table + 8);
        for (colorIndex = 0; colorIndex < modelVertexCount; colorIndex++) {
            CVector3 *light = &((CVector3 *)D_80111D70)[colorIndex];
            s32 red, green, blue;
            packedColor = packed[colorIndex];
            red = ((s32)((u32)(packedColor & 0xFF0000) << 8)) >> 23;
            green = (s8)(packedColor >> 8) * 2;
            blue = ((s32)((u32)packedColor << 24)) >> 23;
            light->x += red;
            light->y += green;
            light->z += blue;
        }
    }
    if (D_800D2850 == 0) {
        func_80277A98_de((void *)copiedModel, (void *)matrices, (void *)D_80111D70, skinned);
    } else if (lightCount == 0) {
        Shared_World *world = &D_8011FE88;
        worldLightCount = 0;
        for (sectorIndex = 0; sectorIndex < world->sectorEntryCount; sectorIndex++) {
            worldLightCount += ((HitBoxTable *)func_8028FDB4_de(*(void **)world->sectors[sectorIndex].resource, 2))->count;
        }
        if (worldLightCount == 0) {
            func_80277A98_de((void *)copiedModel, (void *)matrices, (void *)D_80111D70, skinned);
        }
    } else {
        Actors_AccumulateVertexLighting(lights, lightCount, copiedModel, matrices, D_80111D70, skinned);
    }
    Actors_ApplyVertexColors((void *)copiedModel, (void *)D_80111D70);
    if (needsColors != 0) {
        s32 vertexCount = *(s32 *)(copiedModel + 4);
        u8 *color = colors;
        LitVertex *vertices = (LitVertex *)(copiedModel + 8);
        for (trailerIndex = 0; trailerIndex < vertexCount; trailerIndex++) {
            u8 *dest = color;
            color += 4;
            dest[0] = clampLitChannel(vertices[trailerIndex].color[0]);
            dest[1] = clampLitChannel(vertices[trailerIndex].color[1]);
            dest[2] = clampLitChannel(vertices[trailerIndex].color[2]);
        }
    }
    return (s32)allocation;
}
#else
INCLUDE_ASM("span_1000", Actors_BuildLitModel);
#endif
