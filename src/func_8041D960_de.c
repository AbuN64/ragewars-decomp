#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_8041BEA8.h"
#include "types.h"
/* Sets the label text for the focused node: the text of its entry in the 50-entry id table when the
   current player's unlock bit for that entry is set, otherwise the default text; the European
   cartridges hold each entry's text per language and pick the current language's. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
extern Game_func_8041D960_de D_80145088;
#endif
/* The hub spells D_800E3590 as the padded menu block; its focus slot at +0x0EC is a word there,
   while this unit's view types it as a node pointer, so each member use casts to the view. */
extern TextEntry D_800DF544[];
extern PlayerRecord D_800FEB4A[];
extern char D_800DD4C8[];
extern s32 func_80265650_de(PlayerRecord *bits, s32 bit);
void func_8041D960_de(void) {
    s32 i;
    if (((Menu_func_8041D960_de *) D_800E3590)->focus == 0) {
        ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DD4C8 + 4;
        return;
    }
    for (i = 0; i < 50; i++) {
        if (D_800DF544[i].id == ((Menu_func_8041D960_de *) D_800E3590)->focus->unkC) {
            if (func_80265650_de(&D_800FEB4A[((Menu_func_8041D960_de *) D_800E3590)->player], i) == 1) {
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
                ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DF544[i].text[0];
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
                ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DF544[i].text[D_80145088.language];
#endif
            } else {
                ((Menu_func_8041D960_de *) D_800E3590)->label->text = D_800DD4C8 + 4;
            }
            return;
        }
    }
}
