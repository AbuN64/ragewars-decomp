/* Handles repeated menu navigation inputs and draws the current menu display.
 * Ported from the legacy branch source (byte-exact build there); the five key-repeat counters
 * D_auto_800D2AE4/AF0, D_800D2AEC/D_800D2AF0 and D_auto_800D2AF4/D_auto_800D2AF8 wrap the selection index
 * D_8014AEBC modulo the menu item count D_8014AEB8.unk0 on the fourth consecutive press and
 * mark D_8014AEC4, while the title flip state lives in the menu global block at D_8014AEB0.
 * The values func_80294F1C loads by address:
 * 0x800CA634 = 1.0 (float, D_auto_800CA634 in this cartridge's tables)
 */
#include "span_1000/code_80294C64.h"
#include "shared/func_80286080_de_closed.h"
#include "types.h"

struct MenuGlobal_func_80294F1C_us_rev1;
struct MenuGlobal_func_80294F1C_us_rev1 {
    u8 alternateTitle; /* +0x0 */
    u8 unused0[11]; /* +0x1 */
    s32 selectionIndex; /* +0xC: == D_8014AEBC */
    s32 selectionValue; /* +0x10: == D_8014AEC0 */
    s32 titleWasShown; /* +0x14: == D_8014AEC4 */
    u8 unused1[8480]; /* +0x18 */
    u8 displayData; /* +0x2138 */
    u8 unused2[127]; /* +0x2139 */
    s32 frameCount; /* +0x21B8: == D_8014D068 */
};

struct Selection_func_80294F1C_us_rev1;
struct Selection_func_80294F1C_us_rev1 {
    s32 index; /* +0x0: == D_8014AEBC */
    s32 value; /* +0x4 */
    s32 changed; /* +0x8: == D_8014AEC4 */
};

struct Message;
extern struct Message *func_80237E80_de(void *owner, void *pool, u8 *text);
extern void func_802A84F8_de(void);
extern void func_802A8710_de(void);
extern void func_802A8F28_de(s32 text, s32 x, s32 y, s32 alpha, s32 centred, s32 shadow, f32 scaleX, f32 scaleY);
extern void func_802AAB3C_de(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);
extern void func_802AAB68_de(float arg0, float arg1);
extern void func_80294CA0_us_rev1(void);
extern int D_8010B3D8;
extern Shared_ControlManager D_80145088;
extern struct MenuGlobal_func_80294F1C_us_rev1 D_8014AEB0;
extern s32 D_8014AEC0;
extern s32 D_8014AEBC;
extern s32 D_8014AEC4;
extern u8 D_800CA60C[0x14];
extern u8 D_auto_800CA620[0x14];
extern f32 D_auto_800CA634;
extern s32 D_800D2AE0;
extern s32 D_auto_800D2AE4;
extern s32 D_auto_800D2AE8;
extern s32 D_800D2AEC;
extern s32 D_800D2AF0;
extern s32 D_auto_800D2AF4;
extern s32 D_auto_800D2AF8;
extern s32 D_auto_800D2AFC;
extern s32 D_800E28D4;


