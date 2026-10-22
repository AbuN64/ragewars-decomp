#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern u32 func_802BCF30_de(void);







void *func_8025661C_de(CartridgeReadWorker *arg0) {
    u32 temp_s2;
    void *temp_s0;

    temp_s2 = func_802BCF30_de();
    temp_s0 = arg0->available.head;
    if (temp_s0 != 0) {
        func_80255ED8_de(&arg0->available, temp_s0);
        ((CartridgeReadRequest *)temp_s0)->active = 1;
        func_80255CB8_de(&arg0->pending, temp_s0);
    }
    __osRestoreInt(temp_s2);
    return temp_s0;
}

extern u32 func_802BCF30_de(void);






void func_80256688_de(s32 arg0, CartridgeReadRequest *arg1) {
    u32 temp_s2;

    temp_s2 = func_802BCF30_de();
    func_80255ED8_de(&((CartridgeReadWorker *)arg0)->pending, arg1);
    arg1->active = 0;
    func_80255CB8_de(&((CartridgeReadWorker *)arg0)->available, arg1);
    __osRestoreInt(temp_s2);
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", func_80256688_de_padding_57288);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_802566E8_de_padding_572D8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("span_1000", func_802566E8_de_padding_572A8);
#endif
