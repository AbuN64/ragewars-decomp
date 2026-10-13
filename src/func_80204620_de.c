#include "shared/level_actor.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80203F04.h"
#include "types.h"






s32 func_80204620_de(void *arg0) {
    s32 val;

    val = ((BreakableDefinition *)((Actor_func_8024A7A0_de *)arg0)->definition)->health;
    if (val != 0) {
        ((Actor_func_8024A7A0_de *)arg0)->flags = ((Actor_func_8024A7A0_de *)arg0)->flags | 0x2000;
    } else {
        s32 flags = ((Actor_func_8024A7A0_de *)arg0)->flags & ~0x2000;
        flags &= ~0x100;
        ((Actor_func_8024A7A0_de *)arg0)->flags = flags;
    }
    return val;
}
