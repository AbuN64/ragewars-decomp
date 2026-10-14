#include "shared/gameplay_transition.h"
#include "shared/particle_lighting.h"
#include "shared/world.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"

extern s32 func_8028B21C_de(void *arg0, s32 arg1);
extern s32 func_8028C198_de(void *arg0, s32 arg1);
extern void func_8026DF30_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);





void func_8022B484_de(char *arg0) {
    ObjRecAt120C *object = arg0;
    s32 index;

    if (object->unk120C != 0) {
        index = func_8028B21C_de(&D_8011FE88, 0xC84);
    } else {
        index = func_8028B21C_de(&D_8011FE88, 0xC85);
    }
    if (index != -1) {
        func_8026DF30_de(func_8028C198_de(&D_8011FE88, index),
                      (s32)((Shared_ActorView *)arg0)->transform1600, (s32)&D_800D0EF8, 0, -1);
    }
}
