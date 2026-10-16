#include "span_16E000/code_8043A0A4.h"
#include "TYPES.H"

/* Calls func_8029973C_de and, when the fourth argument is one and the 0x4D0-byte entry of D_800E59E0 the third argument selects is in mode two (the word at 0x4D4, four bytes past the entry) with its word at 0x4B0 equal to one, plays sound 0xE7B through func_8025DF34_de and calls func_8043AE5C_de with the entry index and -1, returning zero. */



extern char *D_800E59E0;
extern void func_8029973C_de();
extern void func_8025DF34_de(s32);

s32 func_8043BDF0_de(void *first, void *second, s32 slot, s32 active) {
    struct EntryRecAt4D4 *entry;
    u16 index;

    func_8029973C_de();
    if (active == 1) {
        index = slot;
        entry = (struct EntryRecAt4D4 *) (D_800E59E0 + index * 0x4D0);
        if (entry->nextActive == 2 && entry->state == active) {
            func_8025DF34_de(0xE7B);
            func_8043AE5C_de(index, -1);
            return 0;
        }
    }
    return 0;
}
