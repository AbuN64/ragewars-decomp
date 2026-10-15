#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Handles an input event for the 0x4D0-byte entry of D_800E59E0 the low half of the third argument
   selects: when that entry is active, the high half is 3 and the fourth argument is zero, it calls
   func_8029973C_de, resets the entry through func_8043B6E8_de, redraws its six columns and then its
   selected column through func_8043B49C_de, and plays sound 0xE7C; it always returns zero. Written
   from the assembly; the entries are an array member of the screen so each column offset is
   summed before the base is added. */





extern struct Screen_func_8043BBB0_de *D_800E59E0;
extern void func_8029973C_de();
extern void func_8043B6E8_de(s32);
extern void func_8043B49C_de(s32, s32, s32);
extern void func_8025DF34_de(s32);

s32 func_8043BBB0_de(void *first, void *second, u32 event, s32 held) {
    s32 index;
    s32 i;

    index = event & 0xFFFF;
    if (D_800E59E0->entries[index].state != 1) {
        return 0;
    }
    if ((event >> 16) != 3) {
        return 0;
    }
    if (held != 0) {
        return 0;
    }
    func_8029973C_de();
    func_8043B6E8_de(index);
    for (i = 0; i < 6; i++) {
        func_8043B49C_de(index, i, D_800E59E0->entries[index].values[i]);
    }
    func_8043B49C_de(index, D_800E59E0->entries[index].selection,
                  D_800E59E0->entries[index].values[D_800E59E0->entries[index].selection]);
    func_8025DF34_de(0xE7C);
    return 0;
}
