#include "span_1000/code_8024BA6C.h"



/** Set or clear status bit two according to the supplied boolean. */
void func_8024BE58_de(void *object, int enabled) {
    func_8024BE48_S1 *object_record = object;
    unsigned int *flags = &object_record->unk2E0;
    if (enabled) {
        *flags |= 2;
    } else {
        *flags &= ~2U;
    }
}
