#include "DATA/REST_SOURCE_RECORDS.H"
#include "include_asm.h"

/* 800C7704.CPP */
#if defined(VERSION_US)
struct {
    unsigned int w0[4];
    unsigned char b1[16];
    unsigned int w2[5];
} s_audioSaveText = {
    {
        0x0000000F, 0x5649445F, 0x4D4F4445, 0x45580000,
    },
    {
        0x61, 0x75, 0x64, 0x69, 0x6F, 0x2F, 0x73, 0x61, 0x76, 0x65, 0x2E, 0x63, 0x00, 0x00, 0x00, 0x00,
    },
    {
        0x00000F56, 0x49445F4D, 0x4F44455F, 0x3FF00000, 0x00000000,
    },
};
#endif

/* 800C816C.CPP */

/* 800C83D4.CPP */
#if defined(VERSION_EU)
RestLinkerAlignmentFill12 g_Save2LinkerAlignmentFill792 = {
    { 66, 128, 0, 0, 67, 0, 0, 0, 79, 0, 0, 0 },
};
#endif

/* 800C853C_4.CPP */
#if defined(VERSION_EU_X)
const unsigned char g_SaveBytes1[3] = {
    0x42, 0x40, 0x00,
};
#endif
