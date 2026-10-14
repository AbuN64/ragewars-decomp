#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
#include "types.h"


extern void func_80263740_de(void);
extern u8 D_8010BBB8;
extern u8 D_8010FBE3[];
extern u8 D_80153330[];
extern u8 D_8010FC00[];
extern s32 func_802B7FD8_de(u8 *a0, u8 *a1, s32 a2);
extern s32 func_80404018_de(s32 a0);

extern void func_8026454C_de(void);

/* Probes the Controller Pak slot for kind and records its state: 2 when the probe succeeds, otherwise 3 or 1 depending on func_80404018_de. */
void func_80404E28_de(s32 kind)
{
    u8 *cur;
    s32 ready;

    ((void (*)(s32))func_802644FC_de)(1);
    func_80263740_de();
    D_8010BBB8 = 2;

    cur = D_80153330 + kind * 112;
    if (D_8010FBE3[kind * 4] != 0) {
        cur[0] = 0;
        ready = 0;
    } else {
        cur[0] = func_802B7FD8_de(D_8010FC00, cur + 8, kind) == 0;
        ready = cur[0];
    }

    if (ready != 0) {
        D_801534F0[kind] = 2;
    } else if (func_80404018_de(kind) != 0) {
        D_801534F0[kind] = 3;
    } else {
        D_801534F0[kind] = 1;
    }
    func_8026454C_de();
}
