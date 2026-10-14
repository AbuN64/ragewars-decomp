#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"
/* Cycles a menu selection and updates the associated character setting. */

extern func_80204468_S3 *D_800E39C0;
extern s32 D_8014DCF8[];
extern unsigned char D_8014DCFB[],D_8014236A[];
extern void func_8029973C_de(void),func_8041E408_de(s32);
extern s32 func_802999A0_de(s32);
s32 func_8041EFAC_de(s32 unused0, s32 unused1, u32 arg2, s32 arg3) {
    s32 temp_a1;
    s32 temp_a1_2;
    u32 temp_a2;

    temp_a2 = arg2 >> 0x10;
    if ((temp_a2 == 3) && (arg3 == 0)) {
        func_8029973C_de();
        temp_a1 = D_800E39C0->unk14 * 0x1C;
        *(s32 *)((char *)D_8014DCF8 + temp_a1) = (*(s32 *)((char *)D_8014DCF8 + temp_a1) + 1) % 5;
        func_8041E408_de(D_800E39C0->unk14);
        if (func_802999A0_de(0) == 0x16) {
            temp_a1_2 = D_800E39C0->unk14;
            *(D_8014236A + ((7 - temp_a1_2) * 0x96)) = *(D_8014DCFB + (temp_a1_2 * 0x1C));
        }
    }
    return 0;
}
