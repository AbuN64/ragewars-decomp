#include "shared/motion_step.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023D370.h"
#include "types.h"






void func_8023EBFC_de(void *arg0, void *arg1) {
    s32 temp_a1;
    s32 temp_v1;

    temp_v1 = ((ActorMotion *)arg0)->flags & ~0xE00;
    ((ActorMotion *)arg0)->flags = temp_v1;
    temp_a1 = ((MotionContactResult *)arg1)->flags;
    if (temp_a1 & 0x20000000) {
        ((ActorMotion *)arg0)->flags = temp_v1 | 0x200;
        return;
    }
    if (temp_a1 & 0x40000000) {
        ((ActorMotion *)arg0)->flags = temp_v1 | 0x400;
        return;
    }
    if (temp_a1 < 0) {
        ((ActorMotion *)arg0)->flags = temp_v1 | 0x800;
    }
}
