#include "span_16E000/code_8041F1FC.h"
/* Handles a packed message whose high half is type 3 with no extra argument: when the entry named by
   its low half in the 0x4C8-byte table D_800E42D0 is active and has a target, runs func_804201A4_de on it
   and plays sound 0xE7C; always returns 0. */


extern EntryRecAt14V1 *D_800E42D0;
extern void func_804201A4_de(int, EntryRecAt14V1 *);
extern void func_8025DF34_de(int);

int func_80420B78_de(int unused0, int unused1, unsigned int message, int extra) {
    int index = message & 0xFFFF;
    EntryRecAt14V1 *e;

    if ((message >> 16) == 3 && extra == 0) {
        e = &D_800E42D0[index];
        if (e->active == 1 && e->target != -1) {
            func_804201A4_de(index, e);
            func_8025DF34_de(0xE7C);
        }
    }
    return 0;
}
