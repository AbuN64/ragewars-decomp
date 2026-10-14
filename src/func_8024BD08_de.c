#include "shared/legacy_collision_actor.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"







extern Vec3 *func_80275BC8_de(Vec3 *out, Node75 *node);




s32 func_8024BD08_de(Shared_Func80243A80Actor *arg0) {
    Vec3 direction;
    Node75 *node;
    f32 upper;
    f32 upperNext;
    f32 lower;
    f32 lowerNext;
    f32 sine;
    f32 cosine;

    node = (void *)arg0->collision;
    if (node != 0) {
        upper = node->cur->y;
        if (node->prev->y <= upper) {
        } else {
            upper = node->prev->y;
        }
        upperNext = node->next->y;
        if (upper <= upperNext) {
        } else {
            upperNext = upper;
        }
        lower = node->cur->y;
        if (lower <= node->prev->y) {
        } else {
            lower = node->prev->y;
        }
        lowerNext = node->next->y;
        if (lowerNext <= lower) {
        } else {
            lowerNext = lower;
        }
        if (upperNext < arg0->y) {
            return 0;
        }
        if (arg0->y < lowerNext) {
            return 0;
        }
        sine = func_802B7130_de(arg0->angle);
        cosine = func_802B6560_de(arg0->angle);
        func_80275BC8_de(&direction, node);
        if (direction.x * -sine + direction.z * -cosine < 0.0f) {
            return 1;
        }
    }
    return 0;
}
