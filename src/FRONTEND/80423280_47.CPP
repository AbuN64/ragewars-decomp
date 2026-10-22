#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
extern s32 *D_800E4EF0;
extern s32 D_8014DD98;
extern s32 D_auto_800D74C0, D_auto_800D74C4, D_auto_800D74C8, D_auto_800D74CC, D_800D34A4, D_auto_800D74D4, D_auto_800D74D8;
extern s32 *func_8025305C_de(s32);
extern void func_8043C210_de(s32 *, s32, s32, s32, s32);
extern s32 func_8041EAC4_de(void);
extern s32 func_8040EC30_de(void *, s32);
extern void func_8040E950_de(s32, s32);
extern s32 func_802A1990_de(s32, s32, s32, s32, s32);
extern s32 func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(s32, s32);
extern void func_8041B110_de(s32);
extern void func_80429560_de(void);
extern void func_80429654_de(s32);
s32 func_804291D0_de(void *menu) {
    s32 *state;
    s32 widget;
    state = func_8025305C_de(0x40);
    D_800E4EF0 = state;
    func_8043C210_de(state, 0x67, 0, 0, 0);
    D_800E4EF0[0xE] = func_8041EAC4_de();
    switch (D_8014DD98) {
    case 1:
        func_8040E950_de(func_8040EC30_de(menu, 0x35F), 1);
        func_8040E950_de(func_8040EC30_de(menu, 0x363), 1);
        break;
    case 0:
        func_8040E950_de(func_8040EC30_de(menu, 0x365), 1);
        func_8040E950_de(func_8040EC30_de(menu, 0x363), 1);
        break;
    case 2:
    case 3:
        func_8040E950_de(func_8040EC30_de(menu, 0x35F), 1);
        func_8040E950_de(func_8040EC30_de(menu, 0x365), 1);
        break;
    default:
        break;
    }
    D_800E4EF0[9] = func_802A1990_de(0x363, 0x364, 0, 0x64, 1);
    D_800E4EF0[10] = func_802A1990_de(0x361, 0x362, 0, 0x64, 1);
    D_800E4EF0[11] = func_802A1990_de(0x35F, 0x360, 0, 0x64, 1);
    D_800E4EF0[12] = func_802A1990_de(0x365, 0x366, 0, 0x64, 1);
    D_800E4EF0[15] = 0;
    if (D_800E4EF0[14] == 3) {
        D_800E4EF0[15] = 1;
    }
    D_800E4EF0[13] = func_802A1990_de(0x36C, 0x36D, D_800E4EF0[15], D_800E4EF0[14], 1);
    widget = func_8041ABC0_de(0x367, 0x368);
    D_800E4EF0[7] = widget;
    func_8041AD34_de(widget, D_auto_800D74C0);
    func_8041AD34_de(D_800E4EF0[7], D_auto_800D74C4);
    widget = func_8041ABC0_de(0x36E, 0x36F);
    D_800E4EF0[8] = widget;
    func_8041AD34_de(widget, D_auto_800D74C8);
    func_8041AD34_de(D_800E4EF0[8], D_auto_800D74CC);
    func_8041AD34_de(D_800E4EF0[8], D_800D34A4);
    func_8041AD34_de(D_800E4EF0[8], D_auto_800D74D4);
    func_8041AD34_de(D_800E4EF0[8], D_auto_800D74D8);
    func_8041B110_de(0x369);
    func_8041B110_de(0x36A);
    func_8041B110_de(0x36B);
    func_80429560_de();
    func_80429654_de(0);
    func_80429560_de();
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804291D0_de);
#endif
