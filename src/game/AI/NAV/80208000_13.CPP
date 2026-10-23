#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#if defined(VERSION_EU)
unsigned int func_8020D364_de_padding_DF84[3] = {
    0x24020064, 0xAE0200A0, 0x2402FFFF,
};
#endif
#if defined(VERSION_EU_X)
unsigned int func_8020D364_de_padding_DF84[3] = {
    0x46800860, 0x46030842, 0x3C01800C,
};
#endif
#endif
