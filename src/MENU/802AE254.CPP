#include "include_asm.h"
#include "COMMON/RESPONSE.H"
#include "MENU/802AE254.H"

/** Return the one status used by callers. */
int func_802AD264_de(void) {
    return 1;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802AD19C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("span_1000", func_802AD264_de_padding_ADE6C);
#endif
