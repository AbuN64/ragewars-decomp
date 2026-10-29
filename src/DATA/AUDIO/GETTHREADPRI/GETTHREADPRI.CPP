#include "include_asm.h"

/* 802BFD80_17.CPP */
#if defined(VERSION_EU)
unsigned char g_GetthreadpriTrailingBytesBlock1[4] = { 0x8E, 0x70, 0x00, 0x04 };
#endif

/* g_getthreadpriConstantWords_Getthreadpri.CPP */
#if defined(VERSION_US)
char func_802B6664_de_padding_BC334[12] =
    "\020m_PickupInf";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802B6664_de_padding_BC334 */
unsigned int g_getthreadpriConstantWords[3] = {
    0xA0820000, 0x24630001, 0x24C60008,
};
#endif
