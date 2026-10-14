#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"
/* Sets arg0's unk14 field to the address of D_800D76C8 and returns 0. */



extern char D_800D76C8;

s32 func_8043E190_de(ObjRecAt14V1 *arg0) {
    arg0->unk14 = &D_800D76C8;
    return 0;
}
