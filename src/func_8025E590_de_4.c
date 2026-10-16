#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8025E568.h"

/** Return the signed halfword at offset 0x14 in the supplied object. */
int func_8025E590_de(Controller_func_80259C5C_de *object) {
    return object->y;
}

/** Return the signed halfword at offset twelve. */
int func_8025E59C_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->fieldC;
}
