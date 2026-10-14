#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8024D018.h"
#include "types.h"
#include "shared/level_actor.h"
#include "common/types_8fd754e1e915.h"






s32 func_8024DF08_de(void *arg0) {
    void *temp_a1 = ((Actor_func_8024A7A0_de *)arg0)->definition;
    s32 temp_v1 = ((ModelBlend *)temp_a1)->kind;

    if (temp_v1 != 1) {
        if (temp_v1 != 0xB) {
            goto ret0;
        }
        return 1;
    }
    {
        s32 var_v1 = 0;
        if (((Actor_func_8024A7A0_de *)arg0)->active <= 0 || (((ModelBlend *)temp_a1)->collisionOptions & 2)) {
            var_v1 = 1;
        }
        return var_v1;
    }
ret0:
    return 0;
}
