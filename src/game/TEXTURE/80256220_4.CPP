#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TEXTURE/80256220.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

extern u32 __osDisableInt(void);







void *func_8025661C_de(CartridgeReadWorker *cartridgeReadWorker) {
    u32 mask;
    void *head;

    mask = __osDisableInt();
    head = cartridgeReadWorker->available.head;
    if (head != 0) {
        func_80255ED8_de(&cartridgeReadWorker->available, head);
        ((CartridgeReadRequest *)head)->active = 1;
        func_80255CB8_de(&cartridgeReadWorker->pending, head);
    }
    __osRestoreInt(mask);
    return head;
}

extern u32 __osDisableInt(void);






void func_80256688_de(s32 worker, CartridgeReadRequest *request) {
    u32 mask;

    mask = __osDisableInt();
    func_80255ED8_de(&((CartridgeReadWorker *)worker)->pending, request);
    request->active = 0;
    func_80255CB8_de(&((CartridgeReadWorker *)worker)->available, request);
    __osRestoreInt(mask);
}

#if defined(VERSION_US)
unsigned int func_80256688_de_padding_57288[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802566E8_de_padding_572D8[2] = {
    0x24050001, 0x8E442B48,
};
#endif

#if defined(VERSION_EU)
unsigned int func_802566E8_de_padding_572A8[2] = {
    0x12A00005, 0x00000000,
};
#endif
