#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Points a field's text at the label for the state word D_80153778: one of 4 strings through the jump table
   jtbl_800E1020 for states 0 to 4, and D_800D799C for any other state. Returns zero. */


extern u32 D_80153778;
extern char D_800D799C[];
extern char D_800D3984[];
extern char D_800D3998[];
extern char D_800D39AC[];
extern char D_800D39C0[];

s32 func_8040B8E4_de(struct FieldRecAt14 *field) {
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
    field->text = D_800D799C;
    goto done;
case_1:
    field->text = D_800D3984;
    goto done;
case_2:
    field->text = D_800D3998;
    goto done;
case_3:
    field->text = D_800D39AC;
    goto done;
case_4:
    field->text = D_800D39C0;
done:
    return 0;
}
