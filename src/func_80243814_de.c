#include "shared/motion_step.h"
#include "shared/gameplay_movement.h"
#include "span_16E000/code_8044ACCC.h"
#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802412C0.h"
#include "types.h"

/** Swap two pairs of words. */
void func_80243814_de(Hit8 *arg0, Hit8 *arg1) {
    Hit8 temporary = *arg0;
    *arg0 = *arg1;
    *arg1 = temporary;
}

s32 func_80243850_de(void *arg0, void *arg1) {
    s32 var_v0;
    var_v0 = 1;
    if ((((Hit8 *)arg0)->t) < (((Hit8 *)arg1)->t)) {
        var_v0 = -1;
    }
    return var_v0;
}

extern void func_8026F620_de(void *, void *, void *);
extern char *func_8028FDB4_de(s32 *, s32);
extern void func_80242FE8_de(void *arg0, void *arg1);






void func_80243874_de(void *arg0) {
    void *temp_a1;
    void **temp_s0;
    void *temp_s0_2;
    s32 *temp_v0;
    s32 temp_s1;
    s32 var_s0;

    temp_a1 = ((ContextB0 *)arg0)->element;
    temp_s0 = ((ElementE8 *)temp_a1)->resource;
    if (temp_s0 != 0) {
        func_8026F620_de(&((ContextB0 *)arg0)->transform, &((ElementE8 *)temp_a1)->transform, (char *) arg0 + 0xC);
        temp_s0_2 = *temp_s0;
        ((ContextB0 *)arg0)->vertices = func_8028FDB4_de(temp_s0_2, 0);
        temp_v0 = func_8028FDB4_de(temp_s0_2, 2);
        temp_s1 = *temp_v0;
        var_s0 = 0;
        if (temp_s1 > 0) {
            do {
                func_80242FE8_de(arg0, func_8028FDB4_de((void *) temp_v0, var_s0));
                var_s0 += 1;
            } while (var_s0 < temp_s1);
        }
    }
}


extern void *func_8028B2F8_de(void *, u16 *);
extern void func_80240CAC_de(QueryE0 *arg0);
extern s32 func_8023E8D4_de(ActorB0 *, QueryE0 *, s32);








void func_80243920_de(ActorB0 *actor) {
    QueryE0 query;
    u8 *data;
    s32 *flags;
    void *resource;
    s32 i;
    f32 height;

    data = actor->data;
    flags = actor->flags;
    if (data != 0) {
        resource = func_8028B2F8_de(&D_8011FE88, (u16 *)data);
        if (resource != 0) {
          if ((*flags & 8) != 0) {
           if ((*flags & 0x100000) == 0) {
            query.word14 = 3;
            for (i = 0; i < 3; i++) {
                query.vectors[2 - i].x = ((CollisionBuildTriangle *)data)->fields.v[i]->x;
                query.vectors[2 - i].y = ((CollisionBuildTriangle *)data)->fields.v[i]->ceiling +
                                         actor->height;
                query.vectors[2 - i].z = ((CollisionBuildTriangle *)data)->fields.v[i]->z;
            }
            func_80240CAC_de(&query);
            height = query.result.y;
            if ((0.10000000149011612f) < height) {
                query.word0 = 5;
                query.word4 = ((MotionSurface *)flags)->materialResponse;
                query.word8 = ((MotionSurface *)flags)->materialKind;
                query.input = 0;
                query.index = -1;
                query.word10 = 0;
                if ((((Shared_Surface *)resource)->flags & 0x400000) != 0) {
                    query.wordC = 7;
                } else if ((((Shared_Surface *)resource)->flags52 & 0x80) != 0) {
                    query.wordC = 8;
                } else {
                    query.wordC = 1;
                }
                func_8023E8D4_de(actor, &query, 1);
            }
           }
          }
        }
    }
}
