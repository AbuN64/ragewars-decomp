#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS4_2.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/UNUSED.H"
#include "FX/GRAPHU64_NORMALIZEVEC3.H"
#include "COMMON/EXTERNS_15.H"
#include "RENDER/OBJECTSTATE8E.H"
#include "COMMON/WORLD.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/APPROACHLOCATION.H"
#include "ACTORS/80277444.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "particle/80271B18_3.H"
#include "stddef.h"

/* 80275E44_12.CPP */
#define SK_FIELD(base, type, offset) (*(type *)((u8 *)(base) + (offset)))

extern void Graphu64_IdentityMatrix(void *);
extern void RollMatrix(void *, f32);
extern void Graphu64_ProjectPoint(void *, void *, void *);
extern void Graphu64_ScaleMatrixWorld(void *, f32, f32, f32);
extern void TranslateMatrix(void *, f32, f32, f32);
extern void Graphu64_InvertAffineMatrix(void *, void *);
extern void Region_ComputePointBounds(void *, s32, void *);
void Lighting_DecodeBoxTransform(u8 *self, u8 *src) {
    CVector3 translation;
    CVector3 rotation;
    CVector3 scale;
    CVector3 corners[8];
    CVector3 up;
    CVector3 tilt;
    CVector3 probe;
    u8 *matrix;
    s32 inside;
    s32 i;
    f32 x;
    f32 y;
    f32 z;
    SK_FIELD(self, u8, 0xBB) = SK_FIELD(src, u8, 0x2F);
    translation.x = SK_FIELD(src, s32, 0) * 2.38418579e-05f;
    translation.y = SK_FIELD(src, s32, 4) * 2.38418579e-05f;
    translation.z = SK_FIELD(src, s32, 8) * 2.38418579e-05f;
    if (SK_FIELD(self, u8, 0xBB) != 1) {
        rotation.x = SK_FIELD(src, s32, 0xC) * 9.31322575e-09f;
        rotation.y = SK_FIELD(src, s32, 0x10) * 9.31322575e-09f;
        rotation.z = SK_FIELD(src, s32, 0x14) * 9.31322575e-09f;
    } else {
        up.x = 0;
        up.y = (-1.0f);
        up.z = 0;
        tilt.x = SK_FIELD(src, s32, 0xC) * 9.31322575e-09f;
        tilt.y = SK_FIELD(src, s32, 0x10) * 9.31322575e-09f;
        tilt.z = SK_FIELD(src, s32, 0x14) * 9.31322575e-09f;
        matrix = self + 0x60;
        Graphu64_IdentityMatrix(matrix);
        RollMatrix(matrix, tilt.x);
        YawMatrix(matrix, tilt.y);
        Graphu64_ProjectPoint(matrix, &up, self + 0x14);
        rotation.x = 0;
        rotation.y = 0;
        rotation.z = 0;
    }
    inside = 1;
    if (((rotation.x < 0) ? -rotation.x : rotation.x) > 0.00999999978f) {
        inside = 0;
    }
    if (((rotation.y < 0) ? -rotation.y : rotation.y) > 0.00999999978f) {
        inside = 0;
    }
    if (((rotation.z < 0) ? -rotation.z : rotation.z) > 0.00999999978f) {
        inside = 0;
    }
    SK_FIELD(self, u8, 0xB9) = 0;
    if (inside != 0) {
        SK_FIELD(self, u8, 0xB9) = 1;
    }
    scale.x = SK_FIELD(src, s32, 0x18) * 2.38418579e-05f;
    scale.y = SK_FIELD(src, s32, 0x1C) * 2.38418579e-05f;
    scale.z = SK_FIELD(src, s32, 0x20) * 2.38418579e-05f;
    SK_FIELD(self, f32, 0) = (f32)SK_FIELD(src, s32, 0x24) * 2 * 4.65661287e-10f;
    SK_FIELD(self, f32, 4) = (f32)SK_FIELD(src, s32, 0x28) * 2 * 4.65661287e-10f;
    if (D_801462C8.flags & 0x4000) {
        SK_FIELD(self, s32, 8) = 0;
        SK_FIELD(self, s32, 0xC) = 0;
        SK_FIELD(self, s32, 0x10) = 0;
    } else {
        SK_FIELD(self, f32, 8) = (f32)SK_FIELD(src, u32, 0x3C) * 2.37487257e-06f;
        SK_FIELD(self, f32, 0xC) = (f32)SK_FIELD(src, u32, 0x40) * 2.37487257e-06f;
        SK_FIELD(self, f32, 0x10) = (f32)SK_FIELD(src, u32, 0x44) * 2.37487257e-06f;
    }
    matrix = self + 0x60;
    SK_FIELD(self, u8, 0xB8) = SK_FIELD(src, u8, 0x37);
    SK_FIELD(self, u8, 0xBA) = SK_FIELD(src, u8, 0x3B);
    SK_FIELD(self, u8, 0xBD) = SK_FIELD(src, u8, 0x4B);
    Graphu64_IdentityMatrix(matrix);
    Graphu64_ScaleMatrixWorld(matrix, scale.x, scale.y, scale.z);
    RollMatrix(matrix, rotation.z);
    YawMatrix(matrix, rotation.y);
    PitchMatrix(matrix, rotation.x);
    TranslateMatrix(matrix, translation.x, translation.y, translation.z);
    Graphu64_InvertAffineMatrix(self + 0x20, matrix);
    for (i = 0; i < 8; i++) {
        x = 1.0f;
        y = 1.0f;
        z = 1.0f;
        if (i & 1) {
            x = -1.0f;
        }
        if (i & 2) {
            y = -1.0f;
        }
        if (i & 4) {
            z = -1.0f;
        }
        probe.x = x;
        probe.y = y;
        probe.z = z;
        Graphu64_ProjectPoint(self + 0x60, &probe, &corners[i]);
    }
    Region_ComputePointBounds(self + 0xA0, 8, corners);
}

