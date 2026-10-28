#include "include_asm.h"
#include "COMMON/GAMEPLAY_TRANSITION.H"

const Shared_HeightBonuses g_playerDeathHeightOffsets = {
    10.23999977f,
    81.91999817f,
};
const float g_playerDeathMotionCenter = 512.0f;
const float g_playerDeathMovingSpeed = 5.119999886f;

#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int rodata_func_8021BFC4_de_800C2658[3] = {
    0x3D888889, 0x3F800000, 0x424CCCCC,
};
#endif
