#include "span_16E000/code_8043E9A8.h"
#include "types.h"





extern s32 func_80264690_de(void);

/** Clears or sets bit 24 of arg1's record's flags depending on how many of func_80264690_de's four slots are active, and demotes arg1->unk0 from state 2 to 1 in the low-count case. */
s32 func_8043EB70_de(void *arg0, Obj8043ECE8 *arg1) {
    if (func_80264690_de() < 2) {
        arg1->unkC->unk58 &= 0xFEFFFFFF;
        if (arg1->unk0 == 2) {
            arg1->unk0 = 1;
        }
    } else {
        arg1->unkC->unk58 |= 0x01000000;
    }
    return 0;
}
