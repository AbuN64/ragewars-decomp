#include "span_1000/code_8022D944.h"
#include "types.h"

extern char D_8013B1A8;


void func_8022E890_de(void *unused0, s32 *arg1) {
    s32 temp;

    temp = *arg1;
    if (temp != 0) {
        func_80268C7C_de(&D_8013B1A8, temp);
        *arg1 = 0;
    }
}
