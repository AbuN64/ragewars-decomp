#include "COMMON/PACKED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"

extern f32 D_800C49F0_de;

extern s32 D_800CD3E8;

extern void Particle_CrossVectors(CVector3 *, CVector3 *, CVector3 *);

/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E20 for the last node seen, with a default up vector for a null node.
   Adapted from func_802750B0_de with the edge vectors computed through the Particle_SubtractVectors subtract helper, the cross product arguments in forward order, and the cache globals changed. */



extern float D_800C49F4_de;

extern float D_800C49F8_de;


extern int D_800CD3E8;

extern int D_800CD3EC;
extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);


static inline CVector3 *cross_edges(CVector3 *out, Node75 *node) {
    CVector3 a;
    CVector3 b;

    if (node == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C49F8_de;
    } else if ((int)node != D_800CD3E8) {
        Particle_SubtractVectors(&a, node->cur, node->prev);
        Particle_SubtractVectors(&b, node->next, node->cur);
        Particle_CrossVectors(&D_80115E10, &a, &b);
    }
    D_800CD3E8 = (int)node;
    *out = D_80115E10;
    return out;
}

void Nav_ScaleWordsToFloats(void *arg0) {
    s32 *ip = (s32 *)arg0;
    f32 *fp = (f32 *)arg0;
    f32 scale = D_800C49EC_de;
    fp[0] = (f32)ip[0] * scale;
    fp[1] = (f32)ip[1] * scale;
    fp[2] = (f32)ip[2] * scale;
    fp[3] = (f32)ip[3] * scale;
}

/* Decodes a packed header into its runtime form: copies the two leading shorts and the word at 0x10,
   and for each of three channels resolves a 16-byte-scaled offset against base and a 32-byte-scaled
   offset against extra, leaving the latter null when it is 0xFFFF. */




void Nav_DecodePackedRegion(CGameRegion *dst, Packed *src, char *base, int unused, char *extra) {
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

s32 Nav_IsPointInTriangleXZ(Node75 *triangle, f32 x, f32 z) {
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

CVector3 *func_80275BC8_de(CVector3 *out, Node75 *node) {
    CVector3 a;
    CVector3 b;
    CVector3 *b_ptr;

    if (node == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C49F0_de;
    } else if ((s32)node != D_800CD3E8) {
        Particle_SubtractVectors(&a, node->cur, node->prev);
        b_ptr = &b;
        Particle_SubtractVectors(b_ptr, node->next, node->cur);
        Particle_CrossVectors(&D_80115E10, &a, b_ptr);
    }
    *out = D_80115E10;
    D_800CD3E8 = (s32)node;
    return out;
}

CVector3 *func_80275C94_de(CVector3 *out, Node75 *node) {
    if (node == 0) {
        D_80115E20.x = 0;
        D_80115E20.z = 0;
        D_80115E20.y = D_800C49F4_de;
    } else if ((int)node != D_800CD3EC) {
        cross_edges(&D_80115E20, node);
        Particle_NormalizeVec3(&D_80115E20);
    }
    *out = D_80115E20;
    D_800CD3EC = (int)node;
    return out;
}
