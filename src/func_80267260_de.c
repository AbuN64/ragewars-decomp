#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "span_1000/code_80275E44.h"
#include "types.h"



extern void func_8024E79C_de(void *arg0, Triple input, Triple *output,
                          s32 *value, s32 unused0, s32 unused1);



void func_80267260_de(void *arg0, Triple input, s32 arg4) {
    Triple output;
    s32 value;

    func_8024E79C_de(arg0, input, &output, &value, 0, 0);
    if (arg4 != 0) {
        func_80276184_de((void *)value);
    } else {
        func_802761B8_de((void *)value);
    }
}