s32 Lighting_EvaluateLocalVolume(ObjectRecAtBC *arg0, CVector3 arg1,
                  CVector3 *arg4, f32 *arg5) {
    f32 temp_f0;
    f32 var_f0;
    f32 var_f1;
    f32 var_f20;
    f32 var_f3;
    u8 temp_v1;

    var_f3 = arg1.x;
    var_f20 = 0.0f;
    if (!(D_800C4AC0_de <= var_f3) && !(var_f3 <= D_800C4AC4_de) &&
        !(D_800C4AC0_de <= arg1.y) && !(arg1.y <= D_800C4AC4_de) &&
        !(D_800C4AC0_de <= arg1.z) && !(arg1.z <= D_800C4AC4_de)) {
        temp_v1 = arg0->shape;
        switch (temp_v1) {
        case 0:
            var_f20 = (var_f3 * var_f3) + (arg1.y * arg1.y) +
                      (arg1.z * arg1.z);
            if (!(D_800C4AC0_de < var_f20)) {
                var_f20 = D_800CD3F8[(s32)(var_f20 * D_800C4AC8_de)];
                goto shared;
            }
            goto fail;
        case 2:
            if (!(var_f3 <= 0.0f)) {
                var_f20 = (arg1.y * arg1.y) +
                          (arg1.z * arg1.z);
                if (!((var_f3 * var_f3) < var_f20)) {
                    var_f20 = D_800CD4FC[(s32)(var_f20 * D_800C4ACC_de)];
                    var_f20 /= var_f3;
                    goto shared;
                }
            }
            goto fail;
        case 1:
            if (var_f3 < 0.0f) {
                var_f3 = -var_f3;
            }
            var_f0 = arg1.y;
            arg1.x = var_f3;
            if (var_f0 < 0.0f) {
                var_f0 = -var_f0;
            }
            var_f1 = arg1.z;
            arg1.y = var_f0;
            if (var_f1 < 0.0f) {
                var_f1 = -var_f1;
            }
            arg1.z = var_f1;
            var_f20 = var_f1;
            if (!(var_f0 <= var_f20)) {
                var_f20 = var_f0;
            }
            if (!(var_f3 <= var_f20)) {
                var_f20 = var_f3;
            }
            goto shared;
        default:
            goto shared;
        }
shared:
        var_f20 = D_800C4AD0_de - var_f20;
        temp_f0 = arg0->falloff;
        if (var_f20 < temp_f0) {
            var_f20 /= temp_f0;
        } else {
            var_f20 = D_800C4AD0_de;
        }
        if (arg0->shape == 1) {
            *arg4 = arg0->axis;
        } else {
            *arg4 = arg1;
        }
        Graphu64_NormalizeVec3(arg4);
        *arg5 = var_f20;
        return 1;
    } else {
fail:
        arg4->y = 0.0f;
        arg4->z = 0.0f;
        arg4->x = D_800C4AD4_de;
        *arg5 = 0.0f;
        return 0;
    }
}