void func_80294F1C_us_rev1(void) {
    s32 temp_a0;
    s32 regpart_temp_a0; /* FAKEMATCH: separate the five-step navigation live range for allocation. */
    s32 count_0;
    s32 count_1;
    s32 count_2;
    s32 count_3;
    s32 count_4;
    s32 count_5;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_10; /* FAKEMATCH: preserve declaration order for the original register allocation. */
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_v1;
    s32 var_v1_2;
    s32 minusOne; /* FAKEMATCH: isolate the one-step decrement from remainder temporaries. */
    struct Selection_func_80294F1C_us_rev1 *selection; /* FAKEMATCH: retain the late field pointer to reproduce address reuse. */


    if (D_800D2AE0 != 0) {
        if (D_8010B3D8 & 0x10) {
            if (D_auto_800D2AFC == 0) {
                if (D_8014AEB0.alternateTitle == 0) {
                    func_80237E80_de(&D_80145088, &D_80145088.unknown0[0x40], D_800CA60C);
                    D_8014AEB0.titleWasShown = 1;
                } else {
                    func_80237E80_de(&D_80145088, &D_80145088.unknown0[0x40], D_auto_800CA620);
                }
                D_auto_800D2AFC = 1;
                D_8014AEB0.alternateTitle = (u8) ((u8) D_8014AEB0.alternateTitle < 1U);
            }
        } else {
            D_auto_800D2AFC = 0;
        }
        if (D_8010B3D8 & 0x2000) {
            if (D_8010B3D8 & 0x200) {
                count_0 = D_800D2AEC;
                temp_v1 = count_0; /* FAKEMATCH: retain a copy while incrementing the count in place. */
                count_0 += 1;
                D_800D2AEC = count_0;
                if (temp_v1 >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AEC = 0;
                    D_8014AEC0 -= 1;
                }
            }
            if (D_8010B3D8 & 0x100) {
                count_1 = D_800D2AF0;
                temp_v1_2 = count_1; /* FAKEMATCH: retain a copy while incrementing the count in place. */
                count_1 += 1;
                D_800D2AF0 = count_1;
                if (temp_v1_2 >= 3) {
                    D_8014AEC4 = 1;
                    D_800D2AF0 = 0;
                    D_8014AEC0 += 1;
                }
            }
        } else {
            if (D_8010B3D8 & 0x200) {
                count_2 = D_auto_800D2AE4;
                temp_v1_3 = count_2; /* FAKEMATCH: retain a copy while incrementing the count in place. */
                count_2 += 1;
                D_auto_800D2AE4 = count_2;
                if (temp_v1_3 >= 3) {
                    minusOne = D_8014AEBC;
                    minusOne -= 1;
                    temp_v0_2 = minusOne + D_8014AEB8.unk0;
                    var_v1 = temp_v0_2 % D_8014AEB8.unk0;
                    D_8014AEB0.titleWasShown = 1;
                    D_8014AEBC = minusOne;
                    D_8014AEBC = var_v1;
                    if ((f32) var_v1 < 0.0f) {
                        var_v1 = -var_v1;
                    }
                    D_8014AEB0.selectionIndex = var_v1;
                    D_auto_800D2AE4 = 0;
                }
            }
            if (D_8010B3D8 & 0x100) {
                count_3 = D_auto_800D2AE8;
                temp_v1_4 = count_3; /* FAKEMATCH: retain a copy while incrementing the count in place. */
                count_3 += 1;
                D_auto_800D2AE8 = count_3;
                if (temp_v1_4 >= 3) {
                    temp_v1_5 = D_8014AEBC + 1;
                    temp_a0 = temp_v1_5 % D_8014AEB8.unk0;
                    D_auto_800D2AE8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEBC = temp_v1_5; /* FAKEMATCH: retain the pre-modulo index store present in the original. */
                    D_8014AEBC = temp_a0;
                }
            }
            if (D_8010B3D8 & 0x400) {
                count_4 = D_auto_800D2AF4;
                temp_v1_7 = count_4; /* FAKEMATCH: retain a copy while incrementing the count in place. */
                count_4 += 1;
                D_auto_800D2AF4 = count_4;
                if (temp_v1_7 >= 3) {
                    regpart_temp_a0 = D_8014AEBC - 5;
                    temp_v0_3 = regpart_temp_a0 + D_8014AEB8.unk0;
                    var_v1_2 = temp_v0_3 % D_8014AEB8.unk0;
                    D_8014AEBC = regpart_temp_a0;
                    selection = (struct Selection_func_80294F1C_us_rev1 *)&D_8014AEBC;
                    D_8014AEBC = var_v1_2;
                    if ((f32) var_v1_2 < 0.0f) {
                        var_v1_2 = -var_v1_2;
                    }
                    selection->index = var_v1_2;
                    selection->changed = 1;
                    D_auto_800D2AF4 = 0;
                }
            }
            if (D_8010B3D8 & 0x800) {
                count_5 = D_auto_800D2AF8;
                temp_v1_8 = count_5; /* FAKEMATCH: retain a copy while incrementing the count in place. */
                count_5 += 1;
                D_auto_800D2AF8 = count_5;
                if (temp_v1_8 >= 3) {
                    temp_v1_9 = D_8014AEBC + 5;
                    temp_a0 = temp_v1_9 % D_8014AEB8.unk0;
                    D_auto_800D2AF8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEBC = temp_v1_9; /* FAKEMATCH: retain the pre-modulo index store present in the original. */
                    D_8014AEBC = temp_a0;
                }
            }
        }
        D_8014AEB0.frameCount += 1;
        if (D_8014AEB0.titleWasShown != 0) {
            func_80294CA0_us_rev1();
            D_8014AEB0.titleWasShown = 0;
        }
        func_802A84F8_de();
        func_802A8710_de();
        func_802AAB68_de(D_auto_800CA634, D_auto_800CA634);
        func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_802A8F28_de((s32) &D_8014AEB0.displayData, 0x10, D_800E28D4 - 0x30, 0xFF, 0, 0, D_auto_800CA634, D_auto_800CA634);
    }
}
