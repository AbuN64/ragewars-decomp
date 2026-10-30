#include "DATA/REST_SOURCE_RECORDS.H"

/* ROM-grounded data: rodata/writable/800E59E0 */
u16 g_EquipShowequipchoiceHalfwords1[4] = { 0, 0, 0,
#if defined(VERSION_DE)
    207
#elif defined(VERSION_EU_X)
    213
#else
    0
#endif
};
