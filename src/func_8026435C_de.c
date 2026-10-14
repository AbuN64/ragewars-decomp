#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802636D0.h"



/** Report whether flag 0x1000 is set in the word at offset 0xB4. */
int func_8026435C_de(void *object) {
    int flags = ((Shared_Effect *)(object))->state & 0x1000;
    return flags != 0;
}
