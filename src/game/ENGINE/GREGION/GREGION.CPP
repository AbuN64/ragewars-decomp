#include "COMMON/PACKED.H"
#include "COMMON/OBJ.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "FX/80271B18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTLINKS4_2.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJB.H"
#include "include_asm.h"

/* 8027451C_2.CPP */
/* Returns the rotation quaternion that tilts the up axis onto a polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one, straight up for no polygon), recording the half-angle sine in D_80115DEC and giving the identity when the normal is vertical. Adapted from func_80275688_de with the cached polygon normal of Region_TestPolygonSlopeFlag replacing Graphu64_GetCachedSurfaceNormal and the default normals written through their separate cells. */

extern Triangle *D_800CD3E8;

extern Triangle *D_800CD3EC;

extern void GraphU64_SubtractVectors(CVector3 *out, CVector3 *a, CVector3 *b);

extern void Graphu64_CrossVectors(CVector3 *out, CVector3 *a, CVector3 *b);

extern void GraphU64_ScaleVector(CVector3 *out, CVector3 *in, f32 scale);

extern f32 Gu_Sqrtf(f32);

static inline void edge(CVector3 *out, CVector3 *a, CVector3 *b) {
    GraphU64_SubtractVectors(out, a, b);
}

static inline void normalize_copy(CVector3 *out, CVector3 *in) {
    *out = *in;
    GraphU64_NormalizeVec3(out);
}

extern void Graphu64_GetCachedSurfaceNormal(CVector3 *);

CQuatern *Region_GetPolygonUpQuat(CQuatern *out, Triangle *polygon) {
    CVector3 normal;
    CVector3 up;
    CVector3 axis;
    CQuatern result;
    CVector3 edge0;
    CVector3 edge1;
    f32 one;
    f32 len;
    f32 angle;
    f32 scale;

    if (polygon == 0) {
        *(s32 *)&D_80115E20 = 0;
        D_80111D68 = 0;
        D_80111D64 = 1.0f;
    } else if (polygon != D_800CD3EC) {
        if (polygon == 0) {
            *(s32 *)&D_80115E10 = 0;
            D_80111D58 = 0;
            D_80111D54 = 1.0f;
        } else if (polygon != D_800CD3E8) {
            edge(&edge0, polygon->vertices[1], polygon->vertices[0]);
            edge(&edge1, polygon->vertices[2], polygon->vertices[1]);
            Graphu64_CrossVectors(&D_80115E10, &edge0, &edge1);
        }
        D_800CD3E8 = polygon;
        normalize_copy(&D_80115E20, &D_80115E10);
    }
    one = 1.0f;
    D_800CD3EC = polygon;
    normal = D_80115E20;
    up.x = 0.0f;
    up.y = one;
    up.z = 0.0f;
    Graphu64_CrossVectors(&axis, &up, &normal);
    len = Gu_Sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0.0f) {
        result.z = 0.0f;
        result.y = 0.0f;
        result.x = 0.0f;
        result.w = one;
    } else {
        GraphU64_ScaleVector(&axis, &axis, one / len);
        angle = Graphu64_ArcCos(up.x * normal.x + up.y * normal.y + up.z * normal.z);
        angle *= 0.5f;
        scale = Math_Sinf(angle);
        result.x = axis.x * scale;
        result.y = axis.y * scale;
        result.z = axis.z * scale;
        D_80115DEC = scale;
        result.w = Math_Cosf(angle);
    }
    *out = result;
    return out;
}

