#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804290E8.h"
#include "types.h"
/* Synchronizes screen D_800E4EF0's option widgets and player-count widget with the stored option
 * block D_801462C8 and the live player count: pushes the four stored option bytes back into their
 * checkbox widgets, sets the player-count widget to the lesser of the screen's cap and the live
 * player count (or the screen's default when that count is zero), and sets the selection and
 * cursor widgets from the stored selection byte and the current cursor value. */





extern struct Screen_func_80429560_de *D_800E4EF0;
extern struct Options_func_80429560_de D_801462C8;
extern void func_802A1B24_de(void *arg0, s32 arg1);
extern void func_8041AD10_de(void *arg0, s32 arg1);
extern s32 func_8041E720_de(void);


void func_80429560_de(void) {
    struct Options_func_80429560_de *opts;
    s32 count;
    s32 cap;

    opts = &D_801462C8;
    func_802A1B24_de(D_800E4EF0->widget24, opts->val1);
    func_802A1B24_de(D_800E4EF0->widget28, opts->val0);
    func_802A1B24_de(D_800E4EF0->widget2C, opts->val2);
    func_802A1B24_de(D_800E4EF0->widget30, opts->val3);
    count = func_8041EB50_de();
    cap = D_800E4EF0->countCap;
    if (cap < count) {
        count = cap;
    }
    if (count == 0) {
        count = D_800E4EF0->countDefault;
    }
    func_802A1B24_de(D_800E4EF0->widget34, count);
    func_8041AD10_de(D_800E4EF0->selectWidget, opts->val4);
    func_8041AD10_de(D_800E4EF0->cursorWidget, func_8041E720_de());
}
