#include "types.h"
#include "span_1000/code_802B8DD0.h"


extern OSPiHandle_s D_801486C0;
extern OSPiHandle_s *D_800D437C;
extern void *func_802A001C_de(void *dst, s32 value, u32 size);
extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32 mask);

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
