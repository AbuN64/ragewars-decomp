#include "include_asm.h"

/* 80263760.CPP */
#if defined(VERSION_EU)
unsigned char g_ContpadTrailingBytes[12] = { 0x46, 0x14, 0x00, 0x32, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x02 };
#endif

/* 80263760_10.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_80264F4C_eu_x[1] = { 0xAFA9003CU };
#endif

/* DATA_8024F924.CPP */
#if defined(VERSION_US)
char g_ContpadEncodedBytes[12] = "ngNoOfLaps8";
#endif
