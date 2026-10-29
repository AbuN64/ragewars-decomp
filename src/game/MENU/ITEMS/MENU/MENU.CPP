#include "include_asm.h"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* 3-word split artefact: only sets $a0 (a caller-saved scratch) and returns. */
void Items_MenuUpdateNoOpEuropean(void) {
}
#else
INCLUDE_ASM("ovl_frontendMenu", Items_MenuUpdateNoOpEuropean);
#endif
#endif
