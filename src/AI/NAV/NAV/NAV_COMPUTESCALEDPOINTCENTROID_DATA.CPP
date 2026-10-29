#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const float g_pointCentroidUnitScale = 1.0f;
#endif


#if defined(VERSION_DE)
unsigned int k_NavComputescaledpointcentroidEncodedWords[1] = {
    0x0020DF30,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/g_pointCentroidUnitScale_us_rev1.c */

/* ROM-grounded data: src/g_Nav_ComputeScaledPointCentroidConstantWords_NavComputescaledpointcentroidData.c */
const unsigned int g_Nav_ComputeScaledPointCentroidConstantWords[1] = {
    0x3F800000,
};
#endif
