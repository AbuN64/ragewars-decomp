#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043DF84.h"
#include "types.h"
/* Forwards arg0->unk20->unk4 to func_80264770_de and clears D_800E28C0. */

extern void func_80264770_de(s8 arg0);
extern s32 D_800E28C0;





void func_8043E504_de(struct Record_func_80409BDC_de *arg0) {
    func_80264770_de(arg0->inner->unk4);
    D_800E28C0 = 0;
}
