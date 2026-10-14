#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "span_16E000/code_8044ACCC.h"



/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E00 for the last node seen, with a default up vector for a null node. Adapted from func_80275F28_de, which it inlines to compute the raw cross product, with the result normalised through func_8027207C_de and cached by a second last-node word; the inlined copy records its last node before copying its result. */


extern int D_80111D30;
extern int D_80115E00;
extern int D_800CD3E0;
extern int D_800CD3E4;
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);






static inline Vec3 *cross_edges(Vec3 *out, Node75 *node) {
    Vec3 a;
    Vec3 b;
    char *p;
    char *q;

    if (node == 0) {
        ((Vec3 *)&D_80111D30)->x = 0;
        ((Vec3 *)&D_80111D30)->z = 0;
        ((Vec3 *)&D_80111D30)->y = D_800C49C4_de;
    } else if ((int)node != D_800CD3E0) {
        p = node->cur;
        q = node->prev;
        a.x = ((CollisionBuildVertex *)p)->x - ((CollisionBuildVertex *)q)->x;
        p = node->cur;
        q = node->prev;
        a.y = ((CollisionBuildVertex *)p)->ceiling - ((CollisionBuildVertex *)q)->ceiling;
        p = node->cur;
        q = node->prev;
        a.z = ((CollisionBuildVertex *)p)->z - ((CollisionBuildVertex *)q)->z;
        p = node->next;
        q = node->cur;
        b.x = ((CollisionBuildVertex *)p)->x - ((CollisionBuildVertex *)q)->x;
        p = node->next;
        q = node->cur;
        b.y = ((CollisionBuildVertex *)p)->ceiling - ((CollisionBuildVertex *)q)->ceiling;
        p = node->next;
        q = node->cur;
        b.z = ((CollisionBuildVertex *)p)->z - ((CollisionBuildVertex *)q)->z;
        func_80272018_de((Vec3 *)&D_80111D30, &b, &a);
    }
    D_800CD3E0 = (int)node;
    *out = *(Vec3 *)&D_80111D30;
    return out;
}

Vec3 *func_802750B0_de(Vec3 *out, Node75 *node) {
    if (node == 0) {
        ((Vec3 *)&D_80115E00)->x = 0;
        ((Vec3 *)&D_80115E00)->z = 0;
        ((Vec3 *)&D_80115E00)->y = D_800C49C0_de;
    } else if ((int)node != D_800CD3E4) {
        cross_edges((Vec3 *)&D_80115E00, node);
        func_8027207C_de((Vec3 *)&D_80115E00);
    }
    *out = *(Vec3 *)&D_80115E00;
    D_800CD3E4 = (int)node;
    return out;
}
