#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
#include "RENDER_4/8028FD2C_7.H"

/** Add an indexed word from the first argument to the second argument. */
int SetN64_GetDirectoryEntry(int *directory, int bankOffset, int level) {
    directory += level;
    return bankOffset + directory[1];
}

s32 SetN64_LocatePackSection(void *directory, s32 bankOffset, s32 sectionIndex, s32 *sectionSizeOut) {
    
    s32 *next = (s32 *)(directory + ((sectionIndex + 1) * 4));
    s32 *entry = (s32 *)(directory + (sectionIndex * 4));
    *sectionSizeOut = next[1] - entry[1];
    return bankOffset + entry[1];
}

s32 SetN64_GetPackSectionOffsetAndSize(s32 arg0, s32 arg1, s32 *arg2) {
    
    s32 *next = (s32 *)(arg0 + ((arg1 + 1) * 4));
    s32 *entry = (s32 *)(arg0 + (arg1 * 4));
    *arg2 = next[1] - entry[1];
    return entry[1];
}

void SetN64_GetPackBaseAndSize(int *arg0, int **arg1, int *arg2) {
    int *p;
    *arg1 = arg0;
    p = arg0 + *arg0;
    *arg2 = p[1];
}
