#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/GFX.H"
#include "COMMON/__OSDISPATCHTHREAD.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECT_INSTANCE_TRANSFORM_AND_RENDER_VIEWS.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/GEOMETRY_BLEND_AND_INSTANCE_VIEWS.H"
#include "COMMON/MTX.H"
#include "COMMON/PARTICLE_ATTACHMENT_AND_OWNER_VIEWS.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "TYPES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/CTX.H"
#include "COMMON/OSSETFPCCSR.H"
#include "COMMON/AUDIO_LOADDECODEDSAMPLES.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/MENU_INITIALIZEOPTIONSSCENE.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "COMMON/BOOT_TV_TYPE.H"
#include "sdk/libultra/io/pirawread.H"
#include "AUDIO/SIRAW.H"
#include "AUDIO/SIRAWWRITE.H"
#include "ENGINE/VIRTUAL/VIRTUAL_REGION_AND_PAGER_OPERATIONS.H"
#include "sdk/libgultra/CPU_STATUS_REGISTER_EU_X.h"
#include "sdk/libgultra/status_register_write.h"
#include "sdk/libgultra/CPU_STATUS_REGISTER_US.h"
#include "sdk/libgultra/OS_GET_STATUS_REGISTER.h"
#include "sdk/libgultra/CPU_STATUS_REGISTER_EU.h"
#include "RESMGR/X_PLUS.H"
#include "AUDIO/AUDIO_ASSERT.H"

/* osInitialize, drafted from ultralib src/os/initialize.c (before 2.0J, _FINALROM): the clock
   rate comes from the ROM header through osPiRawReadIo. */




extern void osWritebackDCache(void *addr, s32 size);
extern void osInvalICache(void *addr, s32 size);


void Audio_InitializeOperatingSystem(void)
{
    u32 pifdata;
    u32 clock = 0;
    u64 *rate;

    g_osInitializationStarted = 1;
    __osSetSR(

#if defined(VERSION_DE)
__osGetSRDe
#elif defined(VERSION_EU)
__osGetSREu
#elif defined(VERSION_US)
__osGetSRUs
#else
__osGetSREuX
#endif

() | 0x20000000);
    __osSetFpcCsr(0x01000800);
    while (Audio_ReadSerialInterfaceWord(0x1FC007FC, &pifdata)) {
        ;
    }
    while (Audio_WriteSerialInterfaceWord(0x1FC007FC, pifdata | 8)) {
        ;
    }
    *(QuadN64EngDrawNumericWidgetChildren *)0x80000000 = *g_osExceptionPreamble;
    *(QuadN64EngDrawNumericWidgetChildren *)0x80000080 = *g_osExceptionPreamble;
    *(QuadN64EngDrawNumericWidgetChildren *)0x80000100 = *g_osExceptionPreamble;
    *(QuadN64EngDrawNumericWidgetChildren *)0x80000180 = *g_osExceptionPreamble;
    osWritebackDCache((void *)0x80000000, 0x80000180 - 0x80000000 + sizeof(QuadN64EngDrawNumericWidgetChildren));
    osInvalICache((void *)0x80000000, 0x80000180 - 0x80000000 + sizeof(QuadN64EngDrawNumericWidgetChildren));
    Vhandler_MapBootstrapAddressRange();
    osPiRawReadIo(4, &clock);
    clock &= ~0xf;
    if (clock != 0) {
        g_systemClockFrequency = clock;
    } else {
        g_systemClockFrequency = 62500000;
    }
    rate = &g_systemClockFrequency;
    *rate = *rate * 3 / 4;
    if (osResetType == 0) {
        XPlus_FillMemory(osAppNMIBuffer, 0, 0x40);
    }
    if (g_consoleTvType == 0) {
        g_audioClockRate = 0x2F5B2D2;
    } else if (g_consoleTvType == 2) {
        g_audioClockRate = 0x2E6025C;
    } else {
        g_audioClockRate = 0x2E6D354;
    }
}


int Audio_ReadSerialInterfaceWord(u32 deviceAddress, u32 *data) {
    if (deviceAddress & 3) {
        Audio_Assert(g_serialDmaAssertionCondition, &s_sirawreadText, 0x33);
    }
    if (data == 0) {
        Audio_Assert(g_serialDmaAssertionCondition, &s_sirawreadText, 0x34);
    }
    if (Audio_IsSerialInterfaceBusy() != 0) {
        return -1;
    }
    *data = *(u32 *)(deviceAddress | 0xA0000000);
    return 0;
}

int Audio_WriteSerialInterfaceWord(u32 deviceAddress, u32 data) {
    if (deviceAddress & 3) {
        Audio_Assert(&g_audioAssertionConditionText, &g_audioAssertionSourceText, 0x34);
    }
    if (Audio_IsSerialInterfaceBusy() != 0) {
        return -1;
    }
    *(u32 *)(deviceAddress | 0xA0000000) = data;
    return 0;
}

#if defined(VERSION_US)
unsigned int k_SirawwriteEncodedWords[1] = {
    0x7265656E,
};
#endif

const char s_siRawWriteSourcePath[16] = "io/sirawwrite.c";
