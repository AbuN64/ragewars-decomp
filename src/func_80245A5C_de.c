#include "shared/func_804235A8_eu_layout.h"
#include "span_1000/code_80245980.h"
extern void *D_800E2830;




/** Store four incoming words into the global record's tail fields. */
void func_80245A5C_de(int arg0, int arg1, int arg2, int arg3) {
    Shared_MenuContext *record = D_800E2830;
    record->unknown104[2] = arg1;
    record->unknown104[1] = arg0;
    record->unknown104[3] = arg2;
    record->unknown104[4] = arg3;
}
