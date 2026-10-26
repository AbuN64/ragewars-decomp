#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/** Return the byte address named by an indexed word offset from the base. */
void *SetN64_GetPackSection(void *table, s32 index) {
    s32 *entry = (s32 *)table + index;
    return (char *)table + entry[1];
}

s32 SetN64_GetSizedPackSection(s32 packAddress, s32 sectionIndex, s32 *sectionSizeOut) {
    
    s32 *next = (s32 *)(packAddress + ((sectionIndex + 1) * 4));
    s32 *entry = (s32 *)(packAddress + (sectionIndex * 4));
    *sectionSizeOut = next[1] - entry[1];
    return packAddress + entry[1];
}

s32 SetN64_GetPackSectionSize(s32 *table, s32 index) {
    s32 nextIndex = index + 1;
    s32 *next = &table[nextIndex];
    s32 *entry = &table[index];
    s32 size;
    s32 *output = &size;
    *output = next[1] - entry[1];
    return size;
}
