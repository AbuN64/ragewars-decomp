#include "include_asm.h"
#include "TYPES.H"

#if defined(VERSION_DE)
const f32 data_func_802631B0_de_800C4290[23] = {
    0.99000001f, 0.0078125f, 1.0f, 0.100000001f, 0.75f, 1.0f,
    -1.0f, 0.0125000002f, 1.0f, -1.0f, 0.0125000002f, 0.0125000002f,
    1.0f, -1.0f, 0.0125000002f, 1.0f, -1.0f, 0.0125000002f,
    0.75f, 1.0f, 0.75f, -1.0f, 0.100000001f,
};
#endif

#if defined(VERSION_DE) || defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C42EC);
#endif
