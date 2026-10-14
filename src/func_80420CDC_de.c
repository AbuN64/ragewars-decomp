#include "span_16E000/code_8041F1FC.h"
#include "types.h"



/* Applies the chosen character when the active player panel is ready. */

void func_8029973C_de();                                  /* extern */
s32 func_8040EBD0_de(s32);                             /* extern */
s32 func_8041B7FC_de(s32, s32);                        /* extern */
s32 func_8041B810_de(s32, s32);                        /* extern */
void func_80420618_de(s32, s32);                          /* extern */
extern CharacterSelectionRoot *D_800E42D0;

#if defined(VERSION_DE)
enum { SPECIAL_CHAR = 127 };
#elif defined(VERSION_EU_X)
enum { SPECIAL_CHAR = 133 };
#else
enum { SPECIAL_CHAR = 129 };
#endif

s32 func_80420CDC_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_s1;
    s32 var_a1;
    CharacterSelectionRoot *temp_a0;

    temp_s0 = arg2 & 0xFFFF;
    temp_s1 = func_8041B810_de(D_800E42D0->panel, temp_s0);
    func_8029973C_de();
    temp_a0 = (CharacterSelectionRoot *)((char *)D_800E42D0 + (temp_s0 * 0x4C8));
    if (temp_a0->phase == 1) {
        if (temp_s1 == SPECIAL_CHAR) func_80420618_de(temp_s0,temp_a0->choice);
        else if (func_8040EBD0_de(func_8041B7FC_de(D_800E42D0->panel,temp_s0)) == 0) func_80420618_de(temp_s0,temp_s1);
    }
    return 0;
}
