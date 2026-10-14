#include "span_16E000/code_8044ACCC.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80275E44.h"



extern int D_80111D30;
extern int D_800CD3E0;
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);






Vec3 *func_80275F28_de(Vec3 *out, Node75_func_802750B0_de *node) {
    Vec3 a;
    Vec3 b;
    CollisionBuildVertex *p;
    CollisionBuildVertex *q;

    if (node == 0) {
        ((Vec3 *)&D_80111D30)->x = 0;
        ((Vec3 *)&D_80111D30)->z = 0;
        ((Vec3 *)&D_80111D30)->y = D_800C4A04_de;
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
        func_80272018_de((Vec3 *)&D_80111D30, &b, &a);
    }
    *out = *(Vec3 *)&D_80111D30;
    D_800CD3E0 = (int)node;
    return out;
}
