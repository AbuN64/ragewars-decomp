#include "span_1000/code_8028CCB8.h"



/** Clear the object field at offset 0x10BC. */
void func_8028D644_de(void *object) {
    ObjRecAt10BC *record = object;
    record->unk10BC = 0;
}