/* 800C9BB0.CPP */
const unsigned int D_auto_src_rw_pool_80277128_CA7B0_us_rev1[6] = {
    0x3F800000, 0xBF800000, 0x42800000, 0x42800000, 0x3F800000, 0x3F800000,
};

/* 80277444_2.CPP */
extern void Graphu64_TransformDirection(void *arg0, void *arg1, void *arg2);

s32 Lighting_EvaluateLightVolume(ObjectRecAtBC *lightVolume, CVector3 worldPoint, CVector3 surfaceNormal, f32 *lightTransform,
                  CVector3 *lightContribution, f32 *contributionWeight) {
    CVector3 second;
    CVector3 first;
    CVector3 normal;
    f32 amount;
    f32 dot;
    f32 value;
    f32 objectValue;

    if (lightVolume->flagB9 != 0) {
        first.x = worldPoint.x * lightTransform[0];
        first.y = worldPoint.y * lightTransform[5];
        first.z = worldPoint.z * lightTransform[10];
        first.x += lightTransform[12];
        first.y += lightTransform[13];
        first.z += lightTransform[14];
        second.x = surfaceNormal.x * lightTransform[0];
        second.y = surfaceNormal.y * lightTransform[5];
        second.z = surfaceNormal.z * lightTransform[10];
    } else {
        Graphu64_TransformPoint(lightTransform, &worldPoint.x, &first);
        Graphu64_TransformDirection(lightTransform, &surfaceNormal.x, &second);
    }
    Graphu64_NormalizeVec3(&second.x);
    if (Lighting_EvaluateLocalVolume(lightVolume, first, &normal, &amount) == 0) {
        return 0;
    }
    {
        dot = -((normal.x * second.x) + (normal.y * second.y) +
                (normal.z * second.z));
        if (dot < 0.0f) {
            dot = 0.0f;
        }
        objectValue = lightVolume->value;
        value = amount * (objectValue +
                          (dot * (1.0f - objectValue)));
        amount = value;
        if (value <= 0.0f) {
            amount = 0.0f;
        }
        if (lightVolume->flagB8 != 0) {
            amount = -amount;
        }
        if (contributionWeight != 0) {
            *contributionWeight = amount;
        }
        Graphu64_ScaleVector(lightContribution, &lightVolume->direction, amount);
    }
    return 1;
}

