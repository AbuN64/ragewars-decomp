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

s32 SetN64_GetPackSectionOffsetAndSize(s32 directoryAddress, s32 sectionIndex, s32 *sectionSizeOut) {
    
    s32 *next = (s32 *)(directoryAddress + ((sectionIndex + 1) * 4));
    s32 *entry = (s32 *)(directoryAddress + (sectionIndex * 4));
    *sectionSizeOut = next[1] - entry[1];
    return entry[1];
}

void SetN64_GetPackBaseAndSize(int *directory, int **packBaseOut, int *packSizeOut) {
    int *p;
    *packBaseOut = directory;
    p = directory + *directory;
    *packSizeOut = p[1];
}
