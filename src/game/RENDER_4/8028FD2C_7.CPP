#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
#include "RENDER_4/8028FD2C_7.H"

/** Add an indexed word from the first argument to the second argument. */
int Render_GetDirectoryEntry(int *directory, int arg1, int level) {
    directory += level;
    return arg1 + directory[1];
}

s32 Render_LocatePackSection(void *arg0, s32 arg1, s32 arg2, s32 *arg3) {
    
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
