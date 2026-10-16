#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802412C0.h"





/** Set flag 8 in the first object and flag 0x10 in the second. */
void func_802428D0_de(void *first, void *second) {
    ActorRecAtB0 *actor = first;
    Input_func_802426CC_de *input = second;
    actor->flags |= 8;
    input->flags38 |= 0x10;
}
