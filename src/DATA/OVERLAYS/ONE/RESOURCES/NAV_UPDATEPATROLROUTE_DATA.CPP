#include "TYPES.H"



/* 800C2000.CPP */
#if defined(VERSION_US)
unsigned int g_NavUpdatepatrolrouteWords2[12] = {
    0x42CCCCCC, 0x52000000, 0x0000000A, 0x0008001C, 0x42CCCCCC, 0x424CCCCC, 0x65724678, 0x5F745400,
    0x42CCCCCC, 0x00080008, 0x00080000, 0x00000007,
};
#endif

/* 800C2374.CPP */
#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    u8 alignmentFill[12];
} g_NavUpdatepatrolrouteWords3 __attribute__((aligned(4))) = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x0B, 0x28, 0x00 }
};
#endif
#endif

/* 802192C0_10.CPP */
#if defined(VERSION_EU_X)
const float g_NavUpdatepatrolrouteWords1[4] = {
    0.05f, 0.3f, -0.7071f, 0.7071f,
};
#endif
