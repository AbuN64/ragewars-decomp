#include "include_asm.h"
#include "COMMON/EXTERNS_3.H"
#include "COMMON/DEVICE_IO.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "sdk/AUDIO/802BF300.H"
#include "sdk/AUDIO/802BFA00.H"
#include "RESMGR/802A0888.H"
#include "sdk/libultra/audio/802BF300.h"

extern __OSViContext_func_802BA910_de *D_800D8440;
extern __OSViContext_func_802BA910_de *D_800D4414;

void __osViInit(void)
{
    __OSViContext_func_802BA910_de *contexts = D_800D43B0;
    s32 tv_type;

    XPlus_FillMemory(contexts, 0, sizeof(D_800D43B0));
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
        contexts[1].modep = &g_videoInterfaceModeTable;
    }
    D_800D4414->state = 0x20;
    D_800D4414->control = D_800D4414->modep->comRegs.ctrl;
    while (IO_READ_WORD(0xA4400010U) > 10) {
    }
    IO_WRITE(0xA4400000U, 0);
    __osViSwapContext();
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
unsigned int func_802BA210_de_padding_BB1EC[1] = {
    0x00000000,
};
#endif
