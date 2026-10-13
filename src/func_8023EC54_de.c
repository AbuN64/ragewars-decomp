#include "shared/motion_step.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8023D370.h"
#include "types.h"






void func_8023EC54_de(void *arg0, void *arg1) {
    s32 temp_a1;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;

    temp_v1 = ((ActorMotion *)arg0)->flags;
    if (temp_v1 & 0x1000) {
        ((ActorMotion *)arg0)->flags = temp_v1 & ~0x2000;
    }
    temp_v0 = ((ActorMotion *)arg0)->flags;
    temp_v1_2 = temp_v0 & 0xFFFC7FFF;
    ((ActorMotion *)arg0)->flags = temp_v1_2;
    if (temp_v0 & 0x7000) {
        temp_a1 = ((MotionContactResult *)arg1)->material;
        switch (temp_a1) {
        case 8:
            ((ActorMotion *)arg0)->flags = temp_v1_2 | 0x10000;
            return;
        case 7:
            ((ActorMotion *)arg0)->flags = temp_v1_2 | 0x8000;
            break;
        }
    }
}
