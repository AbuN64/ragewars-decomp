#include "span_1000/code_80294C64.h"
#include "TYPES.H"
#include "common/unused.h"

extern u8 D_8014AEB0;

extern s32 D_8014AEC0;
extern s32 D_8014AECC;
extern s32 D_8014AED0;
extern s32 D_8014AED4;

void func_802A001C_de(int a, int b, int c);

void func_802954E0_us_rev1(void) {
    s32 *base = &D_8014AEB8;

    D_8014AEB0 = 0;
    D_8014AEB1 = 0;
    D_8014AEBC = 0;
    D_8014AEC0 = 0;
    *base = 1;
    D_8014AEB4 = 0;
    D_8014AEC4 = 0;
    D_8014AECC = 0;
    D_8014AED4 = 0;
    D_8014AED8 = 0;
    D_8014AED0 = 0;
    D_8014CFDC = 0;
    D_8014CFE0 = 0;
    D_8014CFE4 = 0;
    D_8014D068 = 0;

    func_802A001C_de((s32) ((char *) base + 0x24), 0, 0x2000);
    func_802A001C_de((s32) ((char *) base + 0x2024), 0xFF, 0x100);

    *base = *D_8011FED8;
}
