#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Points a field's text at the label for the state word D_80153778: one of 4 strings through the jump table
   jtbl_800E1068 for states 0 to 4, and D_800D79A8 for any other state. Returns zero. */


extern u32 D_80153778;
extern char D_800D79A8[];
extern char D_800D3990[];
extern char D_800D39A4[];
extern char D_800D39B8[];
extern char D_800D39CC[];

s32 func_8040BA58_de(struct FieldRecAt14 *field) {
    u32 state = D_80153778;

    if (state >= 5) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        }
state_other:
    field->text = D_800D79A8;
    goto done;
case_1:
    field->text = D_800D3990;
    goto done;
case_2:
    field->text = D_800D39A4;
    goto done;
case_3:
    field->text = D_800D39B8;
    goto done;
case_4:
    field->text = D_800D39CC;
done:
    return 0;
}
