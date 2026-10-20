#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "TYPES.H"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802BA0D0_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802BA0F4_de);
#endif

#if !(defined(VERSION_DE))
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
INCLUDE_DATA("span_1000", rodata_unresolved_802BA02C);
#endif