CQuatern *Region_GetCachedUpQuat(CQuatern *out, Triangle *polygon) {
    CVector3 a;
    CVector3 up;
    CVector3 axis;
    CQuatern result;
    float len;
    float angle;
    float scale;
    float one;

    Graphu64_GetCachedSurfaceNormal(&a);
    one = D_800C49D8_de[1];
    up.x = 0;
    up.y = one;
    up.z = 0;
    Graphu64_CrossVectors(&axis, &up, &a);
    len = Gu_Sqrtf(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);
    if (len == 0) {
        result.z = 0;
        result.y = 0;
        result.x = 0;
        result.w = one;
    } else {
        GraphU64_ScaleVector(&axis, &axis, one / len);
        angle = Graphu64_ArcCos(up.x * a.x + up.y * a.y + up.z * a.z);
        angle *= D_800C49E0_de;
        scale = Math_Sinf(angle);
        result.x = axis.x * scale;
        result.y = axis.y * scale;
        result.z = axis.z * scale;
        D_80115DEC = scale;
        result.w = Math_Cosf(angle);
    }
    *out = result;
    return out;
}

/* 8027451C_3.CPP */
/* Returns whether a polygon counts as a wall: without flag 0x2000 it returns its flag 8, and otherwise it takes the polygon's unit normal (recomputed from its edges into D_80115E10 and normalised into D_80115E20 whenever the polygon differs from the last one) and returns whether the normal's upward component is at most D_800C9AD8. */

s32 Region_TestPolygonSlopeFlag(Triangle *polygon) {
    CVector3 up;
    CVector3 normal;
    CVector3 edge0;
    CVector3 edge1;

    if (polygon == 0) {
        return 0;
    }
    if (!(polygon->flags & 0x2000)) {
        return polygon->flags & 8;
    }
    up.x = 0.0f;
    up.y = *(&D_800C49E0_de + 1);
    up.z = 0.0f;
    if (polygon != D_800CD3EC) {
        if (polygon == 0) {
            *(s32 *)&D_80115E10 = 0;
            D_80111D54 = *(&D_800C49E0_de + 1);
            D_80111D58 = 0;
        } else if (polygon != D_800CD3E8) {
            edge(&edge0, polygon->vertices[1], polygon->vertices[0]);
            edge(&edge1, polygon->vertices[2], polygon->vertices[1]);
            Graphu64_CrossVectors(&D_80115E10, &edge0, &edge1);
        }
        D_800CD3E8 = polygon;
        normalize_copy(&D_80115E20, &D_80115E10);
    }
    normal = D_80115E20;
    D_800CD3EC = polygon;
    if (normal.x * up.x + normal.y * up.y + normal.z * up.z <= D_800C9AD8) {
        return 1;
    }
    return 0;
}

void Region_ComputePointBounds(f32 *pointBounds, s32 pointCount, CVector3 *pointCursor)
{
    s32 i;

    i = 0;
    if (pointCount != 0) {
        pointBounds[0] = pointCursor->x;
        pointBounds[1] = pointCursor->y;
        pointBounds[2] = pointCursor->z;
        pointBounds[3] = pointCursor->x;
        pointBounds[4] = pointCursor->y;
        pointCount -= 1;
        pointBounds[5] = pointCursor->z;
        pointCursor += 1;

        if (pointCount > 0) {
bounds_loop:
                {
                    f32 value = pointCursor->x;
                    f32 bound = pointBounds[0];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    pointBounds[0] = value;
                }

                {
                    f32 value = pointCursor->y;
                    f32 bound = pointBounds[1];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    pointBounds[1] = value;
                }

                {
                    f32 value = pointCursor->z;
                    f32 bound = pointBounds[2];
                    if (!(value <= bound)) {
                        value = bound;
                    }
                    pointBounds[2] = value;
                }

                {
                    f32 value = pointCursor->x;
                    f32 bound = pointBounds[3];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    pointBounds[3] = value;
                }

                {
                    f32 value = pointCursor->y;
                    f32 bound = pointBounds[4];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    pointBounds[4] = value;
                }

                {
                    f32 value = pointCursor->z;
                    f32 bound = pointBounds[5];
                    if (!(bound <= value)) {
                        value = bound;
                    }
                    pointBounds[5] = value;
                }

                i += 1;
                pointCursor += 1;
            if (i < pointCount) goto bounds_loop;
        }
    }
}

