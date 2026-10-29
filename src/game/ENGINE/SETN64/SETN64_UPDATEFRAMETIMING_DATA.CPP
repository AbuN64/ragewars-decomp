#include "include_asm.h"

/* 800CA538.CPP */
const unsigned int g_Setn64UpdateframetimingWords1[9] = {
    0x3F800000, 0x437F0000, 0x358637BD, 0x3DCCCCCD, 0x3F000000, 0x3F800000, 0xC0800000, 0x3F000000,
    0x3F800000,
};

/* 800CA55C.CPP */
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned int g_Setn64UpdateframetimingWords2[2] = {
    0x358637BD, 0x41700000,
};

#if defined(VERSION_DE)
const unsigned int k_Setn64UpdateframetimingEncodedWords[1] = {
    0x3F666666,
};
#endif
