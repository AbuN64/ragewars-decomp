#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"



/** Report whether the signed word at byte offset 0x5E4 is below 0x6400. */
int func_8022ADB0_de(struct SharedPlayer *object, s32 arg1) {
    return object->views5E4.view5E4_0.unk5E4 < 0x6400;
}
