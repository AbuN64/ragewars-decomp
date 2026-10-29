#include "include_asm.h"
#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "TYPES.H"

#if defined(VERSION_US)
unsigned int func_80437C28_us_rev1_padding_1A5C28[2] = {
    0x04000800, 0x00000363,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char g_MenuDispatchtitlebuttoneventTrailingBytes[8] = { 0x08, 0x10, 0xE3, 0x15, 0x00, 0x00, 0x00, 0x00 };
#endif