extern void Graphu64_ConvertMatrixToFloat(f32 *, PackedMatrixWords *);
void Lighting_AccumulateVertexLighting(ObjectRecAtBC **lights, s32 lightCount, Vertices38 *mesh,
                     PackedMatrixWords *matrices, CVector3 *output, s32 multiple)
{
    f32 matrix[16];
    CVector3 sum, position, normal, worldPosition, worldNormal, contribution;
    f32 amount, selectedAmount;
    s32 count, i, j, mode, colour, level, drawn;
    CVector3 *dest;
    u32 pattern;
    Vertex38 *vertex, *base;
    ObjectRecAtBC *light;

    count = mesh->count;
    base = mesh->vertices;
    Graphu64_ConvertMatrixToFloat(matrix, matrices);
    drawn = 0;
    for (i = 0; i < count; i++) {
        vertex = &base[i];
        dest = &output[drawn];
        mode = 0;
        selectedAmount = 0.0f;
        colour = 0;
        if (vertex->flags & 0x80) {
            continue;
        }
        if (multiple) {
            Graphu64_ConvertMatrixToFloat(matrix, &matrices[vertex->flags >> 8]);
        }
        position.x = vertex->px;
        position.y = vertex->py;
        position.z = vertex->pz;
        Graphu64_TransformPoint(matrix, &position, &worldPosition);
        normal.x = vertex->x;
        normal.y = vertex->y;
        normal.z = vertex->z;
        Graphu64_TransformDirection(matrix, &normal, &worldNormal);
        sum.x = 0.0f;
        sum.y = 0.0f;
        sum.z = 0.0f;
        for (j = 0; j < lightCount; j++) {
            light = lights[j];
            contribution.x = 0.0f;
            contribution.y = 0.0f;
            contribution.z = 0.0f;
            if (light->bounds.max.x > worldPosition.x &&
                light->bounds.max.y > worldPosition.y &&
                light->bounds.max.z > worldPosition.z &&
                light->bounds.min.x <= worldPosition.x &&
                light->bounds.min.y <= worldPosition.y &&
                light->bounds.min.z <= worldPosition.z &&
                Lighting_EvaluateLightVolume(light, worldPosition, worldNormal,
                                light->inverse, &contribution, &amount)) {
                if (light->animatedLight) {
                    mode = light->animatedLight;
                    colour = light->animationSeed;
                    selectedAmount = amount;
                }
                Graphu64_AddVec3(&sum, &sum, &contribution);
            }
        }
        if (mode) {
            level = 0;
            if (selectedAmount < 0.6f) level = 1;
            if (selectedAmount < 0.3f) level = 2;
            if (mode == 1) {
                vertex->flags = (vertex->flags & 0xFF8F) |
                                (((colour % 7 + 1) << 4) & 0x70);
            }
            if (mode == 2) {
                pattern = 0;
                pattern += (u32)worldPosition.x / 10;
                pattern += (u32)worldPosition.y / 10;
                pattern += (u32)worldPosition.z / 10;
                pattern = pattern % 7 + 1;
                vertex->flags = (vertex->flags & 0xFF8F) |
                                ((pattern << 4) & 0x70);
            }
            vertex->flags = (vertex->flags & 0xFFF3) | (level << 2);
            if (selectedAmount < 0.1f) {
                vertex->flags &= 0xFF83;
            }
        }
        dest->x += sum.x;
        dest->y += sum.y;
        dest->z += sum.z;
        drawn++;
    }
}

