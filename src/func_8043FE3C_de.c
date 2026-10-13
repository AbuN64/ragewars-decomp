#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A8A94.h"
#include "span_16E000/code_8043F69C.h"
#include "types.h"
















/* Chooses a text style, updates its colours and scale, then draws the text. */
/* The values func_8043FE3C_de loads by address:
 * 0x800E2490 = 1.25 (float, D_800E2490 in this cartridge's tables)
 * 0x800E2494 = 0.9 (float, unnamed in this cartridge's tables)
 * 0x800E2498 = 0.25 (float, D_800E2498 in this cartridge's tables)
 * 0x800E28D0 = 4.48e-43 (float, D_800E28D0 in this cartridge's tables; not a literal: a variable, its value in the image, since D_800E28D0: `sw` at %lo(D_800E28D0) in func_8040BBB0_de.s)
 * 0x800E28D4 = 3.36e-43 (float, D_800E28D4 in this cartridge's tables)
 * 0x800E249C = 0.0035211267 (float, D_800E249C in this cartridge's tables)
 * 0x800E24A0 = 0.0045045046 (float, D_800E24A0 in this cartridge's tables)
 * 0x800E24A4 = 255.0 (float, D_800E24A4 in this cartridge's tables)
 * 0x800E24A8 = 1.0 (float, D_800E24A8 in this cartridge's tables)
 */
u32 func_80265350_de(void);
int func_802934F8_de(void);





void func_80441BE0_de();

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif

extern s32 D_800E28D0;
extern s32 D_800E28D4;                          /* unable to generate initializer: unknown type */
extern s32 D_800E1E20;
                          



extern func_8043FFAC_S4 D_800E1E24_de[];



/* unable to generate initializer: unknown type */

void func_8043FE3C_de(func_80254D70_S2 *arg0, func_8043FFAC_S5 *arg1, s32 arg2, func_8043FFAC_S2 *arg3, s32 arg4, s32 arg5) {
    f32 var_f1;
    s32 temp_f3;
    s32 temp_f3_2;
    s32 temp_f3_3;
    s32 temp_f3_4;
    s32 temp_f3_5;
    s32 temp_f3_6;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_s0;
    u32 temp_v1;
    u8 var_s5;
    func_8043FFAC_S4 *temp_s1;

    var_s5 = 1;
    if ((func_802934F8_de() == 0) || !(arg0->unk8 & 0x40000000)) {
        if (D_801462E5 != 0) {
            if (arg0->unk8 < 0) {
                if (func_80265350_de() == 0x400000) {
                    goto block_5;
                }
            }
        }
    } else {
block_5:
        arg3->unk38 = 0;
    }
    if (arg0->unk8 & 0x08000000) {
        if (arg3->unk3C != 0) {
            arg3->unk38 = 0;
        }
        func_80441BE0_de(arg3, arg0, 1);
        func_80441BE0_de(arg3, arg0, 0);
        var_s5 = 0;
    }
    if (arg3->unk38 == 0) {
        var_s5 = 0;
    }
    temp_v1 = arg0->unk8 & 0x3FE0;
    var_a0 = 0;
    switch (temp_v1) {
    case 0x20: var_a0 = 0; break;
    case 0x40: var_a0 = 1; break;
    case 0x80: var_a0 = 2; break;
    case 0x100: var_a0 = 3; break;
    case 0x200: var_a0 = 4; break;
    case 0x400: var_a0 = 5; break;
    case 0x800: var_a0 = 6; break;
    case 0x1000: var_a0 = 7; break;
    case 0x2000: var_a0 = 8; break;
    default: var_a0 = 0; break;
    }
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    var_a0 += D_80152789 * 9;
#endif
    temp_s1 = &D_800E1E24_de[var_a0];
    var_s0 = temp_s1->unk0;
    if (arg5 != 0) {
        var_s0 = 6;
    }
    if (D_800E1E20 != var_s0) {
        switch (var_s0) {                           /* irregular */
        case 0:
            func_802A84F8_de();
            break;
        case 1:
            func_802A84F8_de();
            func_802A8710_de();
            break;
        case 2:
            func_802A84F8_de();
            func_802A8800_de();
            break;
        case 6:
            func_802A84F8_de();
            func_802A8710_de();
            D_80147150 = 1;
            break;
        }
        D_800E1E20 = var_s0;
    }
    if (arg1->unk0 == arg3->unk0) {
        var_f1 = 1.25f;
    } else if (!(arg0->unk8 & 0x01000000)) {
        var_f1 = 0.25f;
    } else {
        var_f1 = 0.9f;
    }
    temp_f3 = (s32) ((f32) temp_s1->unk15 * var_f1);
    var_a0_2 = 0xFF;
    if (temp_f3 < 0x100) {
        var_a0_2 = temp_f3;
    }
    temp_f3_2 = (s32) ((f32) temp_s1->unk16 * var_f1);
    var_a1 = 0xFF;
    if (temp_f3_2 < 0x100) {
        var_a1 = temp_f3_2;
    }
    temp_f3_3 = (s32) ((f32) temp_s1->unk17 * var_f1);
    var_a2 = 0xFF;
    if (temp_f3_3 < 0x100) {
        var_a2 = temp_f3_3;
    }
    temp_f3_4 = (s32) ((f32) temp_s1->unk18 * var_f1);
    var_a3 = 0xFF;
    if (temp_f3_4 < 0x100) {
        var_a3 = temp_f3_4;
    }
    func_802AAB3C_de(var_a0_2, var_a1, var_a2, var_a3,
        (s32)((f32)temp_s1->unk19 * var_f1) > 0xFF ? 0xFF : (s32)((f32)temp_s1->unk19 * var_f1),
        (s32)((f32)temp_s1->unk1A * var_f1) > 0xFF ? 0xFF : (s32)((f32)temp_s1->unk1A * var_f1));
    D_801377B8[0] = (s32) temp_s1->unk14;
    D_801377B8[1] = (s32) temp_s1->unk14;
    func_802AAB68_de(temp_s1->unkC * (f32) (D_800E28D0) * 0.0035211267f, temp_s1->unk10 * (f32) (D_800E28D4) * 0.0045045046f);
    if (var_s5 != 0) {
        var_s5 = temp_s1->unk14;
    }
    func_802A8F28_de(arg4, arg1->unk14, arg1->unk1C, (s32) (arg3->unk30 * (arg3->unk34 * 255.0f)), 0, (s32) var_s5, 1.0f, 1.0f);
}
