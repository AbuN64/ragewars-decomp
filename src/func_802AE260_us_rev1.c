#include "span_1000/code_802AE254.h"
#include "span_1000/code_802B8CCC.h"
#include "types.h"

extern s8 D_8014D3E0;
extern u8 D_8014D3E1;
extern u8 D_8014D3E2;
extern u8 D_8014D3E3;
extern u8 D_8014D3E4;
extern s32 D_8014D3E8;
extern s16 D_B2000000;
extern s16 D_B2000004;
extern s16 D_B2000008;
extern s16 D_B200000C;
extern s16 D_B2000010;



s32 func_802AE260_us_rev1(void) {
    u8 temp_s0;

    D_8014D3E0 = 0;
    D_8014D3E1 = 0;
    D_8014D3E2 = 0;
    D_8014D3E3 = 0;
    D_8014D3E4 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000000 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000004 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B200000C = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000010 = 0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    temp_s0 = D_8014D3E2 | 0x40;
    D_8014D3E2 = temp_s0;
    do {
    } while (func_802BDEA0_us_rev1() & 3);
    D_B2000008 = temp_s0;
    D_8014D3E8 = 0;
    return 1;
}