/* 8027451C_4.CPP */

/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E20 for the last node seen, with a default up vector for a null node.
   Adapted from Graphu64_GetCachedSurfaceNormal with the edge vectors computed through the GraphU64_SubtractVectors subtract helper, the cross product arguments in forward order, and the cache globals changed. */

static inline CVector3 *cross_edges(CVector3 *out, Node75 *node) {
    CVector3 a;
    CVector3 b;

    if (node == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C49F8_de;
    } else if ((Triangle *)node != D_800CD3E8) {
        GraphU64_SubtractVectors(&a, node->cur, node->prev);
        GraphU64_SubtractVectors(&b, node->next, node->cur);
        Graphu64_CrossVectors(&D_80115E10, &a, &b);
    }
    D_800CD3E8 = (Triangle *)node;
    *out = D_80115E10;
    return out;
}

void Region_ScaleWordsToFloats(void *wordStorage) {
    s32 *ip = (s32 *)wordStorage;
    f32 *fp = (f32 *)wordStorage;
    f32 scale = D_800C49EC_de;
    fp[0] = (f32)ip[0] * scale;
    fp[1] = (f32)ip[1] * scale;
    fp[2] = (f32)ip[2] * scale;
    fp[3] = (f32)ip[3] * scale;
}

/* Decodes a packed header into its runtime form: copies the two leading shorts and the word at 0x10,
   and for each of three channels resolves a 16-byte-scaled offset against base and a 32-byte-scaled
   offset against extra, leaving the latter null when it is 0xFFFF. */

void Region_DecodePackedRegion(CGameRegion *dst, Packed *src, char *base, int unused, char *extra) {
    int i;

    dst->unk0 = src->unk0;
    dst->unk2 = src->unk2;
    dst->unk1C = src->unk10;
    for (i = 0; i < 3; i++) {
        dst->first[i] = base + src->first[i] * 16;
        if (src->second[i] == 0xFFFF) {
            dst->second[i] = 0;
        } else {
            dst->second[i] = extra + src->second[i] * 32;
        }
    }
}

s32 Region_IsPointInTriangleXZ(Node75 *triangle, f32 x, f32 z) {
    s32 i;
    CVector3 *vertexA;
    CVector3 *vertexB;

    if (triangle == 0) {
        return 1;
    }

    for (i = 0; i < 3; i++) {
        vertexA = ((Triangle *)triangle)->vertices[i];
        vertexB = ((Triangle *)triangle)->vertices[(i + 1) % 3];
        if (((vertexB->z -
              vertexA->z) *
             (x - vertexA->x)) +
                ((vertexA->x - vertexB->x) *
                 (z - vertexA->z)) <
            0.0f) {
            return 0;
        }
    }

    return 1;
}

CVector3 *Region_GetNodeEdgeCross(CVector3 *out, Node75 *node) {
    CVector3 a;
    CVector3 b;
    CVector3 *b_ptr;

    if (node == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C49F0_de;
    } else if ((Triangle *)node != D_800CD3E8) {
        GraphU64_SubtractVectors(&a, node->cur, node->prev);
        b_ptr = &b;
        GraphU64_SubtractVectors(b_ptr, node->next, node->cur);
        Graphu64_CrossVectors(&D_80115E10, &a, b_ptr);
    }
    *out = D_80115E10;
    D_800CD3E8 = (Triangle *)node;
    return out;
}

CVector3 *Region_GetNodeNormal(CVector3 *out, Node75 *node) {
    if (node == 0) {
        D_80115E20.x = 0;
        D_80115E20.z = 0;
        D_80115E20.y = D_800C49F4_de;
    } else if ((Triangle *)node != D_800CD3EC) {
        cross_edges(&D_80115E20, node);
        GraphU64_NormalizeVec3(&D_80115E20);
    }
    *out = D_80115E20;
    D_800CD3EC = (Triangle *)node;
    return out;
}

