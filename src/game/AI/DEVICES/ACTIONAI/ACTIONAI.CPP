#include "include_asm.h"

/* 800C1D38.CPP */
#if defined(VERSION_EU_X)
const unsigned int k_actionaiConstantWords[5] = {
    0x0020421C, 0x00204224, 0x0020422C, 0x00204234, 0x0020423C,
};
#endif

/* TURRETAI_9.CPP */
#if defined(VERSION_EU)
const unsigned int k_actionaiFloatConstantWords[1] = {
    0x42F5C28F,
};
#endif

/* g_actionaiConstantWords_Actionai.CPP */
#if defined(VERSION_DE)
unsigned int g_actionaiConstantWords[30] = {
    0x063FB64E, 0x2BDF9701, 0x409AF000, 0x3C1A0020, 0x275A2460, 0x03400008, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3C1A8000, 0x375A0194, 0x03400008, 0x00000000,
    0x409AF000, 0x3C1A0020, 0x275A2460, 0x03400008, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x3C1A8000, 0x375A0014, 0x03400008, 0x00000000,
};
#endif
