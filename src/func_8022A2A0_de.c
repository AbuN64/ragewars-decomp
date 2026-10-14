#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8026AC38.h"
#include "types.h"



extern s32 func_80245908_de(void);
extern void func_8021C9D8_de(void *arg0, void *arg1);








void func_8022A2A0_de(void *arg0, void *arg1) {
    func_80228774_S1 *object;
    func_80207B5C_S2 *argument;
    func_8022A274_S2 *cur;

    func_8026D980_de();
    object = arg0;
    cur = object->unk20;
    if (cur != 0) {
        do {
            argument = arg1;
            if (cur->unk5DC != arg1 ||
                argument->unk24 == 1 ||
                func_80245908_de() != 0) {
                func_8021C9D8_de(cur, arg1);
            }
            cur = cur->unk16E0;
        } while (cur != 0);
    }
    func_8026D9D0_de();
}
