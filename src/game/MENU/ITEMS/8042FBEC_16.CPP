#include "include_asm.h"

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* 2-word split artefact: a bare return whose delay slot holds the next routine's stack adjust (addiu $sp, $sp, -0x38). */
void func_8043FCFC_eu(void) {
}
#else
INCLUDE_ASM("ovl_80400000", func_8043FCFC_eu);
#endif
#endif
