#include "span_1000/code_80293A04.h"
#include "shared/world.h"
#include "span_1000/code_802944E8.h"
#include "types.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "span_1000/code_8023A284.h"

extern void func_80293A20_de(s32 arg0, s32 arg1, s32 arg2);

void func_802945D8_de(s32 arg0) {
    func_80293A20_de(arg0, 0xD, 0xD);
}

extern void func_80293B28_de(void);
void func_802945F8_de(void) { func_80293B28_de(); }

extern void func_80293268_de(void *arg0);
extern void func_8023EE00_de(void);
extern void func_802954E0_us_rev1(void);
extern void func_8044D528_de(void *arg0, s32 arg1, s32 arg2);


extern s32 D_800D2970;
extern s32 D_800CD730;
extern f32 D_800D2988;












struct func_802077F4_S2;

void func_80294614_de(void *arg0) {
    void *dst;
    s32 field;
    f32 f;

    D_80142868 = 0;
    D_800CD730 = 0;
    func_80293268_de(arg0);
    func_8023EE00_de();
#if defined(VERSION_US_REV1)
    func_802954E0_us_rev1();
#endif
    dst = &D_8011FE88;
#if defined(VERSION_US_REV1)
    f = (1.0f);
#else
    f = (1.0f);
#endif
    field = ((GameSession *)arg0)->selector;
#if defined(VERSION_US_REV1)
    D_800D2970 = 0;
#endif
    D_800CD744_de = f;
    D_800D298C = f;
    D_800CD740_de = f;
    func_8044D528_de(dst, field, 0);
    ((GameSession *)arg0)->mode = 0xD;
    D_80154048 = 0;
}