/* 80275E44.CPP */
/* Returns the height of a path node's triangle plane at (x, z) from the cached edge cross product in D_80115E10, or the mean vertex height when the plane is vertical.
   Adapted from func_8027525C_de with the edge vectors computed through the GraphU64_SubtractVectors subtract helper inside a static inline helper, the vertex read as a whole vector with y at offset 4, the null result a rodata constant, and the cache globals changed. */

static inline void cross_node_edges(Node75 *node) {
    CVector3 a;
    CVector3 b;

    GraphU64_SubtractVectors(&a, node->cur, node->prev);
    GraphU64_SubtractVectors(&b, node->next, node->cur);
    Graphu64_CrossVectors(&D_80115E10, &a, &b);
}

extern void *Scene_GetModelRecordByIndexPointer(Shared_World *arg0, s32 arg1);

extern void Gregion_ExpandHorizontalBounds(void *arg0, s32 arg1, void *arg2);

f32 Region_GetPolygonHeight(Node75 *node, f32 x, f32 z) {
    CVector3 normal;
    CVector3 point;

    if (node == 0) {
        return D_800C49FC_de;
    }
    if ((Triangle *)node != D_800CD3E8) {
        cross_node_edges(node);
    }
    normal = D_80115E10;
    D_800CD3E8 = (Triangle *)node;
    if (normal.y == 0.0f) {
        return (node->prev->y + node->cur->y + node->next->y) * D_800C4A00_de;
    }
    point = *node->prev;
    return (((point.z - z) * normal.z) +
            ((point.x - x) * normal.x) + (point.y * normal.y)) /
           normal.y;
}

CVector3 *Region_GetCachedCeilingNormal(CVector3 *out, Node75 *node) {
    CVector3 a;
    CVector3 b;
    CollisionBuildVertex *p;
    CollisionBuildVertex *q;

    if (node == 0) {
        D_80111D30.x = 0;
        D_80111D30.z = 0;
        D_80111D30.y = D_800C4A04_de;
    } else if ((int)node != D_800CD3E0) {
        p = node->cur;
        q = node->prev;
        a.x = p->x - q->x;
        p = node->cur;
        q = node->prev;
        a.y = p->ceiling - q->ceiling;
        p = node->cur;
        q = node->prev;
        a.z = p->z - q->z;
        p = node->next;
        q = node->cur;
        b.x = p->x - q->x;
        p = node->next;
        q = node->cur;
        b.y = p->ceiling - q->ceiling;
        p = node->next;
        q = node->cur;
        b.z = p->z - q->z;
        Graphu64_CrossVectors(&D_80111D30, &b, &a);
    }
    *out = D_80111D30;
    D_800CD3E0 = (int)node;
    return out;
}

u8 Region_GetModelBlendByte58(s32 modelId) {
    ModelBlend *blend = Scene_GetModelRecordByIndexPointer(&g_world, modelId);
    if (blend == 0) {
        return 0;
    }
    return blend->byte58;
}

u8 Region_GetModelBlendByte59(s32 modelId) {
    ModelBlend *blend = Scene_GetModelRecordByIndexPointer(&g_world, modelId);
    if (blend == 0) {
        return 0;
    }
    return blend->byte59;
}

f32 Region_GetTriangleEdgeAngle(void *triangle, s32 edgeIndex) {
    Triangle *polygon = triangle;
    CVector3 *v0;
    CVector3 *v1;
    f32 dx, dz;
    f32 mag;
    f32 result;

    v1 = polygon->vertices[edgeIndex];
    v0 = polygon->vertices[(edgeIndex + 1) % 3];
    dx = v0->x - v1->x;
    dz = v0->z - v1->z;
    mag = Gu_Sqrtf((dx * dx) + (dz * dz));
    if (mag == 0.0f) {
        return 0.0f;
    }
    result = Graphu64_ArcCos(dx / mag);
    if (!(dz < 0.0f)) {
        result = -result;
    }
    return result;
}

