#include "span_1000/code_8023D370.h"







/** Copy three words from offsets 0x48..0x50 to offsets 0x18C..0x194. */
void func_8023E8B4_de(void *arg0, void *arg1) {
    ObjRecAt48 *arg1_record = arg1;
    ObjRecAt18C *arg0_record = arg0;
    arg0_record->unk18C = arg1_record->unk48;
}
