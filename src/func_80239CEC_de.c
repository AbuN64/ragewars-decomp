#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802393F4.h"



/** Clear four consecutive object words beginning at offset 4. */
void func_80239CEC_de(void *arg0) {
    struct Channel *channel = arg0;
    channel->level = 0.0f;
    channel->state[0] = 0;
    channel->state[1] = 0;
    channel->state[2] = 0;
}
