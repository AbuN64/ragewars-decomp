#include "include_asm.h"

#define L_udivdi3
#include "libgcc2.inc.c"

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802C1254);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", rodata_unresolved_802C1604);
#endif
