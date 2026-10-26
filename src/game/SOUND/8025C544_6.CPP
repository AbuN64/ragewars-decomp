#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "TYPES.H"
#include "SOUND/8025C544_6.H"


/** Return the address of the global state word at D_8011F260. */
s32 *func_8025CC6C_de(void) {
    return &D_8011F260;
}

/** Deliberately perform no work. */
void func_8025CC7C_de(void) {
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8025CC24[3] = {
    0x72000000, 0x00940A00, 0x08001400,
};
#endif
