#include "span_1000/code_8027302C.h"



/** Swap the two floats within each of the object's four 0x10-byte records. */
void func_80273E20_de(struct Mtx *object) {
    float t;
    t = object->right.y;
    object->right.y = object->right.z;
    object->right.z = t;

    t = object->up.y;
    object->up.y = object->up.z;
    object->up.z = t;

    t = object->forward.y;
    object->forward.y = object->forward.z;
    object->forward.z = t;

    t = object->m31;
    object->m31 = object->m32;
    object->m32 = t;
}
