#include "span_16E000/code_804251F4.h"
#include "types.h"

/* Announces the current arena's entry for a slot: selects one of four five-byte name tables from the
   mode byte D_801462D5, indexes it by the argument times 400 and hands that entry to func_80265688_de
   together with the current handle D_8015402C and flag 1; an unrecognised mode does nothing. */

extern char D_80102B7E[];
extern char D_800FEB83[];
extern char D_800FEB88[];
extern char D_800FEB8D[];
extern u8 D_801462D5;
extern s32 D_8015402C;
extern void func_80265688_de(char *, s32, s32);

void func_80425D14_de(s32 slot) {
    switch (D_801462D5) {
    case 1:
        func_80265688_de(&D_80102B7E[slot * 0x190], D_8015402C, 1);
        return;
    case 2:
        func_80265688_de(&D_800FEB83[slot * 0x190], D_8015402C, 1);
        return;
    case 3:
        func_80265688_de(&D_800FEB88[slot * 0x190], D_8015402C, 1);
        return;
    case 4:
        func_80265688_de(&D_800FEB8D[slot * 0x190], D_8015402C, 1);
        return;
    }
}
