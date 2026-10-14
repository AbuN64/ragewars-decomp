#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8040B45C.h"
#include "types.h"

/* Points a field's text at the label for the state word D_80153778: one of four strings through the
   jump table jtbl_800E1008 for states 0 to 4, and D_800D7998 for any other state. Returns zero. */


extern u32 D_80153778;
extern char D_800D7998[];
extern char D_800D3980[];
extern char D_800D3994[];
extern char D_800D39A8[];
extern char D_800D39BC[];

s32 func_8040B868_de(struct FieldRecAt14 *field) {
    u32 state = D_80153778;

    if (state >= 5) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto state_1;
        case 2: goto state_2;
        case 3: goto state_3;
        case 4: goto state_4;
        }
state_other:
    field->text = D_800D7998;
    goto done;
state_1:
    field->text = D_800D3980;
    goto done;
state_2:
    field->text = D_800D3994;
    goto done;
state_3:
    field->text = D_800D39A8;
    goto done;
state_4:
    field->text = D_800D39BC;
done:
    return 0;
}
