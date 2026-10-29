#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: rodata/System_RunPiManager/800CCB80 */
#ifdef VERSION_DE
const unsigned int k_SystemRunPiManagerJumpTableWords[7] = {
    0x002B9354, 0x002B9274, 0x002B92A8, 0x002B9364, 0x002B9364, 0x002B92DC, 0x002B9318,
};
#endif
#ifdef VERSION_EU
const unsigned int k_SystemRunPiManagerJumpTableWords[8] = {
    0x002B95F4, 0x002B9514, 0x002B9548, 0x002B9604, 0x002B9604, 0x002B957C, 0x002B95B8, 0x41800000,
};
#endif
#endif

#if defined(VERSION_DE)
unsigned int k_SystemEncodedWords[1] = {
    0x77726561,
};
#endif
