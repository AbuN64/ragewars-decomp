#include "types.h"

typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u32 baseAddress;
    u32 speed;
    u8 transferInfo[0x60];
} OSPiHandle;

extern OSPiHandle D_801486C0;
extern OSPiHandle *D_800D437C;
extern s32 func_802B9B20_de(u32 devAddr, u32 *data);
extern void *func_802A001C_de(void *dst, s32 value, u32 size);
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 mask);

OSPiHandle *func_802B8F48_de(void)
{
    u32 domain = 0;
    u32 saveMask;
    OSPiHandle *h = &D_801486C0;
    OSPiHandle **table;

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
    func_802BCF50_de(saveMask);

    return h;
}
