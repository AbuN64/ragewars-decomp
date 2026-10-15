#include "span_1000/code_802BA23C.h"
#include "hardware_io.h"
#include "device_io.h"

extern __OSViContext_func_802BA910_de D_800D43B0[2];
extern __OSViContext_func_802BA910_de *D_800D8440;
extern __OSViContext_func_802BA910_de *D_800D4414;
extern OSViMode_func_802BA910_de D_800D4440;
extern OSViMode_func_802BA910_de D_800D4490;
extern OSViMode_func_802BA910_de D_800D44E0;
extern s32 D_80000300;
extern void *func_802A001C_de(void *destination, s32 value, u32 size);

void func_802BA210_de(void)
{
    __OSViContext_func_802BA910_de *contexts = D_800D43B0;
    s32 tv_type;

    func_802A001C_de(contexts, 0, sizeof(D_800D43B0));
    tv_type = D_80000300;
    D_800D8440 = &contexts[0];
    D_800D4414 = &contexts[1];
    contexts[1].retraceCount = 1;
    contexts[0].retraceCount = 1;
    contexts[1].framep = (void *)0x80000000U;
    contexts[0].framep = (void *)0x80000000U;
    if (tv_type == 0) {
        contexts[1].modep = &D_800D4490;
    } else if (tv_type == 2) {
        contexts[1].modep = &D_800D44E0;
    } else {
        contexts[1].modep = &D_800D4440;
    }
    D_800D4414->state = 0x20;
    D_800D4414->control = D_800D4414->modep->comRegs.ctrl;
    while (IO_READ_WORD(0xA4400010U) > 10) {
    }
    IO_WRITE(0xA4400000U, 0);
    func_802BA910_de();
}
