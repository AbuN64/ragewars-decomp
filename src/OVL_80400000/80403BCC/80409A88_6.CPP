#include "span_16E000/code_80409A88.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_16E000/code_8040A83C.h"
#include "TYPES.H"

/* Points a field's text at the label for the state word D_80153788: one of 15 strings through the jump table
   jtbl_800E0F88 for states 0 to 15, and D_800D783C for any other state. Returns zero. */


extern u32 D_80153788;

s32 func_8040B150_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        case 5: goto case_5;
        case 6: goto case_6;
        case 7: goto case_7;
        case 8: goto case_8;
        case 9: goto case_9;
        case 10: goto case_10;
        case 11: goto case_11;
        case 12: goto case_12;
        case 13: goto case_13;
        case 14: goto case_14;
        case 15: goto case_15;
        }
state_other:
    field->text = D_800D783C;
    goto done;
case_1:
    field->text = D_800D3824;
    goto done;
case_2:
    field->text = D_800D3838;
    goto done;
case_3:
    field->text = D_800D3860;
    goto done;
case_4:
    field->text = D_800D384C;
    goto done;
case_5:
    field->text = D_800D3874;
    goto done;
case_6:
    field->text = D_800D3888;
    goto done;
case_7:
    field->text = D_800D389C;
    goto done;
case_8:
    field->text = D_800D38B0;
    goto done;
case_9:
    field->text = D_800D38C4;
    goto done;
case_10:
    field->text = D_800D38D8;
    goto done;
case_11:
    field->text = D_800D38EC;
    goto done;
case_12:
    field->text = D_800D3900;
    goto done;
case_13:
    field->text = D_800D3914;
    goto done;
case_14:
    field->text = D_800D3928;
    goto done;
case_15:
    field->text = D_800D393C;
done:
    return 0;
}
