#include "include_asm.h"

#if defined(NON_MATCHING) && !defined(__i386__) && !defined(__x86_64__)
/* 371/379 words with -msplit-addresses (a per-file cflag in config.toml, 343/379 without); remaining: 8 words of hi/lo hazard nops the assembler does not insert */
#if defined(VERSION_US)
#define __divdi3 func_802C0164
#else
#define __divdi3 func_802C0230_de
#endif
#define L_divdi3
#include "libgcc2.inc.c"
#else
#if !(defined(VERSION_US))
INCLUDE_ASM("span_1000", func_802C0230_de);
#endif
#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_802C0164);
#endif
#endif
