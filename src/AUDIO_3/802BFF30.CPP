#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/GFX.H"
#include "COMMON/EXTERNS_5.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
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
#include "COMMON/ARG.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/CTX.H"
#include "COMMON/EXTERNS_19.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/S1_5.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "AUDIO_3/802BEC10.H"
#include "AUDIO_3/802BEE60.H"
#include "AUDIO_3/802BFF30.H"
#include "SCHED/8023A284_16.H"
#include "sdk/libgultra/libasm_802BBC68_14.h"
#include "sdk/libgultra/libasm_802BBC68_21.h"
#include "sdk/libgultra/libasm_802BBC68_6.h"
#include "sdk/libgultra/libasm_802BBC68_7.h"
#include "sdk/libgultra/libasm_802BBC68_8.h"
#include "RESMGR/802A0888.H"
#include "AUDIO_3/802BFD40.H"

/* osInitialize, drafted from ultralib src/os/initialize.c (before 2.0J, _FINALROM): the clock
   rate comes from the ROM header through osPiRawReadIo. */




extern void func_802BD280_de(void *addr, s32 size);
extern void func_802BD010_de(void *addr, s32 size);


void func_802BAE40_de(void)
{
    u32 pifdata;
    u32 clock = 0;
    u64 *rate;

    D_80149B08 = 1;
    func_802BD220_de(

#if defined(VERSION_DE)
func_802BCF20_de
#elif defined(VERSION_EU)
func_802BD1C0_eu
#elif defined(VERSION_US)
func_802BCE50_us
#else
func_802BD200_eu_x
#endif

() | 0x20000000);
    func_802BD160_de(0x01000800);
    while (func_802BB060_de(0x1FC007FC, &pifdata)) {
        ;
    }
    while (func_802BB0F0_de(0x1FC007FC, pifdata | 8)) {
        ;
    }
    *(Quad_func_802A1BE0_de *)0x80000000 = *D_002BBC70;
    *(Quad_func_802A1BE0_de *)0x80000080 = *D_002BBC70;
    *(Quad_func_802A1BE0_de *)0x80000100 = *D_002BBC70;
    *(Quad_func_802A1BE0_de *)0x80000180 = *D_002BBC70;
    func_802BD280_de((void *)0x80000000, 0x80000180 - 0x80000000 + sizeof(Quad_func_802A1BE0_de));
    func_802BD010_de((void *)0x80000000, 0x80000180 - 0x80000000 + sizeof(Quad_func_802A1BE0_de));
    func_8023C750_de();
    func_802B9B20_de(4, &clock);
    clock &= ~0xf;
    if (clock != 0) {
        D_80149B00 = clock;
    } else {
        D_80149B00 = 62500000;
    }
    rate = &D_80149B00;
    *rate = *rate * 3 / 4;
    if (D_8000030C == 0) {
        func_802A001C_de(D_8000031C, 0, 0x40);
    }
    if (D_80000300 == 0) {
        D_800D5250 = 0x2F5B2D2;
    } else if (D_80000300 == 2) {
        D_800D5250 = 0x2E6025C;
    } else {
        D_800D5250 = 0x2E6D354;
    }
}


int func_802BB060_de(u32 arg0, u32 *arg1) {
    if (arg0 & 3) {
        func_802BAC50_de(D_800CCC30, &D_800C79E4_de, 0x33);
    }
    if (arg1 == 0) {
        func_802BAC50_de(D_800CCC30, &D_800C79E4_de, 0x34);
    }
    if (func_802B9D70_de() != 0) {
        return -1;
    }
    *arg1 = *(u32 *)(arg0 | 0xA0000000);
    return 0;
}

int func_802BB0F0_de(u32 arg0, u32 arg1) {
    if (arg0 & 3) {
        func_802BAC50_de(&D_800C7A00_de, &D_800C7A04_de, 0x34);
    }
    if (func_802B9D70_de() != 0) {
        return -1;
    }
    *(u32 *)(arg0 | 0xA0000000) = arg1;
    return 0;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802BB08C);
#endif
