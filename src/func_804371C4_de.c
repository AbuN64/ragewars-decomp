/* Cycles the selected option, refreshes its label, and wraps at four choices. */
#include "types.h"
#include "common/unused.h"
#include "menu_text.h"
 
void func_8029973C_de();                                  /* extern */
s32 func_802A0C08_de(void *, s32, ...);                  /* extern */
void func_804368F8_de(s32);                               /* extern */
void func_804369E8_de(s32);                               /* extern */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1D54[];
extern u8 D_80152789;
#else
extern s32 D_800D34C0_de;
#endif
extern StyleNextState *D_800E5694;

s32 func_804371C4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    func_8029973C_de();
    if (arg3 == 1) {
        func_804369E8_de(D_800E5694->unk_14);
        temp_v0 = D_800E5694->unk_14 - 1;
        D_800E5694->unk_14 = temp_v0;
        if (temp_v0 < 0) {
            D_800E5694->unk_14 = 3;
        }
        func_804368F8_de(D_800E5694->unk_14);
        func_802A0C08_de(D_800E5694->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5694->unk_14 + 1);
        D_800E5694->unk_18->text = (void *) (D_800E5694->text);
        return 0;
    }
    return 0;
}
