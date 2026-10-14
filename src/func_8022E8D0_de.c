#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022D944.h"
/* Returns whether the entity registered under an id in D_800D052C has flag 1 (mode 0) or flag 2
   (mode 1) set in its word at 0x14; other modes give 0. The interval also holds the empty function
   func_8022E940_de that follows. */


extern func_80204468_S3 *D_800D052C[];

int func_8022E8D0_de(short id, int mode) {
    switch (mode) {
    case 0:
        if (!(D_800D052C[id]->unk14 & 1)) {
            break;
        }
        return 1;
    case 1:
        if (D_800D052C[id]->unk14 & 2) {
            return 1;
        }
        break;
    }
    return 0;
}

void func_8022E940_de(void) {
}
