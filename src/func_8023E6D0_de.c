#include "shared/motion_step.h"
#include "span_1000/code_8023D370.h"



void func_8023E6D0_de(void *arg0, float arg1) {
    ActorMotion *motion = arg0;
    motion->bottom = 0.0f;
    motion->field08 = arg1;
    motion->radius = arg1;
    motion->height = arg1;
    motion->field18 = arg1;
}
