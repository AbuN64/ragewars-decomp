#include "include_asm.h"
#include "COMMON/RESPONSE.H"
#include "MENU/CODE_802AE254.H"

/** Return the one status used by callers. */
int func_802AD264_de(void) {
    return 1;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802AD19C[1] = {
    0x5F437572,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802AD264_de_padding_ADE6C[1] = {
    0x00000000,
};
#endif
