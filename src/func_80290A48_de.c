#include "span_1000/code_80290980.h"



/** Copy four scalar fields from the source into output pointers. */
void func_80290A48_de(void *source, int *word, float *third, float *fourth, float *second) {
    func_80290A28_S1 *source_record = source;
    *word = source_record->unk20;
    *second = source_record->unk10;
    *third = source_record->unk8;
    *fourth = source_record->unkC;
}
