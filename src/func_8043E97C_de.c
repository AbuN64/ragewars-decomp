#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043E9A8.h"
#include "types.h"

/* Marks the selected record's byte tag and clears the active menu state. */
extern void func_80264770_de(int);
extern s32 D_800E28C0;

void func_8043E97C_de(void *arg0) {
    Obj8043EB20 *item = arg0;

    func_80264770_de(item->unk20->unk4);
    D_800E28C0 = 0;
}
