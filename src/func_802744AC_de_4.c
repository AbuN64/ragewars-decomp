#include "span_1000/code_8027451C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "types.h"

extern f32 D_800C49F0_de;

extern s32 D_800CD3E8;

extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);

/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E20 for the last node seen, with a default up vector for a null node.
   Adapted from func_802750B0_de with the edge vectors computed through the func_80271F68_de subtract helper, the cross product arguments in forward order, and the cache globals changed. */



extern float D_800C49F4_de;

extern float D_800C49F8_de;

extern int D_80115E20;

extern int D_800CD3E8;

extern int D_800CD3EC;

extern void func_8027207C_de(Vec3 *);

static inline Vec3 *cross_edges(Vec3 *out, Node75 *node) {
    extern void func_80271F68_de(Vec3 *, void *, void *);
    extern int D_80115E10;
    Vec3 a;
    Vec3 b;

    if (node == 0) {
        ((Vec3 *)&D_80115E10)->x = 0;
        ((Vec3 *)&D_80115E10)->z = 0;
        ((Vec3 *)&D_80115E10)->y = D_800C49F8_de;
    } else if ((int)node != D_800CD3E8) {
        func_80271F68_de(&a, node->cur, node->prev);
        func_80271F68_de(&b, node->next, node->cur);
        func_80272018_de((Vec3 *)&D_80115E10, &a, &b);
    }
    D_800CD3E8 = (int)node;
    *out = *(Vec3 *)&D_80115E10;
    return out;
}

void func_80275A58_de(void *arg0) {
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




void func_80275AA4_de(HeaderRecAt1C *dst, Packed *src, char *base, int unused, char *extra) {
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

s32 func_80275B10_de(void **arg0, f32 arg1, f32 arg2) {
    s32 i;
    Vec3 *point1;
    Vec3 *point2;

    if (arg0 == 0) {
        return 1;
    }

    for (i = 0; i < 3; i++) {
        point1 = ((Triangle *)arg0)->vertices[i];
        point2 = ((Triangle *)arg0)->vertices[(i + 1) % 3];
        if (((point2->z -
              point1->z) *
             (arg1 - point1->x)) +
                ((point1->x - point2->x) *
                 (arg2 - point1->z)) <
            0.0f) {
            return 0;
        }
    }

    return 1;
}

Vec3 *func_80275BC8_de(Vec3 *out, Node75 *node) {
    extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
    extern Vec3 D_80115E10;
    Vec3 a;
    Vec3 b;
    Vec3 *b_ptr;

    if (node == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C49F0_de;
    } else if ((s32)node != D_800CD3E8) {
        func_80271F68_de(&a, node->cur, node->prev);
        b_ptr = &b;
        func_80271F68_de(b_ptr, node->next, node->cur);
        func_80272018_de(&D_80115E10, &a, b_ptr);
    }
    *out = D_80115E10;
    D_800CD3E8 = (s32)node;
    return out;
}

Vec3 *func_80275C94_de(Vec3 *out, Node75 *node) {
    if (node == 0) {
        ((Vec3 *)&D_80115E20)->x = 0;
        ((Vec3 *)&D_80115E20)->z = 0;
        ((Vec3 *)&D_80115E20)->y = D_800C49F4_de;
    } else if ((int)node != D_800CD3EC) {
        cross_edges((Vec3 *)&D_80115E20, node);
        func_8027207C_de((Vec3 *)&D_80115E20);
    }
    *out = *(Vec3 *)&D_80115E20;
    D_800CD3EC = (int)node;
    return out;
}
