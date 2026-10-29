#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int k_vector3intersectplaneDataFloatConstantWords[9] = {
    0x3A83126F, 0xBA83126F, 0x3F000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8029E93C_CBA3C_us_rev1.c */
const unsigned int k_vector3intersectplaneDataFloatConstantWordsBlock1[3] = {
    0x3A83126F, 0xBA83126F, 0x3F000000,
};

/* ROM-grounded data: src/rw_pool_8029EB14_CBA48_us_rev1.c */
const unsigned int k_VectorIntersectplaneOneWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8029ED54_CBA4C_us_rev1.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant1[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8029EDD8_CBA50_us_rev1.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant2[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8029EE78_CBA54_us_rev1.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant3[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8029EF18_CBA58_us_rev1.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant4[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8029F254_CBA5C_us_rev1.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant5[1] = {
    0x3F800000,
};
#endif
