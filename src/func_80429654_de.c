#include "span_16E000/code_8041DF04.h"
#include "span_16E000/code_804290E8.h"
#include "types.h"

/* Refreshes the entry list of screen D_800E4EF0: reads the selection of its cursor at 0x20 through
   func_8041AD04_de and the entry count of its list at 0x34 through func_802A1B18_de. With no entries it
   clears the list through func_8041EA70_de; otherwise, when the count differs from what
   func_8041EB50_de shows or force is 1, it clears the list and rebuilds it for the count and
   selection through func_8041E81C_de. */


extern struct Screen_func_80429654_de *D_800E4EF0;
extern s32 func_8041AD04_de(s32);
extern s32 func_802A1B18_de(s32);
extern void func_8041EA70_de(void);

extern void func_8041E81C_de(s32, s32);

void func_80429654_de(s32 force) {
    s32 selection;
    s32 count;

    selection = func_8041AD04_de(D_800E4EF0->cursor);
    count = func_802A1B18_de(D_800E4EF0->list);
    if (count <= 0) {
        func_8041EA70_de();
        return;
    }
    if (count != func_8041EB50_de() || force == 1) {
        func_8041EA70_de();
        func_8041E81C_de(count, selection);
    }
}
