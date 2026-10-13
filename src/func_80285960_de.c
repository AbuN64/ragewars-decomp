#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028567C.h"



/** Clear the target word when the pointer field is populated. */
void func_80285960_de(char *object) {
    struct Node_func_80285B64_de *node = (void *)object;
    struct Node_func_80285B64_de **target = node->owner;
    if (target != 0) {
        *target = 0;
    }
}
