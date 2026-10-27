#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned short func_8020D364_de_padding_DF64[6] = {
    0xA66B, 0xFB05, 0x9FA5, 0x010A, 0xA069, 0x8DCD,
};
#endif
#if defined(VERSION_US)
unsigned int func_8020D364_de_padding_DF64[3] = {
    0x06000000, 0x00000E6D, 0x5F486569,
};
#endif
#endif

#if defined(VERSION_US_REV1)
unsigned int D_d0_cd1f3a8def92aa29[3] = {
    0x46800860, 0x46030842, 0x3C01800C,
};
#endif
