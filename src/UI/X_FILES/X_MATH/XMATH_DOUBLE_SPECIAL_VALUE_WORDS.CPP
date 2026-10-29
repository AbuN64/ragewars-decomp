#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"
#if defined(VERSION_US)
const unsigned int k_dispatchControllerButtonEventJumpTableTrailingWords[3] = { 0x00400000, 0x00020004, 0x00000004 };
#endif
#if defined(VERSION_EU)
const unsigned int k_dispatchControllerButtonEventJumpTableTrailingWords[3] = { 0x00C81804, 0x00A91006, 0x00624025 };
#endif

const unsigned int k_xMathConstantWords[6] = {
    0x7FF00000, 0x00000000, 0x3FF00000, 0x00000000, 0x3FF00000, 0x00000000,
};
