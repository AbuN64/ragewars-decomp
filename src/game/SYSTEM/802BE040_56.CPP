#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/EXTERNS_2.H"
#include "AUDIO_3/802BEC10.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"

#if !(defined(VERSION_US))
extern OSPiHandle_s D_801486C0;
extern OSPiHandle_s *D_800D437C;
extern u32 func_802BCF30_de(void);

OSPiHandle_s *func_802B8F48_de(void)
{
    u32 domain = 0;
    u32 saveMask;
    OSPiHandle_s *h = &D_801486C0;
    OSPiHandle_s **table;

    if (h->baseAddress == 0xB0000000)
        return h;

    h->type = 0;
    h->baseAddress = 0xB0000000;
    func_802B9B20_de(0, &domain);
    h->latency = domain & 0xff;
    h->pulse = (domain >> 8) & 0xff;
    h->pageSize = (domain >> 0x10) & 0xf;
    h->relDuration = (domain >> 0x14) & 0xf;
    h->domain = 0;
    h->speed = 0;

    func_802A001C_de(&h->transferInfo, 0, sizeof(h->transferInfo));

    saveMask = func_802BCF30_de();
    table = &D_800D437C;
    h->next = *table;
    *table = h;
    __osRestoreInt(saveMask);

    return h;
}
#endif

#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_802B92B0_eu);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802B9010_de);
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
INCLUDE_ASM("span_1000", func_802B92F0_eu_x);
#endif
