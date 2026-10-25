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
   Adapted from func_8027525C_de with the edge vectors computed through the Particle_SubtractVectors subtract helper inside a static inline helper, the vertex read as a whole vector with y at offset 4, the null result a rodata constant, and the cache globals changed. */







extern int D_800CD3E8;


extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

extern void Particle_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

static inline void cross_edges(Node75 *node) {
    CVector3 a;
    CVector3 b;

    Particle_SubtractVectors(&a, node->cur, node->prev);
    Particle_SubtractVectors(&b, node->next, node->cur);
    Particle_CrossVectors(&D_80115E10, &a, &b);
}



extern void *func_8028B2F8_de(Shared_World *arg0, s32 arg1);

extern f32 Math_Sqrtf(f32);


extern void func_80276510_de(void *arg0, s32 arg1, void *arg2);

f32 Anim_GetPolygonHeight(Node75 *node, f32 x, f32 z) {
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

CVector3 *func_80275F28_de(CVector3 *out, Node75 *node) {
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
        Particle_CrossVectors(&D_80111D30, &b, &a);
    }
    *out = D_80111D30;
    D_800CD3E0 = (int)node;
    return out;
}

u8 func_80276054_de(s32 modelId) {
    ModelBlend *blend = func_8028B2F8_de(&g_world, modelId);
    if (blend == 0) {
        return 0;
    }
    return blend->byte58;
}

u8 func_80276088_de(s32 modelId) {
    ModelBlend *blend = func_8028B2F8_de(&g_world, modelId);
    if (blend == 0) {
        return 0;
    }
    return blend->byte59;
}

f32 func_802760BC_de(void *triangle, s32 arg1) {
    Triangle *polygon = triangle;
    CVector3 *v0;
    CVector3 *v1;
    f32 dx, dz;
    f32 mag;
    f32 result;

    v1 = polygon->vertices[arg1];
    v0 = polygon->vertices[(arg1 + 1) % 3];
    dx = v0->x - v1->x;
    dz = v0->z - v1->z;
    mag = Math_Sqrtf((dx * dx) + (dz * dz));
    if (mag == 0.0f) {
        return 0.0f;
    }
    result = Nav_ArcCos(dx / mag);
    if (!(dz < 0.0f)) {
        result = -result;
    }
    return result;
}

void func_80276184_de(void *modelTreeNode) {
    struct ModelTreeNode *node = modelTreeNode;
    if ((modelTreeNode != 0) && (node->flags & 2)) {
        func_80276214_de(modelTreeNode, node->modelId);
    }
}

void func_802761B8_de(void *modelTreeNode) {
    struct ModelTreeNode *node = modelTreeNode;
    if ((modelTreeNode != 0) && (node->flags & 2)) {
        func_80276298_de(modelTreeNode, node->modelId);
    }
}

f32 func_802761EC_de(u16 *arg0, f32 arg1) {
    f32 result = arg1;
    if (arg0 != 0) {
        result = func_8027631C_de(arg0, arg1, *arg0);
    }
    return result;
}

void func_80276214_de(struct ModelTreeNode *modelTreeNode, u16 arg1) {
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
                func_80276214_de(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[1];
            if (temp_a0 != 0) {
                func_80276214_de(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[2];
            if (temp_a0 != 0) {
                func_80276214_de(temp_a0, modelId);
            }
        }
    }
}

void func_80276298_de(struct ModelTreeNode *modelTreeNode, u16 arg1) {
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
                func_80276298_de(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[1];
            if (temp_a0 != 0) {
                func_80276298_de(temp_a0, modelId);
            }
            temp_a0 = modelTreeNode->branches[2];
            if (temp_a0 != 0) {
                func_80276298_de(temp_a0, modelId);
            }
        }
    }
}

f32 func_8027631C_de(u16 *arg0, f32 arg1, u16 arg2) {
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
                func_8027631C_de(((ObjectLinks1C *)(node))->unk_10.v1, arg1, id);
            }
            if (((ObjectLinks1C *)(node))->unk_14.v0 != 0) {
                func_8027631C_de(((ObjectLinks1C *)(node))->unk_14.v1, arg1, id);
            }
            if (((ObjectLinks1C *)(node))->unk_18.v0 != 0) {
                func_8027631C_de(((ObjectLinks1C *)(node))->unk_18.v1, arg1, id);
            }
        }
    }
}

void func_8027640C_de(f32 *arg0, s32 arg1, CVector3 *arg2)
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

void func_802764D4_de(void *arg0, s32 arg1, void *arg2) {
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
        func_80276510_de(arg0, arg1 - 1, points + 1);
    }
}
