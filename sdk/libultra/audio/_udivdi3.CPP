#include "include_asm.h"

#if !defined(__i386__) && !defined(__x86_64__)
#define L_udivdi3
#include "../../libgcc/libgcc2.inc.c"
#endif


