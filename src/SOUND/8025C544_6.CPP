#include "include_asm.h"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "TYPES.H"
#include "SOUND/8025C544_6.H"

extern s32 D_8011F260;

/** Return the address of the global state word at D_8011F260. */
s32 *func_8025CC6C_de(void) {
    return &D_8011F260;
}

/** Deliberately perform no work. */
void func_8025CC7C_de(void) {
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_8025CC24);
#endif
