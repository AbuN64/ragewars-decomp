#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022A274.h"
#include "types.h"




void func_8022A940_de(void *arg0) {
    s32 val = ((Shared_Effect *)(arg0))->state;
    if (val != 0 && val != 3) {
        ((Shared_Effect *)(arg0))->state = 3;
    }
}
