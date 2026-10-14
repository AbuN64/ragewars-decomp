#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8027451C.h"
#include "span_16E000/code_8044ACCC.h"
#include "types.h"






extern int D_800CD3E0;
extern int D_80111D30;
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);












f32 func_8027525C_de(Node75 *node, f32 x, f32 z) {
    Vec3 normal;
    Vec3 point;
    Vec3 a;
    Vec3 b;
    char *p;
    char *q;

    if (node == 0) {
        return 0.0f;
    }
    if ((int)node != D_800CD3E0) {
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
    normal = *(Vec3 *)&D_80111D30;
    D_800CD3E0 = (int)node;
    if (normal.y == 0.0f) {
        return (((CollisionBuildVertex *)node->prev)->ceiling +
                ((CollisionBuildVertex *)node->cur)->ceiling +
                ((CollisionBuildVertex *)node->next)->ceiling) * D_800C49C8_de;
    }
    p = node->prev;
    point.x = ((CollisionBuildVertex *)p)->x;
    p = node->prev;
    point.y = ((CollisionBuildVertex *)p)->ceiling;
    p = node->prev;
    point.z = ((CollisionBuildVertex *)p)->z;
    return (((point.z - z) * normal.z) +
            ((point.x - x) * normal.x) + (point.y * normal.y)) /
           normal.y;
}
