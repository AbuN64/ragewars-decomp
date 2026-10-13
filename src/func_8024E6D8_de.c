#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024E130.h"
#include "types.h"



extern void func_802165F8_de(void *arg0, void *arg1, void *arg2);




void func_8024E6D8_de(u8 *arg0, void *arg1) {
    Triple buf;
    char pad[0x30];

    if (*arg0 == 1) {
        func_802165F8_de(arg0, arg0 + 0x170, &buf);
        *(Triple *)arg1 = buf;
        return;
    }
    *(s32 *)arg1 = 0;
    ((Triple *)arg1)->y = 0;
    ((Triple *)arg1)->z = 0;
}
