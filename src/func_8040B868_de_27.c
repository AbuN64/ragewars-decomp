#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040F1E0.h"



/** Store a word at offset 0x2c. */
void func_8040F208_de(void *object, int value) {
    ObjRecAt2CV2 *record = object;
    record->unk2C = value;
}
