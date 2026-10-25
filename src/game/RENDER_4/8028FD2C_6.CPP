#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/** Return the byte address named by an indexed word offset from the base. */
void *Render_GetPackSection(void *table, s32 index) {
    s32 *entry = (s32 *)table + index;
    return (char *)table + entry[1];
}

s32 func_8028FDC8_de(s32 arg0, s32 arg1, s32 *arg2) {
    
    s32 *next = (s32 *)(arg0 + ((arg1 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg1 * 4));
    *arg2 = next[1] - entry[1];
    return arg0 + entry[1];
}

s32 func_8028FDF8_de(s32 *table, s32 index) {
    s32 nextIndex = index + 1;
    s32 *next = &table[nextIndex];
    s32 *entry = &table[index];
    s32 size;
    s32 *output = &size;
    *output = next[1] - entry[1];
    return size;
}
