#include "include_asm.h"

/* 8023A284_3.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int g_recycleLinkGapWords[1] = { 0xAC4A0018U };
#endif

/* 8023A284_6.CPP */
#if defined(VERSION_EU)
unsigned char g_RecycleMixedLinkGapFragmentsTrailingBytes[4] = { 0x3C, 0x01, 0x80, 0x0C };
#endif

/* 802591C0_2.CPP */
#if defined(VERSION_US)
char k_RecycleMixedLinkGapFragmentsEncodedBytes[8] =
    "tyMin\001\000\000";
#endif
