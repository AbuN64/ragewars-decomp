#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80268160.h"
#include "types.h"







extern void func_80216288_de(void *, s32, Triple, s32);




void func_8026835C_de(void *arg0, Filter *arg1, s32 arg2, Triple arg3, struct Shape_func_802764D4_de_2 arg6) {
    func_8024BE70_S1 *object = arg0;
    switch (arg1->type) {
    case 0:
        if (object->unk1 != arg6.field_4) {
            return;
        }
        break;
    case 1:
        if (!(arg1->mask & (arg1->type << arg6.field_4))) {
            return;
        }
        break;
    }
    func_80216288_de(arg0, arg6.field_0, arg3, 0);
}
