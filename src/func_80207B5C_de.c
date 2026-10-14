#include "span_1000/code_80206258.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80207ABC.h"
#include "types.h"
typedef struct Owner Owner;

extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);

void func_80207B5C_de(void *object, u32 *arg1) {
    Player *arg0 = object;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_s0;

    resource = arg0->definition;
    temp_s0 = &resource->motion;
    func_80278D78_de(arg0, 0x10000, arg0);
    if (!(temp_s0->transitionFlags & 0x40)) {
        *arg1 &= 0xFFFEFFFF;
    }
}
