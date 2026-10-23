#include "include_asm.h"

#if defined(VERSION_US)
unsigned int func_802131D8_de_padding_13DD8[2] = {
    0x52000030, 0x07000010,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: func_802131D8_de_padding_13DD8 */
#ifdef VERSION_DE
unsigned int D_blob_phase2_9a0d122bfa8da66a4c0e[2] = {
    0x8C430004, 0x8C440008,
};
#endif
#ifdef VERSION_US_REV1
unsigned int D_blob_phase2_9a0d122bfa8da66a4c0e[2] = {
    0x8E220030, 0x10400006,
};
#endif
#endif
