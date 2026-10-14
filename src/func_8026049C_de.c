#include "span_1000/code_8025E568.h"



/** Return the first word of the object referenced at offset 0x10. */
void *func_8026049C_de(void *object) {
    AnimRef *animation = object;
    return *animation->data;
}
