#include "common/types_1dc8418c21db.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "shared/func_80425674_de_layout.h"
#include "span_16E000/code_8041A4B0.h"
#include "span_16E000/code_8041B020.h"
#include "TYPES.H"
void *func_8041ABC0_de(s32 arg0, s32 arg1);
void func_8041AD34_de(void *menu);
void func_8041AD10_de(void *menu, s32 index);
u32 func_80265350_de(void);
void *func_8041A580_de(s32 arg0, s32 arg1, s32 arg2);
void func_8041A6EC_de(struct Scroll *scroll, s32 item);
extern SelectionScreenState *D_800E4514;

s32 func_80422C58_eu(void) {
    MenuWidget *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0;

    D_800E4514 = func_8025305C_de(0x10);
    func_8041B110_de(0x1BD);
    func_8041B110_de(0x1C2);
    temp_v0 = func_8041ABC0_de(0x1BB, 0x1BC);
    D_800E4514->unk4 = temp_v0;
    func_8041AD34_de(temp_v0);
    func_8041AD34_de(D_800E4514->unk4);
    func_8041AD34_de(D_800E4514->unk4);
    func_8041AD10_de(D_800E4514->unk4, (s32) D_801462C8.firstListMode);
    temp_v0_2 = func_8041ABC0_de(0x1BE, 0x1BF);
    D_800E4514->players[0].highlight = temp_v0_2;
    func_8041AD34_de(temp_v0_2);
    if (func_80265350_de() != 0x400000) {
        func_8041AD34_de(D_800E4514->players[0].highlight);
        func_8041AD34_de(D_800E4514->players[0].highlight);
    }
    func_8041AD10_de(D_800E4514->players[0].highlight, (s32) D_801462C8.slots[7].secondListMode);
    temp_v0_3 = func_8041A580_de(0x1C0, 0x1C1, 0x80);
    D_800E4514->screen = temp_v0_3;
    func_8041A6EC_de(temp_v0_3, D_801462C8.buttons);
    func_8041B110_de(0x1C3);
    func_8041B110_de(0x1C4);
    D_800E4514->players[0].unk4 = 0;
    func_802A2394_de();
    return 0;
}
