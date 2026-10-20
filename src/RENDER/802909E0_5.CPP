#include "include_asm.h"
#include "COMMON/OBJRECAT20V1.H"
#include "RENDER/802909E0_5.H"

/** Copy four scalar fields from the source into output pointers. */
void func_80290A48_de(void *source, int *word, float *third, float *fourth, float *second) {
    ObjRecAt20V1 *source_record = source;
    *word = source_record->unk20;
    *second = source_record->unk10;
    *third = source_record->unk8;
    *fourth = source_record->unkC;
}

#if defined(VERSION_US)
/** Perform no operation. */
void func_80290980_us(void) {
}
#endif

#if defined(VERSION_EU)
/** Perform no operation. */
void func_80290B80_eu(void) {
}
#endif
