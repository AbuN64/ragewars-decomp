#include "span_1000/code_8028FC98.h"
#include "common/types_8fd754e1e915.h"
#include "types.h"

/** Add an indexed word from the first argument to the second argument. */
int func_8028FE28_de(int *arg0, int arg1, int arg2) {
    arg0 += arg2;
    return arg1 + arg0[1];
}

s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    
    s32 *next = (s32 *)(arg0 + ((arg2 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg2 * 4));
    *arg3 = next[1] - entry[1];
    return arg1 + entry[1];
}

s32 func_8028FE6C_de(s32 arg0, s32 arg1, s32 *arg2) {
    
    s32 *next = (s32 *)(arg0 + ((arg1 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg1 * 4));
    *arg2 = next[1] - entry[1];
    return entry[1];
}

void func_8028FE9C_de(int *arg0, int **arg1, int *arg2) {
    int *p;
    *arg1 = arg0;
    p = arg0 + *arg0;
    *arg2 = p[1];
}
