/* Cycles the selected option, refreshes its label, and wraps at four choices. */
#include "types.h"
#include "common/unused.h"
#include "menu_text.h"
 
s32 func_8025DF34_de(s32);                                 /* extern */
void func_8029973C_de();                                  /* extern */
s32 func_802A0C08_de(void *, s32, ...);                  /* extern */
void func_804366B8_de(s32);                               /* extern */
void func_804367A8_de(s32);                               /* extern */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1D54[];
extern u8 D_80152789;
#else
extern s32 D_800D34C0_de;
#endif
extern CharacterNextState *D_800E5690;

s32 func_80436D4C_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    func_8029973C_de();
    if (arg3 == 1) {
        func_804367A8_de(D_800E5690->unk_28);
        temp_v0 = D_800E5690->unk_28 - 1;
        D_800E5690->unk_28 = temp_v0;
        if (temp_v0 < 0) {
            D_800E5690->unk_28 = 3;
        }
        func_804366B8_de(D_800E5690->unk_28);
        func_802A0C08_de(D_800E5690->text, RW_LOCALIZED_TEXT(D_800D34C0_de, D_800E1D54, D_800E1D54, D_80152789), D_800E5690->unk_28 + 1);
        D_800E5690->unk_2C->text = (void *) (D_800E5690->text);
        func_8025DF34_de(0xE81);
        return 0;
    }
    return 0;
}
