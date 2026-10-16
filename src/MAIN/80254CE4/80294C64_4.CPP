/* Handles repeated menu navigation inputs and draws the current menu display.
 * The index/value/changed words form the contiguous selection record; named globals
 * and owner fields provide views of that same menu state. */
#include "span_1000/code_80294C64.h"
#include "TYPES.H"
#include "common/data.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_802453D4_de_closed.h"
#include "shared/func_80286080_de_closed.h"
#include "span_1000/code_802A8A94.h"
#include "shared/texture_request.h"

struct MenuGlobalRecAt21B8;

struct SelectionRecAt8;

struct Message;
extern struct Message *func_80237E80_de(void *owner, void *pool, u8 *text);
extern struct MenuGlobalRecAt21B8 D_8014AEB0;
extern s32 D_8014AEC0;


void func_80294F1C_us_rev1(void) {
    f32 scale;
    s32 temp_a0;
    s32 regpart_temp_a0; 
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
    s32 temp_v1_10; 
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
    s32 minusOne; 
    struct SelectionRecAt8 *selection; 


    if (D_800D2AE0 != 0) {
        if (D_8010B3D8 & 0x10) {
            if (D_auto_800D2AFC == 0) {
                if (D_8014AEB0.alternateTitle == 0) {
                    func_80237E80_de(&D_80145088, (u8 *)&D_80145088 + 0x40, D_800CA60C);
                    D_8014AEB0.titleWasShown = 1;
                } else {
                    func_80237E80_de(&D_80145088, (u8 *)&D_80145088 + 0x40, D_auto_800CA620);
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
                temp_v1 = count_0; 
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
                temp_v1_2 = count_1; 
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
                temp_v1_3 = count_2; 
                count_2 += 1;
                D_auto_800D2AE4 = count_2;
                if (temp_v1_3 >= 3) {
                    minusOne = D_8014AEBC;
                    minusOne -= 1;
                    temp_v0_2 = minusOne + D_8014AEB8.unk0;
                    var_v1 = temp_v0_2 % D_8014AEB8.unk0;
                    D_8014AEB0.titleWasShown = 1;
                    ((struct SelectionRecAt8 *)&D_8014AEBC)->index = minusOne;
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
                temp_v1_4 = count_3; 
                count_3 += 1;
                D_auto_800D2AE8 = count_3;
                if (temp_v1_4 >= 3) {
                    temp_v1_5 = D_8014AEBC + 1;
                    temp_a0 = temp_v1_5 % D_8014AEB8.unk0;
                    D_auto_800D2AE8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEB0.selectionIndex = temp_v1_5; 
                    D_8014AEBC = temp_a0;
                }
            }
            if (D_8010B3D8 & 0x400) {
                count_4 = D_auto_800D2AF4;
                temp_v1_7 = count_4; 
                count_4 += 1;
                D_auto_800D2AF4 = count_4;
                if (temp_v1_7 >= 3) {
                    regpart_temp_a0 = D_8014AEBC - 5;
                    temp_v0_3 = regpart_temp_a0 + D_8014AEB8.unk0;
                    var_v1_2 = temp_v0_3 % D_8014AEB8.unk0;
                    D_8014AEB0.selectionIndex = regpart_temp_a0;
                    selection = (struct SelectionRecAt8 *)&D_8014AEBC;
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
                temp_v1_8 = count_5; 
                count_5 += 1;
                D_auto_800D2AF8 = count_5;
                if (temp_v1_8 >= 3) {
                    temp_v1_9 = D_8014AEBC + 5;
                    temp_a0 = temp_v1_9 % D_8014AEB8.unk0;
                    D_auto_800D2AF8 = 0;
                    D_8014AEC4 = 1;
                    D_8014AEB0.selectionIndex = temp_v1_9; 
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
        scale = D_auto_800CA634;
        func_802A8710_de();
        func_802AAB68_de(scale, scale);
        func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
        func_802A8F28_de((char *)&D_8014AEB0.displayData, 0x10, D_800E28D4 - 0x30, 0xFF, 0, 0, scale, scale);
    }
}