void Region_SetNodeGroupFlag(void *modelTreeNode) {
    struct ModelTreeNode *node = modelTreeNode;
    if ((modelTreeNode != 0) && (node->flags & 2)) {
        Region_MarkMatchingNodes(modelTreeNode, node->modelId);
    }
}

void Region_ClearNodeGroupFlag(void *modelTreeNode) {
    struct ModelTreeNode *node = modelTreeNode;
    if ((modelTreeNode != 0) && (node->flags & 2)) {
        Region_UnmarkMatchingNodes(modelTreeNode, node->modelId);
    }
}

f32 Region_SetNodeGroupHeight(u16 *arg0, f32 arg1) {
    f32 result = arg1;
    if (arg0 != 0) {
        result = Region_SetMatchingVertexHeights(arg0, arg1, *arg0);
    }
    return result;
}

void Region_MarkMatchingNodes(struct ModelTreeNode *modelTreeNode, u16 arg1) {
    u16 modelId;
    u16 flags;
    void *temp_a0;

    modelId = modelTreeNode->modelId;
    if (modelId == arg1) {
        flags = modelTreeNode->flags;
        if (!(flags & 4)) {
            temp_a0 = modelTreeNode->branches[0];
            modelTreeNode->flags = flags | 4;
            if (temp_a0 != 0) {
                Region_MarkMatchingNodes(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[1];
            if (temp_a0 != 0) {
                Region_MarkMatchingNodes(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[2];
            if (temp_a0 != 0) {
                Region_MarkMatchingNodes(temp_a0, modelId);
            }
        }
    }
}

void Region_UnmarkMatchingNodes(struct ModelTreeNode *modelTreeNode, u16 arg1) {
    u16 modelId;
    u16 flags;
    void *temp_a0;

    modelId = modelTreeNode->modelId;
    if (modelId == arg1) {
        flags = modelTreeNode->flags;
        if (flags & 4) {
            temp_a0 = modelTreeNode->branches[0];
            modelTreeNode->flags = flags & 0xFFFB;
            if (temp_a0 != 0) {
                Region_UnmarkMatchingNodes(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[1];
            if (temp_a0 != 0) {
                Region_UnmarkMatchingNodes(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[2];
            if (temp_a0 != 0) {
                Region_UnmarkMatchingNodes(temp_a0, modelId);
            }
        }
    }
}

f32 Region_SetMatchingVertexHeights(u16 *arg0, f32 arg1, u16 arg2) {
    u16 *node = arg0;
    u16 id = arg2;

    if (*node == id) {
        if (((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_4)->unk4 != arg1 ||
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_8)->unk4 != arg1 ||
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_C)->unk4 != arg1) {
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_4)->unk4 = arg1;
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_8)->unk4 = arg1;
            ((struct func_802077F4_S2 *) ((ObjectLinks1C *) node)->unk_C)->unk4 = arg1;

            if (((ObjectLinks1C *)(node))->unk_10.v0 != 0) {
                Region_SetMatchingVertexHeights(((ObjectLinks1C *)(node))->unk_10.v1, arg1, id);
            }
            if (((ObjectLinks1C *)(node))->unk_14.v0 != 0) {
                Region_SetMatchingVertexHeights(((ObjectLinks1C *)(node))->unk_14.v1, arg1, id);
            }
            if (((ObjectLinks1C *)(node))->unk_18.v0 != 0) {
                Region_SetMatchingVertexHeights(((ObjectLinks1C *)(node))->unk_18.v1, arg1, id);
            }
        }
    }
}

void Region_ExpandPointBounds(f32 *arg0, s32 arg1, CVector3 *arg2)
{
    s32 i;
    i = 0;
    if (arg1 > 0) {
        do {
            {
                f32 value = arg2[i].x;
                f32 bound = arg0[0];
                if (!(value <= bound)) {
                    value = bound;
                }
                arg0[0] = value;
            }
            {
                f32 value = arg2[i].y;
                f32 bound = arg0[1];
                if (!(value <= bound)) {
                    value = bound;
                }
                arg0[1] = value;
            }
            {
                f32 value = arg2[i].z;
                f32 bound = arg0[2];
                if (!(value <= bound)) {
                    value = bound;
                }
                arg0[2] = value;
            }
            {
                f32 value = arg2[i].x;
                f32 bound = arg0[3];
                if (!(bound <= value)) {
                    value = bound;
                }
                arg0[3] = value;
            }
            {
                f32 value = arg2[i].y;
                f32 bound = arg0[4];
                if (!(bound <= value)) {
                    value = bound;
                }
                arg0[4] = value;
            }
            {
                f32 value = arg2[i].z;
                f32 bound = arg0[5];
                if (!(bound <= value)) {
                    value = bound;
                }
                arg0[5] = value;
            }
            i += 1;
        } while (i < arg1);
    }
}

void Region_ComputeHorizontalBounds(void *arg0, s32 arg1, void *arg2) {
    f32 *bounds = arg0;
    CVector3 *points = arg2;
    f32 temp_f0;
    f32 temp_f0_2;

    if (arg1 != 0) {
        temp_f0 = points->x;
        bounds[2] = temp_f0;
        bounds[0] = temp_f0;
        temp_f0_2 = points->z;
        bounds[3] = temp_f0_2;
        bounds[1] = temp_f0_2;
        Gregion_ExpandHorizontalBounds(arg0, arg1 - 1, points + 1);
    }
}

/* 800C9ACC.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80275688_CA6CC[2] = {
    0x3F800000, 0x3F000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80275688_CA6CC_us_rev1.c */
const unsigned int D_blob_6ed6742ca7aeefaa44c7[2] = {
    0x3F800000, 0x3F000000,
};
#endif

/* 800C9AD4.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_802757E4_CA6D4[2] = {
    0x3F800000, 0x3F000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802757E4_CA6D4_us_rev1.c */
const unsigned int D_blob_704ee15b1ec28a1ee6e6[2] = {
    0x3F800000, 0x3F000000,
};
#endif

/* 800C9ADC.CPP */
/* ROM-grounded data: src/rw_pool_80275A58_CA6DC_us_rev1.c */
const unsigned int D_blob_1dd2bb61dda88f70e062[1] = {
    0x3CF00000,
};

/* 800C9AE0.CPP */
/* ROM-grounded data: src/rw_pool_80275BC8_CA6E0_us_rev1.c */
const unsigned int D_blob_2007bd9d947de3a8f876[1] = {
    0x3F800000,
};

/* 800C9AE4.CPP */
/* ROM-grounded data: src/rw_pool_80275C94_CA6E4_us_rev1.c */
const unsigned int D_blob_39bb6df7b4af97a3ff93[2] = {
    0x3F800000, 0x3F800000,
};

/* 800C9AEC.CPP */
/* ROM-grounded data: src/rw_pool_80275DD4_CA6EC_us_rev1.c */
const unsigned int D_blob_be6f94624239bf08ad99[2] = {
    0xC6600000, 0x3EAAAAAB,
};

/* 800C9AF4.CPP */
/* ROM-grounded data: src/rw_pool_80275F28_CA6F4_us_rev1.c */
const unsigned int D_blob_dd17c7991d2f6b062f5a[1] = {
    0xBF800000,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C4938[2] = {
    0x00000800, 0x08001400,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C4CF8[2] = {
    0xB58637BD, 0x358637BD,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4CB8[2] = {
    0x00000000, 0x46022082,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C4A08[2] = {
    0x3C40C0C1, 0x4F000000,
};
#endif