void Lighting_AccumulateDirectionalLighting(Vertices38 *data, PackedMatrixWords *matrices, CVector3 *output, s32 skin) {
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
    Graphu64_ConvertMatrixToFloat(matrix, matrices);
    source = D_80137078;
    light.x = source->x;
    light.y = source->y;
    light.z = source->z;
    Graphu64_NormalizeVec3(&light);
    drawn = 0;
    for (i = 0; i < count; i++) {
        vertex = &base[i];
        dest = &output[drawn];
        if (!(vertex->flags & 0x80)) {
            f32 red, green, blue;
            if (skin) Graphu64_ConvertMatrixToFloat(matrix, &matrices[vertex->flags >> 8]);
            normal.x = vertex->x;
            normal.y = vertex->y;
            normal.z = vertex->z;
            Graphu64_TransformDirection(matrix, &normal, &transformed);
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

/* Collects the light volumes of the world sectors whose x/z extent overlaps box: the hit boxes in
   pack section 2 of each such sector whose bounds intersect box go to out (at most 64, with
   duplicates across sectors dropped by their summed signature words). Writes their number to
   outCount and returns 1 when any accepted box has flagBA set. */
s32 Lighting_QueryWorldLightVolumes(Bounds *box, void **out, s32 *outCount) {
    u32 keys[0x40];
    /* A query may intersect every world sector; accepted volumes are capped at 64. */
    WorldSector *sectors[128];
    s32 flag;
    s32 matches;
    s32 count;
    s32 i;
    s32 n;
    s32 j;
    u32 sum;
    s32 dup;
    WorldSector *sector;
    HitBoxTable *table;
    HitBox *entry;
    WorldSectorExtent *extent;
    Shared_World *world = &g_world;
    count = 0;
    matches = 0;
    flag = 0;
    for (i = 0; i < world->sectorEntryCount; i++) {
        sector = &world->sectors[i];
        extent = sector->bounds;
        if (extent->maxX > box->minX && extent->minX < box->maxX && extent->maxZ > box->minZ && extent->minZ < box->maxZ) {
            sectors[matches++] = sector;
        }
    }
    if (matches == 1) {
        sector = sectors[0];
        table = SetN64_GetPackSection(sector->resource->pack, 2);
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
            sector = sectors[i];
            table = SetN64_GetPackSection(sector->resource->pack, 2);
            n = table->count;
            n--;
            entry = table->boxes;
            for (; n != -1; n--) {
                if (box->maxX > entry->minX && box->minX < entry->maxX &&
                    box->maxZ > entry->minZ && box->minZ < entry->maxZ &&
                    box->maxY > entry->minY && box->minY < entry->maxY) {
                    u32 *signature = entry->signature;
                    sum = 0;
                    for (j = 0; j < 16; j++) {
                        sum += signature[j];
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

/* Filters the 0xC0-byte hit records held in table slot 2 of arg1: keeps those whose box
   (six floats at record offset 0xA0) intersects the given bounds, and which either have no
   byte set at record offset 0xBD, are paired with arg4, or list the key that
   Statinst_FindPlacedPropIndex(arg4, arg1) finds inside the id list at slot arg1-table index of the list
   table in slot 3. Writes the accepted record pointers into arg2 (at most 0x40 of them),
   reports their number through arg3, and returns 1 when any accepted record has its byte at
   record offset 0xBA set. With no table (arg1 null) it defers to Lighting_QueryWorldLightVolumes. */

extern s32 Statinst_FindPlacedPropIndex(void *wanted, void *table);

typedef struct IdList {
    u16 count;
    s16 ids[1];
} IdList;

s32 Lighting_QueryLightVolumes(Bounds *bounds, void *table, void **out, s32 *countOut, u8 *wanted) {
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
        return Lighting_QueryWorldLightVolumes(bounds, out, countOut);
    }
    boxTable = SetN64_GetPackSection(table, 2);
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
                    idTable = SetN64_GetPackSection(table, 3);
                    if (*idTable > 0) {
                        list = SetN64_GetPackSection(idTable, idx);
                        ids = (s16 *)list;
                        len = list->count;
                        ids++;
                        key = Statinst_FindPlacedPropIndex(wanted, table);
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

/* A coloured model vertex: the Vtx_t layout, colour bytes at 0xC (bit 0x80 of flags keeps the vertex colour). */
typedef struct { s16 x, y, z; u16 flags; s16 s, t; u8 r, g, b, a; } ColorVertex;
typedef struct { s32 tag, count; ColorVertex vertices[1]; } ColorMesh;
/* Accumulated light per vertex (0..255 per channel). */
typedef struct { f32 x, y, z; } VertexColor;

static inline f32 clampIntensity(f32 c) {
    f32 r;
    if (!(c <= 255.0f)) {
        c = 255.0f;
    }
    r = c;
    if (!(5.0f <= r)) {
        r = 5.0f;
    }
    return r;
}
/* Writes the accumulated lighting into the mesh's vertex colours: each channel is clamped to 5..255, blended toward
 * white by the brightness setting (brightness / 255, at most 1) and stored clamped to a byte, except on vertices
 * with flag 0x80. With setting flag 0x4000 the colours are masked to black instead. */
void Lighting_ApplyVertexColors(ColorMesh *mesh, VertexColor *colors) {
    u8 colorMask = 0;
    f32 whiteBlend;
    VertexColor color;
    ColorVertex *vertex;
    s32 count, i, channelValue;
    if (1.0f < (f32)D_801462C8.buttons * (1.0f / 255.0f)) {
        whiteBlend = 1.0f;
    } else {
        whiteBlend = (f32)D_801462C8.buttons * (1.0f / 255.0f);
    }
    vertex = mesh->vertices;
    count = mesh->count;
    if (D_801462C8.flags & 0x4000) {
        for (i = 0; i < count; i++) {
            vertex[i].r &= colorMask;
            vertex[i].g &= colorMask;
            vertex[i].b &= colorMask;
        }
    } else {
        for (i = 0; i < count; i++) {
            color = *colors++;
            color.x = clampIntensity(color.x) * (1.0f - whiteBlend) + whiteBlend * 255.0f;
            color.y = clampIntensity(color.y) * (1.0f - whiteBlend) + whiteBlend * 255.0f;
            color.z = clampIntensity(color.z) * (1.0f - whiteBlend) + whiteBlend * 255.0f;
            if (!(vertex[i].flags & 0x80)) {
                channelValue = (s32)color.x;
                channelValue = (channelValue < 256) ? ((channelValue < 0) ? 0 : ((channelValue < 256) ? channelValue : 255)) : 255;
                vertex[i].r = channelValue;
                channelValue = (s32)color.y;
                channelValue = (channelValue < 256) ? ((channelValue < 0) ? 0 : ((channelValue < 256) ? channelValue : 255)) : 255;
                vertex[i].g = channelValue;
                channelValue = (s32)color.z;
                channelValue = (channelValue < 256) ? ((channelValue < 0) ? 0 : ((channelValue < 256) ? channelValue : 255)) : 255;
                vertex[i].b = channelValue;
            }
        }
    }
}

extern char D_800C4B1C_de[13]; /* "Lit Vertices": allocation tag */
extern CVector3 D_80111D70[];
extern s32 D_800D2850;
extern s32 SetN64_GetSizedPackSection(s32 pack, s32 index, s32 *size);
extern u8 **Cache_AllocateResource(s32, s32, u32, void *);
extern void *func_802BD3A0_de(void *destination, const void *source, int count);
/* A lit model vertex: the Vtx_t layout, colour bytes at 0xC. */
typedef struct LitVertex {
    s16 position[3];
    s16 flags;
    s16 texture[2];
    u8 color[4];
} LitVertex;
/* Section 1 of a model pack: per-vertex packed RGB lighting, present when count is non-zero. */
typedef struct LitColorTable {
    s32 stride, count;
    s32 packed[1];
} LitColorTable;
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
static inline void clampLitColor(u8 *dest, LitVertex *vertex) {
    dest[0] = MAX((u8)MIN(vertex->color[0], 0xE1), 0x1E);
    dest[1] = MAX((u8)MIN(vertex->color[1], 0xE1), 0x1E);
    dest[2] = MAX((u8)MIN(vertex->color[2], 0xE1), 0x1E);
}
/* Builds a lit copy of a model pack section 0: clears the per-vertex light accumulators, copies the model into a new
 * allocation (with a colour trailer section when the bounds query found light volumes that need it), adds the model's
 * packed RGB lighting, then directional or volume lighting, applies it to the vertex colours and, for the trailer,
 * stores each vertex colour clamped to 30..225. Returns the allocation handle, or 0 when allocation fails. */
s32 Lighting_BuildLitModel(s32 modelResource, void *lightResource, Bounds *bounds, PackedMatrixWords *matrices, s32 skinned,
                         u8 *wanted) {
    void *lights[0x40];
    s32 lightCount;
    s32 needsColors;
    s32 modelBytes;
    Vertices38 *model;
    u8 **allocation;
    Vertices38 *copiedModel;
    u8 *colors = 0;
    LitColorTable *table;
    s32 modelVertexCount;
    s32 clearIndex, colorIndex, sectorIndex, trailerIndex;
    s32 worldLightCount;
    s32 packedColor;
    s32 *pack;
    needsColors = Lighting_QueryLightVolumes(bounds, lightResource, lights, &lightCount, wanted);
    model = (Vertices38 *)SetN64_GetSizedPackSection(modelResource, 0, &modelBytes);
    modelVertexCount = model->count;
    for (clearIndex = 0; clearIndex < modelVertexCount; clearIndex++) {
        D_80111D70[clearIndex].x = 0;
        D_80111D70[clearIndex].y = 0;
        D_80111D70[clearIndex].z = 0;
    }
    if (needsColors != 0) {
        allocation = Cache_AllocateResource(0, modelBytes + 4 * sizeof(s32) + model->count * 4, 0, D_800C4B1C_de);
        if (allocation == 0) {
            return 0;
        }
        /* section pack: last section index, section offsets, 0xDEADBEEF end marker */
        pack = (s32 *)*allocation;
        pack[0] = 1;
        pack[1] = 0x10;
        pack[2] = modelBytes + 0x10;
        pack[3] = 0xDEADBEEF;
        copiedModel = (Vertices38 *)(*allocation + pack[1]);
        colors = *allocation + pack[2];
        func_802BD3A0_de(copiedModel, model, modelBytes);
    } else {
        allocation = Cache_AllocateResource(0, modelBytes + 8, 0, D_800C4B1C_de);
        if (allocation == 0) {
            return 0;
        }
        ((s32 *)*allocation)[0] = 0;
        copiedModel = (Vertices38 *)(*allocation + 8);
        func_802BD3A0_de(copiedModel, model, modelBytes);
    }
    table = SetN64_GetPackSection((void *)modelResource, 1);
    if (table->count != 0) {
        s32 *packed = table->packed;
        for (colorIndex = 0; colorIndex < modelVertexCount; colorIndex++) {
            CVector3 *light = &D_80111D70[colorIndex];
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
        Lighting_AccumulateDirectionalLighting(copiedModel, matrices, D_80111D70, skinned);
    } else if (lightCount == 0) {
        Shared_World *world = &g_world;
        worldLightCount = 0;
        for (sectorIndex = 0; sectorIndex < world->sectorEntryCount; sectorIndex++) {
            worldLightCount += ((HitBoxTable *)SetN64_GetPackSection(*(void **)world->sectors[sectorIndex].resource, 2))->count;
        }
        if (worldLightCount == 0) {
            Lighting_AccumulateDirectionalLighting(copiedModel, matrices, D_80111D70, skinned);
        }
    } else {
        Lighting_AccumulateVertexLighting((ObjectRecAtBC **)lights, lightCount, copiedModel, matrices, D_80111D70, skinned);
    }
    Lighting_ApplyVertexColors((void *)copiedModel, (void *)D_80111D70);
    if (needsColors != 0) {
        s32 vertexCount = copiedModel->count;
        s32 colorSlot = 0;
        LitVertex *vertices = (LitVertex *)copiedModel->vertices;
        for (trailerIndex = 0; trailerIndex < vertexCount; trailerIndex++) {
            u8 *dest = &colors[colorSlot * 4];
            colorSlot++;
            clampLitColor(dest, &vertices[trailerIndex]);
        }
    }
    return (s32)allocation;
}

/* 800C9C0C_2.CPP */
#if !(defined(VERSION_US_REV1))
const char D_802784C0_CA80C[13] =
    "Lit Vertices\000";
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C4A59[7] = {
    0x11, 0x43, 0x43, 0x61, 0x6D, 0x65, 0x72,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C4E19[7] = {
    0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C4DD9[7] = {
    0xE3, 0x18, 0x23, 0x00, 0x03, 0x18, 0x80,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C4B29[7] = {
    0x06, 0x34, 0x03, 0x8E, 0x84, 0x00, 0x38,
};
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802784C0_CA80C_us_rev1.c */
const unsigned char D_blob_0351673e4abfd2bdc73f[] = {
    0x4C, 0x69, 0x74, 0x20, 0x56, 0x65, 0x72, 0x74, 0x69, 0x63, 0x65, 0x73, 0x00,
#if defined(VERSION_US_REV1)
    0x83, 0x12, 0x6F,
#endif
};
#endif
