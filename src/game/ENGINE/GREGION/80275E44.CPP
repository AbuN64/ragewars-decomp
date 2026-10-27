#include "COMMON/OBJECTLINKS4_2.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/PACKED.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

/* Returns the height of a path node's triangle plane at (x, z) from the cached edge cross product in D_80115E10, or the mean vertex height when the plane is vertical.
   Adapted from func_8027525C_de with the edge vectors computed through the GraphU64_SubtractVectors subtract helper inside a static inline helper, the vertex read as a whole vector with y at offset 4, the null result a rodata constant, and the cache globals changed. */







extern int D_800CD3E8;


extern void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

extern void GraphU64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

static inline void cross_edges(Node75 *node) {
    CVector3 a;
    CVector3 b;

    GraphU64_SubtractVectors(&a, node->cur, node->prev);
    GraphU64_SubtractVectors(&b, node->next, node->cur);
    GraphU64_CrossVectors(&D_80115E10, &a, &b);
}



extern void *Scene_GetModelRecordByIndexPointer(Shared_World *arg0, s32 arg1);

extern f32 Math_Sqrtf(f32);


extern void Region_ExpandHorizontalBounds(void *arg0, s32 arg1, void *arg2);

f32 Region_GetPolygonHeight(Node75 *node, f32 x, f32 z) {
    CVector3 normal;
    CVector3 point;

    if (node == 0) {
        return D_800C49FC_de;
    }
    if ((int)node != D_800CD3E8) {
        cross_edges(node);
    }
    normal = D_80115E10;
    D_800CD3E8 = (int)node;
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
        GraphU64_CrossVectors(&D_80111D30, &b, &a);
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
    mag = Math_Sqrtf((dx * dx) + (dz * dz));
    if (mag == 0.0f) {
        return 0.0f;
    }
    result = GraphU64_ArcCos(dx / mag);
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
        Region_ExpandHorizontalBounds(arg0, arg1 - 1, points + 1);
    }
}
