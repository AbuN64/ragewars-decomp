#ifndef SDK_OS_PIF_H
#define SDK_OS_PIF_H
#include "sdk/os.h"
/* The controller and pak PIF RAM blocks and the SI access queue that the libultra os/pfs code shares. */
struct OSPifRam;
extern struct OSPifRam D_80154110;
extern struct OSPifRam D_8014D470;
extern u8 D_8014D46C[];
extern OSMesgQueue D_8014EA58;
extern OSMesg D_8014EA50;
extern s32 D_800D83C0[];
#endif
