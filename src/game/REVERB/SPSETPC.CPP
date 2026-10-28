#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "TYPES.H"



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

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA02C[1] = {
    0x5F4A756D,
};
#endif
