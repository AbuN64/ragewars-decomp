#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "types.h"
#include "shared/actor_header.h"









f32 func_8022ADBC_de(void *arg0) {
    struct Object *object = arg0;
    struct Model_func_80223E34_de *temp_v0;

    temp_v0 = object->owner;
    if (temp_v0 != 0) {
        return temp_v0->height * D_800C2D04_de;
    }
    return D_800C2D00_de;
}
