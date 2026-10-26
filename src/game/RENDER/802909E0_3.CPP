#include "COMMON/OBJRECAT20V1.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"
#include "FX_2/80271B18.H"
#include "include_asm.h"
#include "RENDER/802909E0.H"
#include "RENDER/802909E0_5.H"

void func_80290A00_de(void *frame) {
    Frame *view = frame;
    view->direction.x = 0.0f;
    view->direction.y = 0.0f;
}

void func_80290A0C_de(void *schedule) {}


void func_80290A14_de(void *frame, void *arg1) {
    Frame *view = frame;
    CVector3 *direction = arg1;
    view->direction = *direction;
    GraphU64_NormalizeVec3(&view->direction.x);
}

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
