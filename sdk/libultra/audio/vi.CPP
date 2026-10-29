#include "include_asm.h"
#include "COMMON/BOOT_TV_TYPE.H"
#include "COMMON/DEVICE_IO.H"
#include "COMMON/HARDWARE_IO.H"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "../../include/AUDIO/vi.H"
#include "../../include/AUDIO/__OSVISWAPCONTEXT.H"
#include "RESMGR/X_PLUS.H"
#include "../../include/libultra/audio/vi.h"

extern ViSwapContextView *g_currentVideoInterfaceContext;
extern ViSwapContextView *g_nextVideoInterfaceContext;

void __osViInit(void)
{
    ViSwapContextView *contexts = g_videoInterfaceContexts;
    s32 tv_type;

    XPlus_FillMemory(contexts, 0, sizeof(g_videoInterfaceContexts));
    tv_type = g_consoleTvType;
    g_currentVideoInterfaceContext = &contexts[0];
    g_nextVideoInterfaceContext = &contexts[1];
    contexts[1].retraceCount = 1;
    contexts[0].retraceCount = 1;
    contexts[1].framep = (void *)0x80000000U;
    contexts[0].framep = (void *)0x80000000U;
    if (tv_type == 0) {
        contexts[1].modep = &g_videoInterfaceModeDefault;
    } else if (tv_type == 2) {
        contexts[1].modep = &g_videoInterfaceModeAlternate;
    } else {
        contexts[1].modep = &g_videoInterfaceModeTable;
    }
    g_nextVideoInterfaceContext->state = 0x20;
    g_nextVideoInterfaceContext->control = g_nextVideoInterfaceContext->modep->comRegs.ctrl;
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
