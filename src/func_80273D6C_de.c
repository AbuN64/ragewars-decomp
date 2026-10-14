#include "span_1000/code_8027302C.h"



/** Swap the two float-groups at offsets 0x10 and 0x20 (three floats each). */
void func_80273D6C_de(struct Mtx *object) {
    float t;
    t = object->up.x;
    object->up.x = object->forward.x;
    object->forward.x = t;

    t = object->up.y;
    object->up.y = object->forward.y;
    object->forward.y = t;

    t = object->up.z;
    object->up.z = object->forward.z;
    object->forward.z = t;
}
