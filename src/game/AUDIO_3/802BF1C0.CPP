#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "TYPES.H"

#if (defined(VERSION_DE)) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", func_802BA0D0_de);
#endif

#if defined(VERSION_DE)
/* Stub that reports failure. */
s32 func_802BA0F4_de(void) {
    return -1;
}
#endif

#if !(defined(VERSION_DE)) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
/* Sets the RSP program counter: returns -1 unless the RSP status register shows the processor
   halted, otherwise writes the address to the program counter register and returns zero. */
s32 func_802BA0D0_de(u32 pc) {
    u32 status = *(volatile u32 *) 0xA4040010;

    if (!(status & 1)) {
        return -1;
    }
    *(volatile u32 *) 0xA4080000 = pc;
    return 0;
}
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA02C[1] = {
    0x5F4A756D,
};
#endif
