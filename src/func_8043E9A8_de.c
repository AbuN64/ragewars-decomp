#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043E9A8.h"
#include "types.h"

struct List;
struct Owner;





extern struct List D_0044EB04;
extern struct Owner D_8014561C;

extern void func_80264770_de(int arg0);
extern void *func_80442574_de(struct Owner *owner, struct List *list, s32 b, s32 c, s32 d);

/** Marks arg1's inner record's byte tag via func_80264770_de, then hands the record and arg1's fields to func_80442574_de; ignores arg0. */
s32 func_8043E9A8_de(void *arg0, Obj8043EB20 *arg1) {
    func_80264770_de(arg1->unk20->unk4);
    func_80442574_de(&D_8014561C, &D_0044EB04, arg1->unk1C, (s32) arg1->unk20, 0);
    return 1;
}
