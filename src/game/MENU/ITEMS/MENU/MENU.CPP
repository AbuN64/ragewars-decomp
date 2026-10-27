#include "include_asm.h"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* 3-word split artefact: only sets $a0 (a caller-saved scratch) and returns. */
void func_80444308_eu(void) {
}
#else
INCLUDE_ASM("ovl_80400000", func_80444308_eu);
#endif
#endif
