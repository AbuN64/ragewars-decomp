#include "include_asm.h"

#if defined(NON_MATCHING) && !defined(__i386__) && !defined(__x86_64__)
/* 311/317 words with -msplit-addresses (a per-file cflag in config.toml, 278/317 without); remaining: 6 words of hi/lo hazard nops the assembler does not insert */
/* gcc-2.8.1 libgcc2 __umoddi3 compiled in place; the units name it func_802C1330_de */
#define __umoddi3 func_802C1330_de
#define L_umoddi3
#include "libgcc2.inc.c"
#else
INCLUDE_ASM("span_1000", func_802C1330_de);
#endif
