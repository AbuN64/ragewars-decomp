#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802609CC.h"





/** Store a scalar word plus a three-word record by value. */
void func_80260ECC_de(void *arg0, int arg1, Triple t) {
    ObjRecAt4V4 *arg0_record = arg0;
    arg0_record->unk0 = arg1;
    arg0_record->unk4 = t;
}
