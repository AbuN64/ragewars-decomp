#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802393F4.h"




void *func_80239740_de(struct ScreenMessageOwner *owner, struct ScreenMessagePool *pool, u8 *text) {
    struct Message *temp_v0 = func_80237E80_de(owner, pool, text);
    if (temp_v0 != 0) {
        temp_v0->pad20 = 1;
    }
    return temp_v0;
}
