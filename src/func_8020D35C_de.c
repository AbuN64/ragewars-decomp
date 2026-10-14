#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8020AF9C.h"



/** Clear the word at offset 0x28. */
void func_8020D35C_de(void *arg0) {
    ObjRecAt28V2 *record = arg0;
    record->unk28 = 0;
}
