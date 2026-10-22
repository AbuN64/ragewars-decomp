#include "include_asm.h"
#include "COMMON/NAME.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "COMMON/MATH_HELPERS.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8042E080_12.H"
#include "RENDER_2/8025DE50_5.H"

/* Animates the two menu panels through open, close and countdown states and updates the active team menu. */

extern State_func_8042F91C_de *D_800E54A4;
extern void func_80298368_de(s32);
extern void func_8029973C_de(void);
extern void func_802A2360_de(void);
extern void func_80419F24_de(s32);
extern void func_80419F58_de(s32,s32);

extern s32 func_80419F38_de(s32);
s32 func_8042F91C_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_v0;
    Field_u16_14 *temp_a0;
    Field_u16_14 *temp_a0_2;
    Field_u16_14 *temp_a1;
    Field_u16_14 *temp_a1_2;

    if (D_800E28E0 < 2) {
        temp_v0 = D_800E54A4->unk4C;
        switch (temp_v0) {
        case 1:
            temp_a1 = D_800E54A4->unk3C;
            temp_a1->value = (u16) (temp_a1->value + D_800E54A4->unk42);
            temp_a1_2 = D_800E54A4->unk44;
            temp_a1_2->value = (u16) (temp_a1_2->value - D_800E54A4->unk4A);
            temp_v0_2 = D_800E54A4->unk50 - 1;
            D_800E54A4->unk50 = temp_v0_2;
            if (temp_v0_2 <= 0) {
                func_8025DF34_de(0xE79);
                /* unk28 is the panel's item handle, kept untyped in the animation state */
                func_8040E8D8_de((func_8041F2A0_Item *) D_800E54A4->unk28, 1);
                func_80419F58_de(D_800E54A4->unk24, 4);
                D_800E54A4->unk4C = 4;
                D_800E54A4->unk50 = 4;
            }
            break;
        case 2:
            temp_a0 = D_800E54A4->unk3C;
            temp_a0->value = (u16) (temp_a0->value - D_800E54A4->unk42);
            temp_a0_2 = D_800E54A4->unk44;
            temp_a0_2->value = (u16) (temp_a0_2->value + D_800E54A4->unk4A);
            temp_v0_3 = D_800E54A4->unk50 - 1;
            D_800E54A4->unk50 = temp_v0_3;
            if (temp_v0_3 <= 0) {
                D_800E54A4->unk4C = 3;
                func_8029973C_de();
                func_80298368_de(D_800E54A4->unk3470);
                return 0;
            }
            break;
        case 3:
            func_802A2360_de();
            break;
        case 4:
            D_800E54A4->unk50 = RW_CLAMP(D_800E54A4->unk50 - 1, 0, D_800E54A4->unk50);
            if ((D_800E54A4->unk50 <= 0) && (func_80419F38_de(D_800E54A4->unk24) != 0)) {
                func_80419F24_de(D_800E54A4->unk24);
                D_800E54A4->unk4C = 3;
            }
            break;
        case 5:
            func_8025DF34_de(0xE78);
            D_800E54A4->unk4C = 2;
            D_800E54A4->unk50 = 4;
            func_8040E8D8_de((func_8041F2A0_Item *) D_800E54A4->unk28, 0);
            break;
        }
        if (D_800E54A4->unk4C == 3) func_80433398_de(arg2);
    }
    return 0;
}

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DC85C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E93EC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE22C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDBAC);
#endif
