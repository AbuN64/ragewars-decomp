#include "span_1000/code_8028FC98.h"
#include "types.h"
s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    
    s32 *next = (s32 *)(arg0 + ((arg2 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg2 * 4));
    *arg3 = next[1] - entry[1];
    return arg1 + entry[1];
}
