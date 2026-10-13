#include "span_1000/code_8028FC98.h"
#include "types.h"
s32 func_8028FE6C_de(s32 arg0, s32 arg1, s32 *arg2) {
    
    s32 *next = (s32 *)(arg0 + ((arg1 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg1 * 4));
    *arg2 = next[1] - entry[1];
    return entry[1];
}
