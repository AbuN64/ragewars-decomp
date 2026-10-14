#include "span_1000/code_8024E914.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802508E0.h"



/** Read the signed byte at offset 0xE from the object's linked record. */
signed char func_80250A8C_de(struct PlacedProp *object) {
    void *linked = object->model;
    return ((signed char *)linked)[0xE];
}
