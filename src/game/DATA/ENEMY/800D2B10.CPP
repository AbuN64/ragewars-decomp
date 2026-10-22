#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", rodata_unresolved_800D2B10);
#endif

#if defined(VERSION_US_REV1)
/* Announce message block shared by the menu handler table: ids 10..18 followed by the kill-message
   text tail "nted", "Embryo Destr". us-rev1 wording; the other cartridges word this block in their
   own language, so only the versions carrying these bytes land here. */
unsigned int D_auto_rodata_unresolved_800D2B10[16] = {
    0x00000000, 0x0000000A, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F,
    0x00000010, 0x00000011, 0x00000012, 0x6E746564, 0xFFFFFFFF, 0x456D6272, 0x796F2044, 0x65737472,
};
#endif
