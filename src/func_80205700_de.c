#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80204E78.h"



/** Return the object's 0x200 status bit. */
unsigned int func_80205700_de(void *object) {
    struct Hit *hit = object;
    return hit->flags & 0x200;
}
