#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: rodata/System_RunPiManager/800CCB80 */
#endif

#if defined(VERSION_DE)
unsigned int k_SystemEncodedWords[1] = {
    0x77726561,
};
#endif
