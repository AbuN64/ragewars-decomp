#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C36DC[1] = {
    0xAFB40020,
};
#endif
#if defined(VERSION_US)
unsigned int rodata_unresolved_800C36DC[1] = {
    0x4175746F,
};
#endif
#endif
