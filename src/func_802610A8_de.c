#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802609CC.h"
#include "types.h"






void func_802610A8_de(void *arg0, s32 arg1) {
    s32 count;
    s32 *ptr;
    Pack *pack = arg0;
    s32 magic;

    count = 1;
    pack->count = arg1;
    pack->offsets[0] = ((arg1 * 4) + 0xF) & ~7;
    if (arg1 > 0) {
        magic = 0xDEADBEEF;
        ptr = pack->offsets;
        do {
            ptr[1] = magic;
            count += 1;
            ptr += 1;
        } while (arg1 >= count);
    }
}
