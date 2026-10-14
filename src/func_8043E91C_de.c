#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043E9A8.h"
#include "types.h"

extern void func_804427C4_de(void *arg0, void *arg1, void *arg2);
extern s32 D_0044FDF4;

/** Forwards arg1 through and arg2 as the first parameter, adding the D_450A20 record. */
s32 func_8043E91C_de(void *arg0, void *arg1, void *arg2) {
    func_804427C4_de(arg2, arg1, &D_0044FDF4);
    return 1;
}

/* Reads an object's sub-record kind byte and forwards it to two per-kind setup routines. */





extern void func_80264770_de(s32 kind);
extern void func_80404E28_de(s32 kind);

void func_8043E948_de(struct Record_func_80409BDC_de *arg0)
{
    s32 kind = arg0->inner->unk4;

    func_80264770_de(kind);
    func_80404E28_de(kind);
}
