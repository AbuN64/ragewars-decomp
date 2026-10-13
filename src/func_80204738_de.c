#include "shared/level_actor.h"
#include "span_1000/code_80203F04.h"





/** Clear two flag groups when the object's 0x1B0 field exceeds a tunable. */
void func_80204738_de(void *object) {
    if (((Actor_func_8024A7A0_de *)object)->motionThreshold > D_800C1A70_de) {
        int flags = ((Actor_func_8024A7A0_de *)object)->flags;
        flags &= ~0x2000;
        flags &= ~0x100;
        ((Actor_func_8024A7A0_de *)object)->flags = flags;
    }
}
