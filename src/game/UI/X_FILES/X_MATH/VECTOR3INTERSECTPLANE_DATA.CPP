#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"

#if !(defined(VERSION_US_REV1))
const unsigned int k_vector3intersectplaneDataFloatConstantWords[9] = {
    0x3A83126F, 0xBA83126F, 0x3F000000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000,
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/k_vector3intersectplaneDataFloatConstantWordsBlock1_Vector3intersectplaneData.c */
const unsigned int k_vector3intersectplaneDataFloatConstantWordsBlock1[3] = {
    0x3A83126F, 0xBA83126F, 0x3F000000,
};

/* ROM-grounded data: src/k_VectorIntersectplaneOneWords_Vector3intersectplaneData.c */
const unsigned int k_VectorIntersectplaneOneWords[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/k_VectorIntersectplaneOneWordsVariant1_Vector3intersectplaneData.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant1[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/k_VectorIntersectplaneOneWordsVariant2_Vector3intersectplaneData.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant2[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/k_VectorIntersectplaneOneWordsVariant3_Vector3intersectplaneData.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant3[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/k_VectorIntersectplaneOneWordsVariant4_Vector3intersectplaneData.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant4[1] = {
    0x3F800000,
};

/* ROM-grounded data: src/k_VectorIntersectplaneOneWordsVariant5_Vector3intersectplaneData.c */
const unsigned int k_VectorIntersectplaneOneWordsVariant5[1] = {
    0x3F800000,
};
#endif
