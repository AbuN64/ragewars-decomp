#include "shared/level_actor.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_80279208.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80206258.h"







/** Copy the source byte at offset 7 into two fields under object offset 0x18. */
void func_80206930_de(void *arg0, int arg1, void *arg2) {
    void *inner = ((Actor_func_8024A7A0_de *)arg0)->definition;
    ((ActorDefinitionHeader *)inner)->first = (s8)((Trigger *)arg2)->unk4;
    inner = ((Actor_func_8024A7A0_de *)arg0)->definition;
    ((ActorDefinitionHeader *)inner)->second = (s8)((Trigger *)arg2)->unk4;
}
