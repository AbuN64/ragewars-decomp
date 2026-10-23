#include "include_asm.h"
#include "COMMON/S1_2.H"
#include "TYPES.H"
#include "SYSTEM_2/8025E280_3.H"
#include "TEXTURE/80256220_16.H"
#include "COMMON/AUDIO_CONTEXT.H"



s32 func_802585F4_de(struct ContextRecAt2BC0 *, s32);

void func_8025E4B0_de(void) {
    func_802587A4_de(&D_8010C080);
}

struct ContextRecAt2BC0;

s32 func_8025E4D4_de(s32 arg0) {
    return func_802585F4_de(&D_8010C080, arg0);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8025E49C[1] = {
    0x74685F74,
};
#endif
