#include "MAIN/802B6380.H"
#include "common/draft_fields_func_8026DC24_de.h"
#include "common/draft_fields_func_80283278_de.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "decomp/argb_color.h"
#include "gfx.h"
#include "libasm_802BBC68.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022A274.h"
#include "span_1000/code_8023B9A0.h"
#include "span_1000/code_80243A80.h"
#include "span_1000/code_80246E34.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80265370.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_8027302C.h"
#include "span_1000/code_8028308C.h"
#include "span_1000/code_8028CCB8.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_8028FC98.h"
#include "span_1000/code_802944E8.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B243C.h"
#include "span_1000/code_802B4730.h"
#include "span_1000/code_802B53FC.h"
#include "span_1000/code_802B8DD0.h"
#include "span_1000/code_802B9BB4.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802BBC68.h"
#include "span_1000/code_802BCF1C.h"
#include "span_1000/code_802BE0D0.h"
#include "span_166000/code_80426310.h"
#include "span_16E000/code_80403BCC.h"
#include "span_16E000/code_8040B45C.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "span_16E000/code_8041BEA8.h"
#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_8041F1FC.h"
#include "span_16E000/code_804221A0.h"
#include "span_16E000/code_804251F4.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8042BD40.h"
#include "span_16E000/code_8043962C.h"
#include "span_16E000/code_8043E9A8.h"
#include "span_16E000/code_8044ACCC.h"
#include "TYPES.H"
#include "MAIN/802BF300.H"

/* osInitialize, drafted from ultralib src/os/initialize.c (before 2.0J, _FINALROM): the clock
   rate comes from the ROM header through osPiRawReadIo. */




extern void func_802BD280_de(void *addr, s32 size);
extern void func_802BD010_de(void *addr, s32 size);

extern void *func_802A001C_de(void *dst, s32 value, u32 size);

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

extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);


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

extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);

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
