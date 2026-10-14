#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80245980.h"
#include "types.h"
/* Returns the collisions an object would meet moving to a position, without committing the move: picks the collision set for the object
 * (D_801040D0 for flagged players; otherwise by func_8024DF5C_de and then func_8024DFA0_de or func_8024DEE0_de among
 * D_80103FF0, D_80104070, D_80104050 and D_801040D0), reports it through the optional out pointer, runs
 * the collision mover func_80243A90_de and restores the object's 0x50-byte header. Adapted from
 * func_8024643C_de. */





extern char D_80103FF0;
extern char D_80104050;
extern char D_80104070;
extern char D_801040D0;
extern s32 func_8024DEE0_de(Instance8020CD74 *);
extern s32 func_8024DF5C_de(Instance8020CD74 *);
extern s32 func_8024DFA0_de(Instance8020CD74 *);
extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, char *);




s32 func_802462E8_de(Instance8020CD74 *arg0, Vec3 position, char **out) {
    Instance8020CD74 saved;
    char *set;
    s32 grounded;
    s32 collisions;
    struct Actor_func_80214DD4_de *actor = (struct Actor_func_80214DD4_de *)arg0;

    if (actor->type == 1 && (actor->flags100 & 0x300000) != 0) {
        set = &D_801040D0;
    } else {
        grounded = func_8024DEE0_de(arg0);
        if (func_8024DF5C_de(arg0) == 0) {
            set = &D_801040D0;
            if (grounded != 0) {
                set = &D_80104050;
            }
        } else if (func_8024DFA0_de(arg0) == 0) {
            set = &D_80104070;
        } else {
            set = &D_80103FF0;
        }
    }
    if (out != 0) {
        *out = set;
    }
    saved = *arg0;
    collisions = func_80243A90_de(arg0, position, set);
    *arg0 = saved;
    return collisions;
}
