#include "span_1000/code_80279208.h"
#include "types.h"

extern s32 func_80204308_de(s32 arg0, s32 arg1, s32 arg2);

extern s32 D_801371D4;




s32 func_80279420_de(void *arg0, s32 arg1) {
    func_80279490_S1 *object = arg0;
    s32 temp_a1;

    if (object->unkA == D_801371D4) {
        if (arg1 != 0) {
            temp_a1 = D_8011BF00 + (object->unk4 * 0x2E8);
            if ((object->unk11 == 0xA) && (object->unk12 == 1)) {
                return func_80204308_de(temp_a1, temp_a1 + 0x170, arg1);
            }
        }
        return 1;
    }
    return 1;
}
