#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8024D018.h"
#include "types.h"





extern u8 D_801462E5;
s32 func_8024DEA0_de(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt18V5 *) ((s8 *) arg0))->unk18);
    if ((((struct ObjRecAt14V3 *) ((s8 *) temp_a0))->unk0) == 0xB) {
        if (D_801462E5 != 0) {
            return (((struct ObjRecAt14V3 *) ((s8 *) temp_a0))->unk14) & 1;
        }
        return 1;
    }
    return 0;
}
