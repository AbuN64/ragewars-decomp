#include "include_asm.h"
#include "sdk/OBJECTSTATE2.H"

unsigned short func_802AD270_de(float arg0) {
    return *(unsigned short *)&arg0;
}

#if defined(VERSION_EU)
#include "TYPES.H"

f32 func_802AD520_eu(u32 value) {
    u32 bits = value << 16;
    return *(f32 *)&bits;
}
#ifdef NON_MATCHING
/* Split artefact: the tail of the routine at 0x802A8544's neighbour; hands $s3 to $a1 and jumps into that routine, the
   rest is a bare return. Carried as the original instructions. */
void func_802AD538(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "j          0x802A8544\n"
        "addu       $5, $19, $0\n"
        "jr         $31\n"
        "nop\n"
        ".set reorder\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_802AD538);
#endif
#endif
