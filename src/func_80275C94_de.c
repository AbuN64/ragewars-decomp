#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
/* Returns the normalised cross product of a path node's two edge vectors, cached in D_80115E20 for the last node seen, with a default up vector for a null node.
   Adapted from func_802750B0_de with the edge vectors computed through the func_80271F68_de subtract helper, the cross product arguments in forward order, and the cache globals changed. */



extern float D_800C49F4_de;
extern float D_800C49F8_de;
extern int D_80115E10;
extern int D_80115E20;
extern int D_800CD3E8;
extern int D_800CD3EC;
extern void func_80271F68_de(Vec3 *, void *, void *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_8027207C_de(Vec3 *);

static inline Vec3 *cross_edges(Vec3 *out, Node75_func_802750B0_de *node) {
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

Vec3 *func_80275C94_de(Vec3 *out, Node75_func_802750B0_de *node) {
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
