#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8028FC98.h"
#include "TYPES.H"

/** Return the byte address named by an indexed word offset from the base. */
char *func_8028FDB4_de(int *arg0, int arg1) {
    int *entry = arg0 + arg1;
    return (char *)arg0 + entry[1];
}

s32 func_8028FDC8_de(s32 arg0, s32 arg1, s32 *arg2) {
    
    s32 *next = (s32 *)(arg0 + ((arg1 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg1 * 4));
    *arg2 = next[1] - entry[1];
    return arg0 + entry[1];
}
